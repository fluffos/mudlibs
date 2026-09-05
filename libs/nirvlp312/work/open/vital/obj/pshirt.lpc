/******************************************************************************
 *  
 *  File:           pshirt.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 2001 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:         Started 9/21/01.
 *  
 *  Notes:			
 *  
 *  Change History: 
 *  
 *  
 *****************************************************************************/

#include "/players/vital/spaceport/spaceport.h"

inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("silk shirt");
   set_short(BLU+"S"+HIB+"i"+NORM+BLU+"l"+HIB+"k "+NORM+BLU+"S"+HIB+"h"+NORM+BLU+"i"+HIB+"r"+NORM+BLU+"t"+NORM);
   set_long("\
  Only a true rag-master could appreciate the fine quality that \n\
went in to making this master piece. Other shirts merely protect \n\
the man...this shirt instead has the look and the feel. A man with \n\
shirt like this could rule the world.\n");
   set_ac(2);
   set_info("100\% Pure Neo-Silk. So silky, even the worms butts are chapped.\n");
   set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(random(200)+400);
}

do_special(owner) {
   switch(random(100)) {
       case   0..9: return -1; break;
       case 10..80: return 0; break;
       case 81..90: tell_object(owner, "You dance and move like Michael Jackson on crack.\n"); return 1; break;
       case 91..94: tell_object(owner, "You fight like Mean Joe "+GRN+"Green!\n"); return 2; break;
       case 95..98: tell_object(owner, "This fashion owns you.\n"); TP->add_money(-10); return 1; break;
       case 99:     tell_object(owner, "The "+BLU+"S"+HIB+"i"+NORM+BLU+"l"+HIB+"k "+NORM+BLU+"S"+HIB+"h"+NORM+BLU+"i"+HIB+"r"+NORM+BLU+"t"+NORM+" gaffles the crowd and swings some juice.\n"); TP->add_money(10); return 1;
   }
}
