//  Created by Whit

#include <citrin.h>
#include <std.h>

inherit OBJECT;
int rt;

void create() {
    ::create();
    set_name("tree");
    set_prevent_get("Its roots are tight in the ground.");
    set_short("a small tree");
    set_long("This is the only obstruction in the path.  There are "
      "several small branches on the tree.");
}

void reset() {
    ::reset();
    rt = 0;
}

void init() {
    ::init();
    add_action("pull", "pull");
}

int pull(string str) {
    if(!str || str != "branch") return notify_fail("Pull what?\n");
    if(rt) return notify_fail("There are no more branches left to "
	  "pull.\n");
    write("The branch falls and a gemed necklace falls out.\n");
    new(ARM"necklace")->move(environment(this_object()));
    rt = 1;
    return 1;
}

