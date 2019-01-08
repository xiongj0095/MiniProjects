<?php

	session_start();
	include('includes/dbconnect.php');
	global $db;
	
	$username = mysqli_real_escape_string($db, $_POST["username"]);
	$password = $_POST["password"];

	$result = mysqli_query($db,"SELECT `id`,`password` FROM `users` WHERE username = '$username'");
	if (mysqli_num_rows($result) > 0) {
		$row = mysqli_fetch_assoc($result);
		$hash = $row["password"];
	}
	else {
		echo "Invalid credentials.\n";
		echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/loginScreen.html" />';
		exit(); 
	}
	// Hashing the password with its hash as the salt returns the same hash
	if ( password_verify($password, $hash)) {
		echo "Success, logged in.\n"; 
		$_SESSION["username"] = $username;
		$_SESSION["userID"] = $row["id"];
		echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/customer.html" />';
		exit();
	}
	else {
			echo "Invalid credentials.\n";
			echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/loginScreen.html" />';
			exit();
	}

?>