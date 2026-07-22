inherit NPC;

void create()
{
        set_name("长腿虾婆", ({"xia po", "po"}));
        set_level(43);
        set("long", "一个蹦来蹦去的老虾婆。\n");
        set("age", 50);
        set("attitude", "peaceful");
        set("gender", "女性");
        set("per", 10);

        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed",430);
        set_skill("force",430);
        set_skill("spells",430);
        set_skill("dodge",430);
	set_skill("hammer",430);
        set("chat_msg", ({
        "长腿虾婆蹦了几蹦。\n",
	"长腿虾婆嘴里嘟嘟囔囔：原来一蹦就可以进去。\n",
        (: random_move :)
}));

        setup();
	add_money("silver", random(2)+1);
        carry_object("/d/obj/cloth/skirt")->wear();
}