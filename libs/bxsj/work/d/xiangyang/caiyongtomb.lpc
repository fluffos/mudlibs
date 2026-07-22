// /d/xiangyang/caiyongtomb.c

inherit ROOM;

int do_dig(string arg);

void create()
{
	set("short", "蔡邕墓");
	set("long", @LONG
蔡邕死后葬于此地，他是东汉末年人士，不知是否保存有那些自晋以后就
失传了的古物。
LONG
	);
        set("outdoors", "长安");

	set("exits", ([
		"south" : __DIR__"caiyongmanor",
	]));
	setup();
}

void init()
{
	add_action("do_dig", ({"dig", "wa", "daomu", "juemu", "jue"}));
}

int do_dig(string arg)
{
	object ob, me = this_player();
	string action = query_verb();

	if ((action == "dig" || action == "wa" || action == "jue") &&
		(arg != "tomb" && arg != "mu" && arg != "caiyong mu")) {
		write("你要挖什么？\n");
		return 1;
	}
	if (!(ob = present("gravedigger tools", me))) {
		write("你没有工具，怎么盗墓呀？\n");
		return 1;
	}
	destruct(ob);
	write("你费力地挖开土堆，由于不熟练，把工具都搞坏了。所幸的是你终于挖出了一个可以钻进去的洞。\n");
	write("你在墓穴里找了半天，没有找到什么好东西，只发现了一本很古旧的竹简。\n");
	write("你丧气地钻出墓穴，想了想，还是把墓上面的土又堆了回去。\n");
	new(__DIR__"obj/guanglingsan")->move(me);
	return 1;
}
