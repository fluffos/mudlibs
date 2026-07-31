// Room: /d/tianshui/xiaolu2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条小路，路边长满了蒿草，蒿草里有几株不知名的灌
木，偶尔小风吹过一阵沙沙的做响。往西看天水镇的东口遥遥在
望，一条土路向东延伸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xiaolu1",
  "east" : __DIR__"xiaolu3",
]));
	set("item_desc",([
	"灌木" : "一株低矮的灌木，稀疏的叶子里长着几颗红红的小果子。\n",

]));
	set("num",3);
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
}

void init()
{
	add_action("do_zhai",({"zhai", "pick"}));
}

int do_zhai(string arg)
{
	object obj;
	if(!arg || arg == "")
		return notify_fail("你要摘什么？\n");
	if(arg != "小果子" && arg != "果子")
		return notify_fail("你要摘什么？\n");
	if(!query("num"))
		return notify_fail("小果子已经被摘完了。\n");
	message_vision("$N伸手摘下了一颗小果子。\n",this_player());
	add("num",-1);
	obj = new(__DIR__"obj/guozi");
	obj->move(this_player());
	return 1;
}