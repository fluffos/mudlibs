//  tianmbook 人物传记
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
        set_name(WHT"人物传记"NOR, ({ "tianm's zhuanji","zhuanji", "novel"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "卷");
				set("long", "这是一卷人物传记，记载了"HIW"天命"NOR"编写生平的故事，你可以看看(kan)。\n");
				set("value", 38000);
            }
        setup();
	}

int do_study(string arg)
	{
        object me,ob;
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
        me = this_player();
        ob = this_object();
        if (!arg||arg!=this_object()->query("id"))
        {
            tell_object(me,WHT"你要看哪本传记？。\n"NOR);
            return 1;
        }
        if (me->query_temp("personalbook/read"))
        {
            tell_object(me,WHT"你已经开始读这本传记了，好好读完它吧。\n"NOR);
            return 1;
        }
        else
        {
            tell_object(me,color[random(sizeof(color))]+"你翻开了人物传记，并大声朗读。\n"NOR);
            tell_object(me,color[random(sizeof(color))]+"第一页上写着，李伏澜代笔。\n"NOR);
            call_out("study2", 4, me);
            me->set_temp("personalbook/read",1);
            return 1;
        }
	}

int study2(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"编者按：这是一个淫民道长。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"天命，男（女）生卒不详，性别不详，地址不详。\n"NOR);
		call_out("study3", 4, me);
		return 1;
	}

int study3(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"目前在江湖第一大老年大学攻读博士学位，\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"其博士导师是武当老年大学前校长，院士张三丰。\n"NOR);
		call_out("study4", 4, me);
		return 1;
	}

int study4(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"曾师从谷虚道长，儿子为了泡妞背叛老爹的武老大学宋远桥校长。。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"课余，天命同志长期兼职于林家镖局。\n"NOR);
		call_out("study5", 4, me);
		return 1;
	}
			
int study5(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"曾经获得武当十大杰出老年，\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"全国三八红旗手，全国五一劳动奖章。\n"NOR);
		call_out("study6", 4, me);
		return 1;
	}

int study6(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"其终身致力于将有限的生命贡献于无限的走镖事业中。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"在其漫长而又无聊的护镖生涯中结识了大量的工作伴侣，\n"NOR);
		call_out("study7", 4, me);
		return 1;
	}

int study7(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"如物流界大少爷某某某，目前已淡出江湖的某首富等实力派人士，某政府高官等。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"观天命同志的一生，一直走在时代的前列，是广大武老大学新生们的楷模。\n"NOR);
        me->delete_temp("personalbook/read");
		return 1;
	}
		
