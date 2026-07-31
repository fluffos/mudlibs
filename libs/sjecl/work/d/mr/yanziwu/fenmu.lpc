
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",BLU"墓地"NOR);
	set("long", @LONG
这里是慕容的坟场, 慕容氏的子孙死后都被安葬这里，世世代代, 无一例外。
每到清明时分, 慕容后裔都要在这里祭祖。场中一座新坟格外引人住目, 坟前
有一块墓碑(bei)。
LONG);
	set("exits", ([
		"west" : __DIR__"xiaojing4",
	]));
	set("outdoors", "燕子坞");
	set("item_desc", ([
		"bei" : "慕容博之墓\n",
		"mubei" : "慕容博之墓\n",
	]));
	setup();
}

void init()
{
	this_player()->set_temp("ketou_times", 30);
	add_action("do_ketou", "ketou");
//	add_action("do_push", "push");
}

int do_push(string arg)
{
	if ( !arg || (arg != "bei") )
		return notify_fail("你要推什么？\n");

	if((int)this_player()->query("neili")< 1000)
		return notify_fail("你感觉气喘吁吁，力不从心，原来是内力不够了。\n");

	message_vision("$N大喝一声，双掌推向墓碑，只见墓碑后闪出一个出口，$N纵身一跃不见人影。\n",this_player());
	this_player()->move(__DIR__"mishi");
	message_vision("$N从坟墓跳了进来。 \n",this_player());

	return 1;
}

int do_ketou()
{
	object me, ob;

	me = this_player();

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query_temp("ketou_times") == 0 ) {
		message_vision("$N磕头磕得晕了过去。\n", me);
		me->set_temp("ketou_times", random(30));
		me->unconcious();
		return 1;
	}

	me->add_temp("ketou_times", -1);

	message_vision("$N虔诚地跪下来，在墓碑面前磕头。\n", me);

	if ((int)me->query_skill("force", 1) >= 30
	&& (int)me->query_skill("force", 1) <= 100
	&& present("force book", me)) {
		me->receive_damage("jing", 20);
		me->improve_skill("force", me->query("int"));
		if ( random(5) == 0 )
		tell_object(me, "冥冥之中，你似乎觉得解决了你在内功方面的疑难。\n");
	}
	if ( random(100) == 37 ) {
		ob= unew(BOOK_D("neigong-book"));
		if(!ob) return 1;
		ob->move(__DIR__"fenmu");
		tell_object(me, "突然你面前，啪地一声掉下一本内功心法！\n");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("ketou_times") >= 0 )
		me->delete_temp("ketou_times");
	return ::valid_leave();
}
