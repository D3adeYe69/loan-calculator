function openNewWindow(itemName, itemPrice, imageUrl) {
    const formattedPrice = itemPrice.toFixed(2);
    document.getElementById('price').value = formattedPrice;
    document.getElementById('myModal').style.display = 'block';
    updateLoanTypes();
}

function closeModal() {
    document.getElementById('myModal').style.display = 'none';
    clearOutput();
}

function updateLoanTypes() {
    const bankChoice = document.getElementById('bankChoice').value;
    const loanTypeContainer = document.getElementById('loanTypeContainer');
    const price = parseFloat(document.getElementById('price').value);

    // Clear existing loan types
    loanTypeContainer.innerHTML = '';

    // Add logic to dynamically update loan types based on bank choice and price
    if (bankChoice == 1 && price >= 300) { // MAIB - minimum loan amount: 300
        loanTypeContainer.innerHTML = '<label for="loanType">Loan type (MAIB):</label>' +
            '<select id="loanType" name="loanType" required>' +
            '<option value="1">Credit de Consum Espresso</option>' +
            '</select><br>';
    } else if (bankChoice == 2 && price >= 1000) { // OtpBank - minimum loan amount: 1000
        loanTypeContainer.innerHTML = '<label for="loanType">Select loan type (OtpBank):</label>' +
            '<select id="loanType" name="loanType" required>' +
            '<option value="3">Credit de Nevoi Personale ONLINE</option>' +
            '<option value="4">Credit de Nevoi Personale</option>' +
            '</select><br>';
    } else if (bankChoice == 3 && price >= 500) { // VictoriaBank - minimum loan amount: 500
        loanTypeContainer.innerHTML = '<label for="loanType">Select loan type (VictoriaBank):</label>' +
            '<select id="loanType" name="loanType" required>' +
            '<option value="5">Credit Express</option>' +
            '<option value="6">Credit Garantat de Consum</option>' +
            '<option value="7">Credit Negarantat de Consum</option>' +
            '</select><br>';
    }
}
function clearOutput() {
    // Remove all output elements (function outputs) from list items
    var outputElements = document.querySelectorAll("div > p");
    outputElements.forEach(function(outputElement) {
        outputElement.remove();
    });
}


$(document).ready(function() {
    $('#loanForm').submit(function(event) {
        event.preventDefault();

        const formData = {
            price: parseFloat($('#price').val()).toFixed(2),
            bankChoice: $('#bankChoice').val(),
            loanType: $('#loanType').val(),
            loanTermMonths: $('#loanTermMonths').val()
        };

        $.ajax({
            type: 'POST',
            url: 'http://localhost:3000/calculateLoan', 
            data: formData,
            success: function(response) {
                $('#loanResult').html('<p>' + response + '</p>');

            },
            error: function(xhr, status, error) {
                console.error('Error:', error);
                $('#loanResult').html('<p>Error calculating loan</p>');
            }
        });
    });
});