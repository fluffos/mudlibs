// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
#define JCH "/d/jingcheng/"

void create()
{
	set_name("庙祝", ({ "miao zhu" , "keeper" }));
	set("title",YEL"勘破生死"NOR);
	set("long",
	"一个普普通通的庙祝，脸上布满皱纹，一双饱经风霜的手，他正用一明亮的眼睛看着你。\n");
	set("gender", "男性");
	set("age", 65);
	set("attitude", "peaceful");
	set("combat_exp", 5000);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"庙祝慢慢的抬起头，瞅了你一眼。\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}

int accept_object(object who,object what)
{
	int value;

	if( what->query("money_id") && 
		( value = what->value() ) > 1000 )
	{
		tell_object(who,GRN"庙祝轻轻的笑了一下，嘉许的看着你说：“"
		+RANK_D->query_respect(who)+"诚心求善，老天定会保佑你的。\n"NOR);
		if( who->query("shen") < 0 )
			who->add("shen", (int)(value/10));
		else
			who->add("shen", -(int)(value/20));
		if( !who->query("luck") )
			who->set("luck", 1);
		who->add("luck", 1);
	} else {
		message_vision("$N点点头头，对$n说：“多谢施主恩惠，这里多谢了。”\n",
		this_object(), who);
		remove_call_out("dest");
		call_out("dest", 1, what);
	}				
	return 1;
}
int accept_kill(object killer)
{
	int killer_max_qi;

	killer_max_qi = killer->query("max_kee");

	message_vision(YEL"庙祝大声叫道：“你如此作恶多端，会遭报应的。\n"NOR, this_object());
	if( killer->query("luck") > 3 ){	
		killer->add("luck", -3);
		message_vision(YEL"庙祝不知道在墙上何处按了一个机关，就听见“砰”的一声，$N\n"
		"就被踢了出去。\n"NOR, killer);
		tell_object(killer,YEL"你看见一个金盔金甲的天将一脚把你给踢出了庙门.\n");
		killer->move(JCH"chhgch");	
	} else {
		message_vision(RED"庙祝重重的跺了一下脚，地上裂开了一条缝，庙祝一下就消失\n"
		"不见了。\n"NOR, killer);
		remove_call_out("dest");
		call_out("dest", 1, this_object());
		tell_object(killer,RED"从庙里四处发出无数暗器，都冲着你发来，结果你措手不及,\n"
		"来不及防备，被射得浑身浴血。\n"NOR);
		killer->receive_wound("kee", (int)(killer_max_qi*9/10) );
		if( killer->query("kee") < 300 ){
			killer->die();
			return 1;
		}	
		killer->receive_damage("kee", -300 );
	}
	return 1;
}

void dest(object what)
{
	destruct(what);
}
