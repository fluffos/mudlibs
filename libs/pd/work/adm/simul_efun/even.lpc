//  Contains even() and odd() efuns.

int even(int i) {
   int a, b;
   float f, res;
   f=to_float(i);
   res = f/2;
   if(!sscanf(itos(res), "%d.%d", a, b)) return 0;
   if(b > 0) return 0;
   return 1;
}

int odd(int i) {
   if(!even(i)) return 1;
   return 0;
}

