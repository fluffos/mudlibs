// Room: /u/llx/room/quanzhou/jinjiting.c

inherit ROOM;

void create()
{
	set("short", "金鸡亭");
	set("long", @LONG
这里是一个偏僻的地方。因为很少人来这，所以长满了
杂草。远处有一个破亭子，里面坐着一位老者，似乎在
远眺东海的美景。
LONG);
        set("exits", ([ /* sizeof() == 2*/
        "west" : "/d/quanzhou/huanggu",
        "east" : __DIR__"heici",
	]));
	set("objects",([
	__DIR__"npc/laozhe" : 1,
	]));
	set("no_clean_up", 0);
	setup();
}
