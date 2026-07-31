// Room: /u/qingyun/jyzj/conglin2.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "雪山丛林");
	set("long", @LONG
这是一个很大的丛林，树木的枝叶上挂满了冰雪，雪白的一大片，奇美无
比。丛林向山上延伸，直至山顶。在丛林中微露出一条小道，依稀可认，你走
在小道上，雪地中留下一行长长的足印。
LONG	);
	set("exits", ([
		"westup" : __DIR__"xuanya",
		"southdown" : __DIR__"conglin1",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("objects",([
		__DIR__"npc/dog1" : 1,
		__DIR__"npc/dog2" : 1,
		__DIR__"npc/dog3" : 1,
		__DIR__"npc/dog4" : 1,
	]));
	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
object fang;
object who;
int i;
who=me;



	if ( objectp(present("dog", environment(me))) )
		return notify_fail("一只大狗拦住了你的去路。\n");



        return ::valid_leave(me, dir);
}
