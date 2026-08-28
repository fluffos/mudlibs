/*
 * Save Daemon v1.0
 *
 * The Complete room, and object saving daemon.
 * Handles giving out, and processing of Save IDS
 * Which are used as unique parts of a save filename
 * Helios 11/28/98
 * DarkeLIB 2.0
 *
 */

#include <security.h>
#include <dirs.h>
#include <rooms.h>
#include <daemons.h>


string *unique_ids;
string *save_rooms;


//begin func define
int add_save_room(mixed room);
int remove_save_room(mixed room);
void save_ids();
void save_save_rooms();
string get_sid();
int unregister_sid(object ob);
//end func define

string *query_save_rooms(){return save_rooms;}

void move_bugs(string bn, string id){
    int a;
    object *obs;

    obs = children(bn);
    for(a=0;a<sizeof(obs);a++){
        if(obs[a]->query_sid2() == id){
            message("info", "Sid: "+id, find_living("parnell"));
            if(environment(obs[a]))
                message("info", "Location: "+base_name(environment(obs[a])), find_living("parnell"));
            obs[a]->move(environment(find_living("parnell")));
        }
    }
}

int run_fix(){
    object *obs;
    string *ids, sid;
    int a, c;

    c = 0;
    ids = ({});
    obs = objects();
    for(a=0;a<sizeof(obs);a++){
        if(!obs[a] || !objectp(obs[a]) || obs[a]->query_room() || query_shadowing(obs[a])) continue;
        sid = obs[a]->query_sid2();
        if(sid){
            if(member_array(sid, ids) != -1){
                move_bugs(base_name(obs[a]), sid);
                c = 1;
                return c;
            }
            ids += ({ sid });
        }
    }
    return c;
}

int is_save_room(mixed room){
    string tmp;
    if(objectp(room))
        tmp = base_name(room);
    else
        tmp = room;
    if(member_array(tmp, save_rooms) != -1) return 1;
    else return 0;
}

int add_save_room(mixed room){
    string tmp;
    object r;

    if(objectp(room))
        tmp = base_name(room);
    else
        tmp = room;
    r=find_object_or_load(tmp);
    if(!r || !r->query_room())
        return 0;
    r->set_save_room(1);
    if(member_array(tmp, save_rooms) == -1)

    save_rooms += ({ tmp });
    save_save_rooms();
    r->save();
    return 1;

}

int remove_save_room(mixed room){
    string tmp;
    object r;

    if(objectp(room))
        tmp = base_name(room);
    else
        tmp = room;
    r=find_object_or_load(tmp);
    if(!r || !r->query_room())
        return 0;
    r->set_save_room(0);
    if(member_array(tmp, save_rooms) != -1)
        save_rooms = save_rooms - ({ tmp });
    unregister_sid(r);
    save_save_rooms();
    return 1;
}

void compat_stuff(){
    int i;
    string tmp;

    for(i=0;i<sizeof(save_rooms);i++){
        reset_eval_cost();
        tmp = save_rooms[i];
        SAVE_ITEMS_D->remove_room(tmp);
    }
    return;
}

void save_ids() {
   seteuid(UID_SECURE_DAEMONSAVE);
   write_file(DIR_SECURE_DAEMONS_SAVE+"/unique_ids.v", save_variable(unique_ids), 1);
   seteuid(getuid());
   return;
}

void save_save_rooms() {
   seteuid(UID_SECURE_DAEMONSAVE);
   write_file(DIR_SECURE_DAEMONS_SAVE+"/save_rooms.v", save_variable(save_rooms), 1);
   seteuid(getuid());
   return;
}

string get_sid() {
    string type, tmp, *tmp2, sid2, *tmp3, tmp4;
    object prev;
    int i;

    prev = previous_object();
    sid2 = DIR_ADM_SAVE+"/";
    if(prev->query_room())
        type = "room";
    else
        if(prev->is_pet())
            type = "pet";
        else
            if(prev->is_rune())
                type = "rune";
            else
                type = "obj";
    sid2 += type;
    mkdir(sid2);
    sid2 += "/";
    if(type == "room")
	{
  //      seteuid(UID_ROOT);
        type = file_name(prev);
        tmp2 = explode(type, "/");
        type = sid2;
        for(i=0;i<(sizeof(tmp2)-1);i++)
		{
            type = type + tmp2[i];
            if(file_size(type) != -2)
                mkdir(type);
            type +="/";
            message("debug", "Make dir: "+type, find_player("parnell"));
        }
        seteuid(getuid());
        tmp = file_name(prev);
        tmp = sid2+tmp[1..sizeof(tmp)];
        message("debug", "Room sid: "+tmp, find_player("parnell"));
        return tmp;
    }
    seteuid(UID_ROOT);
    type = base_name(prev);
    tmp2 = explode(type, "/");
    type = sid2;
    for(i=0;i<(sizeof(tmp2));i++){
        type = type + tmp2[i];
        if(file_size(type) != -2)
            mkdir(type);
        type +="/";
    }
    seteuid(getuid());
    tmp = base_name(prev);
    tmp = sid2+tmp[1..sizeof(tmp)];
    tmp = tmp + "/";
    tmp3 = get_dir(tmp);
    tmp4 = tmp2[sizeof(tmp2)-1];
    i = 1;
    while(member_array(tmp4+"_"+i+".o", tmp3) != -1){
        i++;
    }
    tmp = tmp + tmp4 + "_" + i;
message("debug", "Item sid: "+tmp, find_player("parnell"));
    return tmp;
}

int unregister_sid(object ob) {
    string key;
    object *o;
    int i;

    key = ob->query_sid2();
    if(!key)
        return 0;
    o = all_inventory(ob);
    for(i=0;i<sizeof(o);i++){
        reset_eval_cost();
        unregister_sid(o[i]);
    }
    ob->reset_sid();
    unique_ids = unique_ids - ({ key });
    rm(key+".o");
    save_ids();
    return 1;
}

void create() {
    unique_ids = ({});
    save_rooms = ({});
    seteuid(UID_SECURE_DAEMONSAVE);
    if(file_exists(DIR_SECURE_DAEMONS_SAVE+"/unique_ids.v"))
        unique_ids = restore_variable(read_file(DIR_SECURE_DAEMONS_SAVE+"/unique_ids.v"));
    if(file_exists(DIR_SECURE_DAEMONS_SAVE+"/save_rooms.v"))
        save_rooms = restore_variable(read_file(DIR_SECURE_DAEMONS_SAVE+"/save_rooms.v"));
    seteuid(getuid());
    return;
}

