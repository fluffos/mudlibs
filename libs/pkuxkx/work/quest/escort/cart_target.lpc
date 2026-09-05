//test
// /task/npc/target.c
//Made by jason@pkuxkx
//2001.1.3
inherit NPC;
#include <ansi.h>

int other_qi,other_jing;
int leave();

void create()
{
	string name,*tmp,*pinying;

	set("chat_chance",10);
	set("chat_msg",({
		(: random_move :),
	}));
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));	
	set("nickname",HIC"店铺伙计"NOR);
	set("gender",random(3)>0?"男性":"女性");
	set("no_get",1);
	set("uni_target",1);
	set("age",20);
	set("is_huoji",1);
	setup();
}

void start_leave(int leave_time)
{
	if ( !leave_time || leave_time<=240 )
		call_out("leave", 900);
	else
		call_out("leave", leave_time);
}

void die()
{
    object me,killer;
    me = this_object();
    if (objectp(killer = me->get_damage_origin_object()))
     	CHANNEL_D->do_channel(this_object(), "rumor",
                   sprintf(me->name() + "被" + killer->name() + "杀死了。"));
    else
    	CHANNEL_D->do_channel(this_object(), "rumor",
                   sprintf(me->name() + "莫名其妙地死了。"));
    ::die();
}

int random_move()
{
mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
        "out":          "外",
]);
	mapping exits;
	string *dirs;
	int i;
	if(!environment()) return 0;
	if(sizeof(environment()->query("exits")) == 0) return 0;
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	i = random(sizeof(dirs));
	if( !environment()->valid_leave(this_object(), dirs[i]) ) return 0;
	message_vision(this_object()->name() + "向" + default_dirs[dirs[i]] + "离开。\n",this_object());
	dirs = values(exits);
	this_object()->move(dirs[i]);
	message_vision(this_object()->name() + "身穿布衣走了过来。\n",this_object());
}

void unconcious()
{
	die();
}

int leave()
{
	if (!this_object()) return 1;
	CHANNEL_D->do_channel(this_object(), "qy", "唉！看来" + this_object()->query("dart_name") + "这镖是运不来了，我还是先回去吧！");
	if (environment(this_object()))
		message_vision("$N转身走了。\n",this_object());
	destruct(this_object());
	return 1;
}
