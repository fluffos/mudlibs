// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit BOSS;
//inherit  NPC;
#include "/d/migong/romnpc2.c"
string *first_name = ({ "五雷盟"});
string *first_id = ({ "enemy"});
string *name_words = ({ "爪牙", "护院", "舵主", "掌司"});
string *id_words = ({ "zhaoya","huyuan","duozhu","zhangsi"});

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
	
	     set("vrm_guard", 1);
        set("attitude", "aggressive");

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);
        
        set("combat_exp", 50000000);
        set("level", 25);
        set("qi", 60000);
        set("max_qi", 60000);
        set("jing", 65000);
        set("max_jing", 65000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("jiali", 1000);
 set_temp("apply/attack", 100);
        set_temp("apply/damage", 600);
        set_temp("apply/armor", 600);
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
	set("bonus", random(380)+220);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&180"   :  200,
	      "TA&180"   :  200,
	]));
	

	
	setup();
	carry_object("/clone/misc/cloth")->wear();
initlvl(520+random(30),(39));
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
        
