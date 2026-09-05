// This is a room made by zhx.
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是麒麟村中的小路，村中只有十多户人家，多半都是败屋号风，颓垣不
掩。茅檐雪压，冷灶无烟，看去十分残破。西首一家，同样也是土屋，但门外的
雪，却似经过多次打扫，只积有薄薄一层，一望而知这是一家勤谨的人家。北边
是一个小广场。
LONG);
	set("exits", ([
		"north" : __DIR__"guangchang",
		"east"  : __DIR__"mingzhai1",
		"south"  : __DIR__"mingzhai2",
		"west" : __DIR__"yuejia",
	]));
	setup();
	replace_program(ROOM);
}