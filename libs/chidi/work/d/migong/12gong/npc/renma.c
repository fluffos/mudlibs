// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("宙斯", ({"zhou si", "ren ma"}));
        set("long", "传说中的天帝宙斯，守护着人马座.\n");
        set("gender","男性");
        set("title", "【天帝】");
        set("no_get",1);
        set("age",37);
        set("con",40);
        set("per",30);
        set("str",43);
        set("int",54);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "宙斯说道：不知何时能再见到雅典娜！\n"   
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
        set_skill("renma", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_neili", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",60);
        set("force_factor", 60);
        set("max_qi", 21000);
        set("max_jing", 21000);

        setup();
        carry_object(__DIR__"obj/rm_cloth")->wear();
         carry_object(__DIR__"obj/westsword")->wield();
}
void init()
{
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("$N冷笑一声：我乃$N，你想耍什么花样？\n",me);
        return 1;
} 
void check()
{
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
        message_vision(HIY"$N手指$n，$N的指尖突然串出一道白光！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"白光之后，$N感到身上无比的疼痛！\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(HIW"$N毫无惧色，一个转身，躲开了白光。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一吹口哨，一只半人半马的怪物向$n冲 去！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N被怪物一口咬中了要害！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIG"$N振作精神，仔细一看，原来只是幻象。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIW"$N双手合十，禁闭双眼，$n顿时迷惑起来！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIM"$N感觉浑身的力量正从脚下被吸走！\n"NOR,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
                }
        else
        message_vision(HIG"$N站稳脚跟，好象在和大地搏斗。\n"NOR,me);
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

        if((ob&&ob->query("12gong/tianxie")=="done") && (ob&&ob->query("12gong/renma")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第九宫：人马宫，向黄金战士努力！\n"NOR,users());
        ob->set("12gong/renma","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"你赢得了20000经验");

        }
       ::die();
}
