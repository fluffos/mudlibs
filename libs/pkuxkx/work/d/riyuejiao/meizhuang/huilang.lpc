// huilang.c	梅庄回廊
// by bing

inherit ROOM;

void create()
{
        set("short", "回廊");
        set("long", @LONG
这是一道长长的回廊。回廊两边种着许多花草，当然最多的还是
梅花。可以想象隆冬时节这里一定是梅香四溢，令人陶醉。能住在这
种世外梅园也是一种难得的福气了。
LONG);

        set("exits", ([ 
	"east" : __DIR__"keting",
	"west" : __DIR__"jiushi",
]) );
	setup();
	replace_program(ROOM);
}
