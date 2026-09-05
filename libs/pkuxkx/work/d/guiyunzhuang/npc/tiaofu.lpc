// tiaofu.c

inherit NPC;

void create()
{
	set_name("挑夫", ({ "tiao fu", "tiao" }) );
	set("gender", "男性" );
	set("age", 20+random(15));
	set("long",
		"这是个老实巴交的穷挑夫，长得膀阔腰圆，一身肌肉。\n");
	set("combat_exp", random(1500));
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
	set("attitude", "heroism");

	set("shen_type",1);set("score",200);setup();
        carry_object("clone/misc/cloth")->wear();

}

