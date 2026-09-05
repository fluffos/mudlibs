// /d/changbai/xuedi.h

#include <ansi.h>
int storm(object me);

void init()
{
	object ob;
	if( interactive( ob = this_player()))
	storm(ob);
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
