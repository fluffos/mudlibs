inherit "/obj/armour";
#include <move_failures.h>
void setup(){
 set_name("pendant");
 set_short("butterfly lover's pendant");
 add_adjective(({"butterfly", "lovers", "lover's"}));
 set_long("A finely wrought enamel pendant in brilliant hues of blue "
  "and green has two silver filigree wings. Each wing is dotted with tiny "
  "peridots and emeralds.  When the pendant is opened, it splits in half.  "
  "The pendant drops from a silver filigree chain.  A second matching chain "
  "is included.  Open the pendant to create two necklaces, one for each lover.\n");
 set_type("necklace");
 add_property("no recycling", 1);
 set_value(12000);
}
int do_open(){
 object left, right;
 add_succeeded_mess("$N split$s the pendant in two, then connect$s the chain "
    "cunningly crafted inside onto the other half.\n",({}));
 left=clone_object("/obj/armour");
 left->set_name("pendant");
 left->set_short("butterfly left wing lovers pendant");
 left->set_long("A finely wrought enamel pendant drops from a silver filigree chain.  The "
   "intricate left wing of a butterfly is fashioned of silver filigree dotted "
   "with tiny peridots and emeralds.  Your lover wears the right wing of the "
   "butterfly to symbolize your shared love.\n");
 left->set_short("butterfly left wing lover's pendant");
 left->add_property("no recycling", 1);
 left->add_adjective(({"butterfly", "left", "wing","lovers", "lover's"}));
 left->set_type("necklace");
 left->set_value(0);
 left->move(environment(this_player()));
 if(left->move(this_player()) != MOVE_OK)
  write("You drop the left wing pendant.\n");
 right=clone_object("/obj/armour");
 right->set_name("pendant");
 right->set_short("butterfly right wing lovers pendant");
 right->set_long("A finely wrought enamel pendant drops from a silver filigree chain.  The "
"intricate right wing of a butterfly is fashioned of silver filigree dotted "
"with tiny peridots and emeralds.  Your lover wears the left wing of the "
"butterfly to symbolize your shared love.\n");
 right->set_short("butterfly right wing lover's pendant");
 right->add_adjective(({"butterfly", "right", "wing","lovers", "lover's"}));
 right->set_type("necklace");
 right->set_value(0);
 right->add_property("no recycling",1);
 right->move(environment(this_player()));
 if(right->move(this_player()) != MOVE_OK)
  write("You drop the right wing pendant.\n");
 move("/room/rubbish");
 return 1;
}
void init(){
 add_command("open", "<direct:object>");
 add_command("split", "<direct:object>", (:do_open():));
}