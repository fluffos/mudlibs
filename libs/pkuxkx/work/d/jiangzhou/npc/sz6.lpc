// robber for dart
//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include "sz.h"
int exer();
void create()
{ 
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	    string color1=color[random(sizeof(color))];
        name=NAME_D->create_female_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title",color1+"鄱阳水贼"+NOR);
        set("long","这是一位鄱阳水贼。\n");
        set("gender", "女性" );
        set("age", random(30)+14);
        set("bonus",1);
        set("vendetta/authority", 1);
        set("no_use/qiankun-danuoyi",1);
        set("no_use/iron-cloth",1);       
        set("feilong",1); 
	set("busy",1);
        set("max_qi", 2000);
        set("eff_qi", 2000);
        set("qi", 2000);
        set("max_jing", 900);
        set("jing", 900);
        set("neili", 1500);
        set("max_neili", 1500);
          set("jiali", 100);
	//set("shen",-100);
        //set("shen_type", -10);
        set("combat_exp", 500000);

        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("huashan-jianfa", 300);
        set_skill("yunushijiu-jian", 300);
        set_skill("strike",300);
        set_skill("hunyuan-zhang",300);
        set_skill("cuff",300);
        set_skill("dodge", 300);
        set_skill("sword", 300);
        set_skill("parry", 300);
        set_skill("force",300);
        set_skill("huashan-neigong",300);
        set_skill("zixia-shengong",300);
        set_skill("huashan-shenfa",300);
        set("huashan_newskills/qizong",1);
        map_skill("sword","yunushijiu-jian");
        map_skill("dodge","huashan-shenfa");
        map_skill("parry","huashan-jinfa");
        map_skill("strike","hunyuan-zhang");
        map_skill("force","zixia-shengong");
        prepare_skill("strike", "hunyuan-zhang");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
        
        create_family("华山派" , 19, "弟子");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        call_out("start_attact",5,this_object());
        call_out("dest",900);
}
int exer()
{
    object *enemy,target,weapon;
    if (!living(this_object()))
    return 1;
    command("exert powerup");
    command("exert recover");
    if (this_object()->is_busy())
    	return 1;
    if (this_object()->query("no_pfm"))
    {
        return 1;
    }
    enemy = query_enemy();
    if (sizeof(enemy))
    {
        target = enemy[random(sizeof(enemy))];
    }
	weapon = this_object()->query_temp("weapon");
    if (weapon)
    {
        weapon->set("no_get",1);
    }
	if (!weapon)
		carry_object("/clone/weapon/changjian")->wield();
	weapon=this_object()->query_temp("weapon");
	weapon->set("no_get",1);
	weapon->set("no_drop_to_room",1);
    switch( random(2) )
{
            case 0:
            if (target&&random(100)>95)
            command("perform sword.sanqingfeng " + target->query("id"));
             break;
            case 1:
            if (target)
            {
                command("perform huashan-jianfa.jianzhang " +target->query("id"));
            }
             break;
}
}
