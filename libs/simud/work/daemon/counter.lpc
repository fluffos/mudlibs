mapping count;

void create() {
   restore_object("/daemon/count");
   if( !mappingp(count) )
      count = ([ ]);
}

void reset() {
   save_object("/daemon/count");
}

string destructor( object ob ) {
   save_object("/daemon/count");
   return 0;
}

int query_count( string var ) {
   return count[var];
}

mapping query_counts() {
   return count;
}

varargs void add_count( string var, int amt ) {
   if( !amt ) amt = 1;
   count[var] = count[var] + 1;
}

void set_count( string var, int amt ) {
   if( !amt )
      m_delete( count, var );
   else
      count[var] = amt;
}

void clear_counts() {
   count = ([ ]);
}
