
#include <spells.h>
#include <player.h>

inherit COMMAND_BASE;

/** @ignore yes */
int do_cast_spell(string words, object *targets, object *using, string args) {
    string spell, spell_nick;
    mapping spells;
    object ob;

    if( !ENV(TP) ) {
        add_failed_mess("You are in limbo; you cannot cast spells here.\n");
        return 0;
    }
    if( TP->query_property("dead") ) {
        add_failed_mess("$Ving spells while dead?  I don't think so.\n");
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
            add_failed_mess("You do not know any spell called "+words +".\n");
            return -1;
        }
        spell = spell_nick;
    }

    if( !spells[spell][S_OBJECT]->query_is_spell() ) {
        add_failed_mess("You do not know any spell called "+words+".\n");
        return -1;
    }

    if( !stringp( spells[ spell ][ S_OBJECT ] ) ||
        catch( ob = load_object( spells[spell][S_OBJECT] ) ) ) {
        add_failed_mess("Badly added spell.\n");
        return -1;
    } else {
        if( !ob->query_cast_spell( TP, args, targets, using ) )
            return -1;
        else
            return 1;
    }

} /* do_cast_spell() */

/** @ignore yes */
int do_cast_scroll( string spell, object *things, string args, object *targets,
                    object *using ) {
    string spell_ob;

    if( sizeof( things ) > 1 ) {
        add_failed_mess("You can't cast spells from more than one scroll at "
            "once.\n");
        return 0;
    }

    if( !things[ 0 ]->query_magic_scroll() ) {
        add_failed_mess("$I is not a magic scroll.\n", things );
        return 0;
    }

    if( lower_case( things[ 0 ]->query_spell_name() ) != lower_case(spell) ) {
        add_failed_mess("$I does not contain the spell "+spell+".\n",
            things );
        return 0;
    }

    spell_ob = things[ 0 ]->query_spell();
    return spell_ob->cast_spell_new( args, 1, targets, using );

} /* do_cast_scroll() */

/** @ignore yes */
mixed *query_patterns() {
    return ({
      "<string'spell'>",
      (: do_cast_spell($4[0], ({ }), ({ }), "") :),
      "<string'spell'> {on|at} <indirect:object'target'>",
      (: do_cast_spell($4[0], $1, ({ }), "") :),
      "<string'spell'> {on|at} <indirect:any-living'living target'>",
      (: do_cast_spell($4[0], $1, ({ }), "") :),
      "<string'spell'> with <string'arguments'>",
      (: do_cast_spell($4[0], ({ }), ({ }), $4[1]) :),
      "<string'spell'> {on|at} <indirect:object'target'> "
      "with <string'arguments'>",
      (: do_cast_spell($4[0], $1, ({ }), $4[3]) :),
      "<string'spell'> using <indirect:object'components'>",
      (: do_cast_spell($4[0], ({ }), $1, "") :),
      "<string'spell'> {on|at} <indirect:object'target'> "
      "using <indirect:object'components'>",
      (: do_cast_spell($4[0], $1[0], $1[1], "") :),
      "<string'spell'> from <indirect:object'scroll'> {on|at} "
      "<indirect:object'target'> with <string'arguments'>",
      (: do_cast_scroll($4[0], $1[0], $4[3], $1[1], ({ })) :),
      "<string'spell'> from <indirect:object'scroll'> with <string'arguments'>",
      (: do_cast_scroll($4[0], $1, $4[2], ({ }), ({ })) :),
      "<string'spell'> from <indirect:object'scroll'> {on|at} "
      "<indirect:object'target'>",
      (: do_cast_scroll($4[0], $1[0], 0, $1[1], ({ })) :),
      "<string'spell'> from <indirect:object'scroll'>",
      (: do_cast_scroll($4[0], $1, 0, ({ }), ({ })) :)
    });
} /* query_patterns() */
