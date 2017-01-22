

<?php
   $stock = lookup($_POST["symbol"]);
?>

A share of <?= htmlspecialchars($stock["name"]) ?> ( <?= htmlspecialchars($stock["symbol"]) ?> ) costs $<?= htmlspecialchars($stock["price"]) ?>


