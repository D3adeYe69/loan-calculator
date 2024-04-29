<?php
// Retrieve form data
$price = $_POST['price'];
$bankChoice = $_POST['bankChoice'];
$loanType = $_POST['loanType'];
$loanTermMonths = $_POST['loanTermMonths'];

// Call your C program with the form data
// Assuming the C program is named 'calculateLoan' and located in the same directory
// You might need to adjust the command based on the actual location and name of your C program
exec("./calculateLoan $price $loanType $bankchoice $loanTermMonths", $output, $return_value);

// Return the output of the C program
echo implode("\n", $output);
?>
