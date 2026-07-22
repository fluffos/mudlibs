// monk.c

inherit NPC;
string give_money();
object ob=this_object();
void create() 
{
set_name("老和尚", ({ "old monk", "monk" }) );
	set("class", "bonze");
	set("gender", "男性");
          set("age", 77);
	set("long","他穿着一身灰色的僧袍，看起来很老实的样子。\n");
	set("title", "城隍庙扫地和尚");
	set("combat_exp", 3000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry",([
		"领钱" : (:give_money:)
    	]));
	set("chat_chance", 5);
set("chat_msg", ({"老和尚对你说到：这位施主，请排队。\n"}));
	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("env/wimpy", 60);

	set_skill("force", 25);
	set_skill("unarmed", 20);
	set_skill("sword", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

  	setup();
  	carry_object("/clone/misc/cloth")->wear();
//	add_money("silver", 50);
}

void init() 
{
  	object me;
  	::init();
  	if(interactive(me=this_player()) && !is_fighting()) {
  		remove_call_out("greeting");
                call_out("greeting", 1, me);

    	}
}
void greeting(object ob)
{
   	object me;
   	me=this_player();
        if(interactive(me=this_player()) && !is_fighting()) {
   		command("look "+me->query("id"));
                command("hi "+me->query("id"));
           }
}

string give_money()
{
	object me;
	me=this_player();
  	if(!me || environment(me)!=environment()) return 0;
  	if((int)me->query("given")==1) {
    		command("kick "+me->query("id"));
    		command("faint "+me->query("id"));
    		return "你怎么这么贪财！！！";
    	}
	if( (int)me->query("kar") >=20 ) {
/*
		ob->add_money("silver", 50);
		command("give "+me->query("id")+" 50 silver");
*/
		me->set("given",1);
            return "施主与老衲能在此相见，也算有缘，可惜你来迟了。";
    	}
	if ((int)me->query("kar")<20){	
/*
		ob->add_money("silver", 30);
		command("give "+"30 silver "+"to "+me->query("id"));
		ob->add("silver",30);
*/
		me->set("given",1);
            return "施主与老衲能在此相见，也算有缘，要钱没有，命有一条。";
    	}
}
