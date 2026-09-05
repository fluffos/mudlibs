//  zinebook 人物传记
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
        set_name(CYN"人物传记"NOR, ({ "zine's zhuanji","zhuanji", "novel"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "卷");
				set("long", "这是一卷人物传记，记载了"HIC"我踏月色而来"NOR"编写襄阳地图的故事，你可以看看(kan)。\n");
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
            tell_object(me,color[random(sizeof(color))]+"第一页上写着，我踏月色而来，朝廷一品鹿鼎公，本日夜勤练武功不辍。\n"NOR);
            call_out("study2", 4, me);
            me->set_temp("personalbook/read",1);
            return 1;
        }
	}

int study2(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"在一个风雨交加的夜晚，我踏月色而来看到了大神杰森贴出的悬赏告示。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"为了梦寐以求的天，我踏月色而来决定撕下皇榜。\n"NOR);
		call_out("study3", 4, me);
		return 1;
	}

int study3(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"于是我踏月色而来开始不断地在襄阳挖路，修桥的过程。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"其间不断得到老牌地产商杰森大神的的帮助。\n"NOR);
		call_out("study4", 4, me);
		return 1;
	}

int study4(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"很快，襄阳所有的路修好了，我踏月色而来说道：让这里起点房子吧。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"于是有了这么多房间。\n"NOR);
		call_out("study5", 4, me);
		return 1;
	}
			
int study5(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"我踏月色而来又说：让这里有些可爱的小动物吧。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"于是这里出现了鳄鱼和巨蟒。\n"NOR);
		call_out("study6", 4, me);
		return 1;
	}

int study6(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"一切都很好。我踏月色而来又说：让这里有人来玩吧。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"但是很可惜，这里暂时不开放。\n"NOR);
		call_out("study7", 4, me);
		return 1;
	}

int study7(object me)
	{
        string * color=({HIR,HIY,HIG,HIC,CYN,MAG,HIM,HIW});
		tell_object(me,color[random(sizeof(color))]+"七天过去了，我踏月色而来要休息了。\n"NOR);
		tell_object(me,color[random(sizeof(color))]+"我们大草原再见。\n"NOR);
        me->delete_temp("personalbook/read");
		return 1;
	}
		
