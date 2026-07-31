#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc.c"


void set_from_me(object me);
void create()
{
        string *names = ({ "陶俑兵士" }); 
        
        ::create();
        set_name( names[random(sizeof(names))], ({ "bing shi"}) );
        set("long", @LONG
这是一个沉睡在皇陵千年陶俑兵士，身高五尺有余，由陶土烧制而成，看起来十分坚
硬。他手持一柄青铜长矛，神情颇为威武。在机关消息的作用下，他的四肢可以活动，
攻守进退也有模有样，但总归不算非常灵活。
LONG);
        set("title", YEL "皇陵护卫" NOR); 
 
        set("str", 50);
        set("con", 50);
        set("dex", 50); 
        set("int", 50);
        set("max_qi", 10000);
        set("max_jing", 15000);
        set("neili", 150000);
        set("max_neili", 150000);
        set("max_jingli", 10000);
        set("attitude", "peaceful");

        set("combat_exp", 2000000);
        set("death_msg",YEL"\n$N化成了一堆黄土。\n\n"NOR);

        set("bonus", 5000);
        set_temp("apply/attack", 1000);
        set_temp("apply/parry", 1000);
        set_temp("apply/damage", 500);
        set_temp("apply/unarmed_damage", 500);
        set_temp("apply/armor", 1000);          
        setup();
initlvl(220+random(70));        
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
 
