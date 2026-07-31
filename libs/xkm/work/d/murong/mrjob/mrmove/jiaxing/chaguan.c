//Cracked by Play
// Room: chaguan

inherit ROOM;

void create()
{
	set("short", "茶馆");
	set("long", @LONG
这是一间昼夜茶馆，厅内摆设着数十张木桌，茶客们进进出出十
分热闹。几名茶博士殷勤的招呼着来往于山南海北的客人。在这里经
常可以得到一些鲜为人知的消息，也因此成为了人们闲暇时交流的一
个好地方。
LONG
	);

	set("exits", ([
                "out" : "/d/jiaxing/chating",
	]));
        set("no_fight", 1);
	set("objects", ([
		__DIR__"huoji" : 1,
		__DIR__"Mranpc.c" : 1,
	]));

	set("cost", 0);
	setup();
}
void init()
{
	add_action("do_fill", "fill");
}
int do_fill(string arg)
{
	object ob, obj, me = this_player();

	if (!arg || !(ob = present(arg, this_player())) || !ob->query("liquid")){
                write("你要把茶水装在哪儿？\n");
		return 1;
	}

	switch (MONEY_D->player_pay(this_player(), 5)) {
        case 0: {
		write("穷光蛋，一边呆着去！\n");
		return 1;
		}
        case 2: {
                write("您的零钱不够了。\n");
		return 1;
		}
	}

        if( ob->query("liquid/remaining") )
                message_vision("$N将" + ob->name() + "里剩下的" + ob->query("liquid/name") + 
		"倒掉。\n", this_player());
        message_vision("$N给茶博士几文铜板，茶博士为$N的"+ob->name()+"装满茶水。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        ob->set("liquid/type", "tea");
        ob->set("liquid/name", "茶水");
        ob->set("liquid/remaining", ob->query("max_liquid"));
	return 1;
}





