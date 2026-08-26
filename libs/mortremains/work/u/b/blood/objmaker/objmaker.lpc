// The Infamous Object Maker, by Chronos.
// This is the inheritable file that adds the "make" action to whatever
// object you inherit this into.  This is basically so Cyanide can add
// this shit to his black crystal staff.  :D
// (30 Aug 1999) Chronos begins the code.  [Y2k Compliant!]

void init() {
  add_action("make", "make") ;
  ::init() ;  // Call the original init to make sure you don't lose anything.
}

int make(string str) {
  if (!str) {
    write(@ENDSHIT
 You sense that you can use the following commands:

      make object               Make a generic object with no special props.
      make weapon               Make a weapon.
      make armor                Make an armor.
      make monster              Make a living being.
      make room                 Make a room.


ENDSHIT
    );
    return 1;
  }
  switch(str) {
    case "object" :
    case "item"   :
      break ;
    case "weapon" :
    case "wep" :
      break ;
    case "armor" :
    case "armour" :
    case "arm" :
      break ;
    case "monster" :
    case "being" :
    case "mon" :
      break ;
    case "room" :
      break ;
    default:
      break ;
  }


// not even close to finished.
