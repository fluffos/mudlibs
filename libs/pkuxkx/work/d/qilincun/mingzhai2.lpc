// Room: /xiaocun2/jiudian.c
// zhx 2006/12/27
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "民宅");
	set("long", @LONG
这是本村村民王二愣的家，屋内四壁空空，并没有什么值钱的器物，一看就
知道是一个穷家。一个村汉正坐在那里闷头发呆。你进村时仿佛听说过村里有人
的妻子被土匪给抢走了，不知是也不是。
LONG
	);
	set("exits", ([
		"north" : __DIR__"xiaolu3",
	]));
	set("objects", ([
		__DIR__"npc/wangerleng": 1,
	]));

	setup();
	replace_program(ROOM);
}