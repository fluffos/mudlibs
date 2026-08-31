#include <std.h>

inherit OBJECT;

void create()
{
 ::create();
 set_name("diary");
 set_short("A little black book");
 set_long("The book is Katen's diary, maybe you should read it.  (Read entry #)");
 set_id( ({ "diary", "book" }) );
 set_weight(1);
 set_value(1);
}

void init()
{
 ::init();
 add_action("fRead", "read");
}

int fRead(string str)
{
 int entry;
 if (!str || str == "") return notify_fail("Read what?\n");
 if (sscanf(str, "entry %d", entry)!=1)
   return notify_fail("Read which entry?\n");
 if (!entry) { write("Read which entry?\n"); return 1; }
 switch(entry)
  {
   case 1:
    write("Day one of my stay here was the worst day of my life!  "
          "I had to work construction, after they promised me that "
          "I be in paradise.  What's worse, is they wouldn't tell me "
          "where they hid paradise.  Maybe I can sneak out tomorrow and "
          "and look for it...");
    break;
   case 2:
    write("Day two..I was able to sneak out of the city!  How cleaver they "
          "were in hiding this dump.  I learned that this town is just a decoy.  "
          "I was also told to say near the city, there's an aweful threat that threatens "
          "the citizens of this dump of a town.  Found nothing of paradise, ...");
    break;
   case 3:
    write("Day three..Worked my tail off for a town that dosn't exist.");
    break;
   case 4:
    write("Day four..Found ogre bones on the far side of the marsh.  Hidden "
          "in the mud was a lizard-made snorkle.  I must be close.  WHERE did "
          "they put paradise?  I must get out of this town, I'm no construction worker.");
    break;
   case 5:
    write("Day five..went back to the bones and swam around HOW CLEAVER I'm most impressed!");
    break;
   case 6:
    write("nothing, no more pages were written");
    break;
  }
 return 1;
}
