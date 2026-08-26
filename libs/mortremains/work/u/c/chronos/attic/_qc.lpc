// _qc.c - Idea stolen from Cyanide.  Quality control quick check.
// (28 Aug 99) Chronos reinvents the wheel.

inherit DAEMON ;

int cmd_qc(string str) {
  object room, y;
  object * inv, * roominv, * inv2;
  mapping Map;
  string x;
  int i, j ;
  room = environment(TP) ;
  if (!room) {
    write("The void looks fine to me, dumbass.\n") ;
    return 1;
  }
  write("[Quality Control Quick Scan Initiated..]\n");
  write("----------------------------------------\n");
  write("Filename: "+ file_name(room)+"\n");
  write("Short   : "+ room->query("short")+"\n");
  write("Author  : ");
  x = room->query("author") ;
  if (!x) write("** NOT SET **\n") ;
  else {
  x = capitalize(x) ;
   if (!user_exists(lower_case(x))) 
      write(x+" [** User does not exist **]\n");
    else write(x+".\n");
  }
  write("LongDesc: ");
  if (!room->query("long")) write("** NOT SET **\n") ;
  else write("Appears to be set.\n") ;
  write("ItemDesc: ");
  if (!room->query("item_desc")) write("** NOT SET **\n") ;
  else write("Appears to be set.\n") ;
  write("Exits   : ");
  if (!room->query("exits")) write("[!] This room has no normal exits.\n") ;
  else write("Appear to be set normally.\n") ;
  write("Objects : ") ;
  Map = room->query("objects") ;
  if (!Map) write("This room does not have an objects property.\n") ;
  else {
    inv = values(Map) ;
    roominv=all_inventory(room) ;
    inv2 = allocate(sizeof(roominv));
    for(i=0;i<sizeof(roominv);i++) {
      if (!userp(roominv[i])) {
        inv2[j] = roominv[i] ;  j++ ; 
      }
    }
   if (sizeof(inv) != j ) {
     write(" [!] Not all of the objects appear to be loading.\n");
     write("         ") ;
     write("     Objects loaded from this room: "+sizeof(inv)+"\n") ;
     write("         ") ;
    write("     Objects in room (Minus users): "+j+"\n") ;
    write("         ") ;
    write("     NOTE: Update the room and try again.\n") ;
  }
    else write("Objects appear to be loading normally.\n") ;
  }
  write("[Secondary properties scan..]\n") ;
  write("-----------------------------\n");
  if (room->query("outside")) 
    write("Outside : ** THIS ROOM IS SET AS OUTSIDE. **\n") ;
  if (!room->query("light")) write("Light   : [!] This room is dark.\n") ;
  if (room->query("smell")) write("Smell   : This room has a smell set.\n");
  if (room->query("listen")) write("Listen  : This room has a listen property set.\n") ;
  if (room->query("search_desc")) write("Search  : This room has special search messages set.\n");
  if (room->query("search_func")) write("SrchFunc: This room has a search function set.\n") ;
  if (room->query("exit_msg")) write("ExitMsg : This room has exit msgs set.\n");
  if (room->query("item_func")) write("ItemFunc: This room has item functions set.\n") ;
  if (room->query("post_exit_func")) write("PostExit: This room has a post-exit function.\n");
  if (room->query("pre_exit_func")) write("PreExit : This room has a pre-exit function.\n");


  write("Finished.\n");
  return 1;
}

string help() {
  return @endlong
Usage: qc

This is the quality control quick scan program, designed to speed
up the Quality Control effort on the Mud.  It does a quick check of
some of the basic things that could be discrepancies in rooms.  It
does not check the object files within the room, but does verify 
that objects in the room load.
endlong
  ;
}


               
