package com.exp6;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginServlet extends HttpServlet 
{
	private static final long serialVersionUID = 1L;
	protected void doPost(HttpServletRequest req, HttpServletResponse res)throws ServletException,IOException
	{
		res.setContentType("text/html");
		PrintWriter out = res.getWriter();
		String usr = req.getParameter("User");
		String pwd = req.getParameter("password");
		String card = req.getParameter("cardid");
		boolean flag = true;
		String[] userId = getInitParameter("username").split(",");
		String[] password = getInitParameter("passwords").split(",");
		String[] cardids = getInitParameter("cardid").split(",");
		int i;
			for(i=0;i<userId.length;i++)
			{
				if(userId[i].equals(usr)&& password[i].equals(pwd)&&cardids[i].equals(card))
				{
					flag = false;
						Cookie Mycookie = new Cookie("currentuser",usr);
						Mycookie.setMaxAge(60*60);
						res.addCookie(Mycookie);
						res.sendRedirect("LoginSuccess");
						
				}
			}
			if(flag==true)
			{
				out.println("<h4>Invalid user please try again by clicking following link</h4>");
				out.println("<a href='LoginForm.html'>"+"LoginForm.html");
			}
		
	}

}

