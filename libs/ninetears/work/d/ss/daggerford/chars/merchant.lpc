// Merchant...

inherit "/obj/monster";

void setup() {    
      set_name("merchant");
      set_short("Merchant");
      set_race("human");
      set_class("merchant");
      add_move_zone("city");
      set_level(4+random(3));
	set_random_stats(6, 18);
      add_alias("trader");
      set_long(
"This is a merchant. He comes to Daggerford to sell his goods.\n");
      adjust_money(random(20),"copper");
      load_chat(10, ({
        1, "'My goods are cheapest.",
        1, "'Don't buy his, they are defective.",
        1, "'Alas, It'll be the death of me, but you can have it cheap.",
        1, "'What?  No you can't possibly have it cheaper.",
        1, ":shuffles over to you and mutters about what he is selling.",
        1, ":wanders over to an unsuspecting victim and tries to " +
           "sell to him."
      }));
      load_a_chat(60, ({
        1, "'But I paid the thieves guild already.",
        1, "'The lords will hear about this.",
        1, "'Why me ?",
        1, "'Help, Cityguards save me.",
        1, ":tries to bribe you to leave."
      }));
      if(random(4))
	new("/baseobs/weapons/knife")->move(this_object());
      new("/baseobs/armours/cape")->move(this_object());
	this_object()->init_equip();
} /* setup */
