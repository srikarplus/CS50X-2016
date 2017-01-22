<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Sell Stocks"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)

    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        $stock = lookup($_POST["symbol"]);
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?",$_SESSION["id"]);
        
        if($_POST["shares"]*$stock["price"] <= $cash[0]["cash"] && preg_match("/^\d+$/", $_POST["shares"]))
        {
            //if(CS50::query("SELECT symbol FROM portfolios WHERE symbol=?",$_POST["symbol"])){
                CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",$_SESSION["id"],$_POST["symbol"],$_POST["shares"]);
                
           // }
           // else
           // {
           //     CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ",$_SESSION["id"],$_POST["symbol"],$_POST["shares"]);
            //}
            
            
            
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?",$stock["price"] * $_POST["shares"], $_SESSION["id"]);
            
            
            
            CS50::query("INSERT INTO history (transaction, symbol, shares, price) VALUES( ?, ?, ?, ?) ","BUY", $_POST["symbol"], $_POST["shares"], $stock["price"]);
            
            
        }
        else
        {
            apologize("Not enough funds");
        }
        
        
        redirect("/");
        
    }

?>
