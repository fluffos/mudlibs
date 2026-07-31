#include <ansi.h>
inherit NPC;

void create()
{
	set_name("姚伯义",({"yao boyi","yao"}));
	set("nickname","腥风斩");
	set("area","野羊寨");
	set("age",50);
        set("shen_type",-1);
	set_skill("dodge",220);
	set_skill("unarmed",120);
	set_skill("parry",120);
	set_skill("blade",220);
set("max_neili",1900);set("neili",1900);set("max_qi",1900);set("max_jing",1900);
	set("combat_exp",500000);
        setup();
	carry_object(__DIR__"obj/xingfengdao")->wield();
	add_money("gold",2);
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
}

void greeting(object ob)
{
	string banghui;
        if( !ob || environment(ob) != environment() ) return;
	banghui=(string) ob->query("banghui");
        if(! banghui || query("banghui")!=banghui)   {
		command("say 即然到了野羊寨，就躺着出去吧！\n");
                command("guard north");
                kill_ob(ob);
                ob->fight_ob(this_object());
                return;
        }
}


