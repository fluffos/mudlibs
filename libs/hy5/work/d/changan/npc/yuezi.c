inherit  NPC;
void  create()
{
        set_name("乐子",  ({"yue girl", "girl"}));
        set("age",  18);
        set("gender",  "女性");
        set("long", "一个手里拿着乐器的戏子。\n");
        set("attitude",  "peaceful");
        set("per",  22);
        set("combat_exp",  8000);
        set("shen_type",  1);
        set("class",  "scholar");
        set("force",  200);
        set("max_force",  200);
        set("force_factor",  3);
        set_skill("unarmed",  40);
        set_skill("dodge",  40);
        set_skill("parry",  40);
        setup();

        carry_object("/d/changan/obj/skirt")->wear();
}
