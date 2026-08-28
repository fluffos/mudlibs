// -N

string humanize_integer(int i)
{
 int n;
 string s;

 n = 0;

 if(i > 1000) { i = i / 1000; n++; }
 if(i > 1000) { i = i / 1000; n++; }
 if(i > 1000) { i = i / 1000; n++; }

 if(!n) return to_string( i );

 if(n == 1) s = "k";
 if(n == 2) s = "M";
 if(n == 1) s = "G";

 return to_string( i + s );
}
