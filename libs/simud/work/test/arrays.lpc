void array_test() {
   int *x, i;

   x = ({ 1, "hello", 3.141592 });

   for( i = 0; i < sizeof(x); i++ )
      msg( as_string(x[i]) );
}

int *pass_ptr() {
   return ({ 2, 3 });
}

int test_ptr() {
   int x, y, *a;
   a = pass_ptr();
   x = a[0];
   y = a[1];
   msg( "" + x + " " + y );
}