<?php
session_start();
include ('includes/dbconnect.php');
global $db;

$technotes  = mysqli_real_escape_string($db, $_POST["technotes"]);
$status     = mysqli_real_escape_string($db, $_POST["status"]);

$selectedTicketId = $_SESSION["selectedTicketIdSession"];


if ($db->query("UPDATE `techhelpdb`.`tickets` 
                SET `technotes` = '$technotes', `ticketStatus` = '$status' 
                WHERE (`id` = '$selectedTicketId');")) 
{
    echo "Ticket inserted.\n";
}

echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/monitorV2.php" />';

?>