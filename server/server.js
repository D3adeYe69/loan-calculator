// server.js

const express = require('express');
const { exec } = require('child_process');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static('public')); 

app.post('/calculateLoan', (req, res) => {
    const { price, loanType, bankChoice, loanTermMonths } = req.body;

    // Execute the C program with the provided form data
    exec(`calculateLoan ${price} ${loanType} ${bankChoice} ${loanTermMonths}`, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error executing C program: ${error.message}`);
            res.status(500).send('Error calculating loan');
            return;
        }
        
        // Send the output of the C program back to the client
        res.send(stdout);
    });
});

app.listen(port, () => {
    console.log(`Server is listening on port ${port}`);
});
