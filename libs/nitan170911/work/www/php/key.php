<?php
	if(isset($_POST['key'])) {
                echo "<img src=\"test.php?key=".$_POST['key']."\" width=\"400\" height=\"40\"></img>"; 
	} else {
		echo "wrong key!";
	}
?>
