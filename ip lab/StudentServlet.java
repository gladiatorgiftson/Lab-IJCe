package com.Expno5;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

public class StudentServlet extends HttpServlet
{
	private static final long serialVersionUID = 1L;
	String SeatNum,Name,ans1,ans2,ans3,ans4,ans5;
	int a1=0,a2=0,a3=0,a4=0,a5=0;
	Connection connect = null;
	Statement stmt = null;
	ResultSet rs = null;
	public void doPost(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException
	{
		//Database connection
		try
		{
			Class.forName("com.mysql.jdbc.Driver");
			String url="jdbc:mysql://localhost:3306/student";
			connect = DriverManager.getConnection(url,"gift","gift");
			
		}
		catch(ClassNotFoundException e)
		{
			e.printStackTrace();
		}
		catch(SQLException s)
		{
			s.printStackTrace();
		}
		catch(Exception exp)
		{
			exp.printStackTrace();
		}
		
		//Getting parameter from html form
		SeatNum = request.getParameter("Seat_no");
		SeatNum = request.getParameter("Name");
		ans1 = request.getParameter("group1");
		if(ans1.equals("True"))
			a1=2;
		else
			a1=0;
		ans2 = request.getParameter("group2");
		if(ans2.equals("True"))
			a2=0;
		else
			a2=2;
		ans3 = request.getParameter("group3");
		if(ans3.equals("True"))
			a3=0;
		else
			a3=2;
		ans4 = request.getParameter("group4");
		if(ans4.equals("True"))
			a4=2;
		else
			a4=0;
		ans5 = request.getParameter("group5");
		if(ans5.equals("True"))
			a5=0;
		else
			a5=2;
		
		int Total = a1+a2+a3+a4+a5;
		try
		{
			stmt = connect.createStatement();
			String query = "INSERT INTO studenttable("+"Seat_no,Name,Marks"+") VALUES('"+SeatNum+"', '"+Name+"','"+Total+"')" ;
			int result = stmt.executeUpdate(query);
			stmt.close();
		}
		catch(SQLException s1)
		{
			s1.printStackTrace();
		}
		
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		out.println("<html>");
		out.println("<head>");
		out.println("<title>Result<Title>");
		out.println("</head>");
		out.println("<body bgcolor=pink>");
		out.println("<br><br>");
		out.println("<h2 style=text-align:center>Student Database</h2>");
		out.println("table border=5");
		try
		{
			stmt = connect.createStatement();
			String query = "SELECT * FROM studenttable";
			rs = stmt.executeQuery(query);
			out.println("<th>"+"Seat_no"+"</th>");
			out.println("<th>"+"Name"+"</th>");
			out.println("<th>"+"Marks"+"</th>");
			while(rs.next())
			{
				out.println("<tr>");
				out.println("<td>"+rs.getString(0)+"</td>");
				out.println("<td>"+rs.getString(1)+"</td>");
				out.println("<td>"+rs.getString(2)+"</td>");
				out.println("</tr>");
			}
			out.println("</table>");
		}
		catch(SQLException exp3)
		{
			exp3.printStackTrace();
		}
		finally
		{
			try
			{
				if(rs!=null)
					rs.close();
				if(stmt!=null)
					stmt.close();
				if(connect!=null)
					connect.close();
			}
			catch(SQLException exp4)
			{
				exp4.printStackTrace();
			}
			out.println("<h1 style=text-align:center>Thanks</h1>");
			out.println("/table");
			out.println("</body>");
			out.println("</html>");
		}
	}
}
