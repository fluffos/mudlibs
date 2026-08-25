// this will be used to handle all the area rooms
// by fire on July 17, 1999
#include <security.h>
#define FRONT_ROOM "/sgdomain/home/front_room"
#define FROOM( x , y ) "/sgdomain/home/home_server/"+ x +"/"+ y
#define RFILE( x ) "/sgdomain/home/room/"+ x 
#define CONTROL "/sgdomain/home/control"

mixed create_control(string p_id) {
	mapping home;
	home=CHAR_D->get_char(p_id,"h");
	if(!mapp(home)) return 0;
	return new(CONTROL,p_id);
}
void add_objs(object r,mixed ob) {
	r->set_objects(ob);
}
object create_home_room(string p_id,string r_id) {
	object o_front;
	mapping room;
	object o_rom;
	string room_file,*exit;
	string p_area;
	string *npcs;

	o_front=load_object(FROOM(p_id,"control"));

	if(!objectp(o_front)) return 0;
	room=o_front->get_room(r_id);


	if(!mapp(room)) return 0;

	room_file=RFILE( room["t"] );


	o_rom = new(room_file);

	if(!objectp(o_rom)) return 0;

	p_area=o_front->get_area();
	o_rom->set_type(room["t"]);
	o_rom->set_brief(room["b"]);
	o_rom->set_long(room["l"]);
	o_rom->set_owner(p_id);
	o_rom->set_area(p_area);

	exit=keys(room["e"]);
	foreach(string e in exit) {
		if(room["e"][e][0]=='/') 
			o_rom->add_exit(e,room["e"][e]);
		else
			o_rom->add_exit(e,FROOM(p_id,room["e"][e]));
	}
	if(r_id=="enter")
		call_out("add_objs",0,o_rom,room["o"]);
	else
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
	string p_id,r_id;

	ids=explode(arg,"/");
	
	p_id=ids[0];
	r_id=ids[1];
	
	if(r_id == "control") // the open area
		room = create_control(p_id);	
	else 
		room=create_home_room(p_id,r_id);
	return room;
}
// Disappear if no longer needed
protected void clean_up() {
	return 0; // don't want it is destroyed
}
