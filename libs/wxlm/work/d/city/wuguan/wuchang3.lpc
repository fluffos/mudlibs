//wuchang3.c

inherit ROOM;

int do_tiao(string arg);

void create()
{
        set("short", "东练武场");
        set("long", @LONG
这里是个露天练武场，门口写着一块牌子（paizi）。好多人在这里辛苦的
练着，你走在场中，可是没有人回头看你一眼，都在聚精汇神的练着自己的功
夫，场子的东角有一个沙坑(shakeng)。
LONG
        );
	set("item_desc",([
            "【牌子】" :
		HIY"
※※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　　※※※※
※※※※　                  ※※※※
※※※※   东  练  武  场   ※※※※
※※※※　                  ※※※※     
※※※※　　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※※"NOR"\n",
            "shakeng" : "一个大沙坑，几个小伙子正在其中上下跳(tiao)跃。\n",
	]));

	set("outdoors","武馆");
	set("no_fight",1);
        set("exits", ([
               "east" : __DIR__"wuchang4",
               "west" : __DIR__"shilu4",
	       "south" : __DIR__"bingqiku",
        ]));
	
        set("objects", ([
                  __DIR__"npc/jiaotou" : 1,
        ]));
	set("action_list", ([
		"跳沙坑":"tiao shakeng",
	]));
        setup();
}

void init()
{
        add_action("do_tiao", "tiao");        
}

int do_tiao(string arg)
{       
        object me;
        int costj, costq;

        me = this_player();
        if (me->is_busy()){
            write("你现在正忙着呢!\n");
            return 1;
        }
        if (me->is_fighting()){
            write("你正在战斗中,无法专心干活!\n");
            return 1;
        }
        if ( !living(me)) return notify_fail("你发疯了? \n");     

        if ( !arg || arg != "shakeng" ){ 
            write("你在场子里蹦蹦跳跳了半天，别人还以为你发神经！\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N奋力一跳，脚一滑，在沙坑里摔了个狗吃屎!"NOR"\n",me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jing", costj);
        me->add("qi", -costq);       

        write("你气从丹田提升，奋力一跳。\n");

        if ( (int)me->query_skill("dodge", 1) < 20 && random(10)>6 ){
            write(HIM"你不断的在沙坑中跳着，自己的基本轻功有了提高!"NOR"\n");
            me->improve_skill("dodge", (int)(me->query("int") / 6));
        }
        return 1;
}
