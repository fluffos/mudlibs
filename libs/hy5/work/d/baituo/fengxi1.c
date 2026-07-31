#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "缝隙");
        set("long", @LONG
这里是石块与石块之间的夹缝，光线昏暗。你明显感觉到四周的沙沙
声是各种毒虫爬行的声音，一股股腥味中也夹杂着一些刺鼻的气息。你发
现前面有一石块(shikuai) 隐隐发出淡淡的光芒。
LONG);
       set("objects", ([
                    __DIR__"npc/fushe" : 2
        ]));
        set("exits", ([
              "south" : __DIR__"fengxi",
              "west" : __DIR__"fengxi2",
              "out" : __DIR__"yuanzi3",
        ]));
         set("item_desc", ([                    
                "shikuai": RED"\n这块石头呈红汞色，散发着阵阵热气，石块上凹陷进去的部分是个左手手掌形。\n"NOR,
        ]));
        setup(); 
}

void init()
{
        add_action("do_push", "tui");
        add_action("do_push", "push");      
}

int do_push(string arg)
{
        object me = this_player();
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙着呢。\n");
        	
        if( !me->query_temp("baituo_stone") ) return 0;
        if( (int)me->query_temp("baituo_stone") > 1) 
                return notify_fail("你已经推动过了石块。\n");
                
        if (arg == "shikuai" ){   
           	message_vision("$N深深吸了口气，伸出左手按住石块上的手印，缓缓向下推去。\n", me);            
           	me->add_temp("baituo_stone", 1);
           	message_vision("$N将石块按下寸许，隐隐约约听到地下传来一阵轰隆声。\n", me);
           	me->start_busy(5);      
           	call_out("poisoned", 5, me);
        	return 1;
        } 
        return 0;    
}

int poisoned(object me)
{
        if(!me) return 0;
        
        if ((int)me->query_skill("poison", 1) < 80 &&
             !me->query_skill("hamagong", 1)){
               tell_object(me, RED "你感到石块上的炎热之气顺着手臂慢慢传了上来。\n\n" NOR );
               message_vision("$N突然身子一颤，好象是中了热毒！\n", me);
               me->apply_condition("snake_poison", me->query_condition("snake_poison")+50);
               return 1;
               }   
        else {
               tell_object(me, RED "忽然一股炎热之气顺着手臂从石块上慢慢传了上来。\n\n" NOR );
               tell_object(me, HIW "你连忙运功调气，将侵入手臂的炎热之气尽数逼了出去。\n" NOR );
               return 1;
               }               
}
