 //      jueding.c 凌霄绝顶

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"绝顶"NOR);
        set("long",@LONG 
这里是大雪山顶峰，人迹罕至，连鸟兽都不见踪影。四面寂静，惟闻风声。
凛冽的山风刮脸如刀，透骨冰凉，平常人只待上一小会就得被冻僵。
LONG);

        set("exits", ([
                "down" : __DIR__"shanpo",
        ]));

        set("hua", 1);

        setup();
}

void init()
{
        mixed *local;
    
	local = localtime(time() * 60);
	add_action("do_get","cai");
	add_action("do_look", "look");
	if ( (local[2] < 11 || local[2] > 13) && !wizardp(this_player())) {
		message_vision(HIW"狂风夹着雪花劈头盖脸打了过来，吹得$N睁不开眼。\n"+
			"突然从山崖边落下一大块积雪，$N躲闪不及正砸在头上！\n"NOR,this_player());
		message_vision(HIR"\n$N脚下不稳，顺着山崖跌落下去。\n"NOR,this_player());
		this_player()->move(__DIR__"xuegu");
		this_player()->unconcious();
	}
}

int do_look(string arg)
{
	object me;
	me = this_player();
	if (query("hua") < 1){
	set("long", @LONG
这里是大雪山顶峰，人迹罕至，连鸟兽都不见踪影。四面寂静，惟闻风声。
凛冽的山风刮脸如刀，透骨冰凉，平常人只待上一小会就得被冻僵。
LONG
);
	me->look(arg);
	}
	else {
		if (!arg) {
		set("long", @LONG
这里是大雪山顶峰，人迹罕至，连鸟兽都不见踪影。四面寂静，惟闻风声。
凛冽的山风刮脸如刀，透骨冰凉，平常人只待上一小会就得被冻僵。你欣喜地
发现一朵生长在西藏高原上极其罕见的藏红花（hua）。
LONG
		);
		me->look(arg);
		}
		else if(arg == "hua") {
			write("一朵生长在西藏高原上极其罕见的藏红花。好象可以采(cai)下来。\n");
			me->set_temp("drug/hua", 1);
			return 1;
		}
	}                
}

int do_get(string arg)
{
	int i;
        object me, ob, *inv;

        me = this_player();
        inv = deep_inventory(me);
        i = sizeof(inv);

        if(!me->query_temp("drug/hua")) return 0;
        if (!arg) return notify_fail("你要采什么？\n");
        if ( arg != "hua") return notify_fail("你要采什么？\n");

        while (i--)
        if( inv[i]->query("drug"))
		return notify_fail("你身上已有不少药物，这朵藏红花还是留给别人吧。\n"); 

	ob = new(MEDICINE_D("neili/zanghonghua"));
	ob->set("owner",me->query("id"));
	log_file("quest/neili",sprintf("%-18s在雪山绝顶处得到%s。\n",
		me->name(1)+"("+capitalize(me->query("id"))+")",ob->name()), me);
	ob->move(me);
	add("hua", -1);
	me->delete_temp("drug/hua");
	message_vision("$N小心翼翼地采下一朵"HIR"藏红花"NOR"。\n",me);
	return 1;
}

void reset()
{
	set("hua", 1);
}

int clean_up()
{
	return 0;
}
