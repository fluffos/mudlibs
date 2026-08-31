//  Created by Whit
//  City of Ages
//  Inheritable Required for all rooms

inherit "/std/room";

void init() {
    ::init();
    if(!this_player()->query_property("lca")) 
	this_player()->set_property("lca", "1");
    add_action("look", "look");
}

int look(string str) {
    if(str == "sky") {
	write("You see nothing but a metallic shell over the "
	  "city");
	return 1;
    }
    return 0;
}

