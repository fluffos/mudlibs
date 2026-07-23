inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("尚天一", ({ "shang tianyi","dizi"}));
	set("gender", "男性");
	set("age", 23);
       set("title","雁荡三剑");
       set("nickname","灵心剑");
       set("food",250);
       set("water",250);
    set("chat_chance", 7);
	set("chat_msg", ({
		"唉,她们说就是在这附近丢失的,怎会找不到!\n",
	}));
	set("combat_exp", 10000);
	set("mingwang", 2000);
       set_skill("unarmed", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
        set("shen_type",1);
	set_skill("dodge", 60);
       set_skill("force", 160);


   create_family("雁荡派",2,"弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
