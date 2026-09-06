#include <const.h>

string mymap;

/** An object for generating ASCII maps.
 */

string *bottom_row = ({
 "'---'",
 "'----",
 "'---'",
 "'----",
 "|   |",
 "|   .",
 "|   |",
 "|    ",
 "'---'",
 "'----",
 "'---'",
 "'----",
 "|   |",
 "|   .",
 "|   |",
 "|    ",
 "----'",
 "-----",
 "----'",
 "-----",
 ".   |",
 ".   .",
 ".   |",
 ".    ",
 "----'",
 "-----",
 "----'",
 "-----",
 "    |",
 "    .",
 "    |",
 "     " });

string *top_row = ({
 ".---.",
 ".----",
 ".---.",
 ".----",
 "|   |",
 "|   '",
 "|   |",
 "|    ",
 ".---.",
 ".----",
 ".---.",
 ".----",
 "|   |",
 "|   '",
 "|   |",
 "|    ",
 "----.",
 "-----",
 "----.",
 "-----",
 "'   |",
 "'   '",
 "'   |",
 "'    ",
 "----.",
 "-----",
 "----.",
 "-----",
 "    |",
 "    '",
 "    |",
 "     " });

string *middle_row = ({
 "|   |",
 "|    ",
 "    |",
 "     " });

string *tile_types = ({ "flats", "river", "ocean", "cliff", "sand", "road", "lake", "hills", "mud", "rocky ground", "granite cliff", "lava", "dunes", "forest floor", "river bank", "rocky grass", "rocky desert", "tiled floor", "snow", "snowy hills", "rock edge" });
string *tile_small = ({ "@@", "rr", "OO", "##", "++", "::", "ww", "^^", "``", "o.", "#.", "ll", "dd", "ff", "`:", "@o", "@+", "[]", "*.", "*^", "o:" });
string *tile_small_color = ({ "~[020", "~[040", "~[120", "~[030", "~[110", "~[030", "~[120", "~[100", "~[030", "~[080", "~[070", "~[090", "~[110", "~[100", "~[100", "~[030", "~[090", "~[070", "~[150", "~[150", "~[080" });
int *tile_fertility = ({ 7, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 15, 10, 4, 0, 0, 1, 0, 0 });

int bottom_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y+1][x+1]<<1) + (map[y+1][x]<<2) + (map[y+1][x-1]<<3) + (map[y][x-1]<<4);
}

int top_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y-1][x+1]<<1) + (map[y-1][x]<<2) + (map[y-1][x-1]<<3) + (map[y][x-1]<<4);
}

int middle_index( int x, int y, mixed map ) {
   return map[y][x+1] + (map[y][x-1]<<1);
}

string zbuf;

string query_zbuf() {
   return zbuf;
}

string make_map( string map_src, int map_width, int map_height ) {
   mixed base_map;
   string map_str, wall, wall5, floor5;
   int ix, iy;

   base_map = allocate( map_height + 2 );
   for( iy = sizeof(base_map); iy--; )
      base_map[iy] = allocate( map_width + 2 );

   // Create the grid from the map_src
   for( iy = map_height + 2; iy--; )
   for( ix = map_width + 2; ix--; )
   if( iy == 0 || iy > map_height || ix == 0 || ix > map_width || map_src[(ix-1) + (iy-1) * map_width] != ' ' ) {
      base_map[iy][ix] = 1;
   }
//   else
//      msg("Clear base_map for ix="+ix+", iy="+iy);

   // Upper-left corner
   if( base_map[1][1] ) map_str = " "; else map_str = ".";
   // Top row
   for( ix = 1; ix <= map_width; ix++ )
      map_str += bottom_row[bottom_index(ix, 0, base_map)];
   // Upper-right corner
   if( base_map[1][map_width] ) map_str += " \n"; else map_str += ".\n";

   // Loop through map rows
   for( iy = 1; iy <= map_height; iy++ ) {
      // Leftmost column, top row
      if( base_map[iy][1] )
         map_str += base_map[iy-1][1]?" ":"'";
      else
         map_str += "|";
      // Top cell row, middle
      for( ix = 1; ix <= map_width; ix++ )
      if( base_map[iy][ix] )
         map_str += top_row[top_index(ix, iy, base_map)];
      else
         map_str += "     ";
      // Rightmost column, top row
      if( base_map[iy][map_width] )
         map_str += base_map[iy-1][map_width]?" \n":"'\n";
      else
         map_str += "|\n";

      // Leftmost column, middle row
      if( base_map[iy][1] )
         map_str += " ";
      else
         map_str += "|";
      // Middle cell row, middle
      for( ix = 1; ix <= map_width; ix++ )
      if( base_map[iy][ix] )
         map_str += middle_row[middle_index(ix, iy, base_map)];
      else
         map_str += "     ";
      // Rightmost column, middle row
      if( base_map[iy][map_width] )
         map_str += " \n";
      else
         map_str += "|\n";

      // Leftmost column, bottom row
      if( base_map[iy][1] )
         map_str += base_map[iy+1][1]?" ":".";
      else
         map_str += "|";
      // Bottom cell row, middle
      for( ix = 1; ix <= map_width; ix++ )
      if( base_map[iy][ix] )
         map_str += bottom_row[bottom_index(ix, iy, base_map)];
      else
         map_str += "     ";
      // Rightmost column, top row
      if( base_map[iy][map_width] )
         map_str += base_map[iy+1][map_width]?" \n":".\n";
      else
         map_str += "|\n";
   }

   // Bottom-left corner
   if( base_map[map_height][1] ) map_str += " "; else map_str += "'";
   // Bottom row
   for( ix = 1; ix <= map_width; ix++ )
      map_str += top_row[top_index(ix, map_height+1, base_map)];
   // Bottom-right corner
   if( base_map[map_height][map_width] ) map_str += " \n"; else map_str += "'\n";

   // Generates a zbuffer to give this room's shape.
   wall = " "; wall[0] = LAYER_INVALID + '0'; wall5 = tab( wall, 5 );
   floor5 = " "; floor5[0] = LAYER_TERRAIN + '0'; floor5 = tab( floor5, 5 );
   zbuf = wall + tab(wall5, map_width) + wall;
   for( iy = 1; iy <= map_height; iy++ ) {
      string row;

      row = wall;
      for( ix = 1; ix <= map_width; ix++ )
         if( base_map[iy][ix] ) row += wall5;
         else row += floor5;
      row += wall;
      zbuf += tab( row, 3 );
   }
   zbuf += wall + tab(wall5, map_width) + wall;

   return map_str[..<2]; // Drop trailing \n
}

string *query_tile_types() {
   return tile_types;
}

string *query_tile_small() {
   return tile_small;
}

string *query_tile_small_color() {
   return tile_small_color;
}

int *query_tile_fertility() {
   return tile_fertility;
}

string base_world_map() {
   return
      "." + tab("-", OVERWORLD_WIDTH * 5) + ".\n" +
      tab( "|" + tab(" ", OVERWORLD_WIDTH*5) + "|\n", OVERWORLD_HEIGHT * 3 ) +
      "'" + tab("-", OVERWORLD_WIDTH * 5) + "'\n";
}

string base_world_zbuf() {
   string wall, floor;

   wall = " "; wall[0] = LAYER_INVALID + '0';
   floor = " "; floor[0] = LAYER_TERRAIN + '0';

   return
      tab(wall, OVERWORLD_WIDTH * 5 + 2) +
      tab( wall + tab(floor, OVERWORLD_WIDTH*5) + wall, OVERWORLD_HEIGHT * 3 ) +
      tab(wall, OVERWORLD_WIDTH * 5 + 2);
}

string *hills = ({
"  .-''-.            ",
".'      '.  .-''-.  ",
"          .'      '.",
"       .-''-.       ",
"'-.  .'      '.  .-'",
"   '.          .'   "
});

string *hills_mask = ({
"DDDDDAAAAA``````````",
"DDDDDAAAAADDDDDAAAAA",
"``````````DDDDDAAAAA",
"`````DDDDDAAAAA`````",
"AAAAADDDDDAAAAADDDDD",
"AAAAA``````````DDDDD"
});

string *mountains = ({
"  .  /   \\ /'\\ ",
"`/'\\   .  /   \\",
"/   \\ /'\\   .  "
});

string *mountains_mask = ({
"cc`ffbbbbbcbbbf",
"c```fiihllbbbbb",
"`````ihhhliihll"
});

string *mud = ({
";;`;;`;;`;;`;;`",
"`;;`;;`;;`;;`;;",
";;`;;`;;`;;`;;`",
"`;;`;;`;;`;;`;;",
";;`;;`;;`;;`;;`",
"`;;`;;`;;`;;`;;",
});

string *mud_mask = ({
"S```VS```VS```V",
"```````````````",
"Y```\\Y```\\Y```\\",
"S```VS```VS```V",
"```````````````",
"Y```\\Y```\\Y```\\"
});


string *mountains_color = ({
"\49\49\48\49\49\48\49\49\49\48\49\48\49\48\49",
"\49\48\49\48\49\49\49\48\49\49\48\49\49\49\48",
"\48\49\49\49\48\49\48\49\48\49\49\49\48\49\49"
});

// Backslash probs, should be:
// \     / \\     \\/\ /  \\
// \\/\ /  \\\     / \\
//  / \\     \\/\ /  \\\
// /  \\\     / \\     \\/\
//      \\/\ /  \\\     / \\
//

/*
string *big_mount = ({
"\\     / \\\\     \\\\/\\ /  \\\\",
"\\\\/\\ /  \\\\\\     / \\\\     ",
" / \\\\     \\\\/\\ /  \\\\\\    ",
"/  \\\\\\     / \\\\     \\\\/\\ ",
"     \\\\/\\ /  \\\\\\     / \\\\",
"\\     / \\\\     \\\\/\\ /  \\\\",
"\\\\/\\ /  \\\\\\     / \\\\     ",
" / \\\\     \\\\/\\ /  \\\\\\    ",
"/  \\\\\\     / \\\\     \\\\/\\ ",
"     \\\\/\\ /  \\\\\\     / \\\\",
"\\     / \\\\     \\\\/\\ /  \\\\",
"\\\\/\\ /  \\\\\\     / \\\\     ",
" / \\\\     \\\\/\\ /  \\\\\\    ",
"/  \\\\\\     / \\\\     \\\\/\\ ",
"     \\\\/\\ /  \\\\\\     / \\\\",
});
*/

string *forest_floor = ({
";;.;;;;;;;",
";;;:;;;.;;",
";;.;;;;;;;",
":;;;;:;.;;",
";;.;;;;;:;",
";;;;;;;.;;",
});

string *forest_floor_color = ({
"\35\35\32\35\35\35\35\35\35\35",
"\35\35\35\32\35\35\35\32\35\35",
"\35\35\32\35\35\35\35\35\35\35",
"\32\35\35\35\35\32\35\32\35\35",
"\35\35\32\35\35\35\35\35\32\35",
"\35\35\35\35\35\35\35\32\35\35",
});

string *forest_floor_mask = ({
"S```VS```V",
"``````````",
"Y```\\Y```\\",
"S```VS```V",
"``````````",
"Y```\\Y```\\",
});


string *grass = ({
"````.`````",
"`.`````.``",
"`````````.",
"``.```.```",
"````.`````",
".`````````",
});

string *grass_color = ({
"\32\32\32\32\42\32\32\32\32\32",
"\32\42\32\32\32\32\32\42\32\32",
"\32\32\32\32\32\32\32\32\32\42",
"\32\32\42\32\32\32\42\32\32\32",
"\32\32\32\32\42\32\32\32\32\32",
"\42\32\32\32\32\32\32\32\32\32",
});

string *rocky_grass = ({
"```````````.:.``````",
"``:.`````````````.:`",
"`:.````:.````````:.`",
"``````:.:.```:.```:`",
"`````:.:````:.:.````",
"``````:.:`````.:.```",
":.`````:.``````.:.``",
".:.:````````````````",
"````````````.:.:.```",
});

string *rocky_grass_color = ({
"\32\40\32\32\32\32\32\32\32\32\32\50\50\50\32\32\40\32\32\32",
"\32\32\50\50\32\32\32\32\32\32\32\32\32\32\32\32\32\50\50\32",
"\32\50\50\32\32\40\32\50\50\32\32\32\40\32\32\32\32\50\50\32",
"\32\32\32\32\32\32\50\50\50\50\32\32\32\50\50\32\32\32\50\32",
"\32\32\40\32\32\50\50\50\32\32\32\32\50\50\50\50\32\32\32\32",
"\32\32\32\32\32\32\50\50\50\32\40\32\32\32\50\50\50\32\32\32",
"\50\50\32\32\32\32\32\50\50\32\32\32\32\40\32\50\50\50\32\32",
"\50\50\50\50\32\32\40\32\32\32\32\32\32\32\32\32\32\32\32\32",
"\32\32\32\32\32\32\32\32\32\32\32\32\50\50\50\50\50\32\32\32",
});

string *sand = ({
".....",
"...:.",
":....",
});

string *water = ({
"OoOoOoOoOo",
"oOoOoOoOoO",
"OoOoOoOoOo",
"oOoOoOoOoO",
"OoOoOoOoOo",
"oOoOoOoOoO"
});

string *lava = ({
"    .     ",
" o      . ",
"   .  o   ",
"          ",
"  o       ",
"       . o"
});

mapping neighbortab =
([
 'A':0, 'C':0, 'B':0, 'F':2, 'D':2, 'L':2, 'H':2, 'I':0,
 'Q':0, 'S':0, 'R':0, 'V':2, 'T':2, '\\':2, 'X':2, 'Y':0,
 'a':1, 'c':1, 'b':1, 'f':1, 'd':3, 'l':3, 'h':3, 'i':3,
 'q':1, 's':1, 'r':1, 'v':1, 't':3, '|':3, 'x':3, 'y':3
]);

string *water_mask = ({
"Ss`vVSs`vV",
"``````````",
"Yy`|\\Yy`|\\",
"Ss`vVSs`vV",
"``````````",
"Yy`|\\Yy`|\\",
});

string *sand_mask = ({
"ssvvv",
"`````",
"yyy||",
});

string *road = ({
":::::",
":::::",
":::::"
});

string *road_mask = ({
"s```v",
"`````",
"y```|",
});

string *rocky = ({
"....:...........:........",
".........o.........:..o..",
"...............o.........",
"..o.......:..............",
"....:..............:..o..",
".........:...............",
".........................",
"..........o......:.......",
"...o........:............"
});

string *rocky_mask = ({
"ssvvvssvvvssvvvssvvvssvvv",
"`````````````````````````",
"yyy||yyy||yyy||yyy||yyy||",
"ssvvvssvvvssvvvssvvvssvvv",
"`````````````````````````",
"yyy||yyy||yyy||yyy||yyy||",
"ssvvvssvvvssvvvssvvvssvvv",
"`````````````````````````",
"yyy||yyy||yyy||yyy||yyy||",
});


string *rocky_desert = ({
"++.::....++.....:......++",
".++.....++.........::++..",
"..+++...++++...o..++++...",
"..o.++++++++++...++..:...",
"....:.+++....+++++.:..o..",
".::.....++..o..+++++.....",
".........++......+++...:.",
"......::.++......+++++...",
"+..o.....++.:...::....+++"
});

/*
string *tile_floor = ({
"/\\/\\/\\/\\/\\",
"\\/\\/\\/\\/\\/",
"/\\/\\/\\/\\/\\",
"\\/\\/\\/\\/\\/",
"/\\/\\/\\/\\/\\",
"\\/\\/\\/\\/\\/",
"/\\/\\/\\/\\/\\",
"\\/\\/\\/\\/\\/",
"/\\/\\/\\/\\/\\",
"\\/\\/\\/\\/\\/"
});
*/

string *tile_floor = ({
" /\\  /\\  /\\  /\\  /\\ ",
"/  \\/  \\/  \\/  \\/  \\",
"\\  /\\  /\\  /\\  /\\  /",
" \\/  \\/  \\/  \\/  \\/ ",
" /\\  /\\  /\\  /\\  /\\ ",
"/  \\/  \\/  \\/  \\/  \\",
"\\  /\\  /\\  /\\  /\\  /",
" \\/  \\/  \\/  \\/  \\/ ",
" /\\  /\\  /\\  /\\  /\\ ",
"/  \\/  \\/  \\/  \\/  \\",
"\\  /\\  /\\  /\\  /\\  /",
" \\/  \\/  \\/  \\/  \\/ "
});

string *tile_floor_color = ({
"\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7",
"\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8",
"\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8",
"\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7",
"\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7",
"\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8",
"\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8",
"\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7",
"\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7",
"\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8",
"\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8",
"\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7\7\8\8\7"
});


/*
string *tile_floor_color = ({
"\4\8\4\8\4\8\4\8\4\8",
"\8\4\8\4\8\4\8\4\8\4",
"\4\8\4\8\4\8\4\8\4\8",
"\8\4\8\4\8\4\8\4\8\4",
"\4\8\4\8\4\8\4\8\4\8",
"\8\4\8\4\8\4\8\4\8\4",
"\4\8\4\8\4\8\4\8\4\8",
"\8\4\8\4\8\4\8\4\8\4",
"\4\8\4\8\4\8\4\8\4\8",
"\8\4\8\4\8\4\8\4\8\4"
});
*/


string *rocky_desert_color = ({
"\59\59\59\57\57\59\59\59\59\59\59\59\59\59\59\59\57\59\59\59\59\59\59\59\49",
"\59\59\59\59\59\59\59\59\59\57\59\59\59\59\59\59\59\59\59\57\57\59\57\59\59",
"\59\59\59\59\59\59\59\59\49\49\49\49\59\59\59\57\59\59\59\59\59\59\59\59\59",
"\59\59\57\59\59\59\49\49\49\49\49\59\59\59\59\59\59\59\59\59\59\57\59\59\59",
"\59\59\59\59\57\59\49\49\49\59\59\59\59\59\59\57\57\59\59\57\59\59\57\59\59",
"\59\57\57\59\59\59\59\59\59\57\59\59\57\59\59\59\59\59\49\49\59\59\59\59\59",
"\59\59\59\59\59\59\59\59\59\59\59\59\59\59\59\59\59\49\49\49\59\59\59\57\59",
"\59\59\59\59\59\59\57\57\59\49\49\59\59\59\59\59\59\49\49\59\59\59\59\59\59",
"\49\59\59\57\59\59\59\59\59\49\49\59\57\59\59\59\57\57\59\59\59\59\59\49\49"
});

/* Some notes on masks:
 *
 * Masks are a bit of a pain. The way to understand what a single character
 * does is to break it out to its binary representation. It's something like
 * this:
 *
 * 01v|drul
 *
 * v = If set, use a vertical tile to match (see neighbor_tab),
 *     otherwise use the horizontal tab. Notes on neighbor_tab:
 *     0=left, 1=up, 2=right, 3=down
 * | = If clear, then ALL adjacent tiles must match; otherwise,
 *     only one adjacent tile must match.
 * l,u,r,d = Which tile(s) have to match -- left, up, right, down.
 */



nosave mixed tiletab, coltab, masktab, ztab, forcemask;

mixed code, color, z;

mapping terrain_files = ([
   1: "/scn/ground/map_grass",
   2: "/scn/water/map_river",
   7: "/scn/water/map_lake",
   15: "/scn/ground/map_river_bank",
]);

void generate_scenery( string grid, object dest ) {
   int i;
   mapping tile_list = ([ ]);
   string s;
   object ob;

   foreach( ob : all_inventory(dest) )
      if( ob->query_is_landscape() ) destruct(ob);

   if( !stringp(grid) ) return;
   foreach( i : grid ) tile_list += ([ terrain_files[i] ]);
   tile_list -= ([ 0 ]);
   foreach( s : tile_list ) clone_object(s)->move(dest);
}

mixed *query_last_tile() {
   return ({ code, color, z });
}

varargs void build_tile( int x, int y, int type, int *tilegroup, int match_mask, mixed alt_color ) {
   int ix, iy;

   if( !alt_color ) alt_color = coltab[type];

   if( masktab[type] ) {
      int iret, curr_mask;

      code = color = z = "               ";
      iret = 0;
      y %= sizeof(tiletab[type]);
      for( iy = 0; iy < 3; iy++ ) {
         x %= strlen(tiletab[type][0]);
         for( ix = 0; ix < 5; ix++ ) {
//            debug("ix="+ix+", iy="+iy+", strlen(tiletab["+type+"][0]) is "+strlen(tiletab[type][0]),"map");
            curr_mask = masktab[type][y][x];
            if( ((curr_mask & 0x10) && ((curr_mask & match_mask & 0xF) > 0)) ||
               (curr_mask & match_mask) == curr_mask ) {
               code[iret] = tiletab[type][y][x];
               if( intp(alt_color) )
                  color[iret] = alt_color;
               else {
                  color[iret] = alt_color[y][x];
               }
               z[iret] = ztab[type] + '0';
            }
            else {
               int ineighbor;
               if( forcemask[type] )
                  ineighbor = forcemask[type];
               else
                  ineighbor = tilegroup[neighbortab[masktab[type][y][x]]];
               code[iret] = tiletab[ineighbor][y % sizeof(tiletab[ineighbor])][x % strlen(tiletab[ineighbor][0])];
               if( intp(coltab[ineighbor]) )
                  color[iret] = coltab[ineighbor];
               else {
//                  debug("coltab["+ineighbor+"]["+y+"]["+x+"] is "+coltab[ineighbor][y][x], "map");
                  color[iret] = coltab[ineighbor][y % sizeof(tiletab[ineighbor])][x % strlen(tiletab[ineighbor][0])];
               }
               z[iret] = ztab[ineighbor] + '0';
            }

            x++;
            iret++;
         }
         x -= 5;
         y++;
         y %= sizeof(tiletab[type]);
      }
   }
   else {
      x %= strlen(tiletab[type][0]);
//      debug("type="+type+", x="+x+", y="+y,"map");
      // Grabs the characters from the relevant location in the
      // tile template. It loops horizontally and vertically, though
      // does assume that the width is a multiple of five.
      code = tiletab[type][y%sizeof(tiletab[type])][x..x+4];
      code += tiletab[type][(y+1)%sizeof(tiletab[type])][x..x+4];
      code += tiletab[type][(y+2)%sizeof(tiletab[type])][x..x+4];
      if( intp(alt_color) )
         color = alt_color;
      else {
         color = alt_color[y%sizeof(alt_color)][x..x+4];
         color += alt_color[(y+1)%sizeof(alt_color)][x..x+4];
         color += alt_color[(y+2)%sizeof(alt_color)][x..x+4];
      }
      z = ztab[type];
   }
}


void paint_world_map( object painter, string grid ) {
   int ix, iy, x, y, tile, itile;
   string *type, *mask;
   int *tilegroup;
   int match_mask;

   for( iy = 0; iy < OVERWORLD_HEIGHT; iy++ )
   for( ix = 0; ix < OVERWORLD_WIDTH; ix++ ) {
      x = ix * 5 + 1;
      y = iy * 3 + 1;
//      debug("Paint x="+x+", y="+y, "map");
      mask = 0;
      tile = grid[itile = iy * OVERWORLD_WIDTH + ix];
      if( tile < 0 ) tile = 1;
      if( tile >= sizeof(tiletab) ) tile = 1;

      match_mask = 0x60;
      if( ix == 0 || tile == grid[itile - 1] )
         match_mask |= 1;
      if( iy == 0 || tile == grid[itile - OVERWORLD_WIDTH] )
         match_mask |= 2;
      if( ix == OVERWORLD_WIDTH - 1 || tile == grid[itile + 1] )
         match_mask |= 4;
      if( iy == OVERWORLD_HEIGHT - 1 || tile == grid[itile + OVERWORLD_WIDTH] )
         match_mask |= 8;
      tilegroup = allocate(4);
      tilegroup[0] = ix==0?tile:grid[itile-1];
      tilegroup[1] = iy==0?tile:grid[itile-OVERWORLD_WIDTH];
      tilegroup[2] = ix==OVERWORLD_WIDTH-1?tile:grid[itile+1];
      tilegroup[3] = iy==OVERWORLD_HEIGHT-1?tile:grid[itile+OVERWORLD_WIDTH];
      build_tile(x - 1, y - 1, tile, tilegroup, match_mask);
      painter->paint_tile( x, y, code, color, z );
   }
}


void create() {
   tiletab = ({ 0, grass, water, water, mountains, sand, road, water, hills, mud, rocky, mountains, lava, hills, forest_floor, sand, rocky_grass, rocky_desert, tile_floor, grass, hills, rocky });
   coltab = ({ 0, grass_color, 70, 76, mountains_color, 59, 48, 76, 42, 0x34, 0x08, 0x07, 0x19, 0x3B, forest_floor_color, 0x23, rocky_grass_color, rocky_desert_color, tile_floor_color, 0x7F, 0x7F, 0x08 });
   masktab = ({ 0, 0, water_mask, water_mask, mountains_mask, sand_mask, road_mask, water_mask, hills_mask, mud_mask, 0, mountains_mask, water_mask, hills_mask, forest_floor_mask, 0, 0, 0, 0, water_mask, hills_mask, rocky_mask });
   forcemask = ({ 0, 0, 0, 0, 9, 0, 0, 0, 1, 0, 0, 10, 0, 5, 0, 0, 0, 0, 0, 0, 20, 0 });
   ztab = ({ 0, LAYER_TERRAIN, LAYER_WATER, LAYER_WATER, LAYER_MOUNTAIN, LAYER_TERRAIN, LAYER_ROAD, LAYER_WATER, LAYER_ROUGH, LAYER_TERRAIN, LAYER_ROUGH, LAYER_MOUNTAIN, LAYER_WATER, LAYER_ROUGH, LAYER_ROUGH, LAYER_TERRAIN, LAYER_TERRAIN, LAYER_TERRAIN, LAYER_TERRAIN, LAYER_TERRAIN, LAYER_ROUGH, LAYER_ROUGH });
   if( sizeof(tiletab) != sizeof(coltab) || sizeof(coltab) != sizeof(masktab) || sizeof(masktab) != sizeof(forcemask) ||
      sizeof(forcemask) != sizeof(ztab) )
      debug("Map daemon: array sizes do not match: " + as_string(({ sizeof(tiletab), sizeof(coltab), sizeof(masktab), sizeof(forcemask), sizeof(ztab) })) );
}

int query_zlevel( int type ) {
   if( type < 0 || type >= sizeof(ztab) - 1 ) return LAYER_INVALID;
   return ztab[type+1];
}
