inherit NPC;

void create()
{
	set_name("船夫",({"chuan fu","chuan","fu"}));
	set("gender", "男性" );
	set("age",20);
	set("str",25);
	set("cor", 30);
	set("cps", 30);
	set("int",30);
	set("con",25);
	set("mingwang",-1);
	set("long",
	"豪爽的汉子,满脸的风尘,看来是从远方来的。\n"
	);
	set("combat_exp",3000);
	set("attitude","hero");
	set_skill("literate",20);
	set_skill("parry",20);
	set_skill("dodge",20);
	set_skill("unarmed",30);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",5);
}

