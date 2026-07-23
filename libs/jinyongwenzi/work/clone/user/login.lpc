#include <login.h>

#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;

void create()
{
	set_temp("pob", previous_object(-1));
}

void logon()
{
	if (!find_object(LOGIN_D)) {
		write("游戏尚未启动完毕，请等五秒再来。\n");
		destruct(this_object());
		return;
	}
	call_out( "time_check", 30 );
	LOGIN_D->logon( this_object() );
}

// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
void net_dead()
{
	remove_call_out("time_out");
	call_out( "time_out", 1 );
}

void time_out()
{
	object me = this_object();
	object ob = query_temp("body_ob");

// add by Yu Jue 1997.08.31
	if (objectp(ob) && environment(ob)) return;
	if (interactive(me))
		write("您花在连线进入手续的时间太久了，下次想好再来吧。\n");
	destruct(me);
}

void time_check()
{
	string id = query("id");

	if (!id || file_size("/data/login/"+id[0..0]+"/"+id+".o") > 0) {
		time_out();
		return;
	}

	call_out( "time_out", LOGIN_TIMEOUT );
}

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}

void receive_message(string type, string str)
{
	if( type!= "write" ) return;
        if (query_temp("big5")) str = "/adm/daemons/gb_b5d"->gb_b5(str);
	receive(str);
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
}

void window_size(int x, int y)
{
	set_temp("window_size/x", x);
	set_temp("window_size/y", y);
}

void telnet_suboption(string opt)
{
	set_temp("telnet_suboption", opt);
}

// Protect login object's data against hackers.
nomask mixed set(string prop, mixed data)
{
	if( geteuid(previous_object()) != ROOT_UID
	&& base_name(previous_object()) != USER_OB ) return 0;
	return ::set(prop, data);
}
