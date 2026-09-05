/* 05/16/06 Earwax: removed this from player.c put it here just in
 * case it's still in use somewhere.
 *
 */

old_score() {
  int intox_level;
  string tmp;

    if (ghost) {
write("You are in an immaterial state with no scores.\n");
return 1;
    }
    write("You have " + experience + " experience points, " +
  money + " gold coins,\n");
    write(hit_point + " hit points (of " + max_hp + "), and ");
    write(spell_points + " spell points (of " + max_spell + ").\nYou are " + short() + " (level " + level + ").\n");
    if (hunter && call_other(hunter, "query_name"))
        write("You are hunted by " + call_other(hunter, "query_name") + ".\n");
    if (!intoxicated)
write("You are sober.\n");
    else {
intox_level = (level + 4) / intoxicated;
if (intox_level == 0)
    write("You are in a drunken stupor.\n");
else if (intox_level == 1)
            write("You are roaring drunk.\n");
else if (intox_level == 2)
    write("You are somewhat drunk.\n");
else if (intox_level == 3)
    write("You are quite tipsy.\n");
else
    write("You are slightly tipsy.\n");
    }
    if (stuffed || soaked)
    {
tmp = "You are ";

        if (stuffed)
{
    tmp += "satiated";

    if (soaked)
tmp += " and ";
    else
tmp += ".\n";
}

if (soaked)
    tmp += "not thirsty.\n";

write(tmp);
    }

    if (whimpy)
write("Wimpy mode.\n");
    show_age(); write("\n");
  return 1;
}
