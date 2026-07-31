#include <room.h>

inherit ROOM;

void create()
{
	set("short", "问梅阁");
	set("long", @LONG
阁内的桌凳、花窗、地坪、书画皆取材于梅花，并悬匾额“绮窗春讯”。
阁前种植了许多枝梅，以符阁名。曾为旧时文人著书、绘画之处。
LONG
);      
        set("objects",([
        __DIR__"npc/binv" : 2,
        ]));  
	set("exits", ([
	"west" : __DIR__"zhenquting",
        "south" : __DIR__"lixuetang",
	]));
 	set("outdoors", "suzhou");
	set("coor/x",150);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}


