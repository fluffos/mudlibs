// File         : wokou.c
// Created By   : zhx@pkuxkx, 2009-08-29

#include <ansi.h>
#include "wield.h"
inherit FAMILY_NPC;
#include "random_name3.h"
void die();
void full_me();

string* family_list = ({  //门派列表
        "shaolin", "wudang", "emei", "gaibang", "tianlong", 
        "tiandihui", "huashan1", "quanzhen", "xingxiu", "baituo", 
        "shenlongjiao", "riyuejiao","dalunsi", "taohua", "gumu", 
        "lingjiu", "murong", "mingjiao" , "chaoting","xiake",
});
int die();
void create()
{
        set_name(get_rndname(), ({get_rndid(), }));
        set("job_title","倭寇");
        set("nickname",HIC"死猪"NOR);
        set("gender", "男性" );
        set("chat_chance_combat", 100);
        family_skill(this_object(), family_list[random(19)], 800+random(100), 1);
        set("max_qi",  15000);
        set("eff_qi",  15000);
        set("qi",      15000);
        set("max_jing",15000);
        set("eff_jing",15000);
        set("jing",    15000);
        set("max_jingli",15000);
        set("jingli",    15000);
        set("max_neili", 15000);
        set("neili",     15000);
      //  set("stage",1);
        
       
        // set("shen_type", -1);
        set("attitude", "aggressive");

        set_temp("apply/damage", 400);
        set_temp("apply/defense",800);
        set("jiali",500);
        set("combat_exp",80000000+random(20000000));
        setup();
        carry_object("/clone/armor/bianfuxuejia")->wear();
        wield_weapon();
}

void unconcious()
{        
        object ob = this_object();
        if(ob->query("qi")>=0 && random(2)==1)
                return;
        die();
}

int die(object me)
{
          int xiayi;
          message_vision(HIC"$N说道：“天皇...”，话没说完，两眼翻白，腿儿蹬了几下，脑袋一歪，死了。\n",this_object());
          ::die();
          return 1;       
          
}


void init()
{
        add_action("do_none","hit");
        add_action("do_none","fight");
        add_action("full_me","kill");
        add_action("do_none","hitall");
    //    add_action("do_none","killall"); 
        add_action("do_none","halt");         
        ::init();
}




int do_none()
{
        return 1;
}

void full_me()
{
        object me = this_object();
        me->command("sneer");
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("neili",2*me->query("max_neili"));
        me->set("jingli",2*me->query("max_jingli"));
        me->clear_condition();
        return;
}
