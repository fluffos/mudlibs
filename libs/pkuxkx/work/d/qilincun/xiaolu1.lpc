// This is a room made by zhx.
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是麒麟村中的小路，村中只有十多户人家，多半都是败屋号风，颓垣不
掩。茅檐雪压，冷灶无烟，看去十分残破。而北面却是一个颇为气派的院子，看
来是个大户。西首有一家小酒店，东面通向附近的山中。
LONG);
	set("exits", ([
		"south" : __DIR__"xiaolu2",
		"north" : __DIR__"wangjia",
		"east"  : __DIR__"shanlu",
		"west"  : __DIR__"jiudian",
	]));

	setup();
	replace_program(ROOM);
}
