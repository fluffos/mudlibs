//雁门关
//created by Zine 2 Aug 2011

#include <ansi.h>
inherit NPC;
int ask_job();
void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("gender", "男性" );
		set("title", HIR"大辽南院 "+HIW+"枢密使"NOR);
        set("age", 40+random(20));
        set("long", 
            "他就是大辽国掌南院枢密使"+this_object()->query("name")+"。\n");
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
		set("attitude", "friendly");
        set("inquiry", ([
            "萧远山" : "萧大人夫妇已经出发，听说有刺客行刺，真是让人担忧啊。",
			"job" : (: ask_job :),
            "护送" : (: ask_job :),
       	]) );
		set("chat_chance", 1);
        set("chat_msg", ({
                (:askforhelp:),
        }) );
        setup();
        
		carry_object(__DIR__"obj/cloth")->wear();

}


void unconcious()
{
        die();
}

void die()
{
        message_vision("史可法摇了摇头，似乎很不理解你想干嘛。\n",environment(this_object()));
        this_object()->fullme();
        return;
}



