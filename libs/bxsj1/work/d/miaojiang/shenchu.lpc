// /u/dubei/miaojiang/mjqj

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY+"苗疆奇境"+NOR);
        set("long", @LONG
这里是山顶的深处，但阳光非常明媚。四周的植物上凝结着许多露水。似
乎一些灵药往往生长在这些地方。
LONG                           
        );

        set("qnwu_count",1);
        
        set("exits", ([             
             "northup" : __DIR__"shulin",
        ]));

	set("outdoors", "苗疆");

        set("objects",([
                __DIR__"npc/guaimang" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));    
}
 
int do_wa(string arg)
{ 
	int i;
        object qnwu, me, *inv;

        me = this_player();
        inv = deep_inventory(me);
        i = sizeof(inv);

        if(!( present("xiao tiechan", this_player())))
		return notify_fail("灵药怎能用手去采？\n");

        if( !arg || arg != "qiannian shouwu" )
		return notify_fail("你想做什麽？\n");
        
        if((int)me->query("jingli") < 200) 
		return notify_fail("你太累了！\n");

        if(random(20)!= 3) {
		me->add("jingli",-120);
		return notify_fail("你挖了半天，没有什麽发现。\n"); 
        }

        while (i--)
        if( inv[i]->query("drug"))
		return notify_fail("你挖了半天，没有什麽发现。\n"); 
        
        if( query("qnwu_count") < 1 )
		return notify_fail("你挖了半天，结果一无所获。\n");

        qnwu = unew(MEDICINE_D("neili/qnshouwu"));

        if(!clonep(qnwu)) return notify_fail ("你挖了半天，结果一无所获。\n");
        if(clonep(qnwu) && qnwu->violate_unique()){
		destruct(qnwu);
		return notify_fail ("你挖了半天，结果一无所获。\n");
        } 
	add("qnwu_count", -1);
	qnwu->set("owner", me->query("id"));
	qnwu->move(me);
	log_file("quest/neili",sprintf("%-18s在苗疆挖到了%s。\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",qnwu->name()), me);
	me->add("jingli", -200);
	return 1;
}

int count = 1;

void reset()
{
	if (--count == 0) {
		count = 10;
		set("qnwu_count", 1); 
		::reset();
	}
}

int clean_up()
{
	return 0;
}
