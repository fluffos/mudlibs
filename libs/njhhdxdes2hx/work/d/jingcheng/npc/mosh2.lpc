// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC;

int ask_me(object me);
void create()                                        
{
	string ch;
	int i;
	
	if( (i = random(10)) != 0 ) ch = chinese_number(i);
	else ch = "大";
                   
	switch( random(2) ){
	case 0:
		set("long",
		"这是一个满脸横肉的陌生人，长得五大三粗，他用一双不怀好意的眼睛盯着你。\n");
		set("gender", "男性");
		set_name("陌生人周"+ch+"郎", ({ "mosheng ren" , "ren"  }));
		set("age", 20+random(40));
		break;
	default:
		set("long",
		"这是一个慈眉善目的老婆婆，手里拿着一枝绣花针。\n");
		set("gender", "女性");
		set_name("陌生人陆"+ch+"娘", ({ "mosheng ren" , "ren"  }));
		set("age", 40+random(20));
		break;
	}
	set("attitude", "peaceful");
	set("combat_exp", 2000);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		(: random_move :),
        }) );
		
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 3, me);
                return;
        }
}

void greeting(object me)
{                          
	object ob, obj;                      
	int my_combatexp = random(me->query("combat_exp"));
	ob = this_object();
	
	if( (int)me->query("shen") > 50000
		|| (int)me->query("shen") < -50000 ){  
		ob->set("combat_exp", my_combatexp*9/8);
		ob->set_skill("sword", 120);       
		ob->set_skill("force", 120);
		ob->set_skill("kuihua-shengong", 120);
		ob->set_skill("pixie-jian", 120);
		ob->set_skill("dodge", 120);
		ob->map_skill("dodge", "pixie-jian");
		ob->map_skill("sword", "pixie-jian");
		ob->map_skill("force", "kuihua-shengong");
		ob->set("max_force", 2000);
		ob->set("force", 2000);
		ob->set("force_factor", 50);  
		ob->set("chat_chance_combat", 80);
		ob->set("chat_msg_combat",({
			(: perform_action, "sword.shuangda "+me->query("id") :),
			(: exert_function, "recover" :),
			(: exert_function, "kuihua" :),
		}));  
		obj = new(__DIR__"obj/gangjian");
		obj->move(ob);
		obj->wield();    
		if( present( me->query("id"), environment(me)) ){
		tell_object(me,RED+ob->query("name")+"告诉：阎罗王差我来送你上西天，你死了可别怨我。\n"NOR);
		ob->kill_ob(me);                               
		}
	} 
	return;
}
