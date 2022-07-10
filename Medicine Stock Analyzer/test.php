<html>
<body>

<?php

$dbname = 'project_test';
$dbuser = 'root';  
$dbpass = ''; 
$dbhost = 'localhost'; 

$connect = @mysqli_connect($dbhost,$dbuser,$dbpass,$dbname);

if(!$connect){
	echo "Error: " . mysqli_connect_error();
	exit();
}

echo "Connection Success!<br><br>";


$w= $_GET["weight"];
$weight= substr($w,0,-1);
$val= substr($w, -1);
$key=(int) $val;
// $weight=sprintf("%.2f",$wt);

$timestamp = time();
$date=date_default_timezone_set('Asia/Kolkata');
$time=date("y-m-d h:i:s A");
echo $time;
echo $date;

$q0 = mysqli_query($connect,"SELECT * FROM weighttest WHERE id = $key");
if (mysqli_num_rows($q0) == 0)
{
    $q1 = mysqli_query($connect,"INSERT INTO weighttest(id,weight,created,updated) VALUES ($key,'$weight','$time','$time')");
}
 else
 {
    $q2 = mysqli_query($connect,"UPDATE weighttest SET weight='$weight',updated='$time' WHERE id = $key");
 }


//$q2 = "UPDATE weighttest SET updated='$time'";


// $r1 = mysqli_query($connect,$q0);
// $r2 = mysqli_query($connect,$q1);



echo "Insertion Success!<br>";

?>
</body>
</html>
