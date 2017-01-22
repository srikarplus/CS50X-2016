
<table class="table table-striped">

    <thead>
        <tr>
            <th>Transaction</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
        
        <?php foreach ($display as $dis): ?>

    <tr>
        <td><?= $dis["transaction"] ?></td>
        <td><?= $dis["symbol"] ?></td>
        <td><?= $dis["shares"] ?></td>
        <td>$<?= $dis["price"] ?></td>
        
    </tr>

    <?php endforeach ?>
    
    </thead>

    
</table>
           