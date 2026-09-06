#include <const.h>

// Verb for picking up objects.

int distance(object obj) {
  float dx = this_player()->query_x() - obj->query_x();
  float dy = this_player()->query_y() - obj->query_y();
  int d = (int)(sqrt( pow(dx,2) + pow(dy,2) ));

  debug("distance to "+(string)obj+" = "+(string)d);

  return d;
}

int main( string str ) {
   object env, *list;
   string a, b;
   int i;

   if( !str ) {
      notify_fail("Get what?\n");
      return 0;
   }

   env = environment(this_player());
   if( sscanf(str, "%s from %s", a, b) ) {
      list = all_present( b, env );
      if( !list ) list = all_present( b );
      if( !list ) {
         notify_fail("I don't know what you mean by '"+b+"'.\n");
         return 0;
      }
      env = list[0];

      list = all_present( a, env );
   }
   else {
      list = all_present( str, env );
      if( !list ) {
         if( env->extra_id(str) ) {
            notify_fail("You can't get that!\n");
            return 0;
         }
         notify_fail("I don't know what you mean by '"+str+"'.\n");
         return 0;
      }
   }


   for( i = 0; i < sizeof(list); i++ ) {
      int flag;

      flag = list[i]->on_get( this_player() );

      if( !valid_manipulate(this_player(), list[i]) )
         flag = 0;
      if( !(flag & MOVE_OK_FLAG) || (flag & MOVE_SILENCE_FLAG) ) {
         list = list[..i-1] + list[i+1..];
         i--;
      }
   }

   if( !sizeof(list) ) {
      notify_fail("You can't get that!\n");
      return 0;
   }
   else {
      int flag = 1, closest = -1;
      mapping dist_list = ([]);
      object item, *other_list = ({});

      // trim list to contain only the closest items
      if (sizeof(list) > 1) {
         foreach ( item : list )
            dist_list += ([item: distance(item)]);

         // remove items that are too far
         while (flag) {
            flag = 0;
            foreach ( item : m_indices(dist_list) ) {
               if (closest == -1 || dist_list[item] < closest) {
                  closest = dist_list[item];
                  flag = 1;
               } else if (closest < dist_list[item]) {
                  dist_list -= ([item]);
                  other_list += ({item});
               }
            }
         }

         list = ({});
         foreach ( item : dist_list )
            list += ({item});

         // walk to closest item
         if (closest > 1)
            "/bin/walk"->main("to "+(string)list[0]);

         // grab everything next to you that's on the list
         for( int i = 0; i < sizeof(list); i++ ) {
            if (this_player()->query_adjacent(list[i]))
              list[i]->move( this_player() );
            else {
              other_list += ({ list[i] });
              list = list[..i-1] + list[i+1..];
              i--;
            }
         }

         // report any items that were too far
         if (sizeof(other_list) == 1)
            msg(capitalize(inventory_string(other_list))+" is too far.");
         else if (sizeof(other_list) > 1)
            msg(capitalize(inventory_string(other_list))+" are too far.");
      } else {
         if (distance(list[0]) > 1)
            "/bin/walk"->main("to "+(string)list[0]);
         if (this_player()->query_adjacent(list[0]))
            list[0]->move( this_player() );
         else
            list = ({});
      }

      if (sizeof(list))
        this_player()->msg_local("~CACT~Name ~verbget " + inventory_string(list) + ".~CDEF");
      else
        msg("You didn't get anything.");
   }

   return 1;
}
