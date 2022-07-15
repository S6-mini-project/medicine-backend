
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

$timestamp = time();
$date=date_default_timezone_set('Asia/Kolkata');
$time=date("y-m-d h:i:s A");


$q0=mysqli_query($connect,"SELECT med_name, min_stock FROM api_medstocks WHERE med_id=$key");
$obj=$q0->fetch_object();
$med_name=$obj->med_name;
$min_stock=$obj->min_stock;

$q0 = mysqli_query($connect,"SELECT * FROM api_medicinebase WHERE m_id = $key");
if (mysqli_num_rows($q0) == 0)
{
    $q1 = mysqli_query($connect,"INSERT INTO api_medicinebase(m_id,medicine_weight,medicine_name,minimum_stock,created_at,updated_at) VALUES ($key,'$weight','$med_name','$min_stock','$time','$time')");
}
 else
 {
    $q2 = mysqli_query($connect,"UPDATE api_medicinebase SET medicine_weight='$weight',updated_at='$time' WHERE m_id = $key");
 }



echo "Insertion Success!<br>";

?>
</body>
</html>
