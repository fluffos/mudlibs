// SN:K<Le2UX37bA]_SP^
// File(/data/room/tiantian/shufang.c) of tiantian's room
// Create by LUBAN written by Doing Lu

#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "书房");
	set ("long", @LONG
这里是猪猪会总坛的主人猪猪快跑读书写字的地方，干净明亮。
文房四宝整整齐齐的摆在桌子上面。有时猪猪快跑也在这里签发(sig
n)一些邀请客人的请柬。 
LONG );

	set("exits", ([
		"east" : __DIR__"jusuo",
	]));

        set("sleep_room", 1);
        setup();

        set("room_owner", "猪猪快跑");
        set("room_name", "猪猪会总坛");
        set("room_id", "tian");
        set("room_owner_id", "tiantian");
        set("room_position", "南大街");
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
