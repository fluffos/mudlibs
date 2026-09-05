// ahua.c 阿花

inherit NPC;

void create()
{
          set_name("丁丁", ({ "ding ding", "ding","dog" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只昂首挺胸，吐着长舌头的看门狗。正瞪着两只眼睛瞧着你。\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);
          set("chat_chance", 100);
	set("chat_msg", ({
		"汪汪!\n",
		"旺旺!\n",
		"汪汪汪!\n",
                  "丁丁忽作人立状，向你讨肉吃。\n",
	}) );
	
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	set("shen_type",1);set("score",200);setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("hongshao niurou") ) {
		message_vision("阿花高兴得汪汪叫了两声，朝$N摇了摇尾巴，叼着红烧牛肉跑到一边去吃了。\n",who);
		call_out("destroying",0,who,this_object());
		return 1;
	}
	else {
		message_vision("阿花嗅了嗅" + ob->query("name") +"，摇摇头，理都不理了。\n",who);
		return 1;
	}
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

void die()
{
	object ob,me,obj;
	me = this_object();
	
	message_vision("$N惨嚎一声，死了！\n", this_object());
	if( objectp(obj = me->get_damage_origin_object()))
	{
		 obj->set_temp("riyue/kill_ahua",1);
	}
	ob = new(__DIR__"obj/goupi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
