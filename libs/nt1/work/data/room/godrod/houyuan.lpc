// SN:N49LPkg`l=SM7TH1
// File(/data/room/godrod/houyuan.c) of godrod's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "土地公庙后院");
	set ("long", @LONG
在后院里，养著几只放山的鸡鸭，周围种著一些美丽芬芳的花草。
一张小藤桌，几张小藤椅，桌上摆放著祺具和茗茶器皿。[2;37;0m
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "hangzhou");
        set("sleep_room", 1);

        set("room_owner", "断武");
        set("room_name", "土地公庙");
        set("room_id", "tudigong");
        set("room_owner_id", "godrod");
        set("room_position", "山路");
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
