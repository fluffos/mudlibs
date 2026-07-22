// Room: /d/city/bingying.c

inherit ROOM;

void create()
{
        set("short", "兵营");
        set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操练，有
的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不动声色地寻视
着四周。看到你进来，他们全都向你包围了过来，形势看来不太妙。西边有一
个小窗口(window)。为了方便探监的百姓，可以从这个窗口传递(pass)些吃的
东西。
LONG
        );
        set("item_desc", ([
                "men" : "这是一扇极厚的铁门。\n",
        ]));
        set("exits", ([
                "south" : __DIR__"bingqiku",
                "east" : __DIR__"bingyingmen",
        ]));
        set("objects", ([
		NPC_D("guanfu/shi-qingshan") : 1,
                NPC_D("guanfu/wujiang") : 2,
                NPC_D("guanfu/bing") : 3,
        ]));
	set("incity",1);
	setup();
}
void init()
{
        add_action("do_visit", "look");
        add_action("do_pass", "pass");
}

int do_pass(string arg)
{
        object ob;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要送什么？\n");

        if (ob->query_weight() > 5000)
                return notify_fail(ob->query("name")+"太大了，不能从窗口里塞进去。\n");

	if (ob->query("no_drop")
	|| ob->query("id") == "huashi fen" || ob->query("id") == "tie he" || ob->is_container() || ob->query("hsf"))
                return notify_fail("这个东西放不进去。\n");

        message_vision("$N把一"+ob->query("unit")+"$n从窗口塞了进去。\n", this_player(), ob);
        ob->move("/d/city/dalao");
        message("vision", this_player()->name()+"从窗外塞进来一"
                +ob->query("unit")+ob->query("name")+"。\n",environment(ob), ob);
        return 1;
}
int do_visit(string arg)
{
        object env, me = this_player();

        if (arg != "window") return 0;

        if(!( env = find_object("/d/city/dalao")) )
                env = load_object("/d/city/dalao");

        message_vision("$N趴在窗台上往里望去。\n", me);
        tell_room(env, "你感到有一双眼睛在窗外打量你。\n");
        return COMMAND_DIR"std/look"->look_room(me, env);
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("guan bing", environment(me))) &&
                dir == "south")
                return notify_fail("官兵拦住了你的去路。\n");
        return ::valid_leave(me, dir);
}
