//  Filtration System for fucking potty mouths.  Damn those sons of a bitches!
//   Whit
//
//  Extended a bit by Nulvect

#include <daemons.h>
#include <guild.h>

// if someone changes these words, be sure to update the daemon
#define WORDS ({ \
  "fuck", "blowjob", "pussy", \
  "damn", "vagina", "nipple", \
  "dammit", "shit", "bitch", \
  "cunt", "nigger", "whore", \
  "fag", "dick", "cock", \
  "piss", \
})
#define LINES ({\
  "newbie", "hm", "elite",\
  "fighter", "mage", "rogue",\
  "clergy", "wanderer", "dragon",\
  "gossip", "OOC", "colosseum",\
  "trivia", "angel", "demon",\
  "lich", "vampire", "guild",\
  "council", "shout",\
})
#define CLASS_NO_CENSOR ({\
  "room_description", "smell", "listen",\
  "living_item", "inanimate_item", "system",\
  "combat", "magic", "prompt",\
  "room_exits", "info", "no_wrap",\
})
#define COMMANDS_PUB ({\
  "say", "emote", "speak", "yell",\
})
#define LOCATIONS_PUB ({\
  "/d/nopk/tirun/square",\
  "/d/nopk/tirun/pubstart",\
  "/wizards/nulvect/workroom",\
})
#define REPLACEMENTS ({\
  "@", "!", "#",\
})

string cusscheck;

int query_public_location(object room);
string censor(object who, string channel, string msg);
string apply_censor(string str);

void create() {
  // do this here to save cycles
  cusscheck = implode(WORDS, "|");
}

int query_public_location(object room) {
  if (member_array(base_name(room), LOCATIONS_PUB) != -1) return 1;
  if (inherits(HALL, room)) return 1;
  return 0;
}

string censor(object who, string channel, string msg) {
  string *tmp;
  object env;
  int cussed = 0;
  int flag = 0;

  if (!who || !channel || !msg) return 0;

  env = environment(who);

  if (member_array(channel, CLASS_NO_CENSOR) == -1 &&
       (
         who->getenv("CENSOR_PRIVATE") ||
         member_array(channel, LINES) != -1 ||
         (
           member_array(channel, COMMANDS_PUB) != -1 &&
           query_public_location(env)
         )
       )
     ) {
       msg = apply_censor(msg);
  }
  
  return msg;

}

string apply_censor(string str) {
  string *tmp;
  int cussed=0;

  if (!str) return "";

  if (!regexp(lower_case(str), cusscheck))
    return str;

  tmp = explode(str, " ");

  for (int i=0; i < sizeof(tmp); i++) {

    if (regexp(lower_case(tmp[i]), cusscheck)) {
      cussed = 1;
      for (int j=0; j < strlen(tmp[i]); j++)
        if (tmp[i][j..j] != "\n")
          tmp[i][j..j] = REPLACEMENTS[random(sizeof(REPLACEMENTS))];
    }

  }

  if (cussed) {
    return implode(tmp, " ");
  }
  else
    return str;

}
