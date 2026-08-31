#include <std.h>

inherit ROOM;

string get_desc()
{
 if (this_player()->query_name()!="seeker")
   {
    return "How in the hell did you get here?! shoo before you feel my "
           "wrath you innocent mortal, or immortal.";
   }
    return "You have entered the workroom for seeker, the main admin on "
           "Carnage, the place is covered in plans, papers, old "
           "code. This place is hella messy";
   
}

string go_square()
{
 write("You go square..");
 return "/d/standard/edivos1";
}
void create() {
   room::create();
    set_property("light", 2);
    set_property("indoors", 1);

    set("short", "The workroom of a new immortal");
   set_long( (: get_desc :) );

   set_exits( ([ "north" : "/d/standard/square" ]) );

    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");

}

int init()
{
 object ob;
 ::init();
/*   ob = get_object("/adm/save/users/s/seeker.o");
  write("ob = "+ob->query_name()); */
/* if (this_player()->query_name()!="seeker")
   this_player()->move_player("/d/standard/square"); */
}

void reset()
{
 ::reset();
 if (!present("peacekeeper"))
   new("/d/standard/obj/mon/peacekeeper")->move(this_object());
}
