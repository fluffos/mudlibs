// Flee@Sgz July 22 1999
#include <mudlib.h>

string get_all()
{
	string ret;
	object *players;

	ret="<center><table board=2 cellspacing=0>";
	players = users();
	foreach(object o in players){
		if( !objectp(o) )	continue;
		if( !o->query_body() )	continue;
		ret+= "<tr><td align=left><a href=\"/cgi/sg_who.c?="
			+o->query_body()->query_primary_id()+"\">"+
			o->query_body()->in_room_desc()+"</a></td></tr>";
	}
	return ret+"</table></center>";
}
string main(string arg)
{
	string html, who;

	html=@HTML
<html><body topmargin="12" background="http://sgz.yesite.com/images/desk5.gif" text="#FFFFFF">
<br><head><h2>三国志在线玩家列表</h2></head>
HTML;
	if( arg&&arg!=""&&stringp(arg) )
		html = html + FINGER_D->get_finger(arg, 1);
	else 
		html = html + get_all();

	html = html + @END
</body></html>
END;
	return html;
}
