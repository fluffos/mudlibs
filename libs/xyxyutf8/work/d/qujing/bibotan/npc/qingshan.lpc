inherit SUPER_NPC;

void create()
{
        set_name("笑波儿天", ({"xiaoboer tian", "tian"}));
        set("long", "他是乱石山碧波潭的小妖。\n");
	set_level(45);        
        set("age", 30);
	set("title", "青鳝怪");
        set("attitude", "friendly");
        set("gender", "男性");
	set("class", "dragon");
        set("per", 10);
        set("force_factor", 40);
        set("mana_factor", 20);
        set_skill("unarmed",450);
        set_skill("force",450);
        set_skill("spells",450);
        set_skill("dodge",450);
	set_skill("fork",450);
	set_skill("parry",450);
	set_skill("yueya-chan",450);
	map_skill("parry", "yueya-chan");
	map_skill("fork", "yueya-chan");
	set("inquiry", ([
		"后花园": "听说这后花园是个八卦阵，不知道方位的，嘿嘿．．．\n",
	]) );

        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
	add_temp("apply/dodge",500);
	add_temp("apply/attack",500);
	add_temp("apply/combat_def",1000);
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
	if( random(5) > 3  ) {
        if (objectp(present("xiao", environment(this_object())))) {
                switch( random(6) ){
                        case 0:
                                command("say 天波儿笑，别又睡着了！");
                                command("wake xiao");
                        break;
                        case 1:
                                command("say 天波儿笑，听说龙王又赏你了。");
                                command("consider xiao");
                        break;
                        case 2:
                                command("say 天波儿笑，想嘛呢？");
                                command("poke xiao");
                        break;
                        case 3:
                                command("say 天波儿笑，上月来的那个小宫娥还真漂亮！");
                                command("grin xiao");
                        break;
                        case 4:
                                command("say 天波儿笑，看好了门，别让人溜进去！");
                                command("kick xiao");
                        break; 
			case 5:
				command("say 天波儿笑，快去向公主请示方位！");
				command("lazy xiao");
			break;
                	}
        	}
        }
	}
        return ::heal_up() + 1;
}