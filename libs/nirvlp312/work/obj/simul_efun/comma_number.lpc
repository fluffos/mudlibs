/******************************************************************************
 * Program: comma_number.c
 * Path: /obj/simul_efun
 * Type: Simulated efun
 * Created: Apr 23, 2014 by Dragnar
 *
 * Purpose: Simulated efun for formatting numbers with commas
 * 
 * History:
 *          04/23/2014 - Gnar
 *            Created
 *          07/16/2014 - Gnar
 *            Thanks Mokri for provided code to update this function!
 ******************************************************************************/
string
comma_number(int numberInt) {
   string tmp,number;
   int x,loopCount;

   loopCount = 0;
   tmp = "";
   number = "" + numberInt + "";

   for(x = strlen(number)-1; x >= 0; x--) {
      loopCount++;
      tmp += extract(number,x,x);
      if(loopCount % 3 == 0 && x > 0)
         tmp += ",";
   }

   number = "";

   for(x = strlen(tmp)-1; x >= 0; x--)
      number += extract(tmp,x,x);

   return number;
}
