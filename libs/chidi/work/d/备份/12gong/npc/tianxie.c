//黃金第八宮守護者
//死亡隨機掉靈魂寶石
inherit BHNPC;
#include "star.h"
 
void create()
{
        set_name("哈迪斯", ({"hadis", "tian xie"}));
        set("long", "传说中的冥王哈迪斯 ，守护着天蝎座.\n");
        set("gender","男性");
        set("title", "【冥王】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",250);
        set("int",35);
                 set("jh_dj/dj",80);
        set("dex",3500);
        set("no_suck",1);
        set("combat_exp",1900000000);
        set("chat_chance",50);
        
        set_skill("dodge", 6000);
        set("attitude", "peaceful");
        set_skill("force", 6000);
        set_skill("parry", 6000);
        set_skill("unarmed", 6000);
        set_skill("sword", 6000);
        set_skill("westsword",6000);
        set_skill("boxing",6000);
        set_skill("balei",6000);
        set_skill("spells",6000);
        set_skill("tianxie", 6000);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","tianxie");
        set_skill("piaomiao-shenfa",6000);
        set_skill("taixuan-gong",6000);
        map_skill("force","taixuan-gong");
        map_skill("dodge","piaomiao-shenfa");
        set("max_qi", 80000000);
   set("max_jing", 80000000);
   set("max_jingli", 80000000);   
   set("max_neili", 80000000);
   set("jingli", 80000000);   
   set("neili", 80000000);    
   set("jiali", 3500);    
        set_temp("apply/defense1", 60);
        setup();
        carry_object(__DIR__"obj/tx_cloth")->wear();
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
       // if( pointerp(ob->query_team()) && ob->is_team_leader())//必须组队并且是队长
        {
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
           }else{
        message_vision("$N冷笑一声：只有队伍的队长才由资格杀我，你想耍什么花样？\n",me);
        return 1;
}
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
     if(ob)
         destruct(ob);
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
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
        message_vision(YEL"$N一声狂笑，巨波排山倒海般向$n冲去。！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(YEL"$N在波涛中摇摆着！\n"NOR,me);
              me->receive_wound("qi", query("max_neili")/5);
              me->receive_wound("jing", query("max_jingli")/10);
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
              me->receive_wound("qi", query("max_neili")/5);
              me->receive_wound("jing", query("max_jingli")/10);
                }
        else
        message_vision(YEL"$N旋转不停，不多一会毒气消失的无影无踪。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N口念咒语：小鬼何在？\n",ob);
        ghost=new("/d/12gong/npc/ghost.c");
        ghost->move(environment());
        ghost->set("combat_exp",ob->query("combat_exp"));
        ghost->set("qi",ob->query("max_qi"));
        ghost->set("max_jingli",ob->query("max_jingli")/10);
        ghost->set("jing",ob->query("max_jing"));
        ghost->set("max_neili",ob->query("max_neili")/5);
        ghost->kill_ob(ob);
        message_vision(HIC"不知从何处串出来几个小鬼向$N杀去！\n"NOR,me);
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
        killer=new("/d/12gong/npc/renma"); 
        killer->move("/d/12gong/renma"); 
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第八宫：天蝎宫，继续向黄金战士努力！\n"NOR,users());
        ob->add("12gong/number",1);       
       ::die();
}
