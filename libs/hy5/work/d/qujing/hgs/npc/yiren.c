inherit NPC;

void create()
{
        set_name("江湖艺人", ({"yiren"}));
        set("age", 22);
        set("gender", "男性");
        set("long",
"一个打把式卖艺的，正在场中练功夫。\n");
        set("attitude", "peaceful");

        set("combat_exp", 100000);
        set("shen_type", 1);


        set_skill("unarmed", 240);
        set_skill("dodge", 220);
        set_skill("parry", 240);
        set_skill("blade", 240);
        set_skill("force", 240);
        set("chat_chance", 8);
        set("chat_msg", ({
"艺人喊道：各位父老乡亲，在下初来贵宝地，多多指教！\n",
"艺人拿铜锣敲了敲，喊到：各位有钱的捧个钱场，没钱的捧个人场！\n",
"艺人舞了个刀花道：我这趟刀，叫五虎断门刀！\n",
"艺人指着旗杆说：还没见一个人爬到顶的！\n",
}) );
        setup();
	add_money("silver", 1+random(3));
        carry_object("/d/obj/weapon/blade/blade")->wield();
        carry_object("/d/obj/cloth/linen")->wear();
}

