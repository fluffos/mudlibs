/* An example "monster"
 * Made with the "new" monster system for FR.
 * Not much have changed..
 * Baldrick, may '94
 */

inherit "/obj/monster";

/* The setup routine, does most of the work.
 * Please keep the order of the set*
 * Please don't use set_guild_ob or set_race_ob unless it is nessesary..
 * use the set_class & set_race instead.. 
 * nessesary = it uses guild specific stuff.. (= not often used. )
 */ 

void setup()
  {
  /* First, the obligatory.. */

  /* Name, keep it lower case letters. */
  set_name("exthief");

  /* What we see. */
  set_short("Exthief");

  /* An alias.. (not obligatory)*/
  add_alias("thief");

  /* What we see when we look at the creep.. */
  set_long("An ugly little creep.\n");

  set_main_plural("exthieves");

  /* not needed.. : */
  //add_plurals("thieves");

  /* 1 = male 2 = female*/
  set_gender(1);

  /* set_race gives just a string, to get the stats from the true race you have
   * to use set_race_ob()
   * but always have set_race too.. */

  set_race("human");
  // set_race_ob("human");

  /* This should be put before set_level! 
   * Usually it was set_class, but that's just a string.. This need the full 
   * path, but not the class thingie..(nor does set_race_ob) */

//   set_guild_ob("/std/guilds/rouges/thief");
//set_class("thief");

  /* here is the meat... the level in set_level is the hit dice..
   * Remember, you can use random.. 
   * set the stats first.. then the level.. 
   */

  /* 
   set_str(14)
   and so on..
  
   * you have a neato version: (easy to use.. stats *have* to be set in
   * a way or another....
   */ 

  set_random_stats(6,18); //will set radom between 6 & 18.. for all stats..

  set_level(4); 
  // set_level(roll(1,8)); // gives a level of 1d8 
  
  /* the XP_value is set by the level, but this will be changed..
   * But you can put a set_xp here if the NPC / Monsie has special XP value..
   * Not nessesary unless the mnsie has special attacks..
   */ 

  //set_kill_xp(200);
  
  /* Alignment, have to be in numbers.. negative is good, positive is evil..
   * Don't ask me why... answers may be found in a Galaxy near you..
   */

  set_al(100);
  
  /* wimpy is known to you.. */
  set_wimpy(0);

  /* add stuff: */
  new("/baseobs/weapons/dagger")->move(this_object());
  new("/baseobs/armours/leather")->move(this_object());
  this_object()->init_equip();
  
  /* Money? maybe.. */
  adjust_money(10, "silver");
} /* setup */
