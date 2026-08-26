#include <mudlib.h>

inherit CONTAINER ;

void create()
{
    ::create();
  set("id" , ({ "chest" }) );
  set("short" , "A large chest");
  set_open_long("A large wooden chest, to store equipment in.\n");
  set_closed_long("A large wooden chest. The lid is closed right now.\n");
  set("holding" , 1);
  set("capacity" , 5000);
  set("volume" , 5000);
  set("bulk" , 50000);
  set("mass" , 50000);
  set_possible_to_close(1);
  set("value" , ({ 25, "gold" }) );
}
void init() {
  container::init();
}
