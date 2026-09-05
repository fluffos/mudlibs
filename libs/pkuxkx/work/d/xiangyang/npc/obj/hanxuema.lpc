#include <ansi.h>

inherit NPC_TRAINEE;

void create()
{
        set_name(RED"汗血宝马"NOR, ({"hanxue ma", "horse", "ma"}));
        set_weight(30000);
        set_max_encumbrance(70000);
	    set("race", "马类");
        set("long", "一匹十分罕见的宝马,乃漠北高山上五色野马与家马杂交而得。\n");
        set("msg_fail", "$n冲着$N怒嘶一声，一摆头向旁边走去！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低鸣一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("ride_msg","一跃身骑");
        set("wildness", 50);
        set("combat_exp", 10000);
        set("horse",1);
        set("max_qi", 10000);
        set("qi", 10000);

        setup();
        
}


void randommove()
{
    mapping exits;
    string *dirs;
    int i;
	object target;

    if(!environment()) return 0;
    if(sizeof(environment()->query("exits")) == 0) return 0;
    if( !mapp(exits = environment()->query("exits")) ) return 0;

	if(random(100) == 3)
	{
        dirs = keys(exits);
        i = random(sizeof(dirs));
        target = find_object(exits[dirs[i]]);
		if(objectp(target))
		{
			tell_room(environment(),query("name")+"不安的刨了刨前蹄，跑了。\n");
			this_object()->move(target);
			tell_room(target,"一匹"+query("name")+"跑了过来。\n");
		}
	}
}
int heart_beat()
{
	add("move_point",1);
	if (query("move_point")>=100)
	{
		set("move_point",1);
		randommove();
	}
	::heart_beat();
}