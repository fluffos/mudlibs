#include <ansi.h>
inherit NPC;   
string ask_me();
void create()
{
	set_name(RED"土匪"NOR, ({ "tu fei", "fei" }));
	set("long", 
		"他就是他是在黑松岭上占山为王的土匪。\n"
           );
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 300);
	set("max_jing", 300);
	set("max_neili", 800);
    set("qi", 300);
    set("jing", 300);
    set("neili", 800);

	set("jiali", 15);
	set("combat_exp", 200000);
	set("score", 20000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 150);
	set_skill("blade", 150);
  	set_skill("zhaixinggong", 80);
	map_skill("dodge", "zhaixinggong");
	setup();
  	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
        object ob;  
        ob=this_object();
        ::init();       
        write(
 "领头的土匪嘿嘿冷笑几声：\n" + 
RED"          居然敢闯到这里来，我看你是活得不耐烦了！"NOR); 
        add_action("do_kill","kill"); 
//        command("kill " + this_player()->query("id"));
        call_out("kill_ob",1,this_player());
     }
int do_kill(string arg)
{
	object me,ob,obj;
	me=this_player();
	ob=this_object();
	obj=present(arg,environment(me));
	ob->kill_ob(me);
	me->kill_ob(ob);
//	me->set_temp("killed",1);
	return 1;
}
