#include <ansi.h>
inherit ROOM;

void create()
{
        object gold;
        set("short", "内洞");
        set("long", @LONG
这里就是堆放天下密宝的密洞了!但是你却没看到宝藏,
洞的中间放着一口棺材(coffin)，洞顶刻有文字(zi)。
LONG
        );

	set("count", 1);

        set("exits", ([
                "north" : __DIR__"midong",
                ]));
    	set("item_desc",([
                "zi" : HIR "
                   人     鸟
                   为     为
                   财     食
                   死     亡
                   \n\n"NOR,
                 "coffin" : "也许宝藏就在棺材里面。\n",
        ]));


        set("objects",([
            //__DIR__"npc/corpse":5,
        ]) );
 	setup();
}

void init()
{
     	add_action("do_open", "push");
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, zombie, ob, room;
	int i;

   	me = this_player();
  	me->save();

	if (!arg || arg != "coffin")
	{
		write("你要打开什么?\n");
		return 1;
	}
	if ( ((int)me->query_condition("push_coffin" ) > 0 ) )
	{
		write("你前不久才来拿过东西，现在又来拿太贪心了吧。\n");
		return 1;
	}
	if ( this_object()->query("count") <= 0 )
	{
		write("有人不久前才来拿过东西，现在棺材已经空了。\n");
		return 1;
	}

	room = load_object(__DIR__"midong");
	room->reset();

	message_vision("$N推开棺材盖子，一只硕大的僵尸跳了出来。\n", me);

	me->apply_condition("push_coffin", 2000);
	zombie = new(__DIR__"npc/zombie");
	zombie->move(this_object());
	zombie->command("guard north");
	zombie->set_leader(me);
	zombie->kill_ob(me);
	add("count", -1);
	return 1;
}