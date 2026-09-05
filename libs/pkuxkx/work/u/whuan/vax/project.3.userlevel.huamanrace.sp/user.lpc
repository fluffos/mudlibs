// user.c

#include <origin.h>
#include <user.h>
#include <ansi.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;

nosave int last_age_set;

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
    if( query("pet_died") )
	add("pet_died", time() - last_age_set);
    last_age_set = time();
    set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

// Dewolf/vax@pkuxkx 2006.1.6  This function updates player's level, called by heart_beat()
void update_level()
{
	int curr_level, bug_sign, shuld_be_level, my_exp;
	
	bug_sign = 0;
	curr_level = (int)query("level");
	if (curr_level < 0)
	{
		curr_level = 0 ;
		bug_sign = 1;
	}
	else if (curr_level > 50)
	{
		curr_level = 50 ;
		bug_sign = 2;
	}
	my_exp = (int)query("combat_exp");
	if (my_exp < 1)
	{
		my_exp = 1;
		bug_sign = 3;
	}
	else if(my_exp > 12588800)
	{
		my_exp = 12588800;
		//bug_sign = 4; this line stop high_exp user get level
	}
	shuld_be_level = (int)(pow(my_exp/100.0,0.3333));
	
	if (!bug_sign)
	{
		if (curr_level + 1 <= shuld_be_level )
		{
			add("level", 1);
			tell_object(this_object(), HIY"你的等级提升了！\n"NOR);
			tell_object(this_object(), HIY"你的特别潜能点增加了！\n"NOR);
			if (curr_level <= 5)
			{
				tell_object(this_object(), "如何使用特别潜能点，请参考 "HIG"help user-level\n"NOR);
			}
		}
	}
}

void setup()
{
    // We want set age first before new player got initialized with
    // random age.
    update_age();

    ::setup();
    restore_autoload();
}

//private
void user_dump(int type)
{
	//jason添加这个东西，以冒充有更多的玩家，希望能吸引人来玩。
	//人多了以后，可以渐渐去掉。不知道能不能起作用。
	if(query("noDeadNetnoIdle") == "Pkuxkx")
		return;
    switch(type) {
    case DUMP_NET_DEAD:
	tell_room( environment(), query("name") + "断线超过 "
	  + NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
	command("quit");
	break;
    case DUMP_IDLE:
	if (!wizardp(this_object()))
	{
	    tell_object( this_object(), "对不起，您已经发呆超过 "
	      + IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
	    tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
	      + "化为一堆飞灰，消失了。\n", ({this_object()}));
	    command("quit");
	}
	break;
    default: return;
    }
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
//private
void net_dead()
{
    object link_ob;

    set_heart_beat(0);
    if( objectp(link_ob = query_temp("link_ob")) )
	destruct(link_ob);

    // Stop fighting, we'll be back soon.
    remove_all_enemy();
	set_temp("netdead", 1);
    if( userp(this_object()) ) {
		if(this_object()->query("noDeadNetnoIdle") != "Pkuxkx")
		{
			call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
			tell_room(environment(), query("name") + "断线了。\n", this_object());
		}
		CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
    } else {
	command("quit");
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

int is_user_ob()
{
	return 1;
}

