// wanfota.c
// 万佛塔
inherit ROOM;
void create()
{
	set("short", "万佛塔");
	set("long",@long
这里就是万佛顶上的万佛塔了，塔内供奉着很多牌位。
long);
	set("exits",([
	 "out" : __DIR__"wanfoding",
]));
	setup();
}

void reset()
{
	set("count", 1);
	::reset();
}

void init()
{
	add_action("do_ketou", "ketou");
	add_action("do_ketou", "拜祭");
}             

int do_ketou()
{
	object me = this_player();
	object ob = this_object();
	object ring;

	if ( !me->query_temp("marks/pass_yitian") ) return 0;
       me->receive_damage("jingli", 30);
	if ( me->query_temp("ketou") >= random( 60 ) + 1 ) {
		if ( query("count") > 0 && ring = unew(__DIR__"obj/ring")) {
			ring->move(ob);
			message("vision","只听见铛的一声，灵牌里掉下一只" +
				"铁指环。\n",me);
			me->delete_temp("ketou",1);
                        me->set_temp("marks/get_ring",1);
			add("count", -1);
			return 1;
		}
		else {
			message("vision","你不经意望见灵牌似乎已被打开过。\n",
				me);
			me->delete_temp("ketou");
			return 1;
		}
	}
	else {
		me->add_temp("ketou", 1);
		message_vision("$N恭恭敬敬地在灵牌前磕了个响头。\n", me);
		return 1;
	}
}	
