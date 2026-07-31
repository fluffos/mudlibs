// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wu.c 吴劲草

inherit NPC;

void create()
{
        set_name("吴劲草", ({ "wu jincao", "wu", "jincao" }));
        set("gender", "男性");
        set("age", 43);                
	set("rank_info/respect","旗主");
	set("title","明教锐金旗副掌旗使");

	set("str", 28);
        set("int", 20);
        set("con", 23);
        set("dex", 22);
        set("per", 20);
        set("combat_exp", 145000);
        set("level", 8);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("eff_jingli", 1000);
	set("jiali",30);
	
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

        create_family("明教", 37, "弟子");               
        setup();
        
        carry_object("/d/mingjiao/obj/green-cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
}

void attempt_apprentice(object ob)
{     
        command("say 由于教事繁忙，我已许久不收弟子了。");
        command("say 这位"+RANK_D->query_respect(ob)+"还是请回吧。");
        return;
}
