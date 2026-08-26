// _rmemote.c -- Fantome @ TMI-2, Woodstock
// don't know why this was missing, so i added it (;

#include <config.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON;

int cmd_rmemote (string arg) {
  string verb, emotion;
  int temote;

  if (!arg) {
    notify_fail ("Usage:  rmemote emote_name\n");
    return 0;
  }
  if (sscanf (arg, "%*s %*s") > 1) {
    write ("Verbs cannot have spaces in them.\n");
    return 1;
  }
  if (temote = sscanf (arg, "%s/t", verb))
    emotion = (string)EMOTE_D->query_temote (verb);
  else {
    verb = arg;
    emotion = (string)EMOTE_D->query_emote (verb);
  }
  if (!emotion) {
    notify_fail (sprintf ("Emotion '%s' does not exist.\n", verb));
    return 0;
  }
  if (temote)
    EMOTE_D->delete_temote (verb);
  else
    EMOTE_D->delete_emote (verb);
  write (sprintf ("Emotion '%s' removed from the soul.\n", verb));
  return 1;
}

int help() {
  write (@Help
Usage:  rmemote <argument>

  The rmemote command allows you to remove bad or misspelled soul commands.

See also:  semote, temote, edemote, mvemote
Help
);
	return 1 ;
}
