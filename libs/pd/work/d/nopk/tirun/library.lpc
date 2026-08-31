#include <std.h>
#include <daemons.h>
#include <dirs.h>
#include <tirun.h>
inherit ROOM;
int gu;
int rt;
void init() {
    ::init();
    add_action("help", "help");
    add_action("read", "read");
    add_action("passage", "passage");
    add_action("move_crate", "push");
}

int passage() {
if(!query_exit("passage")) return 0;
  if(find_object("/d/guilds/darksoul/entrance"))
tell_room("/d/guilds/darksoul/entrance", "Someone is coming.");
return 0;
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Tirun Library");
    set_long(
      "%^GREEN%^The Tirun Library%^RESET%^\n"
      "The library has been around in Tirun since the first days.  "
     "Adventurers from all "
      "over this reality come here to learn.  Type <read books> to see "
      "what books are on the shelves.  Also, type <read [title]> to "
      "read a particular book.");
    set_items(
      (["library" : "The laws of reality are explained in here.",
        "shelf" : "It has books on it.",
        "shelves" : "Books fill them.",
        "book" : "One of many.",
        "books" : "They are everywhere on the shelves."]) );
    set_exits( 
      (["out" : ROOMS "square6"]) );
    set_property("no attack", 1);
    set_property("no steal", 1);
}
int read(string str) {
    string *dir;
    int i;
    if(!str || str == "") {
        notify_fail("Read what?\n");
    }
    if(str == "volume" || str == "book") {
        notify_fail("Which "+str+"?\n");
        return 0;
    }
    if(str == "volumes" || str == "books") {
        message("info", "The books available for reading are:",this_player());
         dir = get_dir(DIR_LIBRARY + "/");
         for(i=0; i<sizeof(dir); i++) dir[i] = replace_string(dir[i], "_", "
");
                message("info", replace_string(format_page(dir, 3), "\n", " "),
                  this_player());
/*message("info", "changing       high mortal     intermud      offensive
players\n"
"snooping       guilds          immortal      name changes    organization\n"
"rules          sexual harassment", this_player());
*/
        message("info", "Type <read [book name]> to read a particular book.",
this_player());
    }
    else {
        if(str)
          str = replace_string(str, " ", "_");
        if(file_size(DIR_LIBRARY + "/"+str) == -1) {
            notify_fail("There is no book here by that title.\n");
            return 0;
        }
        this_player()->more(DIR_LIBRARY + "/"+str);
    }
    return 1;
}
int help(string str) {
    if(!str) return 0;
    if(str != "library") {
        notify_fail("You help "+str+".\n");
        return 0;
    }
    write("You can read what is in the library.\nType <read books>.\n");
    write("It is highly reccomended that you read the documents put "
      "into the library for your reading enjoyment!");
    return 1;
}
void reset() {
    ::reset();
      rt = 1;
    if(!present("bookcase"))
     new("/d/nopk/tirun/obj/misc/bookcase")->move(this_object());
}
int move_crate(string str) {
    if(!str) {
        notify_fail("Push what?\n");
        return 1;
    }
    if(str != "bookcase") {
        notify_fail("You can't push that!\n");
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" pushes the bookcase "
       "revealing a passage.", this_object(), ({this_player()}));
    message("info", "The bookcase moves reveiling a secret passage.", this_player());
    add_exit("/d/guilds/darksoul/entrance", "passage");
    call_out("go_crate", 15);
    return 1;
}
void go_crate() {
    message("info", "The bookcase returns to its normal position.",
       all_inventory(this_object()));
    remove_exit("passage");
}
