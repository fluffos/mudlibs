// Cgi programs for checking, finding .. etc emotes
// Flee@sgz, August 25, 1999

#include <mudlib.h>
#include <daemons.h>

#define MAX_SIZE_ALLOWED 16

inherit M_GLOB;

private string *alls;

string check_chinese(string cc);
string check_english(string ee);
string find_all();

void create()
{
	alls = sort_array(SOUL_D->list_emotes(), 1);
	return;
}
string main(string arg)
{
	string html;

	html=@HTML
<html><body background="http://sgz.yesite.com/images/desk5.gif" text="#FFFFFF" link=yellow vlink=yellow alink=yellow>
HTML;
	if( !arg||!stringp(arg)||arg=="" ) html+=find_all();
	else if( sizeof(arg)>= MAX_SIZE_ALLOWED ) html+="<br><center><h2>Too long argument!</h2></center><br><br><br>";
	else if(arg[0]>96&&arg[0]<123) html+=check_english(arg);
	else if( sizeof(arg)<4 ) html+="<br><center><h2>Too short argument!</h2></center></br>";
	else html+=check_chinese(arg);

	html = html + @END_HTML
<hr><br>
<form action="/cgi/sg_emote.cgi" METHOD="get">
Please enter keyword here:
<input type="text" name="" size=20><input type="submit" value="Search">
</body></html>
END_HTML;

	return html;
}
string check_english(string ee)
{
	int i;
	string out, *list;
	mixed data;

	out ="<center><h2>三国志情感动词查找："+ee+"</h2></center><br>";
	if( !has_magic(ee) ) ee+="*";
	ee = "^"+translate(ee)+"$";
	list = regexp(alls, ee);
	if( !list||!arrayp(list)||!sizeof(list) ) out = "<br><center><h2>No emote found!</h2></center><br><br><br>";

	out+= "<center><table border=1 cellspacing=3 cellpadding=3>";
	data = SOUL_D->query_emote(list[0]);
	foreach(mixed mm in keys(data)){
		if (stringp(data[mm]) )
            		out+=sprintf("<tr><td>%O -> %s</td></tr>", mm, data[mm]);
        	else
            		out+=sprintf("<tr><td>%O -> %s\n</tr></td>", mm, implode(data[mm], "\n\t-> "));
	}
	out+="</table></center>";
	out+="<p><br><center>相近的动词有：</center><br><center><table border=0 cellspacing=3 cellpadding=3>";
	foreach(string ss in list){
		if( i>=4 ) { i=0; out+="</tr><tr>"; }
		i++;
		out+=sprintf("<td align=left><a href=\"/cgi/sg_emote.cgi?=%s\">%s</a></td>",ss, ss);
	}
	out+="</table></center>";

	return out;
}
string find_all()
{
	int i;
	string out;
	out ="<center><h2>三国志情感动词查找：全体</h2></center><br>";
	out+="<center>三国志情感动词列表</center><br><center><table border=1 cellspacing=3 cellpadding=3>";
        foreach(string ss in alls){
                if( i>=8 ) { i=0; out+="</tr><tr>"; }
                i++;
                out+=sprintf("<td align=left><a href=\"/cgi/sg_emote.cgi?=%s\">%s</a></td>",ss, ss);
        }
        out+="</table></center>";

        return out;
}
int trans_char_to_num(string ss)
{
	int all;

	if( ss[0]>=48&&ss[0]<=57 ) all = (ss[0]-48)*16;
	else all = (ss[0]-55)*16;
	if( ss[1]>=48&&ss[1]<=57 ) all+= ss[1]-48;
        else all+= ss[1]-55;

	return all;
}
string trans_code_to_chinese(string cc)
{
	int a;
	string back, *list;

	list = explode(cc, "%");
	back = "";
	foreach(string ss in list){
		a = trans_char_to_num(ss);
		back+=sprintf("%c", a);
	}
	return back;
}
string check_chinese(string cc)
{
	int i;
	string out, *list, *tmp;

	cc = trans_code_to_chinese(cc);
	list = SOUL_D->emote_apropos(cc);
	out ="<center><h2>三国志情感动词查找："+cc+"</h2></center><br>";	

	if( !list||!arrayp(list)||!sizeof(list) ) out+="<br><center><h2>No emote found!</h2></center><br><br><br>";
	else {
		out+= "<center><table border=1 cellspacing=3 cellpadding=3>";
		foreach(string ss in list){
			if( i>=5 ) { i=0; out+="</tr><tr>"; }
                	i++;
			tmp = explode(ss, " ");
			out+=sprintf("<td align=left><a href=\"/cgi/sg_emote.cgi?=%s\">%s</a></td>",tmp[0], ss);
		}
	}
	out+="</table></center>";

	return out;
}

