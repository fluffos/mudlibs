// tzhroad10.c
// by wolf

inherit ROOM;

void create()
{
	set("short", "村庄的中心");
	set("long", @LONG
    这里是村庄的中心，人比较多，看样子有很多人是来铁掌帮拜师的，
在中心处站着一个身穿背心的大汉，他正在调戏一个路过的姑娘。不过因为
他长得凶神恶杀的，所有没有一个人敢出声。东面一直走是一条死胡同，南
面比较冷清，西面是西街的尽头，北面是村庄外围的一条街道。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
                   "east" : __DIR__"tzhroad11",
                   "south" : __DIR__"tzhroad12",
                   "west" : __DIR__"tzhroad9",
                   "north" : __DIR__"tzhroad7",
	]));

	setup();
	replace_program(ROOM);
}

