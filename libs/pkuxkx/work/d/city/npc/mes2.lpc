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
        set("yanmen/hide",1);
		set_skill("force", 50);
		set("combat_exp", 500000);
		set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
		set("uni_target",1);
	    set("no_show",1);
		
        setup();
        
		carry_object(__DIR__"obj/cloth")->wear();

}


void unconcious()
{
    die();
}

void die()
{
    object ob=this_object();
    message_vision("$N摇了摇头，似乎有什么难以理解的事情。\n",ob);
    ob->fullme();
    return;
}

void relay_message(string msgclass, string msg)
{
    object room;
    object ob=this_object();
    object env=environment(ob);
    room = load_object("/d/changjiangnorth/cjb3");
    
    if(objectp(room) && room != environment(this_object())&&time()-(int)ob->query("time")>0)
    {
        msg = replace_string(msg,"你",ob->query("name"));
        msg = "【"+env->query("short")+"】" +  msg+"\n";
        tell_room(room,msg);
        ob->set("time",time());
    }
}

