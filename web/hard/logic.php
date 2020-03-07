<?php

ini_set("display_errors", "On");
error_reporting(E_ALL | E_STRICT);

echo "<html>";
if ( isset($_POST['encode_button'])){
	$text = $_POST['entry'];
	$escaped_text= escapeshellcmd($text);
	echo base64_encode($escaped_text);
}
elseif ( isset($_POST['decode_button'])){
	$text = $_POST['entry'];
	$decoded_text = base64_decode($text);
	echo shell_exec("echo $decoded_text");
}
else {}


?>
