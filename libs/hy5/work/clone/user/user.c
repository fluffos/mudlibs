// user.c

#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_ENCODING;

static int last_age_set;

void create()
{
	::create();
	set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
	if( (int)query("potential") - (int)query("learned_points") < 100 )
		add("potential", 1);
	if( (int)query("thief") > 0 )
		add("thief", -1 );
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
	int res;

	save_autoload();
	res = ::save();
	clean_up_autoload();		// To save memory
	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	// Update the time we spend on mudding, using method from TMI-2 mudlib.
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();
}

private void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "断线超过 "
				+ NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
                        "/cmds/usr/quitgame"->main(this_object());
//			command("quitgame");
			break;
		case DUMP_IDLE:
                       if ((this_object()->query("id") != "hxsd") &&
                         (this_object()->query("id") != "guaf"))
                         {
			tell_object( this_object(), "对不起，您已经发呆超过 " 
				+ IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
			tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
				+ "化为一堆飞灰，消失了。\n", ({this_object()}));
                        "/cmds/usr/quitgame"->main(this_object());
//			command("quitgame");
                        }
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	remove_all_enemy();

	set_temp("netdead", 1);
	set_heart_beat(0);
if (this_object())
{
	if( userp(this_object()) ) {
if (this_object()->query("combat_exp") <100)
{
//"/cmds/usr/quithy"->main(this_object());
//"/cmds/usr/quitgame"->main(this_object());
//"/cmds/usr/quit"->main(this_object());
call_out("user_dump", 1, DUMP_NET_DEAD);
}else		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
if (this_object())
{
	    tell_room(environment(), query("name") + "断线了。", this_object());
	    CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
}
	} else {
               "/cmds/usr/quitgame"->main(this_object());
//		command("quitgame");
}
}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "重新连线完毕。\n");
}

