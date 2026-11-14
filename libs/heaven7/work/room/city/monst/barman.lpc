inherit "inherit/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_race("ogre");
  set_gender(1);
  set_level(10);
  set_name("bloodeye");
  set_short("Bloodeye, the ogre barman");
  set_long(
   "Big, strong and yellow. Bloodeye is the barman for Skandles' Downfall.\n"+
   "Even though he might not look smart, his muscles do the talking for him.\n");
  load_chat(10, ({ "Bloodeye licks a glass clean.\n",
   "Bloodeye looks behind the bar.\n",
   "Bloodeye watches you carefully.\n",
   "Bloodeye drinks a mug of beer.\n",
   "Bloodeye says: You not look like a thief person.\n",
   "Bloodeye looks warily behind the bar.\n",
   "Bloodeye watches the room carefully.\n",
   "Bloodeye says: You not be stirrin' up twubble hey?\n",
   "Bloodeye says: No twubble fom you I hope.\n",
   "Bloodeye sneazes into a beer mug.\n" }));

  load_a_chat(10, ({ "Bloodeye exclaims: You're not a nice person!\n",
   "Bloodeye smashes a bottle over your head.\n",
  "Bloodeye says: You're a nasty person!\n",
  "Bloodeye throws a mug of beer at you!\n" }));

  set_wc(14);
  set_ac(10);

  set_spell_dam(3);
  set_spell_mess1("Bloodeye smashes you with his fist!");
  set_spell_mess2("Bloodeye smashes 0 with his fist!");

  set_al(-10);
  add_money(random(50) + 35);
  load_l_chat(5, "ogre", ({ "Are you a thief person?",
    "The thieves meet down the trap door..." }));
}

init() {
  ::init();
  add_action("hug", "hug");
}

hug(string str) {
  if(id(str)) {
    write("Bloodeye hugs you back!\n");
    say("Bloodeye hugs "+ this_player()->query_name() +".\n", this_player());
    return 0;
  }
return 0;
}
