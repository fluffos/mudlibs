
inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string word ) {
    switch( word ) {
      case "debate" :
      case "debating" :
        TP->interrupt_debate();
      break;
      case "spell" :
        TP->interrupt_spell();
      break;
      case "ritual" :
        TP->interrupt_ritual();
      break;
      case "lockpick" :
      case "lockpicking" :
        TP->interrupt_lockpicking();
      break;
      case "fight" :
      case "fighting" :
        if( TP->query_hp() < 0 || TP->query_property("dead") ) {
            write("You are dead; stopping now is pointless.\n");
            return 1;
        }
        if( !sizeof( TP->query_attacker_list() ) ) {
            write("You are not fighting anyone.\n");
            return 1;
        }
        write("Stopping fight.  Please wait.\n");
        call_out("stop_fight", 5, TP );
        return 1;
      default:
        TP->interrupt_debate();
        TP->interrupt_spell();
        TP->interrupt_ritual();
        TP->interrupt_lockpicking();
        cmd("fight");
   }

   "/cmds/player/sea_rch"->interrupt_search(TP);
   write("Okay.\n");
   return 1;

} /* cmd() */

/** @ignore yes */
void stop_fight( object who ) {
    object *atts, ob;

    if( !who )
        return;

    atts = who->query_attacker_list();

    if( sizeof( atts = filter( atts, (: ENV($1) != ENV($2) :), who ) ) ) {
        tell_object( who, "You stop fighting "+query_multiple_short( map(
            atts, (: $1->query_property("dead") ?
            $1->a_short()+" (dead anyway)" : $1 :) ) )+".\n");

        foreach( ob in atts )
            who->stop_fight(ob);

    }

} /* stop_fight() */

/** @ignore yes */
mixed query_patterns() {
   return ({
        "",
        (: cmd(0) :),
        "{debate|debating|spell|ritual|fight|fighting|lockpick|lockpicking}",
        (: cmd($4[0]) :) });
} /* query_patterns() */
