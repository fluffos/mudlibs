#include <room.h>

inherit ROOM;

void create()
{
	set("short", "狮子林");
	set("long", @LONG
你一走进狮子林，便不禁为江南苏州园林的奇妙美景所折服。狮子林东
南多山，西北多水，素有”假山王国“之称。假山峰峦叠嶂，曲折盘旋，石
洞连绵不断，幽深莫测。咫尺之间，可望而不可及，变幻无穷如入迷宫，不
由得不为之赞叹不已。
LONG
	);

	set("exits", ([
	"west" : __DIR__"nandajie1",
	"east" :__DIR__"yanyutang",
        "northeast" : __DIR__"zhibaixuan",
        ]));
 	set("outdoors", "suzhou");
	set("coor/x",120);
  set("coor/y",-240);
   set("coor/z",0);
   set("incity",1);
	setup();
}


