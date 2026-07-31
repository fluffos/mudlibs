// inn.c
// edit by pian
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "饮风客栈");
        set("long", @LONG
这里是一家小客栈，老旧的桌椅因为经年的使用而变得乌黑黝
亮，西边隔著一层竹帘隐隐传来一阵阵锅铲的声音，大概是客栈的
厨房，靠北边的墙壁边上有一道通往二楼雅座的楼梯，楼梯下就是
柜台，东边是客栈的出口，门口一串纸糊灯笼随风摇摆，上面写著
「饮风客栈」，意思是即使你没有钱，也欢迎来这里聊天听书，喝
西北风。西边有一扇木门通往後面的厨房。靠近门口的地方有一块
乌木雕成的招牌(sign)。
LONG
        );
   set("item_desc", ([ /* sizeof() == 7 */

	"酒缸": "你仔细地瞧了瞧酒缸上贴的红纸，不得了，有延德年间的高粱，京\n"
                "城廖麻子酒坊火漆封印的「拔舌酒」，有四季红的一品醉美人，还\n"
                "有好几坛贴著西郊大鼓楼的陈年老酒。\n",
        "柜台": "柜台後面陈列著一坛坛贴著红纸条的酒缸，这些是客栈掌柜视如性\n"
                "命的陈年老酒，如果你有兴趣，不妨问问掌柜有关这些陈年老酒卖\n"
                "是不卖。\n",
        "灯笼": "一串纸糊的大灯笼高高地挂在屋前的旗杆上，共是五个，分别写著\n"
                "「饮风客栈」四个大字，最下面的灯笼画著一个葫芦。\n",
        "楼梯": "这道楼梯通往二楼的雅座跟客房。\n",
        "竹帘": "竹帘用来隔开客人用膳跟厨房的炉灶，但是挡不住从厨房飘出来的\n"
                "香气。\n",
        "桌椅": "这些桌椅零零散散地放置在客栈的厅中，看来相当老旧了。\n",
        "sign":"招牌写著：饮风客栈。\n",
        ]));
        // This enables players to save this room as their startroom.
       	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
       set("exits", ([
                "east"          : __DIR__"guangchang_w",
                "west"          : __DIR__"inn_kitchen",
                //"north"          : "/u/y/yuyan/inn",
                //"up"            : "/u/f/free/food",
                //"northwest"     : "/d/wiz/entrance", 
                ]) );
        set("indoors","xueting");
        set("item_desc", ([
                "door": (: look_door, "northwest" :),
        ]) );
       set("objects", ([
  //     __DIR__"npc/traveller" : 3,
           //   "/d/npc/sungoku" : 1,
                __DIR__"npc/paotang" : 1 ]) );
   //     create_door("northwest", "木门", "southeast", DOOR_CLOSED);
        setup();
        // To "load" the board, don't ever "clone" a bulletin board.
//        call_other( "/obj/board/common_b", "???" );
}
