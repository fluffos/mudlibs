// Room: /d/huashan/hole.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "思过崖洞口");
	set("long", @LONG
这里便是犯错误华山派弟子受罚思过的地方。位于玉女峰顶，正好有一小
块平地，一面是深不可测的山谷、一面是陡峭的悬壁(bi)，零零落落的有几块
山石。其中一块特别光滑，想是弟子在面壁是久坐而成。
LONG
	);
	set("exits", ([
		"out" : __DIR__"siguoya",
	]));

	set("item_desc", ([
		"bi" : "你看着看着忽然发现有一处石壁上的青苔比别处少得多。不禁想....\n",
	]) );

	setup();
}

void init()
{
        object me = this_player();
        me->delete_temp("mianbi_count");
        me->delete_temp("break_flag");
        add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
	int getshen;
        object me = this_player();

        if (me->is_busy())
                return notify_fail("你正忙着呢，无法静下心来面壁思过。\n");
        if (me->is_fighting())
                return notify_fail("你正在战斗中，如何静下心来面壁思过？\n");
        if ((int)me->query("shen") < 0)
        {
        	getshen= random(-1 * (int)me->query("shen")/600);
        }
        else
        {
        	getshen= -1 * random((int)me->query("shen")/300);
        }

        if (!me->query_temp("break_flag"))
        {
        message_vision("$N对着石壁跌坐静思，良久，若有所悟。\n", me);
        me->receive_damage("jing", random(100));
        me->add("shen",getshen);
        me->start_busy(random(3));
        if (random(me->add_temp("mianbi_count", 1)) > 20) {
                me->set_temp("break_flag", 1);
                add_action("do_break", "break");
                write("你忽然产生一种破壁的欲望，不禁站了起来。\n");
        }
        }
        return 1;
}


int do_break(string arg)
{
        int n;
	object me = this_player();
	object weapon;
	object room;
	n = (int)me->query("neili");
   	room = find_object(__DIR__"rukou");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你手中无剑，怎能破壁？\n");
     message_vision("$N走到石壁前，拔出腰间所悬长剑，运劲向石壁刺了过去。\n", me);

    if ( n >= 600 ){
    message_vision("$N只听一声轰响，石壁被捅穿了，原来里面有一个大洞。！\n", me);
    set("exits/enter",__DIR__"rukou");
    set("exits/out",__DIR__"siguoya");
    this_player()->add("neili", -200);
    remove_call_out("close");
    call_out("close", 5, this_object());
    if(!(room = find_object(__DIR__"rukou"))) room = load_object(__DIR__"rukou");
    if( room = find_object(__DIR__"rukou") ) {
    message("vision", "你只听外面一声轰响，石洞被人从外面捅穿了，露出了一个洞口。\n", room);
    room->set("exits/out",__DIR__"hole");
//  remove_call_out("close1");
    call_out("close1", 5, room);   }
    }
    else {
    message_vision("结果只听一声闷哼，$N被石壁的反弹力震得眼前一黑....\n", me);
    this_player()->unconcious();
    }
    return 1;
}

void close(object ob)
{
        message("vision","崖上忽然掉下来一块巨石，将洞口封了个严严实实。\n", ob);
        ob->delete("exits/enter");
}
void close1(object room)
{       
        message("vision","崖上忽然掉下来一块巨石，将洞口封了个严严实实。\n", room);
        room->delete("exits/out");
}