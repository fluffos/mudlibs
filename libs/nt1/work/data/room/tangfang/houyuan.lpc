// SN:n2N39ZUB`h>jc47h
// File(/data/room/tangfang/houyuan.c) of tangfang's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "一间小屋后院");
	set ("long", @LONG
[1;32m斜斜的一条由鹅卵石铺就的小路通往后院。来到后院，你才觉悟江湖上

的一切纷争全无什么意义，后院有些花草，也不多，但是一个个却翠绿的可

爱，在微风中摇摆，柔弱但却决至于倒下。院子的左面有一个六角凉亭，亭

子里，四个石凳，一张石桌，几只小鸟立在石桌上梳理羽毛，见到你来并不

飞走，只鸣叫了几声，仿佛欢迎。[2;37;0m
LONG );

	setup();

	set("exits", ([
                "south"  : __DIR__"dating",
	]));

        set("outdoors", "xiakedao");
        set("sleep_room", 1);

        set("room_owner", "唐方");
        set("room_name", "一间小屋");
        set("room_id", "tangfang");
        set("room_owner_id", "tangfang");
        set("room_position", "南海之滨");
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
