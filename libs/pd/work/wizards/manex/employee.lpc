#include <std.h>
inherit MONSTER;

void create() {
::create();
   set_name("employee");
   set_short("company employee");
   set_long("This is the generic company employee, except, he is "
     "kind of gone crazy. He was making a kill list when his "
     "pencil broke, that was the last straw! now the whole world "
     "has to pay!");
   set_id(({"employee", "company employee"}));
   set_level(15);
   set_race("human");
   set_body_type("human");
   set_gender("male");
   new("/wizards/manex/pencil")->move(this_object());
   this_object()->force_me("wield pencil");
}
