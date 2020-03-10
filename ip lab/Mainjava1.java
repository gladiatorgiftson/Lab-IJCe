import java.sql.*;
public class Mainjava 
{

	public static void main(String[] args) throws Exception
	{
		// TODO Auto-generated method stub
		String url = "jdbc:mysql://localhost:3306/student";
		String Uname ="root";
		String pass  = "";
		String query ="select * from testtable";
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = DriverManager.getConnection(url,Uname,pass);
		Statement st = con.createStatement();
		ResultSet rs = st.executeQuery(query);
		rs.next();
		String name = rs.getString("seatno");
		System.out.println(name);
		st.close();
		con.close();
		
	}

}
