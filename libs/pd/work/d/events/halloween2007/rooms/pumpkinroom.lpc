
#include <std.h>
#include <h2k7.h>

inherit VIRTUALROOM;

void reset() {
  object *mons;
  ::reset();
  if (!present("pumpkin"))
    do {
      new(H2K7ITEMS"pumpkin")->move(this_object());
    } while (random(1000) < 300);

  mons = filter(all_inventory(this_object()),
    (: $1->id("monster") :)
  );
  foreach (object m in mons)
    if (random(400) < 150)
      new(H2K7ITEMS"costume")->move(m);
}
