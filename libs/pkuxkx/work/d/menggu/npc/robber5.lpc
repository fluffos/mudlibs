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
        create_family("桃花岛",3,"弟子");
        set_skill("force", 80); 
        set_skill("throwing", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("yuxiao-jian", 300);
        set_skill("fuxue-shou", 300); 
        set_skill("tanzhi-shengong", 300);  
        set_skill("finger", 300); 
        set_skill("hand",300);
        set_skill("music",300);
        set_skill("dodge", 300);
        set_skill("cuff", 300);
        set_skill("sword", 300);
        set_skill("parry", 300);
        set_skill("force", 300);
        set_skill("luoying-shenfa", 300);
        set_skill("bihai-shengong", 300);
        map_skill("force","bihai-shengong");
        map_skill("sword","yuxiao-jian");
        map_skill("hand", "fuxue-shou");  
        map_skill("dodge","luoying-shenfa");
        map_skill("parry","yuxiao-jian");
        map_skill("finger", "tanzhi-shengong");
        prepare_skill("finger", "tanzhi-shengong");
        prepare_skill("hand", "fuxue-shou");
	      set("zuoyou-hubo",1);
	      set("jiali",300);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );

     
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        
}
