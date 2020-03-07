<?php
	ini_set('display_errors', 'On');
	error_reporting(E_ALL | E_STRICT);

	echo "<html>";
	if ( isset($_POST["username"]) && isset($_POST["password"]) ) {
		$servername = "localhost";
		$username = "sqli-user";
		$password = 'AndThatDudeBryceBrown';
		$dbname = "SqliDB";

		$conn = new mysqli($servername, $username, $password, $dbname);
		if ( $conn->connect_error )
			die("Connection Failed: " . $conn0->connect_error);
		$user = $_POST["username"];
		$pass = $_POST["password"];
		
		$sql = "SELECT * FROM login WHERE User = '$user' AND Password = '$pass'";
		if ( $result = $conn->query($sql)){
			if($result->num_rows >= 1){
				$row = $result->fetch_assoc();
				if( $row["User"] == "admin")
					echo "aubie{g3t_9ud_\$On}";
				else
					echo "Welcome, " . $row["User"];
			}
			else
				echo "Username/Password don't match our records";
		}
		$conn->close();
	}
	else
		echo "Username and Password are required.";

	echo "</html>";
?>
	