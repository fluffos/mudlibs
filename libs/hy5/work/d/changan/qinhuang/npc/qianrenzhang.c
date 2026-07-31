#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc.c"

void set_from_me(object me); 
void create()
{
        string *names = ({ "陶俑千人长" }); 
        
        ::create();
        set_name( names[random(sizeof(names))], ({ "qian renzhang"}));
        set("long", @LONG
这是一个沉睡在皇陵千年陶俑千人长，身高七尺有余，由陶土烧制而成，看起来十分
坚硬。他手持一柄青铜巨锤，神情颇为威武。在机关消息的作用下，他的四肢可以活
动，攻守进退也有模有样，但总归不算非常灵活。
LONG);
        set("title", YEL"皇陵四品护卫" NOR); 
 
        set("str", 80);
        set("con", 80);
        set("dex", 80); 
        set("int", 80);
        set("max_qi", 100000);
        set("max_jing", 50000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("max_jingli", 50000);
        set("attitude", "killer");
        set("auto_perfrom", 1);
 
        set("combat_exp", 10000000);
        set("death_msg",YEL"\n$N化成了一堆黄土。\n\n"NOR);
 
        set("bonus", 10000);
        set_temp("apply/attack", 5000);
        set_temp("apply/parry", 5000);
        set_temp("apply/damage", 5000);
        set_temp("apply/unarmed_damage", 5000);
        set_temp("apply/armor", 5000);          
        setup();
        initlvl(220+random(270));     
} 
 
void init()
{
        object me;

        ::init();
        if (! interactive(me = this_player()) || 
            this_object()->is_fighting())
                return;
                
       
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
 

