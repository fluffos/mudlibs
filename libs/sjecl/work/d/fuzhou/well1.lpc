// room: well1.c
// Jay 4/8/96

inherit ROOM;

int do_use(string);
int do_zuan();

void create()
{
        set("short", "井底");
        set("long", @LONG
这是在一口枯井的井底。光线极暗，什么也看不清。
LONG
        );

        set("exits", ([
                "up" : __DIR__"well",
        ]));

        set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{

        if( !arg || arg != "fire" ) return 0;

        if (!present("fire", this_player())) return 0;
        if( arg == "fire" ) {
             write("你点燃了火折，发现井底什么也没有。\n");
             return 1;
        }
	return 0;
}

int do_zuan()
{
	object me;
	me = this_player();

	message_vision("$N像没头苍蝇一样在黑洞洞的井底瞎钻，结果一头撞在井壁的石头上。\n", me);
	if(random(2) == 1)
		me->unconcious();
	return 1;
}
