/**
 * @author Ringo
 * @started 20th September 1999
 */
#include <player_shop.h>

inherit "/std/object";

private nosave string _office;

void setup()
{
   set_name( "chart" );
   set_short( "items chart" );
   add_adjective( "items" );
   set_long( "This chart lists the items of interest to the shop.\n" );
   add_extra_look( this_object() );
   reset_get();
}
/* setup() */

/**
 * @ignore yes
 * Where to get the data from?
 */
void set_office( string office ) { _office = office; }


/**
 * @ignore yes
 * Chart display
 */
string extra_look( object thing )
{
   int i;
   string chart, *items;
   mapping list;

   if ( thing == this_object() )
   {
      list = _office->query_list_mapping();
      if ( !m_sizeof( list ) )
      {
         return "There are no items on the list.\n";
      }
      chart = "\n";
      chart += sprintf( "%-2s  %-25s  %-3s  %-5s  %-4s  %-4s  %-3s  %-4s  %-8s\n",
        "no", "items", "max", "stock", "avst", "avsl", "buy", "sell", "cabinets" );
      chart += sprintf( "%-2s  %-25s  %-3s  %-5s  %-4s  %-4s  %-3s  %-4s  %-8s\n",
        "--", "-----", "---", "-----", "----", "----", "---", "----", "--------" );
      items = m_indices( list );
      for ( i = 0; i < sizeof( items ); i++ )
      {
         /* This can be a long loop if there is a lot of stock,
          * and we don't want 'too long eval' errors popping up...
          */
         reset_eval_cost();

         chart += sprintf( "%2d  %-25s  %3d  %5d  %4d  %4d  %3d  %4d  %8s\n",
           i + 1, items[i], list[items[i]][CHART_MAX],
           _office->query_stock( items[i] ), list[items[i]][CHART_AVE],
           list[items[i]][CHART_AVESALE], list[items[i]][CHART_BUY],
           list[items[i]][CHART_SELL],
           implode( list[items[i]][CHART_CAB], (: $1+","+$2 :), "" )[1..] );
           // imploding *int - need to convert to *string
      }
      return chart;
   }
}
/* extra_look() */
