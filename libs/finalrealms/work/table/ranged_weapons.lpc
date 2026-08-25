
// Radix stepped here and fell on his face - Feb. 22, 1996
/*
   get_info() returns array:
   
     0 - Range
     1 - Speed 
     2 - Base Accuracy
     3 - Container type
     4 - Ammo type
     5 - Hands needed
*/
 
string look_up(string t)
{
   if(!t || !stringp(t)) return "bow";
   switch(t)
   {
      case("long bow"):
         return t;
      case("bow"):
      case("short bow"):
         return "bow";
      case("cross bow"):
         return t;
      case("blow gun"):
      case("blowgun"):
         return "blow gun";
      case("light cross bow"):
         return t;
      case("heavy cross bow"):
         return t;
      case("knife"):
      case("throwing knife"):
         return "throwing knife";
      case("throwing hammer"):          /* return t */
      	 return "throwing hammer";	/* By me */
      case("sling"):
         return t;
   }
   return "bow";
}
 
mixed get_info(string t)
{
    switch(t)
   {
      case("long bow"):         return ({ 5,3,50,"quiver","arrow",2 });
      case("bow"):              return ({ 3,2,40,"quiver","arrow",2 });
      case("heavy cross bow"):  return ({ 3,1,40,"quiver","bolt",2 });
      case("cross bow"):        return ({ 2,1,30,"quiver","bolt",2 });
      case("light cross bow"):  return ({ 1,1,30,"quiver","bolt",2 });
      case("blow gun"):         return ({ 2,2,40,"pouch","needle",2 });
      case("throwing knife"):   return ({ 1,1,30,"none","itself",1 });
      case("throwing hammer"):  return ({ 1,1,30,"none","itself",2 });
      case("sling"):            return ({ 1,2,20,"pouch","pebble",1 });
   }
}
