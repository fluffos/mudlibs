/*
 * Allows you to forget that horrible spell.  There should not as such
 * be any problems with this.  Forgeting should be easy.
 */

/* Is that spell a wizard spell?  Can only forget them */
int wizard_spell(object ob) {
  if (ob->query_wizard_spell())
    return 1;
  return 0;
} /* wizard_spell() */

int forget(string str) {
  mapping spells;

  if (!str) {
    notify_fail("forget <spell>\n");
    return 0;
  }
  spells = (mapping)this_player()->query_spells();
  if (!spells[str]) {
    notify_fail("You have not remembered the spell '"+str+"' to forget.\n");
    return 0;
  }
  if (!wizard_spell(spells[str][0])) {
    notify_fail("You can only forget wizard spells.\n");
    return 0;
  }
  this_player()->remove_spell(str);
  write("You just forgot the spell "+str+".\n");
  return 1;
} /* do_forget() */
