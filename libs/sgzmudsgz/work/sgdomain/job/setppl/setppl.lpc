// the job of setppl
// by Listen on July 2001
//this file should be in /sgdomain/job/setppl/setppl.c
// purpose of this file is to assign the setppl job to a player
mixed job(string m_id,string officer_id)
{
   string m_area=CHAR_D->get_char(officer_id,"area"); //get the officer(taishou)'s city
   string m_nation=CHAR_D->get_char(officer_id,"nation");//get the officer's nation

	object o=find_body(m_id);
	if(!objectp(o)) return "$N对$T道：内部系统错误。\n";
	
	if(CHAR_D->get_char(m_id,"level")<4 || CHAR_D->get_char(m_id,"ranknation")==0)
		return "$N对$T道：$R当前的官职无法申请设置间谍的工作。 \n";
		
	if(o->query_job("setppl","status")=="begin")
		return "$N对$T道：你申请的间谍任务还没有完成呢。\n";
//fobidden from NPC country
	if (CHAR_D->get_char(m_nation,"type")==TYPE_NPC) //king is a npc
		return "$N对$T道：本国国王禁止执行设置间谍任务。\n";
//try to reduce 50 soldier from the city
	if(!AREA_D->reduce_soldier(m_area,"sum",50))
		return "$N对$T道：本地没有足够的士兵去执行设置间谍任务。\n";

//assign the job to the player
	o->add_job("setppl");
	o->set_job("setppl","status","begin");
	o->set_job("setppl","memo","设置间谍");

	return "$N对$T道：那就麻烦$R去执行设置间谍的任务。\n有困难就用 help setppl。\n";
}
	


