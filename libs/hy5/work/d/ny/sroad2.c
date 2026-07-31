
// Room: /d/snow/sroad2.c

inherit ROOM;

void create()
{
	set("short", "宁远城街道");
	set("long",
"这里是宁远城的街道，你的北边有一家客栈，从这里就可以听到客栈里人们饮酒谈笑的声音\n"
"，街道往东不远处有个转角往北，如果你往东直走就是上山的小径了，往西则可以走到车马\n"
"来往络绎不绝的官道。\n"
);
	set("exits", ([ /* sizeof() == 3 */
]));
	set("outdoors", "ny");

	setup();
	replace_program(ROOM);
}
