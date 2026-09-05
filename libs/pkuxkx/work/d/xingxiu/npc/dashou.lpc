inherit NPC;
void create()
{
	set_name("打手",({"da shou","da","shou"}));
	set("gender","男性");
	set("str",25);
	set("long","他是一个凶悍的人。"
	"看起来很骇人的。\n");
        set("shen_type", -1);
	set("max_qi",300);
	set("combat_exp",10000+random(2000));
	set_skill("unarmed",30);
	set_skill("dodge",30);
	set_skill("parry",30);
	set_skill("force",30);
	create_family("星宿派",5,"弟子");
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
	if((string)this_player()->query("family/family_name")!="星宿派"&&!wizardp(this_player()))
	{
	this_object()->kill_ob(this_player());
	return;
	}
}


	

































		
