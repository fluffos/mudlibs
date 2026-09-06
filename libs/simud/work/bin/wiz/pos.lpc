#include <wizard.h>
#include <const/shapeconst.h>

object ob;
int shape_mode;

int eval_pos( string s, int base ) {
   int offs;

   if( shape_mode ) base = 0;
   if( sscanf(s, "+%d", offs) == 1 )
      return offs + base;
   if( sscanf(s, "-%d", offs) == 1 )
      return base - offs;
   return base + to_int(s);
}

int main( string param ) {
   string obname, xs, ys, zs;
   int border_mode, landscape_mode, x, y, z;

   WIZ_CHECK

   if( !param ) {
      notify_fail("pos object [-s|-b|-l] [+/-]x [+/-]y [[+/-]z]\n");
      return 0;
   }

   shape_mode = border_mode = 0;
   if( sscanf(param, "%s -%s %s", xs, ys, zs) == 3 && !to_int(ys) ) {
      param = xs + " " + ys + " " + zs;
      if( member(ys, 's') > -1 ) shape_mode = 1;
      if( member(ys, 'b') > -1 ) shape_mode = border_mode = 1;
      if( member(ys, 'l') > -1 ) shape_mode = landscape_mode = 1;
   }
   if( sscanf(param, "%s %s %s %s", obname, xs, ys, zs) != 4 ) {
      zs = 0;
      if( sscanf(param, "%s %s %s", obname, xs, ys) != 3 ) {
         notify_fail("I have no clue what you're trying to do. Read the help file if anyone bothered to write one.\n");
         return 0;
      }
   }

   ob = find_thing( obname );
   if( !ob ) {
      notify_fail("Can't position "+obname+" because I don't know what it is.\n");
      return 0;
   }

   x = eval_pos( xs, this_player()->query_x() );
   y = eval_pos( ys, this_player()->query_y() );
   if( zs )
      z = eval_pos( zs, this_player()->query_z() );
   else
      z = ob->query_z();
   if( !function_exists("set_coord", ob) || shape_mode ) {
      if( border_mode )
         ob->set_border( SHAPE_OFFSET(ob->query_border(), SMAKE_C(x,y,z)) );
      else if( landscape_mode ) {
         ob->set_spots( SHAPE_OFFSET(ob->query_spots(), SMAKE_C(x,y,z)) );
         ob->set_deep_spots( SHAPE_OFFSET(ob->query_spots(), SMAKE_C(x,y,z)) );
      }
      else
         ob->set_shape( SHAPE_OFFSET(ob->query_shape(), SMAKE_C(x,y,z)) );
   }
   else {
      ob->set_coord( MAKE_C(x, y, z) );
   }

   msg("Position set.");
   return 1;
}