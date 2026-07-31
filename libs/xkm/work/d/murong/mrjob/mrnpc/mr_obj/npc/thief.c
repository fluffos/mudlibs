/************************
File:   Thief.c
Create: Play
Time:   4/25/2002
************************/
inherit NPC;
#include <ansi.h>;

void create()
{
	set_name("小偷",({ "xiao tou", "thief", "tou" }) );
        set("gender", "男性" );
        set("age", 25+random(20));
        set("long", "贼眉鼠眼的一个小偷，一身黑衣，面部用一块黑巾遮住。\n");
        set("per", 28);
        set("str", 34);
        set("dex", 25);
        set("con", 26);
        set("int", 25);
        set("attitude", "friendly");
        set("env/wimpy", 40);
        set("chat_chance", 10+random(10));
	set("chat_msg", ({
                "","",
		(: random_move :),
		(: command, "get all" :),
		(: command, "wear all" :),
	}) );
        set("combat_exp", 5000);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 50);


        setup();
        carry_object("/clone/armor/cloth")->wear();
        carry_object("/clone/weapon/duanjian")->wield();
}

void init()
{
	if(!query("del_patrol")){
		set("del_patrol",time());
		remove_call_out("go_patrol");
		call_out("del_patrol",180);
       	}
	add_action("do_zhuo", "zhuo");
}

int del_patrol()
{
	if(this_object()->is_fighting()||!living(this_object()))
	{
		remove_call_out("go_patrol");
		call_out("del_patrol",10);
	}
	else
	{
	       	message_vision(CYN"$N一晃身失去了踪迹！\n"NOR,
                 	this_object() );
        	destruct(this_object());
	}
	return 1;
}
int do_zhuo(string arg)
{
	object me;
	me = this_player();
	if(!arg)
	{
		write("你要抓谁？\n");
		return 1;
	}
	if(!query("Mrjob")||query("Mrjob")!="thief")
	{
		write("什么？\n");
		return 1;
	}
	if(!me->query_temp("Mrjob")||me->query_temp("Mrjob/content")!="patrol")
	{
		write("什么？\n");
		return 1;
	}
       	message_vision(CYN"$N对$n喝道：臭贼胆敢到慕容行窃！！\n"NOR,
                 	me,this_object() );
       	message_vision(CYN"$N欺身向前双手扣向$n脉门！！\n"NOR,
                 	me,this_object() );

        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;

}
int die()
{
        object me,ob;
        me = this_object()->query_temp("last_damage_from");
        ob = me->query_temp("Mrjob_thief");
        if(ob)
        {
        	if(ob==this_object())
        	{
        		me->add_temp("Mrjob_hortation",2+random(2));
        		me->delete_temp("Mrjob_thief");
       		        me->delete_temp("Mrjob_path");
        		me->add_temp("Mrjob_amu",1);
		}
        	message_vision(CYN"$n跪下对$N说道：大侠饶了小的吧！！\n"NOR,
        	me,this_object() );
        	message_vision(CYN"$N毫不理会$n的哀求，一把将其擒住关进了地牢。\n"NOR,
        	me,this_object() );
		destruct(this_object());
	}
	else
	::die();
	return 1;
}