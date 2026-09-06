#include <const.h>

int main() {
   int ix, iy, i = 0, xdim, ydim;
   object ob;
   string map = "", key = "";

   xdim = environment( this_player() )->query_map_xdim();
   ydim = environment( this_player() )->query_map_ydim();

   // init map to full size
   for( iy = ydim; iy--; ) {
      for( ix = xdim; ix--; )
         map += " ";
      map += "\n";
   }

   // loop over room contents,
   foreach( ob : all_inventory(environment(this_player())) ) {
      if (ob->query_invis() && !(this_player()->query_level() > WIZLEVEL))
         continue;

      ix = ob->query_x();
      iy = ob->query_y();
      if ( ob->query_host() ) {
         ix += ob->query_host()->query_x();
         iy += ob->query_host()->query_y();
      }

      if ( ix == 0 && iy == 0 || ob == this_player())
         continue;

      key += sprintf("%c ", (i + 'A')) + ob->query_name() + "\n";

      map[ix + iy * xdim + iy] = i + 'A';

      i++;
   }

   // paint the player
   ix = this_player()->query_x();
   iy = this_player()->query_y();
   map[ix + iy * xdim + iy] = '@';

   // put the legend on the side, stolen from /bin/look
   ix = this_player()->query_term_width();
   ix -= xdim + 3;
   key = "  " + break_string(process_codes(key), ix, 2);
   key = "/inherit/textdraw"->splice_text( process_ansi(map), key, xdim );

   msg(key);

   return 1;
}
