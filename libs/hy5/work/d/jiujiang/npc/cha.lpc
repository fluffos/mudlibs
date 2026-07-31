
inherit NPC;

void create()
{
   set_name("茶馆老板",({ "chaguan laoban","laoban" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是茶馆的老板。\n");
       
   set("combat_exp", 50000);
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
	case 0: message_vision("$N笑道:这位客官，欢迎来坐坐!\n",ob2);break;
	case 1: message_vision("$N冲$n笑道：我们的茶叶可都是上等的。\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
