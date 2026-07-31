inherit NPC;

void create()
{
	set_name("猿长老", ({ "zhanglao","yuan",}));
	set("age", 76);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("str", 34);
	set("dex", 36);
       set("title","修真");
	set("combat_exp", 300000);
	set_skill("unarmed", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("sword", 140);
	set_skill("force", 140);
	set_skill("literate",140);

    set("chat_chance", 15);
	set("chat_msg", ({
		"落雁那个老家伙怎么还不过来!\n",
		"猿长老看了看你,微笑地指了指书房.\n",
	}));
        set("shen_type",1);
	set("inquiry", ([
		"剑" : "无双神剑,不过......你是雁荡一派的么？",
		"name" : "我就是猿长老,落雁老儿是我的好死党,hehe!",
		]) );	
	setup();
      add_money("gold",2);
carry_object("/clone/misc/cloth")->wear();
}
