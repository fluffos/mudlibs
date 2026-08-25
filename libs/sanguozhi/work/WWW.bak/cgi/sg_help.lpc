// Created by flee@sgz 03221999
// Cgi program for searching helps in sgz 
// Modified by flee July 21 1999 
// replace ansi color code to html color code

#include <mudlib.h>
#include <daemons.h>

#define SAVE_FILE "/data/daemons/sghelp"
#define ROOT "/help/player/sanguo/"
#define COLORS ({"%^H_RED%^", "%^H_MAGENTA%^", "%^H_CYAN%^","%^H_YELLOW%^","%^H_GREEN%^", "%^H_BLUE%^","%^RED%^"})

inherit M_ACCESS;

private mapping topics;

void create()
{
	unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	if( !sizeof(topics) )topics = ([ ]);
	return;
}	
string main(string arg)
{
	int i;
	string html, file;
	string *list;
	string *colors;
	
	html=@HTML
<html><body background="http://sgz.yesite.com/images/desk5.gif" text="#FFFFFF" link=yellow vlink=yellow alink=yellow>
HTML;
	if( !arg || !stringp(arg) || arg == "" )arg = "main";
	if( !topics[arg] )html = html +	"\n没有此帮助主题。\n";
	else if( !topics[arg]["p"] )html = html + "\n此帮助主题内容还没有完成。\n";
	else {
		file = ROOT + topics[arg]["p"];
		if( file_size(file) <= 0 )html = html + "\n此帮助主题内容还没有完成。\n";
		else {
			html = html + "<head><h2>" + topics[arg]["t"] + "</h2></head>";
			html = html + read_file(file);
			html = replace_string(html, "\n", "\n<br>");
			html = replace_string(html, "%^RESET%^","<font color=ffffff>");
			foreach(string ss in COLORS)
				html = replace_string(html, ss, "<font color=ff0000>");
			if( topics[arg]["is_parent"] ){
				list = filter_array(keys(topics), (: member_array($(arg),topics[$1]["parent"])!=-1 :));
				if( sizeof(list) ){
					html = html + "<hr>";
					html = html + "<h3>本主题是一个帮助类，其中包括以下主题：</h3>";
					for( i = 0; i < sizeof(list); i++)
html = html + "<a href=\"/cgi/sg_help.cgi?=" + list[i] + "\">" + topics[list[i]]["t"] + "</a>\n<br>";
				};
			};

			list = topics[arg]["parent"];
			if( !list )list = ({ });
			list = list - ({"topics", "classes", "new"});
			if( sizeof(list) ){
				html = html + "<hr>";
				html = html + "<h3>本主题所属类：</h3>";
				for( i = 0; i < sizeof(list); i++)
html = html + "<a href=\"/cgi/sg_help.cgi?=" + list[i] + "\">" + topics[list[i]]["t"]+ "</a>\n<br>";
			};

			if(sizeof(topics[arg]["related"])){
				html = html + "<hr>";
				html = html + "<h3>相关帮助：</h3>";
				list = sort_array(topics[arg]["related"], 1);
for( i = 0; i < sizeof(list); i++)html = html + "<a href=\"/cgi/sg_help.cgi?=" + list[i] + "\">" + topics[list[i]]["t"]+ "</a>\n<br>";
			};
		};
	};

	html = html + @END_HTML
<hr>
<br>
<form action="/cgi/sg_help.cgi" METHOD="get">
Please enter keyword here:
<input type="text" name="" size=20>
<input type="submit" value="Search">
</body>
</html>
END_HTML;
	
	return html;
}
