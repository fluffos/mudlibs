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
        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("huashan-jianfa", 300);
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
        map_skill("sword","huashan-jianfa");
        map_skill("dodge","huashan-shenfa");
        map_skill("parry","huashan-jinfa");
        map_skill("strike","hunyuan-zhang");
        map_skill("force","zixia-shengong");
        prepare_skill("strike", "hunyuan-zhang");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
     
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        
}
