// Room: /xiaocun2/jiudian.c
// zhx 2006/12/27
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "学馆");
	set("long", @LONG
这里便是周侗开馆授徒的地方。学馆靠近一片柳林，有十多间房、一个大院
子，地势很幽静。书房两面皆窗，没有外墙，旁边有一小门，学生都由此出入。
窗外花木扶疏，有松有石，与村中破败的景象大是不同。
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaolu3",
	]));
	set("objects", ([
		__DIR__"npc/zhou": 1,
	]));
	setup();
	replace_program(ROOM);
}