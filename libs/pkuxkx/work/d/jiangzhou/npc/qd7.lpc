// robber1 for dart
//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
void exer();
#include "qiangdao.h"

void create()
{ 
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        string* title=({"恶贯满盈","穷凶极恶","罪该万死","冷面屠夫","杀人不眨眼","千刀万剐","杀人放火"});
	    string title1=title[random(sizeof(title))];
	    string color1=color[random(sizeof(color))];
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title",color1+title1+NOR);
        set("long","这是一位丐帮高手。\n");
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
        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("dagou-bang", 80);
        set_skill("unarmed",80);
        set_skill("xianglong-zhang",80);
        set_skill("dodge", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("strike", 80);
        set_skill("force", 80);
        set_skill("huntian-qigong", 80);
        map_skill("force","huntian-qigong");
        map_skill("staff","dagou-bang");
        map_skill("dodge","xiaoyaoyou");
        map_skill("parry","dagou-bang");
        map_skill("parry","xianglong-zhang");
        map_skill("strike", "xianglong-zhang");
        prepare_skill("strike", "xianglong-zhang");
	    set("leiting",1);
	    set("jiali",300);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
        set("inquiry", ([
            "fight" : (: ask_fight :),
			"干架" : (: ask_fight :),
       	]) );
        setup();
        carry_object("/clone/armor/tiejia")->wear();
        call_out("start_attact",5,this_object());
        call_out("dest",900);
        call_out("leave",100);
    call_out("check_status",1);
}
void exer()
{
    object *enemy,target,weapon;
    if (!living(this_object()))
    return;
    command("exert powerup");
    command("exert recover");
    if (this_object()->is_busy())
    	return;
    enemy = query_enemy();
    if (sizeof(enemy))
    {
        target = enemy[random(sizeof(enemy))];
    }
	command("perform strike.xiao");
    
}
