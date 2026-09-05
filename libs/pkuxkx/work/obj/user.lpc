#pragma save_binary
// user.c

#include <origin.h>
#include <user.h>

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

	id = query("id", 1);
	if( !id ) id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}
int save(int raw)
{
	int res;

	if(!raw) save_autoload();
	res = ::save();
	if(!raw) clean_up_autoload();		// To save memory
	return res;
}
/*int backup()
{
	int res;

	save_autoload();
	res = ::backup();
	clean_up_autoload();		// To save memory
	return res;
}
*/
// This function updates player's age, called by heart_beat()
void update_age()
{
	// Update the time we spend on mudding, using method from TMI-2 mudlib.
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	if (query("mud_age")-query("old_age")>=3600 && query("biaoju/score")>0 && query("biaoju/level")>0)
	{
		add("biaoju/score",-query("biaoju/level")/2);
		if(query("biaoju/score")<0)
                   set("biaoju/score",0);
		set("old_age",query("mud_age"));
	}
	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	mapping	fabao_map;
	string  *fabao_list, *id_list, *t_list;
	int		i;
	object	newob;
	string  fabao_id;

	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();

    // here We restore the self-made fabao
	fabao_map = query("fabao");
    if( !mapp(fabao_map) )
		return;

	fabao_list = keys(fabao_map);
	for(i=0; i<sizeof(fabao_list); i++)  {
        newob = new("/obj/fabao");
        if( newob )   {
            newob->set("owner_id", query("id"));
            newob->set("series_no", fabao_map[fabao_list[i]]);
            if( !newob->restore() )   {
				tell_object(this_object(), "不能 restore fabao. \n");
				destruct(newob);
				continue;
			}
			fabao_id = (string)newob->query("id");
			fabao_id = replace_string(fabao_id, " ", "_");
			newob->set("id", fabao_id);
			seteuid(fabao_id);
			export_uid(newob);
			seteuid(getuid());

			id_list = ({ fabao_id });
			t_list = explode(fabao_id, "_");
			if( sizeof(t_list) > 1)   {
				id_list += t_list;
			}
			newob->set_name(newob->query("name"), id_list);
			if( stringp(newob->query("default_file")) )
				newob->set_default_object( newob->query("default_file") );

			newob->save();
            newob->move(this_object());
        }
    }
}

protected void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "断线超过 "
				+ NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
			this_object()->set_temp("must_quit",1);
			command("quit");
			break;
		case DUMP_IDLE:
			if (wizardp(this_object())) return;
			tell_object( this_object(), "对不起，您已经发呆超过 " 
				+ IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
			tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
				+ "化为一堆飞灰，消失了。\n", ({this_object()}));
			this_object()->set_temp("must_quit",1);			
			command("quit");
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
protected void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	remove_all_enemy();

	set_temp("netdead", 1);
	if( userp(this_object()) ) {
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
             tell_room(environment(), query("name") + "断线了。\n", this_object());
             CHANNEL_D->do_channel(this_object(), "sys", "断线了。\n");
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
int check_array()
{
	object* team;
	team=this_object()->query_team();
	if (sizeof(team)==0)
		return 0;
	for(int i=0; i<sizeof(team); i++)
	{
		if (!present(team[i],environment(this_player())))
		{
			this_player()->dismiss_array("你的伙伴没有在这里。\n");
			return 0;
		}
	}
	return 1;
		
}
void dismiss_array(string message)
{      
        if (this_object()->query_temp("array/name"))
                SKILL_D(this_object()->query_temp("array/name"))->dismiss_array(this_object(),message);
}
