// poem.c
#include <ansi.h>
inherit ITEM;

string *story;
int step = 0;

void create()
{
        set_name("书函", ({"shu han","letter","shu","xin"}));
        set_weight(100);
       	set("unit", "封");
	set("long","一封%s给%s的书函，盖了封印，看不到里面的内容。\n");
       	set("value", 0);
       	set("no_give","给别人了，你如何交代？\n");
       	set("no_drop","这样的话，你如何交代？\n");
       	set("no_sell","这样的话，你如何交代？\n");
	setup();
}

void init()
{
	add_action("do_give", "give");
}

mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}

void go_on_process(object me,object who)
{
	if( !me || !who || !present(who,environment(me)) 
	 || !living(me) || !living(who) )
        	return;
	call_out("start_smash",2+random(3),me,who);
}

void start_smash(object me,object who)
{
	mixed line;
	string prompt;
	remove_call_out("start_smash");
	if( !me || !who || !present(who,environment(me)) 
	 || !living(me) || !living(who) )
	{
		destruct(this_object());
        	return;
        }	
	go_on_process(me,who);        
	line = query_story_message(step);
	if( !line )
	{
		evaluate(query("fuction"));
		destruct(this_object());
		return;
	}
	step++;
	prompt = ""; 
	if( functionp(line) ) 
        	catch(line = evaluate(line));
	if( stringp(line) )
		message_vision(line,who,me);
	if(intp(line) && !line)
        	go_on_process(me,who);
}

int do_give(string arg)
{
	string id;
	object obj,who,me=this_player();
	if( !arg )
		return 0;
	if( sscanf(arg,"%s to %s",arg,id)!=2
	 && sscanf(arg,"%s %s",id,arg)!=2 )
		return 0;
	if( !who=present(id,environment(me)) )
		return 0;
	if( !living(who) || who->is_fighting() )
		return 0;
	if( who->query("id")!=query("target_id") )
		return err_msg("这信可不是给"+id+"的哦。\n");
	if( query("storyed") )
		return 1;	
	if( userp(who) )
		return err_msg("你确定是给"+(who->query("gender")=="女性"?"她":"他")+"的吗？\n");
	if( query("owner_id")!=me->query("id") )
	{
		EMOTE_D->do_emote(who, "?",geteuid(me),CYN,0,0,0);
		message_vision("$N喝道：这封信你是怎么得来的？！\n",who);
		who->kill_ob(me);
		destruct(this_object());
		return 1;
	}
	story = query("story");
	if( !story || !arrayp(story) || sizeof(story)<1 )
	{
		EMOTE_D->do_emote(who, "?",geteuid(me),CYN,0,0,0);
		destruct(this_object());
		return 1;
	}
	if( me->query("family/moon_magu") )
	{
		me->set_temp("pedding/moon_wangfangping",1);
		obj = new("/d/obj/misc/seed");
		obj->set("owner_id",me->query("id"));
		if( !obj->move(me) )
			obj->move(environment(me));
		message_vision("王方平从怀中掏出一件物什交给$N。\n",me);
		tell_object(me,HIG"王方平在你耳边说道：我给你一粒"+me->query("family/moon_magu")+HIG"的种子，你待其成熟后交予麻姑，她自知结果。\n"NOR);
		destruct(this_object());
		return 1;
	}
	set("storyed",1);
	EMOTE_D->do_emote(who, "wow",geteuid(me),CYN,0,0,0);
	start_smash(me,who);
	return 1;
}
		