// This is a room made by zhx.
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是麒麟村中的小路，村中只有十多户人家，多半都是败屋号风，颓垣不
掩。茅檐雪压，冷灶无烟，看去十分残破。西面通向村中的小广场，南面便是出
村的路了。
LONG);
	set("objects", ([
		__DIR__"npc/laozhang" : 1,
	]));
	set("exits", ([
		"south"  : __DIR__"xiaolu5",
		"west"  : __DIR__"guangchang",
	]));

	setup();
	replace_program(ROOM);
}