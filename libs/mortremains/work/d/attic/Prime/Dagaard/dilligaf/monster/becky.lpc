#include <mudlib.h>
inherit MONSTER ;

void create () {
  ::create();
  seteuid(getuid());
  set("no_attack" , 1);
  set("short" , "Rebecca");
  set("long" , @EndText
  This is the magnificent Rebecca, though most call her Becky.
  Her beauty astounds you and drool starts to dribble a 
  little from the left side of your mouth. She gazes at
  you with crystal blue eyes, and your knees start to go
  weak.


EndText
);
  set("id" , ({ "becky" , "rebecca" , "fruitcake" , "brat" }) );
  set_level(1);
  set_size(5);
  set_name("becky");
  set_living_name("mickey");
  set("gender" , "female");
  set("race" , "human");
}

void init() {
  command("say Coco! Come here!");
  command("grope coco");
 }
