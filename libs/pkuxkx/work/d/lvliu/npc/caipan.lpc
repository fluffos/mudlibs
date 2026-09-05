#include <ansi.h>

inherit NPC;

void create()
{
	set_name("裁判", ({ "cai pan", "pan" }));
	set("gender", "男性");
	set("age", 35);
	set("combat_exp", 4000);      
	set("shen_type", 1);
	set("no_get",1);
	set("uni_target", 1);
	set("biwu_caipan", 1); 
	set("env/broadcast_combat",1);
	set("env/invisibility", 1);
	setup();	
}

void unconcious()
{
    die();
}

int is_relay_npc()
{
	return 1;
}

void die()
{
    this_object()->fullme();
	this_object()->clear_condition();
}

void relay_message(string msgclass, string msg)
{
    object env, room;
	if (strwidth(msg)<=0) return;
    room = load_object("/d/lvliu/biwukantai");
	env = environment(this_object());
    if(objectp(room) && env->query("lvliu_biwuchang"))
    {
        msg = replace_string(msg,"你", query("name"));
        msg = HIG "【"+env->query("short")+ HIG "】" NOR + msg;
        room->show_biwuchang_msg(msg, env->query("lvliu_biwuchang"));
    }
}

