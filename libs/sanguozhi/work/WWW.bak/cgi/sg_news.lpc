// Created by flee@sgz on 03261999
// Cgi program for read news via NEWS_D
#include <mudlib.h>
#include <daemons.h>

inherit CLASS_NEWSMSG;

class news_msg news;

mapping boards = (["caolu":"草庐留言板","newbie":"新手帮助", ]);

string get_group_list(string group, int from)
{
	string msg;
	int i, *ids, end;
		
	if( member_array(group, keys(boards)) == -1 )
		return "<br><br><h2>没有此新闻组</h2><br>";
	ids = NEWS_D->get_messages( group );
	if( from > sizeof(ids) )return "<br><br><h2>没有此条新闻</h2><br>";
	if( from + 10 < sizeof(ids) )end = from + 10;
	else end = sizeof( ids );

	msg = "<br><head><h2><center>"+boards[group]+"</center></h2><head><br>";
	msg = msg + "<center><table border=5>";

	for( i = from; i < end; i ++){
		news = NEWS_D->get_message(group, ids[i]);
		msg = msg + sprintf("<tr><th><td><a href=\"/cgi/sg_news.c?=group:%s&which:%d\">%-40s</a></td><td>%-10s</td><td>%-10s</td></tr>\n",
			group, ids[i], news->subject, news->poster, ctime(news->time));
	};

	msg = msg + "</table></center><br>";
	msg = msg + "<center><table border=3 cellspacing=%5 cellpadding=%3><tr>";

	if( from >= 10 ) msg = msg + "<td align=center><a href=\"/cgi/sg_news.c?=group:"+group+"&from:"+(from-10)+"\">Previous Ten</a></td>";
	else msg = msg + "<td align=center>Previous Ten</td>";
	msg = msg + "<td align=center><a href=\"/cgi/sg_post.c\">Write a Post</a></td>";
	if( from + 10 < sizeof(ids) )msg = msg +"<td align=center><a href=\"/cgi/sg_news.c?=group:"+group+"&from:"+(from+10)+"\">Next Ten</a></td>";
	else msg = msg + "<td align=center>Next Ten</td>";

	msg = msg + "<tr></table></center>";
	return msg;
}
string get_one_msg(string group, int id)
{
        string msg;
        int *ids;

        if( member_array(group, keys(boards)) == -1 )
                return "<br><br><h3>没有此新闻组</h3><br>";
        ids = NEWS_D->get_messages( group );
	if( member_array(id, ids) == -1 )
		return "<br><br><h3>没有此条新闻</h3><br>";

	news = NEWS_D->get_message(group, id);
	msg = "<br><head><h2><center>"+boards[group]+"</center></h2><head><br>";
	msg = msg + "<center><table border=5>";
	msg = msg + "<tr><td>" + news->subject + "</td><td>" + news->poster +
		"</td><td>" + ctime(news->time) + "</td></tr></table></center>";
	msg = msg + "<br><center><table border=5 width=\"160\"><tr><td>" + replace_string(news->body, "\n", "\n<br>") +
		"</td></tr></table></center>";

	return msg;
}
string main(string arg)
{
	string group, html;
	int from, id;

	html = @HEAD
<html>
<title> Reading news </title>
<body background="http://sgz.yesite.com/images/desk5.gif" text=white link=yellow vlink=white>
HEAD;
	if( !arg || arg == "" || !stringp(arg) )html = html + "<br><h2><center>非法读取，返回。</center></h2>";
	else if( sscanf(arg, "group:%s", group) == 1 ){
                if ( sscanf(group,"%s&which:%d", group, id) == 2 )
			html = html + get_one_msg(group, id);
		else if( sscanf(group,"%s&from:%d", group, from) == 2 )
                        html = html + get_group_list(group, from);
		else html = html + get_group_list(group, 0);
	} else html = html + "<br><h2><center>非法读取，返回。</center></h2>";

	html = html + @END_HTML
</body>
</html>
END_HTML;

	return html;	
}
