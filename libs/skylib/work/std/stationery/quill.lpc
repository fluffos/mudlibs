/**
 * Ink/dipping can be added once vessels/liquids is finished.
 * Writing size can be added once that's worked out.
 * @changed Added 'copy' command - Jeremy, 10-Dec-95
 * @changed Added 'sign' command - Shiannar, 30-Aug-2002.
 */

#include <language.h>

#undef USE_COPY

inherit WEAPON_OBJ;

nosave object writing_on;

/** @ignore yes */
int do_write( object *things ) {
    string language;
    object thing;

    if( query_wielded() != TP ) {
        add_failed_mess("You need to be holding $D to $V with it.\n");
        return 0;
    }

    things = filter( things, (: ENV($1) == TP || ENV($1) == ENV(TP) :) );

    if( !sizeof(things) ) {
        add_failed_mess("You can only $V on objects you are holding or are "
            "in the room with you.\n");
        return 0;
    }

    if( sizeof( things ) > 1 ) {
        add_failed_mess("You can only $V on one object at once.\n");
        return 0;
    }

    thing = things[0];

    if( !thing->query_writeable() && !thing->query_property("writeable") ) {
        add_failed_mess("You cannot $V on $I with $D.\n", things );
        return 0;
    }

    language = (string)TP->query_current_language();

    if( !LANGUAGE_H->query_language_written( language ) ) {
        add_failed_mess("You cannot $V on $I with $D when you are not using "
            "a language that can be written.\n", things );
        return 0;
    }

    if( writing_on ) {
        add_failed_mess("You are already writing on $I with $D.\n",
            ({ writing_on }) );
        return 0;
    }

    tell_object( TP, "You start writing on "+thing->the_short()+" with "+
        poss_short()+".\n");
    tell_room( ENV(TP), TP->the_short()+" $V$0=starts,start$V$ writing on "+
        thing->a_short()+" with "+a_short()+".\n", TP );

    add_succeeded_mess("");
    writing_on = thing;

    TP->do_edit( 0, "end_writing");
    return 1;

} /* do_write() */

/** @ignore yes */
void end_writing( string words, int flag ) {
    string language;

    if( !words || words == "") {
        write("You don't write anything on "+
            (string)writing_on->the_short()+".\n");
        say( (string)TP->the_short()+" doesn't write anything after all.\n");
        writing_on = 0;
        return;
    }

    language = (string)TP->query_current_language();
    if( !LANGUAGE_H->query_language_written( language ) ) {
        write("You seem to have changed to using a non-written language.\n");
        say( (string)TP->the_short() +" seems linguistically challenged.\n");
        writing_on = 0;
        return;
    }

    if( !writing_on ) {
        write("You seem to have lost what you were writing on.\n");
        say( (string)TP->the_short() +" looks around in puzzlement.\n");
        return;
    }

    if( ENV(writing_on) != TP && ENV(writing_on) != ENV(TP) ) {
        write( (string)writing_on->the_short()+" seems to have run away from "
            "you.\n");
        say( (string)TP->the_short()+" looks like "+(string)TP->HE+" has "
            "lost something.\n");
        writing_on = 0;
        return;
    }

    if( writing_on->is_current_page_torn_out() ) {
        write("The page of "+(string)writing_on->the_short()+" you were "
            "writing on appears to have been torn out.\n");
        say( (string)TP->the_short()+" looks like "+(string)TP->HE+" has "
            "lost something.\n");
        writing_on = 0;
        return;
    }

    if( !flag && !writing_on->test_add_read_mess( words, 0, language ) ) {
        write("\nAll of that text doesn't want to fit very well on "+
            writing_on->the_short()+".\n\nDo you want to continue editing "
            "what you wrote? (answering no will cut off whatever doesn't "
            "fit on the page) [y|n|q] ");
        input_to("do_confirm", words );
        return;
    }

    writing_on->add_read_mess( words, 0, language );
    write("You finish writing on "+(string)writing_on->the_short()+".\n");
    say( (string)TP->the_short()+" finishes writing on "+
        (string)writing_on->a_short() +".\n");
    writing_on = 0;

} /* end_writing() */

/** @ignore yes */
void do_confirm( string str, string text ) {
    switch( lower_case(str) ) {
      case "q":
        write("You don't write anything on "+
            (string)writing_on->the_short()+".\n");
        say( (string)TP->the_short()+" doesn't write anything after all.\n");
        writing_on = 0;
        return;
      case "y":
      case "yes":
        write("You continue editing the text...\n");
        TP->do_edit( text, "end_writing");
        return;
      case "n":
      case "no":
        end_writing( text, 1 );
        return;
      default:
        write("Please choose [y]es or [n]o: ");
        input_to("do_confirm", text );
    }
} /* do_confirm() */

#ifdef USE_COPY
/** @ignore yes */
int do_copy( mixed *in_dir, string direct, string indirect, mixed *args ) {
    // This will need a lot of checks.  For now it is just a "proof of
    // concept".
    mixed src_mess, mess;
    string lang, cur_lang;
    int i, c, siz, perr;

    //printf("-------- in_dir\n%O\n------- args\n%O\n", in_dir, args);
    // This is to keep the parser from matching "quill in <word>" on
    // a second attempt when the language checks fail.  Maybe this won't
    // be necessary some day.
    if( !present( direct, TP ) )
        return 0;

    if( query_wielded() != TP ) {
        add_failed_mess("You need to be holding $D to $V with it.\n");
        return 0;
    }

    if( sizeof(in_dir) != 2 || sizeof(in_dir[0]) != 1 ||
        sizeof(in_dir[1]) != 1 ) {
        add_failed_mess("You can only $V to/from one object at a time.\n");
        return 0;
    }

    if( !in_dir[1][0]->query_writeable() ) {
        add_failed_mess("You can't write on $I.\n", in_dir[1] );
        return 0;
    }

    if( sizeof(args) == 4 ) {
        if( !LANGUAGE_H->query_language_written(args[3]) ) {
            add_failed_mess( CAP(args[3])+" is not a written language.\n");
            return 0;
        }

        if( LANGUAGE_H->query_language_magic(args[3]) ) {
            add_failed_mess("You can't write "+args[3]+" like this.\n");
            return 0;
        }

        if( !TP->query_language(args[3]) ) {
            add_failed_mess("You don't know any "+args[3]+".\n");
            return 0;
        }
        cur_lang = args[3];
    }

    src_mess = in_dir[0][0]->query_read_mess();

    if( !sizeof(src_mess) ) {
        add_failed_mess("There is nothing written on $I.\n", in_dir[0] );
        return 0;
    }

    // Copy each read_mess.
    for( i = 0; i < sizeof(src_mess); i++ ) {
        mess = src_mess[i][0];
        lang = src_mess[i][2];
        siz = src_mess[i][3];

        if( LANGUAGE_H->query_language_magic(lang) ) {
            mess = "A series of unintelligible scribbles.";
            lang = "common";
        } else if( !TP->query_language(lang) && stringp(mess) ) {
            // Introduce a few copying errors, based on intelligence
            // and dexterity
            if( ( perr = TP->query_int() + TP->query_dex() - 20 ) < 1 )
                perr = 1;
            for( c = random(perr); c < sizeof(mess); c += random(perr)+1 ) {
                if( mess[c] >= 'a' && mess[c] <= 'z' )
                    mess[c] = 'a' + random(26);
                else if( mess[c] >= 'A' && mess[c] <= 'Z' )
                    mess[c] = 'A' + random(26);
            }
        } else if( stringp(cur_lang) )
            lang = cur_lang;
        // TCRE("sandoz", sprintf("%O\n", src_mess[i] ) );
        // TCRE("sandoz", sprintf("--------\n%O\n", in_dir ) );
        in_dir[1][0]->add_read_mess( mess, type, lang, siz );
    }

    add_succeeded_mess("$N $V the writing on $I onto "+
        in_dir[1][0]->the_short()+" with $D.\n", in_dir[0] );
    return 1;

} /* do_copy() */
#endif

/** @ignore yes */
int do_sign( object *things ) {
    object thing;
    string sig;

    if( query_wielded() != TP ) {
        add_failed_mess("You need to be holding $D to $V with it.\n");
        return 0;
    }

    things = filter( things, (: ENV($1) == TP || ENV($1) == ENV(TP) :) );

    if( !sizeof(things) ) {
        add_failed_mess("You can only $V objects you are holding or are "
            "in the room with you.\n");
        return 0;
    }

    if( sizeof( things ) > 1 ) {
        add_failed_mess("You can only $V one object at once.\n");
        return 0;
    }

    thing = things[0];

    if( !thing->query_writeable() && !thing->query_property("writeable") ) {
        add_failed_mess("You cannot $V $I with $D.\n", things );
        return 0;
    }

    switch( TP->query_dex() ) {
      case 0..10:
        sig = "a barely legible signature of "+TP->short();
      break;
      case 11..13:
        sig = "a rough signature of "+TP->short();
      break;
      case 14..16:
        sig = "a signature of "+TP->short();
      break;
      case 17..19:
        sig = "a neat signature of "+TP->short();
      break;
      default:
        sig = "a perfect signature of "+TP->short();
    }

    if( !thing->test_add_read_mess( sig, "signature", 0 ) ) {
        add_failed_mess("There isn't enough space on $I to write your "
            "signature on it.\n", things );
        return 0;
    }

    thing->add_read_mess( sig, "signature", 0 );
    add_succeeded_mess("$N sign$s $I with $D.\n", things );
    return 1;

} /* do_sign() */

/** @ignore yes */
string query_writing_commands() {
#ifndef USE_COPY
    return "\"write\" or \"sign\"";
#else
    return "\"write\", \"copy\" or \"sign\"";
#endif
} /* query_writing_commands() */

/** @ignore yes */
void init() {
    add_command("write", "on <indirect:object> with <direct:object:me>");
    add_command("write", "with <direct:object:me> on <indirect:object>");
    add_command("sign", "<indirect:object> with <direct:object:me>");
#ifdef USE_COPY
    add_command("copy", ({
        "<indirect:object> to <indirect:object:me> with <direct:object:me>",
        "<indirect:object> to <indirect:object:me> with <direct:object:me> "
        "in <word'language'>"}) );
#endif
} /* init() */
