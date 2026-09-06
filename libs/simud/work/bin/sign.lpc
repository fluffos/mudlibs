#include <literacy.h>;

int main(string str) {
  string what, as_str;
  int quality, fail;
  object ob, as;

  if( !str ) {
      notify_fail("What do you want to sign?\n");
      return 0;
  }
  /* forging commented out for now
  if (sscanf( str, "%s as %s", what, as_str ) < 2) {
    what = str;
    as = this_player();
  } else {
    as = find_player(as_str);
    if (!as)
      as = present(as_str,environment(this_player()));
    if (!as || !as->query_is_living()) {
      notify_fail("I don't know who you mean by '"+str+"'.");
      return 0;
    }
  }
  */
  what=str;
  as=this_player();

  ob = single_present( what, this_player() );
  if( !ob ) ob = single_present( str, environment(this_player()) );
  if( !ob ) {
    notify_fail("I don't know what you mean by "+str+"\n");
    return 0;
  }

  // quality is indication of how much it looks right
  // won't look right if you're tired
  if (as == this_player()) {
    quality = 100;
    if (this_player()->query_endurance() < this_player()->query_max_endurance())
      quality = quality - this_player()->query_max_endurance() + this_player()->query_endurance();
  } else {
    quality = 1;
  }

  if( (fail = ob->on_sign(as->query_name(), quality)) > 0) {
    set_target(ob);
    this_player()->msg_local("~CACT~Name ~verbsign ~targ.~CDEF");
    this_player()->set_doing("signing ~targ", this_object());

    return 1;
  } else {
    switch(fail) {
    case HAS_SIGNED: notify_fail("You've already signed it.\n"); break;
    case CANT_EDIT: //fall through
    default: notify_fail("You can't sign that.\n"); break;
    }
    return 0;
  }
}
