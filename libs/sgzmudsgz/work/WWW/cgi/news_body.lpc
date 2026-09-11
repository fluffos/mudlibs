// news_body.c by fire on May,2000
// this file is used for user to select news from different groups
inherit CLASS_NEWSMSG;
string empty_page(string s) {
	return "<html><head></head><body><table><tr>
		<td align='center' valign='center' width=100% height=100% ><h2>"+s+
		"</h2></td></tr></table></body></html>\n";
}
string main(string arg) {
	int id=1;
	string group;
	string con;
    class news_msg msg;
	string ret;
	if((!arg)||(arg=="")) return empty_page("三国留言板");
	if(sscanf(arg,"%s,%d",group,id)!=2) return empty_page("三国留言板");
	if(!WEB_D->valid_group(group)) return empty_page("没有这条新闻");
	msg=NEWS_D->get_message(group,id);
	if(!msg || !msg->body) return empty_page("没有这条新闻");
	
	con=msg->body;
	if((arg[0..6]=="nation.")&&(con[0]=='*'))
		return empty_page("国家机密，不得阅读。");
	ret="
		<html>
		<head>
		<title>News Groups</title>
		<meta http-equiv='Content-Type' content='text/html; charset=gb2312'>\n";
	ret+="<table width=90% align='center'>\n";
	ret+="<tr><td align='left' width=150 ><b>站点：</b></td><td align='left' width=900>"+
		mud_name()+"</td></tr>\n";
	ret+="<tr><td align='left' width=150 ><b>作者：</b></td><td align='left' width=900>"+
		msg->poster+"</td></tr>\n";
	ret+="<tr><td align='left' width=150 ><b>日期：</b></td><td align='left' width=900>"+
		(intp(msg->time) ? ctime(msg->time)[4..9] : msg->time)+"</td></tr>\n";
	ret+="<tr><td align='left' width=150 ><b>标题：</b></td><td align='left' width=900>"+

		msg->subject+"</td></tr>\n";
	ret+="</table>";
	ret+="<hr><pre>";
	ret+=con;
	
	ret+= "</pre></body>
		</html> ";
	return ret;
}

