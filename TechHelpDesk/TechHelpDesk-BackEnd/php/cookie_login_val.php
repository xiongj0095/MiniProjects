<?php
// This php page should be included (or required) at the first line of the login validation page
$Month = 2592000 + time(); // this adds 30 days to the current time
setcookie('AboutVisit', date("F jS - g:i a"), $Month);
?>