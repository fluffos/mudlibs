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
        set("title",color1+"带头大哥"+NOR);
        set("long","这是一位策划狙击行动的带头大哥。\n");
        set("gender", "男性" );
        set("age", random(30)+14);
        set("no_use/qiankun-danuoyi",1);        
        set("no_use/iron-cloth",1); 
       	set("max_qi", 1200000);
        set("eff_qi", 1200000);
        set("qi", 1200000);
        set("max_jing", 600000);
        set("jing", 600000);
        set("neili", 500000);
        set("max_neili", 250000);
        set("jingli",500000);
        set("max_jingli",250000);
        set("jiali", random(200));
        set("combat_exp", 800000);

        set_skill("force", 400);             // 基本内功
        set_skill("huntian-qigong", 380);    // 混天气功
        set_skill("parry",350);
        set_skill("hand",380);
        set_skill("strike", 350);
        set_skill("liuhe-dao", 400);   // 六合刀
        set_skill("blade", 400);   // 基本刀法
        set_skill("xianglong-zhang", 400);   // 降龙十八掌
        set_skill("shexing-shou",430);
        set_skill("dodge", 350);             // 基本躲闪

        set_skill("xiaoyaoyou", 350);        // 逍遥游
        set_skill("staff", 350);             // 基本棍杖
        set_skill("dagou-bang", 350);        // 打狗棒法
        set_skill("checking", 300);          // 道听途说
        set_skill("begging", 250);
          // 道听途说
        set_skill("stealing", 150);
          // 道听途说
        set_skill("hujia-daofa", 150);
        map_skill("blade", "hujia-daofa");
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");

        prepare_skill("strike", "xianglong-zhang");
        
        create_family("丐帮", 7, "帮主");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );
        set("yidao/times",10000);
        set("level",122);
        set("boss",3);
        set("special_skill/chainless", 1);
        set("special_skill/might", 1);
        set("special_skill/agile", 1);
        setup();
        carry_object("/clone/armor/tiejia")->wear();
        carry_object("/kungfu/class/gaibang/yuzhu_zhang")->wield();
        call_out("dest",900);
        call_out("kill_target",2);
}
int exer()
{
    object *enemy,target,weapon,obj;
    object ob=this_object();
    int i;
    if (!living(this_object()))
    return 1;
        map_skill("blade", "hujia-daofa");
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");
        prepare_skill("strike", "xianglong-zhang");
    command("exert powerup");
    command("exert recover");
    if (!ob->query("might"))
    {
        ob->query("might",1);
        command("special might");
    }
    command("special chainless");
    command("special agile");
    if (this_object()->is_busy())
    	return 1;
    enemy = query_enemy();
    target = enemy[random(sizeof(enemy))];
    if (!weapon)
    {
        carry_object("/kungfu/class/gaibang/yuzhu_zhang")->wield();
        weapon=this_object()->query_temp("weapon");
        weapon->set("no_get",1);
		weapon->set("no_drop_to_room",1);
    }
	switch( random(7) )
        {
            case 0:
            command("drop blade");
            command("wield zhang");
            command("enable parry dagou-bang");
            command("perform staff.chan " +target->query("id"));
            break;
            case 1:
            command("drop blade");
            command("wield zhang");
            command("enable parry dagou-bang");
            command("perform staff.chuo " +target->query("id"));
            break;
            case 2:
            command("drop blade");
            command("wield zhang");
            command("enable parry dagou-bang");
            command("perform staff.zhuan " +target->query("id"));
            break;
            case 3:
            command("unwield all");
            command("prepare none");
            command("enable strike xianglong-zhang");
            command("enable parry xianglong-zhang");
            command("prepare strike");
            command("perform strike.xiao");
            break;  
            case 4:
            command("unwield all");
            command("prepare none");
            command("enable strike xianglong-zhang");
            command("enable parry xianglong-zhang");
            command("prepare strike");
            command("perform strike.sanhui " +target->query("id"));
            break;  
            case 5:
            command("drop blade");
            command("wield zhang");
            command("enable parry dagou-bang");
            command("perform staff.tiao " +target->query("id"));
            break;
            case 6:
            obj=new("/clone/weapon/gangdao");
            obj->move(this_object());
            command("unwield all");
            command("wield blade");
            command("enable blade hujia-daofa");
            command("enable parry hujia-daofa");
            command("perform blade.daoying");
            break;
        }
            
}
