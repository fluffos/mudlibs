// Room: /clone/misc/lakeside2.c
// create by zine aug 28 2010
inherit "/biwu/biwuroom1";

void create()
{
	set("short", "湖边");
	set("long", @LONG
一片碧光粼粼的湖面，夕阳下美得让人心醉。不时有几条鱼儿跃出湖面。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"eastgate",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_swim", ({ "swim", "you" }));
	::init();
}

int do_swim(string arg)
{
	object me;
	me = this_player();
	if ( !arg ) 
		{
		return notify_fail("你要往那里游？\n");
		}
	if (arg != "lake" && arg!="hu")
		{
			return notify_fail("你要往那里游？\n");
		}
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	else
		{
			message_vision("$N一个漂亮的入水，没带起一点水花，潜入了湖底。\n", me);
			me->move(__DIR__"hudi");
			me->add_busy(random(2));
			tell_room(environment(me), me->name() + "从湖边跳了下来。\n", ({ me }));
			return 1;
		}
}