inherit NPC;
string *first_name = ({ "双头", "金睛", "青皮", "花斑"});
string *name_words = ({ "蛟"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "jiao" }) );
        set("race", "野兽");
        set("age", 20);
	set("attitude", "aggressive");
        set("long", "一只怪模怪样的海蛟。\n");
        set("str", 20);
        set("cor", 30);
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("limbs", ({ "头部", "身体", "龟壳", "尾巴", "肚皮"}) );
        set("verbs", ({ "bite", "claw"}) );

        set("combat_exp", 370000+random(100000));
  set("daoxing", 400000);

	set_skill("dodge", 170);
	set_skill("unarmed", 170);
	set_skill("parry", 170);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 80);
	set_weight(500000);
        setup();
}

