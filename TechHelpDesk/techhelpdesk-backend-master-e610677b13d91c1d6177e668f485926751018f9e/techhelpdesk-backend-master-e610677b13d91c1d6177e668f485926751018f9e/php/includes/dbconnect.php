<?php
    $db = new mysqli("localhost", "helpdeskdev", "DE#y#6RH", "helpdesk");
    if($db->connect_errno > 0){
        die('Unable to connect to database [' . $db->connect_error . ']');
    }
?>
