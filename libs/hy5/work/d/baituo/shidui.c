#include <ansi.h>
inherit ROOM;
string* obj = ({
       __DIR__"obj/book1",
       __DIR__"obj/book2",
       __DIR__"obj/book3",
       __DIR__"obj/book4",
});
void create()
{
        set("short", "乱石堆");
        set("long", @LONG
这里四周所围全是巨石，地上铺满了凌乱的碎石子，象是被人击打巨
石所打下来的碎块。正中一块平滑的青石板上蹲着一只雪白的蛤蟆。
地下乱七八精有一大堆东西，你好像可以找找(find)看。
LONG);        
        set("objects", ([
                    __DIR__"npc/chanchu" : 1,
        ]));
         set("item_desc", ([                    
                "stone": "\n这些巨石都有凹面，看得出是被人拿来练掌力用的。\n",
        ]));
        set("outdoors", "白陀山");
        setup(); 
}

void init()
{
       	object me = this_player();       
       	if(!me->query_temp("baituo_yun") 
       	&& me->query("id") != "xuanbing chanchu" 
       	&& me->query("id") != "snowman"){
             	message_vision(HIW"玄冰蟾蜍突然纵起，对着$N一口毒气喷出！\n"NOR,this_player()); 
             	tell_object(me, HIB "你感到脑中一阵旋晕，立时昏了过去。\n" NOR ); 
             	me->unconcious();
             	me->move(__DIR__"yuanzi5");
             	tell_room(environment(me), me->name()+"突然从巨石之上直落下来，‘叭’的一声摔在地上！\n", ({ me }));
          	if(me->query_skill("poison", 1) < 100) 
          		me->unconcious();              
          	else me->add("max_neili", -5);
          	}  
        add_action("do_climb", "climb");
        add_action("do_climb", "pa");
        add_action("do_strike", "strike");       
        add_action("do_find", "find");
        add_action("do_find", "zhao");
        add_action("do_find", "fan");

}

int do_climb(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙着呢。\n");
        	
        if (arg == "stone" ){   
           	message_vision("$N手脚并用，爬上了巨石去，翻身一纵，已经跳了出去。\n", me);                      
               	me->move(__DIR__"yuanzi5");
               	message("vision", me->name() + "从里面跳了出来。\n",environment(me), ({me}) );
               	return 1;
        }     
        return 0;
}

int do_strike(string arg)
{
        int improve, cost, hmglevel;
        object me = this_player();
        
        improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
        hmglevel = me->query("oyf_hamagong");
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙着呢。\n");
        	
        if (arg == "stone" ){             
            	if(!me->query_skill("hamagong", 1))  
               		return notify_fail("你用手指推了推巨石，脸上露出一丝难堪的神色。\n");
            	if(me->query_skill("hamagong", 1) > 64 && hmglevel < 2)  
               		return notify_fail("你用手指推了推巨石，脸上露出一丝难堪的神色。\n");
            	if(me->query_skill("hamagong", 1) > 100)  
               		return notify_fail("你一掌向巨石推去，只听轰的一声，巨石被你掌力震成两半！\n");
               		
        	cost = 600 / (int)me->query("int");
        	cost = 600 / (int)me->query("int");

           	if ((int)me->query("jing") < cost || (int)me->query("jing") < cost){
                	message_vision("$N用力过猛, 一不留神劲力反弹，震得$N晕了过去。\n",me);
                	me->unconcious();
                	return 1;
                } 
                
                message_vision("$N默诵蛤蟆功口诀，运力于双掌之上，一掌掌向巨石推去。\n"NOR, me);  
           	me->improve_skill("hamagong", improve);            
           	me->improve_skill("strike", improve/4); 
           	me->receive_damage("jing", cost);
           	me->receive_damage("jing", cost);                        
           	return 1;
        }     
        return 0;
}

int valid_leave(object me)
{        
       me->delete_temp("baituo_yun");       
       return ::valid_leave(me);
}


int found(object me)
{
        object ob = new( obj[random(sizeof(obj))] );
        ob->move(me);
        message_vision("$N翻了半天，找到了" + ob->query("name") + "。\n", me);
        me->set_temp("baituo_find", 1);
        return 1;
}

int do_find()
{
       object me = this_player();
       if( (int)me->query_temp("baituo_find") ) 
                return notify_fail("你已经拿了东西了，走吧。\n");
       if (me->query_skill("hamagong", 1) && 
           me->query_skill("poison", 1) > 30){
                message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
                found(me);    
                }
       else if (me->query_skill("poison", 1) > 50){
                message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
                if(random((int)me->query("kar")) < 15){
                     write("你吸了口气，突然觉得头中一阵眩晕。\n");
                     me->unconcious();
                     }
                else found(me);    
                }
       else { 
                message_vision("$N捏着鼻子在物品堆中乱翻着。\n", me);
                write("你吸了口气，突然觉得头中一阵眩晕。。。不好！你中毒了！\n");
                me->apply_condition("snake_poison", me->query_condition("snake_poison")+22);
                me->unconcious();
                }
       return 1; 
}

