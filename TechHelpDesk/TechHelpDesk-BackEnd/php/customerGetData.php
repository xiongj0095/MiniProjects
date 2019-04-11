<?php
    session_start();
    include ('includes/dbconnect.php');
    
    global $db;
    
    $userid = $_SESSION["userid"];
    
    if(empty($_SESSION["username"])) {
        echo 'You are not logged on. Please try logging in again.\n';
        echo '<meta http-equiv="refresh" content="5; url=/TechHelpDesk-FrontEnd/loginScreen.html" />';
    }

?>