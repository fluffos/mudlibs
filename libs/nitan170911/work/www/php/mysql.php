<?php
function mysql_check($key) {
	$mysql_server_name="localhost"; //数据库服务器名称
	$mysql_username="mud"; // 连接数据库用户名
	$mysql_password="mud46899981"; // 连接数据库密码
	$mysql_database="mud"; // 数据库的名字

	$conn=@mysql_connect($mysql_server_name, $mysql_username, $mysql_password);
	if(!$conn)
		return "no data!";
	$strsql = "select `value` from captcha where `id`='"; 
	$result=mysql_db_query($mysql_database, $strsql.addslashes($key)."'", $conn);
	if(!$result)
		return "no data!";
	if($row=mysql_fetch_row($result)) {
		$ret = $row[0];
		mysql_free_result($result);
        	mysql_close();
		return $ret;
	} else {
		return "no data!";
	}
}
?>
