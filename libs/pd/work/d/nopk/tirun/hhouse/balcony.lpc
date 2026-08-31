#include <std.h>
#include <tirun.h>

inherit ROOM;

int garg;

void create() {
    ::create();
    set_smell("default", "The outside air is chilling, yet refreshing.");
    set_listen("default", "Wind whistles across the balcony.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
        "%^BLUE%^A cold breeze chills the bone.%^RESET%^\n"
        "The balcony is made up of a cold marble, which has become cracked and dirty over "
        "the years.  A low railing traverses the outer edge, curving around in a large half-"
        "circle.  Two large gargoyles sit at each end.  Over the edge of the railing, the "
        "courtyard is visible.  No entrance to the courtyard can be seen from here.");
    set_items(
        (["balcony" : "Carved from solid marble, this balcony must weigh a ton.",
          "railing" : "The short railing is obviously more for looks than safety.",
          "courtyard" : "The plants and shrubs in the courtyard seem to be "
                        "arranged into the shape of a winged creature.  "
                        "They have become too overgrown to know specifically what creature."]) );
    set_exits( ([ "west" : ROOMS"hhouse/upstairs" ]) );
    garg = 0;
}

void init() {
  ::init();
  add_action("look", "look");
}

void reset() {
  ::reset();
  garg = 0;
}

int look(string str) {
  object mon;

  if(!str)
    return 0;

  if(str != "gargoyle" && str != "statue" && str != "gargoyles")
    return 0;

  write(" ,                                                               ,\n"
" \\'.                                                           .'/\n"
"  ),\\                                                         /,( \n"
" /__\\'.                                                     .'/__\\\n"
" \\  `'.'-.__                                           __.-'.'`  /\n"
"  `)   `'-. \\                                         / .-'`   ('\n"
"  /   _.--'\\ '.          ,               ,          .' /'--._   \\\n"
"  |-'`      '. '-.__    / \\             / \\    __.-' .'      `'-|\n"
"  \\         _.`'-.,_'-.|/\\ \\    _,_    / /\\|.-'_,.-'`._         /\n"
"   `\\    .-'       /'-.|| \\ |.-\"   \"-.| / ||.-'\\       '-.    /`\n"
"     )-'`        .'   :||  / -.\\\\ //.- \\  ||:   '.        `'-(\n"
"    /          .'    / \\\\_ |  /o`^'o\\  | _// \\    '.          \\\n"
"    \\       .-'    .'   `--|  `\"/ \\\"`  |--`   '.    '-.       /\n"
"     `)  _.'     .'    .--.; |\\__\"__/| ;.--.    '.     '._  ('\n"
"     /_.'     .-'  _.-'     \\\\ \\/^\\/ //     `-._  '-.     '._\\\n"
"     \\     .'`_.--'          \\\\     //          `--._`'.     /\n"
"      '-._' /`            _   \\\\-.-//   _            `\\ '_.-'\n"
"          `<     _,..--''`|    \\`\"`/    |`''--..,_     >`\n"
"           _\\  ``--..__   \\     `'`     /   __..--``  /_\n"
"          /  '-.__     ``'-;    / \\    ;-'``     __.-'  \\\n"
"         |    _   ``''--..  \\'-' | '-'/  ..--''``   _    |\n"
"         \\     '-.       /   |/--|--\\|   \\       .-'     /\n"
"          '-._    '-._  /    |---|---|    \\  _.-'    _.-'\n"
"              `'-._   '/ / / /---|---\\ \\ \\ \\'   _.-'`\n"
"                   '-./ / / / \\`---`/ \\ \\ \\ \\.-'\n"
"                       `)` `  /'---'\\  ` `(`\n"
"                      /`     |       |     `\\\n"
"                     /  /  | |       | |  \\  \\\n"
"                 .--'  /   | '.     .' |   \\  '--.\n"
"                /_____/|  / \\._\\   /_./ \\  |\\_____\\\n"
"               (/      (/'     \\) (/     `\\)      \\)\n");

  if(garg == 0) {
  mon = new(MONSTER);
  mon->set_name("gargoyle");
  mon->set_alignment(-500);
  mon->set_id(({"gargoyle", "statue"}));
  mon->set_short("Gargoyle");
  mon->set_long("This gargoyle has been disturbed from his watchful perch, and is now defending his home.");
  mon->set_gender("male");
  mon->set_race("gargoyle");
  mon->set_body_type("dragon");
  mon->set_level(5+random(2));
  mon->move(this_object());
  mon->kill_ob(this_player());
  garg = 1;
  }

  return 1;
}
