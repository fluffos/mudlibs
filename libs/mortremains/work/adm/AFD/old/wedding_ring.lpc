// Standard wedding ring, written by Chronos 1-95.
#include <mudlib.h>

inherit OBJECT;

void divorce();

void divorce() {
  environment()->delete("spouse");
  this_object()->remove();
  return;
}

void broadcast(string str);

void create() { 
  seteuid(getuid());
  set("id", ({ "diamond ring", "ring", "wedding_band", "wedding ring" }) );
  set("short", "a sparkling wedding ring");
  set("long", @ENDLONG
It's an absolutely beautiful diamond ring, signifying the martimonial
bond between two loved ones.
(Type "help ring" for help.)
ENDLONG
);
  set("prevent_insert", 1);
  set("silent_look", 1);
  set("prevent_get", 1);
  set("prevent_drop", 1);
  set("mass",1);
  set("bulk",1);
  set("armor", 0);
}

void init() {
  add_action("miss", "miss");
  set("extra_look",
   capitalize(possessive(environment()->query("gender"))) +
   " eyes sparkle with love for " + 
    capitalize((string)this_player()->query("spouse")) + ".\n");
  add_action("help", "help");
/*
  add_action("love", "love");
*/
  add_action("chat", "-");
  add_action("chate", "--");
  if (!userp(environment())) remove();
}
 
void broadcast(string str) {
  object spouse;
  spouse = find_player(environment()->query("spouse"));
  if (spouse) tell_object(spouse, str);
  else tell_object(environment(), "Your spouse is not here...\n");
  tell_object(environment(), str);
  return;
}

int chat(string str) {
  if (!str) {
    write("  Usage: - <message>\n");
    return 1;
  }
  else str = "-"+ TPN + "- : " + str + "\n";
  broadcast(str);
  return 1;
}
 
int chate(string str) {
  if (!str) {
    write("  Usage: -: <feeling>\n");
    return 1;
  }
  else str = "-"+TPN +" "+str+ "-\n";
  broadcast(str);
  return 1;
}

int help(string str) {
  if (str != "ring") return 0;
  write(@ENDLONG
The following commands are valid : 

                -               Chat with spouse.
                --              Emote to spouse.
                love  -Removed- You love your spouse.
                miss            You miss your spouse.

ENDLONG
  );
  return 1;
}
 

int miss() {
  if (!present(environment()->query("spouse"), environment(environment()))) {
    write("You miss "+capitalize(environment()->query("spouse"))+".\n");
  say(TPN+" misses "+capitalize(environment()->query("spouse"))+".\n");
    return 1;
  }
  write("Your spouse is right here!\n");
  return 1;
}
query_auto_load() {
  return "/std/wedding_ring:";
}
