#include <ansi.h>
inherit NPC;
void create()
{
	set_name(RED"土匪头"NOR, ({
		"tufei tou",      
		"tufei",
		"tou",
	}));
	set("long",
		"他是土匪头.\n"
	);
	set("gender", "男性");
	set("attitude", "friendly");
	set("age", 35);
      set("shen_type",-1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 50000);

	set_skill("force", 100);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 100);
        set_skill("liuhe-dao",80);
	map_skill("parry", "liuhe-dao");
	map_skill("blade", "liuhe-dao");
	setup();

        carry_object("/d/city/obj/gangdao")->wield();
//        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
      if(interactive(this_player()))
{
        command("say 小妞,你就别逞强了,乖乖的听大爷的话吧.\n");
        command("kiss cungu");
        command("kill cungu");
}
//        command("kill cungu");
//        call_out("kill_ob", 0, this_player()); 
//        COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));		  
	return 0;
}


