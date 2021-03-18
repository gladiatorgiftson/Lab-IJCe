package com.expno4;
import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

public class SiteHitCounter implements Filter
{

   private int hitCount; 

   public void  init(FilterConfig config) throws ServletException 
   {
      // Reset hit counter.
      hitCount = 0;
   }

   public void  doFilter(ServletRequest req, ServletResponse response, FilterChain chain) throws java.io.IOException, ServletException 
   {
	   HttpServletRequest request = (HttpServletRequest) req;
      // increase counter by one
      hitCount++;

      // Print the counter.
      System.out.println("Site visits count :"+ hitCount );

      // Pass request back down the filter chain
      HttpSession session = request.getSession();
	  session.setAttribute("hitCount", hitCount);
      chain.doFilter(req,response);
      
   
   }
}
   
