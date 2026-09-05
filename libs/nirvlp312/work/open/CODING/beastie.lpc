make_monster() {
   object monster;
   monster = clone_object("/obj/monster");
   /* name and alias are what the monster is identifyable by */
      monster->set_name("chicken");
   monster->set_alias("rubber chicken");
   monster->set_short("A rubber chicken");
   monster->set_long(
      "A blubbery rubber chicken. Makes you want to kill it, doesn't it?\n");
   monster->set_level(5);
   monster->set_hp(100);
   monster->set_wc(10);
   monster->set_ac(5);
   monster->set_ep(10000);   
   monster->set_align(-100); /* this monster is bad, obviously :) */ 
  /* set up a message seen when the monster is around */
  monster->load_chat("The rubber chicken flobbles.\n");
  monster->set_chat_chance(20); /* 20% chance of seeing it */
  /* set up a message seen when the monster is fighting */
  monster->load_a_chat("The rubber chicken slaps you with its jelly!\n");
  monster->set_a_chat_chance(20);
  return monster; /* return our created monster to the room */
}
