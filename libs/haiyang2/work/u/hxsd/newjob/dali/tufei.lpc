#include <ansi.h>
inherit NPC;
void create()
{
      string weapon;
        set_name("土匪", ({ "tufei"}));
        set("gender", "男性");
        set("age", random(10) + 25);
        set("no_quest", 1);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "山西劫匪。\n");
        set("combat_exp", 1080000 + random(4000000)); 
       
        set("no_quest", 1);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 350);
        set_skill("parry", 50);
        set_skill("fanliangyi-dao", 100);
        set_skill("blade", 50);
	 set_skill("zixia-shengong",100);
        map_skill("blade","fanliangyi-dao");
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        weapon = "/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

