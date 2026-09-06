// You should include this file to make the object you are
// working with a stackable object. You can include it
// anywhere in the file.
//
// Stackable objects are only appropriate for objects
// whose stats don't change. Items that you can carve
// your initials into, or that need to track independent
// stats such as decay or health, are not good
// candidates. Objects which need to be used in bulk
// and are fairly stable, like money, are good.

string query_distant() {
   if( query_quantity() == 1 )
      return ::query_distant();
   else
      return rough_amount( query_quantity() ) + " " + query_plural();
}

string query_specific() {
   if( query_quantity() == 1 )
      return ::query_specific();
   else
      return rough_amount( query_quantity() ) + " " + ::query_plural();
}

int query_bulk() {
   return ::query_bulk() * query_quantity();
}

int query_weight() {
   return ::query_weight() * query_quantity();
}

int query_value() {
   return ::query_value() * query_quantity();
}
