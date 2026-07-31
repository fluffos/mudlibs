#include <ansi.h>
inherit NPC;  

void create()
{
    set_name(MAG"朝奉"NOR, ({ "chao feng", "feng" }));
    set("age", 59);
    set("gender", "男性");
    set("long", "一名朝奉, 看起来很精明。\n");
    set("combat_exp", 80000);
    setup();                                     
    carry_object(__DIR__"obj/cloth3")->wear();
} 

void init()
{
    object ob;
    ::init();
    if( interactive(ob = this_player()) && !this_object()->can_act() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
} 

void greeting(object ob)
{

    if( !ob || environment(ob) != environment() ) return;
    message_vision("朝奉迎上来：你想换钱还是当物？\n",ob);
}

