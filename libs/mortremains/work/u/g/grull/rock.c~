
// bag.c
// Originally written by Truilkan 92/04/20.
// Updated to mudlib 0.9 by Mobydick, 10-14-92.
// Trashed/Hacked by Cattt  6/15/99

#include <mudlib.h>
#include <sewers.h>

inherit CONTAINER ;
object sewerblade;

void create()
{
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("id", ({"rock", "stone"}));
    set("short", "a large rock");
    set_open_long ("@@query_long");
    set("prevent_get",1);
    set ("capacity", 1000) ;
    set ("volume", 25) ;
}

void remove() {

  int i;
  object *inv ;

  inv = all_inventory(this_object()) ;
  if (!inv || sizeof(inv) == 0) {
    ::remove() ;
   return ;
  }  
  for(i=0;i<sizeof(inv);i++) {
    inv[i]->remove() ;
  }
  :: remove() ; 
}

void init () {
    container::init();
    add_action ("get", "get");
}

int get (string str) {
    object questobj;
    if (!str) {
        write ("Get what?\n");
        return 1;
    }
    if (str!="blade") return 0;

    if (present("gem", TO) && present("mug", TO) && present("tooth", TO) && present("skull", TO)) {
         sewerblade = clone_object(M_WEAP+"sewerblade.c");
         write ("You retrieve the legendary SewerBlade!\n");
         say(wrap(TPN+" retrieves the legendary SewerBlade!"));
         write ("The rock crumples to pieces as the blade comes out.\n");
         say("The rock crumples to pieces as the blade comes out.\n");
         sewerblade->move( this_player() );
         remove();
	 questobj = find_object_or_load(M_ROOM+"sewerstd");
	 questobj->reset_quest();
         return 1;
    } 
    
    else{ 
        write ("You can't retrieve the blade.\n");
        write ("Maybe you need to put something into the rock.\n");
    }
    return 1;
}

string query_long() {
    string str =
    "A large rock with a blade stuck into it.  At a closer "+
    "glance you see four slots in it that come in various shapes "+
    "and sizes.  It looks like you must put in some tributes to "+
    "even possibly achieve this magnificant weapon. \n";

    if (present("gem", TO))
        str += "A star shaped gem is in one of the slots on the rock.\n";
    if (present("mug", TO))
        str += "A mug is in one of the slots on the rock.\n";
    if (present("tooth", TO))
        str += "A tooth is in one of the slots on the rock.\n";
    if (present("skull", TO))
        str += "A skull is in one of the slots on the rock.\n";
    if (present("gem", TO) && present("mug", TO) && present("tooth", TO) && present("skull", TO))
        str += "Perhaps you can get the blade now!\n";   
    return wrap(str);
}

