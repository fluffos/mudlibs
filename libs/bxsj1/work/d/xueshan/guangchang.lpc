 // guangchang.c  殿前广场
 // by dubei

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short","殿前广场");
        set("long",@LONG 
这是大殿前的广场，方圆一百多丈，一色的青石板漫地，许多大轮寺的喇
嘛正在忙忙碌碌的穿梭不停，更有许多进香客在这里一步一个头的磕进大殿去。
大殿里传来众喇嘛讼经和法器敲打的声音。一股浓郁的香火味道飘散在空中。
LONG);
	set("exits", ([ 
  		"northup" : __DIR__"dadian",
		"west" :__DIR__"huilang1",
		"east" :__DIR__"huilang2"
              ]));

        set("objects", ([__DIR__"npc/heilinbofu" : 1,
                         __DIR__"npc/fanseng" : 1,
                         __DIR__"npc/xiangke" : 1,]));

        "/clone/board/xueshan_b"->foo();

        set("outdoors", "雪山");
 
	setup();

}
void init()
{
        if(query("exits/southdown")) {
        set("item_desc", ([
                "gate": "两扇红漆的大门向两侧敞开着。\n",
                "门": "两扇红漆的大门向两侧敞开着。\n",
        ]) );
        add_action("do_pull", "pull");
	}
	else {
        set("item_desc", ([
                "gate": "两扇红漆的大门紧紧关闭着，你可以拉(pull)门。\n",
                "门": "两扇红漆的大门紧紧关闭着，你可以拉(pull)门。\n",
        ]) );
        add_action("do_pull", "pull");
	}
}

int do_pull(string arg)
{
        object room, me;

        if( arg=="gate" || arg == "门") {
                me = this_player();
                if(query("exits/southdown")) {
                        write("门已经是开着的！\n");
		}
		else {
                set("exits/southdown", __DIR__"shanmen");
	        set("item_desc", ([
       	         "gate": "两扇红漆的大门向两侧敞开着。\n",
       	         "门": "两扇红漆的大门向两侧敞开着。\n",
       		 ]) );
                message_vision(HIY"$N将大门拉开。\n"NOR, me);
                if( room = find_object(__DIR__"shanmen") ) {
                        tell_room(room,HIY"大门从里面打了开来。\n"NOR);
	                room->set("exits/northup", __FILE__);
			call_out("closedoor", 15, room);
                }
		}
	}
	else {
                 write("你要开什么？\n");
	}
	return 1;
}

int closedoor(object room)
{
	tell_room(room,HIY"护寺喇嘛上前把大门关上了。\n"NOR);
        set("item_desc", ([
                "gate": "两扇红漆的大门紧紧关闭着，你可以拉(pull)门。\n",
                "门": "两扇红漆的大门紧紧关闭着，你可以拉(pull)门。\n",
        ]) );
	room->delete("exits/northup");
	delete("exits/southdown");
}