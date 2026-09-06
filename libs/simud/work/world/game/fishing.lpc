#include <object.h>

string query_name() {
   return "Fishinggame";
}

object id( string s ) {
   if( s == query_name() ) return this_object(); return 0;
}

void showpond();

int xfish, yfish, cast_count;
int *casts = ({ });

void showhelp() {
   msg(
"~CTITFishing\n" +
"~CDEF-------\n" +
"~CCOMcast A1~CDEF -- Casts at angle A, strength 1.\n" +
"~CCOMlook~CDEF -- Look at the fishing field.\n" +
"~CCOMstop~CDEF -- Stop fishing.\n" +
"~CCOM!command~CDEF -- Do something outside the game (!chat, !say, etc.)");
}

void init() {
   showhelp();
   showpond();
   add_interface( "dofish", "[Fishing] " );
   xfish = random(21);
   yfish = random(10);
}

void dofish( string s ) {
   string comm, param;

   if( s == "" || s == 0 ) return;
   sscanf( s, "%s %s", comm, param);
   if( !comm ) comm = s;
   if( comm == "look" || comm == "l" ) {
      showpond();
      return;
   }
   if( comm == "cast" ) {
      int x, y;

      if( !param || strlen(param = lower_case(param)) != 2 || param[0] < 'a' ||
         param[0] > 'u' || param[1] < '0' || param[1] > '9' ) {
         msg("When you cast, you have to do it in this format:\n"
         "   ~CCOMcast A#~CDEF -- where A is any letter A-U, and # is any number 0-9");
         return;
      }
      this_player()->msg_local("~CACT~Name ~verbcast ~poss line out into the water.~CDEF");
      x = param[0] - 'a';
      y = 9 - (param[1] - '0');
      if( x == xfish && y == yfish ) {
         msg("Congratulations! You caught a fish! The captain of the boat buys it from you for a coin.");
         clone_object("/obj/coins")->move(this_player());
         drop_interface();
         destruct(this_object());
         return;
      }
      cast_count++;
      if( cast_count >= 4 ) {
         msg( "Oh no! The fish nibbles the bait off your line... and then gets away." );
         drop_interface();
         destruct(this_object());
         return;
      }
      if( x < xfish )
         msg( "The fish is further to the right." );
      if( x > xfish )
         msg( "The fish is further to the left." );
      if( y > yfish )
         msg( "You didn't cast the line far enough." );
      if( y < yfish )
         msg( "You cast the line too far." );
      casts += ({ MAKE_C(x,y,0) });
      return;
   }
   else if( comm == "help" ) {
      showhelp();
   }
   else if( comm == "stop" ) {
      msg( "You stop fishing." );
      drop_interface();
      destruct(this_object());
      return;
   }
   else {
      msg("Sorry, I didn't get that. Use ~CCOM!command~CDEF to do something outside the game, or ~CCOMstop~CDEF to quit");
      return;
   }
}

void showpond() {
   int i, j;
   string str = "";
   msg("~CBRT  A B C D E F G H I J K L M N O P Q R S T U");
   for( i = 0; i < 5; i++ ) {
      string evenline, oddline;
      int pos;

      evenline = tab( "Oo", 21 );
      oddline = tab( "oO", 21 );
      foreach( pos : casts )
      if( CY(pos) / 2 == i ) {
         if( CY(pos)%2 )
            oddline[CX(pos)*2..CX(pos)*2+1] = "_";
         else
            evenline[CX(pos)*2..CX(pos)*2+1] = "_";
      }
      evenline = implode( explode(evenline, "_"), "~[090><~[124" );
      oddline = implode( explode(oddline, "_"), "~[090><~[124" );

      msg_bare("~CBRT" + (9-i*2) + " ~[124" + evenline + "~CDEF\n");
      msg_bare("~CBRT" + (8-i*2) + " ~[124" + oddline + "~CDEF\n");
   }
   msg( "  ~[030------------------- ~CBRT@~[030 --------------------~CDEF");
}
