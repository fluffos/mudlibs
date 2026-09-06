string reverse_string( string s ) {
   int i, j;

   for( i = 0; i < strlen(s) / 2; i++ ) {
      j = s[i];
      s[i] = s[<i+1];
      s[<i+1] = j;
   }

   return s;
}

string *ctest() {
   string *l;

   l = ({ "absolution", "thickening", "liquidation", "sighed", "deify" });
   l = sort_array( l,
      lambda( ({ 'a, 'b }),
         ({ #'?,
            ({ #'>, ({ #'reverse_string, 'a }),
               ({ #'reverse_string, 'b }) }),
            1, 0 })) );
   return l;
}

mapping ftest() {
   mapping l, m;

   l = ([ "absolution":0, "thickening":1, "liquidation":2, "sighed":3, "deify":4, "hailing":5, "rings":6 ]);
   m = filter( l, (: $1[<3..] == "ing" :) );
   return l;

}