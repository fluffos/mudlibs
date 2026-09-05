//  dzlcbook 人物传记
//  created by zine 28 Aug 2010
//  edited by zine 28 Aug 2010
inherit ITEM;
#include <ansi.h>

void init()
	{
		add_action("do_study", "kan");
	}

void create()
	{
        set_name(CYN"人物传记"NOR, ({ "dzlc's zhuanji","zhuanji", "novel"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "卷");
				set("long", "这是一卷人物传记，记载了"HIC"地主老财"NOR"生平的故事，你可以看看(kan)。\n");
				set("value", 50000);
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
            tell_object(me,color[random(sizeof(color))]+"第一页上写着，地主老财，二零零八年秋来到北侠泥潭。\n"NOR);
            call_out("study2", 4, me);
            me->set_temp("personalbook/read",1);
            return 1;
        }
	}

int study2(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"初立志做一位百姓大侠，于钱塘江畔苦练玄铁剑法，\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"剑法虽成，但做胡一刀、萧峰任务不得要领，\n"NOR);
		call_out("study3", 4, me);
		return 1;
	}

int study3(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"遂研究task，发觉辟邪剑法乃做task之最佳武功，\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"故毅然投身东方阿姨门下。\n"NOR);
		call_out("study4", 4, me);
		return 1;
	}

int study4(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"期间苦心研究机器人技术，一年后完成全自动task机器人，\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"二零零九年国庆期间突飞猛进，\n"NOR);
		call_out("study5", 4, me);
		return 1;
	}
			
int study5(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"完成蜡像之身。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"后退隐江湖，不见踪迹。\n"NOR);
		me->delete_temp("personalbook/read");
		return 1;
	}
		
