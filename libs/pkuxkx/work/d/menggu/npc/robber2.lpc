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
        create_family("少林派",37,"弟子");
        
        set_skill("riyue-bian", 300);
        set_skill("luohan-quan", 300);  
        set_skill("cuff", 300); 
        set_skill("buddhism",300);
        set_skill("dodge", 300);
        set_skill("whip", 300);
        set_skill("parry", 300);
        set_skill("force", 300);
        set_skill("shaolin-shenfa", 300);
        set_skill("hunyuan-yiqi", 300);
        map_skill("force","hunyuan-yiqi");
        map_skill("whip","riyue-bian");
        map_skill("cuff", "luohan-quan");  
        map_skill("dodge","shaolin-shenfa");
        map_skill("parry","riyue-bian");
        prepare_skill("cuff", "luohan-quan");
	      set("zuoyou-hubo",1);
	      set("jiali",300);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );

     
        setup();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        
}
