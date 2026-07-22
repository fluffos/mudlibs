//baitu.c
inherit NPC;

void create()
{
        set_name("黄鹿", ({ "huang lu", "lu" }) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只黄色的大野鹿。\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 1000+random(1000));

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
	set_temp("apply/defence",5);
	set_temp("apply/armor",2);
      
	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );

	setup();
}


void die()
{
	object ob;
	message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
        if( random(30) >29 )      {
        	ob = new(__DIR__"obj/lurong");
                ob->move(environment(this_object()));
        }
        else    
                message_vision("天空中突然出现一只秃鹫，把$N叼走了。\n", this_object());
	destruct(this_object());
}

