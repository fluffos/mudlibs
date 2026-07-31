// music   yangzhou's 兵勇

inherit NPC;

void create()
{
	set_name("巡逻官兵", ({ "guan bing", "bing", "guanbing" }) );
	set("gender", "男性" );
	set("age", 20);
	set("long",
		"巡逻的官兵。\n");
	set("mingwang", 1);
	set("combat_exp", 80000);
        set("str", 30);
        set("cps", 20);
        set("con", 20);
        set("int", 20);
        set_skill("dodge",60);
        set_skill("unarmed",50);
	set_skill("parry",80);
	set_skill("blade",70);
	set("attitude", "peaceful");
	set("chat_msg", ({
		(: random_move :)
	}) );
	setup();
        carry_object("/obj/armor/tiejia")->wear();
        carry_object(__DIR__"obj/gangdao")->wield();
	add_money("silver", 20);
}
int accept_fight(object me)
{
        message_vision("巡逻官兵对$N把眼一瞪，喝道：呔，大胆，还不退下！\n\n", me);
        return 0;
}
/*
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

*/

