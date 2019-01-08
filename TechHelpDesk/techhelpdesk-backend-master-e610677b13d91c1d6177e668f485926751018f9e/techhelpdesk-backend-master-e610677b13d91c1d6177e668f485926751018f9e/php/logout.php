<?php
session_start();
session_destroy();
echo "Logged out.\n";
echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/loginScreen.html" />';
?>