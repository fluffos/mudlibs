// jieshuoyuan.c 解说员

#include <ansi.h>

inherit NPC;
//inherit F_SAVE;

void create()
{
	set_name("解说员", ({ "jieshuo yuan", "yuan" }));
	set("gender", "男性");
	set("age", 35);

	set("combat_exp", 4000);      
    set_skill("dodge", 20);
    set_skill("unarmed", 20);
    set_temp("apply/attack",  10);
    set_temp("apply/defense", 10);
	set("shen_type", 1);
	set("accept_fight",0);
	set("no_get",1);
//	restore();
	setup();	
}

/*
void die()
{
//	  fullme();
    revive();
    return;
}
*/

void relay_message(string msgclass, string msg)
{
    object room;
    room = load_object("/u/haiv/jiaoji_kantai");
    if(objectp(room) && room != environment(this_object()))
    {
        msg = replace_string(msg,"你",query("name"));
        msg = "【解说员】" +  msg;
        tell_room(room,msg);
    }
}
