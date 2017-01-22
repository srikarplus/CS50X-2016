<?php

    // configuration
    require("../includes/config.php");
    
    
    $rows = CS50::query("SELECT * FROM history");
    
    
    $display = [];
    
    foreach ($rows as $row)
    {
        $display[] = [
                "transaction" => $row["transaction"],
                "price" => $row["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                
            ];

    }
    
    
    
    
    
    render("history_form.php", ["display" => $display, "title" => "Portfolio History"]);



?>