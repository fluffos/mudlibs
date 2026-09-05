string cap_name, *adverb_list;
object the_owner;

status valid_adverb(string s);
status abbr(string s1, string s2);

void reset(status arg) {
  if (!arg) {
    adverb_list = ({
#include "/include/adverbs.h"
    });
  }
}

status soul_command(string verb, string str, string player_name) {
  object ob;
  string adv, who;

  cap_name = player_name;
  the_owner = this_player();

  if (str) {
    if (sscanf(str, "%s %s", who, adv) != 2)
      who = str;
    ob = present(lower_case(who), environment(this_player()));
    if (ob == this_player()) {
      write("You must be awfully bored.\n");
      return 1;
    }
    if (!ob || !living(ob)) {
      adv = who;
      ob = 0;
    }
    adv = adv ? valid_adverb(adv) : 0;
  }
  return call_other(this_object(), verb, ob, adv);
}

status valid_adverb(string s) {
  int i;

  for (i = 0; i < sizeof(adverb_list); i++)
    if (abbr(s, adverb_list[i])) {
      return adverb_list[i]);
    }
  return 0;
}

status abbr(string s1, string s2) {
  if (strlen(s1) < 4) return 0;
  return s2[0..strlen(s1)-1] == s1;
}

/***************************************************************************/

int ack(object ob, string adv) {
  string ob_name;

  if (ob) {
    write("How do you ack someone else?\n");
    return 1;
  }
  write("You ack " + (adv ? adv : "noisily") + ".\n");
  say(cap_name + " acks " + (adv ? adv : "noisily") + ".\n");
  return 1;
}

int agree(object ob, string adv) {
  string ob_name;

  if (!ob && !adv) {
    write("You agree wholeheartedly.\n");
    say(cap_name + " agrees wholeheartedly.\n");
    return 1;
  }
  if (ob) {
    tell_object(ob, cap_name + " agrees with you " +
                (adv ? " " + adv : "") + ".\n");
    ob_name = interactive(ob) ? ob->query_name() : ob->short();
  }
  write("You agree" + (ob ? " with " + ob_name : "") +
        (adv ? " " + adv : "") + ".\n");
  say(cap_name + " agrees " + (ob ? " with " + ob_name : "") +
      (adv ? " " + adv : "") + ".\n", ob ? ob : this_object());
  return 1;
}

