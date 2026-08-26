/*
** Cyanide new learn thingie for mage spells.
** Not for players!
*/

int cmd_plearn(string str) {
  if (!str) {
    write("Learn what?\n");
    return 1;
  }

   TP->add("priest_spells", ({ str }) );
  write ("You now know the "+str+" spell.\n");
  
  return 1;
}
