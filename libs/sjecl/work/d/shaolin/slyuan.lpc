//slyuan.c

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", HIY"舍利院"NOR);
	set("long", @LONG
这是一座寂静的小院，院中堆满的劈好的木柴，几名身穿白布僧衣的僧
人正在往来忙碌着。这里是寺中僧人圆寂后，焚化归西的场所。院落的西面
有一道小门。
LONG
	);
        set("no_fight",1);
       	
	set("exits", ([
		 "east" : __DIR__ "huaishu4",
                 "west" : __DIR__ "talin1",
        ]));

        create_door("west", "木门", "east", DOOR_CLOSED);
	
	set("coor/x",20);
  set("coor/y",310);
   set("coor/z",120);
   setup();
}



