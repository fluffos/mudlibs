
inherit "/std/effect_shadow";

int query_meditating() { return 1; }

string query_passed_out_message() {
    return "You are meditating, and cannot do that.\n";
} /* query_passed_out_message() */

mixed query_property( string name ) {
    if( name == PASSED_OUT )
        return 1;
    return player->query_property(name);
} /* query_property() */
