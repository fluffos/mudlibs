// This is the virtual creater of the museum rooms
// by fire on June 17, 2000
#define MUSEUM_ROOM "/sgdomain/museum/museum_room"
string room(int x,int y,int f) {
	return "/sgdomain/museum/control/"+x+"_"+y+"_"+f;
}
object create_museum_room(int x,int y,int f) {
	int c;
	object o_rom;
	string r_id=MUSEUM_D->get_string_index(x,y,f);

	o_rom=new (MUSEUM_ROOM);
	if(!objectp(o_rom)) return 0;
	o_rom->set_string_index(r_id);
	o_rom->set_pos(x,y,f);
	o_rom->set_area("museum");
	if(stringp(MUSEUM_D->get_room(r_id,"b")))
		o_rom->set_brief("%^H_GREEN%^"+MUSEUM_D->get_room(r_id,"b")+"%^RESET%^");
	else
		o_rom->set_brief("%^H_GREEN%^走廊%^RESET%^");
	o_rom->set_long("");

	c=MUSEUM_D->get_connect_type (x,y,f,"e");
	if(c) o_rom->add_exit("east",room(x+1,y,f));

	c=MUSEUM_D->get_connect_type (x,y,f,"w");
	if(c) o_rom->add_exit("west",room(x-1,y,f));

	c=MUSEUM_D->get_connect_type (x,y,f,"n");
	if(c) o_rom->add_exit("north",room(x,y-1,f));

	c=MUSEUM_D->get_connect_type (x,y,f,"s");
	if(c) o_rom->add_exit("south",room(x,y+1,f));

   	if(r_id==MUSEUM_D->get_enter_room())
		o_rom->add_exit("out","/sgdomain/museum/yard");
	return o_rom;
}
object virtual_create(string arg)
{
	object room;

	string *ids;
	int x,y,f;

	ids=explode(arg,"_");
	if(sizeof(ids)!=3) return 0;

	x=to_int(ids[0]);
	y=to_int(ids[1]);
	f=to_int(ids[2]);

	if(!MUSEUM_D->room_exist(x,y,f))
		return 0;
	
	room=create_museum_room(x,y,f);
	return room;
}
// Disappear if no longer needed
protected void clean_up() {
	return 0; // don't want it is destroyed
}

