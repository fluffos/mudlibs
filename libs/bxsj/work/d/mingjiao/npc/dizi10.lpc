// dizi10.c 门主
#include <ansi.h>
inherit NPC;
void create()
{
        string weapon;
        set_name("门主", ({"men zhu","men", "zhu"}));
        set("long","这是一位杨逍属下天地风雷四门之一的门主。\n");
        set("gender", random(2)?"女性":"男性");
        set("attitude", "peaceful");
        set("age", 25+random(20));
        set("str", 23);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1400);
        set("max_neili", 1400);
        set("jiaji", 20);
        set("combat_exp", 120000);
        set_skill("force", 65);
        set_skill("shenghuo-shengong", 65);
        set_skill("dodge", 65);
        set_skill("piaoyi-shenfa", 65);
        set_skill("cuff", 65);
        set_skill("lieyan-dao", 65);
        set_skill("liehuo-jian", 65);
        set_skill("parry", 65);
        set_skill("blade", 65);
        set_skill("taizu-quan",70);
        map_skill("parry","taizu-quan");
        map_skill("cuff","taizu-quan");
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("blade", "lieyan-dao");
        map_skill("sword", "liehuo-jian");
        prepare_skill("cuff","taizu-quan");
        setup();
        create_family("明教",38,"弟子");
        weapon = random(2)?BINGQI_D("changjian"):BINGQI_D("blade");
        if(random(2)==1) carry_object(weapon)->wield();
        carry_object("/d/mingjiao/obj/red-cloth")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say 呵呵，我武功低微，可不敢收徒啊。");
        return;
}
