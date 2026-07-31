// SN:K4BT<@;^FIJ8nkBW
// File(/data/room/boa/houyuan.c) of boa's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "天堂乐土后院");
	set ("long", @LONG
这是天堂乐土的后院，种着一些花草，大部分是都不知名的野生
花草。不过花儿开起来也看上去也非常漂亮。有时宝儿读书练武疲倦
了，就到这里稍作片刻以休息，也有时友人来到这里，大家在这里切
磋一下武艺。 
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "suzhou");
        set("sleep_room", 1);

        set("room_owner", "宝儿");
        set("room_name", "天堂乐土");
        set("room_id", "elysium");
        set("room_owner_id", "boa");
        set("room_position", "南大街");
}

void init()
{
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
