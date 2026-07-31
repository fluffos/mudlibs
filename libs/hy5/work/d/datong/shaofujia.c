// Room: /open/dt/shaofujia.c

inherit ROOM;

void create()
{
	set("short", "少妇家");
	set("long", @LONG
这是一座打扫得非常洁净的院落，主屋是三间青瓦房，下首
还有一间偏房，院子角落里停着一辆大车，一只青骡正在低头啃
着食槽里的草料。走进屋中，一名正在给怀中婴儿喂奶的少妇笑
着说：大山你快来看宝宝多可爱……。当她抬头看见你时，脸上
的笑容登时转为惊讶，你慌忙退了出去。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luzhuxiang2",
]));

	setup();
	replace_program(ROOM);
}
