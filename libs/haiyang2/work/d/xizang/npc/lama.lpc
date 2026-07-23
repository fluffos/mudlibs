 inherit NPC;
void create()
{
        set_name("护寺喇嘛", ({ "lama"}) );
        set("gender", "男性" );
        set("age", 35);
        set("str", 20);
        set("long", @LONG
一个大昭寺的藏僧。
LONG
);
        set("attitude", "heroism");
        set("combat_exp", 6000);
        create_family("大昭寺", 24, "弟子");
        set_skill("unarmed", 100);

        set_skill("iron-cloth", 20);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
        if(random(5)==1)
        carry_object(__DIR__"obj/sunbook");
        if (random(2)) carry_object(__DIR__"obj/fake-tooth");
        carry_object(__DIR__"obj/redcloth")->wear();
} 
