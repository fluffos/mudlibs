#pragma strong_types

#include <prop/room.h>  // Carador, Jul-1996
#include <grammar.h>
#include <describe.h>
#include <who.h>        // Chameloid, 03-Sep-1996
#include <tongue.h>     // Chameloid, 05-Dec-1996
#include <global_commands.h> // Ugh Mar-17-1998, added global_, Coogan, 02-May-2001
#include <libs.h>

#define COMM    COMMANDS_COMM
#define LOOK    COMMANDS_LOOK
#define MOVE    COMMANDS_MOVE
#define MISC    COMMANDS_MISC
#define COMBAT  COMMANDS_COMBAT
#define MONEY   COMMANDS_MONEY
#define SIT     COMMANDS_SIT
#define OPEN    COMMANDS_OPEN
#define MAGIC   COMMANDS_MAGIC
#define CONSUME COMMANDS_CONSUME // Coogan, 04-Feb-1998
#define SENSE   COMMANDS_SENSE   // Coogan, 04-Feb-1998

inherit "basic/create";
inherit "basic/daemon";
inherit "basic/parser";

string failure(string sentence, string *words);

// next function added by Chameloid, 03-Sep-1996

status parse_who_mode(mixed r,mixed a,int f,int l,string *w,string *t) {
  r=implode(w[f..l]," ");
  return member(WHO_MODES, r)>=0;
}

void create() {
  add_rule("glimpse",            "glimpse",     LOOK);  // Coogan, 07-Nov-2002
  add_rule("see",                "see",         LOOK);
  add_rule("look",               "look",        LOOK);
  add_rule("look "G_VIEW,        "look_view",   LOOK);
  add_rule("look into "G_OBJECT, "look_into",   LOOK);  // Coogan, 15-Apr-2003
  add_rule("look at "G_ALL,      "examine_all", LOOK);
  add_rule("examine "G_ALL,      "examine_all", LOOK);

  // these two macros must be the same as in LOOK!
#define OBJECT2 "<object2>"
#define LIVING2 "<living2>"

  duplicate_class(G_OBJECT,OBJECT2);
  duplicate_class(G_LIVING,LIVING2);
  add_rule("weigh "G_ONLY_IN_INVENTORY, "est_weight", LOOK);
  add_error_message("weigh",({ "Estimate the weight of what?\n",-1}));

#define DOITFOR2(prop,x,class1,class2)                              \
  add_rule("estimate "prop" of "class1, "est_"x,LOOK);              \
  add_rule("estimate "class1" ' s "prop, "est_"x,LOOK);             \
  add_rule("compare "prop" of "class1" and "class2,"cmp_"x,LOOK);   \
  add_rule("compare "class1" ' s and "class2" ' s "prop,"cmp_"x,LOOK)
#define DOITFOR(prop,class1,class2) DOITFOR2(prop,prop,class1,class2)

  DOITFOR("weight",            G_OBJECT,OBJECT2);
  DOITFOR("light",             G_OBJECT,OBJECT2);
  DOITFOR("value",             G_OBJECT,OBJECT2);
  DOITFOR("quality",           G_OBJECT,OBJECT2);
  DOITFOR("strength",          G_LIVING,LIVING2);
  DOITFOR2("str","strength",   G_LIVING,LIVING2);
  DOITFOR("condition",         G_LIVING,LIVING2);
  DOITFOR2("con","condition",  G_LIVING,LIVING2);
  DOITFOR("alignment",         G_LIVING,LIVING2);
  DOITFOR2("align","alignment",G_LIVING,LIVING2);
  DOITFOR("age",               G_LIVING,LIVING2);
  DOITFOR("load",              G_LIVING,LIVING2);
  DOITFOR("weapon",            G_LIVING,LIVING2);
  DOITFOR("armour",            G_LIVING,LIVING2);
  DOITFOR("health",            G_LIVING,LIVING2);

#undef DOITFOR
#undef DOITFOR2

  add_rule("estimate health", "est_health", LOOK);  // for in fight
  add_rule("compare health",  "cmp_health", LOOK);  // for in fight
  add_error_message("estimate",
                    ({ "You can estimate the weight, the light, the value and"
                       " the quality of an item.  You also can estimate the"
                       " strength, the condition, the alignment, the age, the"
                       " load, the weapon, the armour and the health of a"
                       " living.\n",-1 }));
  add_error_message("compare",
                    ({ "You can compare the weight, the light, the value and"
                       " the quality of two items.  You also can compare the"
                       " strength, the condition, the alignment, the age, the"
                       " load, the weapon, the armour and the health of two"
                       " livings.\n",-1 }));
  add_rule("show "G_IN_INVENTORY" to "G_LIVING, "show",             LOOK);
  add_rule("show "G_LIVING" "G_IN_INVENTORY,    "show",             LOOK);
  // added next two rules, Coogan, 21-May-2004
  add_rule("show "G_ALL_IN_INVENTORY" to "G_LIVING, "show_all",     LOOK);
  add_rule("show "G_LIVING" "G_ALL_IN_INVENTORY,    "show_all",     LOOK);
  add_rule("look at place",                     "examine_place",    LOOK);
  add_rule("examine place",                     "examine_place",    LOOK);
  add_rule("inventory",                         "inventory",        LOOK);
  add_rule("inventory of "G_ALL,                "inventory",        LOOK);
  add_rule("inventory "G_ALL,                   "inventory",        LOOK);
  add_rule("i",                                 "inventory",        LOOK);
  add_rule("i "G_ALL,                           "inventory",        LOOK);
  add_rule("equipment",                         "equipment",        LOOK);
  add_rule("equipment of "G_ALL,                "equipment",        LOOK);
  add_rule("equipment "G_ALL,                   "equipment",        LOOK);
  add_rule("eq",                                "equipment",        LOOK);
  add_rule("eq "G_ALL,                          "equipment",        LOOK);
  add_rule("toggle map",                        "toggle_map",       LOOK);
  add_rule("toggle inventory",                  "toggle_inventory", LOOK);
  add_rule("toggle look",                       "toggle_combined",  LOOK);
  add_rule("toggle encoding",                   "toggle_encoding",  MISC);
  add_rule("toggle inputencoding",         "toggle_inputencoding",  MISC);
  add_rule("toggle",                            "toggle",           MISC);
#if 0
  add_error_message("look", ({"Look at what?\n",-1}));
#else
// Carador, Jul-1996
  add_error_message("look", #'failure);
  add_error_message("examine", #'failure);
#endif
  
  add_error_message("show", ({"Show what to whom or show whom what?\n",-1}));
   // Chameloid, 07-Jun-1996
  add_error_message("weigh",
                    ({ "Weigh what?  You can only weigh what you hold in your"
                       " hands.\n",-1 }));
   // Chameloid, 07-Jul-1996

  add_rule("away ? "G_ANY_LIVING,   "away?", COMM);
  add_rule("absent ? "G_ANY_LIVING, "away?", COMM);
  add_rule("afk ? "G_ANY_LIVING,    "away?", COMM);  // Coogan, 27-Feb-2001

  // the following two rules are necessary to add the verbs with '?' appended
  add_rule("away? "G_ANY_LIVING,   "away?", COMM);
  add_rule("absent? "G_ANY_LIVING, "away?", COMM);
  add_rule("afk? "G_ANY_LIVING,    "away?", COMM);  // Coogan, 27-Feb-2001

  add_rule("away "G_TEXT,   "away", COMM); // Alfe 1995-Mar-29
  add_rule("absent "G_TEXT, "away", COMM); // Alfe 1995-Mar-29
  add_rule("afk "G_TEXT,    "away", COMM); // Coogan, 27-Feb-2001
  add_error_message("away",({"Mark yourself as being absent with "
                             "what message or test whom for being marked as "
                             "being absent?\n",-1})); // Chameloid, 28-Oct-1997
  add_error_message("absent",({"Mark yourself as being absent with "
                               "what message or test whom for being marked as "
                               "being absent?\n",-1})); // Chameloid, 28-Oct-1997
  add_error_message("afk",({"Mark yourself as being absent with "
                            "what message or test whom for being marked as "
                            "being absent?\n",-1})); // Alfe 01-Jul-11
                             
  add_rule("speak in "G_TONGUE, "speak_tongue", COMM);
  add_rule("speak "G_TONGUE,    "speak_tongue", COMM);
  add_error_message("speak",
     (: string *tongues;
        tongues = map(TONGUES, 
                      (: int r;
                         r = LIB_TONGUE->can_speak(this_player(), $1);
                         return r && capitalize($1); :)) - ({ 0 });
        return ({ "Speak in which language? You " +
                  (sizeof(tongues) == 0
                  ? "don't know any language.\n"
                  : (sizeof(tongues) == 1 ? "only " : "") + "know " +
                    make_list(tongues, "Hmm", " and ") + ".\n"), 0 }); :)); 
      // Chameloid, 05-Dec-1996; inlines added, Coogan, 30-Jan-2002

  // Alfe 1996-May-29
  add_rule("say in "G_TONGUE" \" "G_TEXT" \" to "G_ALL_LIVINGS, "say", COMM);
  add_rule("say in "G_TONGUE" \" "G_TEXT" \"","say",COMM);
  add_rule("say in "G_TONGUE" \" "G_TEXT,"say",COMM);
  add_rule("say in "G_TONGUE" "G_TEXT,"say",COMM);
  add_rule("say to "G_ALL_LIVINGS" in "G_TONGUE" \" "G_TEXT" \"", "say", COMM);
  add_rule("say to "G_ALL_LIVINGS" in "G_TONGUE" \" "G_TEXT, "say", COMM);
  add_rule("say to "G_ALL_LIVINGS" in "G_TONGUE" "G_TEXT, "say", COMM);
  add_rule("say \" "G_TEXT" \" to "G_ALL_LIVINGS, "say", COMM);
  add_rule("say to "G_ALL_LIVINGS" \" "G_TEXT" \"", "say", COMM);
  add_rule("say to "G_ALL_LIVINGS" \" "G_TEXT, "say", COMM);
  add_rule("say to "G_ALL_LIVINGS" "G_TEXT, "say", COMM);
  add_rule("say \" "G_TEXT" \"","say",COMM);
  add_rule("say "G_TEXT,"say",COMM);
  add_rule("to "G_ALL_LIVINGS" ' "G_TEXT, "say", COMM);  // Alfe 1995-Oct-19
  add_rule("to "G_ALL_LIVINGS" in "G_TONGUE" say "G_TEXT, "say", COMM);
  add_rule("to "G_ALL_LIVINGS" in "G_TONGUE" ' "G_TEXT, "say", COMM);
  add_rule("to "G_ALL_LIVINGS" say in "G_TONGUE" \" "G_TEXT" \"", "say", COMM);
  add_rule("to "G_ALL_LIVINGS" say in "G_TONGUE" \" "G_TEXT,      "say", COMM);
  add_rule("to "G_ALL_LIVINGS" say in "G_TONGUE" "G_TEXT,         "say", COMM);
  add_rule("to "G_ALL_LIVINGS" say \" "G_TEXT" \"",               "say", COMM);
  add_rule("to "G_ALL_LIVINGS" say "G_TEXT,                       "say", COMM);

  add_error_message("say" , ({"Say what?\n",-1}));
#if __START_TIME__ < "970701000000"
  add_rule("tell "G_AMBIG_LIVINGS" "G_TEXT,"tell",COMM);
  add_rule("tell", "Tell whom what?\n");
#endif

  // added 'at' versions for 'shout to players' parser rules,
  //   Chameloid, 31-Jan-1997
  // added some more rules and the TONGUE-rules, Coogan, 21-Jan-2002
  add_rule("shout at "G_ANY_LIVINGS" \" "G_TEXT" \"", "shout_at", COMM);
  add_rule("shout at "G_ANY_LIVINGS" \" "G_TEXT,      "shout_at", COMM);
  add_rule("shout at "G_ANY_LIVINGS" "G_TEXT,         "shout_at", COMM);
  add_rule("shout \" "G_TEXT" \" at "G_ANY_LIVINGS,   "shout_at", COMM);

  add_rule("shout to players \" "G_TEXT" \"", "shout_pl", COMM);
  add_rule("shout to players \" "G_TEXT,      "shout_pl", COMM);
  add_rule("shout to players "G_TEXT,         "shout_pl", COMM);
  add_rule("shout \" "G_TEXT" \" to players", "shout_pl", COMM);

  add_rule("shout at players \" "G_TEXT" \"", "shout_pl", COMM);
  add_rule("shout at players \" "G_TEXT,      "shout_pl", COMM);
  add_rule("shout at players "G_TEXT,         "shout_pl", COMM);
  add_rule("shout \" "G_TEXT" \" at players", "shout_pl", COMM);

  add_rule("shout to wizards \" "G_TEXT" \"", "shout_wiz", COMM);
  add_rule("shout to wizards \" "G_TEXT,      "shout_wiz", COMM);
  add_rule("shout to wizards "G_TEXT,         "shout_wiz", COMM);
  add_rule("shout \" "G_TEXT" \" to wizards", "shout_wiz", COMM);

  add_rule("shout at wizards \" "G_TEXT" \"", "shout_wiz", COMM);
  add_rule("shout at wizards \" "G_TEXT,      "shout_wiz", COMM);
  add_rule("shout at wizards "G_TEXT,         "shout_wiz", COMM);
  add_rule("shout \" "G_TEXT" \" at wizards", "shout_wiz", COMM);

  add_rule("shout in "G_TONGUE" \" "G_TEXT,    "shout", COMM);
  add_rule("shout in "G_TONGUE" "G_TEXT,       "shout", COMM);
  add_rule("shout \" "G_TEXT" \" in "G_TONGUE, "shout", COMM);

  add_rule("shout "G_TEXT,                     "shout", COMM);

  add_error_message("shout",
      ({"Shout \""G_TEXT"\" to wizards/players? Shout what [at whom]?\n",-1}));

  add_rule("whisper to "G_ALL_LIVINGS" in "G_TONGUE" "G_TEXT, "whisper", COMM);
  add_rule("whisper \" "G_TEXT" \" to "G_ALL_LIVINGS" in "G_TONGUE,"whisper",
           COMM);
  add_rule("whisper "G_ALL_LIVINGS" in "G_TONGUE" "G_TEXT, "whisper", COMM);
  add_rule("whisper to "G_ALL_LIVINGS" "G_TEXT, "whisper", COMM);
  add_rule("whisper \" "G_TEXT" \" to "G_ALL_LIVINGS,"whisper", COMM);
  add_rule("whisper "G_ALL_LIVINGS" "G_TEXT, "whisper", COMM);
  add_error_message("whisper",
                    ({ "Whisper \""G_TEXT"\" to whom? Whisper whom what?\n",
                       -1 }));

  add_rule("ask "G_ALL_LIVINGS" in "G_TONGUE" about "G_TEXT,"ask_about",COMM);
  add_rule("ask "G_ALL_LIVINGS" in "G_TONGUE" for "G_TEXT, "ask_for", COMM);
  add_rule("ask "G_ALL_LIVINGS" in "G_TONGUE" to "G_TEXT, "ask_to", COMM);
  add_rule("ask "G_ALL_LIVINGS" about "G_TEXT, "ask_about", COMM);
  add_rule("ask "G_ALL_LIVINGS" for "G_TEXT, "ask_for", COMM);
  add_rule("ask "G_ALL_LIVINGS" to "G_TEXT, "ask_to", COMM);
  add_error_message("ask", ({"Ask whom for|about|to what?\n",-1}));

  add_rule("emote "G_TEXT,"emote",COMM);
  add_error_message("emote", ({"Emote what?\n",-1}));
  add_rule("me "G_TEXT,"emote",COMM);
  add_error_message("me", ({"Me what?\n",-1}));
  add_rule(": "G_TEXT, "emote", COMM);

  add_rule("toggle echo","toggle_echo",COMM);
  add_rule("score","score",MISC);              // activated, Carador, Aug-1996

#if 0
  add_rule("skills", "skills", MISC);
  add_rule("save","save",MISC);
  add_rule("quit","quit",MISC);
  add_rule("brief", "brief", MISC);
#endif

  add_rule("toggle fails",  "toggle_fails",  MISC);  // Alfe 1998-Mar-18
  add_rule("toggle output", "toggle_output", MISC);
  add_rule("toggle more",   "toggle_more",   MISC);
  add_rule("toggle history","toggle_history",MISC);
  add_rule("toggle monitor","toggle_monitor",MISC);  // Carador, Aug-1996
  add_rule("toggle who",    "toggle_who",    MISC);  // Chameloid, 28-Aug-1996
  add_rule("toggle autoloads", "toggle_hide_autoloads", COMMANDS_LOOK);
                                                     // Coogan, 28-Apr-1999
  add_rule("toggle resize", "toggle_resize", MISC);  // Coogan, 24-Oct-2002

  add_class(WHO_MODE_PARSER_CLASS, "parse_who_mode"); // Chameloid, 03-Sep-1996

  // next four rules added by Chameloid, 03-Sep-1996
  add_rule("who "WHO_MODE_PARSER_CLASS" "G_AMBIG_LIVINGS, "who", MISC);
  add_rule("who "WHO_MODE_PARSER_CLASS,                   "who", MISC);
  add_rule("who "G_AMBIG_LIVINGS,                         "who", MISC);
  add_rule("who",                                         "who", MISC);

  add_error_message("who",
                    ({ ("Usage: who [" + implode(WHO_MODES, "|") + "] "
                        "[<groups>]\n"),-1 })); // Chameloid, 03-Sep-1996

  add_rule("help", "help", MISC);
  add_rule("help "G_TEXT, "help", MISC);
  add_rule("webster "G_TEXT,"webster",MISC);  // Alfe 1996-Sep-3
  add_error_message("webster",({ "See 'help webster' for proper usage.\n",
                                 -1 }));

  add_rule("report bug here : "G_TEXT, "bug", MISC);
  add_rule("report typo here : "G_TEXT, "typo", MISC);
  add_rule("report idea here : "G_TEXT, "idea", MISC);
  add_rule("report praise here : "G_TEXT, "praise", MISC);
  add_rule("report bug here", "bug", MISC);
  add_rule("report typo here", "typo", MISC);
  add_rule("report idea here", "idea", MISC);
  add_rule("report praise here", "praise", MISC);
  add_rule("report bug "G_INDIRECT, "bug", MISC);
  add_rule("report typo "G_INDIRECT, "typo", MISC);
  add_rule("report idea "G_INDIRECT, "idea", MISC);
  add_rule("report praise "G_INDIRECT, "praise", MISC);
  add_rule("report bug "G_INDIRECT" : "G_TEXT, "bug", MISC);
  add_rule("report typo "G_INDIRECT" : "G_TEXT, "typo", MISC);
  add_rule("report idea "G_INDIRECT" : "G_TEXT, "idea", MISC);
  add_rule("report praise "G_INDIRECT" : "G_TEXT, "praise", MISC);
#if 1
  // Following shall only provide notify_fails for the commands 
  // 'bug', 'typo' and 'idea'. It's intended that they do not appear
  // in do_action. Carador, 18-Dec-1996.
  add_rule("bug "G_TEXT, "bug");
  add_error_message("bug", "\
Please use 'report bug' to report bugs. Read 'help report' for details.\n\
Example: report bug here : This room is buggy.\n");
  add_rule("idea "G_TEXT, "idea");
  add_error_message("idea", "\
Please use 'report idea' to report ideas. Read 'help report' for details.\n\
Example: report idea here : I want to do this-and-that.\n");
  add_rule("typo "G_TEXT, "typo");
  add_error_message("typo", "\
Please use 'report typo' to report typos. Read 'help report' for details.\n\
Example: report typo here : Check the spelling of 'foorblzxfras'.\n");
#endif
  add_rule("capitalize", "capitalize", MISC);
  add_rule("capitalize "G_TEXT, "capitalize", MISC);
  add_rule("xyzzy", "xyzzy", MISC);
  add_rule("email", "email", MISC);
  add_rule("email "G_TEXT, "email", MISC);
  add_rule("town", "town", MISC);
  add_rule("town "G_TEXT, "town", MISC);

  add_rule("beep "G_AMBIG_LIVINGS, "beep_player", COMM);
                                                        // Chameloid, 01-May-191996
  add_error_message("beep", ({ "Beep whom?\n", -1 }) );

  add_rule("toggle beep", "toggle_beep", COMM); // Chameloid, 16-Oct-1996
  
  add_error_message("report",
                    ({ "You may report a bug, typo, idea or praise like"
                       " this:\n"
                       "report <report_type> here\n"
                       "report <report_type> "G_OBJECT"\n"
                       "report <report_type> here : "G_TEXT"\n"
                       "report <report_type> "G_OBJECT" : "G_TEXT".\n",
                       -1 }));
  add_rule("verbose do", "toggle_verbose_do", MISC);
  add_error_message("verbose", ({"Try: verbose do\n",-1}));
  add_rule("do",        "do_command", MISC);
  add_rule("do "G_TEXT, "do_command", MISC);
  add_error_message("do",
                     ({ "Do <sequence of commands separated by ';'>\n", -1 }));

  add_rule("give "G_ALL_OBJECT" to "G_LIVING,  "give_all",  MOVE);
  add_rule("give "G_LIVING" "G_ALL_OBJECT,     "give_all",  MOVE);
  add_rule("offer "G_ALL_OBJECT" to "G_LIVING, "offer_all", MOVE);
  add_rule("offer "G_LIVING" "G_ALL_OBJECT,    "offer_all", MOVE);
  add_rule("offer "G_ALL_OBJECT,               "offer_all", MOVE);
  add_rule("offer",          "stop_offering",  MOVE);
  add_rule("stop offering",  "stop_offering",  MOVE);
  add_rule("toggle refuse",  "toggle_refuse",  MOVE);
  add_rule("stop accepting", "stop_accepting", MOVE);
  add_rule("refuse",         "stop_accepting", MOVE);
  add_error_message("refuse","Just 'refuse' to stop accepting everything.\n");

#if 0  // this is a test, Coogan, 13-Aug-2001
  add_rule("pick up "G_ALL_IN_ENVIRONMENT, "pick_up_all_test", MOVE);
  add_rule("pick up "G_ALL_IN_INVENTORY,   "pick_up_all_test", MOVE);
#endif
#if 0  // also temporarily
  add_rule("pick "G_ALL_INDIRECT" up", "pick_up_all",     MOVE);
  add_rule("pick up "G_ALL_INDIRECT,   "pick_up_all",     MOVE);
#endif
  add_rule("get "G_ALL_INDIRECT,       "take_all",        MOVE);
  add_rule("take "G_ALL_INDIRECT,      "take_all",        MOVE);
  add_rule("drop "G_ALL_OBJECT,        "drop_all",        MOVE);
  add_rule("empty "G_CONTAINER,        "empty",           MOVE);//Coogan,8-Jul03
  add_rule("put down "G_ALL_OBJECT,    "drop_all",        MOVE);
  add_rule("put "G_ALL_OBJECT" down",  "drop_all",        MOVE);
  add_rule("order inventory "G_TEXT,   "order_inventory", MOVE);

#ifndef G_CONTAINER // Ugh Apr-2-1998
#define G_CONTAINER "<container>"
  duplicate_class(G_OBJECT, G_CONTAINER);
#endif
  add_rule("put "G_ALL_OBJECT" into "G_CONTAINER,    "put_all_into", MOVE);
  add_rule("put "G_ALL_OBJECT" in "G_CONTAINER,      "put_all_into", MOVE);
  add_rule("put "G_ALL_OBJECT" onto "G_CONTAINER,    "put_all_on",   MOVE);
  add_rule("put "G_ALL_OBJECT" on "G_CONTAINER,      "put_all_on",   MOVE);
  add_rule("insert "G_ALL_OBJECT" into "G_CONTAINER, "put_all_into", MOVE);
  add_rule("insert "G_ALL_OBJECT" in "G_CONTAINER,   "put_all_into", MOVE);

  // 'open' and 'close' with handles by Coogan, 26-Mar-1998
  // joined cases with _handleless or _keyless with the normal cases
  // Ugh Mar-31-1998
  add_rule("open "G_INDIRECT" with "G_OBJECT,   "open",   OPEN);
  add_rule("open "G_INDIRECT,                   "open",   OPEN);
  add_error_message("open", "Open what?\n");
  add_rule("close "G_INDIRECT" with "G_OBJECT,  "close",  OPEN);
  add_rule("close "G_INDIRECT,                  "close",  OPEN);
  add_error_message("close", "Close what?\n");
  add_rule("unlock "G_INDIRECT" with "G_OBJECT, "unlock", OPEN);
  add_rule("unlock "G_INDIRECT,                 "unlock", OPEN);
  add_error_message("unlock", "Unlock what?\n");
  add_rule("lock "G_INDIRECT" with "G_OBJECT,   "lock",   OPEN);
  add_rule("lock "G_INDIRECT,                   "lock",   OPEN);
  add_error_message("lock", "Lock what?\n");

  add_rule("sit down", "sit_down", SIT);
  add_rule("sit "G_TEXT" "G_INDIRECT, "sit", SIT);
  add_rule("sit down "G_TEXT" "G_INDIRECT, "sit", SIT);
  add_rule("sit up", "sit_up", SIT);
  add_rule("sit up "G_TEXT" "G_INDIRECT, "sit_up_ob", SIT);
  add_error_message("sit", #'failure);
  add_rule("lie down", "lie_down", SIT);
  add_rule("lie "G_TEXT" "G_INDIRECT, "lie", SIT);
  add_rule("lie down "G_TEXT" "G_INDIRECT, "lie", SIT);
  add_error_message("lie", #'failure);
  add_rule("stand up", "stand_up", SIT);
  add_rule("stand up from "G_INDIRECT, "leave", SIT);
  add_error_message("stand", #'failure);
  add_rule("leave "G_INDIRECT, "leave", SIT);
  add_error_message("leave", #'failure);
  add_rule("get up", "stand_up", SIT);
  add_rule("get up from "G_INDIRECT, "leave", SIT);
  add_error_message("get", #'failure);

  add_rule("display", "display", MISC);  // Alfe 1996-Feb-1
  add_rule("display "G_WORD, "display", MISC);  // Alfe 1996-Feb-1
  add_rule("display "G_WORD" "G_TEXT, "display", MISC);  // Alfe 1996-Feb-1

  // all consume stuff by Coogan, 03-Feb-1998
  // more eat stuff added, Coogan, 06-Feb-1998
  add_rule("eat mouthful of "G_IN_INVENTORY,     "eat",   CONSUME);
  add_rule("eat mouthful of "G_IN_ENVIRONMENT,   "eat",   CONSUME);
  add_rule("eat piece of "G_IN_INVENTORY,        "eat",   CONSUME);
  add_rule("eat piece of "G_IN_ENVIRONMENT,      "eat",   CONSUME);
  add_rule("eat "G_NUMBER" mouthful of "G_IN_INVENTORY,   "eat", CONSUME);
  add_rule("eat "G_NUMBER" mouthful of "G_IN_ENVIRONMENT, "eat", CONSUME);
  add_rule("eat "G_NUMBER" pieces of "G_IN_INVENTORY,     "eat", CONSUME);
  add_rule("eat "G_NUMBER" pieces of "G_IN_ENVIRONMENT,   "eat", CONSUME);
  add_rule("drink mouthful of "G_IN_INVENTORY,   "drink", CONSUME);
  add_rule("drink mouthful of "G_IN_ENVIRONMENT, "drink", CONSUME);
  add_rule("slurp mouthful of "G_IN_INVENTORY,   "slurp", CONSUME);
  add_rule("slurp mouthful of "G_IN_ENVIRONMENT, "slurp", CONSUME);
  add_rule("sip "G_IN_INVENTORY,                 "sip",   CONSUME);
  add_rule("sip "G_IN_ENVIRONMENT,               "sip",   CONSUME);

  add_rule("eat "G_IN_INVENTORY,     "eat_all",   CONSUME);
  add_rule("eat "G_IN_ENVIRONMENT,   "eat_all",   CONSUME);  // error handling
  add_rule("drink "G_IN_INVENTORY,   "drink_all", CONSUME);
  add_rule("drink "G_IN_ENVIRONMENT, "drink_all", CONSUME);  // for fakeitems
  add_rule("slurp "G_IN_INVENTORY,   "slurp_all", CONSUME);  // error handling
  add_rule("slurp "G_IN_ENVIRONMENT, "slurp_all", CONSUME);

  add_error_message("eat",   "Eat what?\n");
  add_error_message("drink", "Drink what?\n");
  add_error_message("slurp", "Slurp what?\n");
  add_error_message("sip",   "Sip what?\n");

  add_rule("taste "G_OBJECT,    "taste", SENSE);
  add_rule("lick "G_OBJECT,     "lick",  SENSE);
  add_rule("sniff at "G_OBJECT, "sniff", SENSE);
  add_rule("sniff "G_OBJECT,    "sniff", SENSE);
  add_rule("smell "G_OBJECT,    "smell", SENSE);

  add_rule("sniff here", "sniff", SENSE);
  add_rule("sniff air",  "sniff", SENSE);
  add_rule("smell here", "smell", SENSE);
  add_rule("smell air",  "smell", SENSE);

  add_error_message("taste", "Taste what?\n");
  add_error_message("lick",  "Lick what?\n");
  add_error_message("sniff", "Sniff at what?\n");
  add_error_message("smell", "Smell what?\n");

  add_rule("listen to "G_OBJECT, "listen", SENSE);
  add_rule("listen here",        "listen", SENSE);
  add_rule("listen "G_OBJECT,    "listen", SENSE);  // Coogan, 15-Aug-2006
  // add_rule("listen",             "listen", SENSE);

  add_error_message("listen", "Listen where or to whom or what?\n");

  add_rule("break up "G_IN_INVENTORY,                 "break", MISC);
  add_rule("break "G_IN_INVENTORY,                    "break", MISC);
  add_rule("break "G_IN_INVENTORY" with "G_OBJECT,    "break", MISC);
  add_rule("smash up "G_IN_INVENTORY,                 "smash", MISC);
  add_rule("smash "G_IN_INVENTORY,                    "smash", MISC);
  add_rule("smash "G_IN_INVENTORY" against "G_OBJECT, "smash", MISC);

  add_error_message("break", ({ "Break up what?\n", -1 }));
  add_error_message("smash", ({ "Smash up what, or smash what against "
                                "what?\n", -1 }));

  add_rule("fly","fly",MOVE);
  add_error_message("fly", ({ "Try just 'fly'.\n", -1 }));
  
  add_rule("reference "G_OBJECT" as "G_WORD, "reference", MISC);
  add_rule("refer to "G_OBJECT" as "G_WORD, "reference", MISC);
  add_rule("references", "references", MISC);
  add_rule("remove reference "G_WORD, "remove_reference", MISC);

  filter(query_rule_verbs(),
               lambda(({ 'v }), ({ #'add_command, "parse_cmd", 'v })));
}

int parse_cmd(string arg, string verb)
{
  return parse_sentence(arg ? verb + " " + arg : verb);
}

// sunblood 22-jun-1999
string notify_missing_item(string item, string crea) {
  log_file(crea + ".items", 
      ctime() + ": " +
      load_name(environment(this_player())) + ", " +
      item + "\n");
  return "You see nothing special.\n";
}

mixed failure(string sentence, string *words) {
  mixed h; // Chameloid, 17-Aug-1996
  mixed last_item;
  string crea, item, desc;

  switch (words[0]) {
  case "sit":
    if (sizeof(words) == 1)
      return "Sit down or up where?\n";
    else {
      switch (words[1]) {
      case "down":
      case "up":
        switch (sizeof(words)) {
        case 2:
          return capitalize(implode(words[0..2]," "))+
                            " on or in what?\n";
        default:
          switch (words[2]) {
          case "on":
          case "in":
            if (sizeof(words) == 3)
              return capitalize(implode(words[0..3]," ")) + " what?\n";
            else
              return "There is no "+
                describe(implode(words[3..]," "),ARTICLE_NONE)+" here.\n";
          default:
            return "Sit "+words[1]+" on or in what?\n";
          }
        }
        break;
      case "on":
      case "in":
        if (sizeof(words) == 2)
          return "Sit "+words[1]+" what?\n";
        else
          return ("There is no "+
                  describe(implode(words[2..]," "),ARTICLE_NONE)+" here.\n");
      default:
        return "Sit down or up where?\n";
      }
    }
    return "Sit where?\n";

  case "lie":
    if (sizeof(words) == 1)
      return "Lie down where?\n";
    else
    {
      switch (words[1])
      {
      case "down":
        switch (sizeof(words))
        {
        case 2: return capitalize(implode(words[0..2]," "))+
                        " on or in what?\n";
        default:
          switch (words[2])
          {
          case "on":
          case "in":
            if (sizeof(words) == 3)
              return capitalize(implode(words[0..3]," ")) + " what?\n";
            else
              return "There is no "+
                describe(implode(words[3..]," "),ARTICLE_NONE)+" here.\n";
          default:
            return "Lie "+words[1]+" on or in what?\n";
          }
        }
      case "on":
      case "in":
        if (sizeof(words) == 2)
          return "Lie "+words[1]+" what?\n";
        else return "There is no "+
              describe(implode(words[2..]," "),ARTICLE_NONE)+" here.\n";
      default: return "Lie down where?\n";
      }
    }
    return "Lie where?\n";
  case "take":  // Coogan, 13-Aug-2001
    return "Take what or take what from what?\n";
  case "stand":
  case "get":
    switch (sizeof(words))
    {
    case 1:
    case 2:
    case 3:
      if (words[0] == "get") {
        if (sizeof(words) > 1)
          return "Get what or up from what?\n";
        else  // added this branch, Coogan, 13-Aug-2001
          return "Get what of get what from what?\n";
      }
      return capitalize(words[0])+" up from what?\n";
    default:
      if (words[1] == "up" && words[2] == "from")
        return "There is no "+describe(implode(words[3..]," "),ARTICLE_NONE)+
                " here.\n";
      if (words[0] == "get")
        return "Get what or up from what?\n";
    }
    return capitalize(words[0])+" up?\n";

  case "look" :   // Carador, Jul-1996
  case "examine" :
    if ( this_player() &&
         environment(this_player()) &&
         (h=environment(this_player())->query_property(P_LOG_ITEMS)) &&
            // assignment added for evaluation of a possibly given string
            // other than the creator string for the logfile,
            // Chameloid, 17-Aug-1996
         (crea = creator(environment(this_player())) || "Corelib")
                                                       // Chameloid, 01-Sep-1996
       ) {
      if ( words[0] == "examine" &&
           sizeof(words) > 1
         ) item = implode(words[1..], " ");
      else if ( words[0] == "look" &&
                sizeof(words) > 2
              ) item = implode(words[2..], " ");

      if (item) {
        item = lower_case(describe(item, ARTICLE_NONE));
        if ( strstr(lower_case(" "+environment(this_player())->query_room_long()
                                 || ""), " " + item + " ") > -1 ||
             ( (last_item = this_player()->query_last_referenced("item")) &&
               stringp(last_item) &&
               (desc = environment(this_player())->long(last_item)) &&
               strstr(" " + lower_case(desc), " " + item + " ") > -1
               // added the '+ " "' here and 4 lines above to prevent
               // matching of unfinished item-words for items (aka 'x chur'
               // for 'x church', resulting in a 'You see nothing special.'
               // Coogan, 17-Oct-2000
             )
           ) 
        {
#if 0 // sunblood, 22-jun-1999
          log_file((stringp(h)?h:crea) + ".items", 
                         // ?-clause added by Chameloid, 17-Aug-1996 
                 ctime() + ": " +
                 load_name(environment(this_player())) + ", " +
                 item + "\n");
          return "You see nothing special.\n";
#else
          return lambda(0, ({ #'notify_missing_item, item, 
                                        (stringp(h) ? h : crea) }));
#endif
        }
      }
    }
    return "Look at what?\n";
  }
  return 0;
}

