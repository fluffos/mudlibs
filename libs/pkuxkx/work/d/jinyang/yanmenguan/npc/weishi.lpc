//雁门关
//created by Zine 2 Aug 2011

#include <ansi.h>
inherit NPC;
void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("gender", "男性" );
		set("title", HIR"大辽 "+HIW+"卫士"NOR);
        set("age", 20+random(20));
        set("long", 
            "他就是大辽国的武士，"+this_object()->query("name")+"。\n");
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
        
        setup();
        
		carry_object(__DIR__"obj/cloth2")->wear();

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


