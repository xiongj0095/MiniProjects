<?php
	session_start();
	include('includes/dbconnect.php');
	global $db;


	$title = mysqli_real_escape_string($db, $_POST["title"]);
	$date = mysqli_real_escape_string($db, $_POST["date"]);
	$custnotes = mysqli_real_escape_string($db, $_POST["custnotes"]);

	$username = $_SESSION["username"];
	$userID = $_SESSION["userID"];

	if($db->query("insert into tickets (title, date, custnotes) VALUES ('$title', '$date', '$custnotes')")) {
		echo "Ticket inserted.\n";
	}

	//This contains the id num of the ticket we just inserted.
	$ticketID = mysqli_insert_id($db);


	if($db->query("insert into ticket_assignments (userid, ticketid) VALUES ('$userID', '$ticketID')")) {
		echo "Ticket assigned to creating customer.\n";
	}
	echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/customer.html" />';


?>