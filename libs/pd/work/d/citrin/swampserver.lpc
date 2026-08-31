#include <std.h>
#include <citrin.h>
inherit VIRTUALSERVER;

void create() {
    ::create();
    set_how_long(3);
    set_day_sentances( ({
	"The ground is wet and muddy.",
	"Green moss covers most of the ground.",
	"The occasional spiderweb can be seen dangling from the "
	"trees awaiting unsuspecting prey.",
	"Ocassional a ray of sun seems to get past the heavy "
	"over cast of the trees.\n",
	"Tree stumps are on the ground where animals have knocked them "
	"down.",
	"An occasional breeze blows through the area.",
      }) );
    set_night_sentances( ({
	"The ground is wet and muddy.",
	"Green moss covers most of the ground.",
	"The occasional spiderweb can be seen dangling from the "
	"trees awaiting unsuspecting prey.",
	"Almost no light can pass the overcover of trees.\n",
	"Tree stumps are on the ground where animals have knocked them "
	"down.",
	"The air is completely still.\n",
      }) ); 
    set_item_list(([ 
	"trees":"They are covered in moss.",
	"rocks":"The rocks are covered in moss.",
	({"ground","moss"}):"The ground is wet and spongy.  It is covered "
	"by green moss.",
      ]));
    set_properties( ([ "light" : 1,
	"night light" : 1,
	"forest" : 1,
      ]) );
    set_short("lost in a forest");
    set_reset_list(({
	MON"swamp/monster",MON"swamp/dragon",MON"swamp/dragonfly",
	MON"swamp/spider",
      }));
    set_smell("A foul odor reaps the swamp.");
}


