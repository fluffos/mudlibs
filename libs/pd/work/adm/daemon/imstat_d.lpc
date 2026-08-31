#define SAVE "/adm/save/daemons/imstats"
mapping stat;

void create() {
   stat=([]);
   restore_object(SAVE);
}

void save();

int get_new_ses_id() {
  return time();
}

void init_session(object im) {
   int id;
   string name;
   name = im->query_name();
   id = get_new_ses_id();
   im->set("ses_id", id);
   if(!stat[name]) stat[name]=(["used_commands":([]), "session":([ id:([]) ]), "total_time":0]);
   stat[name]["session"][id]=([]);
   stat[name]["session"][id]["used_commands"]=([]);
   stat[name]["session"][id]["time_start"]=time();
   stat[name]["session"][id]["writable"]=1;
   stat[name]["last_session"]=id;
   save();
}

void close_session(object im) {
   int id;
   string name;
   id=im->query("ses_id");
   name=im->query_name();
   if(!stat || !stat[name] || !stat[name]["session"] || !stat[name]["session"][id]) {
     write("Unable to close session."); 
     return;
   }
   stat[im->query_name()]["session"][id]["writable"]=0;
   stat[im->query_name()]["session"][id]["time_end"]=time();
   stat[im->query_name()]["total_time"] += 
     stat[im->query_name()]["session"][id]["time_end"] - stat[im->query_name()]["session"][id]["time_start"];
   stat[im->query_name()]["last_session"]=id;
   save();
}

int add_stat(string id, string command, int time) {
   int ses_id;
   object o;
   if(!o=find_player(id)) return notify_fail("Cannot add stats for an offline player.");
   ses_id = o->query("ses_id");
   if(!ses_id || !stat[id] || !stat[id]["session"] || !stat[id]["session"] || !stat[id]["session"][ses_id]) init_session(o);
   ses_id = o->query("ses_id");
   if(!stat[id]["session"][ses_id]["writable"]) return notify_fail("Session is not writable.  Please log back in.");
   stat[id]["used_commands"][command] += 1;
   stat[id]["session"][ses_id]["used_commands"][command] += 1;
   save();
}

mapping get_session_stats(string name, int id) {
   mapping m;
   if(!stat[name]) return 0;
   if(!stat[name]["session"][id]) return 0;
   m = stat[name]["session"][id];
   return m;
}

mapping get_average_stats(string name, int id) {
   mapping m;
   if(!stat[name]) return 0;
   m=([]);
   m["used_commands"]=stat[name]["used_commands"];
   m["last_session"]=stat[name]["last_session"];
   m["total_time"]=stat[name]["total_time"];
   if(!m["used_commands"]) m["used_commands"]=([]);
   return m;
}

mapping get_sessions(string name) {
   if(!stat[name]) return 0;
   if(!stat[name]["session"]) return 0;
   return stat[name]["session"];
}

void save() {
   save_object(SAVE);
}

