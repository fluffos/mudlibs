// outdoor by fire
#include <hooks.h>
inherit DOOR;
string do_desc();

void later_set_up(string p_id,string dir) {
	tell_user("fire","dir is "+dir+"\n");
	setup_door(p_id,dir);
}
void setup(string p_id,string dir) {
	
	set_id("door", "大门");

	setup_door(p_id,dir);

//	call_out("later_set_up",1,p_id,dir);
	set_locked("locked",p_id);

	set_in_room_desc((: do_desc :));
}
string do_desc() {
	if(stringp(query_locked()))
		return "大门被牢牢着锁着。";
  	if (query_closed())
		return "大门紧闭着。";
	return "大门敞开着。";
}
mixed direct_lock_obj_with_obj(){
	if(stringp(query_locked()))
		return "大门已经锁好了。\n";
	if(!query_closed())
		return "门要先关上才能锁。\n";
	return 1;
}

mixed direct_unlock_obj_with_obj(object ob_d, object ob_k) {
	if(!stringp(query_locked()))
		return "大门没有锁呀。\n";
	return 1;
}