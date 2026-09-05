// D:\xkx\d\liuxiu-shanzhuang\nvyushi.c女浴室
// labaz  2012/10/23
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int do_bath();
void reset_bath(object);
void mess(object,string);

void create()
{
    set("short", "女浴室");
    set("long", 
"这里是女子浴室，浴室很开阔，浴桶"+YEL"(yutong)"NOR+"一字排开，摆了
十余具，底下还有可以加热生火的小灶。看来山庄的女仆都在此处洗浴。\n"
);

    set("indoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "yutong":HIY"快把脏衣服脱光了"NOR+HBBLU+WHT"(remove cloth)\n"NOR+"，赶紧洗个澡。"+HBBLU+WHT"(bath)\n"NOR,
        ]));

    set("exits", ([
        "south" : __DIR__"exiangfang",
        ])
     );

	set("objects", ([
		__DIR__"npc/nvshitong" : 1,
	]));

    setup();
}

void init()
{
    add_action("do_bath","bath");
	add_action("show_quest", "quest");
}

int do_bath()
{
    object who;
	who=this_player();

    if (sizeof(who->query_temp("armor")))
    {
        return notify_fail("先把你的衣物给脱了(remove all)吧！\n");
    }

	if (0==who->query_temp("newbie/bath"))
	{
		who->set_temp("newbie/bath",1);
		who->start_busy(18);
		call_out("mess",1,who,"$N伸出一只脚，试了试，水温刚刚好。于是轻巧的迈入浴桶。");
		call_out("mess",5,who,"$N轻柔的擦洗着身体。");
		call_out("mess",9,who,"$N吩咐侍童打开木桶下的排水门，并再加了一些热水。");
		call_out("mess",13,who,"热水消除了疲惫，$N全身放松了下来。");
		call_out("mess",17,who,"$N洗完了澡，变得楚楚动人，身上散发出阵阵的香气。");
        call_out("reset_bath",18,who);
		call_out("set_nextquest",18,who,"把脏衣服脱了，在浴室洗个澡","终于把澡洗完了，去问庄主关于闯荡江湖的事情吧。", 20, 100);
    }
	else if(check_questindex(who,"把脏衣服脱了，在浴室洗个澡") == 1)
	{
		return notify_fail("你正洗着呢！\n");
	}
    return 1;
}

void mess(object who,string desc)
{
    message_vision(HIW+desc+"\n"NOR,who);
}

void reset_bath(object who)
{
    who->set_temp("newbie/bath",0);
}

int valid_leave(object me, string dir)
{
	object ob;
	if (me->query("id")!="a shu")
    {
        if (!sizeof(me->query_temp("armor"))) 
		{
			if (!objectp(present("cloth",me)))
			{
				message_vision(GRN"侍童说道：“$N怎么没有衣服，给你一件快点穿起来吧。“\n"NOR, me);
				ob=new(__DIR__"npc/obj/cloth");
				ob->move(me);
			}
			return notify_fail("你不能光着身子离开这里，有伤风化！\n请把衣物穿起来(wear all)\n");
		}
	}
	return ::valid_leave(me, dir);
}
