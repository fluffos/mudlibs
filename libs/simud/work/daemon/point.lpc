mapping wizpoints = ([ ]);
mapping weekpoints = ([ ]);
mapping wiz_birthday = ([ ]);

void create() {
   if( file_exists("/daemon/point.o") )
      restore_object( "/daemon/point" );
   // Every hour...
   call_out( "point_decay", 3600 );
}

void add_point( string wizname, int amount, string reason ) {
   if( getuid(previous_object()) != "root" ) return;

   if( amount > 100 ) raise_error( "/daemon/point: Hard limit, can't add more than 100 points at a time. Sorry." );

   wizpoints[wizname] += amount;
   if( wizpoints[wizname] > 0 ) {
      log_file( "points", as_string(previous_object()) + " added " + amount + " points to " + wizname + ", total " + wizpoints[wizname] + ": " + reason + ".\n" );

      if( !weekpoints[wizname] )
         weekpoints[wizname] = ({ });
      if( amount > 0 ) {
         int i;
         for( i = 0; i < amount; i++ )
            weekpoints[wizname] += ({ time() });
      }
      else {
         weekpoints[wizname] = weekpoints[wizname][..<(-amount+1)];
      }
   }
   else {
      log_file( "points", as_string(previous_object()) + " added " + amount + " points to " + wizname + "; zeroed and entry deleted.\n" );
      m_delete( wizpoints, wizname );
      m_delete( weekpoints, wizname );
   }

   save_object( "/daemon/point" );
}

void query_points() {
   return copy(wizpoints);
}

void query_weekpoints() {
   return deep_copy(weekpoints);
}

void point_decay() {
   string name;
   int *times;

   remove_call_out( "point_decay" );
   call_out( "point_decay", 3600 );
   foreach( name, times : weekpoints ) {
      int i = 0;
      while( i < sizeof(times) && times[i] < (time() - 168 * 3600) ) i++;
      if( i > 0 ) weekpoints[name] = weekpoints[name][i..];
   }
}

void set_wiz_birthday( string name, int day ) {
   if( day == -1 )
      m_delete(wiz_birthday, name);
   else
      wiz_birthday[name] = day;
}

mapping query_wiz_birthdays() {
   return wiz_birthday;
}

int query_wiz_birthday( string name ) {
   return wiz_birthday[name];
}

remove_wiz( string name ) {
   m_delete(wizpoints, name);
   m_delete(weekpoints, name);
   m_delete(wiz_birthday, name);
}
