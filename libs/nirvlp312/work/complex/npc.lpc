/*
 * npc.c - written by Ugh for Tubmud 1995
 * adapted for the new living by Coogan, 05-Jan-1999
 *
 */

/*
 * PLEASE NOTE: this npc is thought as a replacement of former /obj/actor.
 * Please only use it, if you really need to have an elaborated monster.
 * For normal hack'n slay -monster, just use /obj/monster.
 * As soon as the new combat is finished, there will be a new
 * /complex/monster.
 * AND ALSO: Although this class is fully configurable from outside,
 * it is not meant to be inherited.
 * It is only an example for the use of /basic/living.c (which incorporates
 * all vital functions for a living object) and some of the classes
 * in /basic/living/ .
 * If you want to write your own npc which is not configured by another 
 * object, please do the same as this class does, but only inherit
 * the classes which you really need and use.
 *
 * Thank you very much.
 */

#pragma strong_types

inherit "basic/living/chat";
inherit "basic/living/feeling";
inherit "basic/living/follow";
inherit "basic/living/mood";
inherit "basic/living/reaction";
inherit "basic/living/sequence";
inherit "obj/monster";

void configure() {
  monster::configure();
  reaction::configure();
}

void refresh() {
  mood::refresh();
  monster::refresh();
}

status query_busy() {
  return 
    sequence::query_busy() ||
    monster::query_busy();
}

void heart_beat() {
  sequence::heart_beat();
  monster::heart_beat();
}

void init() {
  follow::init();
  reaction::init();
  monster::init();
}

void notify_destruct() {        // Coogan, 09-Jan-1999
  remove_all_chat_reactions();
  follow::notify_destruct();
  monster::notify_destruct();
}

void set_defaults(int new) {
  log_file("set_defaults",ctime()+": npc: "+object_name(this_object())+"\n");
}

