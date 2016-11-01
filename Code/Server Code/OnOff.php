<?php
	define('HOST','localhost');
	define('USER','root');
	define('PASS','');
	define('DB','mydb');

	// var $errorMsg = '';

	if ( $_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['device_id']) && isset($_POST['on_off']) ) {

		$device_id = $_POST["device_id"];
		$value = $_POST["on_off"];

		if ( $device_id == '1' ) {
			$command = 'python python_serial.py a ' . $value ;
			shell_exec( $command );
			echo 'LED1 changed';
		} else if ( $device_id == '2' ) {
			$command = 'python python_serial.py b ' . $value ;
			shell_exec( $command );
			echo 'LED2 changed';
		} else if ( $device_id == '3' ) {
			$command = 'python python_serial.py c ' . $value ;
			shell_exec( $command );
			echo 'LED3 changed';
		} else if ( $device_id == '4' ) {
			$command = 'python python_serial.py d ' . $value ;
			shell_exec( $command );
			echo 'Relay1 changed';
		} else if ( $device_id == '5' ) {
			$command = 'python python_serial.py e ' . $value ;
			shell_exec( $command );
			echo 'Relay2 changed';
		} else if ( $device_id == '6' ) {
			$command = 'python python_serial.py f ' . $value ;
			shell_exec( $command );
			echo 'Relay3 changed';
		} else if ( $device_id == '7' ) {
			$command = 'python python_serial.py g ' . $value ;
			shell_exec( $command );
			echo 'Relay4 changed';
		}

		// echo $command;
		// $resultData = json_decode( shell_exec( $command ) , true);
		// echo $resultData;

	} else {
		// $errorMsg .= 'No data passed or passed in wrong format! <br>';
	}

	// if ( $errorMsg != '' )
	// 	echo 'Error: ' . $errorMsg;


?>
