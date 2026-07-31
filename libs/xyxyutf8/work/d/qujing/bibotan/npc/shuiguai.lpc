inherit NPC;
void create()
{
	int i = 30+random(20);
        set_name("水蛇怪", ({"shuishe guai", "guai"}));
        set("long", "一个身材细长的水蛇怪，吐着尺长的芯子，浑身发着恶臭。\n");
        set("age", 30);
        set("attitude", "aggressive");
        set("gender", "男性");
	set("class", "yaomo");
        set("per", 10);
        set_level(i);
	set_temp("apply/armor", 10);
	set("bellicosity", 2000);

	set("eff_dx", -5000);
        set("nkgain", 120);

        set("force_factor", 5);
        set("mana_factor", 5);
        set_skill("unarmed",i*10);
        set_skill("force",i*10);
        set_skill("spells",i*10);
        set_skill("dodge",i*10);
	set_skill("parry",i*10);
	set_skill("cuixin-zhang",i*10);
	map_skill("unarmed", "cuixin-zhang");
        setup();
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
	if( (int)this_object()->query("time") >= 6 ) {
        message("vision",name() + "“噗嗵”一声，跳回到水中。\n", environment(),this_object() );
        destruct(this_object());

	}
	return;
}
