/*
//  File    :  /cmds/std/_say.c
//  Creator :  Watcher@TMI (01/29/93)
//
//  Standard say command with modification for loudness via race,
//  special speech formats, and anonymous voices in dark areas.
//
//  Revision history:
//    Languages support by Megadeath@TMI-2
//    Optimizations (?) by Robocoder@TMI-2
*/

#include <mudlib.h>
//#include <language.h>

inherit DAEMON ;
 
//  Range of possible say verbs used in conjunction with user's
//  speech loudnesss.  If you don't want this feature, simply
//      #undef VERBS
 
#define SIZEOF_VERBS    7
#define LONGEST_VERB    7
#define VERBS   ({ "whisper", "mumble", "sing", "say", "holler", \
                   "yell", "scream" })

#undef VERBS

//      #define VISUAL_CHECK to give anonymous voices in dark areas
//      #undef VISUAL_CHECK to give the speaker's name regardless of light
//          levels
 
#define VISUAL_CHECK    1

//#undef VISUAL_CHECK

//      #undef LANGUAGES to disable LANGUAGE support from <language.h>

#undef LANGUAGES

#ifdef VERBS 

int myloudness;

int compute_loudness(object target);

#endif

int cmd_optsay(string str) {
    mixed *who;
    object here;
    string name, myname, tmp, special, *fmt, rest;
    int loop, s, num;
    int novision, otherlight;

    //  Block an attack from the queue as payment for the say use
    this_player()->block_attack(2) ;
 
    //  Get user's environment
    here = environment( previous_object() );
 
    if (!str || str == "") {
        notify_fail("You mutter to yourself.\n");
        return 0;
    }
#ifndef VERBS 
    //  Check to see if user has a special say verb
    special = (string) previous_object()->query("special_say");
    if (special)
        tmp = " " + special + "s: ";
    else
        tmp = " says: ";
#else
    //  Get my loudness
    myloudness = (int)previous_object()->query("loudness");
#endif
    myname = (string)previous_object()->query("cap_name");

    //  Rewrite string
#ifdef VERBS
    num = 4 + LONGEST_VERB + ((loop = strlen(myname)) > 8 ? loop : 8);
#else
    num = strlen(tmp) + ((loop = strlen(myname)) > 8 ? loop : 8);
#endif
    loop = 79 - num;
    if (strlen(str) > loop) {
        rest = sprintf("%-=79s", sprintf("%" + num + "s", "") + str);
#if 1
        fmt = explode(rest, "\n"); // until driver updated to 0.9.17.13
        str = fmt[0][num..strlen(fmt[0])-1] + "
";
        fmt[0] = 0;
        rest = implode(fmt, "\n");
#else
        loop = strsrch(rest, "\n");
        if (loop != -1) {
            str = rest[num .. loop - 1];
            rest = rest[loop .. strlen(rest)-1];
        } else
            rest = "";
#endif
    } else
        rest = "";
    
    //  Get contents of the user's environment minus the user.

    if (here) 
        who = all_inventory( here ) - ({ previous_object() });
    else
        who = ({ });
 
    //  Loop through and give the message to each member of the room


#ifdef VISUAL_CHECK
    if (s = sizeof(who)) {
        //  Pre compute visual checks

        if (here) {
            novision = here->query("no_vision");
            if (!novision) {
                if (!(otherlight = (here->query("light") > 0))) {
                    for (loop = 0; loop < s; loop++) {
                        if (who[loop]->check_light()) {
                            otherlight = 1;
                            break;
                        }
                    }
		}
            }
        }
    }
#else
    s = sizeof(who);
#endif

    for (loop = 0; loop < s; loop ++) {

    // This should be ok...if you want to catch_tell() you have to be
    // living via enable_commands()
        if (!living(who[loop])) continue;

#ifdef VERBS
        // Get calculated say type corresponding to user's and
        // target's loudness
        num = compute_loudness( who[loop] );
#endif

#ifdef VISUAL_CHECK
        if (!here || (!who[loop]->query("full_vision") &&
              (who[loop]->query("blind") || novision) || !otherlight)) {
            if(wizardp(this_player()))
                name = "Someone";
            else
                name = "Somebody";
        } else
#endif
            name = myname;

#ifdef VERBS
        message("say", sprintf("%s %s: %s%s\n",
              name, VERBS[num], str, rest), who[loop]);
#else
        message("say", sprintf("%s%s%s%s\n", name, tmp, str, rest), who[loop]);
#endif
    }

    if (special)
        tmp = "You " + special + ": ";
    else
        tmp = "You say: ";

    message("write", sprintf("%s%s%s\n", tmp, str, rest), this_player());

    return 1;
}
 
#ifdef VERBS

//  This function calculates the correct say verb to use by
//  comparing the user's and target's loudness levels.

int compute_loudness(object target) {
    int loudness;
 
    loudness = ( myloudness - (int)target->query("loudness") +
          SIZEOF_VERBS/2 );
 
    if (loudness < 0)
        return 0;
    else if (loudness > SIZEOF_VERBS - 1)
        return (SIZEVERBS - 1);
 
    return loudness;
}

#endif

string help() {
    return(

#ifdef LANGUAGES
@ENDSYNTAX
Syntax: say [in <language>] <message>
ENDSYNTAX
#else
@ENDSYNTAX
Syntax: say <message>
ENDSYNTAX 
#endif

@ENDBASICHELP

The say command sends <message> to everyone listening within the current room.
However, if you are invisible, no one will be able to hear what you say.
ENDBASICHELP

#ifdef VERBS
@ENDLOUDNESSHELP
How you sound to others depends on how relatively loud you sound to others.
ENDLOUDNESSHELP
#endif

#ifdef LANGUAGES
@ENDLANGHELP
You may speak in a foreign tongue if you know it well enough.  Otherwise
you'll have to speak in your race's native language.
ENDLANGHELP
#endif
@HELP

See also: converse, speak, languages
HELP
    );
}
