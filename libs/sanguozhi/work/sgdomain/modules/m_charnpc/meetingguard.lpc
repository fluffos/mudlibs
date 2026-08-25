// by fire on june 2000
inherit M_CHAR;
inherit LIVING;
inherit M_BLOCKEXITS;
string p_area,p_nation,p_dir,p_room;
int task_id;
nosave protected string *chaois=({
    "一群小孩在房子里跑着，跳着，要着喜糖。\n",
    "一帮乐师的唢呐「滴滴哒哒」的吹得好不热闹。\n",
    "一人高喊，新娘笑了，众人哄堂大笑。\n",
    "很多人挤在门口，想看个究竟。\n",
    "又来了一队送礼的，各种喜礼都用大红纸包着。\n",
    "一个帐房先生手里拿着算盘，劈里啪啦地计算着礼金的数量，高兴得嘴都合不拢。\n",
    "爆竹「乒乒乓乓」地响个不停，好象比过年还热闹。\n",
    "$N点头哈腰，对进出贵宾不断行礼致敬。\n",
    "$N对新来的宾客道：有什么礼物就交给我吧。\n",

});

private mixed handle_blocks( string dir )
{
        string p_id;

		if(dir!=p_dir) return 0;
	p_id=this_body()->query_primary_id();
	if(CHAR_D->get_char(p_id,"nation")==p_nation) {
		this_object()->targetted_action(
		"$N对$T鞠躬道：$m$R，里面请。\n",this_body());
		return 0;
	}
        return ::handle_blocks(dir);    
}

void setup()
{
    set_name("guard", "卫兵");
	add_id("meeting guard");
    set_gender(1);
    set_in_room_desc("\n一个全副武装的%^H_RED%^卫兵%^RESET%^(guard)\n");

    call_out("check",5);

    set_block_action( "$N『呛啷』一声拔出钢刀，指着$T厉声喝道：大胆$r，胆敢前来刺探军情。\n");
}

string long() {
	return
"一个全副武装的%^H_RED%^卫兵%^RESET%^\n";
}

void finish() {
	remove_call_out("check");	
	this_object()->simple_action("$N离开了。\n");	
	this_object()->remove();
}
void chaois() {
	string msg;
	msg=chaois[random(sizeof(chaois))];
	this_object()->simple_action(msg);
}

void check() {
	remove_call_out("check");
	call_out("check",5+random(5));
	if(!mapp(TASK_D->get_task(task_id))) {
		finish();
		return;
	}
//	chaois();
}
int set_position(string area,int task,string room,string dir) {
	string meetroom;
	p_area=area;
	p_nation=AREA_D->get_area(p_area,"nation");
	p_room=room;
	p_dir=dir;
	task_id=task;

    add_block(p_dir);
	
	remove_call_out("check");
	call_out("check",3);
	return 1;
}
int is_meetingguard() {
	return 1;
}
int query_clean_up() {
	return 1; // if p_life<200 can't clean up
}

