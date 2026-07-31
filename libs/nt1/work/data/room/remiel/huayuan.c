// SN:R=Ak98`8c<V`0Dnf
// File(/data/room/remiel/huayuan.c) of remiel's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "后花园");
	set ("long", @LONG
这是天使禁猎区的后花园，种着一些雷米尔采自五湖四海、名山
大川的奇花异草，美丽非常。雷米尔有时读书练武疲倦了，就到这里
稍作休息，观赏花草以怡情自乐，或许能突发灵感，有所领悟。西面
就是通往主人居所的铁门，东面则是一片竹林。 
LONG );

	set("exits", ([
                "south"  : __DIR__"houyuan",
                "east"   : __DIR__"zhulin",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        set("room_key", "1 of remiel");
        setup();

        set("KEY_DOOR", ([
                "exit" : "west",
                "room" : __DIR__"jusuo",
        ]));
    
        set("room_owner", "雷米尔");
        set("room_owner_id", "remiel");
        set("room_name", "天使禁猎区");
        set("room_id", "angelcage");
        set("room_position", "青砖路");
}

void init()
{
        ::init();
        add_action("do_sit", "sit");
        this_player()->delete_temp("has_sit");
}

int do_sit(string arg)
{
        object me;

        me = this_player();
        if (me->query_temp("has_sit"))
        {
                message_vision("$N坐在那里摇啊摇，好不惬意。\n", me);
                return 1;
        }

        message_vision("$N找了的地方作了下来，看上去轻松多了。\n", me);
        me->set_temp("has_sit", 1);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("has_sit"))
        {
                message_vision("$N掸掸尘土，站了起来。\n", me);
                me->delete_temp("has_sit");
        }

        return ::valid_leave(me, dir);
}
