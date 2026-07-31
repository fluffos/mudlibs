//wuchang1.c

#include <ansi.h>
inherit ROOM;
int do_da(string arg);

void create()
{
        set("short", "西武场");
        set("long", @LONG
这里是个露天练武场，门口写着一块牌子（paizi）。好多人在这里辛苦的
练着，你走在场中，可是没有人回头看你一眼，都在聚精汇神的练着自己的功
夫。地上有一些练武用的工具，墙边摆着一排木桩（zhuang）和几个练功用的
木人（muren）。
LONG);

        set("exits", ([              
               "east" : __DIR__"wuchang2",
        ]));
	set("no_fight",1);
        set("item_desc", ([
          "zhuang"  :  "一个木桩，外面围着一层麻布固定在地上，供人击打(da)练功。\n",
	  "【牌子】" :
		HIY"
※※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　　※※※※
※※※※　                  ※※※※
※※※※   西  练  武  场   ※※※※
※※※※　                  ※※※※     
※※※※　　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※※"NOR"\n",
		]));

	//set("outdoors","武馆");
		
        set("objects", ([
                   __DIR__"npc/muren" : 1,
        ]));
	set("action_list", ([
		"打桩":"da zhuang",
	]));
        setup();
}

void init()
{
        add_action("do_da", "da");        
}

int do_da(string arg)
{
        object me;
        int costj, costq;

        me = this_player();
        
        if (me->is_busy()) 
            	return notify_fail("你现在正忙着呢!\n");
        if (me->is_fighting())
            	return notify_fail("你正在战斗中,无法专心干活!\n");
        if ( !living(me))
            	return notify_fail("你发疯了? \n");        
        if( objectp( me->query_temp("weapon")))
            	return notify_fail("只有空手才能打木桩。\n");
        if (!arg || arg != "zhuang")
      	    	return notify_fail("你要打什么？打人吗？\n");

        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
           	message_vision(HIR"$N马步一松，一不小心撞在了木桩上!"NOR"\n",me);
           	me->unconcious();
	   	return 1;
	}
        
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       

        message_vision("$N站好马步，运气于拳，和木桩对打起来。\n", me);

        if ( (int)me->query_skill("cuff", 1) < 20 && random(10)>6 ){
            	write(HIM"你在和木人桩的对打中领悟了不少基本拳法!"NOR"\n");
            	me->improve_skill("cuff", (int)me->query("int") / 6);
        }
        return 1;
}
