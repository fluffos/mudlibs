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
        set("bonus",2);
        set("zuoyou-hubo", 1);
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("pursuer", 1);
        set("bellicosity", 100000);
        set("max_qi", 3000);
        set("eff_qi", 3000);
        set("qi", 3000);
        set("max_jing", 3000);
        set("jing", 3000);
        set("neili", 2500);
        set("max_neili",2500);
        set("jiali", random(200));        
        set("busy",1);
	      //set("shen",-100);
        //set("shen_type", -10);
        set("combat_exp", 900000);

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
        call_out("start_attact",5,this_object());
        call_out("dest",900);
}
int exer()
{
    object *enemy,target,weapon;
    object obj; 
    
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
//    command("perform sword.tonggui" + target->query("id"));
	weapon = this_object()->query_temp("weapon");
    if (weapon)
    {
        weapon->set("no_get",1);
    }
	if (!weapon)
		carry_object("/clone/weapon/changbian")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
		weapon->set("no_drop_to_room",1);
        command("perform whip.fumoquan");
            
}


