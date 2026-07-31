#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc.c"

void create()
{
        string *names = ({ "陶俑百人长" }); 
        
        ::create();
        set_name( names[random(sizeof(names))], ({ "bai renzhang" }));
        set("long", @LONG
这是一个沉睡在皇陵千年陶俑百人长，身高六尺有余，由陶土烧制而成，看起来十分
坚硬。他手持一柄青铜长枪，神情颇为威武。在机关消息的作用下，他的四肢可以活
动，攻守进退也有模有样，但总归不算非常灵活。
LONG);
        set("title", YEL "皇陵六品护卫" NOR); 
 
        set("str", 50);
        set("con", 50);
        set("dex", 50); 
        set("int", 50);
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("max_jingli", 10000);
        set("attitude", "killer");

        set("combat_exp", 6000000);
        set("death_msg",YEL"\n$N化成了一堆黄土。\n\n"NOR);

        set("bonus", 8000);
        set_temp("apply/attack", 3000);
        set_temp("apply/parry", 3000);
        set_temp("apply/damage", 2000);
        set_temp("apply/unarmed_damage", 2000);
        set_temp("apply/armor", 3000);          
        setup();
initlvl(220+random(170));     
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
 
