// Room: path2.c
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "浣花溪");
	set("long", @LONG
溪源转北，阵阵水响带着你来到草堂前。站在草堂照壁前，回首
浣花溪，想象万红漂坠，少女清歌浣花时节，别是一般滋味。北边就
是“万里桥西宅，百花潭北庄”的杜甫草堂了。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"north"  : __DIR__"caotang",
		"south"  : __DIR__"path1",
	]));
	set("no_clean_up", 0);
	setup();
}
