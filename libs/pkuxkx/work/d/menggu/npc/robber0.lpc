// 蒙古马贼 zine 2012

#include <ansi.h>
inherit NPC;
#include "sz.h"
int exer();
void create()
{ 
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("gender", "男性" );
        set("bonus",1);
        set("age", random(30)+14);       
        set("vendetta/authority", 1);
        set("bellicosity", 100000);
        set("max_qi", 5000);
        set("eff_qi", 5000);
        set("qi", 5000);
        set("max_jing", 900);
        set("jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("combat_exp", 600000);
	    set("busy",1);
		set("is_menggu_mazei",1);
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
}
