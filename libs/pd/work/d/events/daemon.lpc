//  Master System
//  Used to Handle Quest rooms when quest is over or not yet started.

#define SAVE seteuid("EventSave"); save_object("/adm/save/misc/eventmaster")
#define RESTORE seteuid("EventSave"); restore_object("/adm/save/misc/eventmaster")

mapping events;

void start_event(string event, int i) { 
   if(!events[event]) events[event]=([]);
   events[event]["started"]=i; 
   SAVE;
}

int query_start(string event) { return events[event]["started"]; }

//  If an event has certain phases
void set_phase(string event, mixed phase, mixed val) {
   events[event][phase]=val;
   SAVE;
}

mixed query_phase(string event, mixed phase) {
   return events[event][phase];
}

void create() { RESTORE; }

