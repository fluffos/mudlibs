#include <weapon.h>
#include <skill.h>
inherit SWORD;
int do_study(string arj);
void create()
{
        set_name("圣火令", ({ "shenghuo ling", "ling" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
        set("long",
        "这是一块黝黑发亮的铁块，正反两面写满了奇怪的文字。\n");
                set("material", "blacksteal");
                set("value", 5000);
               set("wield_msg",
"只听见「飕」地一声，$N的手中已经多了一把黑黝黝的$n。\n");
                set("unequip_msg", "$N随手将$n插入腰间。\n");
		set("mingjiao",1);
        }
	init_sword(40);
        setup();
}
 void init()
{
        add_action("do_study","study");
}
int do_study(string arg)
{
        object me;
        me = this_player();
        
        if ( arg != "ling" || arg != "shenghuo ling" )
        	return notify_fail("你要读什么？\n");
        if ( (int)me->query_skill("fanwen", 1) < 1)
        {
                write("你不懂梵文，无法领会上面的东西。\n");
                return 1;
        }
	if ( (int)me->query_skill("jiuyang-shengong", 1) < 20)
	{
      		write ("你的九阳神功的级别太低了，领悟不了上面的文字. \n");
      		return 1;
   	}
   	if( (int)me->query("jing") > 30 )
 	{
        	me->add("jing", -30);
        	message_vision("$N正专心研读圣火令上的功夫。\n", me);
        	if((int)me->query_skill("shenghuo-lingfa",1)*(int)me->query_skill("shenghuo-lingfa",1)*(int)me->query_skill("shenghuo-lingfa",1)/10 > me->query("combat_exp"))
        	{
	                write("也许是缺乏实战经验，你对圣火令上的内容总是无法领会。\n");
        	        return 1;
        	}
        	if ( (int)me->query_skill("shenghuo-lingfa", 1) < 101)
        	{
              		me->improve_skill("shenghuo-lingfa", (int)me->query_skill("fanwen", 1)/5+1);
                	write("你对着圣火令琢磨了一回儿，似乎颇有点心得。\n");
                	me->set_temp("wall_learned",1);
        	}
 	}
    	else
             write("你现在过于疲倦，无法专心下来研读新知。\n");
        if ( !me->query_temp("wall_learned") )
            write("你对着圣火令琢磨了一回儿，发现上面所载的太过浅显，对你来说已毫无意义了。\n");
        return 1;
}
