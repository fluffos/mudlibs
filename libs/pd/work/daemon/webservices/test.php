<?php
        error_reporting(E_ALL);
        $fd = socket_create(AF_INET, SOCK_STREAM, getprotobyname('tcp'));
        socket_set_block($fd);
        $bit_return = socket_connect($fd, "localhost", 12333);
        $int_return_bytes = socket_write($fd, "userAuthenticate:/username=whit&password=stargAte&ip=127.0.0.1");
        $data = socket_read($fd, 30);
//      echo("\nData: " . $data . "\nReturn Bytes: " + $int_return_bytes + "\n");
        echo("Data" . "\n" . $data);
        if($bit_return == true) echo("Success"); else echo("Fail");
        echo("\n");
?>
