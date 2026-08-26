inherit COMMAND_BASE;

class cond_info  {
   object cond_item;
   string cond_string;
   int    cond_percent;
}

int compare( float, float );

string cond_colour(int percent) {
   switch( 100 - percent ) {
   case 0..50 :
      return "";
   case 51..60 :
      return "%^CYAN%^";
   case 61..70 :
      return "%^GREEN%^";
   case 71..80 :
      return "%^YELLOW%^";
   case 81..90 :
      return "%^RED%^";
   case 91..100 :
      return "%^BOLD%^%^RED%^";
   }
} /* cond_colour() */

int cmd( object *things, int dir, int dam )  {
  int dark, i = 1;
  string list;
  object thing;
  class cond_info *info = ({ }), new_info;

  if( !TP->query_property("dead") )
      dark = TP->check_dark( ENV( TP )->query_light() );

  if( dark == 2 ) {
      add_failed_mess("It is way too bright to see anything at all.\n");
      return 0;
  }
  if( dark == -2 ) {
      add_failed_mess("It is way too dark to see anything at all.\n");
      return 0;
  }

  if( dam && !sizeof( things = filter( things, (: $1->cond_string() &&
      ( $1->query_cond() * 100 / $1->query_max_cond() ) < 91 :) ) ) ) {
      add_failed_mess("You have no damaged things.\n");
      return 0;
  }

  if( sizeof(things) == 1 ) {
      if( !list = things[0]->cond_string() ) {
          write("$C$"+things[0]->the_short()+" "+({"appears", "appear"})
              [query_group(things[0])]+" to have no condition.\n");
          return 1;
      }
      list = list[strsrch( list, " " )..];
      write( cond_colour( things[0]->query_cond() * 100 /
          things[0]->query_max_cond() ) + "$C$" + things[0]->the_short() +
          list + "%^RESET%^");
      return 1;
  }

  foreach( thing in things ) {
    list = thing->cond_string();
    if( list  &&  list != "" ) {
        list = list[strsrch( list, " " )..];
        info += ({ new( class cond_info,
                     cond_item   : thing,
                     cond_string : list,
                     cond_percent: ( thing->query_cond() * 100) /
                                     thing->query_max_cond() ) });
    }
  }
  if( !sizeof(info) )
      write("None of those things has a condition.\n");
  else if( sizeof(info) == 1 )
      write( cond_colour( info[0]->cond_percent ) + "$C$" +
          info[0]->cond_item->the_short()+info[0]->cond_string+"%^RESET%^");
  else {
    if( dir )  {
        info = sort_array( info, (: $(dir) * compare( $1->cond_percent,
                                                      $2->cond_percent) :) );
    }
    foreach( new_info in info ) {
      write( cond_colour( new_info->cond_percent ) + "$C$" +
             new_info->cond_item->the_short() + " (" + i + ")" +
             new_info->cond_string + "%^RESET%^");
      ++i;
    }
  }
  return 1;
} /* cmd() */

mixed *query_patterns()  {
   return ({ "<indirect:object'item(s)'> sorting {up|down}",
               (: cmd( $1, $4[1] == "up" ? 1 : -1, 0 ) :),
             "<indirect:object'item(s)'>", (: cmd( $1, 0, 0 ) :),
             "<indirect:object'item(s)'> damaged", (: cmd( $1, 0, 1 ) :),
             "<indirect:object'item(s)'> damaged sorting {up|down}",
               (: cmd( $1, $4[1] == "up" ? 1 : -1, 1 ) :),
          });
} /* query_patterns() */

int compare( float first, float second ) {
   if( first > second )
       return 1;
   if( first < second )
       return -1;
   return 0;
} /* compare() */
