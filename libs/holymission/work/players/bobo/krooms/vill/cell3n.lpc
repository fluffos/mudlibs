inherit "room/room";
#include "/players/mangla/defs.h" 
object prisoner;
int south() {
    if("players/bobo/krooms/vill/guardroom"->open(3))
	TP->MOVEP("south#players/bobo/krooms/vill/corridor3");
    else {
        write("A grating bars your way!\n");
        say(this_player()->query_name()+" tries to go south, but fails.\n");
    }
    return 1;
}
int search(string str) {
    if(str!="bed" && str!="plank bed") return 0;
    say(this_player()->query_name()+" searches in the bed.\n");
    write("You search in the bed.\nWaeh. What a creature must have slept in this bed.\n");
    write("Stains and hair. Repulsive, indeed.\n");
    return 1;
}
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A prison cell";
long_desc=
"You're in one of the cells of the prison in Red Rock Junction.  It\n"+
"is not a happy or a fun place to be.  The cell has a small bed lying\n"+
"on the floor and a grated window so that you can look out.  The only\n"+
"other thing that catches your attention is a number of white marks\n"+
"on the walls.\n";
    items = ({
              "wall","A prisoner made a line for every day he was in,\n" +
                     "the hole wall is coverd with chalk line",
              "walls","The walls are really dirty",
              "lines","You can't count them",
              "bed","A simple plank bed",
              "plank bed","A bed like in every prison",
              "window","A grating is in front of the window and bars the way into liberty",
            });
    clone_list = ({ 1, 1, "enemy", "obj/monster",
                       ({ "set_name", "public enemy",
                          "set_alias", "enemy",
                          "set_race", "human",
                          "set_level", 15,
                          "set_hp", 200,
                          "set_short", "A public enemy",
                          "set_long", "He has been arrested here because he threatend" +
                                      " the safety of the realm.\n",
                          "set_al", -350,
                          "set_aggressive", 1,
                          "set_size", 3,
                          "add_money", 150,
                          "set_ac", 6,
                          "set_wc", 10 })
                 });
    ::reset();
}
init() {
    ::init();
    add_action("south","south");
    add_action("search","search");
}
