// SN:^h[F_[Hn7_kJ6AFj
// File(/data/room/xnx/zoudao.c) of xnx's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "走道");
	set ("long", @LONG
霍格沃茨里一共有一百四十二座楼梯，有的宽敞干净；有的不但
窄，还老爱晃动；有的在某个星期五就会变成通向另一处不同的地方；
有的藏着些消失的梯级，弄得你不得不跳起来才能往上走。
    这里的门除非你有礼貌地请求它，或者帮它在某个恰当的地方挠
挠痒，否则它们是不会开的。
    还有些门根本就不是门，而是坚固的墙壁伪装而成的。要记住这
一切机关真的好难呀，因为它们好像是会自己移动的。壁贴肖像上的
人物者爱互相拜访换位置。[2;37;0m
LONG );

	set("exits", ([
		"north"  : __DIR__"yingke",
                "south"  : __DIR__"qianting",
	]));

        set("gate", "close");

        set("objects", ([
                "/d/room/roomnpc/yahuan" : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "绛珠草");
        set("room_name", "霍格沃茨");
        set("room_id", "hgwc");
        set("room_owner_id", "xnx");
        set("room_position", "碎石小道");
}

void init()
{
        add_action("do_push", "push");
        add_action("do_close", "close");
}

int do_push(string arg)
{
        object me;
        object room;

        if (query("gate") == "open")
                return notify_fail("大门开着呢，你还推什么？\n");

        me = this_player();
        message("vision",  "你用力推了推大门，就听大门“吱呀呀”的被人推开了。\n",
                           this_object());
    
        room = get_object(__DIR__"qianting");
        message("vision", "大门“吱呀呀”的被人推开了。\n", room);
        set("gate", "open");
        set("exits/south", __DIR__"qianting");
        room->set("exits/north", __FILE__);
        room->set("gate", "open");
        remove_call_out("do_close");
        call_out("do_close", 10, 0, 1);
        return 1;
}

int do_close(string arg, int n)
{
        object me;
        object room;

        if (query("gate") == "close")
                return notify_fail("大门关着呢，你还再关一遍？\n");

        if (! n)
        {
                me = this_player();
                message("vision", me->name() + "走上前去，用力合上大门。\n",
                        this_object());
        } else
        {
                message("vision", "大门“吱呀呀”的被人关上了。\n",
                        this_object());
        }

        room = get_object(__DIR__"qianting");
        message("vision", "大门“吱呀呀”的被人关上了。\n", room);
        set("gate", "close");
        delete("exits/south");
        room->set("gate", "close");
        room->delete("exits/north");
        return 1;
}

