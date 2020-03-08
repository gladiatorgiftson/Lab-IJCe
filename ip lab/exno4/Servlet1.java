package com.expno4;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class Servlet1 extends HttpServlet 
{	
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		// TODO Auto-generated method stub
		try
		{
			response.setContentType("text/html");
			String n = request.getParameter("Uname");
			String c = request.getParameter("Ucity");
			PrintWriter out = response.getWriter();
            out.println("Hello "+n);
            out.println(" you are from "+c);
            HttpSession session = request.getSession();
            int k =(int)session.getAttribute("hitCount");
            out.println("<br><br><br><center><b>Total hit on this session="+k+"<b></center>");
			
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}

}
