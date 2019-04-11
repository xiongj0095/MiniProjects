<?php
include ('includes/dbconnect.php');
global $db;

// Be sure to escape all user input properly
$email = mysqli_real_escape_string($db, $_POST["email"]);
$username = mysqli_real_escape_string($db, $_POST["username"]);
$password = mysqli_real_escape_string($db, $_POST["password"]);

if ((! $email) || (! $username) || (! $password)) {
    die("Missing input(s);");
}

// Uses default 10 cost bcrypt() with a random salt
$hash = password_hash($password, PASSWORD_DEFAULT);

/*
 * This script should only add standard users. Administrators should
 * be added by hand by other admins (promotion) and technicians
 * should be added by promoting a standard user.
 */
$role = 1;

if ($db->query("insert into `techhelpdb`.`users` (`username`, `password`, `role`, `email`) 
                                        VALUES ('$username', '$hash', '$role', '$email')")) {
    if (($db->affected_rows) > 0) {

        echo "User account created. Please login now.\n";

        echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/loginScreen.html" />';
    }
} else {
    echo "User account not created. Please try again.\n";
    
    echo '<meta http-equiv="refresh" content="2; url=/TechHelpDesk-FrontEnd/loginScreen.html" />';
}
$db->close();

?>