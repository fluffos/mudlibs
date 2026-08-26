// Standard wedding ring, written by Chronos 1-95.
// Might not be finished.  Needs to be looked at.
// (08-27-96) Chronos modified and reorganized the code again.
//            - Made the spouse chat respect invisibility.  Mortals 
//              cannot find out if their spouses are logged in unless
//              the wizard reveals themself.
//            - Modified miss, added bkiss, hold, and caress and lkiss.
#include <mudlib.h>

inherit OBJECT;

void divorce();

void divorce() {
  environment()->delete("spouse");
  remove();
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
  set("prevent_clean", 1);
  set("prevent_get", 1);
  set("prevent_drop", 1);
  set("mass",1);
  set("bulk",1);
  set("armor", 0);
}

void init() {
  if (!userp(environment())) remove();
  add_action("miss", "miss");
  add_action("bkiss", "bkiss");
  add_action("lkiss", "lkiss");
  add_action("hold", "hold");
  add_action("caress", "caress");
  add_action("help", "help");
  add_action("chat", "-");
  add_action("chate", "--");
  set("extra_look",
   capitalize(possessive(environment()->query("gender"))) +
   " eyes sparkle with love for " + 
    capitalize((string)this_player()->query("spouse")) + ".\n");
}
 
void broadcast(string str) {
  object spouse;
  spouse = find_player(environment()->query("spouse"));
  if (spouse) {
   if (wizardp(spouse) && !wizardp(TP) && spouse->query("invisible")) {
      tell_object(environment(), "Alas, your spouse isn't logged in.\n");
      tell_object(spouse, "** You sense that your spouse wants to speak to you.\n");
      return ;
    }
    tell_object(spouse, str);
    tell_object(environment(), str);
  }
  else tell_object(environment(), "Alas, your spouse isn't logged in.\n");
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
        miss            Openly miss your spouse.
        bkiss           Blow a kiss to your spouse.
        hold            Hold your spouse.
        hold hands      Hold hands with your spouse
        caress          Caress your spouse.
        lkiss           Give your spouse a lover's kiss.

ENDLONG
  );
  return 1;
}
 
int caress(string str) {
  string spouse;
  object ob;
  spouse = capitalize(environment()->query("spouse"));
  ob = find_player(lower_case(spouse));
  if (!ob || ! present(lower_case(spouse), environment(TP))) {
    write("Your spouse is not here right now.\n");
    return 1;
  } 
  write("You lovingly caress "+spouse+"'s face.\n");
  say(TPN+" lovingly caresses "+spouse+"'s face.\n", ({ TP, ob }) );
  tell_object(ob, TPN+" lovingly caresses your face.\n");
  return 1;
}

int hold(string str) {
  string spouse;
  object ob;
  spouse = capitalize(environment()->query("spouse"));
  ob = find_player(lower_case(spouse));
  if (!ob || ! present(lower_case(spouse), environment(TP))) {
    write("Your spouse is not here right now.\n");
    return 1;
  } 
  if (str == "hands" || str == "hand") {
    write("You hold "+spouse+"'s hand.\n");
    say(TPN+" holds "+spouse+"'s hand.\n", ({ TP, ob }) );
    tell_object(ob, TPN+" holds your hand.\n");
    return 1;
  }
  write("You hold "+spouse+" tenderly.\n");
  say(TPN+" holds "+spouse+" tenderly.\n", ({ TP, ob }) );
  tell_object(ob, TPN+" holds you tenderly.\n");
  return 1;
}

int lkiss(string str) {
  string spouse;
  object ob;
  spouse = capitalize(environment()->query("spouse"));
  ob = find_player(lower_case(spouse));
  if (!ob || ! present(lower_case(spouse), environment(TP))) {
    write("Your spouse is not here right now.\n");
    return 1;
  } 
  write("Sparks fly as you give "+spouse+" a passionate kiss.\n");
  say("Sparks fly as "+TPN+" gives "+spouse+" a passionate kiss.\n", 
     ({ TP, ob }) );
  tell_object(ob, "Sparks fly as "+TPN+" gives you a passionate kiss.\n");
  return 1;
}

int bkiss(string str) {
  string spouse;
  object ob;
  spouse = capitalize(environment()->query("spouse"));
  ob = find_player(lower_case(spouse));
  if (!ob) {
    printf("%s is not logged in right now.\n", spouse);
    return 1;
  }
  if (!present(lower_case(spouse), environment(TP))) {
    write("You blow a kiss across the mud to  "+spouse+".\n");
    say(TPN+" blows a kiss across the mud to "+spouse+".\n");
    tell_object(ob, TPN+" blows you a kiss from across the mud.\n");
    return 1;
  }
  write("Your spouse is right here!\n");
  return 1;
}
  
int miss(string str) {
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
 
