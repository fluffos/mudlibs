// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("波士顿", ({"boston", "shuang yu"}));
        set("long", "传说中的海王波士顿，守护着双鱼座.\n");
        set("gender","男性");
        set("title", "【海王】");
        set("no_get",1);
        set("age",37);
        set("con",60);
        set("per",32);
        set("str",80);
        set("int",80);
        set("combat_exp",1000000);
        set("daoxing",3500000);
        set("chat_chance",20);
        set("chat_msg", ({
                "波士顿说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 280);
        set("cant_be_smashed",1);
        set("attitude", "friendly");
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("unarmed", 280);
        set_skill("sword", 280);
        set_skill("westsword",280);
        set_skill("boxing",280);
        set_skill("balei",280);
        set_skill("spells",280);
        set_skill("shuangyu", 280);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shuangyu");
        map_skill("dodge","balei");
        set("max_neili", 4000);
        set("force", 8000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",80);
        set("force_factor", 50);
        set("max_qi", 27000);
        set("max_jing", 27000);
        setup();
        carry_object(__DIR__"obj/sy_cloth")->wear();
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
//        object rose;
        object me=query_temp("my_killer");

        if( ! me ) return ;
  
    if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(7))
     {        
        case 0:
        {
        message_vision(HIY"$N一阵呼啸，万海之水随之翻腾，把$n淹没！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"$N被四海之水撞击的体无完肤。\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        message_vision(HIW"$N顺着水势，在激流中随波逐流。\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N念了一声：#$%^%!，变成一只双头怪鱼！\n",ob);

        if(random(2)==0)
                {
              message_vision(HIM"怪鱼张开大嘴，对着$N一阵狂撕！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIG"$N一个急转，夺开这夺命一击！\n"NOR,me);
         }
        break;

        case 2:
        {
        message_vision(HIC"$N高喊：海王之星，万物之本，一阵陨石如雨电般对$n铺去！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N根本就无法躲避，到处都是陨石，根本没有躲避的空间！\n"NOR,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
              me->start_busy(1);
                }
        else
        message_vision(HIG"$N左避右闪，好不容易才躲开$n的攻击。\n"NOR,me,ob);
         }
        break;

        case 3:
        {
    //    rose=new("/d/12gong/npc/obj/rose.c");
        message_vision(HIC"$N嘴里衔着一只红玫瑰，只见$N嘴唇微动，红玫瑰如离弦的箭刺向$n！\n"NOR,ob,me);
  //      rose=move(environment(this_object()));
        if( ! me ) return ;
         if(random(2)==0)
                {
              message_vision(HIM"$N被红玫瑰的毒刺刺伤了身体！\n"NOR,ob,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
      //        rose=move(environment());
                }
        else
        
        message_vision(HIG"$N看准红玫瑰飞来的方向，顺势接住了红玫瑰！\n"NOR,me);
//        rose=move(me);

         }
        break;

  }
        if( random(3) == 1 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");
        if( ! ob ) return ;
        if((ob&&ob->query("12gong/baoping")=="done") && (ob&&ob->query("12gong/shuangyu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "终于闯完了黄金十二宫！\n"NOR,users());
        ob->set("12gong/shuangyu","done");
        ob->add("12gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"你赢得了20000经验");
        }
       ::die();
}
