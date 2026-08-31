
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 1, "night light" : 0, "indoors" : 0, "mountain" : 1,
    "coords" : ({ 137, 17, 0 }),
  ]) );
  set_short("sacred summit");
  set_long(
    "The path out of the cave leads up to this summit. Snow drifts "
    "dot the ground regardless of season, and only a few clouds "
    "float by. Looking out, the world stretches out far below: "
    "a vast plain to the east, gradually becoming more forested to "
    "the south, and a craggy beach clearly visible to the west. "
    "The air here is cold and dry, but it seems charged somehow. "
    "A single immense spire of rock stands in the middle of the area. "
    "A ring of boulders has been arranged around the spire, taking "
    "up a lot of space and leaving the cliff edge threateningly close."
  );
  set_items( ([
    "cave" : "The cave to the north glitters with magical illumination.",
    ({ "snow", "drifts" }) : "Chunks of snow that have fallen here and "
      "remain unmelted.",
    "spire" : "Upon the spire are four etched dragons.",
    "dragons" : "They are shown flying, swimming, resting, and standing.",
    ({ "ring", "boulders" }) : "The ring of boulders seems to have some "
      "mystical meaning to the dragons.",
    ({ "cliff", "edge" }) : "The edge of the cliff is where the ground "
      "drops suddenly off into open air.",
  ]) );
  set_listen("default", "Strong winds howl past the side of the mountain.");
  set_smell("default", "A cold scent of earth and spice flits by with the wind.");
  set_exits( ([
    "north" : DRAG_ROOMS+"gathering",
  ]) );
}

void reset() {
  int i = 2+random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
  if (!present("dragon elder"))
    new(DRAG_MOBS+"dragonelder")->move(this_object());

  if(!present("microphone")) {
    ob = new("/wizards/pyro/personal/microphone");
    if(ob) {
      ob->set_microphone_name(path_file(file_name(this_object()))[1]);
      ob->set_owner(DRAG_D);
      ob->set_invincible(1);
      ob->move(this_object());
    }
  }
}

