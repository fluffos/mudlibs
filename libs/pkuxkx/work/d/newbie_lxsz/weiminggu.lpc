// D:\xkx\d\liuxiu-shanzhuang\weiminggu.c未明谷
// labaz  2012/10/20.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int do_climb(string);
int do_get(string);
void climb_wait(object);
void climb_finish(object);
int do_west();
int do_hp();
int do_look();
void is_full();
int do_go(string);

void create()
{
    set("short", "未明谷");
    set("long", 
	"山谷中绿树成荫，却不见有多么明媚的花开于此，但你仍能闻见了远远
飘来的花香。耳边听到了溪水叮咚的声音，原来不远处有一条蜿蜒的小溪\n"+
YEL"(river)"NOR+"，岸边似乎散落了一些物什。在山谷的北侧有条陡峭的山坡"+YEL"(path)\n"NOR+
"隐隐可以通向外界。\n");

    set("outdoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "river":HIY"这是一条清澈的小溪，也许你可以拿起地上的葫芦"NOR+HBBLU"(get hulu)"NOR+HIY"，\n研究下"NOR+HBBLU"(l hulu)"NOR+HIY"用来盛溪水喝。\n"NOR,
		"path":HIY"这是一段陡峭的山坡，应该可以向上攀爬出去。"NOR+HBBLU"(climb up)\n"NOR,
        ]));

    set("exits", ([
        "west" : __DIR__"shulin",
        "east" : __DIR__"luanshizhen",
        "south" : __DIR__"qingshiqiaotou",
        ])
     );

	set("objects", ([
		__DIR__"obj/hulu" : 1,
		__DIR__"obj/yeguo" : 3,
	]));

    set("valid_startroom", 1);
	set("resource/water", 1);

	remove_call_out("is_full");
	call_out("is_full", 1);

    setup();
}

void init()
{	
	object me,weapon,here,hulu,yeguo;
	me=this_player();
    here=this_object();
    me->save();
    
    if (!objectp(present("hu lu",here)))
    {
        hulu=new(__DIR__"obj/hulu");
        hulu->move(here);
    }
    if (!objectp(present("ye guo",here)))
    {
        yeguo=new(__DIR__"obj/yeguo");
        yeguo->set_amount(3);
        yeguo->move(here);
    }
    
    if (1==me->query("newbie_village/master") && !objectp(present("taiyi jian",me)))
    {
        weapon=new(__DIR__"weapon/taiyijian");
        if (1==me->query("newbie_village/pfm"))
            weapon->set("long", "这是一柄只有太乙学徒才能使用的长剑。\n"+HIC"目前你可以使用太乙剑法的绝招：八方风雨(perform sword.bafang)\n"NOR);
        weapon->move(me);
    }

	
	if (me->query(NEWBIE_VILLAGE_INDEX)==get_questindex("用east、west、south等方向命令来探索未明谷周围的三块地方，并回到未明谷"))
	{
		if (3==(me->query_temp("newbie/shulin")+me->query_temp("newbie/luanshizhen")+me->query_temp("newbie/qingshiqiaotou")))
		{
			set_nextquest(me, "用east、west、south等方向命令来探索未明谷周围的三块地方，并回到未明谷", "把周围走了个遍，都没有发现有其他出口，还是从这里的山坡出去吧。", 20, 100);
		}
	}
	
	add_action("show_quest", "quest");
	add_action("do_climb", "climb");
	add_action("do_get","get");
	add_action("do_hp","hp");
    add_action("do_go","go");
	add_action("do_west","west");

	call_out("greeting",1,me);
}

void greeting(object me)
{
	if (!me->query(NEWBIE_VILLAGE_INDEX))
	{
		me->set(NEWBIE_VILLAGE_INDEX,1);
		me->set("food",1);
		me->set("water",1);
        tell_object(me,
HIG"一只云粉蝶飞来飞去，最终决定落在你脸上。你睁开眼睛，晴天暖云像是
一床被掀起来的锦被。你站起身来，抖了抖身上的灰尘，见四处绿草如茵，
黄色的野花和蒲公英点缀在这绿草床上。看着那只蝴蝶，你一时分不清楚是
蝴蝶进入了你的梦里，亦或是你进入了蝴蝶的梦中。
"NOR+GRN"你用可以"NOR+HIY"quest"NOR+GRN"命令了解你现在应该做些什么。\n\n"NOR
);
	}
}

int do_west()
{
	return do_go("west");
}

int do_get(string arg)
{
    object me;
	string failmsg;
	object hulu,here,yeguo;
	here = this_object();

	me=this_player();

	
	if (arg=="all")
	{
		tell_object(me,"做人不能太贪嘛，给其他有需要的人也留点。\n");
		return 1;
	}
	if (present("hu lu", me) &&( arg=="hu lu" || arg == "hulu"))
	{
		tell_object(me,"你身上已经有葫芦了，拿多了也是浪费。\n");
		return 1;
	}
	if (present("ye guo", me) && (arg=="ye guo")||present("guo", me) && (arg=="guo"))
	{
		tell_object(me,"你身上已经有野果了，拿多了也是浪费。\n");
		return 1;
	}

    if (0==call_other("cmds/std/get","main",me,arg))
    {
        if (stringp(failmsg=query_notify_fail()))
        {
            tell_object(me,failmsg);
        }
    }

    if (!objectp(present("hu lu",here)))
    {
        hulu=new(__DIR__"obj/hulu");
        hulu->move(here);
    }
    if (!objectp(present("ye guo",here)))
    {
        yeguo=new(__DIR__"obj/yeguo");
        yeguo->set_amount(3);
        yeguo->move(here);
    }

	return 1;
}

int do_climb(string arg)
{
    object me;
	me=this_player();
	
	if (me->is_busy()) return 0;
	
	if (arg!="up" && arg!="path")
	{
		tell_object(me,"你要往哪里爬？\n");
	}
	else
	{
		if (me->query(NEWBIE_VILLAGE_INDEX)>=get_questindex("使用look path命令，根据提示离开未明谷"))
		{
			me->start_busy(20);
			call_out("climb_wait",0,me);
			call_out("climb_wait",3,me);
			call_out("climb_wait",6,me);
			call_out("climb_finish",8,me);
		}
		else
		{
			tell_object(me,"你探索过未明谷周围的三块地方了吗?\n");
		}
		return 1;
	}
	return 1;
}

void climb_wait(object me)
{
    // object me;
	// me=this_player();
 
    if (0==check_questindex(me,"拿着刻有“柳秀山庄”的葫芦去柳秀山庄一问究竟"))
    {
        tell_object(me,RED"你用尽全力向上攀爬。\n"NOR);
    }
    else
    {
        tell_object(me,RED"你手足并用，飞快的向上攀爬。\n"NOR);
    }
}

void climb_finish(object me)
{
    // object me;
	// me=this_player();

    if (0==check_questindex(me,"拿着刻有“柳秀山庄”的葫芦去柳秀山庄一问究竟"))
    {
        message_vision("$N费了九牛二虎之力，终于爬了上来。发觉眼前竟又是一片开阔之处！\n\n", me);
    }
    else
    {
        message_vision("$N轻轻松松得爬了上来。\n\n", me);
    }
	
	me->move(__DIR__"huanpo");
	me->start_busy(0);
	set_nextquest(me, "使用look path命令，根据提示离开未明谷", "你看着怀里的葫芦，心想柳秀山庄会不会就在前面附近的地方。用localmaps命令可以查看附近地图。", 20, 100);
}

int do_hp()
{
    object me;
    string failmsg;
	me=this_player();
	
    if (0==call_other("/cmds/usr/hp", "main", me))
    {
        if (stringp(failmsg=query_notify_fail()))
        {
            tell_object(me,failmsg);
            return 1;
        }
    }
	
	set_nextquest(me, "你来到这个陌生的地方，前途未卜，请先用hp命令检查自己的身体情况", "你现在又渴又饿，看看在这里能否找到些吃的喝的。", 20, 100);
	return 1;
}

void is_full()
{
	object me;
	int i;
	object* all_inv = all_inventory();
	for(i=0;i<sizeof(all_inv);i++)
	{
		me = all_inv[i];
		if(userp(me) && check_questindex(me,"使用look river或者l river命令，根据提示先让自己喝饱吃足。地上的野果也可以捡起来充饥。(get ye guo;eat ye guo)") == 1)
		{
			if ((me->query("food")>=me->max_food_capacity()*80/100) && (me->query("water")>=me->max_water_capacity()*80/100))
			{
				set_nextquest(me, "使用look river或者l river命令，根据提示先让自己喝饱吃足。地上的野果也可以捡起来充饥。(get ye guo;eat ye guo)", "终于吃饱喝足了，你现在可以去周围探索下，看看有没有能直接出去的出口。", 20, 100);
			}
		}
	}
	remove_call_out("is_full");
	call_out("is_full", 1);
}

int valid_leave(object me,string dir)
{
	object *inv;
	int i;
	
	if (me->query(NEWBIE_VILLAGE_INDEX)<=get_questindex("使用look river或者l river命令，根据提示先让自己喝饱吃足。地上的野果也可以捡起来充饥。(get ye guo;eat ye guo)"))
	{
		return notify_fail("你又渴又饿，浑身无力，根本就走不动路。\n");
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		if (userp(inv[i])) return notify_fail("山路实在太陡了，你没法同时背着一个人爬上去。\n");
	}
	
	return ::valid_leave(me, dir);
}

int do_go(string arg)
{
    object who,shulin_fb;
    who=this_player();
    
    if (("west" == arg) && ( 1==check_questindex(who,"去未明谷的树林除掉老虎") ))
    {
        if (!objectp(shulin_fb=who->query_temp("newbie/shulin_room")))
        {
            shulin_fb=new(__DIR__"shulin_fb");
            if (shulin_fb) 
			{
				who->set_temp("newbie/shulin_room",shulin_fb);
				who->move(shulin_fb);
			}
        }
        else
        {
            who->move(shulin_fb);
        }
        return 1;
    }
    
    return 0;
}