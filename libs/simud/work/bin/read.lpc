#include <literacy.h>

string query_action_name( mixed * action ) {
   return "Read";
}

int main(string str) {
   string what, where = "";
   int page;
   object ob;

   if( !str ) {
      notify_fail("Usage: read [page <num>|<part> of|from|on] <object>\n");
      return 0;
   }

  if ( (sscanf( str, "%s of %s", where, what ) < 1) &&
       (sscanf( str, "%s from %s", where, what ) < 1) &&
       (sscanf( str, "%s on %s", where, what ) < 1)) {
    what = str;
  }
  if (where[0..4] == "page ")
    where = where[5..];

  ob = single_present( what, this_player() );
  if( !ob ) ob = single_present( str, environment(this_player()) );
  if( !ob ) {
    notify_fail("I don't know what you mean by '"+str+"'.\n");
    return 0;
  }

  this_player()->push_action( ({ 1000,
                                 this_object(),
                                 ob,
                                 ST_SITTING | ST_STANDING,
                                 where }) );
  return 1;
}

void on_action(object ob, string where) {
  int fail;
  if( ob->query_file_name() == "/items/paper" )
     where = "front";

  this_player()->add_readiness(-500);

  if( (fail = ob->on_read(where)) > 0 ) {
    set_target(ob);
    this_player()->say_local("~CACT~Name ~verbread ~targ.~CDEF");
    this_player()->set_doing("reading ~targ", ob);
  } else {
    switch(fail) {
       case BAD_LOCATION:
          msg("What part of " + ob->query_specific() + " would you like to read?");
          break;
       case BAD_PAGE:
          msg("That page doesn't exist in " + ob->query_specific() + ".");
          break;
       default:
          msg("You can't read that.");
    }
  }
}
