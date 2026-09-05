// D:\xkx\d\liuxiu-shanzhuang\shanzhuang-damen.c山庄大门
// labaz  2012/10/21
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void init();
void close_gate();
int do_knock(string);
void reset_close();

void create()
{
    set("short", "山庄大门");
    set("long", 
"走进云雾，终见面目。你走到了远远便能望见，却望不真切的大宅子前。
这大门不同于别处，没有玉砌精雕的大狮子，也没有执刀握枪的卫兵。门口
只有两株巨大的岩桂花传来阵阵香气，和一个靓丽的丫鬟站在台阶上探头探
脑，似乎是在等什么人。大门"+YEL"(gate)"NOR+"虽然看上去古朴，却不显呆板，仍能看
出打磨得颇为雅致。

                   "+HIM"※==※==※==※==※==※
                   ※  柳  秀  山  庄  ※ 
                   ※==※==※==※==※==※"NOR+"

"
);

    set("outdoors","liuxiu-shanzhuang");

    set("item_desc", ([
        "gate":"一扇"+HIR"红漆大门"NOR+"上有两个"+HIY"金环"NOR+"在阳光照耀下格外耀眼。似乎可以敲门。"+HBBLU+WHT"(knock gate)\n"NOR,
        ]));

    set("exits", ([
        "west" : __DIR__"liuxiu-dangpu",
        "east" : __DIR__"liuxiu-piaohao",
        "south" : __DIR__"jizhen-xiaodao2",
        ])
     );
	

	// set("objects", ([
		// __DIR__"npc/jiading" : 2
	// ]));

    setup();
}

void init()
{
	object me;
	me=this_player();

	call_out("set_nextquest",1, me, "拿着刻有“柳秀山庄”的葫芦去柳秀山庄一问究竟", "你怔怔地站在那里不知所措,不如去敲敲门(knock gate)，找里面的人问问", 20, 100);
	
    add_action("do_knock", "knock");
	add_action("show_quest", "quest");
}

void close_gate()
{
    object room;
	object ob;
	object here;
	here=this_object();

    if(!( room = find_object(__DIR__"changlang")) )
        room = load_object(__DIR__"changlang");
    if(objectp(room))
    {	
		remove_call_out("close_gate");
		ob=present("yahuan",here);
		if (objectp(ob))
		{
			ob->command_me("go north");
		}
        delete("exits/north");
        message("vision", "丫鬟回到里面，乒地一声，把大门关上了。\n", this_object());
        room->delete("exits/south");
        message("vision", "丫鬟上前把大门关了起来。\n", room);
    }
    else 
	{
		message("vision", "ERROR: gate not found(close).\n", room);
	}
}
void reset_close()
{
	remove_call_out("close_gate");
	call_out("close_gate", 15);
}

int do_knock(string arg)
{
    object room,ob,here,yh,me;
	
	here=this_object();
	me=this_player();

    if (query("exits/north"))
        return notify_fail("大门已经是开着了。\n");

    if (!arg || (arg != "gate"))
	     return notify_fail("你要敲什么？\n");

    if(!( room = find_object(__DIR__"changlang")) )
        room = load_object(__DIR__"changlang");

	yh=present("yahuan",room);
	if ((objectp(yh)) && (yh->query_temp("player")==0)) 
	{
		room->set("exits/south", __FILE__);
		message("vision", "外面传来一阵敲门声，丫鬟应声上前把大门开。\n", room);

		set("exits/north", __DIR__"changlang");
		message_vision("$N轻轻地敲了敲门，只听吱地一声，"
			"丫鬟应声打开大门，\n"
			"她将门打开了一道缝，露出脑袋，转着乌黑的大眼睛，笑嘻嘻打量着$N。\n",
			this_player());

		yh->command_me("go south");

		remove_call_out("close_gate");
		call_out("close_gate", 15);
	}
	else
	{
		return notify_fail("里面的丫鬟正在接待别的客人，你稍等下再敲门试试吧。\n");
	}
	
    return 1;
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;
	
	if ((dir=="north")&&(me->query("id")!="ya huan"))
	{
		if (me->query(NEWBIE_VILLAGE_INDEX)<=get_questindex("ask yahuan about 葫芦，向丫鬟询问有关“葫芦”的事情"))
		{
			return notify_fail("你未经许可不得入内！\n");
		}
	
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) 
		{
			if ((userp(inv[i])) && (inv[i]->query(NEWBIE_VILLAGE_INDEX)<=get_questindex("ask yahuan about 葫芦，向丫鬟询问有关“葫芦”的事情")))
			return notify_fail("你未经许可不得携带其他人入内！\n");
		}
	}

	return ::valid_leave(me, dir);
}

