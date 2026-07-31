// SN:6D?=IZ\Z8HDn:575
// File(/data/room/kwantc/woshi.c) of kwantc's room
// Create by LUBAN written by Doing Lu

#include <room.h>
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "水月楼卧室");
	set ("long", @LONG
这里是水月楼的书房，也是独孤灵月的卧室，里面摆满书架，书
架上排满各门各派的武功秘笈。[2;37;0m
LONG );

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
        ]));
	setup();

        set("exits", ([
                "west" : __DIR__"dating",
        ]));

        create_door("west", "木门", "east", DOOR_CLOSED);
        
    
        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "独孤灵月");
        set("room_name", "水月楼");
        set("room_id", "shuiyue");
        set("room_owner_id", "kwantc");
        set("room_position", "青砖路");
}

void init()
{
        add_action("do_findbaby", "xunzhao");
}

int do_findbaby(string arg)
{
        object me = this_player(), baby;
        string file;

        if (! arg || (arg != "baby" && arg != "child") ||
            ! is_room_owner(me)) 
                return 0;

        if (! me->query("couple/child_id"))
                return notify_fail("你又还没有孩子，来这里凑什么热闹啊？\n");

        if (objectp(baby = find_living(me->query("couple/child_id")))
        &&  environment(baby) && baby->query("is_baby"))
                return notify_fail("你们的孩子已经跑出去玩了，好好四处找找吧！\n");

        if (me->query("gender") == "女性")
                file = read_file("/data/baby/" + me->query("id") + ".o");
        else file = read_file("/data/baby/" + me->query("couple/id") + ".o");

        if (stringp(file))
        {
                baby = new("/clone/user/baby");

                baby->load_baby(me);
                baby->move(environment(me));
                message_vision("你忽然看到床底下" +
                        ({"探出一颗小脑瓜", "伸出一双小脚丫", "伸出一支小手"})
                        [random(3)] + "．．．\n", me);

        } else
        {
                tell_object(me, MAG "你们的孩子不幸夭折了，请节哀吧。\n" NOR);
                me->delete("couple/child_id");
                me->delete("couple/child_name");
        }
        return 1;
}      
