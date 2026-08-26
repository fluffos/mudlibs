
inherit COMMAND_BASE;

mixed cmd(object *things) {
  object *protectees;
  object ob;
  object *fail;

  if(!things) {
    things = ({ });
  }
  things -= ({ TP });

  if ( !sizeof( things ) ) {
    add_failed_mess("You cannot unprotect yourself!\n");
    return 0;
  }

  protectees = ({ });
  fail = ({ });

  foreach ( ob in things) {
    if ( ob->remove_protector( TP ) ) {
      protectees += ({ ob });
    } else  {
       fail += ({ ob });
    }
  }
  
  if ( sizeof( fail ) ) {
    add_failed_mess( "You are not protecting " + query_multiple_short( fail ) +
                     ".\n" );
  }
  if (sizeof(protectees)) {
     add_succeeded_mess("$N stop$s protecting $I.\n", protectees);
     return 1;
  } else {
     return 0;
  }
} /* cmd() */

mixed *query_patterns() {
   return ({ "<indirect:living>", (: cmd($1) :) }); 
} /* query_patterns() */
