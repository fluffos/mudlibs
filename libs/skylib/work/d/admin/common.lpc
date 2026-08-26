
#include <config.h>

#define DOM_TITLE "the domain of admin"
#define DOMAIN    "admin"

inherit ROOM_OBJ;

object board;

void setup() {
    int i;
    string *lords;

    set_light(100);

    add_exit("pub", CONFIG_START_LOCATION, "path");

    set_determinate("the ");
    set_short("common room of "+DOM_TITLE);

    set_long("Large relaxing chairs adorn the room.  The walls are covered "+
        "with strange motifs from different lands and the little shelf "+
        "above the fireplace is chocker block full of strange figurines "+
        "and bits of cloth.  It appears to be the common room of "+
        DOM_TITLE+" - the large red letters on the wall were the " +
        "give away.\n");

    add_item("chair", "The chairs are lazing around the room relaxing, it "
        "looks like they come here after a hard days working in "
        DOM_TITLE+".");
    add_item("fireplace", "A nice little fireplace with a cheery fire "
        "burning in it, keeping everyone warm.");
    add_item("figurine", "Small figurines, they look strangely familiar "
        "until you realise they are the members of "+DOM_TITLE+".\n");
    add_item("cloth", "Strange coloured bits of cloth strewn over the "
        "mantlepice for no readily apparent reason.");
    add_item("motif", "The motifs on close inspection look like stylised "
        "signatures of all the members of "+DOM_TITLE+".  Some of them are "
        "very strange, in fact there seem to be more than there are members "
        "of the house.  Perhaps they are the members of the future.");
    add_item("shelf", "A nice normal sort of shelf thing.  It is like all "
        "those ones you see in houses all over the place, execpt... the way "
        "it has been burnt... it does not look like the fire did it.");
    add_item("fire", "There is a fire happily burning away in the "
        "fireplace, spluttering and crackling to itself.  The flames almost "
        "seem afraid of something.  Looking closer you notice a picture "
        "tacked to the side of the fire place.");

    lords = map( DOMAIN_H->query_leaders(DOMAIN), (: CAP($1) :) );
    i = sizeof(lords);

    add_item("picture", "Tacked to the inside wall of the fire thingy, you "
        "know the hole bit at the bottom, is a small picture which looks "
        "like it was taken with the best of demon photography.  It is a "
        "picture of "+( i > 1 ? query_num(i)+" people holding small staves" :
        "a person holding a small staff")+", you think "+( i > 1 ? "they" :
        "it")+" might be "+query_multiple_short(lords)+" but you are not "
        "sure as the firelight sparkles in your eyes.");

    add_exit("common", "/w/common", "path");
    board = clone_object(BOARD_OBJ);
    board->set_datafile(DOMAIN);
    board->move(TO);

} /* setup() */
