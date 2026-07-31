// SN:TgP3YXhG>[47PI<H
// File(/data/room/czauditb/houyuan.c) of czauditb's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "少林室后院");
	set ("long", @LONG
这是少林室的后院，种着一些花草，大部分是都不知名的野生花
草。不过花儿开起来也看上去也非常漂亮。有时渡性读书练武疲倦了，
就到这里稍作片刻以休息，也有时友人来到这里，大家在这里切磋一
下武艺。 
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);

        set("room_owner", "渡性");
        set("room_name", "少林室");
        set("room_id", "shaol");
        set("room_owner_id", "czauditb");
        set("room_position", "三岔口");
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
