inherit "/std/thing";
#include <properties.h>
#include <moving.h>
#include "path.h"

create() {
  ::create();
  AddId("fly");
  SetShort("A small disturbing fly");
  SetLong("The fly flies round and round your head.\n");
  SetValue(0);
  SetWeight(10);
  SetNoGet("You cannot get it. It is too small and too fast.\n");
}

init() {
  ::init();
  add_action("cc","catch");
  add_action("cc","eat");
  add_action("cc","capture");
}

int cc(string str) {
  object ob;
  if (!this_player()) return 0;
  if (!this_player()->QueryFrog()) return (int) notify_fail("You are not able to catch a fly.\n") && 0;
  if ((!str) || (str!="fly")) return (int) notify_fail("Catch what?\n") && 0;
  if (this_player()->CanSee()) {
    write("You spit out your large frog tongue and ...\n\
... you catch the fly. A hit !. You eat it. Mmmh .. tastes good.\n");
    say(this_player()->QueryName()+" catches the fly!\n");
    write("After your great deed you notice a small key on the ground.\n");
    seteuid(getuid(this_object()));
    ob=clone_object("/obj/key");
    ob->SetShort("a rusty key");
    ob->SetLong(
"This is an old rusty key. You get an evil feeling when you look at it.\n");
    ob->AddKeyId("pirate_rusty_key");
    ob->SetAds(({"a","rusty"}));
    ob->SetWeight(200);
    ob->SetValue(10);
    ob->move(PIRATE("inhole"),M_DROP);
    ob=clone_object("/obj/rope");
    ob->move(PIRATE("inhole"),M_DROP);
    remove();
    if (this_object()) destruct(this_object());
    return 1;
    }
  return (int) notify_fail("It's too difficult to catch a fly while you cannot see.\n") && 0;
}
