#include <ansi.h>
inherit NPC;   
void create()
{
	set_name(BLK"黑熊"NOR, ({ "hei xiong", "xiong" }));
	set("long", 
"这是生长在森林中的的猛兽，力量过人,十分凶猛.\n" 
           );
	set("gender", "男性");
	set("age", 25);
//        set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 15);  
    set("attitude","hateful");
set("condition", "killer");
	set("combat_exp", 200000);
	set_skill("force", 160);
	set_skill("dodge", 160);
        set_skill("strike", 130);
	set_skill("parry", 130);  
        set_temp("apply/attack",  150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage",  120);
	setup();
  	carry_object(__DIR__"obj/xiongdan");
}

void init()
{
        object ob,obb;  
        ob=this_object();
//        obb=this_player();
        ::init();          
if(interactive(obb=this_player())&&(obb->query("race")!="野兽"))
{
remove_call_out("do_killing");
call_out("do_killing", 1, obb);
 }
        remove_call_out("do_dest");
        call_out("do_dest",30,ob);
}

void do_dest(object ob)
{
	if (!ob || environment(ob) != environment())
                return;
  message_vision("$N自觉不敌,带着伤,一瘸一拐地逃走了。\n", ob);
 	destruct(ob);
}
void do_killing(object ob)
{
if(!ob||environment(ob)!=environment()||environment(ob)->query("no_fight"))

return;
this_object()->kill_ob(ob);

}
