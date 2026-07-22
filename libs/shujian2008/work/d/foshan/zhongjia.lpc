// Room: zhongjia.c 
 
#include <room.h>
inherit ROOM; 
 
void create() 
{ 
	set("short", "钟家");
	set("long", @LONG
这是一间用土坯搭成的房屋，屋里只有几件残破的家俱。墙上挂着一
些农具，地上还摆着一些看起来刚刚用完沾满泥巴的农具。东面有一个木
门(door)，好象可以打开。
LONG
	);
        set("indoors","佛山");
	set("exits", ([
        "north" : __DIR__"alleyway",
        "east" : __DIR__"caidi",
        ]));

        set("item_desc", ([
                "door" : "这是一扇破旧的木门。\n",
        ]));


        set("objects", ([
                __DIR__"npc/zhong-asi" : 1,
                __DIR__"npc/zhong-sisao" : 1,
                __DIR__"npc/zhong-xiaoer" : 1,
        ]));

        create_door("east", "木门", "west", DOOR_CLOSED);
       	set("coor/x",10);
  set("coor/y",-570);
   set("coor/z",0);
   setup();
}
