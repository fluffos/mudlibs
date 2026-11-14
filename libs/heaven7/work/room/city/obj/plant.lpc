inherit "inherit/monster";


string *eaten;    /* plants dinner */
object armour;

reset(arg) {
  eaten = ({});
  if(!present("armour")) {
    armour = clone_object("inherit/armour");
    armour -> set_name("leather");
    armour -> set_alias("shirt");
    armour -> set_short("A leather shirt");
    armour -> set_long("A simple leather shirt.\n");
    armour -> set_ac(1);
    armour -> set_weight(1);
    armour -> set_value(300);
    armour -> set_sell_destruct(1);
    armour -> set_armour_material("leather");
    move_object(armour, this_object());
  }
  ::reset(arg);
  if(arg) return;

  set_hp(50);
  set_ac(3);
  set_wc(5);
  set_attack_msg(({
	"grows it's root into", "causing a great deal of pleasure",
        "bites", "with it's flower",
        "whacks", "with it's pot",
        "rises upwards, scaring the wits out of", "",
        "scratches", "with it's thorns, injecting poison",
        "sucks", "into it's knot-hole",
        "slaps", "with it's fronds"
  }));
  set_name("newbie eating plant");
  set_alias("plant");
  set_race("plant");
  set_gender(2); /* female */
  set_light(1); /* so they can see inside her */
  set_short("A newbie eating plant");
}

long() {
  write("This large plant appears to have grown right out of the rose \n"+
        "garden! It is probably the product of some druids sense of   \n"+
        "hunour and magic.\n");
  if(present(this_player(), this_object())) {
    write("You are right inside the tummy of the newbie eating plant!\n"+
          "Perhaps if you scratch it it will let you out.\n");
    return 1;
  }
  write("Its teeth filled mouth gapes open at you, and it stares at you "+
        "hungrily...\n");
  return 1;
}

init() {
  if(this_player() ->query_level() < 2)
    call_out("eatme", 1);
  add_action("scratch", "scratch");
  ::init();
}

eatme() {
  if(present(this_player(), environment())) {
    if(!query_eaten(this_player()->query_name())) {
      write("The newbie eating plant eats you whole!\n");
      say("The newbie eating plant eats "+ this_player()->query_name() +
      " whole!\n", this_player());
      move_object(this_player(), this_object());
      add_eaten(this_player()->query_name());
    }
  }
  return 1;
}

scratch() {
  write("The newbie eating plant spits you out!\n");
 this_player()->move_player("#room/city/garden/garden7");
  return 1;
}

add_eaten(string str) {
  if(!query_eaten(str))
    return eaten += ({ str, });
  return 0;
}

query_eaten(string str) {
  if(!eaten || !sizeof(eaten)) return 0;
  if(index(eaten, str) > -1) return str;
  return 0;
}
