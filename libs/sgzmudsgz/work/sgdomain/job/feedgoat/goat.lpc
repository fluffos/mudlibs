#include <mudlib.h>

#define __WORK__ 20

inherit MONSTER;
inherit M_CHAR;
inherit M_SMARTMOVE;

private int food=10;
private int water=10;
private int count=0;
private object owner;
string *emotes = ({"$N脸上露出灿烂的笑容。",
		"$N快乐的跳来跳去。",
		"$N正在闷闷不乐。",
		"$N痛苦得呲牙咧嘴，大概是牙痛得厉害。",
});

void setup()
{
	set_name("goat", "小山羊");
	set_gender(0);
	set_proper_name("一只可爱的小山羊");
	set_in_room_desc("小山羊(goat)");
	set_long("一只可爱的小山羊在你的脚下窜来窜去。");	
	call_out("heart_beat", 10);
}
void set_owner(object player)
{
	owner = player;
	return;
}
mixed indirect_give_obj_to_liv(object ob, object liv)
{
	object obj;
/*
	if( objectp(obj = present("grass", environment(this_object())))&& 
		obj->direct_cut_obj() ){
		return "小羊高兴的在草地上跳来跳去。\n";
	};
*/
	if( !ob || !objectp(ob) )return "小羊奇怪的打量着你。\n";
	if( ob->is_food() ){
		this_body()->simple_action("$N喂了一些青草给小羊。\n");
		if( food >= 8 )this_object()->simple_action("$N一脚把青草踢到了一边。");
		else this_object()->simple_action("$N几口就把青草吃光了。\n");
		food ++;
		destruct(ob);
		return "小羊高兴的叫了几声。\n";
	} else if( ob->direct_fill_obj() ){
		this_body()->simple_action("$N想给小羊点水喝。\n");
                if( water >= 8 )this_object()->simple_action("$N一阵风似的跑开了。\n");
                else this_object()->simple_action("$N小羊低头喝了几口水。\n");
                water ++;
		ob->move(environment(this_object()));
                return "小羊高兴的叫了几声。\n";
	};
	return "小羊奇怪的打量着你。\n";
}	
void heart_beat()
{
	remove_call_out("heat_beat");
	if( random(3) == 1 )food--;		 
	if( random(3) == 1 )water--;
	count++;

	if( food < 0 || water < 0  ){
		this_object()->simple_action("$N倒在地上挣扎了几下，死掉了。\n");
		tell_user(owner->query_id()[0], "真可惜，您没能完成这项任务。\n");
		owner->finish_job("feedgoat");
		destruct( this_object() );
		return;
	};
	if( count >= __WORK__ ){
		tell_user(owner->query_id()[0], "您的任务已经完成了，赶紧回去交差吧。 \n");
		owner->set_job("feedgoat", "end", 1);
		destruct( this_object() );
		return;
	};
	if( !present(owner->query_id()[0], environment(this_object())) ){
		tell_environment(this_object(), "小羊看没人注意，不知跑到哪儿去了。\n");
		tell_user(owner->query_id()[0], "您的小羊走丢了！\n真可惜，您没能完成这项任务。\n");
		owner->finish_job("feedgoat");
                destruct( this_object() );
                return;
        };
	if( water <= 5 )this_object()->targetted_action(
		"$N在$T的脚下绕来绕去，大概是渴了。\n", owner);
	else if( food <= 5 )this_object()->targetted_action(
		"$N在$T的脚下绕来绕去，想讨点东西吃。\n", owner);
	else this_object()->simple_action(emotes[random(sizeof(emotes))]);
									
	call_out("heart_beat", 15);
	return;
}