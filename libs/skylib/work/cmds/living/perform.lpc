
#include <spells.h>
#include <player.h>

inherit COMMAND_BASE;

/** @ignore yes */
int do_cast_ritual( string words, object *targets, object *using,
                    string args ) {
    string spell, spell_nick;
    mapping spells;
    object ob;

    if( !ENV(TP) ) {
        add_failed_mess("You are in limbo; you cannot $V rituals here.\n");
        return 0;
    }

    if( TP->query_property("dead") ) {
        add_failed_mess("Performing rituals while dead?  I don't think so.\n");
        return 0;
    }

    spells = TP->query_spells();
    spell = words;
    spell_nick = TP->expand_nickname( spell );

    if( !spells[ spell ] ) {
        if( !spells[ spell_nick] ) {
            if( strsrch( words, " using ") != -1 ||
                strsrch( words, " on ") != -1 ||
                strsrch( words, " from ") != -1 ||
                strsrch( words, " at ") != -1 ) {
                return -1;
            }
            add_failed_mess("You do not know a ritual called "+words+".\n");
            return -1;
        }
        spell = spell_nick;
    }

    if( !spells[spell][S_OBJECT]->query_faith_ritual() ) {
        add_failed_mess( "You do not know a ritual called "+words+".\n");
        return -1;
    }

    if( !stringp(spells[ spell ][ S_OBJECT ]) ||
        catch( ob = load_object( spells[spell][S_OBJECT]) ) ) {
        add_failed_mess("It appears "+words+" has been badly added to you.  "
            "Please contact a creator.\n");
        return -1;
    } else {
        if( !ob->cast_spell( args, targets, using ) )
            return -1;
        else
            return 1;
    }

} /* do_cast_spell() */

/** @ignore yes */
mixed query_patterns() {
    return ({
      "<string'ritual'>",
      (: do_cast_ritual($4[0], ({ }), ({ }), "") :),
      "<string'ritual'> {on|at} <indirect:object'target'>",
      (: do_cast_ritual($4[0], $1, ({ }), "") :),
      "<string'ritual'> {on|at} <indirect:any-living'living target'>",
      (: do_cast_ritual($4[0], $1, ({ }), "") :),
      "<string'ritual'> using <indirect:object'components'>",
      (: do_cast_ritual($4[0], ({ }), $1, "") :),
      "<string'ritual'> {on|at} <indirect:object'target'> "
      "using <indirect:object'components'>",
      (: do_cast_ritual($4[0], $1[0], $1[1], "") :),
      "<string'ritual'> with <string'arguments'>",
      (: do_cast_ritual($4[0], ({ }), ({ }), $4[1]) :),
      "<string'ritual'> {on|at} <indirect:object'target'> "
      "with <string'arguments'>",
      (: do_cast_ritual($4[0], $1, ({ }), $4[3]) :),
      "<string'ritual'> using <indirect:object'components'> "
      "with <string'arguments'>",
      (: do_cast_ritual($4[0], ({ }), $1, $4[2]) :),
      "<string'ritual'> {on|at} <indirect:object'target'> "
      "using <indirect:object'components'> with <string'arguments'>",
      (: do_cast_ritual($4[0], $1[0], $1[1], $4[4]) :)
    });
} /* query_patterns() */
