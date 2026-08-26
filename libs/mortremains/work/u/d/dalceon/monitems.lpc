#include <mudlib.h>

inherit MONSTER;

int add_item(string);


int add_item(string file) {

  object the_item;

  the_item = clone_object(file);

  if(present(the_item)) {
     destruct(the_item);
     return 1;
  }

  else {
     the_item->move(this_object());
     return 1;
  }
}

