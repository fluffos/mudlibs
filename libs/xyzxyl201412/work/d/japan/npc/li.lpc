//zhangwuji.c

#include <ansi.h>
inherit NPC;
//#include <renwu.h>

string do_tisheng();
void do_jiangli(object player,int lv,int type);

void create()
{
         set_name("柳生英雄", ({ "liusheng yingxiong", "liusheng", "yingxiong" }));
      set("bh_rank","宗师");
        set("title","扶桑岛神户城");
        set("banghui","扶桑剑门");
	set("gender", "男性");
    set("age", 20);
	set("shen_type",1);
    set("attitude", "friendly");

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

	set("kee",3050);
	set("max_kee",3050);
	set("gin",1500);
	set("max_gin",1500);
	set("force",5000);
	set("max_force",5000);
	set("force_factor",120);

    set("combat_exp", 2900000);
    set("score", 455000);
    
	set_skill("force",300);
	set_skill("unarmed",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("sword",300);
	set_skill("blade",300);



		setup();
   carry_object("/clone/misc/cloth")->wear();
carry_object("/clone/weapon/gangjian")->wield();

		add_money("gold",1);
}
