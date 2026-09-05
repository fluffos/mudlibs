#include <ansi.h>
inherit NPC;   
void create()
{
	set_name(HIW"白熊"NOR, ({ "bai xiong", "xiong" }));
	set("long", 
"这熊毛长身巨，竟和大牯牛相似。张牙舞爪，狰狞可怖。\n" 
           );
	set("gender", "男性");
	set("age", 15);
	set("shen_type", -1);
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 2300);
	set("max_jing", 2300);
	set("neili", 4800);
	set("max_neili", 4800);
	set("jiali", 150);  
    set("attitude","hateful");
    set("condition", "killer");
	set("combat_exp", 4800000);
	set_skill("force", 260);
	set_skill("dodge", 360);
        set_skill("strike", 230);
	set_skill("parry", 230);  
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
void do_killing(object ob)
{
if(!ob||environment(ob)!=environment()||environment(ob)->query("no_fight"))

return;
this_object()->kill_ob(ob);

}
