#include <std.h>

inherit OBJECT;

void create()
{
 ::create();
 set_name("book");
 set_short("a book");
 set_long("The book is old and dusty, perhaps you should read it. <read page #>");
 set_id( ({ "book" }) );
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
 int page;
 if (!str || str == "") return notify_fail("Read what?\n");

 if (sscanf(str, "page %d", page)!=1)
   return notify_fail("Read which page? <read page #> \n");

 if (!page) { write("Read which page? <read page #>\n"); return 1; }
switch(page)
  {
   case 1:
    write("page one text goes here.");
    break;

   case 2:
    write("page two text goes here.");
    break;

   case 3:
    write("page three text goes here.");
    break;

   case 4:
    write("page four text goes here.");
    break;

   case 5:
    write("page five text goes here.");
    break;

   case 6: //last page should have there are no more pages
    write("There are no more pages.");
    break;
  }
 return 1;
}
