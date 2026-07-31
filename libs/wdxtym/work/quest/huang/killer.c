#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
int do_back(object me);

void create()
{
        string weapon;
        set_name("土匪", ({ "tu fei","fei"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "一个满脸横肉的家伙。\n");
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("taizu-quan", 50);
        set_skill("qingmang-jian", 50); 
        map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        map_skill("parry", "qingmang-jian");
        map_skill("blade", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        set("chat_chance", 30);
	    set("chat_msg", ({
		    (: random_move :)
		}));
		prepare_skill("cuff", "taizu-quan");         
        set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
      weapon = random(2)?"/clone/weapon/gangjian":"/clone/weapon/gangdao";
    //    weapon = random(2)?"/clone/weapon/gangjian":"/clone/weapon/blade";
		setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

#include "killer.h"