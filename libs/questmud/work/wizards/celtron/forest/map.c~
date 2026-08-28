/* This is an example of a virtual map object.
Search for '---'s in the code. Important parts that you should configure
are marked with it. You should not change anything else than these
parts, if you don't know what you are doing, or else your map might not
work. 

You can add exits from other rooms to the map by using the format:
ONE_EXIT("[dir of this file]: [x] [y]","[direction]",
...

Example:
ONE_EXIT("/wizards/celtron/forest/map.c: 10 10", "east",
...

Have fun. :)

   Onarion.
*/ 

object rooms, environ;
string players;
int player_x, player_y;
string list_y,list_x;
string map;
int monsuluku;

query_number() {
  return monsuluku;
}

add_number() {
  monsuluku += 1;
}

/*
---
Add here special places. Moves player to the room in the defined dir,
when he moves to coordinates x,y. */

check_special_coords(x,y) {
/* One special place exit...*/
    if (x == 4 && y == 6) {
        return "/world/hallway/hall5";
    }
/*..end here. (so just copy it) */
    return 0;
}

reset(arg) {
    if (arg) {
        return 0;
    }
    start();
}

move_living(dir, x_coord, y_coord) {
    object room, living, ob, last_room; 
    int x, y, i;
    string file;

    if (dir == "X") {
        x = x_coord;
        y = y_coord;
    }
    if (dir == "east") {
        x = x_coord + 1;
        y = y_coord;
    }
    if (dir == "south") {
        x = x_coord;
        y = y_coord + 1;
    }
    if (dir == "north") {
        x = x_coord;
        y = y_coord - 1;
    }
    if (dir == "west") {
        x = x_coord - 1;
        y = y_coord;
    }
    if (dir == "northeast") {
        x = x_coord + 1;
        y = y_coord - 1;
    }
    if (dir == "southeast") {
        x = x_coord + 1;
        y = y_coord + 1;
    }
    if (dir == "northwest") {
        x = x_coord - 1;
        y = y_coord - 1;
    }
    if (dir == "southwest") {
        x = x_coord - 1;
        y = y_coord + 1;
    }
    
    i = 0;
    if (!room) { 
        list_x = 0;
        list_x = list_y[y];
        room = list_x[x];
    }
    if (!room) {

/*
---
Change your own map definitions here. (what letter means what room)
If you do not define a room file to some map letter, you cannot move 
in it and just a 'What ?' is returned from movement command. 
*/
      if (extract(map[y], x, x) == "f") {
        room = clone_object("/wizards/celtron/forest/forest1.c");
      }
      if (extract(map[y], x, x) == "F") {
        room = clone_object("/wizards/celtron/forest/forest2.c");
      }
      if (extract(map[y], x, x) == "b") {
        room = clone_object("/wizards/celtron/forest/bushes.c");
      }
      if (extract(map[y], x, x) == "h") {
        room = clone_object("/wizards/celtron/forest/hills.c");
      }
/* End of room definitions. */

      if (room) {
         room->set_coordinates(x,y);
         list_x = list_y[y];
         list_x[x] = room;
      }
    }
    i = 0;
    if (check_special_coords(x,y)) {
        file = check_special_coords(x,y);
        room = file;
    }         
    
    if (!room) {
        return 0;
    }
    this_player()->move_player(dir,room);
    return 1;
}

draw_map(x,y,big) {
    write("\n");
    if (big) {
       write(extract(map[y - 3], x - 5, x + 5) + "\n");
       write(extract(map[y - 2], x - 5, x + 5) + "\n");
       write(extract(map[y - 1], x - 5, x + 5) + "\n");
       write(extract(map[y], x - 5, x - 1) + "*" + extract(map[y], x + 1, x + 5)+"\n");
       write(extract(map[y + 1], x - 5, x + 5) + "\n");
       write(extract(map[y + 2], x - 5, x + 5) + "\n");
       write(extract(map[y + 3], x - 5, x + 5) + "\n");
       return 1;
    }
    write(extract(map[y - 2], x - 3, x + 3) + "\n");
    write(extract(map[y - 1], x - 3, x + 3) + "\n");
    write(extract(map[y], x - 3, x - 1) + "*" + extract(map[y], x + 1, x + 3) + "\n");
    write(extract(map[y + 1], x - 3, x + 3) + "\n");
    write(extract(map[y + 2], x - 3, x + 3) + "\n");
}

start() {
	int i;
        write("Starting map system.....");
/*
---
Set your own environment file for loaded rooms.
It is not configurable in any way, so just copy the old file and change
the path. */

	environ = clone_object("wizards/celtron/forest/environment");

/* End of environment file setting. */

        players = allocate(1);
        player_x = allocate(1);
        player_y = allocate(1);
        map = allocate(500);

/*
---
Here you can draw your map. Use any letters you want, but if you
haven't defined them earlier in this file, you cannot move to them, but
they will still be printed on the map. 
*/

map[0] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[1] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[2] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[3] =  "^^^^^^^^^^^^hhh^^^^^^^^^^^^^^^^hhhhhhbbhhhhhhhhhhh^^^^^^^^^^^^^^^^^^^^";
map[4] =  "^^^^^^^^^^hhhhhhhh^^^^^^^^hhhhhbbbbffffffffbbbbhhhhhhhhh^^^^^^^^^^^^^^";
map[5] =  "^^^^^^^hhhhhhbbhhhh^^^^hhhhhhbbbbffffffffffffbbbbbbbbbhhhhhhhhh^^^^^^^";
map[6] =  "^^^^?hhhhhbbbbbbbhhh^hhhhhbbbbbfffffffffffffffffffbbbbbhhhhhhhhhh^^^^^";
map[7] =  "^^^hhhhhbbbbbffbbbhhhhhhbbbbffffffffffFFffFfffffffffbbbbbhhhhhhhhhh^^^";
map[8] =  "^^^hhhbbbbbfffffbbbbhhbbbbfffffffffFFFFFFFFFFfffffffffbbbbhhhhhhhhh^^^";
map[9] =  "^^^hhhhhbbffffffffbbbhbbfffffffffFFFFFFFFFFFFFFfffffffffbbbbbhhhhhh^^^";
map[10] = "^^^hhhhbbbbbffffbbbbhhbbbbffffffffFFFFFFFFfffFFffffffffbbbbbhhhhhhh^^^";
map[11] = "^^^^hhhhhbbbbfbbbbbhhhhhbbbbffffffffFFFFFffffffffffffbbbbbhhhhhhh^^^^^";
map[12] = "^^^^^^hhhhbbbbbbbhhhhhhhbbbbbbfffffffFFffffffffffbbbbbbhhhhhhh^^^^^^^^";
map[13] = "^^^^^^^^^hhhhbbhhhhhhhhhhhhbbbbbffffffffffffffbbbbbbbhhhhhh^^^^^^^^^^^";
map[14] = "^^^^^^^^^^^^hhhhhhhhhhhhhhhbbbbbbbbfffffffbbbbbbbhhhhhh^^^^^^^^^^^^^^^";
map[15] = "^^^^^^^^^^^^^^^hhhhh^^hhhhhhbbbbbbbbbfffbbbbbbhhhhhh^^^^^^^^^^^^^^^^^^";
map[16] = "^^^^^^^^^^^^^^^^hh^^^^^^^^^hhhhhbbbbbbbbbbhhhhhh^^^^^^^^^^^^^^^^^^^^^^";
map[17] = "^^^^^^^^^^^^^^^hh^^^^^^^^^^^^^^hhhhhbbhhhhhh^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[18] = "^^^^^^^^^^^^^^^h^^^^^^^^^^^^^^^^^^^hhhhh^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[19] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[20] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[21] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
/* You can add lines. Just copy/paste them, but remember to change the
number, if the line, for example 'map[21] = ... on the last line. */

/* End of map drawing. */

list_y = allocate(sizeof(map));
list_x = allocate(strlen(map[3]));
while(i<sizeof(list_y)) {
  list_y[i] = allocate(sizeof(list_x));
  i += 1;
}
}                                                  

long() {
    write("This is the forest outmap object\n");
}

id() {
    return "forest_map_object";
}

name() {
    return "forest_map_object";
}

get() {
    return 0;
}

