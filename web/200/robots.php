<?php
$my_headers = apache_request_headers();
if ($_SERVER['HTTP_ANSWER'] == "Matthew Rogers"){
	echo "Good Job! \n aubie{h3s_R3eAllY_SM4r7}";
}
else{
	echo "Trivia Question: This Auburn graduate is the original founder of AU-CTF.";
	echo "\n\n";
	echo "Make a HTTP GET request to this webpage, and create a header named 'answer' to submit your answer.";
}
?>