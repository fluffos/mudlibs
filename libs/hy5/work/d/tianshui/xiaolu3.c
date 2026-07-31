// Room: /d/tianshui/xiaolu3.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条小路，路边长满了蒿草，蒿草里有几株不知名的灌
木，偶尔小风吹过一阵沙沙的做响。往西看天水镇的东口遥遥在
望，东面是一片草地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xiaolu4",
  "west" : __DIR__"xiaolu2",
]));
	set("item_desc",([
	"灌木" : "一株低矮的灌木，稀疏的叶子里长着几颗红红的小果子。\n",

]));
	set("num",3);
	set("outdoors", "tianshui");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_push","push");
	add_action("do_zhai",({"zhai", "pick"}));
}

int do_push(string arg)
{
        object me;
        if(!arg || arg=="") return 0;
        if( arg != "grass" && arg != "蒿草" && arg != "草") return 0;

        me = this_player();
        message_vision("$N拨开路边的蒿草，发现了一条向北的路。\n", me);
        if( !query("exits/north") )
        set("exits/north", __DIR__"enter_hole");
        call_out("close_path", 5);
        return 1;
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

void close_path()
{
        if( !query("exits/north") ) return;
        message("vision","一阵小风吹过，道路又淹没不见了。\n",this_object() );
        delete("exits/north");
}
