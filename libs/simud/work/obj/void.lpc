/** A sort of "null" room. This was once a required room for the MUDlib;
 * we hang onto it for tradition. Some unusual error cases will dump players
 * or objects here as a way to fix things. Nobody sees or cares about this much
 * anymore.
 */

/// \return this_object() if \a str is "void" or "anomaly", and false if not.
object id(string str) {
   if( str == "void" || str == "anomaly" ) return this_object();
   else return 0;
}

string query_distant() {
    return "an anomaly";
}

string query_look() {
   return "A strange, disturbing anomaly is sitting here. It appears "+
      "to be ... nothing. This should not be here.";
}

string query_short() {
   return "The Void";
}

string query_long() {
   return "There is an icy cold blackness in this room, which defies all description.  "+
      "You feel utterly, utterly alone, but you might be able to 'escape'.";
}

string query_name() {
   return "void";
}

string query_bgm() {
   return "bgm/holst_jupiter.mp3";
}

/** The function to call to exit this room; this is a lib245 style room
 * (even with all our wacky differences, that style still works).
 */
escape() {
   msg("You feel a sudden rush, and then you see the world stretching before you.");
   this_player()->move_player(";wizarea;reception", 0);
   return 1;
}

/// Called when the player enters; creates the 'escape' verb.
init() {
   add_action("escape", "escape");
}
