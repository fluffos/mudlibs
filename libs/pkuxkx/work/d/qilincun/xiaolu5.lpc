// Created by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是麒麟村中的小路，村中只有十多户人家，多半都是败屋号风，颓垣不
掩。茅檐雪压，冷灶无烟，看去十分残破。北面通向村中，西南就是前往洛阳的
官道。
LONG);
	set("exits", ([
		"north"  : __DIR__"xiaolu4",
		"southwest"  : "/d/luoyang/guandao2",
	]));

	setup();
	replace_program(ROOM);
}