//---------------------------------------------------------------------------
// std/thing.c
//
// A simple object for cloning and moving around (including light and weight).
//--------------------------------------------------------------------------

#include <classes.h>

inherit "/std/thing/restrictions";
inherit "/std/thing/description";
inherit "/std/thing/moving";
inherit "/std/base";
inherit "/std/skills";   // needs create and init

//---------------------------------------------------------------------------

public void create () {
  base::create();
  AddClassId(C_THING);
  skills::create();    // must be AFTER AddClassId
}

public int clean_up (int ref) {
  return moving::clean_up (ref);
}

// Just in case...

public void init() 
{ 
  skills::init();
}
