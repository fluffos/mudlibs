inherit NPC;
void create()
{
	int i = 30+random(20);
        set_name("柳树精", ({"liushu jing", "jing"}));
        set("long", "一个模样极象树桩子的妖怪，手里提着一截树干。\n");
        set_level(i);
        set("age", 30);
        set("attitude", "aggressive");
        set("gender", "男性");
	set("class", "yaomo");
        set("per", 10);
	set("looking", "浑身上下就是木头，那里有什么容貌。");
	set_temp("apply/armor", 30);
	set("bellicosity", 2000);

	set("eff_dx", -20000);
        set("nkgain", 200);

        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed",i*10);
        set_skill("force",i*10);
        set_skill("spells",i*10);
        set_skill("dodge",i*10);
	set_skill("parry",i*10);
	set_skill("staff",i*10);
        setup();
	carry_object("/d/obj/weapon/staff/shugan")->wield();
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
	object stone;
	
	this_object()->add("time", 1);
	if( (int)this_object()->query("time") >= 15 ) {
        message("vision",name() + "一个纵身，跳回到树上。\n", environment(),this_object() );
        destruct(this_object());

	}
	return;
}