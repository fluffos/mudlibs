#include <std.h>
inherit ROOM;
#include <tirun.h>

void create() {
 ::create();
   set("short", "Morian's place");
   set("long", "Torches and such are stored here.");
   set_exits(([
     "east" : ROOMS"light"
   ]));
}

void reset() {
 ::reset();
  if (!present("torch")) {
   new(OBJ"torch")->move(this_object());
   new(OBJ"torch")->move(this_object());
   new(OBJ"torch")->move(this_object());
   new(OBJ"torch")->move(this_object());
  }
  if (!present("lantern")) {
   new(OBJ"lantern")->move(this_object());
   new(OBJ"lantern")->move(this_object());
  }
  if (!present("fuel")) {
   new(OBJ"oil")->move(this_object());
   new(OBJ"oil")->move(this_object());
  }
}
