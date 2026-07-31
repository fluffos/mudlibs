// wolfdog.c
#include <ansi.h>
inherit NPC;

mapping *data=({
(["name":"Ò°êóÅ£",	"id":"xizang mob",	"mw":-1,	]),
(["name":"Ò°ÁçÑò",	"id":"xizang mob",	"mw":-1,	]),
(["name":"²ØÒ°Â¿",	"id":"xizang mob",	"mw":-1,	]),
(["name":"ÑÒÑò",	"id":"xizang mob",	"mw":-1,	]),
(["name":"ÅÌÑò",	"id":"xizang mob",	"mw":-1,	]),
(["name":"²Ø²ò",	"id":"xizang mob",	"mw":-1,	]),
(["name":"²ØÂíÐÜ",	"id":"xizang mob",	"mw":-1,	]),
(["name":"Ñ©±ª",	"id":"xizang mob",	"mw":-1,	]),
(["name":"â¦áû",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"ÀÇ",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"¸ßÔ­ÊóÍÃ",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"³¤Î²Ò¶ºï",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"ÐÜºï",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"â¨ºï",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"÷ä×Ó",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"Ã«¹ÚÂ¹",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"ºì°ßÁç",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"Ò°Å£",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"½ðÇ®±ª",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"ÔÆ±ª",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"ºÚÐÜ",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"Ò°Ã¨",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"¹û×ÓÀê",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"ÂíÂ¹",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"â¯×Ó",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"°×´½Â¹",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"Ð¡ÐÜÃ¨",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"ÑÒÑò",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"²Ø²ò",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"²ØÂíÐÜ",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"Ñ©±ª",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"Ò°êóÅ£",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"Ò°ÁçÑò",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"²ØÂí¼¦",	"id":"xizang mob",	"mw":-1,	]),												
(["name":"²ØÑ©¼¦",	"id":"xizang mob",	"mw":-1,	]),												
(["name":"ºÚ¾±º×",	"id":"xizang mob",	"mw":-1,	]),												
(["name":"°ßÍ·Ñã",	"id":"xizang mob",	"mw":-1,	]),												
(["name":"¸ßÔ­ÊóÍÃ",	"id":"xizang mob",	"mw":-1,	]),																
		
});


void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set("race", "Ò°ÊÞ");
	set("age", 4);
	set("long", "Ò»Ö»Î÷²ØÌØÓÐµÄ"+query("name")+"¡£\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "ºó½Å" }) );
	set("verbs", ({ "bite", "claw" }) );


        set("dex",20+random(100));

	set_skill("parry",30+random(300));
set_skill("unarmed",30+random(300));
	set("max_neili",900+random(8550));
	set("max_jing",900+random(8550));
		set("max_qi",900+random(8550));
	set_skill("dodge",30+random(300));

	set("combat_exp", 10000+random(8000000));
//	set("shen_type", -1);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
	}) );
		
        set_temp("apply/attack", 10+random(380));
        set_temp("apply/defense",10+random(380));
        set_temp("apply/armor", 10+random(380));
        set_temp("apply/damage", 10+random(380));

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}

void die()
{
int i,pot,exp;
	object killer;
	object ob;
	//message_vision("$N²Òº¿Ò»Éù£¬ËÀÁË£¡\n", this_object());	
	exp= random(15)+2;
	pot= exp/2+1;
	if(objectp(killer = query_temp("last_damage_from")))
{

if (userp(killer))
{
 	tell_object(killer,"Äã±»½±ÀøÁË\n"+chinese_number(exp)+"µãÊµÕ½¾­Ñé\n"
		+chinese_number(pot)+"µãÇ±ÄÜ\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);

if (random(3)==0)
{
	ob = new(__DIR__"goupi");
	ob->move(killer);
	message_vision("$n´Ó$NÉíÉÏµÃµ½ÁËÆ¤Ã«£¡\n", this_object(),killer);

}

	ob = new(__DIR__"gourou");
	ob->move(killer);
	message_vision("$n´Ó$NÉíÉÏµÃµ½ÁËÏÊÈâ£¡\n", this_object(),killer);
}	
killer->start_busy(5);
	//destruct(this_object());
}


	::die();

return ;
}

