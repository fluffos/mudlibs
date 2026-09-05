// robber for dart
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
        name=NAME_D->create_female_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title",color1+title1+NOR);
        set("long","这是一位华山派高手。\n");
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
        map_skill("sword","huashan-jianfa");
        map_skill("dodge","huashan-shenfa");
        map_skill("parry","huashan-jianfa");
        map_skill("strike","hunyuan-zhang");
        map_skill("force","zixia-shengong");
        prepare_skill("strike", "hunyuan-zhang");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
        set("inquiry", ([
            "fight" : (: ask_fight :),
			"干架" : (: ask_fight :),
       	]) );
       	
       	create_family("华山派" , 19, "弟子");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
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
    if (this_object()->is_busy() || query_condition("cannt_eq"))
    	return;
    enemy = query_enemy();
    if (sizeof(enemy))
    {
        target = enemy[random(sizeof(enemy))];
    }
	weapon = this_object()->query_temp("weapon");
	if (!weapon) carry_object("/clone/weapon/changjian")->wield();
	weapon=this_object()->query_temp("weapon");
	weapon->set("no_get",1);
	weapon->set("no_drop_to_room",1);
    command("perform sword.jianzhang");
             
}
