/*
 * an action handler for playing instruments
 * modified Aug 93 by marion@cs.tu-berlin.de
 * completely rewritten and events added, Coogan, 15-Jan-02
 */

#pragma strong_types

#include <grammar.h>
#include <event.h>
#include <skilltree.h>
#include <server.h>
#include <prop/item.h>
#include <prop/room.h>

#define G_INSTRUMENT    "<instrument>"

inherit "basic/parser";
inherit "basic/action";

private void receive_play_instrument_event(mapping e, string type, int prio);

private string skp;

string query_info(string str) {
  return "With a bit practice everybody can make beautiful music.\n"
         "And perhaps some music might be powerful?\n"
         "Hint: 'play [on] <instrument>' or 'play <melody> on <instrument>'\n";
} 

void create() {
  action::create();
  set_skill_path(S_P_PLAY);
  set_command("play");
  set_specific(0);
  set_function("parse_action");

  duplicate_class(G_OBJECT, G_INSTRUMENT);
  add_rule("play "G_OBJECT" on "G_INSTRUMENT, "play_note_on_inst");
  add_rule("play "G_TEXT" on "G_INSTRUMENT,   "play_note_on_inst");
  add_rule("play on "G_INSTRUMENT,            "play_on_inst");
  add_rule("play "G_OBJECT,                   "play_note_or_inst");
  add_rule("play "G_TEXT,                     "play_error");
  add_error_message("play",
       ({ "Without an instrument you clap your hands to make music.\n", -1 }));

  set_global_listening_event("play_instrument", 1);
  listen_event("play_instrument",EPRIO_HANDLE,#'receive_play_instrument_event);
}

int do_action(string action, mapping args) {
  mapping event;

  if (action == "play_error") {
    // TODO: a LIB_SONG could decide that G_TEXT is a known song
    notify_fail("Are you really sure this item is for making music?\n");
    return 0;
  }
  event = ([ E_AGENT  : this_player(); this_player()->query_name() ]);

  if (args[G_INSTRUMENT]) {
    event[E_TOOL]   = args[G_INSTRUMENT];
    event[E_TOOL,1] = args[G_INSTRUMENT,1];
  }

  if (args[G_OBJECT]) {
    if (args[G_OBJECT]->query_property(P_ROOM) ||         // a room's fakeitem
        args[G_OBJECT]->query_property(P_MUSIC_INSTRUMENT)) { // or instrument
      event[E_TOOL]   = args[G_OBJECT];
      event[E_TOOL,1] = args[G_OBJECT,1];
    } else {
      event[E_MELODY]   = args[G_OBJECT];
      event[E_MELODY,1] = args[G_OBJECT,1];
    }
  }

  if (args[G_TEXT]) {
    // TODO: a LIB_SONG could decide that G_TEXT is a known song
    event[E_MELODY]   = 0;
    event[E_MELODY,1] = args[G_TEXT];
  }

  send_event("play_instrument", event, environment(this_player()));
  if (event[E_CANCELLED])
    return 1;

  if (event[E_SUCCESS] > 0) {
    if (event[E_SUCCESS] > 1)
      this_player()->add_skill_points(skp||query_skill_path(),event[E_SUCCESS]);
    else
      this_player()->add_skill_points(skp||query_skill_path(),
                                      SE_SKILLS->query_reward(this_player(),
                                                              event[E_SUCCESS],
                                                            50, skp||S_P_PLAY));
  }
  return event[E_SUCCESS];
}

private int apply_play_instrument_action(mapping e) {
  int res, sk;

  if (!(skp = e[E_TOOL] && e[E_TOOL]->query_skill_path())) {
    if (e[E_TOOL]) {
      if      (e[E_TOOL]->id("drum"))
        skp = S_P_PLAY_DRUM;
      else if (e[E_TOOL]->id("trumpet") ||
               e[E_TOOL]->id("tuba"))
        skp = S_P_PLAY_BRASS;
      else if (e[E_TOOL]->id("bass")    ||
               e[E_TOOL]->id("violin"))
        skp = S_P_PLAY_STRINGED;
      else if (e[E_TOOL]->id("guitar")  ||
               e[E_TOOL]->id("mandolin")||
               e[E_TOOL]->id("lute")    ||
               e[E_TOOL]->id("harp"))
        skp = S_P_PLAY_PLUCK;
      else if (e[E_TOOL]->id("piano")   ||
               e[E_TOOL]->id("organ"))
        skp = S_P_PLAY_KEYBOARD;
      else if (e[E_TOOL]->id("flute")   ||
               e[E_TOOL]->id("whistle") ||
               e[E_TOOL]->id("pipe"))
        skp = S_P_PLAY_FLUTE;
      else
        skp = S_P_PLAY;
    } else
      skp = S_P_PLAY;
  }
  sk =  this_player()->query_modified_skill(skp);
  if (!e[E_TOOL])             // no instrument was given, try the room first.
    res = environment(this_player())->apply_action("play instrument", sk, e);
  if (!res && e[E_TOOL])      // okay, try the instrument
    res = e[E_TOOL]->apply_action("play instrument", sk, e);
  return res;
}

private void receive_play_instrument_event(mapping e, string type, int prio) {
  if (prio != EPRIO_HANDLE || e[E_HANDLED])
    return 0;
  e[E_HANDLED] = 1;
  e[E_SUCCESS] = with_player(e[E_AGENT], #'apply_play_instrument_action, e);
}

