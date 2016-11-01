<?php
	define('HOST','localhost');
	define('USER','root');
	define('PASS','');
	define('DB','mydb');
	 

	$temperature = intval( $_POST['temperature'] );
	$humidity = intval( $_POST['humidity'] );

	if ( $temperature < 10 or $temperature > 50 )
		die( 'Temperature out of range' );

	$command = 'python python_serial.py t ' . chr($temperature);
	$return = json_decode( shell_exec( $command ) , true);
	echo 'Temperature: ' . $return;

	$command = 'python python_serial.py m ' . chr($humidity);
	$return = json_decode( shell_exec( $command ) , true);
	echo ' Humidity ' . $return;

	// echo $command;

	// $myfile = fopen("profile_to_MC.txt", "w") or die("Unable to open file!");
	// $txt = "t:".$_POST['temperature'].",h:".$_POST['humidity'];
	// fwrite($myfile, $txt);
	// fclose($myfile);

?>
