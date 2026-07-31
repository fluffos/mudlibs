// File(/data/room/luoyuna/shufang.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <ansi.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "书房");
	set("long", "这里是小白居的主人大白读书写字的地方，干净明亮。文房四宝
整整齐齐的摆在桌子上面。有时大白也在这里签发(sign)一些邀请客
人的请柬。
");

	set("exits", ([
		"east" : __DIR__"jusuo",
	]));

	set("sleep_room", 1);
	setup();

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
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
	return 1;
}
