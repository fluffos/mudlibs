inherit "/obj/armour"; /* Used to be /obj/armour */

void setup()  
{ 
  set_type("chain mail");  /* Will set up most of the armour for you */
  set_name("chainmail");   /* The name is an identifier **/ 
  add_adjective("bloody"); /* Will now react to both 'chainmail', 
                            * 'bloody chain mail' and 'bloody chainmail */ 
  set_short("bloody chainmail");        /* What the players see */ 
  set_main_plural("bloody chainmails"); /* What the the players see if there
                                           are more than one of that armour */
  set_enchant(1);          /* Makes the armour a +1 chain mail, meaning that
                            * it's magic makes it protect you better. */ 
  set_long("This is a really bloody chainmail. The blood can't be removed. "+
           "Perhaps it's magical.\n");  /* What you see when you look at it */
 
  /* Set_read_mess is what is returned when players read what is written on
       your weapon. This can be just about any string */ 
  set_read_mess("Forged especially for Baergon by Ducky."); 

  /* STOP here a moment a read!  The above is all you need to make a piece of
   * armour.  A table of legal armours can be found in /table/armour_table.c.
   * This table sets up ac, value, weight and type of armour for you.
   * If you want to change any of these, look below these comment lines.  This
   * is not normally done however, so it may not be of any interest to you.
   
   * NOTE:  There is an armoury (/obj/handlers/armoury) that includes most of
   * the baisc armour types.  No reason to code what someone else have done 
   * already, so use these when a proper weapon exists. The syntax for this is:
   * "/obj/handlers/armoury"->request_armour("chain mail", 100);
   * This will return a chain mail in perfect shape.  It you want it to be
   * harmed by... say 30 percent, just exchange the 100 with 70. */

  adjust_value(100);  /* Increases the value by 100 GP */
  adjust_weight(10);  /* Increases the weight by 1 pound */
  add_ac("magic","magic",4); /* Gives the armour a protection ration from
                              * attacks of the form 'magic' */
} 
