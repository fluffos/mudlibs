inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Sea bottom");

    set_description(
	"You are at the bottom of the sea."
      );

    add_exit("up", "/room/sea");

    add_transient_object( ({ "/obj/monster"
	, ({ "set_name", "octopus" })
	, ({ "set_short", "An octopus" })
	, ({ "set_long", "A very big octopus with long arms, reaching for you." })
	, ({ "set_level", 9 })
	, ({ "set_hp", 100 })
	, ({ "set_wc", 12 })
	, ({ "set_al", -20 })
	, ({ "set_spell_mess1", "The octopus says: Mumble" })
	, ({ "set_spell_mess2", "The octopus says: I will convert you to a pulp!" })
	, ({ "set_chance", 20 })
	, ({ "add_transient_object", ({ "/obj/chest"
	    , ({ "add_transient_object", ({ "/obj/money"
		    , ({ "set_money", random(500) })
		  })
		})
	      })
	    , "Octopus picks up the chest."
	  })
      }) );
}
