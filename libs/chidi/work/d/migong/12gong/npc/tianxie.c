// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("哈迪斯", ({"hadis", "tian xie"}));
        set("long", "传说中的冥王哈迪斯 ，守护着天蝎座.\n");
        set("gender","男性");
        set("title", "【冥王】");
        set("no_get",1);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "哈迪斯说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("tianxie", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","tianxie");
        map_skill("dodge","balei");
        set("max_neili", 2000);
        set("neili", 24000);
        set("max_neili",22200);
        set("mana",4000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_qi", 19000);
        set("max_jing", 19000);

        setup();
        carry_object(__DIR__"obj/tx_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 
void check()
{
        object *inv;
        object ob=this_object();
        object ghost;
        object me=query_temp("my_killer");
        if( ! me ) return ;
if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                      
     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(6))
     {        
        case 0:
        {
        message_vision(YEL"$N一声狂笑，巨波排山倒海般向$n冲去。！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(YEL"$N在波涛中摇摆着！\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
else        message_vision(YEL"$N如鱼得水，反而加强了进攻。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N吹了一口气，一股绿色的毒气向$n喷去！\n",ob,me);

        if(random(2)==0)

                {
              message_vision(YEL"$N顿时被熏晕了头！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(YEL"$N旋转不停，不多一会毒气消失的无影无踪。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N口念咒语：小鬼何在？\n",ob);
        if( present("ghost",environment(me)))
        return;
        ghost=new(__DIR__"ghost.c");
        ghost->move(environment());
        ghost->set("combat_exp",ob->query("combat_exp")/2);
        ghost->set("max_qi",ob->query("max_qi")/2);
        ghost->set("max_jing",ob->query("max_jing")/2);
        ghost->kill_ob(ob);
        message_vision(HIC"不知从何处串出来几个小鬼向$N杀去！\n"NOR,me);
        }
        break;

  }
        if( random(30) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/tiancheng")=="done") && (ob&&ob->query("12gong/tianxie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第八宫：天蝎宫，继续向黄金战士努力！\n"NOR,users());
        ob->set("12gong/tianxie","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"你赢得了20000经验");

        }
       ::die();
}
