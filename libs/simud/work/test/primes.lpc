int *x;

void remove_multiples( int *x, int seed, int max ) {
   int i;

   for( i = 2; seed * i < max; i++ ) x[i * seed] = 0;
}

int *generate_primes( int max ) {
   int i;
   int *p;

   x = allocate( max );
   for( i = 0; i < max; i++ ) x[i] = 1;
   for( i = 2; i < max; i++ ) if( x[i] ) remove_multiples( x, i, max );

   p = ({ });
   for( i = 2; i < max; i++ ) if( x[i] ) p += ({ i });

   return p;
}