// wolfdog.c
#include <ansi.h>
inherit NPC;

mapping *data=({
(["name":"野牦牛",	"id":"forest mob",	"mw":-1,	]),
(["name":"野羚羊",	"id":"forest mob",	"mw":-1,	]),
(["name":"藏野驴",	"id":"forest mob",	"mw":-1,	]),
(["name":"岩羊",	"id":"forest mob",	"mw":-1,	]),
(["name":"盘羊",	"id":"forest mob",	"mw":-1,	]),
(["name":"藏豺",	"id":"forest mob",	"mw":-1,	]),
(["name":"藏马熊",	"id":"forest mob",	"mw":-1,	]),
(["name":"雪豹",	"id":"forest mob",	"mw":-1,	]),
(["name":"猞猁",	"id":"forest mob",	"mw":-1,	]),		
(["name":"狼",	"id":"forest mob",	"mw":-1,	]),		
(["name":"高原鼠兔",	"id":"forest mob",	"mw":-1,	]),		
(["name":"长尾叶猴",	"id":"forest mob",	"mw":-1,	]),		
(["name":"熊猴",	"id":"forest mob",	"mw":-1,	]),		
(["name":"猕猴",	"id":"forest mob",	"mw":-1,	]),		
(["name":"麂子",	"id":"forest mob",	"mw":-1,	]),							
(["name":"毛冠鹿",	"id":"forest mob",	"mw":-1,	]),		
(["name":"红斑羚",	"id":"forest mob",	"mw":-1,	]),		
(["name":"野牛",	"id":"forest mob",	"mw":-1,	]),		
(["name":"金钱豹",	"id":"forest mob",	"mw":-1,	]),		
(["name":"云豹",	"id":"forest mob",	"mw":-1,	]),		
(["name":"黑熊",	"id":"forest mob",	"mw":-1,	]),		
(["name":"野猫",	"id":"forest mob",	"mw":-1,	]),							
(["name":"果子狸",	"id":"forest mob",	"mw":-1,	]),		
(["name":"马鹿",	"id":"forest mob",	"mw":-1,	]),		
(["name":"獐子",	"id":"forest mob",	"mw":-1,	]),		
(["name":"白唇鹿",	"id":"forest mob",	"mw":-1,	]),		
(["name":"小熊猫",	"id":"forest mob",	"mw":-1,	]),		
(["name":"岩羊",	"id":"forest mob",	"mw":-1,	]),		
(["name":"藏豺",	"id":"forest mob",	"mw":-1,	]),							
(["name":"藏马熊",	"id":"forest mob",	"mw":-1,	]),							
(["name":"雪豹",	"id":"forest mob",	"mw":-1,	]),							
(["name":"野牦牛",	"id":"forest mob",	"mw":-1,	]),							
(["name":"野羚羊",	"id":"forest mob",	"mw":-1,	]),							
(["name":"藏马鸡",	"id":"forest mob",	"mw":-1,	]),												
(["name":"藏雪鸡",	"id":"forest mob",	"mw":-1,	]),												
(["name":"黑颈鹤",	"id":"forest mob",	"mw":-1,	]),												
(["name":"斑头雁",	"id":"forest mob",	"mw":-1,	]),												
(["name":"高原鼠兔",	"id":"forest mob",	"mw":-1,	]),																
		
});


void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set("race", "野兽");
	set("age", 4);
	set("long", "一只试炼之森特有的"+query("name")+"。\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚" }) );
	set("verbs", ({ "bite", "claw" }) );


        set("dex",30+random(100));
  set("vendetta/authority",1);
	set_skill("parry",80+random(300));
set_skill("unarmed",80+random(300));
	set("max_neili",900+random(8550));
	set("max_jing",900+random(8550));
		set("max_qi",900+random(8550));
	set_skill("dodge",80+random(300));

	set("combat_exp", 20000+random(8000000));
//	set("shen_type", -1);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
	}) );
		
        set_temp("apply/attack", 20+random(380));
        set_temp("apply/defense",20+random(380));
        set_temp("apply/armor", 20+random(380));
        set_temp("apply/damage", 20+random(380));

	setup();
}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
int i,pot,exp;
	object killer;
	object ob;
	//message_vision("$N惨嚎一声，死了！\n", this_object());	
	exp= random(15)+1;
	pot= exp/3;
	if(objectp(killer = query_temp("last_damage_from")))
{

if (userp(killer))
{
 	tell_object(killer,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
		+chinese_number(pot)+"点潜能\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);

if (random(3)==0)
{
	ob = new(__DIR__"goupi");
	ob->move(killer);
	message_vision("$n从$N身上得到了皮毛！\n", this_object(),killer);

}

	ob = new(__DIR__"gourou");
	ob->move(killer);
	message_vision("$n从$N身上得到了鲜肉！\n", this_object(),killer);
}	
killer->start_busy(5);
	//destruct(this_object());
}


	::die();

return ;
}

