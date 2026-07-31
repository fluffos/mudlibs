// Room: /d/henshan/sansheng.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "三生塔");
	set("long", @LONG
三生塔是福严寺开山禅师慧思埋骨处，据说慧思禅师的三生均埋骨
这里，故称三生塔。不远处有棵银杏，据说曾受戒于慧思禅师，树龄千
年，仍亭亭华盖，岁岁青苍。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southup"   : __DIR__"jigaoming",
	   "eastdown"  : __DIR__"fuyansi",
	]));
	set("outdoors", "henshan");
	set("no_clean_up", 0);
	setup();
}

