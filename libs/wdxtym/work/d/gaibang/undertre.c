// Room: /d/gaibang/undertre.c 
inherit ROOM; 
	
void create() 
{
	set("short", "树洞下"); 
	set("long", @LONG 
这是老槐树底部，四周光线昏暗，人影晃晃，似乎有几个黑暗的洞口 
在你身边，通向四面八方。一位老乞丐大咧咧地坐在正中的地上。不经 
意中你发现墙壁上画着幅粗糙的路线草图。 
LONG 
	); 
	set("exits", ([ 
		"up"   : __DIR__"inhole", 
		"down" : __DIR__"chuchang",
		"west" : "/d/city/gbxiaowu"
	]));

	set("direct", ([ 
		"1"    : __DIR__"bjandao1", 
		"2"    : __DIR__"slandao1", 
		"3"    : __DIR__"gwandao1", 
		"4"    : __DIR__"hzandao1", 
		"5"    : __DIR__"qzandao1", 
		"6"    : __DIR__"fzandao1", 
		"7"    : __DIR__"fsandao1", 
		"8"    : __DIR__"wgandao1", 
		"9"    : __DIR__"xsandao1", 
		"a"    : __DIR__"xxandao1", 
		"b"    : __DIR__"lzandao1",
		"c"    : __DIR__"dlandao1",
		"d"    : __DIR__"cdandao1",
		"e"    : __DIR__"hsandao1",
		"f"    : __DIR__"wdandao1", 
	])); 
 
	set("item_desc", ([ "【密道】" :
		"请选择想要去的地方：\n"
		ZJOBACTS2+ZJMENUF(4,4,7,26)
		"北京:goto 1"ZJSEP
		"嵩山:goto 2"ZJSEP
		"关外:goto 3"ZJSEP 
		"杭州:goto 4"ZJSEP
		"嘉兴:goto 5"ZJSEP
		"福州:goto 6"ZJSEP
		"佛山:goto 7"ZJSEP
		"武功:goto 8"ZJSEP
		"雪山:goto 9"ZJSEP
		"星宿:goto a"ZJSEP
		"灵州:goto b"ZJSEP
		"大理:goto c"ZJSEP
		"成都:goto d"ZJSEP
		"华山:goto e"ZJSEP
		"武当:goto f\n"
	])); 
       
	set("objects", ([ 
		CLASS_D("gaibang") + "/liang" : 1,
		CLASS_D("gaibang") + "/ma-jw" : 1, 
	])); 
       
	set("no_fight", 1); 
       
	setup(); 
} 

void init()
{
	add_action("do_goto", "goto");
}

int do_goto(string arg)
{
	string dest;
	object me;

	if (! arg)
		return notify_fail("你要去哪里？\n");

	me = this_player();

	if (undefinedp(dest = query("direct/" + arg)))
		return notify_fail("你要去哪里？\n");

	if (me->is_busy())
	{
		write("你现在忙着呢，等会儿再说吧。\n");
		return 1;
	}

	message_vision("$N四周观察了一会儿，找了个出口飘然而去。\n", me);
	me->move(dest);
	me->start_busy(1);
	return 1;
}

int valid_leave(object me, string dir) 
{
	object guarder;

	if (objectp(guarder = present("liang zhanglao", this_object())) && 
	    living(guarder) && dir != "up")
		return guarder->permit_pass(me, dir);

	return ::valid_leave(me, dir); 
}
