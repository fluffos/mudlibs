// _mvemote.c -- Fantome @ TMI-2, Woodstock
// don't know why this was missing, so i added it (;

#include <config.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON;

int cmd_mvemote (string arg) {
  string verb, newverb, emotion;
  int temote;

  if (!arg || (sscanf (arg, "%s To %s", verb, newverb) != 2)) {
    notify_fail ("Usage:  mvemote <oldemotename> To <newemotename>\n");
    return 0;
  }
  if ((sscanf (verb, "%*s %*s") > 1) || (sscanf (newverb, "%*s %*s") > 1)) {
    notify_fail ("Verbs cannot have spaces in them.\n");
    return 0;
  }
  if (temote = sscanf (verb, "%s/t", verb))
    emotion = (string)EMOTE_D->query_temote (verb);
  else
    emotion = (string)EMOTE_D->query_emote (verb);
  if (!emotion) {
    notify_fail (sprintf ("Emotion '%s' does not exist.\n", verb));
    return 0;
  }
  if (temote) {
    EMOTE_D->delete_temote (verb);
    EMOTE_D->add_temote (newverb, emotion);
  } else {
    EMOTE_D->delete_emote (verb);
    EMOTE_D->add_emote (newverb, emotion);
  }
  write (sprintf ("Emotion '%s' renamed to '%s'.\n", verb, newverb));
  return 1;
}

int help() {
  write (@Help
Usage:  mvemote <argument> To <argument>

  The mvemote command allows you to rename emotions.  Sorry about the
To, but it is necessary to differentiate between potential emotions.

See also:  semote, temote, edemote, rmemote
Help
);
	return 1 ;
}
