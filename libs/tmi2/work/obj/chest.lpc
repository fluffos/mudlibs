// chest.c
// A boring treasure chest. A basic container.
// Mobydick@TMI-2, October 1992.

#include <mudlib.h>

inherit CONTAINER ;
inherit LOCK ;

void create() {
   ::create() ;
  set("short", "a chest");
  set("id", ({ "chest" }));
// Containers have two long descriptions, one for open and one for closed.
  set_closed_long("A treasure chest. Its lid is closed.\n") ;
  set_open_long("An treasure chest with its lid wide open.\n") ;
// Some containers are closeable: others are not. This controls it.
  set_possible_to_close(1) ;
  set ("bulk", 250) ;
  set ("mass", 200) ;
// Capacity is the total amount of mass than can be put in the bag, and
// volume is the total amount of bulk that can be put in.
  set ("capacity", 1000) ;
  set ("volume", 225) ;
  set ("value", ({ 3, "gold" }) ) ;
// Each lock has a number which controls how much work is needed to fully
// lock it, and each key has a number which controls how much locking that
// key does in one command. "max_lock" is the total amount of locking that
// can be spent on this lock before it is fully locked.
// Usually the key has enough efficiency that the key can fully lock the
// lock with one command. But it doesn't have to be that way if you'd
// rather it wasn't.
  set("max_lock", 10);
// If lock=0, the object has no lock. If lock<0, it has a lock but is unlocked.
// If lock>0, the lock is locked to that degree of effort. Not to be greater
// than max_lock.
  set("lock", -1);
// The ident string of the key which opens the lock.
  set("key", "golden key") ;
}

// Since both container.c and lock.c have inits, we have to call
// init in both.

void init() {
	container::init() ;
	lock::init() ;
}
