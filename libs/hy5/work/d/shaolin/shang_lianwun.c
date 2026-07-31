inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是商家堡厅后的一个练武场，空阔的场地上铺满了细细
的黄土，正好适合演武。不过这里杂草丛生，看样子已经荒废很
长一段时间了。北侧有一扇门(men)。
LONG);
	set("exits", ([
		"south"  : __DIR__"shang_houyuan",
	]));
	setup();
	//replace_program(ROOM);
}
void init()
{
	add_action("do_unlock", "unlock");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/north"))
		return notify_fail("这扇门已经是打开的。\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("你要打开什么？\n");
	if (!(ob = present("laofang key", this_player())))
//	if (!(ob = present("lywintwo", this_player())))
		return notify_fail("你不会撬锁。\n");
	set("exits/north", __DIR__"shang_dongxiang");
	message_vision("$N用一把钥匙打开了秘门，可是钥匙却断了。\n", this_player());
	destruct(ob);
	return 1;
}