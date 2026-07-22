//黃金第二宮守護者
//死亡隨機掉祝福寶石
inherit BHNPC;
#include "star.h"
 
void create()
{
        set_name("阿弗罗迪蒂", ({"afolodina", "jin niu"}));
        set("long", "传说中的爱与美的女神－阿弗罗迪蒂，守护着金牛座\n");
        set("gender","女性");
        set("title", "【美神】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("no_suck",1);
        set("combat_exp",1200000000);
        set("dex",400000);
        set("chat_chance",50);
        
        set_skill("dodge", 2005210);
        set("attitude", "peaceful");
        set_skill("force", 2005210);
        set_skill("parry", 2005210);
        set_skill("unarmed", 2005210);
        set_skill("piaomiao-shenfa",2005200);
        set_skill("taixuan-gong",2005200);
        set_skill("sword", 2005210);
        set_skill("westsword",2005210);
        set_skill("boxing",2005210);
        set_skill("balei",2005210);
        set_skill("spells",2005210);
        set_skill("jinniu", 2005210);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");        
        map_skill("force","taixuan-gong");
        map_skill("dodge","piaomiao-shenfa");
        set("max_jingli", 3000000);
        set("jingli", 2100000000);
        set("max_neili", 3000000);
        set("neili", 2100000000);
        set("max_qi", 600000000);
        set("max_jing", 600000000);
        set("jiali",2000000);
        set_temp("apply/defense1", 30);
        setup();
        carry_object(__DIR__"obj/jn_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
void init()
{
        add_action("do_kill","kill");
        add_action("do_none","perform");        
        add_action("do_none","conjure");
        add_action("do_none","cast");
        add_action("do_none","halt");
        add_action("do_none","teamkill");//
        add_action("do_none","touxi");//
        add_action("do_none","ansuan");//
}
int do_none()
{
        object me = this_object();
        message_vision("$N冷笑一声：我乃$N，你想耍什么花样？\n",me);
        return 1;
} 
int do_kill()
{
        object me = this_object();
        object ob = this_player();
        //if( pointerp(ob->query_team()) && ob->is_team_leader())//必须组队并且是队长
        //{
        set_temp("my_killer",ob);
//copy对方的特殊攻击和防御等属性
         if (ob->query_temp("apply/defense1"))
        me->set_temp("apply/defense1",ob->query_temp("apply/defense1"));
         if (ob->query_temp("apply/attack1"))
        me->set_temp("apply/attack1",ob->query_temp("apply/attack1"));  
         if (ob->query_temp("apply/dodge"))
        me->set_temp("apply/dodge",ob->query_temp("apply/dodge"));  
          if (ob->query_temp("apply/force"))
        me->set_temp("apply/force",ob->query_temp("apply/force"));
        return 0;
        //   }else{
        //message_vision("$N冷笑一声：只有队伍的队长才由资格杀我，你想耍什么花样？\n",me);
        //return 1;
       //}
} 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     if(ob)
         destruct(ob);
     return;
     }                               
//copy对方的特殊攻击和防御等属性
       if (me->query_temp("apply/defense1"))
           ob->set_temp("apply/defense1",me->query_temp("apply/defense1"));
       if (me->query_temp("apply/attack1"))
           ob->set_temp("apply/attack1",me->query_temp("apply/attack1"));  
       if (me->query_temp("apply/dodge"))
           ob->set_temp("apply/attack1",me->query_temp("apply/dodge"));
       if (me->query_temp("apply/force"))
           ob->set_temp("apply/force",me->query_temp("apply/force"));

     switch(random(6))
     {        
        case 0:
        {
        message_vision(YEL"$N挥挥衣袖，黄土向$n卷卷而来！\n",ob,me);


       if(random(3)==0)
                {
              message_vision(YEL"$N被飞来的黄土淹没了双眼！\n"NOR,me);
              me->receive_wound("qi", query("max_neili")/5);
              me->receive_wound("jing", query("max_jingli")/10);
                }
        else
        message_vision(YEL"$N也鼓起嘴巴，把飞来的黄土纷纷吹落在地！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N念念有词，一只斗牛向$n冲来！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(YEL"$N被斗牛的尖角转了个大窟窿！\n"NOR,me);
              me->receive_wound("qi", 2*query("max_neili")/5);
              me->receive_wound("jing", 2*query("max_jingli")/10);
                }
        }
        break;

        case 2:
        {

        message_vision(HIR"$N向$n射出了爱情之箭。\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N不但不躲避，反而迎了上去！\n"NOR,me);
              me->receive_wound("qi", 3*query("max_neili")/5);
              me->receive_wound("jing", 3*query("max_jingli")/10);
                }
        else
        message_vision(HIR"$N看准方向，躲开了$n的爱情之箭！\n"NOR,me,ob);
        }
        break;

  }
        if( random(8) == 5 )

        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{ 
        string *dir,file;
        object equip;
        object killer;
        object me=this_object();
        object ob = query_temp("my_killer");

        if( ob && random(30) < 1 )
        {            
           dir = get_dir("/clone/misc/newitem/item/");
           file = "/clone/misc/newitem/item/"+dir[random(sizeof(dir))];
           equip = new(file);
               if( objectp(equip) )
               {
                 equip->change_ob(me,ob);
                 equip->move(ob);
                 tell_object(all_inventory(environment(me)),
                             BLINK+HIB"只听“哐铛”一声，好象一样东西从"
                             +me->name()+"的尸体中掉了出来···\n"NOR);
                 tell_object(all_inventory(environment(me)),
                             HIW+ob->name()+"看见了稀世珍宝"HIW+equip->name()+HIW+"从"HIW+me->name()+"身上掉下，立刻把它拣了起来！\n" NOR);            
            }
         }

        ob->start_busy(3);
        killer=new("/d/12gong/npc/shuangzi"); 
        killer->move("/d/12gong/shuangzi"); 
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第二宫：金牛宫!\n"NOR,users());     
        ob->add("12gong/number",1);  
       ::die();
}
