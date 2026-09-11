// news_titles.c by fire on May,2000
// this file is used for user to select news from different groups
inherit CLASS_NEWSMSG;

string main(string arg) {
	int i=1; //sec means secret
	int *ids;
	string sec="";
    class news_msg msg;

	string ret="
		<html>
		<head>
		<title>News Groups</title>
		<meta http-equiv='Content-Type' content='text/html; charset=gb2312'>
		<table border=1 width=90%>
	";
	if((!arg)||(arg=="")) arg="caolu";
    ids = NEWS_D->get_messages(arg);

	if(!sizeof(ids)) {
		return "<html><head></head><body><h1>这个新闻组没有任何新闻！
			   </h1></body></html>\n";
	}
	ids=sort_array(ids,-1);
	ret+="<tr><th>序号</td><th>标题</td><th>留言人</td><th>长度</td><th>日期</td></tr>\n";
	foreach(int id in ids) {
		msg = NEWS_D->get_message(arg, id);
		if (!msg || !msg->body)
			continue;
		sec="";
		if((arg[0..6]=="nation.")&&(msg->body[0]=='*'))
			sec="*";
		ret+="<tr><td>"+sec+i+"</td><td><a href='/cgi/news_body.cgi?="+WEB_D->url_encode(arg)+","+id+
			"' target=body >"+msg->subject+"</a></td><td>"+
			msg->poster+"</td><td>"+sizeof(msg->body)+"</td><td>"+
			(intp(msg->time) ? ctime(msg->time)[4..9] : msg->time)+
			"</td></tr>\n";
		i++;
	}
	
	ret+= "</table>
		</body>
		</html> ";
	return ret;
}

