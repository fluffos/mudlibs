
#include <kabaal.h>
#include <std.h>

inherit OBJECT;

void create()
{
 ::create();
 set_name("book");
 set_short("a large book");
 set_long("This is a large book. The cover is made of a red velvet with a griffon embroidered on it. Perhaps you could read it. <read page
#>");
 set_id( ({ "book" }) );
 set_weight(999999);
 set_value(1);
}

void init()
{
 ::init();
 add_action("fRead", "read");
}

int fRead(string str)
{
 int page;
 if (!str || str == "") return notify_fail("Read what?\n");

 if (sscanf(str, "page %d", page)!=1)
   return notify_fail("Read which page? <read page #> \n");

 if (!page) { write("What page would you like to read? <read page #>\n"); return 1; }
switch(page)
  {
   case 1:
    write("Deep inside the mountains of Logan lies a treasure. This treasure has been seen "
	  "by few but most who reside around Logan know of it's existance. Nobody but those " 
	  "the treasure is, however, unknown...");
    break;

   case 2:
    write("Logan the Griffon King flew above the Sindarii skies, looking down upon his "
	  "world, scoping things out. He flew to Logan square and landed. His objective "
	  "was unknown.");
    break;

   case 3:
    write("Logan walked through the city up to the shrubbary blocking the pathway to the "
	  "mountain pass. He quickly %^BOLD%^%^WHITE%^entered the shrubbary%^RESET%^ and "
	  "strolled up through the mountain base. He climbed his mountain range and %^BOLD%^"
	  "%^WHITE%^entered his cave%^RESET%^ and rested, awaiting someone to find him.");
    break;

   case 4:
    write("Logan is waiting for someone, something....");
    break;

   case 5:
    write("This page is blank.");
    break;

   case 6:
    write("There are no more pages.");
    break;
  }
 return 1;
}
