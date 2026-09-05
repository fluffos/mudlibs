#include <ansi.h>
// d/taohuadao/npc/yapu.c
// By llx 26/10/97
inherit NPC;
//void greeting();
void init();
//int accept_object();
//void serve_tea();
void delete_served();
void create()
{
	set_name("哑仆", ({"yapu"}) );
       
        set("title",RED "桃花岛" NOR + GRN "侍者" NOR);
	set("gender", "男性" );
        set("age", 30+random(20));
	set("long",
	  "这是桃花岛的哑仆，其脸上凶煞的样子也可看出他原来定是一个大恶人。\n"
	  "他的舌头已经被割断了，只能不断比划着手势。见有人示意服务，便过去添加饮食，但动作显得笨拙。\n");
	set("attitude", "peaceful");
    set("shen_type", 0);
        set("str", 20+random(5));
        set("int", 20+random(3));
        set("con", 20+random(4));
        set("dex", 20+random(2));
        set("max_qi", 200+random(100));
        set("max_jing", 150+random(50));
        set("neili", 200+random(100));
        set("max_neili", 200+random(100));
		set("combat_exp", 3000+random(800));
        set("score", 1000+random(1000));
        set_skill("force", 30+random(10));
        set_skill("dodge", 20+random(10));
        set_skill("unarmed", 25+random(10));
        set_skill("parry", 20+random(10));
        set_temp("apply/attack", 20+random(10));
        set_temp("apply/defense", 15+random(10));
        set_temp("apply/damage", 10+random(5));
                
        set("shen_type",1);set("score",200);setup();
        
		carry_object("/d/city/obj/cloth")->wear();
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
	say("哑仆示意：这位" + RANK_D->query_respect(ob)
	     + "请先入座，" + "我这就给您砌茶。\n");
}
void serve_tea(object who)
{
	object obj1;
	object room;
	if( !who || environment(who) != environment() ) return;
	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;
	if ( (int)who->query_temp("tea_cup") <= 0 )
	{
	 	obj1 = new(__DIR__"obj/mudancha");
		obj1->move(room);
		message_vision("哑仆拿出个瓷碗来，将桌上的牡丹茶倒满．\n",
			who);
	} 
	
 	obj1 = new(__DIR__"obj/haoqiutang");
	obj1->move(room);
	message_vision("哑仆拿出一盆鲜热的好逑汤，放在桌上．\n", who);
	
	return;
	
	obj1 = new(__DIR__"obj/feiya");
	obj1->move(room);
	message_vision("哑仆拿出一碟香喷喷的肥鸭，放在桌上。\n",who);
	return;
	obj1 = new(__DIR__"obj/xuntianji");
	obj1->move(room);
	message_vision("哑仆拿出一碟肥嫩的熏田鸡，放在桌上。\n",who);
	return;
	obj1 = new(__DIR__"obj/yinsijuan");
	obj1->move(room);
	message_vision("哑仆拿出一碟银丝卷，放在桌上。\n",who);
	return;
}
