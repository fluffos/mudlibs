#include <ansi.h>
inherit NPC_TRAINEE;

void create()
{
        set_name("伊犁马", ({"horse", "yili ma", "ma"}));
        set_weight(35000);
	    set("race", "马类");
        set_max_encumbrance(80000);
        set("long", "一匹良种的伊犁马，可以驮东西,可以骑(ride)、下(xia)、停(stay)。\n");
        set("msg_fail", "$n冲着$N怒嘶一声，一摆头向旁边走去！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低鸣一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("ride_msg","一跃身骑");
        set("wildness", 1);
        set("combat_exp", 1000);
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
  	object target, ob;
    
    if ( objectp(ob=this_object()->query_temp( "rider" ) ) &&
    	   environment()!=environment(ob) )
	{
		destruct(this_object());
		return;
	}//修改由于马被人骑走，但是中间跟丢的情况
    
    if(!environment()) return;
    if(sizeof(environment()->query("exits")) == 0) return;
    if( !mapp(exits = environment()->query("exits")) ) return;

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
	if (query("move_point")>=360)
	{
		set("move_point",1);
		randommove();
	}
	::heart_beat();
}