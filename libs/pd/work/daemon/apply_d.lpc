//  Daemon For Handling new Names and Removing names
//    -- Whit
#define OFILE "/adm/save/lans/lans"
#include <security.h>

mapping data;

void load_data() {
    data=0;
    seteuid(UID_LAN);
    restore_object(OFILE);
    seteuid(geteuid(this_object()));
    if(!data) data=([]);
}

void save_data() {
    seteuid(UID_LAN);
    save_object(OFILE);
    seteuid(geteuid(this_object()));
    data=0;
}

string *send_data(string owner) {
    string f;
    f=base_name(previous_object());
    load_data();
    if(owner=="listallnames") return keys(data);
    if(!data[owner]) return 0;
    if(!data[owner]["names"]) return ({});
    return (string *)data[owner]["names"];
}

varargs int add_name(string owner, string name, string ip) {
    if(!owner) return error("Wrong number of arguments to function add_name(string,string,int)\n");
    if(!name) return error("Wrong number of arguments to function add_name(string,string,int)\n");
    load_data();
    if(!data[owner]) data[owner]=([]);
    if(!data[owner]["names"]) data[owner]["names"]=({});
    data[owner]["ip"]=ip;
    data[owner]["names"]-= ({ name });
    data[owner]["names"]+= ({ name });
    save_data();
    return 1;
}

int remove_name(string owner, string name) {
    load_data();
    if(!data[owner]) data[owner]=([]);
    data[owner]["names"]-= ({ name });
    save_data();
    return 1;
}
//  If theres a flag, it will add the bypass.  
//   It none, it just checks.
int bypass_verify(object ob, int flag) {
    string n;
    n=ob->query_name();
    load_data();
    if(flag) {
	if(!data[n]) data[n]=([]);
	data[n]["bypass"]=1;
	data[n]["ip"]=query_ip_number(ob);
	save_data();
	return 1;
    }
    if(!data[n]) return 0;
    if(!data[n]["bypass"]) return 0;
    return 1;
}

string get_ip(string str) {
    load_data();
    return data[str]["ip"];
}

