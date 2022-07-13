<html>
<body>

<?php

$dbname = 'medpharma';
$dbuser = 'root';  
$dbpass = ''; 
$dbhost = '192.168.38.252:3306'; 

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

$q0 = mysqli_query($connect,"SELECT * FROM api_medicinebase WHERE m_id = $key");
if (mysqli_num_rows($q0) == 0)
{
    $q1 = mysqli_query($connect,"INSERT INTO api_medicinebase(m_id,medicine_weight,created_at,updated_at) VALUES ($key,'$weight','$time','$time')");
}
 else
 {
    $q2 = mysqli_query($connect,"UPDATE api_medicinebase SET medicine_weight='$weight',updated_at='$time' WHERE m_id = $key");
 }


//$q2 = "UPDATE weighttest SET updated='$time'";


// $r1 = mysqli_query($connect,$q0);
// $r2 = mysqli_query($connect,$q1);



echo "Insertion Success!<br>";

?>
</body>
</html>
