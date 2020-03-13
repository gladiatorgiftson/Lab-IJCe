<?php
$num_reg = '/^[6-9]{1}[0-9]{9}$/';
$num = '5871861023';
$roll_reg = '/^[9510]{4}[0-9]{8}$/';
$roll = '951017104007';
if(preg_match($num_reg,$num))
{
    echo "valid";
}
?>