// SN:i^8k5IK?DAKd3[5V
// File(/data/room/paully/shufang.c) of paully's room
// Create by LUBAN written by Doing Lu

#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "书房");
	set ("long", @LONG
这里是双府的主人双剑读书写字的地方，干净明亮。文房四宝整
整齐齐的摆在桌子上面。有时双剑也在这里签发(sign)一些邀请客人
的请柬。 
LONG );

	set("exits", ([
		"east" : __DIR__"jusuo",
	]));

        set("sleep_room", 1);
        setup();

        set("room_owner", "双剑");
        set("room_name", "双府");
        set("room_id", "shurangfu");
        set("room_owner_id", "paully");
        set("room_position", "碎石小道");
}

void init()
{
        add_action("do_sign", "sign");
}

int do_sign()
{
        object ob;
        object me;

        me = this_player();

            if (! is_room_owner(me))
                    return notify_fail("你又不是这儿的主人，乱搞"
                                       "什么？\n");

        if (me->is_busy())
                return notify_fail("你现在还忙着呢。\n");

        message_vision("$N抽过一张纸，拿起笔来，在上面画符似"
                       "的写了些东西。\n", me);
        tell_object(me, "你写好一份手谕。\n");

        ob = new("/d/room/roomobj/pass");
        ob->set_name(HIW + me->query("name") + "手谕" NOR,
                     ({ "pass", query("room_owner_id") + " pass" }));
        ob->set("long", "一张由" + me->query("name") + "亲笔签发的" +
                     "手谕，凭借它你可以进出" + query("room_name") +
                     "。\n");
        ob->move(me);
        me->start_busy(4 + random(4));
        return 1;
}
