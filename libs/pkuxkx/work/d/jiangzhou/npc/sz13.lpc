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
        set("bonus",1);
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1);        
        set("vendetta/authority", 1);
       	set("max_qi", 3000);
        set("eff_qi", 3000);
        set("qi", 3000);
        set("max_jing", 3000);
        set("jing", 3000);
        set("neili", 3000);
        set("max_neili", 2000);
        set("jiali", random(200));
        set("busy",1);
	//set("shen",-100);
        //set("shen_type", -10);
        set("combat_exp", 800000);

          set_skill("force",380);
          set_skill("linji-zhuang",380);
          set_skill("dodge",300);
          set_skill("zhutian", 300);
          set_skill("jinding-mianzhang",300);
          set_skill("shenghuo-lingfa",380);
          set_skill("blade",300);
          set_skill("fuliu-jian",300);
          set_skill("parry",350);
          set_skill("sword",300);
          set_skill("yanxing-dao",300);
          set_skill("finger",300);
          set_skill("tiangang-zhi",300);
          set_skill("strike",300);
          set_skill("hand",300);
          set_skill("jieshou-jiushi",300);
        map_skill("strike", "jinding-mianzhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("parry", "yanxing-dao");
        map_skill("sword", "fuliu-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("hand", "jieshou-jiushi");
        prepare_skill("hand", "jieshou-jiushi");
        
        set("chat_chance_combat", 150);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );

        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        call_out("start_attact",5,this_object());
        call_out("dest",900);
}
int exer()
{
    object *enemy,target,weapon,weapon2;
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
    weapon2= this_object()->query_temp("secondary_weapon");
    if (weapon2)
    {
        weapon2->set("no_get",1);
    }
	if (!weapon)
	        carry_object("/clone/weapon/gangdao")->wield();
    if (!weapon2)
            carry_object("/clone/weapon/changjian")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
        weapon2= this_object()->query_temp("secondary_weapon");
        weapon2->set("no_get",1);
		weapon->set("no_drop_to_room",1);
    switch( random(3) )
        {
            case 0:
            if (target)
            {
                command("unwield all");
                command("wield jian");
                command("perform sword.huifeng " +target->query("id"));
                command("unwield all");
                command("wield blade");
                command("wield jian");
            }
            break;
            case 1:
            if (target)
            {
                command("unwield all");
                command("wield blade");
                command("wield jian");
                command("perform blade.heji " +target->query("id"));
            }
            break;
            case 2:
            if (target)
            {
                command("unwield all");
                command("wield blade");
                command("wield jian");
                command("perform sword.fuliu " + target->query("id"));
            }
            break;  
        }
            
}
