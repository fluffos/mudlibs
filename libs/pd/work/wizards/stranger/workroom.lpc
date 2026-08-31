
#include <std.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Standard Workroom");
    set_long(
      "This is the dorm room of a new coder.  It is from "
      "this room that a new coder makes their first steps "
      "into coding for the mud. To start with, they will "
      "customize this room.  There is a poster on the wall."
    );
    set_items(([
        "room" : "The dorm room is rather drab looking.",
        "poster" : "1 : Type 'cd /wizards/(yourname)', this"
           " will change your current directory to your home directory."
  "\n2 : Type ls, this will give you a list of whats in your current directory."
  "\n3 : Type 'more workroom.c', this will display the contents of "
  "this file."
  "\n4 : Now, be brave, and type 'ed workroom.c'.  As soon as you do this, "
  "type 'h', this will display a list of commands for the built in editor."
   "\nIf you need any more help, leave goto the hall from this room.",
   ({"wall", "the wall"}):
     "The wall has a poster on it, maybe you should look at it."
    ]));
    set_smell("default", "An odd smell of burning water is in the air.");
    set_listen("default", "The sound of a frustrated wiz beating his "              "code is here");
    set_exits( ([ 
        "square" :  "/d/standard/square",
        "hall"  :  "/d/standard/adv_inner"
    ]) );
    
}

void encounter(object it)
{
    tell_object(find_player("stranger"),"FOO!\n");
    tell_object(this_object(),"Room: enounter called with "+
       it->query_short() + "\n");
}


string *showfilter()
{
    string *it = ({ "11","20","30" });
    string *answer;
    answer = filter_array(it,"grepit",this_object(),"10");
    return answer;
}

int grepit(mixed it, mixed extra)
{
    if(it != extra) return 0;
    return 1;
}
