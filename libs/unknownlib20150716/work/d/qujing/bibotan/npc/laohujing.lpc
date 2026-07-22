inherit NPC;
void create()
{
	int i = 30+random(20);
        set_name("老虎精", ({"laohu jing", "jing"}));
        set("long", "一个凶神恶煞般的老虎精，张着血盆大口，要吃人的样子。\n");
        set("age", 30);
        set("attitude", "aggressive");
	set("bellicosity", 1000);
        set("gender", "男性");
	set("class", "yaomo");
        set("per", 10);
	set_level(i);

	set("eff_dx", -150000);
        set("nkgain", 400);

        set("force_factor", 40);
        set("mana_factor", 10);
        set_skill("unarmed",i*10);
        set_skill("force",i*10);
        set_skill("spells",i*10);
        set_skill("dodge",i*10);
	set_skill("parry",i*10);
	set_skill("blade",i*10);
	set_skill("wuhu-blade",i*10);
	map_skill("blade", "wuhu-blade");
	map_skill("parry", "wuhu-blade");
	set_weight(5000000);
        setup();
	carry_object("/d/obj/weapon/blade/blade")->wield();
}
int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{

        this_object()->add("time", 1);

        if( (int)this_object()->query("time") >= 10 ) {
        message("vision",name() + "一个虎跳，钻入草从中不见了。\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

void die()
{
	object skirt, env;
        if( environment() ) {
        message("sound", "\n老虎精见势不好，忽然扒下自己的皮来，变成一个老虎模样。\n", environment());

		seteuid(getuid());
		if( skirt=new("/d/qujing/bibotan/obj/hupiqun") )
		skirt->move(environment());
		message("vision", "就在这一恍惚之见，真身一个虎跳，钻入草从中不见了。\n",environment());
        }
	env=environment(this_object());
	env->set("done", 1);
        destruct(this_object());
}