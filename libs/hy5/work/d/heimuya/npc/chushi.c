//feifei.c
inherit NPC;
void greeting(object);
void init();
void create()
{
	set_name("瘦瘦", ({ "shou shou","shou" }) );
	set("gender", "男性" );
	set("age", 35);
	set("long", "一个很瘦小的厨师，两只大眼睛不停地眨巴着。\n");
	set("shen_type", -1);
	set("combat_exp", 40000);
	set("str", 20);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");
	create_family("日月神教", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",10);
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
	object obn;
	if( !ob || environment(ob) != environment() ) return;
	if(((string)ob->query("family/family_name")=="日月神教")&&(random(3)==1))
	{say("瘦瘦笑吟吟地说道：这位" + RANK_D->query_respect(ob)
	     + "您饿了吧，请用餐。\n");
	if ( present("cake", ob) )
	{
		say("你不已经有吃的了吗？ 还来干什么？\n");
		return;
	}
	if ( present("jiang", ob) )
	{
		say("你不已经有吃的了吗？ 还来干什么？\n");
		return;
	}
	
	if ( present("jiuhu", ob) )
	{
		say("你不已经有吃的了吗？ 还来干什么？\n");
		return;
	}
	if ( present("niurou", ob) )
	{
		say("你不已经有吃的了吗？ 还来干什么？\n");
		return;
	}		
if (random(3)==0)
{
	     obn=new(__DIR__"obj/cake");
	     obn->move(ob);
	     obn=new(__DIR__"obj/doujiang");
	     obn->move(ob);
}
else
{
	     obn=new("/d/city/npc/obj/sniurou");
	     obn->move(ob);
	     obn->set("value",0);
	     obn=new("/d/city/npc/obj/sjiudai");
	     obn->move(ob);
obn->set("value",0);	
}
	     	   }
	else 
	     say("瘦瘦小眼一眨，笑吟吟地说道：这位" + RANK_D->query_respect(ob)
	     + "，要吃什么吗??。\n");
	   return;
}