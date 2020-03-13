<?php
$conn = mysql_connect("localhost:3306/form","root","");
$reg_email ='/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9]+)*(\.[a-z]{2,3})$/';
$reg_phone ='/(^[6-9-])+([0-9])/';
$reg_roll = '/(^[0-9]$)/';
//$email =$_POST["email"];
//$phone =$_POST["num"];
$email = 'fgif678@gmail.com';//_POST["email"]
$phone = '7871861023';
$roll = '8';
if((preg_match($reg_email,$email)) && (preg_match($reg_phone,$phone)) && (preg_match($reg_roll,$roll)))
{   
    echo "valid";
}
else
{
    echo " invalid ";
}

?>