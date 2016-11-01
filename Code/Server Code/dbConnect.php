<?php
	define('HOST','localhost');
	define('USER','root');
	define('PASS','');
	define('DB','mydb');

	if($_SERVER['REQUEST_METHOD']=='POST') {
		
		$device_id_val = $_POST['device_id_val'];
		$on_off_db = $_POST['on_off_db'];
		// $date = $_POST['date'];
		// $time_db = $_POST['time_db'];
		$milliseconds = $_POST['milliseconds'];
				
		// echo $_POST['device_id_val'];
		// echo $_POST['on_off_db'];
		// echo $_POST['date'];
		// echo $_POST['time_db'];
		// echo $_POST['milliseconds'];

		// $con = mysqli_connect(HOST,USER,PASS,DB);

		// $sql = "INSERT INTO Timers (device_id,device_name,milliseconds,date,time,on_off) VALUES ('$device_id_val','Lightz','$milliseconds','$date','$time_db','$on_off_db')";

		// if(mysqli_query($con,$sql)) {
		// 	echo "Successfully Registered";
		// } else {
		// 	echo "Could not register";
		// }

		$device_id_val = chr( ord('a') + $device_id_val - 1 );

		$currmillis = round(microtime(true) * 1000);
		$t = ( $milliseconds - $currmillis ) / 1000;
		$t = intval( $t );

		if ($t < 0)
			die( 'Error: Provide future time' );

		$command = 'python daemon.py ' . $t . ' ' . $device_id_val . ' ' . $on_off_db;
		// echo $command;
		$return = json_decode( shell_exec( $command ) , true);
		// echo $return;

		// echo $t . ' ms';

	} else {
		echo 'error';
	}

?>
