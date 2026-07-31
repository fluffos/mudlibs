//Cracked by Kafei

//changed by wzfeng@xkx 2000 6

#include <ansi.h>
#define JOB_DIR "/clone/obj/job/"

inherit NPC;
#include "/clone/obj/job/job_npc_pker.h"
#include "/clone/obj/job/lpc_math.h"

void recover_self();

void destruct_self();
void create()
{
		set_name("江湖商人", ({ "jianghu shangren", "jianghu", "shangren" }) );
	    set("long", "此人头带小毡帽，一副平常商人模样，满脸的风尘之色。\n"
			"他身形瘦高，身穿灰白长褂，背后背着一个鼓鼓的行囊。\n");

       
        set("gender", "男性" );
        
        set("no_refresh", 1);
		set("age",45);


        setup();
        carry_object("/clone/armor/beixin")->wear();
}
void init()
{
	recover_self();
	remove_call_out("destruct_self");
	call_out("destruct_self",1200);
	add_action("do_baohu", "baohu");
	add_action("do_baohu", "protect");

}
int baohu(string age)
{
	string npc_name;
	if(!arg)
		return notify_fail("你要保护谁？\n");
	if( sscanf(arg, "%s", npc_name)!=1 ) 
		return notify_fail("请输入baohu id。\n");
	if(npc_name!=query->("id")||
		(this_player()->query("id")!=query("player_name")))
		return notify_fail(query("name")+"不需要你来保护。\n");
	command("say 如此多谢"+this_player()->query("name")+"了。");
	command("say 如今有了这"+this_player()->query("family/family_name")+"高手和我一同上路，估计那些邪魔歪道不敢来了吧。");
	command("thank "+this_player()->query("id"));

	return 1;
}

void destruct_self()
{
	command("say 唉！这次的东西有没送到，我还是赶快离开这里吧。");
tell_room(environment(this_object()), query("name")+"急急忙忙离开了。\n", ({this_object()}));
	destruct(this_object());

}

void recover_self()
{
/*	object ob,player;
	ob=this_object();
	if(query("player_name"))
	{
		if(player=find_player(query("player_name")))
			if(file_name(environment(ob))!=file_name(environment(player)))
			{
				
				player->delete_temp("job_system/kill_killer");
				if(!living (ob))
					tell_room(environment(ob), "一个蒙面人走了过来，抱起昏倒的"+ob->query("name")+"，一个翻身，不知道去了那里。\n", ({ob}));
				else
					tell_room(environment(ob), ob->query("name")+"哼的一声说到：“跑的到挺快。”说罢一个翻身，不知道去了那里。\n", ({ob}));
	
				destruct(this_object());
				return;
				}
	}
	remove_call_out("recover_self");
	call_out("recover_self", 1);

		return ;
		*/
}


void kill_ob(object me)
{
	object player;
    if(me->query("id")!=query("player_name"))
	{
		if(me->query("combat_exp")>query("combat_exp")/2)
		{
			command("say 今天点子不对，不能陪你玩了。");
			command("hehe "+me->query("id"));
			tell_room(environment(this_object()), query("name")+"说罢一个翻身，不知道去了那里。\n", ({this_object()}));
			if(!player=find_player(query("player_name")))
			{
				::kill_ob(me);
				return ;
			}
			else
			{


				player->delete_temp("job_system/kill_killer");

			destruct(this_object());

			
			return;
			}
		}
		else
		{
			command("say 既然你自己找死，也怨不得我。");


			set("neili",query("max_neli")*2);
			set("jingli",query("max_jingli")*2);
			set("qi",query("max_qi")*2);
		}
	}
	::kill_ob(me);
}

void set_status(object player) {
    int exp, sacrifice, exp_rate,skill_rate,lmt,i;
    object menpai_ob;
    string menpai,family;
	if(!living(player))
		return ;

	set("age",30+random(30));
    set("player_name", player->query("id"));
    exp = player->query("combat_exp");
	family=player->query("family/family_name");
	
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	if(!objectp(menpai_ob)) return;
	menpai_ob->restore();
	if(!(luck=menpai_ob->query_luck(family)))
		luck=random(5);
	
	Set_Npcattrib(20,luck,
	 player->query("max_qi"),player->query("max_qi")*luck/10,
 	 player->query("max_jing"),player->query("max_jing")*luck/10,
	 player->query("max_jingli"),player->query("max_jingli")*luck/10,
	player->query("max_neili")+player->query("max_neili")*luck/20,0,
	exp+exp*(10-luck)/20,0);

	exp=query("combat_exp");
   	for (i=0;(i*i*i/10)<exp;i++);

	if(exp<500000)
		i=i*1/2;
	if(exp>=500000&&exp<=2000000)
		i=i*2/3;
	if(exp>=2000000&&exp<=5000000)
		i=i*3/4;
	if(exp>=5000000&&exp<=10000000)
		i=i*4/5;
	 
	set_killer_name(family);
    skills_setup(family,i,i/10);
	if(player->query("combat_exp")<500000)
		delete("chat_msg_combat");
	else
	{
		if(exp>=500000&&exp<=2000000)
			set("chat_chance_combat", 15);
		if(exp>=2000000&&exp<=5000000)
			set("chat_chance_combat", 25);
		if(exp>=5000000&&exp<=10000000)
			set("chat_chance_combat", 50);
		if(exp>10000000)
			set("chat_chance_combat", 70);
	}

}

void die()
{
    mixed killer;
    int kill_num;
	object job_data,player;
	mapping job_map;
	if(!player=find_player(query("player_name")))
	{
		::die();
	}

	if(player=find_player(query("player_name")))
	{
		
		player->delete_temp("job_system/kill_killer");
		if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
		if(!objectp(job_data)) return;
		job_data->restore();
		job_map=get_mapping(query("player_name"),"job_player",job_data->query_job_data());
		map_delete(job_map,"job_oppose_pker_place");
		map_delete(job_map,"job_oppose_pker_mode");
		job_map["job_oppose_pker_finish_time"]=time();
		
		job_map["job_finish"]="oppose_pker";
		job_data->modify_job_data(query("player_name"),job_map);
		player->delete_temp("job_system");
		job_data->save();
		
		

	}
	//change job data.
	
    ::die();
}
void unconcious()
{
      command("say 好，好厉害......没想到......我会命丧于此......");
        ::unconcious();
}
