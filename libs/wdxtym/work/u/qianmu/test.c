inherit NPC;

void xuemo_pfm();

void create()
{
	set_name("血魔", ({ "wuzheng daozu", "daozu" }));
	set("long", "道祖。\n");
	set("gender", "男性");
	set("age", 100);
	set("shen_type", 1);
	set("shen", 500000);
	set("str", 31);
	set("int", 39);
	set("con", 40);
	set("dex", 32);
	
	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: xuemo_pfm :),
	}));
        
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void xuemo_pfm()
{
    object who = select_opponent();
    tell_object(who, "血魔发出一声怪吼，扑向你撕咬。\n");
    if (random(2))
    {
        tell_object(who, "你被血魔咬中了，伤口开始麻痹。\n");
        who->start_busy(3);
    	who->affect_by("xuedu",
    		       ([ "level" : 100,
    			  "id"    : query("id"),
    			  "duration" : 100,]));
    }
    else
    {
        tell_object(who, "你往旁边一躲，血魔扑了个空。\n");
    }
}