// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** cmd.c -- general command processing
*/

#include <mudlib.h>
#include <daemons.h>
#include <commands.h>

object query_link();            // in /std/body.c
void force_look();          // in /std/body.c
string move(object location);       // in /std/object/move.c
mixed expand_if_alias(string input);    // in /std/body/alias.c
object query_mailer();          // in /std/body/mailbase.c


/* forward decl */
string history_and_alias_processing( string arg );


private nosave string * nonsense_msgs;

string nonsense()
{
    if (!nonsense_msgs)
    nonsense_msgs = MESSAGES_D->get_messages("nonsense");
    return choice(nonsense_msgs);
}

varargs nomask int do_game_command(string str, int debug)
{
    mixed result;
    mixed go_result;

    /*
    ** We can't try parsing the user has no environment.  We should
    ** move them to the VOID area and continue processing.
    */
    if ( !environment(this_object()) )
    {
    //write("Oops!  You're lost.  Moving to the void...\n");
    write("噢呀，你迷失了，只好送你去极乐世界了。。。\n");
    move(load_object(VOID_ROOM));
    force_look();
    }

//###Tmp hack, load the verb if not already loaded.
#if 0
    if(sscanf(str,"%s %s", result, tmp) > 0)
    load_object(CMD_DIR_VERBS+"/"+result);
    else
    load_object(CMD_DIR_VERBS+"/"+str);
#endif

    /*
    ** Parse the player's input
    */
    if (!str) return 1;
    result = parse_sentence(str, debug);


    /*
    ** If a string was returned, then the parser figured something out.
    ** Write it out and we're done.
    */

    if ( stringp(result) )
    {
     if(debug)
    return result;
    write(result);
    return 1;
    }

    /*
    ** If the result is 0, the parser didn't know the verb so we keep looking.
    *  If a 1 was returned, then nothing more needs to be done.
    ** If the result is -1 or -2, the parser figured something was wrong.
    **
    */

    switch(result)
      {
      case 0:
    break;
      case 1:
    return 1;
      case -1:
    write(nonsense());
    return 1;
      case -2:
    //write("You aren't able to do that.\n");
    write("你不可以这样做。\n");
    return 1;
      default:
    write("This parser code should never be reached. If it is, let "
          "someone know how you got here.\n");
    return 1;
      }


    // If in debug mode, we're done
    if (debug) return 1;

    /*
    ** Check if they typed an exit
    */
    go_result = parse_sentence("go " + str);
    if (go_result == 1)
        return 1;
    if (!result)
        result = go_result;

    /* 'You can't go ...' is a parser generated message for general
       failure.  The go command is careful to return explicit
       error messages if the command makes sense, so we can safely
       ignore it. */
    if (stringp(result) && result[0..12] != "You can't go ") {
        write(result);
        return 1;
    }
    return 0;
}

nomask void force_game_command(string str)
{
    // set_this_player() only exists in this driver's #else branch of
    // #ifndef NO_ADD_ACTION (core.spec) -- this build has add_action
    // available instead, so the efun this mudlib's custom parser
    // (do_game_command -> parse_sentence) actually needs to run on
    // someone ELSE's behalf isn't there. parse_sentence() hard-requires
    // a valid this_player() (parser package: "No this_player()!"), so
    // rather than crash every call site (all "look" on mount/board),
    // just skip running it when we're not already in a usable
    // this_player() context instead of pretending to switch into one.
    if (!this_player()) return;
    if (!do_game_command(str))
        write(nonsense());
}

