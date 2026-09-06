void test_pass_by_reference() {
   int *x;

   x = ({ 1, 2, 3, 4 });
   "/test/primes"->remove_multiples( x, 2, 4 );
   msg( as_string(x) );
}

remove_item( mapping m, string key ) {
   m_delete( m, key );
}

void test_mappings() {
   mapping m;

   m = ([ "itema":1, "itemb":2, "itemc":3 ]);

   this_object()->remove_item( copy(m), "itema" );
   msg( as_string(m) );
   remove_item( m, "itemb" );
   msg( as_string(m) );
}