#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

object key;
int locked_door, opened_door, keyHere;
 
reset(arg) {
    locked_door = 1; opened_door = 0, keyHere = 1;
    if (arg) return;
 
    set_light(0);
    short_desc = "Entrance of graveyard";
    long_desc = 
        "You are standing in a small passage of the church. This room\n" +
        "is completely empty, except for a door to the north.\n" +
        "You get the feeling that this room was used as an altar room\n" +
        "to pray for the dead in former times.\n";
    dest_dir = ({ "/players/herp/room/father", "south" });
    items = ({"walls","There made of massive stone",
              "bottom","It is made of massive stone",
              "floor","It is made of massive stone",
              "door","It is a massive wooden door. A lot of strange symbols\n" +
                     "are painted on the door and the door has a skeleton-keyhole.\n" +
                     "The door is now @@chk_open@@",
              "keyhole","@@chk_lock@@",
              "skeleton-keyhole","@@chk_lock@@",
              "key","@@chk_key@@",
              "skeleton-key","@@chk_key@@",
              "symbols","@@run_baby@@",
    });
}
 
init() {
  ::init();
  add_action("search","search");
  add_action("unlock","unlock");
  add_action("close","close");
  add_action("lock","lock");
  add_action("open","open");
  add_action("pick","pick");
  add_action("pick","get");
  add_action("pick","take");
  add_action("knock","knock");
  add_action("north","north");
  add_action("picklock","picklock");
}

picklock(str) {
  if (str=="door" && present("picklock",TP)) {
     write("You can't open a magical door by stupidly using a picklock ...\n");
     say(TPN+" the thief tries to use "+TPPOS+" picklock on the door.\n" +
   capitalize(TPOBJ)+" fails completely ...\n");
     return 1;
  }
}

north( ) {
  if (opened_door) {
     this_player()->move_player( "north#players/patience/shadows/gy1" );
  }
  else {
     write("You bang your head against the closed door.\n");
     say(TPN+" runs into the door. Not very effective, though.\n");
  }
  return 1;
}

knock(str) {
string msg;

  if (str=="door") {
     msg=" at the door. Knock "; 
     switch(random(14)) {
     case 0: msg+="knock ";
     case 1: msg+="knock ";
     case 2: msg+="KNOCK ";
     case 3: msg+="knark ";
     case 4: msg+="knock ";
     case 5: msg+="KNARK ";
     case 6: msg+="knerk ";
     case 7: msg+="KNERK ";
     case 8: msg+="knurk ";
     case 9: msg+="KNURK ";
     case 10: msg+="knork ";
     case 11: msg+="KNORK ";
     case 12: msg+"Knarrrrrrkkkkrrrr ";
     }
     msg+="...\n";
     write("You knock"+msg);
     say(TPN+" knocks"+msg);
     return 1;
  }
}

search (str) {
   write("You search and search and find nothing\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}

pick( str )
{
   if ( str == "skeleton-key" || str == "skeleton key" ) {
      write( "You try to get the key form the keyhole, but you're much too unskillful!\n" +
             "So you break the key and it crumbles to dust!!!\n" );
      keyHere = 0;
      return( 1 );
   }
   else if ( str == "key" ) {
      write( "Which key do you mean?\n" );
      return( 1 );
   }
   
   return( 0 );
}

close(str) {
   if (str!="door")
      return;
      
   if (opened_door) {
      write("You close the door.\n");
      say(TPN+" closes the door.\n");
      opened_door = 0;
    }
   else
      write("The door is aready closed!\n");

   return( 1 );
}
     
open (str) {
  if (str!="door") return;
  if ( locked_door ) {
     write("You can't open the door, it is locked.\n");
     say(TPN+" tries to open the door but fails.\n");
  }
  else if ( opened_door ) {
     write( "But it's already open!\n" );
  }
  else {
     write( "You opened the door.\n" );
     say(TPN+" opened the door.\n" );
     opened_door = 1;
  }
  
  return 1;
}

unlock(str) {
   string str1;
   
   if (!str)
      return;
   
   if ( str == "door with skeleton-key" || str == "door with skeleton key" ) {
      if ( keyHere == 1 ) {
         if ( locked_door == 1 && keyHere == 1 ) {
            write("You unlock the door.\n");
            say(TPN+" unlocks the door.\n");
            locked_door = 0;
         }
         else
            write("But the door is already unlocked.\n" );
      }
      else
         write( "But there is no skeleton-key here !!!\n" );
        
      return( 1 );
   }
   else if ( str == "door" ) {
      write( "With what do you want to unlock the door?\n" );
      return( 1 );
   }
   else if ( sscanf( str, "door %s", str1 ) ) {
      if ( present( "key", this_player() ) ) {
         write( "This key won't fit.\n" );
         return( 1 );
      }
      
      write( "This item won't fit.\n" );
      return( 1 );
   }
   write( "You can't unlock that.\n" );
   return( 1 );
}

lock(str) {
   if ( str == "door with skeleton-key" || str == "door with skeleton key" ) {
      if ( keyHere == 1 ) {
         if ( opened_door == 0 ) {
            if ( locked_door == 0 ) {
               write("You lock the door.\n");
               say(TPN+" locks the door.\n");
               locked_door = 1;
            }
            else
               write( "But the door is already locked.\n" );
         }
         else
            write( "You can't lock an open door.\n" );
      }
      else
         write( "But there is no skeleton-key here !!!\n" );

      return( 1 );
   }
   
   write( "With what do you want to lock the door?\n" );
   return 1;
}

chk_open() {
  if ( opened_door ) {
     return "open";
  }
  else {
     return "closed";
   }
  return 1;
  }

chk_lock()
{
   if ( keyHere == 1 )
      return( "You see a tiny skeleton-key stuck in it" );
   else
      return( "It is a skeleton-keylock. You think, that only a skeleton-key will fit" );
}

chk_key()
{
   if ( keyHere == 1 )
      return( "It is a skeleton-key" );
   else
      return( "There is no key here" );
}

run_baby() {
  object inv;
  int    i;
  
  inv=all_inventory(this_player());
  tell_object( this_player(), "This seems to be black-magical symbols, all painted with blood.\n"+
               "You're sooo scared to them, that you run away in panic !!!\n" );
  shout(this_player()->query_name()+" shouts: Help, they are coming to get me !!!!\n");
  
  for( i=0; i<sizeof(inv); this_player()->drop_one_item(inv[i++]) );

  this_player()->run_away();
  return( "You shiver from the power of these symbols" );
}

DoorIsOpen( )
{
   return( opened_door );
}
