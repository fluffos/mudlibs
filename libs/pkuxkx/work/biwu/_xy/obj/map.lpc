//  ghc 襄阳地图
//  created by zine 28 Aug 2010
//  edited by zine 28 Aug 2010
inherit ITEM;
#include <ansi.h>

void init()
	{
		add_action("do_study", "yanjiu");
	}

void create()
	{
        set_name(HIW"襄阳地形图"NOR, ({"map", "tu"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "张");
				set("long", "这是一张襄阳地形图，你可以从中研究(yanjiu)到一些东西。\n");
				set("value", 1);
            }
        setup();
	}

int do_study(string arg)
	{
        object me,ob;
        me = this_player();
        ob = this_object();
		if(me->is_busy() || me->is_fighting())
			{
				return notify_fail("你正忙着哪！\n");
			}
		else 
			{
				if(me->query_skill("literate",1) <= 200)
					{
						return notify_fail("以你目前的修为，似乎不能从地图中研究到什么。\n");
					}
				else
					{
						me->set_temp("xiangyang/xxpass",1);
						me->set_temp("xiangyang/lakepass",1);
						me->set_temp("xiangyang/xypass",1);
						message_vision(HIG"$N仔细研究了襄阳地形图，不禁喜形于色。\n"NOR, me);
						tell_object(me,HIG"你发现城东的湖底，和城北小巷的秘密。\n"NOR);
						me->add_busy(2+random(2));
						call_out("des", 2, ob);
						return 1;
					}
			}
	}
int des(object ob)
	{
		message_vision(WHT"地图竟遇风自燃起来，片刻只剩下灰烬。\n"NOR, ob);
        if (ob)
        {
		destruct(ob);
        }
	    return 1;       
	}
