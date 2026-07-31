// tiaofu.c

inherit NPC;

void create()
{
        set_name("挑夫", ({ "tiao fu", "porter" }) );
        set("gender", "男性" );
        set("age", 20+random(15));
        set("long",
                "这是个老实巴交的穷挑夫，长得膀阔腰圆，一身肌肉。\n");
        set("combat_exp", 1500);
        set("attitude", "heroism");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}