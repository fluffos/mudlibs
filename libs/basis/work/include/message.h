// file:   message.h
// mudlib: CynoMUD-II
// desc:   message classes for message() efun
// author: Truilkan
// note:   mc stands for message class
//
// void message(string message, string class, mixed target, mixed exclude);
//
// void receive_message(string class, string message) gets called in the target
//
// use the #defines rather than string constants in order to prevent typos

#define mc_say     "say"     /* message that everyone in room sees */
#define mc_tell    "tell"    /* private communications */
#define mc_shout   "shout"   /* messages that everyone sees */
#define mc_pcombat "pcombat" /* combat messages (involving _this_ player) */
#define mc_combat  "combat"  /* all other combat-related messages */
#define mc_emote   "emote"   /* emotes (e.g. smile, laugh, etc) */
#define mc_room    "room"    /* descriptions of environment (rooms) */
#define mc_desc    "desc"    /* descriptions of other objects */
