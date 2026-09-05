#include <room.h>
#include <ansi.h>
inherit ROOM;
string look_mishi();
void create()
{
        set("short", WHT+"密室"+NOR);
        set("long", @LONG
这是铜雀台后的一件密室，此处内却又有许多带锁的房间(rooms)。

LONG
        );
        set("exits", ([
             "west" : __DIR__"dating",
        ]));
        set("item_desc",
        ([
        "rooms":(:look_mishi:),
        ]));
        
        setup();
      
}
void init()
{
	add_action("do_insert","insert");
	add_action("do_enter","enter");
}

mapping key_password = ([
        "spider":        "/d/wizard/zine/spider_room",
]);
int do_enter()
{
	object me=this_player(),room;
	string key_pass=me->query_temp("tqt/mishi_permit");
	if (!key_pass)
	{
		return 0;
	}
	room=load_object(key_password[key_pass]);
	if (objectp(room)&&room->isroom())
	{
		message_vision(HIG+"$N"+HIG+"开启了"+room->query("short")+HIG+"的大门，转身走了进去。\n",me);
		tell_object(me,room->query("short")+BLINK+HIR+"可以存盘，退出后可连线再次，但一次开启只能使用十二小时，慎用。\n"+NOR);
		tell_object(me,"离开后可能无法再次进入"+room->query("short")+"。\n");
		me->delete_temp("tqt/mishi_permit");
		me->set("tqt/mishi/enter_time",time());
		me->move(room);
		me->save();
		return 1;
	}
	else
	{
		tell_object(me,"开启密室失败，请联系Zine获得补偿！\n");
		me->set("tqt/error/"+key_pass,1);
		return 1;
	}
}
int do_insert(string arg)
{
	object me=this_player();
	object key;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要把什么插入锁眼？\n");
		return 1;
	}
	if (!key=present(arg,me))
	{
		tell_object(me,"你身上并无"+arg+"。\n");
		return 1;
	}
	if (!key->query("key_tqt"))
	{
		tell_object(me,key->query("name")+"和密室的锁眼并不相称。\n");
		return 1;
	}
	if (key->query("key_for")=="spider"&&me->query_skill("hand",1)<400)
	{
		tell_object(me,"进入养蛛室练习至少需要四百级基本手法，方可无害。\n");
		tell_object(me,"在铜雀台静室可练习基本功夫。\n");
		return 1;
	}
	message_vision("$N拿出了"+key->query("name")+"插入了密室的某个锁眼，转了几转，几声喀喀声响之后，一间小屋的门向$N打开了。\n",me);
	me->set_temp("tqt/mishi_permit",key->query("key_for"));
	destruct(key);
	return 1;
}
string look_mishi()
{
	string msg;
	msg="目前可用的房间有：\n";
	msg+="养蛛室\n";
	msg+="每间房间均须插入(insert)钥匙才能进入(enter)。\n";
	return msg;
}
