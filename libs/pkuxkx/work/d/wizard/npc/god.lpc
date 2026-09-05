// NPC for reboot

#include <ansi.h>

inherit NPC;

void create()
{
    set_name(HIW "武林至尊" NOR, ({ "royal master", "master" }) );
    set("long", @LONG
他就是江湖中传说的超级高手，武林中人莫不以一睹其真容为
幸事。据称他已隐退江湖数十年，想不到今日又在此出现。
LONG
    );

    set("age", 140);

    set("str", 100);
    set("int", 100);
    set("con", 100);
    set("dex", 100);
    set("per", 100);
    set("kar", 100);

    set_temp("apply/damage", 100);
    set_temp("apply/attack", 100);
    set_temp("apply/dodge", 100);
    set_temp("apply/defense", 100);

        set("max_qi",10000000);
        set("qi",10000000);
    set("max_jing", 10000);
    set("jing", 10000);
    set("max_neili", 10000);
    set("neili", 10000);
    set("max_jingli", 10000);
    set("jingli", 10000);
    set("jiali", 500);

    set_skill("dodge", 200);
    set_skill("unarmed", 200);
    set_skill("parry", 200);
    set("combat_exp",1000000000);
    set("no_clean_up",1);

    setup();
}

void shut_down()
{
    call_out("do_shutdown",1,(int)this_object()->query("shutdown_time")+1);
}

int do_shutdown(int min)
{
    min--;
    if ( !min )
    {
        shout ( HIW
"\n北大侠客行现在重新启动，请稍候再来 ...\n"
        NOR );
        users()->save();
        call_out("imm_shutdown", 3);
        return 1;
    }
    else
    {
//        if((min > 120 && min%30 == 0) || (min > 60 && min%15 == 0) || (min > 30 && min%10 == 0) || (min > 10 && min%1 == 0))
        if ( min<=30 || min%15==0 )
        {
        	shout( HIW"\n北大侠客行再过" + chinese_number(min) + "分钟将重新启动 ...\n"NOR );
        }
        else if ( random(10)==1 )
        {
          shout( HIW"\n北大侠客行再过" + chinese_number(min) + "分钟将重新启动 ...\n"NOR );
        }
        
        call_out("do_shutdown", 60, min);
        return 1;
    }
}

int imm_shutdown()
{
    shutdown(0);
}

void die()
{
    remove_call_out("do_shutdown");
    remove_call_out("imm_shutdown");
    ::die();
}
