// wujiang.c 武将

inherit NPC;

void create()
{
        set_name("巡逻官兵", ({ "xunluo guanbing","guanbing", "bing" }));
        set("gender", "男性");
        set_level(99);
        set("age", random(10) + 20);
        set("str", 25);
	set("con", 25);
	set("spi", 25);
	set("dex", 25);
	set("int", 25);
        set("long", "他威风凛凛，杀气腾腾，负责城内商家安全。\n");
        set("combat_exp", 50000);
	set("class", "fighter");
        set("attitude", "herosim");
        set_skill("unarmed", 700);
        set_skill("force", 700);
        set_skill("spear", 700);
        set_skill("dodge", 700);
        set_skill("parry", 700);
	set_skill("bawang-qiang", 700);
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
        setup();
        carry_object(0,"armor",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"shield",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"spear",random(2))->wield();
}

int accept_fight(object me)
{
        message_vision("巡逻官兵对$N把眼一瞪，喝道：呔，大胆，还不退下！\n\n", me);
        return 0;
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
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "吐了口唾沫，骂道：下次别叫老子碰到！
巡逻官兵走了出去。\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

