<html>
<body>

<?php

$dbname = 'medpharma';
$dbuser = 'root';  
$dbpass = ''; 
$dbhost = '192.168.18.178:3306'; 

$connect = @mysqli_connect($dbhost,$dbuser,$dbpass,$dbname);

if(!$connect){
	echo "Error: " . mysqli_connect_error();
	exit();
}

echo "Connection Success!<br><br>";

$wt= $_GET["weight"];
$weight=sprintf("%.2f",$wt);
$timestamp = time();
$date=date_default_timezone_set('Asia/Kolkata');
$time=date("y-m-d h:i:s A");
echo $time;

$q0 = mysqli_query($connect,"SELECT * FROM api_medicinebase WHERE m_id = 1");
if (mysqli_num_rows($q0) == 0)
{
    $q1 = mysqli_query($connect,"INSERT INTO api_medicinebase(m_id,medicine_weight,created_at,updated_at) VALUES (1,'$weight','$time','$time')");
}
 else
 {
    $q2 = mysqli_query($connect,"UPDATE api_medicinebase SET medicine_weight='$weight',updated_at='$time' WHERE m_id = 1");
 }


//$q2 = "UPDATE weighttest SET updated='$time'";


// $r1 = mysqli_query($connect,$q0);
// $r2 = mysqli_query($connect,$q1);



echo "Insertion Success!<br>";

?>
</body>
</html>
