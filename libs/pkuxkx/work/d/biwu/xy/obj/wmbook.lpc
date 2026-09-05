//  武穆遗书
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
        set_name(HIC"武穆遗书"NOR, ({"book", "wumu book"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "册");
				set("long", "这是一本记载着岳王爷行军打仗心得的札记，你可以从中研究(yanjiu)到一些东西。\n");
				set("value", 1);
            }
        setup();
	}

int do_study(string arg)
	{
        object me,ob;
		me = this_player();
        ob = this_object();
		if(me->is_busy())
			{
				return notify_fail("你正忙着哪！\n");
			}
        if (ob->query("read"))
            {
                return notify_fail("你从武穆遗书中无法学得任何东西！\n");
            }
		else 
			{
				if(me->query_skill("literate",1) <= 200)
					{
						return notify_fail("以你目前的悟性，根本不能从武穆遗书中研究到什么。\n");
					}
				else
					{
						message_vision(HIC"$N仔细研究了武穆遗书，遇到不懂处与同门参详了一下。\n"NOR, me);
						me->add_busy(3);
                        ob->set("read",1);
						call_out("learnt", 8, me);
						return 1;
					}
			}
	}
int learnt(object me)
	{
		int i;
	    object* allp = all_inventory();
        
		for(i=0;i<sizeof(allp);i++)
			{
				if(userp(allp[i]) && allp[i]->query("family/family_name") == me->query("family/family_name"))
					{
						allp[i]->add_temp("apply/armor", allp[i]->query_skill("literate",1)/2);
						allp[i]->add_temp("apply/dodge", allp[i]->query_skill("literate",1)/2);
						allp[i]->set_temp("xiangyang/wmeffect",allp[i]->query_skill("literate",1)/2);
					}
				else
					{
						allp[i]->add_temp("apply/armor", -allp[i]->query_skill("literate",1)/2);
						allp[i]->add_temp("apply/dodge", -allp[i]->query_skill("literate",1)/2);
						allp[i]->set_temp("xiangyang/wmeffect",-allp[i]->query_skill("literate",1)/2);
					}
			}
        if(living(me))
        {
		    tell_object(me,WHT"先人用兵如神，你不尽叹服，此等神物不敢独享，你把它放回了原处。\n"NOR);
        }
		destruct(this_object());
		return 1;       
	}

