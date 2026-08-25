#include <mudlib.h>
#include <ansi.h>

#define SAVE_FILE "/data/daemons/history_d"
#define DELE_TIME  604800 // One week
#define BACKUP_TIME  604800*4 // four weeks

inherit M_ACCESS;

private mapping hisdata;
private mapping oldhisdata;
private mapping wizdata;
private nosave int logout;

void do_upgrade();

void save_data()
{
	unguarded(1, (: save_object, SAVE_FILE, 1 :));
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
	if( !hisdata || !mapp(hisdata) )hisdata = ([ ]);
	if( !oldhisdata || !mapp(oldhisdata) )oldhisdata = ([ ]);
	if( !wizdata || !mapp(wizdata) )wizdata = ([ ]);
	call_out("do_upgrade", 6);
}
void do_upgrade()
{
	int *time;
	int back_time;

	time = keys(wizdata);
	time = filter_array(time, (: $1+DELE_TIME<=time() :));
	foreach(int tt in time)map_delete(wizdata, tt);

	remove_call_out("do_upgrade");

	
	time = keys(hisdata);

	back_time=time()-BACKUP_TIME;
	time = filter_array(time, (: $1<=$(back_time) :));
	foreach(int tt in time) {
		oldhisdata[tt]=hisdata[tt];
		map_delete(hisdata, tt);
	}

	remove_call_out("do_upgrade");

	
	call_out("do_upgrade", 3600); // call it once an hour
	return 0;
}
string get_new_msg(int last)
{
	int tt, *time;
	string msg;

	logout = last;
	time = keys(wizdata);
	time = filter_array(time, (: $1>logout :));
	time = sort_array(time, 1);
	msg  = HIC+"◎"+HIY+mud_name()+"巫师通告"+HIC+"◎"+NOR+"\n\n";
	foreach(tt in time)
		msg = msg + CHINESE_D->chinese_time(tt) + "\n" + wizdata[tt] + "\n\n";

        time = keys(hisdata);
        time = filter_array(time, (: $1>logout :));
	time = sort_array(time, 1);
        msg  = msg + HIC+"◎"+HIY+mud_name()+"大事记"+HIC+"◎"+NOR+"\n\n";
        foreach(tt in time)
		msg = msg + mud_name() + hisdata[tt][0] + "\n" + hisdata[tt][1] + "\n\n";

	return msg;
}
void add_hisdata(string msg)
{
	int time;
	string mud_time;
	int *day;

	time = time();
	day  = DAY_D->query_date();
	mud_time = chinese_number(day[3])+"年"+
		chinese_number(day[2])+"月";
	if( day[1] > 7 ) mud_time = mud_time + "下旬";
	else if( day[1] < 4 ) mud_time = mud_time + "上旬";
	else mud_time = mud_time + "中旬";

	if( member_array(time, keys(hisdata)) != -1 ){
		SGSYS("Key "+time+" is used already");
		return;
	} 
	hisdata[time] = ({mud_time, msg});
	save_data();

	return;
}
void add_wizdata(string msg)
{
	int time;

        time = time();
        if( member_array(time, keys(wizdata)) != -1 ){
		SGSYS("Key "+time+" is used already");
		return;
        }
	if( objectp(this_body()) )
		wizdata[time] = HIW+this_body()->short()+NOR+"发布消息："+msg;
	else wizdata[time] = HIW+"系统"+NOR+"发布消息："+msg;

	save_data();

        return;
}
string wiz_for_web()
{
	int *time;
	string html;

	time = keys(wizdata);
	time = sort_array(time, 1);
	html = "<center><table border=0 cellspacing=3 cellpadding=3>";

	foreach(int tt in time){
		html = html + "<td align=left>"+CHINESE_D->chinese_time(tt)+
			"<br>"+wizdata[tt]+"</td><tr><td></td><tr>";
	};

	html = html + "</table></center>";
	html = replace_string(html, "%^H_WHITE%^", "<font color=fffffff>");
	html = replace_string(html, "%^RESET%^", "<font color=fffffff>");

	return html;
}
string his_for_web()
{
        int *time;
        string html;

	logout = time();
        time = keys(hisdata);
	time = filter_array(time, (: $1+DELE_TIME>logout :) );
        time = sort_array(time, 1);
        html = "<center><table border=0 cellspacing=3 cellpadding=3>";

        foreach(int tt in time){
                html = html + "<td align=left>"+hisdata[tt][0]+
                        "<br>"+hisdata[tt][1]+"</td><tr><td></td><tr>";
        };

        html = html + "</table></center>";
        html = replace_string(html, "%^H_WHITE%^", "<font color=fffffff>");
        html = replace_string(html, "%^RESET%^", "<font color=fffffff>");
        html = replace_string(html, "%^H_CYAN%^", "<font color=fffffff>");

        return html;
}

int* check_num() {
	return ({sizeof(hisdata),sizeof(oldhisdata),sizeof(wizdata)});
}
