/**
 * Shiannar@Divided Sky, Somewhere between 3/8/01 and 4/8/01.
 */

#define WAIT_LENGTH 172800
#include <player.h>
#include <playerinfo.h>

inherit OBJECT_OBJ;

string owner;
int time;

void set_owner(string);
void set_time(string);
int do_register();
void confirm_register(string);

void set_owner(string who) { owner = lower_case(who); }
string query_owner() { return owner; }
void set_time(int new_time) { time = new_time; }
int query_time() { return time; }

void setup() {
    set_name("token");
    set_short("pk token");
    set_adjectives(({"pk"}));
    add_property("nosteal", 1 );
    set_long("This small token will allow its owner to become a playerkiller "
       "after a certain period of time has passed.  If you do not wish "
       "to become a playerkiller, simply destroy it in some way, otherwise "
       "use the \"register\" command to both check the time remaining and "
       "to register for once and for all.\n");
    set_value(0);
    set_weight(0);
} /* setup() */

void init() {
  if( ENV(TO) == TP )
      TP->add_command("register", TO, "");
} /* init() */

int do_register() {

    if( ENV(TO) != TP )
        return 0;

    if( time() - WAIT_LENGTH < time ) {
        add_failed_mess("You haven't waited long enough, you still have "+
            time_string( time + WAIT_LENGTH - time() )+" seconds remaining!\n"
            "You can register "+ctime( time + WAIT_LENGTH )+" (local server "
            "time).\n");
        return 0;
    }

    if( owner != lower_case(TP->query_name()) ) {
        TO->move("/room/rubbish");
        add_failed_mess("You are not who the token was intended for.\n");
        return 0;
    }

    tell_object( TP, "%^BOLD%^%^RED%^Warning!  Becoming a playerkiller is "
        "permanent!\nAre you entirely sure you wish to do this?\n"
        "Please note you are using the character %^YELLOW%^"+
        TP->query_name()+"%^RED%^!%^RESET%^\n\n"
        "If you haven't read \"help playerkilling\" it is strongly\n"
        "recommended you choose \"no\"!\n"
        "(\"yes\" or \"no\")");

    input_to("confirm_register");
    return 1;

} /* do_register() */

void confirm_register(string str) {

    if( lower_case( str[0..0] ) != "y" ) {
        tell_object(TP, "It appears you have chosen not to become a "
            "playerkiller just yet.\n");
        return;
    }

    if( ENV(TO) != TP ) {
        tell_object( TP, "You're not carrying the token!\n");
        return;
    }

    if( lower_case(TP->query_name()) != owner) {
        TO->move("/room/rubbish");
        tell_object( TP, "You're not who this token was intended for.\n");
        return;
    }

    if( time() - WAIT_LENGTH < time ) {
        tell_object(TP, "You haven't waited long enough, you still have "+
            time_string( time + WAIT_LENGTH - time() )+" seconds remaining!\n"
            "You can register "+ctime( time + WAIT_LENGTH )+" (local server "
            "time).\n");
        return;
    }

    if( TP->query_property(PKER_NOT_ALLOWED) ) {
        tell_object( TP, "You have been expressly forbidden from becoming "
            "pk.\n");
        TO->move("/room/rubbish");
        return;
    }

    if( TP->query_property(PKER) ) {
        tell_object(TP, "You are already a playerkiller.\n"
            "Your token crumbles to dust and is swept away.\n");
        TO->move("/room/rubbish");
        return;
    }

    TP->add_property( PKER, time() );
    PLAYERINFO_HANDLER->add_entry( TO, TP->query_name(), "misc",
        CAP(TP->HE)+" chose to become a playerkiller via a token.\n");

    tell_object(TP, "You are now a playerkiller.\nYour token crumbles to "
       "dust and is swept away.\n");

    TO->move("/room/rubbish");

} /* confirm_register() */

mapping query_dynamic_auto_load() {
    return ([
      "::": ::query_dynamic_auto_load(),
      "time": time,
      "owner": owner,
      ]);
} /* query_dynamic_auto_load() */

void init_dynamic_arg(mapping map) {
    if( map["::"] )
        ::init_dynamic_arg(map["::"]);
    if( map["time"] )
        set_time(map["time"]);
    if( map["owner"] )
        set_owner(map["owner"]);
} /* init_dynamic_arg() */

mixed stats() {
    return ::stats() + ({
      ({ "time", time }),
      ({ "time left", ((time + WAIT_LENGTH) - time()) }),
      ({ "owner", owner}),
    });
} /* stats() */