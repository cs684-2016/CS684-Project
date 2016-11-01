<?php
define('HOST','localhost');
define('USER','root');
define('PASS','');
define('DB','mydb');
 
$con = mysqli_connect(HOST,USER,PASS,DB);
 
//$sql = "select * from temperature";

///////////////////////

$command = 'python python_serial.py T';
$temperatureData = json_decode( shell_exec( $command ) , true);
$temperatureData = round( floatval($temperatureData), 1);

$command = 'python python_serial.py M';
$humidityData = json_decode( shell_exec( $command ) , true);
$humidityData = round( floatval($humidityData), 2);

$sql = 'INSERT INTO `temperature`(`temperature`, `humidity`) VALUES ( ' . $temperatureData . ' ,' . $humidityData . ' )';
mysqli_query( $con, $sql );

///////////////////////

// $sql= "select * from temperature ORDER BY timestamp DESC LIMIT 1";
 
// $res = mysqli_query($con,$sql);
 

// $sql2= "select * from humidity ORDER BY timestamp DESC LIMIT 1";
 
// $res2 = mysqli_query($con,$sql2);


$result = array();

// $row = mysqli_fetch_array($res);

// $row2 = mysqli_fetch_array($res2);


 
// array_push($result,
// array('temperature'=>$row[0],
// 	'milliseconds'=>$row[2],
//  'timestamp'=>$row[3],
// 'humidity'=>$row[1]
// ));

// while($row = mysqli_fetch_array($res)){
// array_push($result,
// array('temperature'=>$row[0],
// 	'milliseconds'=>$row[2],
//  'timestamp'=>$row[3],
// 'humidity'=>$row[1]
// ));
// }

array_push($result,
array('temperature'=>"$temperatureData",
	'milliseconds'=>'1',
 'timestamp'=>'3',
'humidity'=>"$humidityData"
));
 
echo json_encode(array("result"=>$result));
 
mysqli_close($con);
 
?>
