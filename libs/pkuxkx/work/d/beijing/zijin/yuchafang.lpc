// Room: /d/beijing/zijin/yuchafang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"御茶房"NOR);
	set("long",
HIC"这里是太监的值房,几个太监在这里随时等候皇帝的宣召。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"westup" : __DIR__"qianqinggong",
  	"south" : __DIR__"duanningdian",
	]));
	set("objects",([
	"/d/beijing/npc/wenyoufang":1,
	]));
	setup();
	replace_program(ROOM);
}
