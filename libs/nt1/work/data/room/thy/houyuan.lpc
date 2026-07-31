// SN:\Hf:Z3m`oTX[SM@C
// File(/data/room/thy/houyuan.c) of thy's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "平安坊后院");
	set ("long", @LONG
这里是平安坊后院，是一个药苗大棚。先进的药材种植机器正不
停地往地上栽各式各样的药苗和花苗。一大帮工人在忙着采集药材送
去给好人验收。[2;37;0m
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "yangzhou");
        set("sleep_room", 1);

        set("room_owner", "好人");
        set("room_name", "平安坊");
        set("room_id", "thy");
        set("room_owner_id", "thy");
        set("room_position", "树林");
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
