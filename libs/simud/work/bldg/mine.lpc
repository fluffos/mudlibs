inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

BGM( "bjorn/bjorn_lynne-in_the_cave.mid" )

DISTANT( "a mine" )
SPECIFIC( "the mine" )
LOOK( "A set of wooden planks frames and supports a hole dug deep into the earth.\n\nOwned by $(OWNER)." )
PLURAL( "mines" )
NAME( "mine" )
PHRASE( "A mine entrance leads deep into the ground." )

int direction;
int idle_time;
int full_depth;

mapping survey_result;

create() {
   ::create();
/* OBJEDIT { */
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void reset_idle_time() {
   idle_time = 0;
}

void decay_to_dungeon() {
   object ob;
   // Blueprint check.
   if( !environment() ) return;
   // Firstly, destroy my contents. Could later just destroy rooms and exits and scatter
   // the other stuff throughout the dungeon...
   foreach( ob : deep_inventory() ) {
      if( ob->query_is_player() ) {
         ob->move( load_object("/obj/void") );
         debug( "Made a mine into a dungeon with a player inside. Little weird." );
      }
      else
         destruct( ob );
   }
   // Find any exits leading into this mine.
   foreach( ob : all_inventory(environment()) )
      if( ob->query_host() == this_object() ) destruct( ob );
   // Make a dungeon, filling it with goodies...
   // Make an exit into the dungeon.
}

void reset() {
   idle_time++;
   // After idle_time is long enough, chance of turning the mine into an abandoned mine/dungeon...
}

/*Used by the survey command, tells if you saw all the way down*/
int query_full_depth() {
   return full_depth;
}

void set_full_depth(int i) {
   full_depth = i;
}

mapping query_survey() {
   return survey_result;
}

void set_survey(mapping temp) {
   survey_result = temp;
}

int query_idle_time() {
   return idle_time;
}

int query_direction() {
   if( !direction ) direction = SMAKE_C(0,1,0);
   return direction;
}

void set_direction( int x ) {
   direction = x;
}

mapping query_legal_layers() {
   return FLOOR_CHARS + ([ LAYER_MOUNTAIN + '0':1 ]);
}

mapping query_legal_border_layers() {
   return FLOOR_CHARS;
}

void on_map_paint( object painter ) {
   if( query_direction() == SMAKE_C(0,-1,0) )
      painter->paint_shape( query_x(), query_y(),"|   |\n|\\_/|\n\t'-'", 0x03, LAYER_MOUNTAIN);
   else if( query_direction() == SMAKE_C(1,0,0) )
      painter->paint_shape( query_x(), query_y(),"\t.-.\t\n|--/|\n| |  ", 0x03, LAYER_MOUNTAIN);
   else if( query_direction() == SMAKE_C(-1,0,0) )
      painter->paint_shape( query_x(), query_y(),"\t.-.\t\n|\\--|\n  | |", 0x03, LAYER_MOUNTAIN);
   else
      painter->paint_shape( query_x(), query_y(),"\t.-.\t\n|/ \\|\n|   |", 0x03, LAYER_MOUNTAIN);
}

mapping query_shape() {
   return SHAPE_BOX( 5, 3 );
}

int check_direction( int dir ) {
   int pos, tile;

   if( !dir ) {
      msg("You have to specify a direction when building a mine (i.e. 'build mine to the north').");
      return -1;
   }

   set_direction(SINVERT_C(dir));

   // Multiply up.
   dir = SMAKE_C(SCX(dir)*5, SCY(dir)*3, 0);
   pos = OFFSET_C(this_player()->query_coord(), dir);

   // Snap to grid
   pos = MAKE_C(((CX(pos)-1) / 5) * 5 + 1, ((CY(pos)-1) / 3) * 3 + 1, 0);
   // Now check to see if the tiletype is valid. Query the center of the tile
   // to make life a bit easier.
   tile = environment(this_player())->get_tiletype(CX(pos)+2, CY(pos)+1);
   if( !tile ) {
      msg("You can't build off the edge of the map.");
      return -1;
   }
   tile -= '0'; // get_tiletype uses the zbuffer, which offsets by '0' ...

   if( tile != LAYER_MOUNTAIN ) {
      //debug("tile=="+as_string(tile)+", pos = "+MAKE_CSTR(pos));
      msg( "Mines must be built against a mountain face. Find a mountainous place." );
      return -1;
   }

   // Offset horizontally a bit to make the entrance stick out...
   if( SCX(dir) )
      pos = OFFSET_C(pos, SMAKE_C(-SCX(dir) / 5,0,0));

   // If facing south, adjust to find the entrance.
   // The mountain tiles have funny patterns, and this helps
   // to compensate.
   if( query_direction() == SMAKE_C(0,1,0) ) {
      pos = MAKE_C(CX(pos), CY(pos)-1, CZ(pos) );
      while( environment(this_player())->get_tiletype(CX(pos)+2, CY(pos)+3) == '0' + LAYER_MOUNTAIN ) {
         pos = MAKE_C(CX(pos),CY(pos)+1,CZ(pos));
      }
   }
   // This is a north-facing version to snug the mine up as close as it can go.
   if( query_direction() == SMAKE_C(0,-1,0) ) {
      pos = MAKE_C(CX(pos), CY(pos)-1, CZ(pos) );
      while( environment(this_player())->get_tiletype(CX(pos)+2, CY(pos)) != '0' + LAYER_MOUNTAIN ) {
         pos = MAKE_C(CX(pos),CY(pos)+1,CZ(pos));
      }
   }
   set_coord( pos );

   return 0;
}

int query_site_layer() {
   return LAYER_OVERLAY;
}

mapping query_border() {
   if( !border )
   return border = SHAPE_OFFSET(query_shape(), query_direction() ) - query_shape();
   return border;
}

string *get_level_minerals( int level, string *minerals ) {
   string *buf = ({ minerals[level], minerals[level] });
   string gemstone;
   if( level > 0 )
      buf += ({ minerals[level-1] });
   if( level+1 < sizeof(minerals) )
      buf += ({ minerals[level+1] });
   gemstone = "/daemon/gemstone"->query_gem_name( minerals[level]->query_name() );
   if( gemstone && random(100) < 30 )
      buf += ({ "/econ/gem/"+gemstone });
   return sort_array(buf, #'>);
}

void generate_map( object mine_exit ) {
   string *reslist;
   int i, start_pos, end_pos, xdim, ydim;
   object start_room;

   if( environment() && environment(environment()) )
      reslist = environment(environment())->query_minerals();
   if( !reslist )
      reslist = ({ "/econ/raw/stone", "/econ/raw/copperore" });
   resize_grid( 9, 5, sizeof(reslist) );

   // random chance of smaller mine
   if( random(100) < 30 ) {
      i = random(sizeof(reslist));
      reslist = reslist[..i-1] + reslist[i+1..];
   } // random chance of slightly shuffled mine
   else if( random(100) < 30 ) {
      int k = i = random(sizeof(reslist));
      string tmp = reslist[k];
      while( i == k )
         i = random(sizeof(reslist));
      reslist[k] = reslist[i];
      reslist[i] = tmp;
   }

   // build the mine
   for( i = 0; i < sizeof(reslist); i++ ) {
      int ix, iy;
      object room, rocks;
      xdim = min( 9, i+3 );
      ydim = min( 5, i+3 );
      // Shape the floor
      for( iy = 0; iy < ydim; iy++ )
      for( ix = 0; ix < xdim; ix++ )
         set_cell(ix, iy, i, "mine"+i);
      // Make the room
      room = clone_object( "/world/room" );
      room->set_name( "mine" + i );
      room->set_short( "The " + capitalize(""+NUMBER_WORDS_MAP[-(i+1)]) + " Level of the Mine" );
      room->set_long( "The rocky passageways of this mine close in about you." );
      room->move(this_object());

      // Make the rocks
      rocks = clone_object( "/world/game/minerock" );
      rocks->move(room);
     // New minerock contents math - Al [Jul 10, '05]
     // rocks->set_mineral( reslist[i] );
      rocks->set_mineral( get_level_minerals(i, reslist) );
      ix = xdim * 5;
      iy = ydim * 3;
      rocks->make_level( min(ix / 2 + 12 * i, ix*iy-30), ix, iy );
      start_pos = rocks->query_start_pos();
      // Make exit leading up
      if( i == 0 ) {
         mine_exit->set_link( "mine0" );
         mine_exit->query_backlink()->set_coord( start_pos );
      }
      else {
         object exit_up;
         exit_up = clone_object("/world/exit/hole" );
         exit_up->move(room);
         exit_up->set_link("mine" + (i-1));
         exit_up->set_dir("up");
         exit_up->set_coord(start_pos);
         exit_up->query_backlink()->set_coord( end_pos );
      }
      // So that end_pos is the pos of the exit on the PREVIOUS floor...
      end_pos = rocks->query_end_pos();
   }
}

void on_build() {
   object start_room, door, bedroom;
   int ydoor;

   resize_grid(20, 20, 1);
   clear_grid();

   door = clone_object("/world/exit/door");
   door->set_host( this_object() );
   if( query_direction() == SMAKE_C(0,-1,0) ) ydoor = 0;
   else ydoor = 2;
   door->set_coord( MAKE_C( 2 + 2 * SCX(query_direction()), ydoor, 0) );
   door->set_dir( "mine" );
   door->move( environment() );
   generate_map(door);
}
