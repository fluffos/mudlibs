#include "../priest.h"
inherit PRIEST_ROOM_DIR "officer_room";

void create_room(){
    ::create_room();
    officer_title = "Preceptor Hospitilar";
    set_short("The Office of the Hospitilar");
    set_long(
      "You have entered a small but comfortable room. A fireplace sheds light \
and fills the room with warmth. The walls are filled with beautifully \
woven tapestries, telling tales of the former Hospitilars. There's a bed \
in one corner, and a writing desk with a chair in another. A small altar \
is placed at the end of the room. There are shelves filled with \
alchemical ingredients and tools. The whole room gives you a sense of \
peace and relaxation. Even when you are down in the basement, you feel \
the strenght of the One True God, Boccob the Allmighty.");

    set_items(([
	"room": "This is the room of the Preceptor Hospitilar.",
	"fireplace": "The fireplace is small, but so is the room. There are \
couple of logs burning in it, giving light and warmth to this room. The \
flames flicker but don't die, altough it seems like nobody has added any \
wood to this fireplace for a long, long time. At least you don't see a \
supply of firewood nearby.",
	({ "wall", "walls" }) : "The walls are made of polished oak, with \
some beautifully woven tapestries hanged on them.",
	({ "tapestry", "tapestries" }): "They show some of the works of the \
earlier Hospitilars. They all look powerful and strong in their faith. \
All of them are clad in the Robes of the Order; White, Grey or Black. \
Even if the colour of the Robes changes, one thing remains the same in \
every picture: they all wear a cloak made of soft black cloth with a \
white cross on its back. You know that that is the cloak of the Knights \
of St. John.",
	({ "desk", "writing desk" }) : "There's a great amount of scrolls, \
maps and books on the desk. Seems like someone has been working on this \
table. A bottle of ink and a quill are placed on the corner so that they \
are ready for use. There are no ink stains, so the writer seems to be \
familiar with his tools. There's a chair at the desk for the Hospitilar \
to sit on.",
	"chair": "It is the Hospitilar's writing chair. Altough it seems \
ascetic it is very comfortable when you sit on it. You seem very relaxed \
when sitting on this chair; no wonder someone can work here for so long.",
	({ "scroll", "scrolls" }) : "There is a great amount of the scrolls, \
books and maps on the desk. You recognize the fluent writing of Slade on \
one scroll, but as they are none of your business you decide politely \
not to read them.",
	({ "map", "maps" }) : "There is a great amount of the scrolls, \
books and maps on the desk. There seem to be maps of the distant lands, \
altough you catch some familiar names on them. One of them particularily \
catches your attention: it is a map of the known world, and it seems \
like you know only a small fraction of it. Surely Boccob the Omnipotent \
is great, for he has been able to create all this for his followers to \
enjoy.",
	({ "book", "books" }) : "There is a great amount of the scrolls, \
books and maps on the desk. There are books with leather covers, some of \
them strenghtened with steel. You see text on them but understand only a \
part of them; in some you can't even read the script because it is of \
unknown language or the letters just seem to squiggle in your eyes, not \
making any sense at all. Maybe the Hospitilar knows how to read them - \
otherwise why would they be here?",
	"altar" : "The small altar is made of marble, resembling the Tricolor \
of the Order; The right side of it is made of white marble and the left \
of black. They are divided in half by a strike of the rare grey marble. \
The altar seems to be worn in two places, where the beseecher kneels \
down. Seems like it has been under heavy use.",
	({ "tools", "ingredients" }) : "You see many kinds of tools and \
ingredients placed on the shelves.",
	({ "shelf", "shelves" }) : "There are shelves with potions, powders \
and tools of different kinds and drawers filled with herbs, flowers, \
roots, berries, mushrooms and small vials containing liquid. They are \
used in alchemy, but there are some tools you have never seen and \
therefore can't even imagine using. You have no idea where some of the \
ingredients have been collected, as they're so unknown for you.",
      ]));

    add_exit("east", PRIEST_ROOM_DIR "basement");
    replace_program(PRIEST_ROOM_DIR "officer_room");
}

