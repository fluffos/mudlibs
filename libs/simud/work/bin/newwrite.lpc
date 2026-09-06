#include <legible.h>

int main(string str) {
   string what, where, with;
   object pen, paper;
   int length;
   struct page_contents_struct data;

   if( !str ) {
      return notify_fail("Usage: write [what] on|in <object> with <quill>\n");
   }

   if( sscanf(str, "%s with %s", str, with) != 2 && str[0..4] != "with " ) {
      return notify_fail("You must specify which writing implement you are using.\n");
   }

   if( str[0..2] != "on " && str[0..2] != "in " ) {
      if( sscanf(str, "%s on %s", what, where) != 2 &&
          sscanf(str, "%s in %s", what, where) != 2 ) {
         return notify_fail("You must specify what you are planning on writing on.\n");
      }
   } else {
      where = str[3..];
   }

   msg("what  = '"+what+"'");
   msg("where = '"+where+"'");
   msg("with  = '"+with+"'");

   // validate paper
   paper = single_present(where, this_player());
   if (!paper) {
      return notify_fail("Couldn't find any '"+with+"' to write on.\n");
   } else if (!paper->query_is_writable()) {
      return notify_fail("You can't write on that.\n");
   }

   // validate pen
   pen = single_present(what, this_player());
   if (!pen) {
      return notify_fail("Couldn't find any '"+with+"' to write with.\n");
   } else if (!pen->query_can_write()) {
      return notify_fail("You can't write with that.\n");
   } else if (!pen->query_held()) {
      return notify_fail("You must be holding the pen in order to write with it.\n");
   }

   data.details = L_HAND | (pen->query_ink_colour() ? L_COLOUR | L_BLACK );
   set_actor(this_player());
   set_target(paper);

   // check for special thingies to write
   if (what) {
      // is it a signature?
      if (what == "my name" || what == "signature" || what == "my signature") {
         data.category = L_SIGNATURE;
         data.length = 1;
		 data.language = this_player()->query_current_language();
		 data.contents = this_player()->query_name();
         if (!paper->on_write( data ))
		    return notify_fail("You are unable to sign that...\n");
		 else {
            this_player()->msg_local("~CACT~Name ~verbsign ~poss name on ~targ.~CDEF");
            return 1;
         }
      } else
      // is it a spell?
      if (MAGIC_DAEMON->query_spell(what)) {
      } else
      // is it a skill?
      if (SKILL_DAEMON->skill_exists(what)) {
      } else
      // is it a deed?
      if (what == "deed") {
         // must stand inside of the building in question
         return notify_fail("Sorry, title deeds are not yet operational.\n");
      } else
      // is it a license?
      if (what == "license") {
         // must be government official to write up such things
         return notify_fail("Sorry, licenses are not yet operational.\n");
      }
      // if special, make sure we have enough room
   } else {
      // if not special, start writing until we run out of space
   }

   return 1;
}
