inherit SUPER_NPC;

void create()
{
	set_name("夏鹏展", ({"xia pengzhan", "xia"}));
       	set("title", "清风寨强盗头领");
       	set("long","夏鹏展原是长安城中一名捕头，因贼性难改，落草作了强盗。使一路雁歌刀法，手中雁云刀阴狠无比。\n");
       	set_level(35);
	set("gender", "男性");
	set("age", 37);
	set("str", 25);
	set("attitude", "aggressive");
	set_skill("blade",350);
        set_skill("parry",300);
	set_skill("dodge",300);
	set_skill("unarmed",300);
	set_skill("yange-blade",350);
	set_skill("yanxing-steps",300);
	set_skill("force",240);
	set_skill("ningxie-force",200);
	map_skill("force","ningxie-force");
	map_skill("dodge", "yanxing-steps");
	map_skill("blade", "yange-blade");
	map_skill("parry", "yange_blade");
	set("bellicosity", 5000);
       	set("force_factor", 120);
	setup();
	carry_object(0,"blade",random(5))->wield();
	carry_object(0,"armor",random(5))->wear();
	carry_object(0,"cloth",random(5))->wear();
	carry_object(0,"kui",random(5))->wear();
	carry_object(0,"shoes",random(5))->wear();
	carry_object(0,"pifeng",random(5))->wear();
	carry_object(0,"shield",random(5))->wear();
	carry_object(0,"neck",random(5))->wear();
	carry_object(0,"ring",random(5))->wear();
	carry_object(0,"hand",random(5))->wear();
	carry_object(0,"waist",random(5))->wear();
	carry_object(0,"wrists",random(5))->wear();
	add_money("silver", 50);
	powerup(0,1);
}

void die()
{
	object book;
	if( environment() && time()>=environment()->query("last_book")+1800 )
	{
		book = new("/d/obj/book/parry_book");
		environment()->set("last_book",time());
		if( book && book->move(environment()) )
			message_vision("\n$N大叫：好好，这本秘籍便给了你。\n\n",this_object());
	}
	::die();
}		