#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "睡房");
        set("long", @LONG
这间睡房宽敞明亮，想来便是庄主的卧室了。有一张书桌，桌子上
放有几本书，却是《易经》之类。墙边有一大箱子。整个房间看上去极
为单调。
LONG);
        set("no_fight", "1");
        set("objects", ([
                    __DIR__"obj/book1" : 1,
        ]));
        set("book_count",1);
        set("exits", ([
              "west" : __DIR__"tangwu",
        ]));
        setup(); 
}

void init()
{
        add_action("do_shui", "sleep");
}

int do_shui(string arg)
{
        object me = this_player();
        object where = environment(me);  
        if (me->is_busy() || me->is_fighting() )
        	return notify_fail("你正忙着呢。\n");      
        message_vision("\n$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me); 
        me->start_busy(3);       
        me->set_temp("block_msg/all",1);
        me->disable_player("<睡梦中>");
        call_out("wakeup", 40, me, where);
        return 1;
}

void wakeup(object me)
{
        int cost;
        
        if (!me) return;
        if (!cost = me->query_condition("sleep"))
                me->apply_condition("sleep", 9);
        cost++;        
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));      
                
        me->add("qi",    (me->query("eff_qi") - me->query("qi"))/cost);
        me->add("jing",  (me->query("eff_jing") - me->query("jing"))/cost);
        me->add("neili", (me->query("max_neili") - me->query("neili"))/2/cost);
        me->add("jingli", (me->query("eff_jingli") - me->query("jingli"))/2/cost);
        me->enable_player();
        message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
        me->delete_temp("block_msg/all");       
        write("你一觉醒来，觉得精力充沛，该活动一下了。\n");
        if (random(me->query("kar")) > 15 
        && me->query("oyf_son")
        && me->query_skill("hamagong", 1)
        && query("book_count") >= 1){ 
             	write("你随手在床边一撑，忽然发现床单下盖着什么东西。\n");
             	write("掀开床单一看，原来是一本薄薄的线装书。\n");
             	new_ob(__DIR__"obj/book")->move(me);
             	if(!wizardp(me))
             		log_file("quest/hmg_book", me->query("name")+"("+me->query("id")+
             		") got hamagong book on " + ctime(time()) + "。\n" );
             	add("book_count", -1);
        }
        me->start_busy(2);
}
