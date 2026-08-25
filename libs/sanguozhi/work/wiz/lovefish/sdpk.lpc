// sdpk.c 煽动布告
inherit OBJ;
inherit M_GETTABLE;
string m_area;
string m_roomname;
int m_life;
void setup()
{   
    set_id("bugao", "%^YELLOW%^布告%^RESET%^");
    set_size(VERY_SMALL);
    set_gettable(1);
    set_in_room_desc("墙上贴着一张%^YELLOW%^布告%^RESET%^。\n");   
}
string long() {
	if(!AREA_D->area_exist(m_area)) {
		remove();
		return "";
	}
	return "一张煽动"+AREA_D->get_area(m_area,"name")+
          "居民的布告。\n";
}
void set_area(string area) {
	m_area=area;
}
void set_roomname(string r) {
	m_roomname=r;
}
mixed query_can_drop() {
	object rom;
	rom=this_body()->query_room();
	if(!AREA_D->area_exist(m_area)) {
		remove();
		return 0;
	}
	if(rom->get_area()!=m_area) 
		return "这张布告要贴到"+AREA_D->get_area(m_area,"name")+"。\n";
	if(rom->short()!=m_roomname) 
		return "这张布告要贴到"+m_roomname+"。\n";
	return 1;
}
void my_life() {
	object env;
	int safe;
        if(random(m_life)>1) {
		remove();
		return;
	}
	m_life++;
	env=environment(this_object());
	if((env->short()!=m_roomname)||(env->get_area()!=m_area)) {
		remove();
		return;
	}
	call_out("my_life",random(60)+60);
	safe=AREA_D->get_area(m_area,"safe");
	switch(random(4)) {
		case 0:
			CHANNEL_D->deliver_tell("rumor","system", 
			AREA_D->get_area(m_area,"name")+"出现煽动性布告，所幸居民没受影响。");
			return;

		case 1:
			safe++; 
			AREA_D->set_area(m_area,"safe",safe);
			CHANNEL_D->deliver_tell("rumor","system", AREA_D->get_area(m_area,"name")+
			"出现煽动性布告，但居民看破阴谋，当地安定提高了！");
			return;
		case 2:
			safe-=2; safe=bmax(0,safe);
			AREA_D->set_area(m_area,"safe",safe);
			CHANNEL_D->deliver_tell("rumor","system", 
  AREA_D->get_area(m_area,"name")+"出现煽动性布告，居民议论纷纷，当地安定下降了。");
			return;

		default :
			safe--; safe=bmax(0,safe);
			AREA_D->set_area(m_area,"safe",safe);
			CHANNEL_D->deliver_tell("rumor","system", 
AREA_D->get_area(m_area,"name")+"出现煽动性布告，居民议论纷纷，当地安定下降了。");
			return;
	}
}
mixed drop() {
	string m_id;
	string nat;
	int loy;

       this_body()->other_action(
		"$N看看左右没人，鬼鬼祟祟地从怀里掏出张布告，贴到墙上。\n");
	this_object()->move(this_body()->query_room());
	m_life=0;
        call_out("my_life",5);
	this_body()->start_busy(20,"你现在正忙着呢。\n");
//	call_out("drop_bugao",20);
	this_body()->set_job("bugao","status","done");
	m_id=this_body()->query_primary_id();

	nat=AREA_D->get_area(m_area,"nation");

	loy=CHAR_D->get_char_loyalty(m_id,nat);
	loy--; loy=bmax(1,loy);
	CHAR_D->set_char_loyalty(m_id,nat,loy);


        CHAR_D->set_char(m_id,"catch_time",time()+30);
        CHAR_D->set_char(m_id,"catch_file",PJOB+"bugao/bugao");
        CHAR_D->set_char(m_id,"catch_function","bugao_catch");
        CHAR_D->set_char(m_id,"catch_para",this_object());
        CHAR_D->set_char(m_id,"catch_area",m_area);

	CHANNEL_D->deliver_tell("rumor","system", 
		this_body()->query_chinese_id()+"在"+AREA_D->get_area(m_area,"name")+"张贴煽动性布告。");
       return "你把布告贴到墙上。\n";
}

/*void disapp() {
	remove();
}*/
mixed get() {
	string nat,id;
	nat=AREA_D->get_area(m_area,"nation"); 
	id=this_body()->query_primary_id();
	if(CHAR_D->get_char(id,"nation")!=nat)
		return "他国的事，还是少管。\n";
	this_body()->simple_action(
		"$N一把将布告从墙上撕了下来，揉成一团。\n");
	CHAR_D->set_char(id,"loyalty",CHAR_D->get_char(id,"loyalty")+1);
	remove();
//	call_out("disapp",1);
	return "你的忠诚提高了。\n";
}
/*void drop_bugao()
{
	this_object()->move(this_body()->query_room());
	this_body()->set_job("bugao","status","done");
	return;
}*/
