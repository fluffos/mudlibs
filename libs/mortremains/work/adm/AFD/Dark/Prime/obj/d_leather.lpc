// chainmail.c
// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
	set ("id", ({ "chain", "chainmail" }) ) ;
	set ("short", "a suit of chainmail") ;
	set ("long", "The mail mesh would cover your torso and upper arms.\n") ;
	set ("bulk", 100) ;
	set ("mass", 1200) ;
set_value(30);
// All armor objects need to set a "type", ie - body, gloves, helmet, etc.
// See /doc/armor/TYPES for a listing of valid armor types.
// A player may only wear one of each type of armor.
  set_type("body");
// "armor" is the armor class of the armor. Anything with "armor" 0 is not
// a piece of armor and cannot be equipped. Things with positive values of
// "armor" are armor; higher numbers are better protection against attacks
// (which is the reverse of the D&D method.)
  set_ac(5);
}
