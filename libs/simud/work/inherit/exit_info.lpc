/** The information, generally stored in the area object, which
 * holds exit information. Stores all the exit connecting
 * objects within this area.
 */

/** An array of this form:
 * ({ ([ ... ]), ([ ... ]), ... })
 * Basically, each mapping in the array represents an exit. Exits are then referenced by number.
 * room knows which exits belong to it because they are given in room_exits.
 */
mapping *exits = ({ });
/** A mapping of arrays of ints:
 * ([ "room1": ({ 7, 12, ... }), "room2": ({ 3, 6, ... }), ... ])
 * Each room has an associated array of ints. They are indices into the exits mapping.
 */
mapping room_exits = ([ ]);

// Function prototype
mixed get_exit_index( object ob );
void update_room_exits();

/** \return The mapping for a single exit. It will return
 * 0 if the exit does not exist.
 *
 * \note If the \a exit parameter is an integer, it is
 * the index of the exit. Bounds checking is done. If
 * it is a string, then it is assumed to be a recursive
 * exit reference. If the reference is valid, the exit
 * is returned, otherwise 0 is.
 */
mapping query_exit( mixed exit ) {
   mixed exit_index;

//   msg("query_exit("+as_lpc(exit)+") called in "+object_name(this_object()));
   if( stringp(exit) ) {
      if( exit[0] == '<' ) {
         object env;
         env = this_object();
         while( exit[0] == '<' && environment(env) ) {
            env = environment(env);
            exit = exit[1..];
         }
         return env->query_exit( exit );
      }
      else {
         exit_index = to_int(exit) ;
         if( query_to_int_fail() )
            return 0;
         else {
            if( exit_index < sizeof(exits) )
               return exits[exit_index];
            else
               return 0;
         }
      }

   }
   if( exit < 0 || exit >= sizeof(exits) )
      return 0;
   return exits[exit];
}

/** \retun The handle for the exit in \a room whose link is given
 * by \a link. I have to use link, since not all exits necessarily
 * have associated directions.
 */
mixed query_exit_handle( string room, string link ) {
   mixed i;

   if( !pointerp(room_exits[room]) ) return -1;
   foreach( i : room_exits[room] ) {
      if( query_exit(i)["link"] == link ) return i;
   }
   return -1;
}

/** \return the value of the variable \a var in the exit given by the handle \a exit.
 */
mixed query_exit_var( mixed exit, string var ) {
   mixed val;

   val = query_exit( exit );
   if( !val ) return 0;
   return val[var];
}

/** Sets one of the variables associated with an exit. The only variable that is
 * guaranteed useful for all types of exits is "handler" -- this is the object
 * in /world/exits that is used for managing exit behavior. The handle can be
 * an integer or a string (use the returned value when you created the exit).
 * \return True on success, false on failure.
 */
int set_exit_var( mixed exit, string var, mixed val ) {
   if( stringp(exit) ) {
      if( exit[0] == '<' && environment() ) {
         object env;
         env = this_object();
         while( exit[0] == '<' && environment(env) ) {
            env = environment(env);
            exit = exit[1..];
         }
         return env->set_exit_var( exit, var, val );
      }
      else {
         exit = to_int(exit);
         if( query_to_int_fail() )
            return 0;
      }
   }
   if( exit < 0 || exit >= sizeof(exits) ) return 0;
   if( val != 0 )
      exits[exit][var] = val;
   else
      m_delete( exits[exit], var );
   return 1;
}

/** Delete an exit variable; used to invert the set_exit_var call.
 */
int remove_exit_var( mixed exit, string var ) {
   if( stringp(exit) ) {
      if( exit[0] == '<' && environment(this_object()) )
         return environment(this_object())->remove_exit_var( exit[1..], var );
      else {
         exit = to_int(exit);
         if( query_to_int_fail() )
            return 0;
      }
   }
   if( exit < 0 || exit >= sizeof(exits) ) return 0;
   m_delete( exits[exit], var );
   return 1;
}

/** Adds an exit connecting room1 to room2. The exit's "handle" is returned.
 * Note that the exit handle may be either an integer or a string, so be
 * flexible. Note that either one of the rooms may be a fully qualified
 * room reference; this function figures out correct referencing on its
 * own. If either one of the exits is not in this area, then an inter-area exit is
 * created, and the returned handle will be a string. If the rooms are
 * both within this area, then the returned handle will be an integer.
 *
 * Note that find_room() must return objects for both rooms, or this function
 * will fail.
 *
 * \return An exit handle on success, -1 on failure (0 is a valid exit handle).
 */
mixed add_exit( string room1_name, string room2_name ) {
   object room1, room2;
   mixed common_container, index;

   room1 = find_room( room1_name, this_object() );
   room2 = find_room( room2_name, this_object() );

   if( !room1 || !room2 )
      return -1;

   common_container = all_environment(room1) + ({ room1 }) - all_environment(room2);
   if( sizeof(common_container) == 0 ) common_container = environment(room1);
      else common_container = environment(common_container[0]);

   msg("common_container is " + as_string(common_container) + ", " + common_container->query_name() );

   index = get_exit_index( common_container );
   if( common_container == environment(room1) &&
      common_container == environment(room2) )
      set_exit_var( index, "link", room1->query_name() + "#" + room2->query_name() );
   else
      set_exit_var( index, "link", get_location(room1) + "#" + get_location(room2) );
   set_exit_var( index, room1->query_name(), 0 );
   set_exit_var( index, room2->query_name(), 0 );

   environment(room1)->update_room_exits();
   if( environment(room2) != environment(room1) )
      environment(room2)->update_room_exits();

   return index;
}

/** Deletes an exit and all associated information. The exit given by
 * the handle \a exit is deleted; this handle may be a recursive one,
 * and should still work fine.
 * \return The handle of the removed exit on success, -1 on failure.
 */
mixed remove_exit( mixed exit ) {
   string key;

   if( stringp(exit) ) {
      if( exit[0] == '<' && environment(this_object()) )
         return "<" + environment(this_object())->remove_exit( exit[1..] );
      else {
         exit = to_int(exit);
         if( query_to_int_fail() )
            return -1;
      }
   }
   if( exit < 0 || exit >= sizeof(exits) ) return -1;
   // Set the entry to 0 (can't just delete it, that'll mess up index
   // alignment).
   exits[exit] = 0;
   // Shrink array when possible (remove trailing 0's)
   while( sizeof(exits) && !exits[<1] ) exits = exits[..<2];
   // Update room exits (not efficient, but effective)
   update_room_exits();

   return exit;
}

/** Rebuilds the room_exits mapping. There are two reasons to do this:
 * It is an easy way to fix things if you break them accidentally
 * (which is easy enough, if you don't know what you're doing), and
 * it might actually get used by some highly obscure, complex
 * exit modification scheme. Your pick.
 */
void update_room_exits() {
   int i;
   mapping new_room_exits, room_names, curr_exits;
   string curr;
   mixed ipref;
   object ob;

   new_room_exits = ([ ]);
   ipref = 0;
   foreach( ob : ({ this_object() }) + all_environment(this_object()) ) {
      if( ob->query_is_room() ) {
         if( ipref ) ipref += "<"; else ipref = "<";
         continue; // Heh, only consider AREA objects.
      }
      curr_exits = ob->query_exits();
//      write("From "+as_string(ob)+": "+sizeof(curr_exits)+" exits.\n");
      for( i = 0; i < sizeof(curr_exits); i++ ) {
         if( mappingp(curr_exits[i]) ) {
            mixed *split;
            int isplit;

            curr = curr_exits[i]["link"];
            if( !curr ) continue;
            split = explode( curr, "#" );
//            write( "Link is "+curr_exits[i]["link"]+"\n");
            for( isplit = 0; isplit < sizeof(split); isplit++ ) {
               split[isplit] = find_room( split[isplit], this_object() );
               if( !split[isplit] ) continue;
               if( environment(split[isplit]) == this_object() ) {
                  split[isplit] = split[isplit]->query_name();
                  if( !split[isplit] ) continue;
                  if( !pointerp(new_room_exits[split[isplit]]) )
                     new_room_exits[split[isplit]] = ({ ipref + i });
                  else
                     new_room_exits[split[isplit]] += ({ ipref + i });
//                  write( "Adding: " + as_lpc(ipref+i) + "\n" );
               }
            }
         }
      }
      if( ipref ) ipref += "<"; else ipref = "<";
   }
   room_exits = new_room_exits;
}

/** A low level function for constructing exit indices. It is recursive.
 * You should call add_exit() to create new exits.
 */
mixed get_exit_index( object ob ) {
   if( !environment(this_object()) || ob == this_object() ) {
      int i;
      if( (i = member(exits, 0)) >= 0 ) {
         exits[i] = ([ ]);
         return i;
      }
      exits += ({ ([ ]) });
      return sizeof(exits) - 1;
   }
   else return "<" + environment(this_object())->get_exit_index( ob );
}

/** \return An array of all the exit indices associated with a room. Note that
 * some of them may be strings. This will always return an array.
 */
int *query_room_indices( string name ) {
   if( pointerp(room_exits[name]) )
      return (int *) room_exits[name];
   else
      return ({ });
}

/** \return The array of *all* the exits in this area. This can be very
 * big, so handle with care.
 */
mapping *query_exits() {
   return exits;
}

/** \return If you pass in no parameters, this will return the mapping
 * of rooms with their corresponding indices. If you pass in a \a name,
 * then it will return an array of the exit mappings for that room (not the
 * indices). If you want the indices for a room, use query_room_indices()
 * (but be warned, indices may contain references to outer rooms).
 * Note that these two return types are different! You get back a mapping
 * if you pass in a 0, but an array if you pass in a name. Note that
 * when passing in a name, you'll get an empty array even if the
 * room doesn't exist.
 */
varargs mixed query_room_exits( string name ) {
   mapping ret;

   if( !name )
      return room_exits;

   ret = room_exits[name];
   if( !pointerp(ret) ) return ({ });
   return map( ret,  #'query_exit );
}

/** Sets the exits mapping directly. \a m must be an array, or this call will
 * be quietly ignored. Be very careful not to corrupt exit data; for efficiency,
 * the exit routines will usually assume that data is correctly formatted!
 */
void set_exits( mapping *m ) {
   if( pointerp(m) ) exits = m;
}

/** Sets the mapping of room exits directly. It is required that this be a
 * mapping -- any other datatype is quietly ignored.
 */
void set_room_exits( mapping m ) {
   if( mappingp(m) ) room_exits = m;
}
