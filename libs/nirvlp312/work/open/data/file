/* A Stark Doll, Created <5/6/00> by Jara */


inherit "/obj/treasure.c";

reset(int arg) {
   if(arg) return;
   set_id("doll");
    set_short("A Stark Doll");
  set_long("A six-inch doll, with long curly hair pulled back into a ponytail.\n"+
    "He is wearing a long, black coat and a string hangs from his back.\n");
  set_weight(1);
  set_value(0);
    set_dest_flag(1);
}

init() {
  ::init();
  add_action("flame","pull");
}
flame(arg) {
  if(arg == "string") {
    switch(random(5)) {
      case 0: write("You pull the string...\n"+
                    "The Stark Doll's hands burst into flames!\n");
              say(this_player()->query_name()+" pulls the string on the doll...\n"+
                  "The doll's hands burst into flames!\n");
              break;
      case 1: write("You pull the string...\n"+
                  "The Stark Doll says: G'night for now!\n");
              say(this_player()->query_name()+" pulls the string on the doll...\n"+
                  "The Stark Doll says: G'night for now!\n");
              break;
      case 2: write("You pull the string...\n"+
                    "The Stark Doll grins evilly.\n");
              say(this_player()->query_name()+" pulls the string on the doll...\n"+
                  "The Stark Doll grins evilly.\n");
              break;
      case 3: write("You pull the string...\n"+
                   "The Stark doll giggles and says, 'That tickles!'\n");
              say(this_player()->query_name()+" pulls the string on the doll...\n"+
                   "The Stark Doll giggles and says, 'That tickles!'\n");
              break;
      case 4: write("You pull the string...\n"+
                   "The Stark doll thinks Jara thinks Jaraxle is a total hottie!\n");
              say(this_player()->query_name()+" pulls the string on the doll...\n"+
                   "The Stark doll thinks Jara thinks Jaraxle is a total hottie!\n");
              break;
    }
    return 1;
  }
}

