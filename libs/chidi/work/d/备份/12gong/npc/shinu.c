//黃金第六宮守護者
//死亡隨機掉祝福寶石
inherit BHNPC;
#include "star.h"
 
void create()
{
        set_name("赫尔梅斯", ({"homeis", "shi nu"}));
        set("long", "传说中的传令神赫尔梅斯，守护室女座。\n");
        set("gender","男性");
        set("title", "【传令神】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("jh_dj/dj",60);
        set("int",35);
        set("no_suck",1);
        set("dex",5000);
        set("combat_exp",180000000);
        set("chat_chance",50);
        set("chat_msg", ({
                "赫尔梅斯说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 5500);
        set("attitude", "peaceful");
        set_skill("force", 5500);
        set_skill("parry", 5500);
        set_skill("unarmed", 5500);
        set_skill("sword", 5500);
        set_skill("westsword",5500);
        set_skill("boxing",5500);
        set_skill("balei",5500);
        set_skill("spells",5500);
        set_skill("shinu", 5500);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shinu");
        set_skill("piaomiao-shenfa",5500);
        set_skill("taixuan-gong",5500);
        map_skill("force","taixuan-gong");
        map_skill("dodge","piaomiao-shenfa");
        set("max_jingli", 60000000);
        set("jingli", 60000000);
        set("max_neili", 60000000);
        set("neili", 60000000);
        set("max_qi", 60000000);
        set("max_jing", 60000000);
        set("jiali",3000);
        set_temp("apply/defense1", 40);

        setup();
        carry_object(__DIR__"obj/su_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
void init()
{
        add_action("do_kill","kill");
        add_action("do_none","perform");        
        add_action("do_none","conjure");
        add_action("do_none","cast");
        add_action("do_none","halt");
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
        message_vision(HIG"$N手中令旗一挥，一阵狂风呼啸而起！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIG"$N被风吹的跪在地上，毫无半点力量！\n"NOR,me);
              me->receive_wound("qi", query("max_neili")/5);
              me->receive_wound("jing", query("max_jingli")/10);
                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一挥手中令旗，一道闪电劈向$n！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N被闪电劈了个正着，直电的头皮发麻！\n"NOR,me);
              me->receive_wound("qi", query("max_neili")/5);
              me->receive_wound("jing", query("max_jingli")/10);
                }
        else
        message_vision(HIC"$N早就看清了闪电的方向，轻轻一闪，躲开了。\n"NOR,me);
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
        killer=new("/d/12gong/npc/tianchen"); 
        killer->move("/d/12gong/tianchen"); 
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第六宫：室女座，向黄金战士进军。\n"NOR,users());
        ob->add("12gong/number",1);       
       ::die();
}
