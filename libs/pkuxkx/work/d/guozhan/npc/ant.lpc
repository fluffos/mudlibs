#include <ansi.h>

inherit NPC;

void create()
{
	set_name("蚂蚁", ({ "ma yi", "yi","mayi","ant" }));
	set("race","野兽");
	set("age", 1);

	set("combat_exp", 4000);      
	set("no_get",1);
    set("uni_target",1);
	setup();	
}

void die()
{
    //fullme();
    return;
}

void unconcious()
{
    die();
    return;
}

void relay_message(string msgclass, string msg)
{
    object room;
    object ob=this_object();
    room = load_object("/d/guozhan/ming_qiaodi");
    
    if(objectp(room) && room != environment(this_object()))
    {
        msg = replace_string(msg,"你",ob->query("name"));
        msg = "【桥上】" +  msg+"\n";
        tell_room(room,msg);
    }
}

