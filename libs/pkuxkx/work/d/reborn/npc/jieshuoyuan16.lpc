// jieshuoyuan.c 解说员

#include <ansi.h>

inherit NPC;
//inherit F_SAVE;

void create()
{
	set_name("解说员", ({ "jieshuo yuan", "yuan" }));
	set("gender", "男性");
	set("age", 35);

	  set("combat_exp", 4000000000);      
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	  set("shen_type", 1);
	  set("accept_fight",0);
	  set("no_get",1);
	  set("env/broadcast_combat",1); //使看台上的人能看到招式。
//	restore();
	setup();	
}

int is_relay_npc()
{
    return 1;
}

void die()
{
//	  fullme();
    revive();
    return;
}


void relay_message(string msgclass, string msg)
{
    object room;
    room = load_object("/d/reborn/kantai16");
    if(objectp(room) && room != environment(this_object()))
    {
        msg = replace_string(msg,"你",query("name"));
        msg = HIW"【你看到】"NOR +  msg;
        tell_room(room,msg);
    }
}
