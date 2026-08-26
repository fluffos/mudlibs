#include <mudlib.h>
inherit MONSTER ;

void create () {
  ::create();
  seteuid(getuid());
  set("no_attack" , 1);
  set("short" , "Coco");
  set("long" , @EndText
  Its Coco the Cabanna boy, here to do his Queen's bidding.
  His queen being Rebecca, he is here in his Cabana wear, doing
  all the things a Cabana boy should do.


EndText
);
  set("id" , ({ "coco" }) );
  set_level(1);
  set_size(6);
  set_name("coco");
  set_living_name("mickey");
  set("gender" , "male");
  set("race" , "human");
}

void init() {
  command("say What is thy bidding my master?");
 }
