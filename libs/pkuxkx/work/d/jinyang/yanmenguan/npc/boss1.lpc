//boss1 ,zine

#include <ansi.h>
inherit NPC;
#include "boss.h"
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
        set("title",color1+"带头大哥副手"+NOR);
        set("long","这是一位策划狙击行动的带头大哥副手。\n");
        set("gender", "男性" );
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1); 
       	set("max_qi", 1000000);
        set("eff_qi", 1000000);
        set("qi", 1000000);
        set("max_jing", 500000);
        set("jing", 500000);
        set("neili", 400000);
        set("max_neili", 200000);
        set("jingli",400000);
        set("max_jingli",200000);
        set("jiali", random(100));
        set("combat_exp", 800000);

        set_skill("force", 380); 
        set_skill("unarmed", 380);
        set_skill("dodge", 380);
        set_skill("parry", 380);
        set_skill("finger",500);
        set_skill("tianshan-zhang", 300);
        set_skill("strike",300);
        set_skill("xingxiu-duzhang",300);
        set_skill("staff", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("zhaixinggong", 300);
        set_skill("poison",500);
        set_skill("force", 300);
        set_skill("hand",500);
        set_skill("zhaixing-shou",500);
        set_skill("huagong-dafa", 300);
        set_skill("canhe-zhi",300);
        set_skill("literate",500);
        set_skill("shenyuan-gong",500);
        map_skill("force","huagong-dafa");
        map_skill("finger","canhe-zhi");
        map_skill("staff","tianshan-zhang");
        map_skill("dodge","zhaixinggong");
        map_skill("parry","tianshan-zhang");
        map_skill("strike","xingxiu-duzhang");
        map_skill("hand","zhaixing-shou");
	    prepare_skill("strike", "xingxiu-duzhang");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );

        set("boss",1);
        set("special_skill/chainless", 1);
        set("family/family_name","星宿派");
        setup();
        carry_object("/d/xingxiu/obj/bingpozhang")->wield();
        carry_object("/clone/armor/tiejia")->wear();
        
        call_out("dest",900);
        call_out("kill_target",2);
}
int exer()
{
    object *enemy,target,weapon,obj;
    if (!living(this_object()))
    return 1;
        map_skill("force","huagong-dafa");
        map_skill("finger","canhe-zhi");
        map_skill("staff","tianshan-zhang");
        map_skill("dodge","zhaixinggong");
        map_skill("parry","tianshan-zhang");
        map_skill("strike","xingxiu-duzhang");
        map_skill("hand","zhaixing-shou");
	    prepare_skill("strike", "xingxiu-duzhang");
    command("exert powerup");
    command("exert recover");
    if (random(100)>79)
    {
        command("special chainless");
    }
    if (this_object()->is_busy())
    	return 1;
    enemy = query_enemy();
    target = enemy[random(sizeof(enemy))];
	weapon = this_object()->query_temp("weapon");
    weapon->set("no_get",1);
	if (!weapon)
    {
        carry_object("/d/xingxiu/npc/obj/bingpozhang")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
		weapon->set("no_drop_to_room",1);
    }
	switch( random(8) )
        {
            case 0:
            command("wield all");
            command("perform staff.huose " +target->query("id"));
            break;
            case 1:
            command("wield all");
            command("perform staff.feizhi " +target->query("id"));
            break;
            case 2:
            command("wield all");
            command("perform staff.handu " +target->query("id"));
            break;
            case 3:
            command("unwield all");
            command("prepare none");
            command("enable strike xingxiu-duzhang");
            command("prepare strike");
            command("perform strike.chuanxin " +target->query("id"));
            command("wield all");
            break;  
            case 4:
            command("unwield all");
            command("prepare none");
            command("enable strike xingxiu-duzhang");
            command("prepare strike");
            command("perform strike.chousui " +target->query("id"));
            command("wield all");
            break;  
            case 5:
            command("unwield all");
            command("prepare none");
            command("enable finger canhe-zhi");
            command("prepare finger");
            command("perform finger.canshang");
            command("wield all");
            break;
            case 6:
            command("unwield all");
            command("prepare none");
            command("enable finger canhe-zhi");
            command("prepare finger");
            command("perform finger.dianxue " +target->query("id"));
            command("wield all");
            break;
            case 7:
            switch(random(4))
            {
                case 0:
                obj=new("/d/xingxiu/npc/obj/chuanxinding");
                break;
                case 1:
                obj=new("/d/xingxiu/npc/obj/shuoxindan");
                break;
                case 2:
                obj=new("/d/xingxiu/npc/obj/jileci");
                break;
                case 3:
                obj=new("/d/xingxiu/npc/obj/wuxingfen");
                break;
            }
            obj->move(this_object());
            command("unwield all");
            command("prepare none");
            command("enable hand zhaixing-shou");
            command("prepare hand");
            command("perform hand.tan " +target->query("id"));
            command("wield all");
            break;
        }
}
