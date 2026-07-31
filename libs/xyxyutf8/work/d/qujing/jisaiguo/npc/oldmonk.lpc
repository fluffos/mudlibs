inherit NPC;

void create()
{
        set_name("老和尚", ({"heshang"}));
        set("long", "一位老和尚，看起来慈善的很，口里还不停的咏经。\n");

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 60+random(20));
        set_level(39);
        set("shen_type", 1);
        set("per", 25);
        set("max_kee", 380);
        set("max_gin", 300);
        set_skill("force", 390);
        set_skill("unarmed", 390);
        set_skill("dodge", 390);
        set_skill("parry", 20+random(40));
set("inquiry", ([
"冤枉": "佛宝失窃，我等遭国王训斥，苦不堪言那！\n",
"佛宝": "佛宝原放在琉璃塔上。\n",
"琉璃塔" : "琉璃塔便在寺中后院。\n",
]));
        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();

        setup();
}
