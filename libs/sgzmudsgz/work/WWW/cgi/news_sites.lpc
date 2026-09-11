// news_sites.c by fire on May,2000
// this file is used for user to select news from different site


string main() {
	int i=0;
	int port;
	string myname=mud_name();
	mapping mirs=IMUD_D->query_mudlist();
	string sel_ret="<select name='select_site'>\n";
	string ret="
		<html>
		<head>
		<title>News Sites</title>
		<meta http-equiv='Content-Type' content='text/html; charset=gb2312'>
		<script language='javascript'>
			var ips = new Array(); \n";


	foreach(string nm,array con in mirs) { 
		if(myname==nm)
			sel_ret+="<option value='"+con[1]+"' selected >"+nm+"</option>\n";
		else
			sel_ret+="<option value='"+con[1]+"' >"+nm+"</option>\n";
		port=con[2];
		port+=80;
		ret+="ips['"+i+"']='"+con[1]+":"+port+"';\n";
		i++;
	}

	
	sel_ret+="</select>";
	ret+="
		function goto_other_site() {
			idx=document.forms['sites']['select_site']['selectedIndex'];
			ip=ips[idx];
			top.location.href='http://'+ip+'/news_frame.html';
		}
		</script>
	
		</head>

		<body bgcolor='#FFFFFF'>
		<form name='sites' method='post' action=''> ";
	ret+=sel_ret;
	
	ret+="
		<input type=button name=go value=Go onClick='javascript:goto_other_site()'>
		</form>
		</body>
		</html> ";
	return ret;
}

