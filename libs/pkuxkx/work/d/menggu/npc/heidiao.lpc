// Zine 2012/7/2

inherit NPC;

void create()
{
        set_name("黑雕", ({ "hei diao", "diao" }) );
        set("race", "野兽");
        set("age", 2+random(3));
        set("long", "这是一只黑色的大雕。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300000);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 100);
		set("is_heidiao",1);
        set("shen_type",1);set("score",100);setup();

        set("chat_chance", 10);
        set("chat_msg", ({
		"大雕「哑哑」地叫了几声。\n",
        }) );
}

int showup()
{
	message_vision("$N展动翅膀，似乎向往远处飞走。\n",this_object());
	return 1;
}

int intro(object me)
{
	object tmz;
	if (!me)
	{
		return 1;
	}
	if (base_name(environment(me))!="/d/menggu/xuanyaqian")
	{
		return 1;
	}
	tmz=present("tie muzhen",environment(this_object()));
	if (!tmz)
	{
		return 1;
	}
	tmz->shang(me);
	return 1;
}