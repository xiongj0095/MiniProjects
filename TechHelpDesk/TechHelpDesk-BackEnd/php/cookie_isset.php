<?php
if (session_status() == PHP_SESSION_NONE) {
    session_start();
}
if (isset($_COOKIE['AboutVisit'])) {
    $last = $_COOKIE['AboutVisit'];
    print("<h1>Welcome back " . $_SESSION["username"] . "<br /> You last visited on  " . $last . "</h1>");
} else {
    $Month = 2592000 + time(); // this adds 30 days to the current time
    setcookie('AboutVisit', date("F jS - g:i a"), $Month);
    print("<h1>Welcome " . $_SESSION["username"] . " <br />");
}
?>