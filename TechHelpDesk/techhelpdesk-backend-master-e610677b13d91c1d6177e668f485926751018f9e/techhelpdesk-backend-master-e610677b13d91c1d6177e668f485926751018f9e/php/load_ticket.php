<?php
	session_start();
	include('includes/dbconnect.php');
	global $db;
	$userid = $_SESSION["userID"];
	echo "User id is " . $userid;
	# select title, date, custnotes, technotes from tickets join ticket_assignments on ticket_assignments.ticketid = tickets.id where ticket_assignments.userid = 5;
	$result = mysqli_query($db,"SELECT tickets.id,`title`,`date`, `custnotes`, `technotes` FROM `tickets` JOIN ticket_assignments on ticket_assignments.ticketid = tickets.id WHERE ticket_assignments.userid = '$userid'");
	if (mysqli_num_rows($result) > 0) {
		while($row = mysqli_fetch_assoc($result)) {
			echo $row["custnotes"] . "\n";
		}
	}
	else {
		echo "no entries!\n";
	}

?>
