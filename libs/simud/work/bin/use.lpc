/*
 * Coded by : Durahan <durahan@airmail.net>
 * Date     : 2002-01-19
 * Filename : use.c
 * Notes    : Generic "use" command.
 *
 * Allaryin [8/29/03]:
 * - Converted to an enqueued action
 * - Evil bad braces style fixed
 *
 * Allaryin [9/23/04]:
 * - Using items is now a walking action
 * - You cannot use environment items on other people
 *   - Unfortunately, there is no way of knowing if using an item on somebody
 *     should walk to them or not (bandage vs wand)
 *   - Right now, I assume that any time you use something on someone, you do
 *     not need to walk to them first
 * - Stuff now uses single_present() in stead of all_present()[0]
 *
 * Athenon [8/10/06]:
 * - Nice grammar and such for using livings/yourself
 */

string query_action_name() {
  return "Use";
}

int main(string param) {
    object ob, person;

    if (!param) {
        return notify_fail("Use what? Your noggin?\n");
    } else if (param == "noggin" || param == "my noggin") {
        return notify_fail("You have peculiar feeling for a moment, then it passes.\n"); // yay, obscure Nethack references!
    } else {
        string a,b;
        if( sscanf(param, "%s on %s", a, b) == 2 ) {
            ob = single_present(a,this_player());
            if( !ob ) {
				if (single_present(a,environment(this_player())))
					notify_fail("You cannot specify a target when using items in your environment.\n");
				else
	                notify_fail("I don't understand what "+a+" is.\n");
                return 0;
            } else {
                person = single_present(b,environment(this_player()));
                if(!(person)) {
                    notify_fail(b+" isn't in the room with you.\n");
                    return 0;
                }
				WALK_ACTION_PARAM( 750, ob, person );
            }
            return 1;
        } else {
            ob = single_present(param,this_player());
            if( !ob ) {
                ob = single_present(param,environment(this_player()));
            }
            if( !ob ) {
                notify_fail("I don't understand what "+param+" is.\n");
                return 0;
            } else {
				WALK_ACTION( 750, ob );
            }
            return 1;
        }
    }
}

void on_action(object ob, mixed param) {
  // ob is item to use
  // param is what to use it on
  if (objectp(param)) {
     if (!(ob->on_use(param))) {
       set_actor(ob);
       set_listener(this_player());
       set_target(param);
       msg("~CWRNYou can't use ~name on ~targ.~CDEF");
     }
  } else {
     if(ob == this_player() && !(ob->on_use()))
        msg("~CWRNYou can't use yourself.~CDEF");
     else if(ob->query_is_living() && !(ob->on_use())) {
        set_target(ob);
        msg("~CWRNYou can't use ~objt.~CDEF");
     }
     else if(!(ob->on_use()))
       msg("~CWRNYou can't use "+ob->query_specific()+".~CDEF");
  }
  // it is the duty of on_use to debit readiness
}
