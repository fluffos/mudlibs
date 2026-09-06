#include <literacy.h>;

int main(string str) {
  string what;
  string where = ""; // just so we can do covers, etc. more flexible
  object ob;
  int fail;

  if( !str ) {
      notify_fail("Usage: write [on (page <num>|<part>)] on|of <object>\n");
      return 0;
  }

  if ( (sscanf( str, "%s of %s", where, what ) < 1) &&
       (sscanf( str, "%s on %s", where, what ) < 1)) {
    what = str;
  }
  if (what[0..2] == "on ")
    what = what[3..];
  if (where[0..2] == "on ")
    where = where[3..];
  if (where[0..4] == "page ")
    where = where[5..];

  ob = present( what, this_player() );
  if( !ob ) ob = present( str, environment(this_player()) );
  if( !ob ) {
    notify_fail("I don't know what you mean by "+str+"\n");
    return 0;
  }

  if( ob->query_file_name() == "/items/paper" )
     where = "front";

  if( (fail = ob->on_write(where)) > 0 ) {
    set_target(ob);
    if (sscanf(where, "%!s%D%!s", str)) {
      this_player()->say_local("~CACT~Name ~verbbegin writing in ~targ.~CDEF");
      this_player()->set_doing("writing in ~targ", ob);
    } else {
      this_player()->say_local("~CACT~Name ~verbbegin writing on ~targ.~CDEF");
      this_player()->set_doing("writing on ~targ", ob);
    }
    return 1;
  } else {
    switch(fail){
    case IS_SIGNED: notify_fail("You can't add to or edit something that's signed.\n"); break;
    case BAD_LOCATION: notify_fail("What part of " + ob->query_specific() + " would you like to write on?\n"); break;
    case BAD_PAGE: notify_fail("That page doesn't exist in " + ob->query_specific() + ".\n"); break;
    default: notify_fail("You can't write on that.\n");
    }
    return 0;
  }
}
