/* Silent Movement Checker
 *
 * 5/17/04 - Earwax
 *
 * Coded this item to check for some suspected cheating.
 *
*/

#include <ansi.h>

#define SILENT HIB+"SILENT MOVE: "+NORM+NORM
#define LOG "stealth_checker"

status
main(string arg)
{
  object *obs;
  object ob;
  string *output;
  int i, siz;

  output = ({ });
  siz = sizeof(obs = users());

  for (i = 0; i < siz; i++)
  {
    if (!obs[i] || !environment(obs[i]))
      continue; /* Error prevention hopefully :) */

    /*
     * Check for presence of a silent movement object.
    */

    if (present("silent_move_object", obs[i]))
    {
      output += ({ SILENT + capitalize((string)obs[i]->query_real_name() )
        + " ("+capitalize((string)obs[i]->query_guild_name())+"/"
        + (int)obs[i]->query_invis()+")\n" });
      ob = first_inventory(obs[i]);

      /*
       * They have one, so figure out which item or items it is.
      */

      while(ob)
      {
        if ((status)ob->id("silent_move_object"))
          output += ({ "ITEM: "+object_name(ob)+": "
            + (ob->short() ? (string)ob->short() : "") + "\n" });

        ob = next_inventory(ob);
      }
    }

    /*
     * Check for null movement messages.
    */

    if (!((string)obs[i]->query_msgin()))
      output += ({ "NO MSGIN: "
        + capitalize((string)obs[i]->query_real_name()) + "\n" });

    if (!((string)obs[i]->query_msgout()))
      output += ({ "NO MSGOUT: "
        + capitalize((string)obs[i]->query_real_name()) + "\n" });
  }

  /* 
   * Output information gathered.
  */

  siz = sizeof(output);

  /* Nothing found, if check was manually done, notify user */
  if (!siz)
  {
    if (this_player())
      write("No stealth objects or null movement messages detected.\n");

    return 1;
  }

  if (this_player())
    write(HIG+"===============================================\n"+NORM+NORM);
  else
    log_file(LOG, "====== DETECTED AT "+ctime()+" ======\n");

  for (i = 0; i < siz; i++)
  {
    if (this_player())
      write(output[i]);
    else
      log_file(LOG, output[i]);    
  }

  if (this_player())
    write(HIG+"===============================================\n"+NORM+NORM);

  return 1;
}

/*
 * Item setup functions
*/

void reset(status arg) { return; }

status id(string arg) { return (arg == "checker"); }

string short() { return "Checker"; }

void long() { write("Syntax: check\n"); }

status get() { return 1; }

status drop() { return 1;}

void init() { add_action("main", "check"); }
