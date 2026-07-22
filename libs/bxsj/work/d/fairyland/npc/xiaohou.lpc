// xiaohou.c
// By jpei
// Modify By River@SJ

#include <ansi.h>
inherit NPC;
void wander_about();
void get_save();
void create()
{
        set_name("小猴", ({ "xiao hou", "xiao", "hou", "monkey" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只长着白毛的小猴。\n");

        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100);
        set("unique", 1);

	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
	if (clonep()) call_out("wander_about", 10);
}

void init()
{
	object ob = this_player();
	if (base_name(environment())[<6..] == "shanbi") {
           if (random(10)> 7 && !query("get_save")) {
		set("get_wound", 1);
		say("一个小猴忽然从陡峭的山壁上失足掉了下来，后腿被一块石头压住了，动弹不得。\n");
                call_out("get_save", 300);
	   }
	}
	if (ob->query_temp("help_monkey")
         && !present("jiuyang zhenjing", ob)
         && !query("get_wound")
         //&& !ob->query("jiuyang/baiyuan") move to dbyuan.c
         && random(10) > 5){
	   tell_object(ob,HIW"\n那只你救过的小猴忽然跑了过来，吱吱喳喳，叫个不停。\n"NOR);
	   tell_object(ob,HIW"顺着它的手指看去，只见一个白色大猿蹲在那里，神情痛苦。\n\n"NOR);
	   new(__DIR__"dbyuan")->move(environment());
	   ob->delete_temp("help_monkey");
           ob->set_temp("monkey_help", 1);
	}
}

int return_home(object home)
{
	if (query("get_wound")) return 1;
	return ::return_home(home);
}

void wander_about()
{
	if (!is_fighting()) {
	    if (!query("get_wound")) {
		random_move();
	    }
	    else {
	      add("get_wound", 1);
	      if (query("get_wound") > 15) {
		this_object()->die();
		return;
	      }
	      say("小猴发出“吱吱”的惨叫声。\n");
	    }
	}
	call_out("wander_about", 10);
}

void get_save()
{
       if(query("get_save")){
         delete("get_save");
         return;
       }
}
