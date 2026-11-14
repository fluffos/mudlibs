/* just a littel helppage for the adventurer guild */
/* Cadra@Nightfall 15-06-94 */

string help(string str) {
  if (!str) return (string) notify_fail("What help do you want?\n");
  str=lower_case(str);
  if (str=="missile") 
    return "Usage: missile <victim>\n"
"The spell causes light damage to the victim and will cost you 20 SP to cast "
"and is available at level 5.\n";
  if (str=="shock")
    return "Usage: shock <victim>\n"
"The shock will cause wounds on victim and costs you 40 SP to cast. It is "
"available with at level 10.\n";
  if (str=="fireball")
    return "Usage: fireball <victim>\n"
"The fireball will cause medium wounds on the victim. It will cost 60 SP to "
"cast a fireball. The spell is available at level 15.\n";
  if (str=="snowball")
    return "Usage: snowball <victim>\n"
"The snowball will cause medium wounds on the victim. It will cost 80 SP to "
"cast it. The spell is available at level 20.\n";
  if (str=="lightning")
    return "Usage: lightning <victim>\n"
"Lighting will cause heavy wounds on the victim. It will cost you 100 SP to "
"cast it. The spell is available at level 25\n";
  if (str=="icestorm")
    return "Usage: icestorm [victim]\n"
"Icestorm may either be cast at a special victim or just into the room. In "
"either case everyone in the room will get hurt, even the caster himself. "
"It is available at level 30.\n";
  if (str=="stonekick")
    return "Usage: stonekick <victim>\n"
"You may kick a stone at everyone in the same room as you. This won't hurt "
"the victim. This ability is available at level 5 and will cost you 1 SP.\n";
  if (str=="foolsgold")
    return "Usage: foolsgold <item>\n"
"This will cause the loss of any value of the object. The value will become "
"either 1 copper (when it has had a value higher before) or remain 0 if it has "
"already been worthless. Second effect will be that the item will get heavier. "
"The spell is available at level 10 and will cost 40 SP.\n";
  if (str=="paint")
    return "Usage: paint <victim>\n"
"You may paint any item, monster or player in whatever color you want. This "
"ability will cost you 15 SP and is available at level 15. [see also 'clean']\n";
  if (str=="clean")
    return "Usage: clean <victim>\n"
"Will remove any color from <victim>. Any color given to him by an adventurer "
"for sure. It will cost you 15 SP to clean an object. This ability is available "
"at level 15. [see also 'paint']\n";
  if (str=="button")
    return "Usage: button <inscription>\n"
"Will create a BIG button with the inscription of your choice. you may give it "
"away to any other person, monster or thing. It will cost you 15 SP to create "
"a button and you learn it when you are level 15.\n";
  if (str=="tent")
    return "Usage: tent\n"
"If you reach level 20, you may get an own tent in the guild. This will cost "
"you 202 SP and the guildmaster denies to send it to you when you are not in "
"an adventurer guild. The tent will be a portable home for you. you may only "
"have one tent per time, but may get a new one for the cost of 202 SP whenever "
"you lost your tent.\n";
  if (str=="travel")
    return "Usage: travel\n"
"If you are in an adventurer guild you may travel to any other adventurer guild "
"all over Nightfall. This ability is gained at level 25 and allows you to travel "
"to any guild you already visited by foot. It will cost you 50 SP to use this "
"special ability.\n";
  if (str=="guildshout")
    return "Usage: guildshout <text>\n"
"This is a shout that can only be heard by other members of the adventurer "
"guild. It will cost you 5 SP and every adventurer knows how to use it.\n";
  if (str=="adventurer")
    return "Usage: adventurer\n"
"This will list all adventurers in the game. All own titles will get removed on "
"that list and everyone will be shown with the title the guild would give "
"him/her. This will cost you nothing and is available for every "
"adventurer.\n";
  if (str=="light")
    return "Usage: light\n"
"This will light the current room for some time. It is available for every "
"adventurer and will cost 5 SP to cast.\n";
  if (str=="dark")
    return "Usage: dark\n"
"This will darken the current room for a special amount of time. It is available "
"for every adventurer and costs 5 SP.\n";
}


int advhelp(string str) {
  string text;
  if (!str) return (int) notify_fail("Try \"advhelp <topic>\"\n") && 0;
  if (!text=help(str)) return 0;
  write(text);
  return 1;
}

