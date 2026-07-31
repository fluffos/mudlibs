//wuchang2.c
#include <ansi.h>
inherit ROOM;
int do_chuo(string arg);
int do_da(string arg);
int do_pai(string arg);
int do_zhua(string arg);

void create()
{
        set("short", "西练武场");
        set("long", @LONG
这里是个露天练武场，门口写着一块牌子（paizi）。好多人在这里辛苦的
练着，你走在场中，可是没有人回头看你一眼，都在聚精汇神的练着自己的功
夫，墙角挂着一排大大的沙袋（shadai），一些人正在用沙袋练功。
LONG
        );

        set("exits", ([
               "west" : __DIR__"wuchang1",
               "north" : __DIR__"zoulang1",
	       "east" : __DIR__"shilu3",
	       "south" : __DIR__"shilu2",
        ]));
	set("no_fight",1);
        set("item_desc", ([
           "shadai"  :  "一个大沙袋，挂在柱子上，供新人们练习基本功。\n",
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
	set("action_list", ([
		"戳沙袋":"chuo shadai",
		"拍沙袋":"pai shadai",
		"打沙袋":"da shadai",
		"抓沙袋":"zhua shadai",
	]));
        setup();
}

void init()
{
        add_action("do_chuo", "chuo");
        add_action("do_pai", "pai");
        add_action("do_da", "da");
        add_action("do_zhua", "zhua");
}

int do_chuo(string arg)
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
        
        if( objectp( me->query_temp("weapon")) )
            return notify_fail("只有空手才能打沙袋。\n");

        if ( !arg || arg != "shadai" ){
            write("你伸出食指在空中乱戳一通，好象在鬼画符!\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N用力过猛, 一个不小心,戳在墙上!"NOR"\n",me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jing", costj);
        me->add("qi", -costq);       

        message_vision("$N运气于指，向沙袋戳去。\n", me);

        if ( (int)me->query_skill("finger", 1) < 20 && random(10)>6 ){
            write(HIM"沙袋左右摇晃，你不知不觉中领悟了些基本指法!"NOR"\n");
            me->improve_skill("finger", (int)(me->query("int") / 6));
        }
        return 1;
}

int do_da(string arg)
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
        
        if ( !arg || arg != "shadai" ){
            write("你在空中乱踢一阵，旁边人看着你大笑起来!\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N用力过猛, 一个不小心踢了个空,摔在地上!"NOR"\n",me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jing", costj);
        me->add("qi", -costq);       

        message_vision("$N运气手和脚之上，向沙袋拳打脚踢而去。\n", me);

        if ( (int)me->query_skill("unarmed", 1) < 20 && random(10)>6 ){
            write(HIM"你把沙袋打的摆来摆去，觉的自己的基本拳脚有了提高!"NOR"\n");
            me->improve_skill("unarmed", (int)(me->query("int") / 6));
        }
        return 1;
}

int do_zhua(string arg)
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
        if ( !arg || arg != "shadai" ){
       	    write("你双手乱抓，把周围的人吓了一跳!\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N用力过猛, 一个不留神,抓在自己身上!"NOR"\n",me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jing", costj);
        me->add("qi", -costq);       

        message_vision("$N运气于指，向沙袋抓去。\n", me);

        if ( (int)me->query_skill("claw", 1) < 30 && random(10)>6 ){
            write(HIM"你不断的抓着沙袋，觉的自己的基本抓法有了提高!"NOR"\n");
            me->improve_skill("claw", (int)(me->query("int") / 6));
        }
        return 1;
}

int do_pai(string arg)
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
        if ( !arg || arg != "shadai" ){
            write("你伸手乱拍，打在了旁边人的身上!\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N用力不当，控制不住，一下拍空，摔了一跤!"NOR"\n",me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jing", costj);
        me->add("qi", -costq);       

        message_vision("$N运气于掌，向沙袋拍去。\n", me);

        if ( (int)me->query_skill("strike", 1) < 20 && random(10)>6){
            write(HIM"你把沙袋拍的荡来荡去，觉得自己的基本掌法有了提高!"NOR"\n");
            me->improve_skill("strike", (int)(me->query("int") / 6));
        }
        return 1;

}
