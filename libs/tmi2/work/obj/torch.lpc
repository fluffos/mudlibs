// torch.c
// A torch - for seeing in the dark, roasting marshmallows, whatever you
// want, really.
// Written by Guile@TMI-2, 11-8-92.
// Thanks to Zeus@TMI-2 for a quickie fix, 1-22-93.

#include <mudlib.h>
inherit OBJECT;

void
create()     
     {
     set ("short", "@@query_short");
     set ("long", "@@query_long");
     set ("id", ({ "torch" }));
     set ("mass", 100);
     set ("bulk", 50);
     set ("value", ({ 5, "silver" }));
     set ("fuel", 900);  // fuel is measured in seconds
     }


void
init()
     {
     add_action("light_t", "light");
     add_action("light_t", "ignite");
     add_action("extinguish_t", "extinguish");
     add_action("extinguish_t", "unlight");
     }

int
light_t(string str)
     {
     if(!id(str)) return 0;
     if(!query("fuel"))
          {
          notify_fail("It fails to light.\n");
          return 0;
          }
     if(query("light"))
          {
          notify_fail("It is already lit!\n");
          return 0;
          }
     write("You ignite the torch.\n");
     set("light", 1);
     call_out("burn_out", query("fuel"));
     return 1;
     }

int
extinguish_t(string str)
     {
     if(!id(str)) return 0;
     if(!query("fuel"))
          {
          notify_fail("What's the point, it's cashed.\n");
          return 0;
          }
     if(!query("light"))
          {
          notify_fail("It is not lit.\n");
          return 0;
          }
     write("You extinguish the torch.\n");
     set("light", 0);
     set("fuel", remove_call_out("burn_out"));
     return 1;
     }

void
burn_out()
     {
     tell_object(environment(this_object()), "The torch flickers and dies.\n") ;
     set ("value", ({ 1, "silver" }));
     set ("fuel", 0);
     set ("light", 0);
     }

string
query_short()
     {
     if(query("fuel"))
          return "a torch" + (query("light") ? " (lit)" : "");
     return "a burned out torch";
     }


string
query_long()
     {
     if(query("fuel"))
          return "It is a light source.\n" +
               (query("light") ? "It is lit.\n" : "It is not lit.\n");
     return "It used to be a light source.\n";
     }
