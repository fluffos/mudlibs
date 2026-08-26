#include <state_change.h>
void dest_me() { destruct( this_object() ); }

class state_change item;
mapping data = ([ ]);

mixed data_return_0() {
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
      (: $2->set_name( "clover" ) :),
      (: $2->set_short( "ground plant" ) :),
      (: $2->add_alias( "plant" ) :),
      (: $2->add_plural( "plants" ) :),
      (: $2->add_adjective( "ground" ) :),
      (: $2->set_long( "This is $pile_size$ of ground plant, "
            "$amount_size$.  It looks "
            "like it might have been clover.\n" ) :),
      (: $2->set_medium_alias( "GroundClover" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["grind:Clover"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/coffee.ob";
  item->factor = 5.0;
  item->func = ({ });
  data["grind:CoffeeBean"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("yarrow") :),
        (: $2->set_short("ground plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
            "$amount_size$.  It looks "
                    "like it might've been yarrow.\n") :),
        (: $2->set_medium_alias("GroundYarrow") :),
        (: $2->add_eat_effect("/std/effects/ingested/cum_poison", 12) :),
        (: $2->add_eat_effect("/std/effects/ingested/basic_healing", 2) :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Yarrow"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("comfrey") :),
        (: $2->set_short("ground plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "like it might've been comfrey.\n") :),
        (: $2->set_medium_alias("GroundComfrey") :),
        (: $2->add_eat_effect("/std/effects/ingested/cum_poison", 16) :),
        (: $2->add_eat_effect("/std/effects/ingested/basic_healing", 4) :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Comfrey"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
   (: $2->set_name( "mushroom" ) :),
   (: $2->set_short( "ground mushroom" ) :),
   (: $2->add_alias( "madman" ) :),
   (: $2->add_adjective( "ground" ) :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  Judging from the "
          "green tint, it looks like it might've been Floppy Madman.\n" ) :),
   (: $2->set_medium_alias( "GroundFloppyMadman" ) :)
   });
  data["grind:FloppyMadman"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("fleabane") :),
        (: $2->set_short("ground plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "like it might've been Klatchian fleabane.\n") :),
        (: $2->set_medium_alias("GroundKlatchianFleabane") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:KlatchianFleabane"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.2;
  item->func = ({
        (: $2->set_name("fleabane") :),
        (: $2->set_short("powdered plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective(({"powdered", "lavender"})) :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "a slight lavender hue with specs of orange.\n") :),
        (: $2->set_medium_alias("PowderedKlatchianFleabane") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:GroundKlatchianFleabane"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("mayweed") :),
        (: $2->set_short("ground plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "like it might've been stinking mayweed.\n") :),
        (: $2->set_medium_alias("GroundStinkingMayweed") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:StinkingMayweed"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.2;
  item->func = ({
        (: $2->set_name("mayweed") :),
        (: $2->set_short("powdered plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective(({"powdered", "lavender"})) :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "a brownish green color, as well as a very strong "
                    "odor.\n") :),
        (: $2->set_medium_alias("PowderedStinkingMayweed") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:GroundStinkingMayweed"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
      (: $2->set_name( "walnut" ) :),
      (: $2->set_short( "ground walnut" ) :),
      (: $2->add_adjective( "ground" ) :),
      (: $2->add_plural( "walnuts" ) :),
      (: $2->set_long( "This is a pile of ground walnut.\n" ) :),
      (: $2->set_medium_alias( "GroundWalnut" ) :),
   });
  data["grind:Walnut"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
      (: $2->set_name( "garlic" ) :),
      (: $2->set_short( "ground garlic" ) :),
      (: $2->add_alias( "garlic" ) :),
      (: $2->add_adjective( "wild", "ground" ) :),
      (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  Judging from the "
         "smell, it must have been wild garlic.\n" ) :),
       (: $2->set_medium_alias( "GroundGarlic" ) :),
      (: $2->add_eat_effect("/std/effects/ingested/garlic_breath", 200) :),
      (: $2->set_decay_speed(0) :)
   });
  data["grind:WildGarlic"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("parsley") :),
        (: $2->set_short("ground parsley") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It smells "
                    "like it might've been parsley.\n") :),
        (: $2->set_medium_alias("GroundParsley") :),
        (: $2->add_eat_effect("/std/effects/ingested/breath_fresh", 2) :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Parsley"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("sage") :),
        (: $2->set_short("ground sage") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It smells "
                    "like it might've been sage.\n") :),
        (: $2->set_medium_alias("GroundSage") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Sage"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("rosemary") :),
        (: $2->set_short("ground rosemary") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It smells "
                    "like it might've been rosemary.\n") :),
        (: $2->set_medium_alias("GroundRosemary") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Rosemary"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("thyme") :),
        (: $2->set_short("ground thyme") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It smells "
                    "like it might've been thyme.\n") :),
        (: $2->set_medium_alias("GroundThyme") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Thyme"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("basil") :),
        (: $2->set_short("ground basil") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It smells "
                    "like it might've been basil.\n") :),
        (: $2->set_medium_alias("GroundBasil") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Basil"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("eyebright") :),
        (: $2->set_short("ground eyebright") :),
        (: $2->add_alias("plant") :),
        (: $2->add_plural( "plants" ) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It smells "
                    "like it might've been eyebright.\n") :),
        (: $2->set_medium_alias("GroundEyebright") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Eyebright"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 10.0;
  item->func = ({
        (: $2->set_name("spider") :),
        (: $2->set_short("ground arachnid") :),
        (: $2->add_alias("arachnid") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground arachnid, "
                    "$amount_size$.  It looks "
                    "very chitinous.\n") :),
        (: $2->set_medium_alias("GroundSpider") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Spider"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("fennel") :),
        (: $2->set_short("ground seeds") :),
        (: $2->add_alias(({"seed", "seeds"})) :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "like it might've been fennel.\n") :),
        (: $2->set_medium_alias("GroundFennel") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Fennel"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 10.0;
  item->func = ({
        (: $2->set_name("carrot") :),
        (: $2->set_short("ground carrot") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "very orange.\n") :),
        (: $2->set_medium_alias("GroundCarrot") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Carrot"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 10.0;
  item->func = ({
        (: $2->set_name("eye") :),
          (: $2->add_alias("eyes") :),
        (: $2->set_short("ground eyes") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "very bloody.\n") :),
        (: $2->set_medium_alias("GroundBunnyEyeball") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:BunnyEyeball"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 20.0;
  item->func = ({
        (: $2->set_name("crumbs") :),
        (: $2->set_short("molasses cookie crumbs") :),
        (: $2->add_adjective(({"molasses", "cookie"})) :),
        (: $2->set_long("This is some cookie crumbs.  Yum.\n") :),
        (: $2->set_medium_alias("GroundMolassesCookie") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:MolassesCookie"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 10.0;
  item->func = ({
        (: $2->set_name("radish") :),
        (: $2->set_short("ground radish") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "very orange.\n") :),
        (: $2->set_medium_alias("GroundRadish") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Radish"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 10.0;
  item->func = ({
        (: $2->set_name("parsnip") :),
        (: $2->set_short("ground parsnip") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "a bit like a pile of pine sawdust.\n") :),
        (: $2->set_medium_alias("GroundParsnip") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Parsnip"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("oregano") :),
        (: $2->set_short("ground oregano") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
                    "very Genuan.\n") :),
        (: $2->set_medium_alias("GroundOregano") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Oregano"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("foxglove") :),
        (: $2->set_short("ground foxglove") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  You can tell by the "
             "little purple flowers scattered in with the green stuff.\n") :),
        (: $2->set_medium_alias("GroundFoxglove") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Foxglove"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("violet") :),
        (: $2->set_short("ground violet") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of ground plant, "
                    "$amount_size$.  It looks "
             "very, well, violet.\n") :),
        (: $2->set_medium_alias("GroundViolet") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Violet"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 10.0;
  item->func = ({
        (: $2->set_name("cabbage") :),
        (: $2->set_short("shredded cabbage") :),
        (: $2->add_adjective("shredded") :),
        (: $2->set_long( "This is $pile_size$ of shredded cabbage, "
                    "$amount_size$.  "
             "Hopefully, not a sentinent one.\n") :),
        (: $2->set_medium_alias("GroundCabbage") :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Cabbage"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("garlic") :),
        (: $2->set_short("ground garlic") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long( "This is $pile_size$ of shredded cabbage, "
                    "$amount_size$.  Judging from "
           "the smell, it must have been garlic.\n" ) :),
        (: $2->set_medium_alias( "GroundGarlic" ) :),
        (: $2->add_eat_effect("/std/effects/ingested/garlic_breath", 200) :),
        (: $2->set_decay_speed(0) :)
    });
  data["grind:Garlic"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name( "peel" ) :),
        (: $2->set_short( "ground orange peel" ) :),
        (: $2->add_adjective( ({ "ground", "orange" }) ) :),
        (: $2->set_long( "This is $pile_size$ of ground orange peel, "
            "$amount_siuze$.  It is still "
            "a vibrant orange, the citric acid preserving both the colour "
            "and smell of the orange peel.\n" ) :),
        (: $2->set_medium_alias( "GroundOrangePeel" ) :),
        (: $2->set_decay_speed( 0 ) :)
    });
  data["grind:OrangePeel"] = item;
  item = new( class state_change );
  item->result = LIQUID_OBJ;
  item->factor = 0.5;
  item->func = ({
  (: $2->set_name("liquid") :),
  (: $2->set_short("cloudy yellowish liquid") :),
  (: $2->set_long("This is a cloudy, yellowish liquid, with faint "
      "traces of red swirls.\n") :),
  (: $2->add_adjective(({ "cloudy", "yellowish", "yellow" })) :)
});
  data["juice:snake left eye"] = item;
}

mixed data_return_1() {
  item = new( class state_change );
  item->result = LIQUID_OBJ;
  item->factor = 0.5;
  item->func = ({
  (: $2->set_name( "juice" ) :),
  (: $2->set_short( "jelly orange juice" ) :),
  (: $2->add_adjective( ({ "jelly", "orange" }) ) :),
  (: $2->set_long( "This is a delicious looking juice that "
      "appears to have been made from juicing up a jelly orange.\n" ) :),
  (: $2->set_medium_alias( "JellyOrangeJuice" ) :),
});
  data["juice:JellyOrange"] = item;
  item = new( class state_change );
  item->result = LIQUID_OBJ;
  item->factor = 1.0;
  item->func = ({
  (: $2->set_name( "juice" ) :),
  (: $2->set_short( "apple juice" ) :),
        (: $2->set_main_plural( "apple juices" ) :),
        (: $2->add_plural( "juices" ) :),
  (: $2->add_adjective( "apple" ) :),
  (: $2->set_long( "This is some transparent golden-brown "
                  "juice made from apples, "
                  "$amount_size$.\n" ) :),
  (: $2->set_medium_alias( "AppleJuice" ) :),
});
  data["juice:Apple"] = item;
  item = new( class state_change );
  item->result = LIQUID_OBJ;
  item->factor = 1.0;
  item->func = ({
        (: $2->set_name( "blackheart_juice" ) :),
        (: $2->set_short( "apple juice" ) :),
        (: $2->set_main_plural( "apple juices" ) :),
        (: $2->add_plural( "juices" ) :),
        (: $2->add_alias( "juice" ) :),
        (: $2->add_adjective( "apple" ) :),
        (: $2->set_long( "This is some dark, treacly, "
                        "sweet-smelling apple juice, "
                        "$amount_size$.\n" ) :),
        (: $2->set_medium_alias( "BlackheartJuice" ) :),
});
  data["juice:LancreBlackheart"] = item;
  item = new( class state_change );
  item->result = LIQUID_OBJ;
  item->factor = 1.0;
  item->func = ({
        (: $2->set_name( "disagreeable_juice" ) :),
        (: $2->set_short( "apple juice" ) :),
        (: $2->set_main_plural( "apple juices" ) :),
        (: $2->add_plural( "juices" ) :),
        (: $2->add_alias( "juice" ) :),
        (: $2->add_adjective( "apple" ) :),
        (: $2->set_long( "This is some thin and watery "
                        "sour-smelling apple juice, "
                        "$amount_size$.\n" ) :),
        (: $2->set_medium_alias( "DisagreeableJuice" ) :),
});
  data["juice:GoldenDisagreeable"] = item;
  item = new( class state_change );
  item->result = LIQUID_OBJ;
  item->factor = 1.0;
  item->func = ({
        (: $2->set_name( "billet_juice" ) :),
        (: $2->set_short( "apple juice" ) :),
        (: $2->set_main_plural( "apple juices" ) :),
        (: $2->add_plural( "juices" ) :),
        (: $2->add_alias( "juice" ) :),
        (: $2->add_adjective( "apple" ) :),
        (: $2->set_long( "This is some evil coloured, "
                        "bitter-smelling apple juice, "
                        "$amount_size$.\n" ) :),
        (: $2->set_medium_alias( "BilletJuice" ) :),
        (: $2->add_eat_effect( "/std/effects/ingested/nausea", 50 ) :),
});
  data["juice:GreenBillet"] = item;
  item = new( class state_change );
  item->result = "/std/object";
  item->factor = 1.1;
  item->func = ({
        (: $2->set_name("ice") :),
        (: $2->set_short("ice") :),
        (: $2->set_long("This is a chunk of ice.\n") :)
    });
  data["freeze:Water"] = item;
  item = new( class state_change );
  item->result = "/obj/food";
  item->factor = 0.9;
  item->func = ({
      (: $2->set_name( "potato" ) :),
      (: $2->set_short( "peeled potato" ) :),
      (: $2->add_adjective("peeled") :),
      (: $2->set_long( "This is a raw, peeled potato, ready for what next you do.\n" ) :),
      (: $2->set_medium_alias( "PeeledPotato" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["peel:Potato"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
      (: $2->set_name( "venom" ) :),
      (: $2->set_short( "yellow powder" ) :),
      (: $2->add_alias( "powder" ) :),
      (: $2->add_adjective( "yellow" ) :),
      (: $2->set_long( "This is some yellow powder.\n" ) :),
      (: $2->set_medium_alias( "PoisonVenom" ) :),
      (: $2->add_eat_effect("/std/effects/ingested/cum_poison", 16) :),
      (: $2->add_eat_effect("/std/effects/ingested/basic_healing", 4) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["pulverise:Venom"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("Catalyst") :),
        (: $2->set_short("white powder") :),
        (: $2->add_alias("powder") :),
        (: $2->add_adjective("white") :),
        (: $2->set_long("This is some white powder.\n") :),
        (: $2->set_medium_alias("PoisonCatalyst") :),
        (: $2->add_eat_effect("/std/effects/ingested/cum_poison", 12) :),
        (: $2->add_eat_effect("/std/effects/ingested/basic_healing", 2) :),
        (: $2->set_decay_speed(0) :)
    });
  data["pulverise:Catalyst"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("fang") :),
        (: $2->set_short("black powder") :),
        (: $2->add_alias("powder") :),
        (: $2->add_adjective("black") :),
        (: $2->set_long("This is some black powder.\n") :),
        (: $2->set_medium_alias("PoisonFang") :),
        (: $2->set_decay_speed(0) :)
    });
  data["pulverise:Fang"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 50.0;
  item->func = ({
        (: $2->set_name("leaf") :),
        (: $2->set_short("green powder") :),
        (: $2->add_alias("powder") :),
        (: $2->add_adjective("green") :),
        (: $2->set_long("This is some green powder.\n") :),
        (: $2->set_medium_alias("PoisonLeaf") :),
        (: $2->set_decay_speed(0) :)
    });
  data["pulverise:Leaf"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "carrot" ) :),
      (: $2->set_short( "sliced carrot" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some sliced carrots, little "
            "orange rings around lighter orange circles.\n" ) :),
      (: $2->set_medium_alias( "SlicedCarrot" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Carrot"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
        (: $2->set_name("cabbage") :),
        (: $2->set_short("shredded cabbage") :),
        (: $2->add_adjective("shredded") :),
        (: $2->set_long("This is some shredded cabbage.  "
             "Hopefully, not a sentinent one.\n") :),
        (: $2->set_medium_alias("GroundCabbage") :),
        (: $2->set_decay_speed(0) :)
    });
  data["slice:Cabbage"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "rhubarb" ) :),
      (: $2->set_short( "sliced rhubarb" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some sliced rhubarb, sweet little chunks "
          "perfect for a nice pie.\n" ) :),
      (: $2->set_medium_alias( "SlicedRhubarb" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Rhubarb"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "onion" ) :),
      (: $2->set_short( "sliced onion" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some finely sliced onions.  How very sad...  "
             "could make a bloke break down and sob...\n" ) :),
      (: $2->set_medium_alias( "SlicedOnion" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Onion"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "parsnip" ) :),
      (: $2->set_short( "sliced parsnip" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some parsnip slices, white and hot.\n" ) :),
      (: $2->set_medium_alias( "SlicedParsnip" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Parsnip"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "tomato" ) :),
      (: $2->set_short( "sliced tomato" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some sliced tomato, perfect for a sandwich, "
          "but needing more slicing for other purposes.\n" ) :),
      (: $2->set_medium_alias( "SlicedTomato" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Tomato"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "tomato" ) :),
      (: $2->set_short( "chopped tomato" ) :),
      (: $2->add_adjective( "chopped" ) :),
      (: $2->set_long( "This is some chopped tomato, suitable for cooking.\n" ) :),
      (: $2->set_medium_alias( "ChoppedTomato" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:SlicedTomato"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "potato" ) :),
      (: $2->set_short( "potato chunks" ) :),
      (: $2->add_alias(({"potato chunks", "potato chunk", "chunk", "chunks"})) :),
      (: $2->set_long( "These are some potato chunks.  They could do with "
          "some cooking ere they are eaten.\n" ) :),
      (: $2->set_medium_alias( "PotatoChunks" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:PeeledPotato"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "celery" ) :),
      (: $2->set_short( "sliced celery" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some sliced celery, perfect for a nice "
          "soup or stew.\n" ) :),
      (: $2->set_medium_alias( "SlicedCelery" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Celery"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "radish" ) :),
      (: $2->set_short( "sliced radish" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some sliced radish, the decorative vegetable.\n" ) :),
      (: $2->set_medium_alias( "SlicedRadish" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Radish"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "cucumber" ) :),
      (: $2->set_short( "cucumber slices" ) :),
      (: $2->add_alias(({"cucumber slices", "cucumber slice", "slice", "slices"})) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "These are the remains of a once mighty cucumber, now sliced.  "
          "Tis a great pity.\n" ) :),
      (: $2->set_medium_alias( "SlicedCucumber" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Cucumber"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "apple" ) :),
      (: $2->set_short( "sliced apple" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some sliced apple, sweet and delicious.\n" ) :),
      (: $2->set_medium_alias( "SlicedApple" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Apple"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({
      (: $2->set_name( "banana" ) :),
      (: $2->set_short( "sliced banana" ) :),
      (: $2->add_adjective( "sliced" ) :),
      (: $2->set_long( "This is some sliced banana.  It would go "
           "down a treat on buttered toast.\n" ) :),
      (: $2->set_medium_alias( "SlicedBanana" ) :),
      (: $2->set_decay_speed( 0 ) :)
   });
  data["slice:Banana"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_ore.ob";
  item->factor = 0.75;
  item->func = ({
        (: $2->set_name("ore") :),
        (: $2->set_short("refined iron ore") :),
        (: $2->add_adjective(({"refined", "iron"})) :),
        (: $2->set_long("This is $pile_size$ of refined iron ore, "
                        "$amount_size$.\n" ) :),
        (: $2->set_material("refined iron ore") :),
        (: $2->set_material("refined iron ore") :),
        (: $2->set_medium_alias("RefinedIronOre") :)
    });
  data["smelt:RedHotRawIronOre"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_ore.ob";
  item->factor = 0.75;
  item->func = ({
        (: $2->set_name("bloom") :),
        (: $2->set_short("pig of iron bloom") :),
        (: $2->add_adjective(({"pig", "of", "iron"})) :),
        (: $2->add_property("determinate", "a ") :),
        (: $2->add_alias("pig") :),
        (: $2->add_alias("iron") :),
        (: $2->set_material("iron bloom") :),
        (: $2->set_long("This is a lump of crude iron.\n") :),
        (: $2->set_medium_alias("IronBloom") :),
        (: $2->reset_continuous() :)
    });
  data["smelt:RedHotRefinedIronOre"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_ore.ob";
  item->factor = 0.5;
  item->func = ({
        (: $2->set_name("ingot") :),
        (: $2->set_short("wrought iron ingot") :),
        (: $2->add_adjective(({"wrought", "iron"})) :),
        (: $2->add_property("determinate", "a ") :),
        (: $2->add_alias("iron") :),
        (: $2->set_material("wrought iron") :),
        (: $2->set_long("This is an ingot of wrought iron.\n") :),
        (: $2->set_medium_alias("WroughtIron") :),
        (: $2->reset_continuous() :)
    });
  data["hammer:RedHotIronBloom"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({ (:
   $2->set_decay_speed(0),
   $2->set_medium_alias( "SmokeCrystals" ),
   $2->set_name( "smoke_crystal" ),
   $2->set_short( "tiny gray crystals" ),
   $2->set_main_plural( "tiny gray crystals" ),
   $2->set_weight_unit( ({ 1, 50 }) ),
   $2->add_alias( ({ "crystal", "crystals" }) ),
   $2->add_adjective( ({ "tiny", "gray" }) ),
   $2->set_long( "This is $pile_size$ of tiny, dark gray crystals, "
     "$amount_size$.  The individual crystals catch the light on "
     "their facets, and the pile seems to swirl, like smoke.\n" )
:) });
  data["grind:SmokeRock"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({ (:
   $2->set_decay_speed(0),
   $2->set_medium_alias( "CoatedSmokeCrystals" ),
   $2->set_name( "coated_smoke_crystals" ),
   $2->add_alias( "crystals" ),
   $2->set_short( "powdery black crystals" ),
   $2->add_adjective( ({ "powdery", "black" }) ),
   $2->set_long( "This is $pile_size$ of black crystals, about "
     "$amount_size$.  The crystals are covered in fine black powder.\n" )
:) });
  data["air-dry:DampCoatedSmokeCrystals"] = item;
  item = new( class state_change );
  item->result = "/obj/reagents/generic_solid.ob";
  item->factor = 1.0;
  item->func = ({ (:
   $2->set_decay_speed(0),
   $2->set_medium_alias( "InertSmokeCrystals" ),
   $2->set_name( "inert_smoke_crystals" ),
   $2->add_alias( "crystals" ),
   $2->set_short( "powdery black crystals" ),
   $2->add_adjective( ({ "powdery", "black" }) ),
   $2->set_long( "This is $pile_size$ of black crystals, about "
     "$amount_size$.  The crystals are covered in fine black powder.\n" )
:) });
  data["air-dry:DampInertSmokeCrystals"] = item;
}

mixed data_return() {
  data_return_0();
  data_return_1();
  return data;
}
