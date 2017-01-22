<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell_form.php", ["title" => "Sell Stocks"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)

    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        
        
        $shares = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"],$_POST["symbol"]);
        
        CS50::query("INSERT INTO history (transaction, symbol, shares, price) VALUES( ?, ?, ?, ?) ","SELL", $_POST["symbol"], $shares[0]["shares"], $stock["price"]);
        CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"],$_POST["symbol"]);
        
        
        $stock = lookup($_POST["symbol"]);
        
        
        
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?",$stock["price"] * $shares[0]["shares"], $_SESSION["id"]);
        
        
        
        
        redirect("/");
        
    }

?>
