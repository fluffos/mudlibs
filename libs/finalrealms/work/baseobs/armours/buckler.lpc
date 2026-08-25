
/* The example armour.. */

inherit "/obj/armour"; 
int query_shield() { return 1; }

void setup()  
  { 
  /* THIS HAS TO BE THE FIRST LINE !!!! */
  set_base_armour("buckler");/* Will set up most of the armour for you */

  set_name("buckler");   /* The name is an identifier **/ 

  set_short("buckler");        /* What the players see */ 

  set_main_plural("bucklers"); /* What the the players see if there
                                           are more than one of that armour */
  add_alias("shield"); /*see the bronzeplate.c for an explanation of add_alias
                       and of add_plural */
  add_plural("shields");
  set_long("This is a small buckler-shield which can be fastened to the "
          "wrist.\n");
 
} 
