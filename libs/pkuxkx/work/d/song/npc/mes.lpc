//雁门关
//created by Zine 2 Aug 2011

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("侦察兵",({"bing"}));
        set("gender", "男性" );
        set("str", 30);
        set("dex", 30);
        set("con", 20);
        set("int", 60);
		set("shen_type", 1);
		set_skill("force", 50);
		set("combat_exp", 500000);
		set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
		set("uni_target",1);
		set("no_show",1);
        setup();
        

}


void unconcious()
{
    die();
}

void die()
{
    object ob=this_object();
    ob->fullme();
    return;
}

void relay_message(string msgclass, string msg)
{
    object room,ob=this_object(),env=environment(ob),*listeners=({}),*all_player;
    room = load_object("/d/song/wuchang/kantai1");
	if (room->query("RELAY_"+env->query("L_dir")))
	listeners=room->query("RELAY_"+env->query("L_dir"));
	all_player=all_inventory(room);
	all_player=filter_array(all_player, (: userp :));
	all_player=all_player-listeners;
    if(objectp(room) && room != environment(this_object()))
    {
        msg = "【"+env->query("short")+"】" +  msg;
        tell_room(room,msg,all_player);
    }
}

