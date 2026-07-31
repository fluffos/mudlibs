 inherit NPC;
void create()
{
        set_name("老农", ({ "old farmer", "farmer" }) );
        set("gender", "男性");
        set("age", 46);
        set("long",
                "一位年近五十的农夫。\n"
        );
        set_skill("blade", 10+random(50));
        setup();
        carry_object(__DIR__"obj/liandao")->wield();
}  
