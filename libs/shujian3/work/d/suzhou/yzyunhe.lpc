// matou.c yujue

inherit ROOM;

string look_sign();
int do_go(string);


mapping *sign=({

	(["name":"沧州",
		"id":"cz",
		"file": "/d/cangzhou/",
		"value":20000,
		"time":50
	]),
	(["name":"苏州",
		"id":"sz",
		"file":__DIR__"szyunhe",
		"value":500,
		"time":10
	]),
});

void create()
{
	set("short", "码头");
	set("long",@LONG
这里是扬州东门外古老的运河水运码头，只见大运河水蜿蜒流淌，从扬州
城中穿过。运河的两岸种着一排排青青的垂杨柳，一阵微风吹来，树枝随风摇
荡。在扬州城里出门最好的交通工具就是船了。远处的河上可以望见一艘小船
的影子，船首依稀有一位老船夫。河边的地上立着一个石碑(shibei)。
LONG);
	set("exits", ([
		"north" : "/d/city/dongmen",
	]));
/*
	set("item_desc", ([
		"shibei" : (: look_sign :),
		"bei" : (: look_sign :)
	]));
*/
	set("outdoor", "扬州");
	set("incity",1);
	setup();
}

void init()
{
//	add_action("do_go", "qu");
}


string look_sign()
{
	string str="";
	int i=sizeof(sign);

	while (i--) {
		str += sign[i]["name"];
		str += "(" + sign[i]["id"] + ") ";
		str += MONEY_D->price_str(sign[i]["value"]) + "\n";
	}
	return str;
}


void do_move(object ob, int i)
{
	ob->enable_player();
	ob->delete_temp("block_msg/all");
	write("船慢慢地停了下来，靠在了岸边。\n");
	ob->move(sign[i]["file"]);
	tell_room(environment(ob), ob->name() + "从船上走了下来。\n", ({ob}));
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(sign);

	if (!arg) return 0;
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("你正忙着呢！\n");
	while(i--) {
		if (arg == sign[i]["id"]) {
			switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
				case 0:
					return notify_fail("穷光蛋，一边呆着去！\n");
				case 2:
					return notify_fail("有零钱吗？\n");
			}
			message_vision("$N登上了去" + sign[i]["name"] + "的船。\n", ob);
			ob->disable_player("<旅途中>");
			ob->set_temp("block_msg/all", 1);
			ob->move(__DIR__"onroad");
			call_out("do_move", sign[i]["time"], ob, i);
			return 1;
		}
	}
	return notify_fail("你要去哪里？\n");
}
