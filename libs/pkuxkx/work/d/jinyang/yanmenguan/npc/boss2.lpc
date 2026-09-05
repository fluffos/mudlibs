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

        set_skill("force", 500);
        set_skill("yijin-jing", 500);
        set_skill("yizhi-chan", 500);
        set_skill("dodge", 500);
        set_skill("shaolin-shenfa", 500);
        set_skill("cuff", 500);
        set_skill("jingang-quan",500);
        set_skill("parry",500);
        set_skill("sword", 500);
        set_skill("wuying-jian", 500);
        set_skill("blade", 500);
        set_skill("ranmu-daofa", 500);
        set_skill("whip", 500);
        set_skill("riyue-bian", 500);
        set_skill("buddhism", 500);
        set_skill("finger", 500);
        set_skill("hunyuan-yiqi", 400);
        set_skill("buddhism", 400);
        set_skill("nianhua-zhi", 500);
        set_skill("literate", 300);
        set_skill("strike",500);
        set_skill("banruo-zhang",500);
        map_skill("strike","banruo-zhang");
        map_skill("force","yijin-jing");
        map_skill("dodge","shaolin-shenfa");
        map_skill("cuff","jingang-quan");
        map_skill("parry","jingang-quan");
        map_skill("whip","riyue-bian");
        map_skill("blade","ranmu-daofa");
        map_skill("sword","wuying-jian");
        map_skill("finger","yizhi-chan");
        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: exer() :),
        }) );

        set("boss",2);
        set("special_skill/chainless", 1);
        set("special_skill/might", 1);
        set("family/family_name","少林派");
        setup();
        carry_object("/clone/armor/tiejia")->wear();
        
        call_out("dest",900);
        call_out("kill_target",2);
}
int exer()
{
    object *enemy,target,weapon;
    object ob=this_object();
    int i;
    if (!living(this_object()))
    return 1;
        map_skill("strike","banruo-zhang");
        map_skill("force","yijin-jing");
        map_skill("dodge","shaolin-shenfa");
        map_skill("cuff","jingang-quan");
        map_skill("parry","jingang-quan");
        map_skill("whip","riyue-bian");
        map_skill("blade","ranmu-daofa");
        map_skill("sword","wuying-jian");
        map_skill("finger","yizhi-chan");
        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");
    command("exert powerup");
    command("exert recover");
    if (!ob->query("might"))
    {
        ob->query("might",1);
        command("special might");
    }
    
    if (random(100)>69)
    {
        command("special chainless");
    }
    if (this_object()->is_busy())
    	return 1;
    enemy = query_enemy();
    target = enemy[random(sizeof(enemy))];
	
            command("prepare none");
            command("prepare finger");
            command("prepare strike");
            for (i=0;i<sizeof(enemy);i++)
            {
                command("perform finger.jingmo " +enemy[i]->query("id"));
            }
            
}
