<?php
$reg_email ='/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9]+)*(\.[a-z]{2,3})$/';
$reg_phone ='/^[6-9]{1}[0-9]{9}$/';
$reg_roll = '/^[9510]{4}[17|16|18|19]{2}[1040|1050|1060|]{4}[0-9]{2}$/';
$reg_dept = '/^\bcse|\bece|\bmech$/';
$reg_depcode ='/^\b104|\b105|\b106$/';
$email =$_POST["email"];
$phone =$_POST["num"];
$roll =$_POST["regno"];
$dept =$_POST["dept"];
$depcode = $_POST["code"];
if((preg_match($reg_email,$email)) && (preg_match($reg_phone,$phone)) && (preg_match($reg_roll,$roll)) &&(preg_match($reg_dept ,$dept)) &(preg_match($reg_depcode,$depcode)))
{   
    $conn = mysql_connect("localhost:3306","root","");
    if(!$conn)
    {
        die('error in sql connection'.mysql_error);
    }
    else
    {
        $query="INSERT INTO studentdetail1 () VALUES('$roll','$depcode','$dept','$phone','$email ')";
        echo "value inserted";
        mysql_query($query,$conn);
        $sql = "SELECT * FROM `studenttable1`";
        mysql_close($conn);
    }
}
else
{
    echo " invalid ";
}

?>