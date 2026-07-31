// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;

#include "fight.h"

void create()
{
	set_name("左全", ({"zuo quan", "zuo", "quan"}));
	set("title", "丐帮七袋弟子");
	set("gender", "男性");
	set("age", 35);
	set("long", 
		"这是位豪爽大方的丐帮七袋弟子，看来是个北地豪杰。\n");
	set("attitude", "peaceful");
        set("class", "beggar"); 
        
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);
	set("max_qi", 12020);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 120);
	set("level", 12);
	set("combat_exp", 2120000);
	
	set_skill("force", 98); 
	set_skill("huntian-qigong", 96); 
	set_skill("hand", 98); 
	set_skill("shexing-diaoshou", 80); 
	set_skill("unarmed", 130); 
	set_skill("changquan", 130); 
	set_skill("dodge", 100); 
        set_skill("feiyan-zoubi", 100);
        set_skill("strike", 102);
	set_skill("xiaoyaoyou", 102); 
        set_skill("staff", 90);
        set_skill("fengmo-zhang", 90);
	set_skill("blade", 100); 
	set_skill("liuhe-dao", 100); 
	set_skill("parry", 101); 
	set_skill("begging", 100); 
	set_skill("stealing", 90); 
	set_skill("checking", 90); 
	set_skill("training", 90);
	
	map_skill("force", "huntian-qigong");
	map_skill("hand", "shexing-diaoshou");
        map_skill("strike", "xiaoyaoyou");
        map_skill("staff", "fengmo-zhang");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	map_skill("dodge", "feiyan-zoubi");
        map_skill("unarmed", "changquan");
	
	prepare_skill("hand", "shexing-diaoshou");
	
	create_family("丐帮", 19, "弟子");
	
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);
        
	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;

        if (ob->query("shen") < 0)
        {
                command("say 你身为丐帮弟子，竟然不做好事？");
                return;
        }
        command("nod");
        command("say 你拜我为师，可要做好吃苦的准备，好好做个丐帮弟子！");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
}
