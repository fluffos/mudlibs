// May's Ed Tutorial for Wizards
// brought to FF on 5 Feb 2001

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
  set_light(80);
  set_short("Ed Tutorial 4");
  set_long("Once you have made a file, you want to save it.  "
     "There are many ways to save and or quit in ED.  The easiest "
     "way to both save and quit is by typing <x>.  The only thing "
     "is that you must be editing a file that already exists.  If "
     "you just typed ED when you started, ED will not know the name "
     "to save your file under so it will not allow you to quit.\n"
     "   There are also times when you will not want to save when "
     "you quit, for instance when you make a mistake and you want "
     "to get back to the origional file.  In this case you can "
     "type <Q> or <q>.  The capital one will exit you from Ed "
     "no matter what and the lower case one will exit you "
     "only if the file has not been changed since you opened it "
     "or saved last.\n");

  add_exit("south",EDTUTOR "edtutor03","path");
  add_exit("north",EDTUTOR "edtutor05","path");
}
