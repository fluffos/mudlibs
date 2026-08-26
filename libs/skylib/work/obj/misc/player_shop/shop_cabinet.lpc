/**
 * @author Ringo
 * @started 1st August 1999
 */
#include <move_failures.h>
#define ITEM_COST "player_shop_item_cost"

inherit "/std/container";

private mapping _stock = ([]);

private nosave string _save_file = "";

private nosave int _call_save = 0;

void create()
{
   seteuid( (string)"/secure/master"->
      creator_file( file_name( this_object() ) ) );
   do_setup++;
   ::create();
   do_setup--;
   if ( !do_setup )
   {
      this_object()->setup();
      this_object()->reset();
   }
   this_object()->reset_get();
   TO->set_name("cabinet");
}
/* create() */


/** @ignore yes */
private void do_load()
{
   if ( _save_file )
   {
      if ( file_size( _save_file + ".o" ) > 0 )
      {
         unguarded( (: restore_object, _save_file :) );
         if ( sizeof( _stock ) )
         {
            init_dynamic_arg( _stock );
         }
      }
   }
}
/* do_load() */


/**
 * Set the filename that this cabinet should use to save its inventory to.
 * @param filename The file.
 */
void set_save_file( string filename )
{
   _save_file = filename;
   do_load();
}
/* set_save_file() */


/** @ignore yes */
void do_save()
{
   if ( _save_file && _save_file != "" )
   {
#ifdef DEBUG
      debug_printf( "Saving cabinet data to %s.\n", _save_file );
#endif
      _stock = query_dynamic_auto_load();
      unguarded( (: save_object, _save_file :) );
   }
}
/* do_save() */


/**
 * Used to remove items from the stock.
 * @param items The items to remove.
 * @param player The player removing the items.
 * @return An array of the objects that were dropped by the player.
 */
object *remove_items( object *items, object player )
{
   object item, *failed = ({});

   foreach( item in items )
   {
      if ( item->move( player ) != MOVE_OK )
      {
         failed += ({ item });
      }
   }
   if ( sizeof( failed ) )
   {
      failed->move( environment( player ) );
   }
   remove_call_out( _call_save );
   _call_save = call_out( "do_save", 1 );
   return failed;
}
/* remove_items() */


/**
 * Used to add items to the stock.
 * @param items The items to add.
 * @param player The player adding the items.
 * @return An array of objects that could not be added.
 */
object *add_items( object *items, object player, int cost )
{
   object item, *failed = ({});
   int av_cost;
   float tmp;
   tmp = to_float(cost);
   if(!sizeof(items)) return items;
   if(cost) {
     tmp /= sizeof(items);
     if(to_int(tmp) != cost / sizeof(items)) {
       av_cost = to_float(tmp + 1.0);
     }
     else {
       av_cost = to_float(tmp);
     }
   }
   foreach( item in items )
   {
      if ( item->move( this_object() ) != MOVE_OK )
      {
         failed += ({ item });
      }
      else if(av_cost) {
        item->add_property(ITEM_COST, av_cost);
      }
      else {
        item->add_property(ITEM_COST, item->query_value());
      }  
   }
   if ( sizeof( failed ) )
   {
      failed->move( player );
   }
   remove_call_out( _call_save );
   _call_save = call_out( "do_save", 1 );
   return failed;
}
/* add_items() */


/** @ignore yes */
void dest_me()
{
   remove_call_out( _call_save );
   do_save();
   ::dest_me();
}
/* dest_me() */
