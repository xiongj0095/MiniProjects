<?php


//PHP code to connect with MySQL from Azure
$db = mysqli_init();
//mysqli_ssl_set($db, NULL, NULL, "/var/www/html/BaltimoreCyberTrustRoot.crt.pem", NULL, NULL);
mysqli_real_connect($db, "techdeskhelpserver.mysql.database.azure.com",
    "xiongj0095@techdeskhelpserver", "ZXCtoo21!", techHelpDB, 3306);

if (mysqli_connect_errno($db)) {
    die('Failed to connect to MySQL: '.mysqli_connect_error());
}

//PHP code to connect to MySQL from MySQL workbench
//  $host="techdeskhelpserver.mysql.database.azure.com";
//  $port=3306;
//  $socket="";
//  $user="xiongj0095@techdeskhelpserver";
//  $password="";
//  $dbname="";
//  $con = new mysqli($host, $user, $password, $dbname, $port, $socket)
//  or die ('Could not connect to the database server' . mysqli_connect_error());
//$con->close();


// //PHP code for connecting to MySQL from team member
// $db = new mysqli("localhost", "helpdeskdev", "DE#y#6RH", "helpdesk");
// if($db->connect_errno > 0){
// die('Unable to connect to database [' . $db->connect_error . ']');
// }


// PHP Data Objects code for connecting to SSMS from Azure
// try {
//     $db = new PDO("sqlsrv:server = tcp:techhelpserver.database.windows.net,1433; Database = TechHelpDB", "xiongj0095", "ZXCtoo21!");
//     $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
// } catch (PDOException $e) {
//     print("Error connecting to SQL Server.");
//     die(print_r($e));
// }
// SQL Server Extension Sample Code:
// $connectionInfo = array(
//     "UID" => "xiongj0095@techhelpserver",
//     "pwd" => "ZXCtoo21!",
//     "Database" => "TechHelpDB",
//     "LoginTimeout" => 30,
//     "Encrypt" => 1,
//     "TrustServerCertificate" => 0
// );
// $serverName = "tcp:techhelpserver.database.windows.net,1433";
// $db = sqlsrv_connect($serverName, $connectionInfo);

 


?>