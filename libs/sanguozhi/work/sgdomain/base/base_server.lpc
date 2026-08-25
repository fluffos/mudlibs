// base_server.c to create all the virtual rooms for the base
// by fire on Jan 30, 2000
#include <security.h>
#define FROOM( x , y , z) "/sgdomain/base/base_server/"+ x +"/"+ y +"/"+ z
#define RFILE( x ) "/sgdomain/base/room/"+ x 
#define CONTROL "/sgdomain/base/control"

mixed create_control(string p_area,string f_id) {
	mixed * bases;
	bases=AREA_D->get_area(p_area,"base");

	if(!arrayp(bases)) return 0;
	if(member_array(f_id,bases)==-1) return 0;

	return new(CONTROL,p_area,f_id);
}
void add_objs(object r,mixed ob) {
	r->set_objects(ob);
}
object create_base_room(string p_area,string f_id,string r_id) {
	object o_front;
	mapping room;
	object o_rom;
	string room_file,*exit;
	string *npcs;

	o_front=SGBASE(p_area,f_id);

	if(!objectp(o_front)) return 0;
	room=o_front->get_room(r_id);

	if(!mapp(room)) return 0;

	room_file=RFILE( room["t"] );

	o_rom = new(room_file);

	if(!objectp(o_rom)) return 0;

	o_rom->init_para(p_area,f_id,r_id,room["t"]);

	exit=keys(room["e"]);
	foreach(string e in exit) {
		if(room["e"][e][0]=='/') 
			o_rom->add_exit(e,room["e"][e]);
		else
			o_rom->add_exit(e,FROOM(p_area,f_id,room["e"][e]));
	}

	o_rom->set_objects(room["o"]);


	npcs=o_front->check_npc("room",r_id); 
	if(sizeof(npcs)) {
		foreach(string npc in npcs) {
			object o_n;
			o_n=o_front->find_npc(npc);
			if(objectp(o_n)) continue;
			o_n=o_front->load_npc(npc);
			if(objectp(o_n)) 
				o_n->move(o_rom);
		}
	}

   	return o_rom;
}
object virtual_create(string arg)
{
	object room;

	string *ids;
	string p_area,f_id,r_id;

	ids=explode(arg,"/");
	
	p_area=ids[0];
	f_id=ids[1];
	r_id=ids[2];
	if(r_id == "control") // the open area
		room = create_control(p_area,f_id);	
	else 
		room=create_base_room(p_area,f_id,r_id);
	return room;
}
// Disappear if no longer needed
protected void clean_up() {
	return 0; // don't want it is destroyed
}

