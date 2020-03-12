package com.exp6;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginSuccess extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	protected void doGet(HttpServletRequest req,HttpServletResponse res)throws ServletException,IOException
	{
		Cookie[] my_cookies=req.getCookies();
		res.setContentType("text/html");
		PrintWriter out = res.getWriter();
		out.println("<b>");
		String userName=null;
		if(my_cookies != null)
		{
			for(Cookie cookie : my_cookies)
			{
				if(cookie.getName().equals("currentuser"))
					userName = cookie.getValue();
			}
		}
		out.println("<h3>Login Success!!! Welcome</h3>");
		out.println("<h2>This is a shooping cart for "+userName+"</h2></b>");
		out.close();
	}

}
