// robber1 for dart
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
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title",color1+"鄱阳水贼"+NOR);
        set("long","这是一位鄱阳水贼。\n");
        set("gender", "男性" );
        set("bonus",1);
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("vendetta/authority", 1);
        set("bellicosity", 100000);
        set("max_qi", 5000);
        set("eff_qi", 5000);
        set("qi", 5000);
        set("max_jing", 900);
        set("jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
	//set("shen",-100);
        //set("shen_type", -10);
        set("combat_exp", 600000);
	    set("busy",1);

        set_skill("force", 250);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("sword", 250);
        set_skill("liumai-shenjian", 250);
        set_skill("literate", 250);
        set_skill("yiyang-zhi", 250);
        set_skill("beiming-shengong", 300);
        set_skill("lingbo-weibu", 250);

        map_skill("finger", "liumai-shenjian");
        map_skill("sword", "liumai-shenjian");
        map_skill("force", "beiming-shengong");
        map_skill("parry", "liumai-shenjian");
        map_skill("dodge", "lingbo-weibu");
        prepare_skill("finger","liumai-shenjian");

	    set("leiting",1);
	    set("jiali",300);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
     
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

    command("perform dodge.luoshen");
    command("perform sword.qifa");
}
