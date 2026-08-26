/*
** Cyanide new learn thingie for mage spells.
** Not for players!
*/

int cmd_learn(string str) {
  if (!str) {
    write("Learn what?\n");
    return 1;
  }

  TP->add("mage_spells", ({ str }) );
  write ("You now know the "+str+" spell.\n");
  
  return 1;
}

string help() {
  return @ENDHELP
Usage: learn <spell_name>

This command is used to allow wizards to automatically learn spells,
for testing purposes... mostly.
ENDHELP
  ;
}
