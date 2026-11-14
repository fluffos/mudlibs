// MorgenGrauen MUDlib
//
// inpc.c -- Intelligenter NPC
//
// $Id: inpc.c,v 3.1 1997/02/05 12:46:14 Wargon Exp $

inherit "/std/npc";
inherit "/std/inpc/nobank";
inherit "/std/inpc/select";
inherit "/std/inpc/boozing";
inherit "/std/inpc/items";
inherit "/std/inpc/eval";

#include <moving.h>
#include <inpc.h>
#define ME this_object()
#define ENV environment()
#define TP this_player()

#pragma strong_types

void create() {
  npc::create();
  items::create();
  add_select_commands();
}

void reset() {
  npc::reset();
  items::reset();
}

void init() {
  npc::init();
  if (TP && query_once_interactive(TP))
    SetProp(P_INPC_LAST_PLAYER_CONTACT,time());
}

varargs int move(mixed dest, int meth, string dir, string tin, string tout) {
  int res;
  object env;

  env=ENV;
  if (!(meth&M_NOCHECK)
      && !ENV
      && QueryProp(P_INPC_WALK_MODE)
      && !ME->may_enter_room(dest))
    return ME_CANT_TPORT_IN;
  res=::move(dest,meth,dir,tin,tout);
  if (env!=ENV)
    SetProp(P_INPC_LAST_ENVIRONMENT,ENV);
  return res;
}
