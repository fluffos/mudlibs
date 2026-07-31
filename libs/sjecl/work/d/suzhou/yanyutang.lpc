#include <room.h>

inherit ROOM;

void create()
{
	set("short", "燕誉堂");
	set("long", @LONG
燕誉堂是全园主厅，旧时系园主宴客处。曾经作为御膳房。堂名取于《
诗经》：“式燕且誉，好而无射”。此处建筑为鸳鸯厅形状，高敞宏丽，堂
内陈设富丽精致。
LONG
);
        set("objects",([
        __DIR__"npc/binv" : 2,
        ]));
	set("exits", ([
	"west" : __DIR__"shizilin",
	"southeast" :__DIR__"zhenquting",
        ]));
 	set("outdoors", "suzhou");
	set("coor/x",130);
  set("coor/y",-240);
   set("coor/z",0);
   set("incity",1);
	setup();
}


