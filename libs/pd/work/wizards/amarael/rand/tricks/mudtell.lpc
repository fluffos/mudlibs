int trick(string str) {
    object tellme;
    string who, what;
    if(!str || str == "")
      return notify_fail("mudtell <player|all> <message>\n");
    if(sscanf(str, "%s %s", who, what) != 2)
      return notify_fail("mudtell <player|all> <message>\n");
    if(who == "all")
      message("info", what, users(), );
    else if(!tellme = find_player(who))
      return notify_fail("Could not find "+who+".\n");
    else
      message("info", what, tellme, );
    return 1;
}
