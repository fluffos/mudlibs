// split
//  Will split an entire string into strings of 200 chars
#define SPLIT 200
string split(string str, string output) {
   int t, i,a,b;
   string out;
   out="";
   t=strlen(str);
   i=t/200;
   while(i--) {
     a=b;
     b=b+200;
     out+=str[a..b-1]+"\n";
   }
   write_file(output, out);
   return out;
}
string unsplit(string file, string output) {
   string *l, out;
   int i;
   out="";
   i=sizeof(l=explode(read_file(file), "\n"));
   if(!i) return "";
   for(i=0; i<sizeof(l); i++) {
     out += l[i];
   }
   write_file(output, out);
   return "File Stats: String Length="+strlen(out)+"";
}
