/*
**  File: teleport.c
**  Purpose: The newest breed of teleport. It is limited, and cannot cross
**      planar boundries (ie, Inner/Outer/Prime).
**      The more powerful version has been upgraded to "teleport without
**      error", and "shift" (ie, Plane Shift) now sends directly to a
**      person across planar boundaries.
**  Cost: 44 SP (5th level universal)
**  Credits:
**    09 Dec 97  Cyanide re-created the file.
*/

#define COST 44
#define SYNTAX "Syntax: cast teleport at <mark>\n"

#include <m_spells.h>
#include <mudlib.h>
#include <magic.h>

string *get_msg(string);

inherit SPELL;

varargs int cast_teleport (string str, int obj) {
   mapping marks;
   string *names;
   object targ, *rooms;
   int num;

   if (!str) {
      write(SYNTAX);
      return NO_TARGET;
   }

   if (TP->query("teleport_marks")) {
      marks = TP->query("teleport_marks");
      names = keys(marks);
      rooms = values(marks);
   } else {
      write("You have not yet defined a list of marked locations.\n"+
       "Use the \"mark\" command to add a room to your marks list.\n");
      return INVALID_TARGET;
   }
   

   num = member_array(str, names);
   if (num==-1) {
      write("The word \""+str+"\" is not in your marks list.\n"+
       "Use the \"mark\" command to add a room to your marks list.\n");
      return INVALID_TARGET;
   }

   targ = rooms[num];
   if (!obj) {
      if (!cast_spell(TP, COST)) return NO_STRENGTH;

      write("You begin casting Teleport...\n");
      say(TPN+" begins uttering arcane words...\n");
   }

   num = (int)environment(TP)->query("no_teleport");
   if (num==1 || num==3) {
      write("Your spell fails. \n"+
       "You cannot teleport from the room you're in.\n");
      return INVALID_TARGET;
   }

   if (targ->query_plane() != TP->query_plane() ) {
      write("You cannot teleport into different planes of existance.\n");
      return INVALID_TARGET;
   }

   num = (int)targ->query("no_teleport");
   if (num==1 || num==2) {
      write("That room has been barred against teleportation.\n"+
       "You may not reach it magically.\n");
      return INVALID_TARGET;
   }

/*
   if (query_antimagic(targ)) {
      write("Your spell cannot seem to find that room.\n");
      return 0;
   }
*/

   names = get_msg(this_player()->query("specialization"));
   names[0] = replace_string(names[0], "$N", TPN);
   names[1] = replace_string(names[1], "$N", TPN);

   say(names[0]);
   TP->move_player(targ, "SNEAK");
   say(names[1]);
   
   return SPELL_CAST;
}

string *get_msg(string caster) {
   string *msg = ({ "", "" });

   switch(caster) {
      case "abjuration" :
      case "alteration" :
         msg[0] = "$N creates a spectral door and steps through it.\n"+
          "The door immediately fades away.\n";
         msg[1] = "A spectral door appears, and $N steps out of it.\n";
         break;
      case "conjuration" :
      case "divination" :
      case "enchantment" :
      case "evocation" :
         msg[0] = "$N dissapears in a brilliant burst of "+
          "multicolored flames.\n";  
         msg[1] = "$N appears in a brilliant burst of multicolored "+
          "flames.\n";
         break;
      case "illusion" :
         msg = get_msg( ({"abjuration", "alteration", "conjuration",
          "divination", "enchantment", "evocation", "necromancy", 
          "???"})[ random(8) ] );
         break;
      case "necromancy" : 
         msg[0] = "$N dissolves into shadow and dissapears.\n";
         msg[1] = "$N emerges from the shadows.\n";
      default : msg[0] = "$N dissapears into thin air.\n";
         msg[1] = "$N appears out of thin air.\n";
         break;
   }

   if (!strlen(msg[0])) msg = get_msg("???");
   return msg;
}

string spellcraft() {
   return (@SPELLCRAFT
Teleport (Wizard - Level V - Alteration)

When this spell is used, the wizard instantly transports himself, along
with a certain amount of additional weight that is on the spellcaster,
to a well-known destination. Distance is not a factor, but interplanar
travel is not possible by means of a teleport spell. 

See: "mhelp mark"
SPELLCRAFT
   );
}
