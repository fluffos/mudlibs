// zhx 2006/12/27
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "汤员外家");
	set("long", @LONG
这是汤员外的家。汤员外乃当地有名望绅士，本身又有功名，只是出身行伍，
人较粗直，因此上家中也没什么奢华之物，平日间只着意磨练小儿的心志，于自
身倒没有什么的。
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		__DIR__"npc/tangyuanwai": 1,
		__DIR__"npc/tangqi": 1,
	]));
	setup();
	replace_program(ROOM);
}