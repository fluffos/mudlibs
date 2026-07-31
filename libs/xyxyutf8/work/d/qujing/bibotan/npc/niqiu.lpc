inherit SUPER_NPC;

void create()
{
        set_name("天波儿笑", ({"tianboer xiao", "xiao"}));
        set("long", "他是乱石山碧波潭的小妖。\n");
        set("age", 30);
	set("title", "泥鳅精");
        set("attitude", "friendly");
        set("gender", "男性");
	set("class", "dragon");
        set("per", 10);
	set_level(45);

        set("force_factor", 40);
        set("mana_factor", 20);
        set_skill("unarmed",450);
        set_skill("force",450);
        set_skill("spells",450);
        set_skill("dodge",450);
	set_skill("whip",450);
	set_skill("hellfire-whip",450);
	set_skill("parry",450);
	map_skill("whip", "hellfire-whip");
	map_skill("parry", "hellfire-whip");
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/whip/tielian")->wield();
	add_temp("apply/combat_def",1000);
	add_temp("apply/dodge",500);
}

void relay_emote(object ob,string verb)
{
	if( ob->query("name")!="笑波儿天" ) return;
        switch(verb) {
        case "kick":
                        command("say 狗腿又发痒了...\n");
                break;
        case "wake":
                        command("wake");
		break;
        case "poke":  
                        command("poke xiao");                                        
                break;
        case "consider":  
                        command("poor tian");                                        
                break;
        case "grin":  
                        command("hehe tian");                                        
                break;
	case "lazy":
			command("lazy xiao");
		break;
        }
}