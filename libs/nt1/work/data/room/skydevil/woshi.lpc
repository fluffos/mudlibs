// SN:CK=nI6PHVA_]IPJN
// File(/data/room/skydevil/woshi.c) of skydevil's room
// Create by LUBAN written by Doing Lu

#include <room.h>
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "小库咖啡屋卧室");
	set ("long", @LONG
这是一间宽敞舒适的豪华客房，床边的小茶几上摆饰著古老的花
瓶，上面插满了新鲜美丽的花瓶，从花瓶中飘出阵阵清淡的革因此使
的这个房间柔中带刚，有一种奇妙的韵味充斥在整个房间中。[2;37;0m
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
    
        set("room_owner", "风魔");
        set("room_name", "小库咖啡屋");
        set("room_id", "coffeeshop");
        set("room_owner_id", "skydevil");
        set("room_position", "山路");
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
