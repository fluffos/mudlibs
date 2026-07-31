//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "东厢房");
	set ("long", @LONG
这是知府大人和家眷起居的处所。左首一张雕花大木床，床上堆叠
着锦被和绣花枕头。北边是一条走廊，西边是一个花圃，隐约传来阵阵
花的迷香。北面有一扇门(men)。
LONG);
	set("exits", ([
		"north" : __DIR__"zoulang",
		"west"  : __DIR__"huapu",
	]));
		set("objects", ([
		__DIR__"npc/gaoshou" : 1,
	]));
	
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("sleep_room", 1); 
	set("coor/x", -1480);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	//replace_program(ROOM);
}

void init()
{
        add_action("do_kai", "open");
        add_action("do_kai", "kai");
        if (present("gao shou", environment(this_player())))
                delete("exits/north");
}
int do_kai(string arg)
{
        object ob;
        if (query("exits/north"))
                return notify_fail("这扇门已经是打开的。\n");
        if (!arg || (arg != "men" && arg != "north"))
                return notify_fail("你要打开什么？\n");
        if (!(ob = present("tong yaoshi", this_player())))
                return notify_fail("你用钥匙在门里转了几下,无奈怎么也打不开。\n");
        set("exits/north", __DIR__"zoulang");
        message_vision("$N那起铜钥匙打开房门，可是钥匙却断了。\n", this_player());
        destruct(ob);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("gao shou", environment(me))) && 
                (dir == "north"))
                return notify_fail("无名高手挡住了你：你想入内宅干什么? \n");
        return ::valid_leave(me, dir);
}
