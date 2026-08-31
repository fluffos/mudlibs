#include <std.h>

inherit OBJECT;

void create()
{
 ::create();
 set_name("diary");
 set_short("A underwater diary");
 set_long("its a diary read it.");
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
    write("..I woke up in the middle of the night. I fought a dead "
          "guy in my sleep..");
    break;
   case 2:
    write(".. The next day i uhm.. did something.");
    break;
   case 3:
    write("This is my third entry.");
    break;
   case 4: 
    write("Nod my fourth");
    break;
   default:
    write("Read which entry?\n");
    break;
  }
 return 1;
}
