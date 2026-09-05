// Room: /d/beijing/chongwenjie.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"崇文门外大街"NOR);
	set("long",
CYN"这里是热闹的崇文门大街。街上多是来往的商人，有时也能看见马车载着达官
要员经过。\n"NOR
	);

	set("outdoors", "beijing");
	set("cost", 2);
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"chongwendajie2",
	  "north"  : __DIR__"chongwenmen",
	  "west"  : __DIR__"zhengyangdajie2",
	]));

	setup();
}
