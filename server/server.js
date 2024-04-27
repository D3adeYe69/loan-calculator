const express = require('express');
const path = require('path');
const { exec } = require('child_process');
const fs = require('fs');

const app = express();
const port = 3000;

app.use(express.static(path.join(__dirname, 'public')));
app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

app.post('/calculateLoan', (req, res) => {
    const { price, loanType, bankChoice, loanTermMonths } = req.body;

    // Check if the calculateLoan executable exists and has executable permissions
    const calculateLoanPath = 'C:\\Users\\HP\\loan-calculator\\server\\calculateLoan.exe';
    console.log('Current directory:', __dirname);
    console.log('calculateLoanPath:', calculateLoanPath);

    if (!fs.existsSync(calculateLoanPath)) {
        console.error('calculateLoan executable not found');
        res.status(500).send('Internal Server Error');
        return;
    }

    // Ensure that the price is formatted as a float (string representation)
    const formattedPrice = parseFloat(price).toString();
    const command = `"${calculateLoanPath}" ${formattedPrice} ${loanType} ${bankChoice} ${loanTermMonths}`;

    exec(command, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error executing C code: ${error}`);
            res.status(500).send('Internal Server Error');
            return;
        }

        res.send(stdout);
    });
});

app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});
