// music   yangzhou's 店小二

inherit NPC;
void create()
{
	set_name("小沙弥",({"xiao shami","xiao","shami"}));
	set("gender", "男性" );
	set("age",10);
	set("long",
	"头冒亮光的打杂小和尚。\n");
	set("mingwang",1);
	set("combat_exp",150);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/hui_jiasha.c")->wear();
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
	say("小沙弥合掌:阿~密~豆~腐。\n");
			break;
		case 1:
	say("小沙弥一屁股坐到地上:累死了.....。\n");
			break;
                           }
}
