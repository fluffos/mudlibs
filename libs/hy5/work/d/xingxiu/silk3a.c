// /d/xingxiu/silk3.c
inherit ROOM;
#include <ansi.h>

int wind = 0;

void create()
{
        set("short", YEL"鸣沙山"NOR);
        set("long", @LONG
此山高数十米，山峰陡峭，势如刀刃。北麓有月牙泉。登山俯瞰，沙丘林
立，清泉荡漾。从山顶下滑沙砾随人体下坠，鸣声不绝于耳，兴味盎然。
故称“沙岭晴鸣”。
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "south" : __DIR__"silk3",
                "west" : __DIR__"silk3b",
        ]));

        setup();
        set("yushi_count", 2);
}

void do_move(object me)
{
        if(!me) return;
        tell_object(me, HIR"你一陷身在这狂怒的风暴中，根本身不由己，只能听天由命了....\n\n"NOR);
        me->set_temp("isdeads",1);
        me->unconcious();
        me->move(random(2)?"/d/xingxiu/silk3b":"/d/xingxiu/silk3");
        message("vision", "突然一阵大风刮过，将一个"+me->name()+"甩了过来！\n",environment(me), ({me}));
}

void init()
{
   if(this_player()->query_temp("xlz/hang") && wind == 0)      
//           call_out("do_wait", 3+random(10), this_player());
           call_out("do_wait", 300+random(100), this_player());
   else if(wind > 0) 
           do_move(this_player());
   
   add_action("do_kangheng", "kangheng");
   
}

#include "/kungfu/skill/eff_msg.h";

int do_kangheng()
{
        
        object me;
        int p;
        
        me = this_player(); 
        
        if(wind <= 0 || !me->query_temp("xlz/hang")) return 0;
        
        if( me->query_temp("weapon") )
                return notify_fail("在这种危险的情况下，你还念念不忘手中的武器？！\n");
                
        if (me->query_skill_mapped("unarmed") != "xianglong-zhang"
        || me->query_skill_mapped("parry") != "xianglong-zhang")
                return notify_fail("现在是叫天不应，呼地不灵的时候，你唯一的出路是用「降龙十八掌掌」抗衡！\n");  
                
        if( (int)me->query("max_neili") < 3000)
                return notify_fail(HIR"\n你现在才发觉自己的内力修为是如此的浅薄，完了... 现在后悔已经晚了...\n\n"NOR);      

        if( (int)me->query("neili") < 500 )
                return notify_fail(HIR"你觉得自己已经是内力不继，双手在风中也在不住地颤抖！\n"NOR);
                
        tell_room(me, HIC"你咬紧牙关，双掌护身，心中默念降龙十八掌的口诀，企图在这天地的怒气中维持自己的弱小生命！\n"NOR); 
        
        me->receive_damage("qi", me->query_con()*10);
        me->add("neili", -500);
        p = (int)me->query("qi")*100/(int)me->query("max_qi");
        message_vision("( $N"+eff_status_msg(p)+" )\n", me);
        me->add("combat_exp", 100); 
        me->add_temp("xlz/hang", 1);      
        return 1;
}


int do_wait(object me)
{
        
        object *obj, ob = this_object();
        int i;
        
        if(!me || environment(me) != ob
        || !living(me) || me->is_fighting()) 
                return 0;
        
        tell_room(ob, HIY"
突然，一阵嘘嘘的风声吹来，那尖利的啸声如刀，如剑，越来越尖... 越来越急...

瞬间，已经是狂风大做，漫天的黄沙扑面而来，一浪接着一浪，一波接着一波...

你在这风沙中有如一只大海中漂泊的小舟，如果不想被大自然所吞没，只有奋起和

它相抗衡(kangheng)了！\n" NOR);  

        ob->set_temp("apply/long", YEL"这里黄沙漫天，狂风呼啸，那尖利的啸声如刀，如剑，越来越尖... 越来越急...\n"YEL);
        ob->delete("exits");
        obj = all_inventory(ob);
        if(obj)
                for(i=0; i<sizeof(obj); i++) {
                        if(obj[i]->query_temp("xlz/hang")) continue;
                        do_move(obj[i]);
                }

        
        wind = 15;
        me->start_busy(10);
        call_out("do_wait2", 10+random(10), me);        
        return 1;
}

int do_wait2(object me)
{
        
        object *obj, ob = this_object();
        int i, p;
        string msg;
        
        if(!me || !userp(me) || environment(me) != ob || me->is_ghost() ){
                remove_call_out("do_over"); 
                call_out("do_over", 5, ob);
                return 0;
        }
        
        if( wind <= 0) {
        	remove_call_out("do_over"); 
                call_out("do_over", 5, me);
                return 0;
        }
        
        wind--;
        
        me->start_busy(10);
        
        if(!living(me)){
                me->delete_temp("xlz/hang");
                me->set_temp("last_damage_from", "被黄沙淹没脱力而");
                me->set_temp("isdeads",1);
                me->die();
                return 0;
                }
                
        switch(wind){
                case 0: remove_call_out("do_over"); 
                        call_out("do_over", 5, me);
                        return 0;
                case 14: msg = YEL"\n风沙越来越大，越来越猛... \n\n"NOR; break;
                case 11: msg = YEL"\n黄杀如同波浪一般，一浪接一浪滚滚而至，将你打得东倒西歪！\n\n"NOR; break;
                case 8: msg = YEL"\n风逐渐变弱了，但强烈的气流还在四周旋转着，看来是到了暴风的中心了！\n\n"NOR; break;
                case 4: msg = YEL"\n暴风中心虽然过了，但这强烈的气流却不断地将你压迫，眼前是一片黄沙，什么也看不见！\n\n"NOR; break;
                case 1: msg = YEL"\n风越来越弱了，漫天的黄沙也渐渐消失，阳光又穿透了过来... \n\n"NOR; break;
                default: msg = random(2)? YEL"\n风呼呼地吹着，飞舞的砂砾打在你身上，疼痛万分！\n\n"NOR:
                                          YEL"\n强烈的气流在四周呼啸着，天地已经混为一体，根本没有了东南西北！\n\n"NOR; break;
                }
        tell_room(ob, msg);  

        obj = all_inventory(ob);
        if(obj)
                for(i=0; i<sizeof(obj); i++) {
                        if(obj[i]->query_temp("xlz/hang")) continue;
                        do_move(obj[i]);
                }

        me->receive_damage("qi", 200+random(500));
        p = (int)me->query("qi")*100/(int)me->query("max_qi");
        message_vision("( $N"+eff_status_msg(p)+" )\n", me);
        
        call_out("do_wait2", 10+random(10), me);         
        return 1;
}

int do_over(object me)
{

        wind = 0;
        tell_room(this_object(), HIW"\n突然间，狂风渐渐远去，天空豁然开朗，一切又恢复了原来的样子：这沙，这山...\n\n"NOR); 
        
        this_object()->set_temp("apply/long");
        this_object()->set("exits", ([
                "south" : __DIR__"silk3",
                "west" : __DIR__"silk3b",          
                ]));  
                
        if(!me || !userp(me) || environment(me) != this_object()
        || !living(me) || me->is_ghost())
                return 0;
                
        me->start_busy(2);
        if((int)me->query_temp("xlz/hang") > 1){
                me->set("xlz/hang", 1);
                me->delete_temp("xlz/hang");
                tell_object(me, GRN"你经过一番苦斗，已经全身虚脱，但这从风中所得到的启示却使你对自己的降龙十八掌更具信心！\n"NOR);
                tell_object(me, HIC"你领悟了降龙十八掌之精髓！自己的体质也得到了改善！\n"NOR);
                me->add("con", 1);
                me->add("str", 1); 
                }      
        return 1;
}
