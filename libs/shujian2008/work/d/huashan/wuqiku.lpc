// Room: /d/huashan/wuqiku.c
// Date: Look 99/03/25

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "剑房");
        set("long", @LONG
“剑”本身并不重要，最关键的是使剑的人本身的剑术修为，所以，高手
无剑。华山派弟子用剑的时候，都是到这个剑房来取。这里面也零散放着一些
其他的兵器，供华山弟子习武时取用。
LONG
        );
	set("objects",([
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/changjian" : 1,
		__DIR__"obj/gangdao" : 1,
	]));

        set("exits",([
        	"north" : __DIR__"lianwu2",
        	"south" : __DIR__"shuyuan",
	]));
        set("indoors", "华山" );

	set("coor/x",100);
  set("coor/y",-20);
   set("coor/z",80);
   setup();
}
