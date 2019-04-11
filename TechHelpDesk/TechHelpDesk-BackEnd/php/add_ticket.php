<?php
session_start();
include ('includes/dbconnect.php');
global $db;

$title              = mysqli_real_escape_string($db, $_POST["title"]);
$date               = mysqli_real_escape_string($db, $_POST["date"]);
$custnotes          = mysqli_real_escape_string($db, $_POST["custnotes"]);
$technotes          = mysqli_real_escape_string($db, $_POST["technotes"]);
$hardwareObtained   = mysqli_real_escape_string($db, $_POST["hardwareObtained"]);
$hardwareType       = mysqli_real_escape_string($db, $_POST["hardwareType"]);
$technician         = mysqli_real_escape_string($db, $_POST["technician"]);

$username = $_SESSION["username"];
$userid = $_SESSION["userid"];

if ($db->query(  "INSERT INTO `techhelpdb`.`tickets` (`title`, `date`, `custnotes`, `technotes`, `hardwareObtained`, `hardwareType`, `technician` )
            VALUES('$title', '$date', '$custnotes', '$technotes', '$hardwareObtained', '$hardwareType', '$technician')")) 
{
    echo "Ticket inserted.\n";
}

// This contains the id num of the ticket we just inserted.
$ticketid = mysqli_insert_id($db);

if ($db->query("insert into `techhelpdb`.`ticket_assignments` (`userid`, `ticketid`) VALUES ('$userid', '$ticketid')")) {
    echo "Ticket assigned to creating customer.\n";
}

echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/customerV2.php" />';

?>