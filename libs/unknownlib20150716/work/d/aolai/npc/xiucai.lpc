inherit NPC;

void create()
{
        set_name("蓝图郁", ({"lan tuyu","lan","xiansheng"}));
        set_level(5);        
        set("gender", "男性");
        set("age", 55);
        set("title", "教书先生");
	set("long", "蓝图郁原是大唐一个秀才，因屡试不中，便漂流海外到傲来国。\n");
        set("attitude", "friendly");
        set_skill("literate",50);
        set_skill("sword", 40);
        set_skill("force",30); 
        set_skill("haoran-zhengqi",40);        
        set_skill("haoran-jian", 40);
        set_skill("dodge", 20);
        set_skill("parry", 40);
        map_skill("sword","haoran-jian");
        map_skill("parry","haoran-jian");
        map_skill("force","haoran-zhengqi");    
        set("inquiry", ([
                "读书识字": "对了，你是来对地方了！\n",
        ]) );
        set("skill_public",1);
        setup();
        carry_object("/d/obj/cloth/changpao")->wear();
        carry_object("/d/gao/obj/ruler")->wield();
}

int recognize_apprentice(object ob)
{
	if( ob->query("class") )
		return notify_fail("蓝图郁笑道：这位"+RANK_D->query_respect(ob)+"莫要消遣老夫了。\n");
        return 1;
}


