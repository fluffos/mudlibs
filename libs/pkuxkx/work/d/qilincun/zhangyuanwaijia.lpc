// zhx 2006/12/27
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;
void create()
{
	set("short", "张员外家");
	set("long", @LONG
这是张员外的家。张汤二家虽然也有田业，比王员外却是差的多了，但家境
也还算殷实。张员外行伍出身，却是乐得处处与人方便，像是汤永澄与王明平日
总谈不到一起，全靠张员外从中说和才不至于打起来。
LONG
	);
	set("exits", ([
		"east" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		__DIR__"npc/zhangyuanwai": 1,
		__DIR__"npc/zhangqi": 1,
	]));
	setup();
	replace_program(ROOM);
}