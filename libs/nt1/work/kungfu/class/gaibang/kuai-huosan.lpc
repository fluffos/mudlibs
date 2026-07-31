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
	set_name("快活三", ({"kuaihuo san", "kuaihuo", "san"}));
	set("title", "丐帮四袋弟子");
	set("gender", "男性");
	set("age", 25);
	set("long", 
		"他是个长得十分结实的青年乞丐，正笑咪咪的盯着你瞧，不知他为啥这么高兴。\n");

	set("attitude", "heroism");
        set("class", "beggar");
	set("str", 28);
	set("int", 18);
	set("con", 22);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 30);
	set("level", 6);
	set("combat_exp", 58000);
	
	set_skill("force", 55);
        set_skill("huntian-qigong", 55);
        set_skill("unarmed", 60);
        set_skill("changquan", 60);
        set_skill("dodge", 55);
        set_skill("feiyan-zoubi", 55);
        set_skill("hand", 55);
        set_skill("shexing-diaoshou", 55);
        set_skill("strike", 55);
        set_skill("xiaoyaoyou", 55);
        set_skill("parry", 55);
        set_skill("staff", 55);
        set_skill("fengmo-zhang", 55);
        set_skill("blade", 55);
        set_skill("liuhe-dao", 55);
        set_skill("begging", 55);
        set_skill("checking", 55);
        set_skill("literate", 55);
        set_skill("martial-cognize", 40);
	set_skill("stealing", 60); 
	
        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-diaoshou");
        map_skill("blade", "liuhe-dao");
        map_skill("strike", "xiaoyaoyou");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "shexing-diaoshou");
        map_skill("unarmed", "changquan");
        map_skill("dodge", "feiyan-zoubi");
	
	prepare_skill("hand", "shexing-diaoshou");
	
	create_family("丐帮", 20, "弟子");
	setup();

	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;
               
        if (ob->query("gender") != "男性") 
                return;

        if (ob->query("shen") < 0)
        {
                command("say 你身为丐帮弟子，竟然不做好事？");
                return;
        }
        command("nod");
        command("say 我便收你为徒，日后可得行侠仗义，莫损我丐帮名声。");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
}
