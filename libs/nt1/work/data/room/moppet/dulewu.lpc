// SN:G^SKcUPob;]1O2WY
// File(/data/room/moppet/dulewu.c) of moppet's room
// Create by LUBAN written by Doing Lu
#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "烟竹小筑小屋");
	set ("long", @LONG
一进门，扑面而来一种悠悠的清香，圆锥型的屋顶尖镶嵌着一颗
美丽的夜明珠，壁上挂着一幅琉璃娃娃亲手绘制的仕女图。西窗下摆
放着一张心型的寒冰床，隐约中释放着丝丝的寒气。一袭淡紫色的纱
帐轻拢着小床，微风轻轻拂过，紫纱也随风飞舞。透过小巧的窗户，
可以看到院落的的小竹林。[2;37;0m
LONG );

        set("objects", ([
                "/adm/npc/obj/xiang" : 1,
        ]));
	setup();

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
    
        set("room_owner", "琉璃娃娃");
        set("room_name", "烟竹小筑");
        set("room_id", "moppet");
        set("room_owner_id", "moppet");
        set("room_position", "南海之滨");
}

void init()
{
        ::init();
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
