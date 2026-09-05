// /d/changbai/firn.h

#include <ansi.h>
int storm(object me);

void init()
{
	int i, flag = 0;
	object ob, *inv;
	if( interactive( ob = this_player()))
	{
        	storm(ob);
        	if(!mapp(query("luding_maze")))
        	set("luding_maze",
        	(["period" : 10,
        	  "delay" : -20,
        	  "max_amount" : 3,
        	  "odds" : 60,])
        	);

        	if(!query("luding_npc"))
        	set("luding_npc", ({__DIR__"npc/whitebear", __DIR__"npc/wolf"}));

        	//产生新的怪物的代码
        	inv = all_inventory(this_object());
                for(i = 0; i < sizeof(inv); i++)
                {
                	if(inv[i]->is_character() && !interactive(inv[i]))
                	flag = 1;
                }
        	if(!flag)
        	NPCGEN_D->npc_gen(query("luding_maze"), query("luding_npc"), this_object());
	}
}

int storm(object me)
{
	int i, flag;
	object *inv;
        int qi = me->query("qi");

        inv = all_inventory(me);
        for(i = 0; i < sizeof(inv); i++)
        {
        	if(inv[i]->query("id") == "pi qiu" && inv[i]->query("equipped"))
        	flag = 1;
        }

	if( environment(me) == this_object())
	{
                 if( !flag )
                 {
                         tell_object(me, HIR"\n一股刺骨的寒风吹过，你只觉得浑身的血液都快被冻住了！\n"NOR);
                         write("看来不穿一件保暖的外衣，一定会被冻死的！\n");

                         me->start_busy(1);
                         me->receive_damage("qi", 10 + random(50), "冻");
                         me->receive_wound("qi", 10 + random(20), "冻");
         		if( environment(me) == this_object())
         		call_out("storm", 5 + random(5) , me);
                 }
                 else
                 tell_object(me, HIC"\n一股刺骨的寒风吹过，你将皮裘裹得更加严实了！\n"NOR);
	}
        return 1;
}

int valid_leave(object me, string dir)
{
	int i;
	object *inv;
	inv = all_inventory(this_object());
	for(i = 0; i < sizeof(inv); i++)
	{
		if(inv[i]->query("luding_monster"))//或者其他什么标记
		return notify_fail("你看见形势不妙转身想逃，却被"+ inv[i]->name() + "飞身拦住。\n");
	}
       return ::valid_leave(me, dir);
}