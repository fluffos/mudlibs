//Npc 比古清十郎
//diabio(青云)2003.3.1
#include <ansi.h>
inherit NPC;
int ask_tianxiang();
inherit F_MASTER;
void create()
{
        set_name("魔法测试员", ({ "water test", "magictest" }));
        set("long", "他就是魔法测试员的师傅。 \n");
        set("title", HIW"水系魔法"HIW"测试员"NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude","peaceful");
        set("zhuanbest",1);
        set("str", 90);
        set("dex", 190);
        set("con", 90);
        set("int", 90);
        set("per", 20);
        set("per",23);
        set("tianyu_1",1);
        set("max_qi", 600000);
        set("max_jing", 100000);
        set("max_neili", 5000000);
        set("max_jing",1000);
              set("neili",5000000);
        set("qi",600000);
        set("jing",10000);
        set("jing",10000);
        set("combat_exp", 19000000);
        set_skill("cuff",600);
        set_skill("dodge",600);
        set_skill("unarmed",600);
        set_skill("parry",600);
        set_skill("blade",600);
         set_skill("feitian-yujianliu",600);
         set_skill("shayi-xinfa",800);
        set_skill("force",600);
        set_skill("sword",600);
        set_skill("aikido",600);
        set_skill("spells",600);
        set_skill("wuxing-dun",600);
        set_skill("magic-unarmed",600);
set_skill("magic-water",800);
        set_skill("magic-fire",800);
        set_skill("magic-sword",600);
        set_skill("huoxinliu-jianfa",600);
        set_skill("xuanhualiu-quanfa",600);
        set_skill("literate",350);
        map_skill("cuff", "xuanhualiu-quanfa");
        map_skill("unarmed", "magic-unarmed");
        map_skill("dodge", "wuxing-dun");
        map_skill("sword", "magic-sword");
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
        map_skill("parry", "magic-unarmed");
        map_skill("spells", "magic-water");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.zeroring" :),                                                            
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}
void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        say( "魔法测试员笑着说：我只是在这测试武功！\n");
        command("hehe");

}

void die()
{
        unconcious();
}