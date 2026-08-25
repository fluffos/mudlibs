inherit OUTDOOR_ROOM;
inherit __DIR__+"base";
string get_long();
void base_init() {
	object o_h=get_master();
	object o_leader;
	string p_id=o_h->get_leader();
	set_brief(AREA_D->get_area(p_area,"name")+BASE_D->get_base(f_id,"name"));
	set_long(get_long());
	set_area(p_area);
	if(CHAR_D->char_exist(p_id)) {
		o_leader=new(PBASE+"npc/leader",p_area,f_id);
		if(objectp(o_leader))
			o_leader->move(this_object());
	}

}
string get_long() {
	object oh;
	string ret=get_base_room_long();
	string ext;
	int level;
/*	oh=get_master();
	level=oh->get_level();
	switch(level) {
	case 1:
		ext= "  这是一个新建的农场，周围还没有开发出多少田地。\n\n";
		break;
	case 2:
		ext= "  一个小小的农场，周围有几片农田。\n\n";
		break;
	case 3:
		ext= "  一个大农场，周围都是连绵的田野。\n\n";
		break;
	default:
		ext="一个巨大无比的农场，放眼望去，周围的田地一望无继。\n\n";
	}
	return ret+"\n"+ext;
*/
	if(!sizeof(ret)) ret=" \n";
	return ret;
}