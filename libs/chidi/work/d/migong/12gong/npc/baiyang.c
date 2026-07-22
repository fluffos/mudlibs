inherit NPC;
#include "star.h"
void get_date();
 
void create()
{
        set_name("阿雷斯", ({"aleisi", "bai yang"}));
        set("long", "传说中的站神阿雷斯，守护着白羊座\n");
        set("gender","男性");
        set("title", "【战神】");
        set("no_get",1);
        set("age",37);
        set("attitude", "friendly");
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",1000000);
          set("daoxing",2600000);
        set("chat_chance",20);
        set("chat_msg", ({
                "阿雷斯说道：不知何时能再见到雅典娜！\n"   
        }));
         set("max_neili", 22000);
         set("neili", 24000);
         set("max_mana",3000);
         set("mana",6000);
         set("mana_factor",50);
         set("force_factor", 50);
         set("max_qi", 5000);
         set("max_jing", 5000);
          set_skill("dodge", 300);
          set_skill("force", 300);
          set_skill("parry", 300);
          set_skill("unarmed", 300);
          set_skill("sword", 300);
         set_skill("westsword",300);
          set_skill("boxing",300);
         set_skill("baiyang", 300);
        set_skill("baiyang", 300);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","baiyang");

        setup();
        carry_object(__DIR__"obj/by_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
    
     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
      
if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));
if (me->query("str")>25) set("str",me->query("str"));
if (me->query("con")>25) set("con",me->query("con"));
if (me->query("int")>25) set("int",me->query("int"));
if (me->query("dex")>25) set("dex",me->query("dex"));
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIR"$N双手一挥，一团烈火直冲$n而去！\n",ob,me);

        if(random(2))
        
                {
              message_vision(HIR"$N被$n的烈火烧个焦头焦脸！\n"NOR,me,ob);
              me->add("eff_qi",-me->query("eff_qi")/10);
              me->add("eff_jing",-me->query("eff_jing")/10);
                }
        else
        message_vision(HIR"$N轻而易举的躲过了$n的攻击！\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIR"$N吹了起横笛，顿时一只白羊向$n直冲而去！\n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N被白羊撞了个人仰马翻！\n"NOR,me);
              me->add("eff_qi",-2*me->query("eff_qi")/10);
              me->add("eff_jing",-2*me->query("eff_jing")/10);
                }
        else
        message_vision(HIR"$N对着白羊大喝一声：停！白羊乖乖从旁边溜开了！\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N手中长剑变的硕大无比，直插$n后腰\n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N顿时血流如注，顷刻染红了全身！\n"NOR,me);
              me->add("eff_qi",-3*me->query("eff_qi")/10);
              me->add("jing",-3*me->query("eff_jing")/10);
                }
        else
        message_vision(HIR"$N顺着剑的方向，纵身跃起，躲过这致命一击！\n"NOR,me);
        }
        break;

  }
 //       if( present(me,environment()) )  return ;

        if( random(30) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if(ob&&ob->query("12gong/baiyang")!="done")
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了"+environment(ob)->query("short")+"\n"NOR,users());
        ob->set("12gong/baiyang","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"你赢得了20000经验");
       
        }
       ::die();
}
