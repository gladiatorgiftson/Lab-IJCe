<?php
$reg_name ='/^\w+( +\w+)*$/';
$reg_email ='/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9]+)*(\.[a-z]{2,3})$/';
//$reg_phone ='/^[6-9]{1}[0-9]{9}$/';
$reg_roll = '/^[9510]{4}[17|16|18|19]{2}[1040|1050|1060|]{4}[0-9]{2}$/';
$reg_dept = '/^\bcse|\bece|\bmech|\baero|\bcivil|\beee$/';
$reg_depcode ='/^\b104|\b105|\b106|\b107|\b108|\b109$/';
$name =$_POST["name"];
$email =$_POST["email"];
//$phone =$_POST["num"];
$roll =$_POST["regno"];
$dept =$_POST["dept"];
$deptcode = $_POST["code"];
//(preg_match())
if((preg_match($reg_name,$name)) && (preg_match($reg_email,$email)) && (preg_match($reg_roll,$roll)) && (preg_match($reg_dept,$dept)) && (preg_match($reg_depcode,$deptcode)))
{
    echo 'valid';
    $conn = new mysqli('localhost','root','','student1');
    if($conn->connect_error)
    {
        die('connection failed :'.$conn->connect_error);
    }
    else
    {
       $stmt = $conn->prepare("insert into studenttable(name, email, regno, dept, code) values(?,?,?,?,?)");
        $stmt->bind_param("sssss",$name,$email,$roll,$dept,$deptcode);
        $stmt->execute();
        echo "\nRegistration Sucessfull";
        $stmt->close();
        $conn->close();
        
    }
}
else
{
    echo 'invalid';
}

?>