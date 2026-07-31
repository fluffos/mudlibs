//dipi.c by diabio

inherit NPC;
void create()
{
        set_name("地痞",({"di pi","dipi","pi"}));
	set("gender", "男性" );
	set("age",25);
	set("long",
		"邋遢的地痞。整日无所事事，只知吃喝玩乐。\n");
	set("combat_exp",1000);
	set_temp("apply/attack",10);
	set_temp("apply/defense",10);
	set_skill("unarmed",20);
	set("mingwang",-1);
	set_skill("dodge",20);
	set("attitude", "friendly");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say("地痞自言自语道：今各手气真背，又被左之助赢了。\n");
			break;
		case 1:
			message_vision("地痞对着$N奸笑道："+RANK_D->query_respect(ob)+
			"也是来“踏春”的吧。\n",ob);
			break;
                           }
}
