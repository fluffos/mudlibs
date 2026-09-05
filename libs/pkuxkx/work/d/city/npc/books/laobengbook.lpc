//  laobengbook 人物传记
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
        set_name(CYN"人物传记"NOR, ({ "laobeng's zhuanji","zhuanji", "novel"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "卷");
				set("long", "这是一卷人物传记，记载了"HIC"老蹦"NOR"生平的故事，你可以看看(kan)。\n");
				set("value", 10000);
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
            tell_object(me,color[random(sizeof(color))]+"第一页上写着，老蹦，性别，男，年龄，359岁。\n"NOR);
            call_out("study2", 4, me);
            me->set_temp("personalbook/read",1);
            return 1;
        }
	}

int study2(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"14岁入武当，小学老师谷虚。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"14-18岁，中学老师宋远桥，期间取得少林达摩院函授资格。\n"NOR);
		call_out("study3", 4, me);
		return 1;
	}

int study3(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"18岁-42岁，大学老师张三丰。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"43岁，老师已不堪所学，成功取得武当学士学位。\n"NOR);
		call_out("study4", 4, me);
		return 1;
	}

int study4(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"45岁，成功太极解密，取得硕士学位。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"45岁-123岁，自行深造武当所学，已达武当博士水平。\n"NOR);
		call_out("study5", 4, me);
		return 1;
	}
			
int study5(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"123岁，经金庸ISO论证，取得出师资格。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"123岁-268岁，主要工作为武当静修阁悟道，期间顺利取得蜡像资格 。\n"NOR);
		call_out("study6", 4, me);
		return 1;
	}

int study6(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"268岁，经与武当院长张三丰友好协商，同意留学全真。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"268岁至今，尽得全真所学，拥有全真博士学位。\n"NOR);
		me->delete_temp("personalbook/read");
		return 1;
	}


