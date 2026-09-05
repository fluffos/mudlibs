//  maperbook 人物传记
//  created by zine 28 Aug 2010
//  edited by zine 11 Oct 2010
inherit ITEM;
#include <ansi.h>

void init()
	{
		add_action("do_study", "kan");
	}

void create()
	{
        set_name(CYN"人物传记"NOR, ({ "maper's zhuanji","zhuanji", "novel"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "卷");
				set("long", "这是一卷人物传记，记载了"HIC"地图使者"NOR"生平的故事，你可以看看(kan)。\n");
				set("value", 3000);
            }
        setup();
	}

int do_study(string arg)
	{
        object me,ob;
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
        me = this_player();
        ob = this_object();
        if (me->query_temp("personalbook/read"))
        {
            tell_object(me,WHT"你已经开始读这本传记了，好好读完它吧。\n"NOR);
            return 1;
        }
        else
        {
            tell_object(me,color[random(sizeof(color))]+"你翻开了人物传记，并大声朗读。\n"NOR);
            tell_object(me,color[random(sizeof(color))]+"第一页上写着，地图大师，后被小希导演选中做男一号，取艺名：麦普。\n"NOR);
            call_out("study2", 4, me);
            me->set_temp("personalbook/read",1);
            return 1;
        }
	}

int study2(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"平生最得意两件事：\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"一为画得北侠地图一张，\n"NOR);
		call_out("study3", 4, me);
		return 1;
	}

int study3(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"二为有幸成为小希导演的男一号。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"Zine按：画地图大法利国利民，当巫师前我一直在用。\n"NOR);
		me->delete_temp("personalbook/read");
		return 1;
	}

