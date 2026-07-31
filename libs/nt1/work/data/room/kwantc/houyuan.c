// SN:K\8Nic2`@P@M_7ON
// File(/data/room/kwantc/houyuan.c) of kwantc's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "水月楼后院");
	set ("long", @LONG
这里是水月楼的后院，种满的花草树木，院中还有一潭水池，池
上有数对鸳鸯在嬉戏。[2;37;0m
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "playertown");
        set("sleep_room", 1);

        set("room_owner", "独孤灵月");
        set("room_name", "水月楼");
        set("room_id", "shuiyue");
        set("room_owner_id", "kwantc");
        set("room_position", "青砖路");
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
