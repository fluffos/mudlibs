#include <std.h>

#define TYPES ({ "The valentine is in the shape of a heart, bound in a smooth red silk.  The outside edge is bordered in a beautiful white lace.  It looks like you can open it and <read valentine>.", \
                 "This valentine looks like a rose at first, with large, deep red petals.  Upon closer inspection, the petals open up to reveal a message.  You can <read valentine> to see what it says.", \
                 "The valentine is a small card with a flowing calligraphy on the cover that says \"Every time you smile at someone, it is an action of love, a gift to that person, a beautiful thing.\".  You can open the card and <read valentine>.", \
                 "This valentine is a cute stuffed teddy bear with small black eyes and a smile on it's face.  It's holding its belly where a message has been written.  Perhaps you could read it." })

inherit OBJECT;

mapping buyers;
string *empty;

void create() {
  ::create();
  set_name("stand");
  set_short("valentine stand");
  set_long("There is a small stand here in the square where you can purchase a valentine <buy valentine> for that someone special.  A sign next to the stand says that it's 500 gold per valentine.");
  set_id( ({ "stand", "valentine stand" }) );
  set_prevent_get("You can't take the stand!");
  buyers = ([ ]);
  empty = ({ });
}

void init() {
  ::init();
  add_action("buy", "buy");
}

int buy(string str) {
  int i;

  if(str != "valentine")
    return notify_fail("You cannot buy that here.\n");

  if(this_player()->query_money("gold") < 500)
    return notify_fail("You do not have enough gold to buy a valentine.\n");

  this_player()->add_money("gold", -500);

  buyers[this_player()] = empty;

  write("Note:  You can perform any actions during this process by adding a ! to the front.  ex:  <!newbie I'm making a valentine>\n");

  write("What kind of card would you like?  There are "+sizeof(TYPES)+" to choose from.");
  
  for(i = 0; i < sizeof(TYPES); i++)
    write(""+(i+1)+".  "+TYPES[i]);

  write("\nEnter your choice here: ");
  input_to("pick_type");

  return 1;
}

void pick_type(string str) {
  int pick;

  pick = to_int(str);
  if(!pick) {
    write("Invalid choice.  Choose a number: ");
    input_to("pick_type");
    return;
  }

  if(pick > sizeof(TYPES) || pick <= 0) {
    write("Invalid choice.  Choose a number: ");
    input_to("pick_type");
    return;
  }

  pick--;
  buyers[this_player()] += ({ TYPES[pick] });
  buyers[this_player()] += ({ " " });

  write("\nWhat would you like to write on the inside of the card?");
  input_to("write_card");
}

void write_card(string str) {

  buyers[this_player()][1] = str;

  write("\nYou wrote: "+str+"\nIs that good? (y/n): ");

  input_to("finish_card");
}

void finish_card(string str) {

  if(str == "n" || str == "N") {
    write("\nWhat would you like to write, then?");
    input_to("write_card");
    return;
  }
  else if(str != "y" && str != "Y") {
    write("Is that good? (y/n): ");
    input_to("finish_card");
    return;
  }

  write("Finally, who is this card to?  Please use the name of the character you will give the valentine to.");

  input_to("do_it");
}

void do_it(string str) {
  object ob;

  str = lower_case(str);

  if(!user_exists(str)) {
    write("It needs to be the name of the character.");

    input_to("do_it");
    return;
  }

  ob = new("/wizards/nightshade/val");
  ob->set_long(buyers[this_player()][0]);
  ob->set("read", buyers[this_player()][1]);
  ob->set_type(member_array(buyers[this_player()][0], TYPES));
  ob->set_to(str);
  ob->set_from(this_player()->query_name());
  ob->set_short("a valentine from "+capitalize(this_player()->query_name()));
  ob->move(this_player());

  map_delete(buyers, this_player());

  write("Your card is created and handed to you.  Happy Valentines day!");

}
