//Cracked by Kafei
//wzfeng@xkx 2000 7
//ask somethig about master
//ask master about "贡献度"

#define JOB_DIR "/clone/obj/job/"
//#include JOB_DIR+"lpc_math.h"
//#include JOB_DIR+"job_family_master.h"
#include "/clone/obj/job/lpc_math.h"
#include "/clone/obj/job/job_family_master.h"

void tell_player_family_job_contribute(object player,object master)
{
	object job_data,menpai_ob;
	string family_name,master_name,master_call,msg;
	mapping family_map;
	int point;
	family_name=player->query("family/family_name");
	if(!family_name||
		family_name!=master->query("family/family_name"))
	{
		message_vision(CYN "$n对$N说道：这位"+RANK_D->query_respect(player)+"问错人了吧？"
		+RANK_D->query_self(master)+"怎么知道那种事情呢。\n" NOR, player, master);
		return;
		
	}
	master_name=explode(family_master[family_name], "/")[2];
	master_call=explode(family_master[family_name], "/")[0];
	if(master->query("id")!=master_name)
	{
		message_vision(CYN "$n对$N说道：你去问"+master_call+"吧。\n" NOR, player, master);
		return;
	}

	if(!job_data=find_object(JOB_DIR+"job_data"))
		job_data=new(JOB_DIR+"job_data");
	if(!objectp(job_data)) return 0;
	job_data->restore();
	family_map=job_data->query_family_job_data(family_name);
	if(!mapp(family_map)
		||family_map["job_contribute"]<=0)
	{
		message_vision(CYN "$n对$N摇摇头说道："+family_name+"弟子不争气，还没为"+family_name+"做出任何贡献呢。\n" NOR, player, master);
		return;
	}
	message_vision(CYN "$n对$N说道：目前我"+family_name+"的贡献度为"+chinese_number(family_map["job_contribute"])+"点。\n"NOR, player, master);
	if(!family_map[player->query("id")])
		point=0;
	else
		point=family_map[player->query("id")];
	if(point<0)
		msg="你太令"+family_name+"失望了，照此下去，你在下次"+family_name+"大会上必受重罚。";
	else
		msg="你要继续努力，争取在下次"+family_name+"大会上得到最佳评定。";
	message_vision(CYN "$n对$N说道：你为"+family_name+"所做的贡献为"+chinese_number(point)+"点。"+msg+"\n"NOR, player, master);
	if(!menpai_ob=find_object(JOB_DIR+"job_menpai"))
		menpai_ob=new(JOB_DIR+"job_menpai");
	//write("here");
	if(!objectp(menpai_ob)) return 0;
	menpai_ob->restore();
	
	family_map=menpai_ob->query_assess_basenum(family_name);
	if(!undefinedp(family_map["family_assess_num"]))
	{
		point=family_map["family_assess_num"];
		message_vision(CYN "$n说道：当"+family_name+"贡献度达到"
		+chinese_number(point)+"时，就召开下次的"+family_name+"大会。\n"NOR, player, master);
	}
	if(objectp(menpai_ob))
		destruct(menpai_ob);
	if(objectp(job_data))
		destruct(job_data);



}

