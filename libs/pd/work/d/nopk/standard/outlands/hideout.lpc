inherit "std/room";

void init() {
    ::init();
}

void create() {
  ::create();
    set_property("light", 1);
    set("short", "The path to the hideout");
    set("long",
        "A broken down shack is at the end of this small jungle path "
        "to the southwest.  The path converges with a couple of others "
	"northeast.");
    set_items(
        (["shack" : "It is a broken down home that appears to serve "
	    "no current function.",
	  "path" : "It is covered with jungle growth and dead-ends "
	    "at the shack.",
	  "jungle" : "It is very thick and humid.",
	  "paths" : "They lead off in several directions.",
	  "growth" : "All sorts of jungle vegetation growing over "
	    "the path and everywhere else.",
	  "vegetation" : "It is everywhere, making it impossible "
	    "to see very far ahead."]) );
set_exits( (["northeast" : "/d/nopk/standard/outlands/fork",
]) );
}
