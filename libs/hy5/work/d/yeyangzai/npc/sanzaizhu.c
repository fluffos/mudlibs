#include <ansi.h>
inherit NPC;

void create()
{
	set_name("贾三",({"jiasan","jia san"}));
	set("nickname",YEL"见"+RED"钱"+YEL"眼开"NOR);
	set("title","三寨主");
	set("age",30);
	set("long","「野羊寨」三寨主，专门负责拦路抢劫。\n正恶狠狠的瞪着你。\n");
        set("shen_type",-1);
	set("area_name","野羊寨");
	set("money_need",1000);
	set_skill("dodge",200);
	set_skill("unarmed",200);
	set_skill("parry",100);
	set_skill("axe",200);
set("max_neili",1900);set("neili",1900);set("max_qi",1900);set("max_jing",1900);
	set("combat_exp",150000);
        setup();
	carry_object(__DIR__"obj/jinbanfu")->wield();
	carry_object(__DIR__"obj/yinbanfu")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",10);
	carry_object(__DIR__"obj/gangjia")->wear();
}
	
void init()
{
        object ob,area;

	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_ask","ask");
}

int do_ask(string str)
{
	string banghui;
	object me;
	string sb,sth;
	if(! str)	return 0;
	me=this_player();
	if(! living(me))	return 0;
	if(sscanf(str,"%s about %s",sb,sth)!=2)	return 0;
	if(sb!=this_object()->query("id"))	return 0;
	if(sth!="买路钱")			return 0;
	banghui=(string)me->query("banghui");
        if(! banghui || query("banghui")!=banghui)   {
		if(me->query_temp("have_asked"))	{
		message_vision("$N一瞪眼道："+me->query("name")+
		"！问个没完没了，分明是不想掏钱，让我送你去鬼门关再问吧！\n",
		this_object());
		me->delete_temp("have_asked");
		kill_ob(me);
		me->fight_ob(this_object());
		return 1;
		}
		command("hehe");
		message_vision("$N说道：便宜你了"+me->query("name")+
		"就付(pay)俺十两白银吧。\n",this_object());
		me->set_temp("have_asked",1);
		return 1;
	}
	message_vision("$N拍了拍$n的肩膀道：都是帮中兄弟，我哪会要你的过路费呢。\n",this_object(),me);
	return 1;
}

void greeting(object ob)
{
	string banghui;
	if( !ob || environment(ob) != environment() ) return;
	banghui=(string) ob->query("banghui");
        if(! banghui || query("banghui")!=banghui)   {
		say("贾三高声叫道：呔！此山是我开，此树是俺栽，要打此路过，留下"+GRN"买路钱"NOR+"。\n");
		return;
		}
	command("say 这位"+RANK_D->query_respect(ob)+"，帮主身体可好？\n");
	return;
}

