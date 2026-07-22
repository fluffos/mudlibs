
inherit NPC;

void create()
{
   set_name("李小姐",({ "li xiaojie","li","xiaojie" }) );
        set("gender", "女性" );
        set("age", 18);
   set("long", "她就是李财主的女儿。\n");
       
   set("combat_exp", 10000);
   set("str", 14);
   set("per", 27);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   add_money("coin", 50);
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N微微笑了笑。\n",ob2);break;
	case 1: message_vision("$N向$n做了个万福.\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
