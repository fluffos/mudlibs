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
        set_skill("huanxi-chan", 200);
        set_skill("literate", 180);
        set_skill("force", 80);
        set_skill("longxiang-boruo", 300);
        set_skill("dodge", 80);
        set_skill("yuxue-dunxing", 300);
        set_skill("hammer", 80);
        set_skill("xiangfu-lun", 300);
        set_skill("hand",80);
        set_skill("dashou-yin",300);
        set_skill("claw",80);
        set_skill("tianwang-zhua",300);
        set_skill("parry", 80 );
        set_skill("poison",100);
        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hammer", "xiangfu-lun");
        map_skill("parry", "xiangfu-lun");
        map_skill("hand","dashou-yin");
        map_skill("claw","tianwang-zhua");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

	    set("leiting",1);
	    set("jiali",300);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
     
        setup();
        carry_object("/d/dalunsi/npc/obj/gold-falun")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        
}
