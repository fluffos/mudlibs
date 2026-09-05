// Created by iszt@pkuxkx, 2007-03-14

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj, ob, * inv;
        string killall_msg;
        int i;

        if( environment(me)->query("no_fight") )
                return notify_fail("这里禁止战斗。\n");

        if (me->is_busy())
            return notify_fail("你正忙着呢！\n");

        inv = all_inventory(environment(me));

        if(arg && !objectp(ob = present(arg, environment(me))))
                return notify_fail("你想杀谁？\n");

        if(arg == "menggu bing"  || arg == "menggu qibing" || arg == "qibing")
        {
                if(!present("menggu bing", environment(me)) && !present("menggu qibing", environment(me)))
                        return notify_fail("这里没有蒙古兵，你没糊涂吧？\n");
                if(!stringp(killall_msg = me->query("env/killall_msg")))
                        killall_msg = "呼喝声中，纵身闯入蒙古大军的重重包围，奋勇杀敌";
        }
        else
                if(!stringp(killall_msg = me->query("env/killall_msg")))
                        killall_msg = "长笑一声，开始对周围众人痛下杀手";

        for(i=sizeof(inv)-1; i>=0; i--)
        {
                obj=inv[i];
                if(userp(obj))
                        continue;
				
              if (obj->query("uni_target") && obj->query("uni_target") != me) continue;
							if (obj->query("is_suicongdizi")) continue;

			  if(!me->visible(obj)) continue;

                if(arg && !obj->id(arg) )
                        continue;
                if(!living(obj) && random(4))
                        continue;
                if(load_object(__DIR__"kill")->invalid_kill(me, obj))
                        continue;
                if(obj->id("guo jing"))
                        continue;
                if(obj->query("is_huoji"))
                        continue;
                if(stringp(killall_msg))
                {
                        message_vision(HIY + "$N" + killall_msg + "！\n" + NOR, me);
                        killall_msg = 0;
                }
                me->kill_ob(obj);
                obj->kill_ob(me);
                if(sizeof(me->query_enemy()) >= 10)
                        break;
        }
	if (me->query("shaqi") >= 400)
		message_vision("$N面目狰狞，仿佛难以遏制心中的杀气。\n",me);
	if ( me->query("shaqi") >= 500 )
	{
		message_vision(HIR"$N忽然语无伦次，显然杀气过重，控制不了自己的行动了！\n"NOR, me);
		me->unconcious();
	}
        
        if(killall_msg)
                return 0;
        else
                return 1;
}
