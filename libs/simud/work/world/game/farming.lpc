#include "textdraw.h"

int *weeds;
string crop_type;
int seeds_left;
int *crop_strength;
int *water;
int field_width, field_height;
int daynum, turns_left;

int query_field_width() {
   return field_width;
}

int query_field_height() {
   return field_height;
}

int * query_weeds() {
   return weeds;
}

#define FIELD_WIDTH (query_field_width())
#define FIELD_HEIGHT (query_field_height())
#define FIELD_SIZE ((FIELD_WIDTH) * (FIELD_HEIGHT))
#define CENTER_WIDTH 23
#define TO_POS(x,y,s) { x = lower_case(s[0..0])[0] - 'a'; y = s[1..1][0] - '1'; }

void field_alloc() {
   if( FIELD_SIZE == 0 ) return;
   weeds = allocate( FIELD_SIZE * 4 );
   crop_strength = allocate( FIELD_SIZE );
   water = allocate( FIELD_SIZE );
}

void set_field_width( int x ) {
   field_width = x;
   field_alloc();
}

void set_field_height( int x ) {
   field_height = x;
   field_alloc();
}

void set_seeds( int x ) {
   seeds_left = x;
}

void add_seeds( int x ) {
   set_seeds( seeds_left + x );
}

void _create_farming() {
   set_field_width( 5 );
   set_field_height( 3 );
}

string get_weed_char( int val ) {
   switch( val ) {
      case 0: return " ";
      case 1: return "~[030'~CDEF";
      case 2: return "~[030\"~CDEF";
      default: return "~[090?~CDEF";
   }
   return 0;
}

string get_crop_char( int val ) {
   switch( val ) {
      case -1: return "~[030xxx~CDEF";
      case 0: return "   ";
      case 1..10: return "~[100*  ~CDEF";
      case 11..19: return "~[100** ~CDEF";
      case 20: return "~[100***~CDEF";
      default: return "~[090???~CDEF";
   }
   return 0;
}

string get_water_char( int val ) {
   switch( val ) {
      case 0: return "   ";
      case 1: return "~[120~TILD  ~CDEF";
      case 2: return "~[120~TILD~TILD ~CDEF";
      case 3: return "~[120~TILD~TILD~TILD~CDEF";
      default: return "~[090???~CDEF";
   }
   return 0;
}

void setup_weeds( int strength ) {
   int i;

   if( !strength ) strength = 20;

   for( i = 0; i < strength; i++ )
      weeds[random(FIELD_SIZE*4)] = random(2) + 1;

   for( i = 0; i < FIELD_SIZE; i++ ) {
      crop_strength[i] = -1;
      water[i] = 1 + random(3);
   }
   daynum = "/daemon/time"->query_day_num();
   turns_left = 3;
}

void set_daynum( int x ) {
   daynum = x;
}

int query_daynum() {
   return daynum;
}

void set_crop_type( string str ) {
   crop_type = str;
}

string query_crop_type() {
   return crop_type;
}

string query_crop_name() {
   if( !crop_type ) return "*invalid crop*";
   return crop_type->query_name();
}

string query_center_bar() {
   string buf, blank;

   blank = tab(" ", CENTER_WIDTH) + "\n";
   buf = pad("/daemon/time"->query_elven_month(daynum) + " " +
      "/daemon/time"->query_elven_day_of_month(daynum), CENTER_WIDTH, JUST_CENTER) + "\n" +
      pad("   Crop: " + capitalize(query_crop_name()), CENTER_WIDTH, JUST_LEFT) + "\n" +
      pad("   Progress: N/A", CENTER_WIDTH, JUST_LEFT) + "\n" +
      pad("   Turns: " + turns_left, CENTER_WIDTH, JUST_LEFT) + "\n" +
      pad("   Seeds: " + seeds_left, CENTER_WIDTH, JUST_LEFT) + "\n" +
      pad("   Days:  " + ("/daemon/time"->query_day_num() - daynum), CENTER_WIDTH, JUST_LEFT) + "\n" +
      tab(blank, FIELD_HEIGHT * 3 - 1);

   return buf;
}

string query_crop_field() {
   int i, j;
   string buf, tmp;

   if( sizeof(weeds) != FIELD_SIZE * 4 ) raise_error( "weeds array invalid" );
   buf = "  ";
   tmp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   // Print lettered labels across the top
   for( i = 0; i < FIELD_WIDTH; i++ ) {
      buf += "  " + tmp[i..i] + " ";
   }

   buf += "\n";

   for( j = 0; j < FIELD_HEIGHT; j++ ) {
      int rowoffs = j * FIELD_WIDTH;
      buf += "  " + tab("+---", FIELD_WIDTH) + "+\n  ";

      for( i = 0; i < FIELD_WIDTH; i++ )
         buf += "|" + get_crop_char(crop_strength[rowoffs + i]);
      buf += "|" + pad( "" + (j + 1), 2, JUST_RIGHT ) + "\n  ";

      for( i = 0; i < FIELD_WIDTH; i++ )
         buf += "|" + get_water_char(water[rowoffs + i]);
      buf += "|\n";
   }
   buf += "  " + tab("+---", FIELD_WIDTH) + "+\n";
   return buf;
}

string query_weed_field() {
   int i, j;
   string buf, tmp;

   if( sizeof(weeds) != FIELD_SIZE * 4 ) raise_error( "weeds array invalid" );
   buf = "  ";
   tmp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   // Print lettered labels across the top
   for( i = 0; i < FIELD_WIDTH; i++ ) {
      buf += " " + tmp[i*2..i*2] + " " + tmp[i*2+1..i*2+1];
   }

   buf += " \n";

   for( j = 0; j < FIELD_HEIGHT; j++ ) {
      int rowoffs = j * 4 * FIELD_WIDTH;
      buf += "  " + tab("+---", FIELD_WIDTH) + "+\n";

      buf += pad( (j*2+1), 2, JUST_RIGHT );
      for( i = 0; i < FIELD_WIDTH; i++ )
         buf += "|" +
            get_weed_char(weeds[rowoffs + i*2]) +
            " " +
            get_weed_char(weeds[rowoffs + i*2+1]);

      buf += "|\n" + pad( (j*2+2), 2, JUST_RIGHT );

      rowoffs += 2 * FIELD_WIDTH;
      for( i = 0; i < FIELD_WIDTH; i++ )
         buf += "|" +
            get_weed_char(weeds[rowoffs + i*2]) +
            " " +
            get_weed_char(weeds[rowoffs + i*2+1]);
      buf += "|\n";
   }
   buf += "  " + tab("+---", FIELD_WIDTH) + "+\n";
   return buf;
}

string get_field_string() {
   if( this_player()->query_term_width() > FIELD_WIDTH * 8 + 30 )
      return splice_text(splice_text(query_weed_field(), query_center_bar()), query_crop_field());
   else
      return splice_text(query_weed_field(), query_center_bar()) + "\n" + query_crop_field();
}

void show_field() {
   msg( get_field_string() );
}

int *get_neighbors( int x, int y ) {
   int ix, iy;
   int *ret = ({ });

   for( ix = x - 1; ix <= x + 1; ix++ )
   for( iy = y - 1; iy <= y + 1; iy++ ) {
      if( ix == x && iy == y ) continue;
      if( ix < 0 || iy < 0 ||
         ix >= FIELD_WIDTH * 2 ||
         iy >= FIELD_HEIGHT * 2 ) {
         ret += ({ 0 });
         continue;
      }
      ret += ({ weeds[ix + iy * FIELD_WIDTH * 2] });
   }
   return ret;
}

int get_water_average( int x, int y ) {
   int ix, iy;
   int sum = 0, tot = 0;

   for( ix = x - 1; ix <= x + 1; ix++ )
   for( iy = y - 1; iy <= y + 1; iy++ ) {
      if( ix < 0 || iy < 0 ||
         ix >= FIELD_WIDTH ||
         iy >= FIELD_HEIGHT )
         continue;
      sum += water[ix + iy * FIELD_WIDTH];
      tot++;
   }
   if( tot == 0 ) return 0;
   return (sum + random(tot/2)) / tot;
}

int calc_weed( int self, int *neighbors, int water ) {
// * If an empty square has two or more choked neighbors, and there is >= 1 water,
// it'll change to a few.
   if( self == 0 && water >= 2 && sizeof(neighbors - ({ 2 })) <= 6 )
      return 1;
// * If a few square has three or more neighbors, and it has 1 or more
// water, it will change to choked.
   if( self == 1 && water >= 2 && sizeof(neighbors - ({ 1, 2 })) <= 5 )
      return 2;
// * If a few square has under 3 - water neighbors, it will change to empty.
   if( self == 1 && sizeof(neighbors - ({ 0 })) < 3 - water )
      return 0;
// * If a choked square has under 3 - water neighbors, it becomes a few.
   if( self == 2 && sizeof(neighbors - ({ 0 })) < 3 - water )
      return 1;
   return self;
}

void cweed( int x, int y ) {
   mixed res, self, neighbors, iwater;
   self = weeds[x + y * FIELD_WIDTH * 2];
   neighbors = get_neighbors(x,y);
   iwater = water[(y/2) * FIELD_WIDTH + (x/2)];
   res = calc_weed( self, neighbors, iwater );
   msg( as_string(self) + ", " + implode(explode(as_string(neighbors),"\n")," ") + ", " +
      as_string(iwater) + " -> " + as_string(res) );
}

void weed_growth() {
   int *new_weeds, ix, iy;

   // bad programmer using fixed constants instead of
   // macros... fixed btw
   // - gp
   new_weeds = allocate( FIELD_HEIGHT * FIELD_WIDTH * 4 );
   for( iy = 0; iy < FIELD_HEIGHT * 2; iy++ )
   for( ix = 0; ix < FIELD_WIDTH * 2; ix++ ) {
      new_weeds[ix + iy * FIELD_WIDTH * 2] =
         calc_weed( weeds[ix + iy * FIELD_WIDTH * 2],
            get_neighbors(ix,iy), water[(iy/2) * FIELD_WIDTH + (ix/2)] );
      // weeds that don't have to fight for space with crops
      // can sprout spontaneously
      if( crop_strength[ix/2+(iy/2)*FIELD_WIDTH] <= 0 &&
         new_weeds[ix + iy * FIELD_WIDTH * 2] < 2 && random(10) == 0 )
         new_weeds[ix + iy * FIELD_WIDTH * 2]++;
   }
   weeds = new_weeds;
}

void enter_farming() {
   add_interface( "do_farming", "[Farm | ? for help] " );
}

void add_water( int x, int y, int amt ) {
   if( x < 0 || x >= FIELD_WIDTH || y < 0 || y >= FIELD_HEIGHT ) return;
   if( amt <= 0 ) return;
   water[x+y*FIELD_WIDTH] = 3;
   add_water( x-1, y, amt - 1);
   add_water( x, y-1, amt - 1);
   add_water( x+1, y, amt - 1);
   add_water( x, y+1, amt - 1);
   add_water( x-1, y-1, amt - 1);
   add_water( x-1, y+1, amt - 1);
   add_water( x+1, y-1, amt - 1);
   add_water( x+1, y+1, amt - 1);
}

// Water averages out over time
void disperse_water() {
   int ix, iy;
   int *new_water = allocate( FIELD_WIDTH * FIELD_HEIGHT );

   for( iy = 0; iy < FIELD_HEIGHT; iy++ )
   for( ix = 0; ix < FIELD_WIDTH; ix++ )
      new_water[ix+iy*FIELD_WIDTH] = get_water_average(ix,iy);
   ix = random(FIELD_WIDTH*FIELD_HEIGHT);
   new_water[ix] = max( new_water[ix] - 1, 0 );
   water = new_water;
}

int get_weed_total( int x, int y ) {
   return
      weeds[x*2+y*4*FIELD_WIDTH] +
      weeds[1+x*2+y*4*FIELD_WIDTH] +
      weeds[x*2+(y*2+1)*2*FIELD_WIDTH] +
      weeds[1+x*2+(y*2+1)*2*FIELD_WIDTH];
}

// Make the crops progress or regress
void grow_crops() {
   int ix, iy;
   int *new_crop_strength = copy( crop_strength );

   for( iy = 0; iy < FIELD_HEIGHT; iy++ )
   for( ix = 0; ix < FIELD_WIDTH; ix++ ) {
      int i = ix + iy * FIELD_WIDTH;
      int w = water[i], curr_weed = get_weed_total(ix,iy);

      // Don't affect crops waiting for harvest.
      if( new_crop_strength[i] == 20 ) continue;
      // Fully choked squares die immediately
      if( curr_weed == 8 ) {
         new_crop_strength[i] = -1;
         continue;
      }
      // Don't grow unplanted crops.
      if( new_crop_strength[i] <= 0 ) continue;
      // For weed amounts 3..7, crops won't grow, or will die off faster.
      if( curr_weed > 2 )
         new_crop_strength[i]--;
      switch( w ) {
         default: case 0: new_crop_strength[i] -= 2; break;
         case 1: new_crop_strength[i] -= random(2); break;
         case 2: new_crop_strength[i] += random(2); break;
         case 3: new_crop_strength[i]++; break;
      }
      if( new_crop_strength[i] <= 0 ) new_crop_strength[i] = -1;
      if( new_crop_strength[i] >= 20 ) new_crop_strength[i] = 20;
   }
   crop_strength = new_crop_strength;
}

void do_harvest( int x, int y ) {
   int coord = x + y * FIELD_WIDTH;
   if (crop_strength[coord] == 20) {
      object obj = clone_object(query_crop_type());
      // Al attempted to randomly set the amount based on water and weeds,
      // but:
      // a) This doesn't make sense. Water and weeds have already taken their
      // toll; if they hadn't been taken care of earlier, the crop wouldn't
      // have grown.
      // b) His coord math was screwed up. Weeds don't use the same coord
      // system.
      // So I hacked it quickly... Also, the amount of crops he was handing
      // out was HUGE, I toned that down a tiny bit (it's still generous
      // though).
      obj->set_quantity(7 + random(9));
      set_target(obj);
      set_actor(this_player());
      this_player()->msg_local("~CACT~Name ~verbharvest ~targ.~CDEF");
      obj->move( this_player() );
      crop_strength[coord] = -1;
   } else if (crop_strength[coord] > 0) {
      msg("You cannot harvest that square yet.");
   } else {
      msg("There isn't even a crop planted in that square.");
   }
}

void pull_weeds( int x, int y ) {
   weeds[ x + y * FIELD_WIDTH * 2 ] = 0;
}

int turns()
{
   int sk;

   sk = this_player()->skill_check("craft.farming", 20, 50, 80);

   debug("Farming check: " + sk, "gp");
   return 3 + sk;
}

void do_farming( string s ) {
   string pos;
   int amt;

   if( s == "q" || s == "quit" || s == "x" || s == "exit" ) {
      drop_interface();
     command("look",this_player());
      return;
   }

   if( s == "l" || s == "look" || !s ) {
      show_field();
      return;
   }

   if( s == "?" || s == "help" ) {
      msg( "Farming commands:\n" +
           "  ~CBRTa~CDEFdd - add a seed to the field's supply\n" +
           "  ~CBRTa~CDEFdd X# - add more than one seed at a time\n" +
           "  ~CBRTc~CDEFlear X# - clear the ground at X#\n" +
           "  e~CBRTx~CDEFit - quit farming\n" +
           "  ~CBRTh~CDEFarvest X# - harvest crops from X#\n" +
           "  ~CBRTl~CDEFook - examine the field\n" +
           "  ~CBRTp~CDEFlant X# - plant seeds at X#\n" +
           "  ~CBRTq~CDEFuit - stop farming for now\n" +
           "  ~CBRTn~CDEFext - skip to next day, discarding unused turns.\n" +
           "  ~CBRT10~CDEF days - skip ahead 10 days, discarding unused turns.\n" +
           "  ~CBRTw~CDEFater X# - water at X#\n" +
           "  wee~CBRTd~CDEF X# - weed eliminate weeds at X#\n" +
           "  ~CBRTplough~CDEF - reset the field, discard all unused days" );
      return;
   }

   if( s == "plough" ) {
      setup_weeds( 20 );
      msg( "You plough the field." );
      return;
   }

   if( s == "a" || s == "add" || s == "add seed" ||
      sscanf(s, "a %d", amt) == 1 || sscanf(s, "add %d", amt) == 1 ||
      sscanf(s, "add %d seeds", amt) == 1 ) {
      // Fun fact: This is one of the few cases in which present() will be
      // more correct than single_present. Since the text sought for is
      // program generated, not user generated, present() will do the simpler,
      // dumber algorithm and still return correct results. It's faster.
      // single_present() would also work fine here, but it's using a bazooka
      // to peg a squirrel.
      object obj = present( query_crop_name() + " seed", this_player() );
      if (!obj || !obj->query_has_aspect( C_SEED )) {
         msg("You don't seem to be carrying any viable "+query_crop_name()+" seeds to add to this field.");
         return;
      } else {
         // Acius: Argh! Bad lazy programmer, no cookie! You can't use turns_left to determine
         // whether the turns are used up, since you can have 0 turns but still be fifty DAYS
         // behind! Also, there's no reason to restrict adding seeds if you have 2 turns left
         // but are on the current day... Anyway, this code ought to be correct now.
         if ( daynum < "/daemon/time"->query_day_num() ) {
            msg("Sorry, but you must use up your accumulated turns before you are allowed to add any new seeds.");
            return;
         }
         if( !amt )
            amt = 1;
         if( amt > obj->query_quantity() ) {
            amt = obj->query_quantity();
            msg("You only have "+amt+" "+query_crop_name()+" seeds on hand right now.");
         }
         if (obj->query_quantity() > amt)
            obj->add_quantity(-amt);
         else
            destruct(obj);
         msg("You add "+(amt>1?amt+" seeds":"a seed")+" to the field.");
         add_seeds( amt );
         return;
      }
      show_field();
   }

   if( sscanf(s, "h %s", pos) == 1 || sscanf(s, "harvest %s", pos) == 1 ) {
      int x, y, coord;
      if( strlen(pos) != 2 ) {
         msg( "Positions must be of the format A2 or C3 or similar" );
         return;
      }
      TO_POS( x, y, pos );
      if( x < 0 || y < 0 || x >= FIELD_WIDTH || y >= FIELD_HEIGHT ) {
         msg("Not a valid position. Please check the fields chart on the right for valid positions");
         return;
      }
      do_harvest( x, y );
      show_field();
      return;
   }

   if( s == "n" || s == "next" || turns_left <= 0 ) {
      if( daynum >= "/daemon/time"->query_day_num() ) {
         msg( "The current date is " + "/daemon/time"->query_date() + "." );
         msg( "You won't be able to take any more turns until tomorrow." );
         msg( "Type 'q' to quit." );
         return;
      }
      if ( this_player()->query_readiness() < 500 ) {
         msg( "You're out of breath!" );
         return;
      }
      msg( "Moving forward a day." );
      this_player()->add_readiness(-200);
      weed_growth();
      grow_crops();
      disperse_water();
      daynum++;
      turns_left = turns();
      if( s == "n" || s == "next" ) {
         show_field();
         return;
      }
   }

   if( s == "10" || s == "10 days" ) {
      int i;
      for( i = 0; i < 10; ++i ) {
         if( daynum >= "/daemon/time"->query_day_num() ) {
            msg( "The current date is " + "/daemon/time"->query_date() + "." );
            msg( "You won't be able to take any more turns until tomorrow." );
            msg( "Type 'q' to quit." );
            return;
         }
         if (this_player()->query_readiness() < 500) {
            msg( "You're out of breath!" );
            return;
         }
         msg( "Moving forward a day." );
         this_player()->add_readiness(-200);
         weed_growth();
         grow_crops();
         disperse_water();
         daynum++;
         turns_left = turns();
      }
      show_field();
      return;
   }

   if( sscanf(s, "w %s", pos) == 1 || sscanf(s, "water %s", pos) == 1 ) {
      int x, y;
      if( strlen(pos) != 2 ) {
         msg( "Positions must be of the format A2 or C3 or similar" );
         return;
      }
      TO_POS( x, y, pos );
      if( x < 0 || y < 0 || x >= FIELD_WIDTH || y >= FIELD_HEIGHT ) {
         msg("Not a valid position. Please check the fields chart on the right for valid positions");
         return;
      }
      add_water( x, y, 2 );
      msg( "You water " + upper_case(pos) );
      turns_left--;
      show_field();
      return;
   }

   if( sscanf(s, "d %s", pos) == 1 || sscanf(s, "weed %s", pos) == 1 ) {
      int x, y;
      if( strlen(pos) != 2 ) {
         msg( "Positions must be of the format A2 or C3 or similar" );
         return;
      }
      TO_POS( x, y, pos );
      if( x < 0 || y < 0 || x >= FIELD_WIDTH*2 || y >= FIELD_HEIGHT*2 ) {
         msg("Not a valid position. Please check the fields chart on the left for valid positions");
         return;
      }
      pull_weeds( x, y );
      msg( "You weed " + upper_case(pos) );
      turns_left--;
      show_field();
      return;
   }

   if( sscanf(s, "c %s", pos) == 1 || sscanf(s, "clear %s", pos) == 1 ) {
      int x, y;
      if( strlen(pos) != 2 ) {
         msg( "Positions must be of the format A2 or C3 or similar" );
         return;
      }
      TO_POS( x, y, pos );
      if( x < 0 || y < 0 || x >= FIELD_WIDTH || y >= FIELD_HEIGHT ) {
         msg("Not a valid position. Please check the fields chart on the right for valid positions");
         return;
      }
      crop_strength[x+y*FIELD_WIDTH] = 0;
      msg( "You clear " + upper_case(pos) );
      turns_left--;
      show_field();
      return;
   }

   if( sscanf(s, "p %s", pos) == 1 || sscanf(s, "plant %s", pos) == 1 ) {
      int x, y;
      if( strlen(pos) != 2 ) {
         msg( "Positions must be of the format A2 or C3 or similar" );
         return;
      }
      TO_POS( x, y, pos );
      if( x < 0 || y < 0 || x >= FIELD_WIDTH || y >= FIELD_HEIGHT ) {
         msg("Not a valid position. Please check the fields chart on the right for valid positions");
         return;
      }
      if( seeds_left < 1 ) {
         msg("There are no seeds left for this field, you need to add some if you want to plant any more.");
         return;
      }
      if( crop_strength[x+y*FIELD_WIDTH] != 0 ) {
         msg("You may only sow on cleared ground.");
         return;
      }
      crop_strength[x+y*FIELD_WIDTH] = 1;
      msg( "You sow a seed at " + upper_case(pos) );
      turns_left--;
      seeds_left--;
      show_field();
      return;
   }
}
