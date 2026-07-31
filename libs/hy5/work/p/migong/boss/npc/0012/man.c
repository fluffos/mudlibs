// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit BOSS;
//inherit  NPC;

string *first_name = ({ "通缉", "杀人", "强奸", "放火"});
string *first_id = ({ "tongji", "sharen", "qiangjian", "fanghuo"});
string *name_words = ({ "犯"});
string *id_words = ({ "fan"});

void create()
{
	string name;
	int i, j;
	
	i = random(sizeof(first_name));
	name = first_name[i];
	j = random(sizeof(name_words));
	name += name_words[j];
	
	set_name(name, ({ first_id[i]+" "+id_words[j] }) );
	// random_name_color(this_object());
	
	set("gender",  "男性");
	set("age", 30);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	set("vrm_guard", 1);
	
	set("dex",60);
	set("con",60);
	set("int",60);
	set("str",60);
	
	set("combat_exp", 3000000);
	set("level", 5);
	set("qi", 19000);
	set("max_qi", 19000);
	set("jing", 19000);
	set("max_jing", 19000);
	set("neili", 20000);
	set("max_neili", 20000);
	set("neili", 20000);
	set("jiali", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 300);
	set_temp("apply/armor", 300);
	set_temp("apply/defence",100);
	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200); 
	set_skill("sword",200);
	set_skill("lefthand-sword",200);
	set_skill("shadowsteps",200);
	set_skill("cloudforce",200);
	map_skill("force", "cloudforce");
	map_skill("sword", "lefthand-sword");
	map_skill("dodge", "shadowsteps");
	set("bonus", random(280)+180);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&180"   :  200,
	      "TA&180"   :  200,
	]));
	
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
	        (: perform_action, "sword.duxin" :),     
	}) );
	
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
}

void init()
{
	object me, ob;
	
	::init();
	if (! interactive(me = this_player()))
	      return;
	
	if( !me->is_character() || me==this_object() || !me) return;
	if(me->query("vendetta/authority")) return;
	if(!userp(me)) return;
	
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
}
        
mixed hit_ob(object me, object ob, int damage_bouns)
{
	int damage;
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return 0;
  	damage = 100 + random(100);
	ob->receive_wound("qi", damage);
	ob->add("neili", -2*random(me->query("jiali")));
	me->set("neili", 2*random(me->query("jiali")));

	return "$N阴阴一笑，长剑直出，轻轻刺中$n的膻中大穴，"HIC "$n" HIC "顿觉全身内力如水银般循孔飞泄而出！\n" NOR;
}

