/// Mapping of name: position
mapping landmarks;

void set_landmarks( mapping m ) {
   landmarks = m;
}

mapping query_landmarks() {
   return landmarks;
}

int query_is_landmark() {
   return 1;
}

void set_landmark( string name, int pos ) {
   if( !mappingp(landmarks) ) landmarks = ([ ]);
   landmarks[name] = pos;
}

void remove_landmark( string name ) {
   if( !mappingp(landmarks) ) landmarks = ([ ]);
   m_delete( landmarks, name );
}

int query_landmark( string name ) {
   if( !mappingp(landmarks) ) landmarks = ([ ]);
   return landmarks[name];
}

string get_landmark_description( int pos ) {
   string *desc, ilandname, base_phrase;
   int ilandpos;

   if( !mappingp(landmarks) || sizeof(landmarks) == 0 ) return "No landmarks visible.";
   desc = ({ });
   foreach( ilandname, ilandpos : landmarks ) {
      int dist, dx, dy;
      string dir;

      dx = SCX(ilandpos) - CX(pos);
      dy = SCY(ilandpos) - CY(pos);
      // If on top of the landmark, don't print it...
      if( dx == 0 && dy == 0 )
         return "This is " + ilandname + ".";
      dist = abs(dx) + abs(dy); // Manhattan distance
      if( abs(dx) > 2 * abs(dy) ) { // east/west
         if( dx < 0 ) dir = "west";
         else dir = "east";
      }
      else if( abs(dy) > 2 * abs(dx) ) { // north/south
         if( dy < 0 ) dir = "north";
         else dir = "south";
      }
      else { // Corner directions
         if( dx < 0 && dy < 0 ) dir = "northwest";
         else if( dx > 0 && dy < 0 ) dir = "northeast";
         else if( dx < 0 && dy > 0 ) dir = "southwest";
         else dir = "southeast";
      }

      switch( dist ) {
         case 0..10: desc += ({ "~CLAB" + capitalize(ilandname) + "~CDEF: just " + dir + " of here" }); break;
         case 11..30: desc += ({ "~CLAB" + capitalize(ilandname) + "~CDEF: to the " + dir }); break;
         case 31..50: desc += ({ "~CLAB" + capitalize(ilandname) + "~CDEF: far to the " + dir }); break;
         default    : desc += ({ "~CLAB" + capitalize(ilandname) + "~CDEF: in the distant " + dir }); break;
      }
   }

   return "~CBRTLandmarks~CDEF\n" + comma_list( desc );
}
