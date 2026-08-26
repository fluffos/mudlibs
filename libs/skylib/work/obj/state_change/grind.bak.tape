::item "grind:Clover"::
::->result:: "/obj/reagents/generic_solid.ob"
::->factor:: 50.0
::->func:: ({
      (: $2->set_name( "clover" ) :),
      (: $2->set_short( "ground plant" ) :),
      (: $2->add_alias( "plant" ) :),
      (: $2->add_adjective( "ground" ) :),
      (: $2->set_long( "This is some ground plant material.  It looks "
            "like it might have been clover.\n" ) :),
      (: $2->set_medium_alias( "GroundClover" ) :),
      (: $2->set_decay_speed( 0 ) :)
   })
   
::item "grind:CoffeeBean"::
::->result:: "/obj/reagents/coffee.ob"
::->factor:: 5.0
::->func:: ({ })

::item "grind:Yarrow"::
::->result:: "/obj/reagents/generic_solid.ob"
::->factor:: 50.0
::->func:: ({
        (: $2->set_name("yarrow") :),
        (: $2->set_short("ground plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long("This is some ground plant material.  It looks "
                    "like it might've been yarrow.\n") :),
        (: $2->set_medium_alias("GroundYarrow") :),
        (: $2->add_eat_effect("/std/effects/ingested/cum_poison", 12) :),
        (: $2->add_eat_effect("/std/effects/ingested/basic_healing", 2) :),
        (: $2->set_decay_speed(0) :)
    })

   
::item "grind:Comfrey"::
::->result:: "/obj/reagents/generic_solid.ob"
::->factor:: 50.0
::->func:: ({
        (: $2->set_name("comfrey") :),
        (: $2->set_short("ground plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long("This is some ground plant material.  It looks "
                    "like it might've been comfrey.\n") :),
        (: $2->set_medium_alias("GroundComfrey") :),
        (: $2->add_eat_effect("/std/effects/ingested/cum_poison", 16) :),
        (: $2->add_eat_effect("/std/effects/ingested/basic_healing", 4) :),
        (: $2->set_decay_speed(0) :)
    })

::item "grind:KlatchianFleabane"::
::->result:: "/obj/reagents/generic_solid.ob"
::->factor:: 50.0
::->func:: ({
        (: $2->set_name("fleabane") :),
        (: $2->set_short("ground plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long("This is some ground plant material.  It looks "
                    "like it might've been Klatchian fleabane.\n") :),
        (: $2->set_medium_alias("GroundKlatchianFleabane") :),
        (: $2->set_decay_speed(0) :)
    })

::item "grind:GroundKlatchianFleabane"::
::->result:: "/obj/reagents/generic_solid.ob"
::->factor:: 1.2
::->func:: ({
        (: $2->set_name("fleabane") :),
        (: $2->set_short("powdered plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_adjective(({"powdered", "lavender"})) :),
        (: $2->set_long("This is some powdered plant material.  It has "
                    "a slight lavender hue with specs of orange.\n") :),
        (: $2->set_medium_alias("PowderedKlatchianFleabane") :),
        (: $2->set_decay_speed(0) :)
    })

::item "grind:StinkingMayweed"::
::->result:: "/obj/reagents/generic_solid.ob"
::->factor:: 50.0
::->func:: ({
        (: $2->set_name("mayweed") :),
        (: $2->set_short("ground plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_adjective("ground") :),
        (: $2->set_long("This is some ground plant material.  It looks "
                    "like it might've been stinking mayweed.\n") :),
        (: $2->set_medium_alias("GroundStinkingMayweed") :),
        (: $2->set_decay_speed(0) :)
    })

::item "grind:GroundStinkingMayweed"::
::->result:: "/obj/reagents/generic_solid.ob"
::->factor:: 1.2
::->func:: ({
        (: $2->set_name("mayweed") :),
        (: $2->set_short("powdered plant") :),
        (: $2->add_alias("plant") :),
        (: $2->add_adjective(({"powdered", "lavender"})) :),
        (: $2->set_long("This is some powdered plant material.  It has "
                    "a brownish green color, as well as a very strong "
                    "odor.\n") :),
        (: $2->set_medium_alias("PowderedStinkingMayweed") :),
        (: $2->set_decay_speed(0) :)
    })
    
::item "grind:Walnut"::
::->result:: "/obj/reagents/generic_solid.ob"
::->factor:: 50.0
::->func:: ({
      (: $2->set_name( "walnut" ) :),
      (: $2->set_short( "ground walnut" ) :),
      (: $2->add_adjective( "ground" ) :),
      (: $2->add_plural( "walnuts" ) :),
      (: $2->set_long( "This is a pile of ground walnut.\n" ) :),
      (: $2->set_medium_alias( "GroundWalnut" ) :),
   })


