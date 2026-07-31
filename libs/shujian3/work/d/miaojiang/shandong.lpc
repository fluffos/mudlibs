// /d/miaojiang/shandong.c

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这个山洞里黑漆漆的，四下里伸手不见五指。仔细看去，隐隐约约可以看
到四壁上爬满了树藤（shuteng）。 树藤间仿佛有什么东西发出声音，你不由
心生惧意。
LONG
        );
	set("exits", ([
		"out" : __DIR__"slu9",
	]));
	set("xuezhu_count", 1);
        setup();
}

void reset()
{
	set("xuezhu_count", 1);
}

void init()
{
	add_action("do_dian", "dian");
	add_action("do_yao", ({ "zuan", "yao" }));
}

int do_dian(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if( arg=="fire" ) {
		write("\n你点燃了火折，借着光亮你看到洞的四壁全是树藤，\n"+
		"树藤的空隙中布满了雪白的蜘蛛网。\n");
		me->set_temp("mark/点", 1);
		return 1;
	}
}

int do_yao(string arg)
{
	object me = this_player();
	if ( !arg || arg != "shuteng" )
		return notify_fail("你要干什麽？\n");
	if (!me->query_temp("mark/点"))
		return notify_fail("这里太黑了，看不清树藤，你还是点个火折吧。\n");
	if (query("xuezhu_count") > 0) {
		message_vision("$N轻轻摇晃树藤，忽然掉下一只雪蛛。\n", me);
		add("xuezhu_count", -1);
		new(__DIR__"npc/xuezhu")->move(__DIR__"shandong",);
		me->delete_temp("mark/点");
	}
	else
		message_vision("$N晃动了半天，发现什麽也没有。\n", me);
	return 1;
}
