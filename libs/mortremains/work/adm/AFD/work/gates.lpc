// gates.c
// The standard gate object. Any room (or other object if you like) that
// contains a gate needs to inherit this file.
// Originally written by Rusty@TMI-2, 11-92.
// He lost his access in January 1993. Mobydick@TMI-2 went back and whipped
// the code into shape for the release.
// Originally part of room.c. Mobydick seperated in into two files, rooms
// and gates, on 2-17-93. This was done to save memory since most rooms do
// not contain gates and do not need this code.
// (06-14-96) Chronos tackles the door project, begins recoding this file.
//            - Added in bashing.  Bash is how strong you have to be
//              in order to bash the fucker down.
// (09-17-96) Chronos search/replaced door for gate.  :D

// Prototypes for functions defined in room.c.
varargs void set (string foo, mixed data, string perms) ;
mixed query (string foo) ;
void add (string foo, mixed data) ;

// Homegrown prototypes.
void set_desc (string dir) ;
void initialize_link (string dir) ;

// This function creates a gate for a previously existing exit.
// If all you want is a gate that opens and closes, this is enough.
// Ex. create_gate("east", "west", "A simple wooden gate");
//

varargs void // dir, linked_exit, gate_desc, status, locked, bash
create_gate(string dir, string linked_exit, string gate_desc, 
   string gate_stat, string lock, int bash) {
   set("gates/"+dir+"/linked", linked_exit);
   set("gates/"+dir+"/lock", lock) ;
   if (!gate_desc) gate_desc = 
        "An iron gate.  There is nothing special about it.";
   set("gates/"+dir+"/desc", gate_desc);
   set("gates/"+dir+"/status", gate_stat) ;
   set("gates/"+dir+"/bash", bash);
   set_desc(dir) ;
   initialize_link(dir) ;
   return;
}

// A function to set various gate attributes.
// For value use "open" or "closed" or "locked"..

void set_status(string dir, string value) {
   if (!value) value = "closed";
   set("gates/"+dir+"/status", value);
   set_desc(dir);
}

void set_desc( string dir ) {
   add( "item_desc", ([ dir + " gate" :
        query("gates/"+dir+"/desc") + ". It is "+ 
        query("gates/"+dir+"/status") +".\n" ]) ) ;
   return;
}

// This function initializes a gateway linkage. When you create a new
// gate with a link, this function queries the linked gate and sets the
// status of this gate to match the status of that gate.

void initialize_link (string dir) {
  int i;
  string ob_dir, ob_status, link ;
  object ob;
  mapping gates;
   
  link = this_object()->query("gates/"+dir+"/linked") ;
  if (link && link!="none") {
    if (ob = find_object((string)query("exits/"+dir))) {
      ob_dir = (string)query("gates/"+dir+"/linked");
      ob_status = (string)ob->query("gates/"+ob_dir+"/status") ;
      set_status(dir, ob_status);
    }
  }
  return;
}

// This function updates a gateway link. When called, it finds the gate
// linked to this gate and sets that gate's status to match this gate.
// The difference between initialize_link and update_link is that initialize
// causes this room's gate to match the remote gate, but update causes the
// remote gate to match this room's gate.

void update_link (string dir) {
  int i;
  string link ;
  string ob_dir;
  string gate_stat ;
  string old_stat ;
  object ob;

  link = this_object()->query("gates/"+dir+"/linked") ;
  if (link && link != "none") {
    if (ob = find_object((string)query("exits/"+dir))) {
      gate_stat = (string)query("gates/"+dir+"/status") ;
      ob_dir = (string)query("gates/"+dir+"/linked");
      old_stat = (string)ob->query("gates/"+ob_dir+"/status") ;
      ob->set_status(ob_dir, gate_stat) ;
      switch (gate_stat) {
        case "open" : tell_room (ob, "The "+ob_dir+" gate swings open.\n") ;
                      break ;
        case "locked" : tell_room(ob,"You hear a clicking sound from the "+ob_dir+" gate.\n") ;
                        break ;
        case "closed" : if (old_stat=="locked") 
          tell_room (ob, "You hear a clicking sound from the "+ob_dir+" gate.\n") ;
          else tell_room (ob, "The "+ob_dir+" gate swings shut.\n") ;
          break ;
      }
    }
  }
  return;
}
/* EOF */
