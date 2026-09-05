dhelp(str) {
  write("\n");
  write(HIK+"\tDarkness flows from the ground surrounding you...\n"+NORM);
  if(!str) {
    cat("/players/pestilence/closed/dark/help/general.txt");
    write("\n"); return 1; }
  if(str == "levels"){cat("/players/pestilence/closed/dark/help/levels.txt"); return 1;}
  if(str == "rules"){cat("/players/pestilence/closed/dark/help/rules.txt"); return 1;}
  if(str == "story"){cat("/players/pestilence/closed/dark/help/story.txt"); return 1;}
  if(str == "combat"){cat("/players/pestilence/closed/dark/help/combat.txt"); return 1;}
  if(str == "LeaveDervish"){cat("/players/pestilence/closed/dark/help/leave.txt"); return 1;}
  if(str == "dhome"){cat("/players/pestilence/closed/dark/help/dhome.txt"); return 1;}
  if(str == "dhome"){cat("/players/pestilence/closed/dark/help/dhome.txt"); return 1;}
  if(str == "run"){cat("/players/pestilence/closed/dark/help/run.txt"); return 1;}
  if(str == "scatter"){cat("/players/pestilence/closed/dark/help/scatter.txt"); return 1;}
  if(str == "transfer"){cat("/players/pestilence/closed/dark/help/transfer.txt"); return 1;}
  if(str == "dchant"){cat("/players/pestilence/closed/dark/help/dchant.txt"); return 1;}
  if(str == "dpray"){cat("/players/pestilence/closed/dark/help/dpray.txt"); return 1;}
  if(str == "confuse"){cat("/players/pestilence/closed/dark/help/confuse.txt"); return 1;}
  if(str == "dheal"){cat("/players/snow/dervish/help/dheal.txt"); return 1;}
  if(str == "offwield"){cat("/players/pestilence/closed/dark/help/offwield.txt"); return 1;}
  if(str == "sandblast"){cat("/players/pestilence/closed/dark/help/sandblast.txt"); return 1;}
  write("That help topic is not available.\n"); return 1; }
