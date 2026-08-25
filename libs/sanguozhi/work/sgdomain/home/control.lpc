#include <security.h>

#define SAVE_PATH "/data/home/"
#define FROOM( x , y ) "/sgdomain/home/home_server/"+ x +"/"+ y
#define PIC_PATH "/sgdomain/home/pic/"
#define NPC_SERVER "/sgdomain/home/npc_server/"

inherit M_ACCESS;

protected string p_id,p_area,h_id; 

protected mapping rooms=([]);
protected mapping npcs=([]);

protected string p_savefile="";
void scan_npc();
string set_area(string a);

void save_data();

//================================= npc part ================================
mixed check_npc(string par, mixed val) {
	string *ns;
	ns=keys(npcs);
	ns=filter_array(ns,(: npcs[$1][$(par)]==$(val) :));
	return ns;
}
mixed get_npc(string r_id,string para) {
	if(r_id=="list") return keys(npcs);
	if(r_id=="size") return sizeof(npcs);

	if((!r_id)||(r_id=="all")||(r_id=="")) return npcs;
	if(!npcs[r_id]) return 0;
	if(!para||(para=="")) return npcs[r_id];
	
	return npcs[r_id][para];
}

mixed set_npc(string r_id, string para,mixed val) {
	if(!mapp(npcs[r_id])) return "no such npc\n";
	npcs[r_id][para]=val;
	if(val==0) 
		map_delete(npcs[r_id],para);
	save_data();
	return npcs[r_id];
}
mixed remove_npc(string r_id) {
	if(!mapp(npcs[r_id])) return "no such npc\n";
	map_delete(npcs,r_id);
	save_data();
	return 1;
}
string new_npc_id() {
	string id;
	int i;
	i=1;
	id="npc "+i;
	while (mapp(npcs[id])) {
		i++;
		id="npc "+i;
	}
	return id;
}
mixed add_npc(object o) {
	mapping o_info;
	string id;
	o_info=o->get_info();
	id=new_npc_id();
	npcs[id]=o_info;
	scan_npc();
	save_data();
	return npcs[id];
}
mixed find_npc(string id) {
	return find_object(NPC_SERVER+p_id+"/"+id);
}
mixed load_npc(string id) {
	return load_object(NPC_SERVER+p_id+"/"+id);
}
mixed update_npc(string id) {
	object o,env;
	o=find_npc(id);
	if(objectp(o)) {
		env=o->query_room();
		destruct(o);
		o=load_npc(id);
		o->move(env);
	}
	else
		o=load_npc(id);
	return o;
}

//================================ room part ================================

mixed check_room(string par, mixed val) {
	string *ns;
	ns=keys(rooms);
	ns=filter_array(ns,(: rooms[$1][$(par)]==$(val) :));
	return ns;
}

mixed get_room(string r_id,string para) {
	if(r_id=="list") return keys(rooms);
	if(r_id=="size") return sizeof(rooms);
	if((!r_id)||(r_id=="all")||(r_id=="")) return rooms;
	if(!rooms[r_id]) return 0;
	if(!para||(para=="")) return rooms[r_id];
	
	return rooms[r_id][para];
}
mixed set_room(string r_id, string para,mixed val) {
	if(!mapp(rooms[r_id])) return "no such room\n";
	rooms[r_id][para]=val;
	if(val==0) 
		map_delete(rooms[r_id],para);
	save_data();
	return rooms[r_id];
}

string new_room_id() {
	string id;
	int i;
	i=1;
	id="room"+i;
	while (mapp(rooms[id])) {
		i++;
		id="room "+i;
	}
	return id;
}

mixed load_room(string r_id) {
	return load_object("/sgdomain/home/home_server/"+p_id+"/"+r_id);
}

mixed update_room(string r_id) {
	object v,*os,o;
	o=load_room(r_id);
	os=all_inventory(o);
	v=load_object(VOID_ROOM);
	if(sizeof(os)) {
		foreach(object oo in os) {
			oo->move(v);
		}
	}
	destruct(o);
	o=load_room(r_id);
	if(sizeof(os)) {
		foreach(object oo in os) {
			oo->move(o);
		}
	}
	return o;
}
mixed remove_room(string id) {
	string nb;
	object o_here,o_nb,*os;
	string dir,oppdir;
	if(!rooms[id]) return 0;
	if(sizeof(rooms[id]["e"])>1) return 0;
	dir=keys(rooms[id]["e"])[0];
	nb=rooms[id]["e"][dir];

	oppdir=DIRECTION_D->oppdir(dir);

	nb=rooms[id]["e"][dir];

	map_delete(rooms[nb]["e"],oppdir);
	o_here=load_room(id);
	o_nb=load_room(nb);
	os=all_inventory(o_here);
	if(sizeof(os)) {
		foreach(object o in os) {
			o->move(o_nb);
		}
	}
	destruct(o_here);
	map_delete(rooms,id);
	update_room(nb);
	save_data();
	scan_npc();
	return 1;

}
mixed add_room( string here_id,string h_dir,string opp_dir,string typ,string nam) {
	string r_id;
	r_id=new_room_id();
	rooms[r_id]=([]);
	rooms[r_id]["o"]=([]);
	rooms[r_id]["t"]=typ;
	rooms[r_id]["b"]=nam;
	rooms[r_id]["l"]="";
	rooms[r_id]["e"]=([opp_dir:here_id]);

	rooms[here_id]["e"][h_dir]=r_id;
	save_data();
	update_room(here_id);
	return r_id;
}

void init_rooms() {
	rooms=([]);
	rooms["front"]=([]);
	rooms["front"]["b"]="%^H_GREEN%^"+CHAR_D->get_char(p_id,"name")+"的家%^RESET%^";
	rooms["front"]["l"]=read_file(PIC_PATH+h_id+".pic" );

	rooms["front"]["e"]= ([
		"out" : AREA_D->get_area(p_area,"path")+
			AREA_D->get_area(p_area,"go"), 
		"enter" : FROOM(p_id,"enter"),
		]);

	rooms["front"]["t"] = "front" ;

	rooms["front"]["o"]= (["/sgdomain/home/out_door" : ({1,p_id,"enter"}) ]);

	rooms["enter"]=([]);
	rooms["enter"]["b"]="%^H_GREEN%^门厅%^RESET%^";
	rooms["enter"]["l"]="这里是"+CHAR_D->get_char(p_id,"name")+
	  "家的门厅。\n";
	rooms["enter"]["e"]= (["out" : "front"]);
	rooms["enter"]["t"] = "hall" ;
	rooms["enter"]["o"]= (["/sgdomain/home/out_door" : ({1,p_id,"out"}) ]);
	npcs=([]);
	save_data();
}

//============================== system part ======================================
void get_save_file() {
	if(!p_id) p_savefile="";
	p_savefile=SAVE_PATH+p_id[0..0]+"/"+p_id;
}
void save_data()
{
	if(!sizeof(p_savefile)) return;
       unguarded(1, (: save_object, p_savefile :));
}
void restore_data() {
    if(!sizeof(p_savefile)) return;
      unguarded(1, (: restore_object, p_savefile, 1 :));
}

void scan_npc() {
	string *nps;
	nps=keys(npcs);
	if(!sizeof(nps)) return;
	foreach(string np in nps) {
		if((!stringp(npcs[np]["room"]))||(!mapp(rooms[npcs[np]["room"]]))) {
			npcs[np]["room"]="front";
			save_data();
		}
		if(!stringp(npcs[np]["pre_id"])) {
			npcs[np]["pre_id"]="free";
			save_data();
		}
	}
}
void create(string id) {
	mapping home;
	if(!stringp(id)) return;
	call_out("check_me",300);
	p_id=id;
	
	set_privilege(1);

	get_save_file();
	restore_data();	
	p_id=id;

	home=CHAR_D->get_char(p_id,"h");
	if(!mapp(home)) return ;
	h_id=home["id"];
	p_area=home["a"];
	set_area(p_area);
	if(sizeof(rooms)<2) init_rooms();
	scan_npc();
}
int need_clean() {
	string *rs;
	rs=users()->query_body()->query_room()->get_owner();
	if(member_array(p_id,rs)==-1) return 1; // no user in room
	return 0;
}
void clean_me() {
	string *rs;
	object o_r;
	rs=keys(rooms);
	foreach(string r in rs) {
		o_r=find_object(FROOM(p_id,r));
		if(objectp(o_r))
			destruct(o_r);
	}
	remove_call_out("check_me");
	destruct(this_object());
}

void check_me() {
	remove_call_out("check_me");
	call_out("check_me",300);
	if(need_clean())
		clean_me();	
}

int is_home_control() {
	return 1;
}
string get_owner() {
	return p_id;
}
string get_area() {
	return p_area;
}
string set_area(string a) {
	p_area=a;
	if(mapp(rooms["front"])) {
		rooms["front"]["e"]["out"]=AREA_D->get_area(p_area,"path")+
			AREA_D->get_area(p_area,"go");
	}
	save_data();
}
string set_id(string d) {
	p_id=d;
	save_data();
}
//=======================================================================
mixed has_zhangfang() {
	string *tmp,*tmp2;
	int st;
	tmp=check_room("t", "zhangfang");
	if(!sizeof(tmp)) 
		return "没有帐房。";
	st=get_room(tmp[0],"status");
	if((st>0)&&(st<50)) 
		return "帐房太破旧了。";
	tmp2=check_npc("pos","zfxs");
	if(!sizeof(tmp2))
		return "没有帐房先生。";
	if(get_npc(tmp2[0],"room")!=tmp[0])
		return "帐房先生不在帐房里。";
	return 1;
}
mixed has_chufang() {
	string *tmp,*tmp2;
	int st;
	tmp=check_room("t", "kitchen");
	if(!sizeof(tmp)) 
		return "没有厨房。";
	st=get_room(tmp[0],"status");
	if((st>0)&&(st<50)) 
		return "厨房太破旧了。";
	tmp2=check_npc("pos","dcs");
	if(!sizeof(tmp2))
		return "没有大厨师。";
	if(get_npc(tmp2[0],"room")!=tmp[0])
		return "大厨师不在厨房里。";
	return 1;
}
