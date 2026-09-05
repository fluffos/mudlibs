/*  Cleanse   - Removes Poison for 20 sps & 20 end */

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{
   object boo;
   int al;
   string aln;
	if(USER->query_ghost()) return 0;
   if(!str){ 
     tell_object(USER, "Detect alignment of who?\n"); 
     return 1; 
     }
   boo = present(str, environment(USER));
   if(!boo){ 
     tell_object(USER, "You do not see "+str+" here.\n");
     return 1;
     }
   if(!living(boo)){ 
     tell_object(USER, "That is not a living thing!\n"); 
     return 1; 
     }
   tell_object(USER,
   "You concentrate on "+capitalize(str)+"...\n");
   al = boo->query_alignment();
if(al == 0){ aln = "Neutral"; }
else if(al > 0){
  switch(al){
   case 641..10000: aln = "White Lord"; break;
   case 321..639:   aln = "Paladin";    break;
   case 161..320:   aln = "Crusader";   break;
   case 81..160:    aln = "Good";       break;
   case 41..80:     aln = "Honorable";  break;
   case 1..40:      aln = "Neutral";    break;
   }
 }
else if(al < 0){
  al = - al;     
   switch(al){
   case 641..10000: aln = "Lord of Evil"; break;
   case 321..639:   aln = "Black Knight";    break;
   case 161..320:   aln = "Infamous";   break;
   case 81..160:    aln = "Evil";       break;
   case 41..80:     aln = "Malicious";  break;
   case 1..40:      aln = "Neutral";    break;
   }
 } 
 tell_object(USER, capitalize(str)+" is of "+HIW+aln+NORM+" alignment.\n");
	return 1;
}


