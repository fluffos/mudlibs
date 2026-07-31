#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc.c"

void create()
{
        string *names = ({ "陶俑将领" }); 
        
        ::create();
        set_name( names[random(sizeof(names))], ({ "jiang ling"}));
        set("long", @LONG
这是一个沉睡在皇陵千年陶俑将领，身高八尺有余，由陶土烧制而成，看起来十分坚
硬。他手持一柄青铜长剑，神情颇为威武。在机关消息的作用下，他的四肢可以活动，
攻守进退也有模有样，但总归不算非常灵活。
LONG);
        set("title", YEL "皇陵二品侍卫" NOR); 
 
        set("str", 120);
        set("con", 120);
        set("dex", 120); 
        set("int", 120);
        set("max_qi", 600000);
        set("max_jing", 600000);
        set("neili", 650000);
        set("max_neili", 650000);
        set("max_jingli", 600000);
        set("attitude", "killer");
        set("auto_perfrom", 1);

        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :)
        }) );  
        set("combat_exp", 18000000);
        set("death_msg",YEL"\n$N化成了一堆黄土。\n\n"NOR);

        set("bonus", 15000);
        set_temp("apply/attack", 800);
        set_temp("apply/parry", 800);
        set_temp("apply/damage", 800);
        set_temp("apply/unarmed_damage", 800);
        set_temp("apply/armor", 800);          
        setup();
initlvl(250+random(370)); 
} 

void init()
{
        object me;

        ::init();
        if( !interactive(me = this_player()) || 
            this_object()->is_fighting())
                return;
                

        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
 

void sp_attack() 
{
        object *enemies,enemy;
        string msg;
 
        enemies = query_enemy();
        if( !enemies || sizeof(enemies)==0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        msg = RED"$N"RED"一声嚎叫，口中吐出黄沙，狂风呼啸，那尖利的啸声如刀，如剑，越来越尖... 越来越急...！！\n"
              RED"$n"RED"全身顿时千创百孔，鲜血直涌而出。\n"NOR;
        message_vision(msg, this_object(), enemy);
        enemy->receive_damage("qi",300+random(500));
        COMBAT_D->report_status(enemy);
        if( !enemy->is_busy() )
                enemy->start_busy(2);        
        return;
}

