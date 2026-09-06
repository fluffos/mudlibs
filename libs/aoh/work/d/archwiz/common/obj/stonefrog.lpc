inherit "std/thing";
#include <properties.h>
#include <moving.h>
#include "path.h"

create() {
 ::create();
 SetIds(({"frog","stonefrog"}));
 SetAds(({"stone","a"}));
 SetShort("a stonefrog");
 SetLong("It has a small crack at one side. Be careful not to break it.\n");
 SetWeight(1000);
 SetValue(15);
 Set(P_NOBUY,1);
}

init() {
  ::init();
  add_action("break_it","break");  
}

int break_it(string str) {
  if (str!="frog" && str!="stonefrog")
    return 0;
  write("As you break it open, yellow smoke emerges from its inner parts.\n");
  this_player()->SetFrog(0);
  write("The parts of the stonefrog vanish.\n");
  remove();
  if (this_object())
    destruct(this_object());
  return 1;
}

varargs int move(mixed dest, int method, mixed extra)
{
  int retc;
  retc = ::move(dest, method, extra);
  if (method == M_DROP) {
    write("As you drop the stonefrog, it breaks into pieces and a yellow smoke emerges from it.\n");
    break_it("frog");
  }
  return retc;
}

