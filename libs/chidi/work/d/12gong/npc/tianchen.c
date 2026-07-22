//黃金第七宮守護者
//死亡隨機掉靈魂寶石
inherit BHNPC;
#include "star.h"
 
void create()
{
        set_name("童虎", ({"tong hu", "tian chen"}));
        set("long", "传说中在庐山五老峰静坐0243年的中国老人鵟n");
        set("gender","男性");
        set("title", "【龙圣】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",250);
        set("int",35);
        set("no_suck",1);
        set("dex",550000);
        set("combat_exp",1850000000);
        set("chat_chance",50);
        set("chat_msg", ({
                "童虎说道：只有中国才有最好的功夫。\n",
        }));
        set_skill("dodge", 2005380);
        set("attitude", "peaceful");
        set_skill("force", 2005380);
        set_skill("parry", 2005380);
        set_skill("unarmed", 2005380);
        set_skill("staff", 2005380);
        set_skill("lunhui-zhang",2005380);
        set_skill("jienan-zhi",2005380);
        set_skill("lotusmove",2005380);
        set_skill("spells",2005380);
        set_skill("buddhism", 2005380);
        map_skill("staff","lunhui-zhnag");
        map_skill("unarmed","jienan-zhi");
        map_skill("spells","buddhism");
        set_skill("piaomiao-shenfa",2005200);
        set_skill("taixuan-gong",2005200);
        map_skill("force","taixuan-gong");
        map_skill("dodge","piaomiao-shenfa");
        set("max_jingli", 5500000);
        set("jingli", 2100000000);
        set("max_neili", 5500000);
        set("neili", 2100000000);
        set("max_qi", 1100000000);
        set("max_jing", 1100000000);
        set("jiali",2000000);
        set_temp("apply/defense1", 70);
        setup();
        carry_object(__DIR__"obj/tc_cloth")->wear();
        carry_object("/d/obj/weapon/staff/budd_staff")->wield();
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

     switch(random(5))
     {        
        case 0:
        {
        message_vision(HIC"$N大喊一声『庐山升龙霸』一条居龙自九天而起，直飞$n！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"$N被巨龙在空中顶得翻了几十个跟头！\n"NOR,me);
              me->receive_wound("qi", 2*query("max_neili")/5);
              me->receive_wound("jing", 2*query("max_jingli")/10);
                }
        else        message_vision(HIG"$N身型急转，不知道绕了多少圈才夺过巨龙的攻击！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N高喊一声：『庐山亢龙霸』，一条恶龙自溅底而出，尾巴向$n扫去！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(GRN"$N被恶龙的尾巴甩了个正着，$N顿时眼冒金星！\n"NOR,me);
              me->receive_wound("qi", 2*query("max_neili")/5);
              me->receive_wound("jing", 2*query("max_jingli")/10);
                }
        else
        message_vision(HIY"$N用尽全身力气，飞升而气，恶龙的尾巴正从$N的脚底板扫过！\n"NOR,me);
        } 
        break;

        case 2:
        {

        message_vision(HIR"$N高喊一声：『庐山百龙霸』，无数只巨龙向$n冲过来！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIR"$N如一个球一样，被无数只巨龙在空中戏弄着！\n"NOR,me);
              me->receive_wound("qi", 3*query("max_neili")/5);
              me->receive_wound("jing", 3*query("max_jingli")/10);
                }
        else
        message_vision(HIR"$N看准了巨龙之间的空隙，左转右转，才勉强离难！\n"NOR,me,ob);
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
        killer=new("/d/12gong/npc/tianxie"); 
        killer->move("/d/12gong/tianxie"); 
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第七宫：天秤宫!\n"NOR,users());       
        ob->add("12gong/number",1);
       ::die();
}
