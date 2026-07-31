// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// xu.c 徐达

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("徐达", ({ "xu da","xu","da" }) );
	set("title", "明教洪水旗弟子");
        
	set("gender", "男性");
	set("age",36);
	set("long", "他是后来明朝的开国大功臣。\n");
       	set("str", 24);
	set("int", 27);
	set("con", 23);
	set("dex", 21);
        set("per", 20);
	set("max_qi",600);
	set("max_jing",400);
	set("neili",400);
	set("max_neili",400);
	set("jiali",20);
	set("eff_jingli",200);        
	set("shen_type",1);
	set("combat_exp", 180000);
        set("level", 8);

        set_skill("parry",60);
        set_skill("blade",60);
        set_skill("qingfu-shenfa",60);
        set_skill("dodge", 60);
        set_skill("force",60);
        set_skill("lieyan-dao",60);
        set_skill("shenghuo-shengong",60);
        
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","qingfu-shenfa");
        map_skill("parry","lieyan-dao");
        map_skill("blade","lieyan-dao");
        
        create_family("明教", 38, "弟子");

	setup();
        carry_object("/clone/weapon/blade")->wield();	
	carry_object("/d/mingjiao/obj/black-cloth")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say 呵呵，我武功低微，可不敢收徒啊。");
        command("say 这位"+RANK_D->query_respect(ob)+"还是请回吧。");
        return;
}
