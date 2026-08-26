inherit "/std/effect_shadow";


string mangle_speech( string s ) {
   string ret;
   int i,j;
   i=sizeof(s);
   if(i>1000) 
     i=1000;
   ret="Ook! ";
   for(j=0;j<i; j++){
     if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
          s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
          s[j] == 'O' ||s[j] == 'U')
       ret+=({"Ook! ", "Eeek! ", "OOOK! ", "EEEK! "})[random(4)];
   }
   return ret;
}
