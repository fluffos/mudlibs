// SN:d[oBD7@H=3[mEPbB
// File(/data/room/xnx/woshi.c) of xnx's room
// Create by LUBAN written by Doing Lu

#include <room.h>
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "卧室");
	set ("long", @LONG
古朴的装饰，一张挂着深红天鹅绒幕帘的四柱大床靠在窗边。这
里使人有种昏昏欲睡的感觉。[2;37;0m
LONG );

        set("exits", ([
                "down" : __DIR__"jusuo",
        ]));

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
        ]));

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
        setup();
    
        set("room_owner", "绛珠草");
        set("room_name", "霍格沃茨");
        set("room_id", "hgwc");
        set("room_owner_id", "xnx");
        set("room_position", "碎石小道");
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

        if (! me->query("couple/child"))
                return notify_fail("你又还没有孩子，来这里凑什么热闹啊？\n");

        if (objectp(baby = find_living(me->query("couple/child")))
        &&  environment(baby) && baby->is_baby())
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
                me->delete("couple/child");
                me->delete("couple/child_name");
        }
        return 1;
}      
