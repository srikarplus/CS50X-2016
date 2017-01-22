<!--<div id="middle">-->
<table class="table table-striped">

    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>
    
    
    
    
    <?php foreach ($positions as $position): ?>

    <tr>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["name"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td>$<?= $position["price"] ?></td>
        <td>$<?= $position["price"] * $position["shares"] ?></td>
    </tr>

    <?php endforeach ?>





    <tbody>

    
    
        
        <?php foreach ($cash as $cas): ?>

    <tr>
        <td colspan="4">CASH</td>
        <td>$<?= $cas["cash"] ?></td>
        
    </tr>

    <?php endforeach ?>
    

    </tbody>

</table>
          <!--  </div>-->