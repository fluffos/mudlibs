inherit NPC;
string *first_name = ({ "花皮", "绿背", "双头", "虎齿"});
string *name_words = ({ "鲨"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "shark" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只模样凶恶的大鲨鱼。\n");
        set("str", 20);
        set("cor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("limbs", ({ "头部", "身体", "前鳍", "尾巴", "肚皮"}) );
        set("verbs", ({ "bite"}) );

        set("combat_exp", 100000+random(10000));
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 20);
	set_weight(500000);
        setup();
}



