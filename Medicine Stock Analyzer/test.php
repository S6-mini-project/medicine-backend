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

$weight = $_GET["weight"];
$timestamp = time();
$time=date("F d, Y h:i:s A", $timestamp);

$q0 = mysqli_query($connect,"SELECT * FROM weighttest WHERE id = 1");
if (mysqli_num_rows($q0) == 0)
{
    $q1 = mysqli_query($connect,"INSERT INTO weighttest(id,weight,created,updated) VALUES(1,'$weight','$time','$time')");
}
 else
 {
    $q2 = mysqli_query($connect,"UPDATE weighttest SET weight='$weight',updated ='$time' WHERE id = 1");
 }


//$q2 = "UPDATE weighttest SET updated='$time'";


// $r1 = mysqli_query($connect,$q0);
// $r2 = mysqli_query($connect,$q1);



echo "Insertion Success!<br>";

?>
</body>
</html>
