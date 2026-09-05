// Rewrote by iszt@pkuxkx, 2007-02-11
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIG"沥泉洞"NOR);
	set("long", CYN @LONG
这便是传言中的沥泉洞了。据说洞中这股泉水本是奇品，不独味甘，若取来
洗目，便老花复明。不意近日有一怪事，那洞中常常喷出一股烟雾迷漫，人若触
着他，便昏迷不醒。原来竟是这条怪蛇作祟。
LONG NOR);

	set("exits", ([
		"out" : __DIR__"liquandongqian"
	]));
	set("objects", ([
		__DIR__"npc/guaishe": 1,
	]));

//	set("no_clean_up", 0);
        set("no_task",1);
	setup();
	replace_program(ROOM);
}