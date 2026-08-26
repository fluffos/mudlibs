
#include <colour.h>

string calc_colour( int red, int green, int blue, int whitener ) {
   string result;

   result = "";
   if ( whitener > -1 ) {
      switch ( red + green + blue ) {
         case 0 .. 4 :
            return "colourless";
         case 5 .. 29 : 
            result += "faint ";
            break;
         case 30 .. 154 :
            break;
         default :
            result += "intense ";
      }
   }
   return result;
} /* calc_colour() */

