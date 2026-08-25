//  This should be the much anticipated lock handler... 
//      -it is not inheritable
//      -should return to room.c the mappings and arrays required
//          for locks.... 

// Piper [12/15/95] -initial code

#define LOCK_BUGS "room_locks.bug"
private nosave mapping lock_types;

void create()
{
   //lock_types  "type":({type_num, base diff, range})

   lock_types = ([
	"tumb"   :({0,35,30}),
	"bolt"   :({1,1,15}),
	"l_pin"  :({2,15,20}),
	"catch"  :({3,35,30}),
	"comb"   :({4,65,35}),
	"cmplx"  :({5,65,35}),
	"hid"    :({6,65,35}),
	"magic"  :({7,100,200}),
	"vary"   :({8,1,100}),
        "tumb2"   :({9,1,35})
   ]);

}

// This receives the lock setup data...

varargs mapping add_lock(mapping locks_in, string index,
			 string type, int str, int pub, int trap)
{


  if(type == "0") type = "tumb";

  // check for lock type validity
  if(!lock_types[type])
  {
    // logging the screw-ups
      log_file( LOCK_BUGS, ctime(time())+
      " bad lock type: "+type+", ["+index+"] "
      +file_name(previous_object())+"\n");
    // using default -- >tumbler for now
    type = "tumb";
  }

  // now setting strength based on preset range
  if((!str)||(str == 0))
  {
    str = lock_types[type][1]+random(lock_types[type][2]);
  }

  if(!pub) { pub = 0; }
  if(!trap) { trap = 0; }

  // at this point the lock data is compiled... trap number is 0 (none)

  if(!mappingp(locks_in)) {locks_in = ([ ]); }

  locks_in[index] = ({ type, str, pub, trap });
  return locks_in;
}

int query_lock_index(mapping locks_in, string index)
{
  if(!mappingp(locks_in)) { return(0); }
  if(!locks_in[index]) { return(0); }
  return(1);
}

string query_lock_str(mapping locks_in, string index)
{
  string lock_str;
  if(!mappingp(locks_in)) {return(0); }
  if(query_lock_index(locks_in,index) == 0) { return 0; }
  
  lock_str = locks_in[index][1];
  return lock_str;
}

string query_lock_type(mapping locks_in, string index)
{
  string lock_type;
  if(!mappingp(locks_in)) { return 0; }
  if(query_lock_index(locks_in,index) == 0) {return 0; }

  lock_type = locks_in[index][0];
  return lock_type;
}

int query_lock_notify(mapping locks_in, string index)
{
  int notify;
  if(!mappingp(locks_in)) { return 0; }
  if(query_lock_index(locks_in,index) == 0) { return 0; }

  notify = locks_in[index][2];
  return notify;
}

int query_trap(mapping locks_in, string index)
{
  int trap;
  if(!mappingp(locks_in)) { return 0; }
  if(query_lock_index(locks_in,index) == 0) { return 0; }

  trap = locks_in[index][3];
  return trap;
}

string lock_messages(mapping exit_map, string index)
{
   write("\n  The "+exit_map[index][1]+" is locked.  "
        "Yes locked...Do you have a key? No.  Find someone to help you.\n");
   say("\n"+TP->query_cap_name()+" attempts to leave by the "+
       (string)exit_map[index][3]+" "+(string)exit_map[index][1]+
       ", but is thwarted for it is securely locked.\n\n");
   return "";
}
  
mapping remove_lock(mapping locks_in, string index)
{
  if(!mappingp(locks_in)) { return 0; }
  if(query_lock_index(locks_in,index) == 0) { return 0; }
  
  locks_in = m_delete(locks_in, index);
  return locks_in;
}
