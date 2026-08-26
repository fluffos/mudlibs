#include <reaction.h>
void dest_me() { destruct( this_object() ); }

class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ item;
mapping data = ([ ]);

mixed data_return_0() {
  if (!mappingp(data["BlackheartJuice"])) data["BlackheartJuice"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 1.3, 2.1 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "blackheart_disagreeable_juice" ) :),
        (: $3->add_alias( "juice" ) :),
        (: $3->set_short( "apple juice" ) :),
        (: $3->set_main_plural( "apple juices" ) :),
        (: $3->add_plural( "juices" ) :),
        (: $3->add_adjective( "apple" ) :),
        (: $3->set_long( "This is some juice made from "
                        "apples, $amount_size$.  It has a "
                        "somewhat sweet, yet also slightly "
                        "sour, scent to it.\n" ) :),
        (: $3->set_medium_alias( "BlackheartDisagreeableJuice" ) :),
    });
  data["BlackheartJuice"]["DisagreeableJuice"] = item;
  if (!mappingp(data["BilletJuice"])) data["BilletJuice"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0.1, 0.4 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "pre_scumble_juice" ) :),
        (: $3->add_alias( "juice" ) :),
        (: $3->set_short( "apple juice" ) :),
        (: $3->set_main_plural( "apple juices" ) :),
        (: $3->add_plural( "juices" ) :),
        (: $3->add_adjective( "apple" ) :),
        (: $3->set_long( "This is some juice made from "
                        "apples, $amount_size$.  It has a "
                        "familiar scent, an almost sickly "
                        "sweetness combined with a certain "
                        "tartness yet with bitter overtones.  "
                        "It smells rather like scumble might, "
                        "if it didn't have alcohol in it.\n" ) :),
        (: $3->set_medium_alias( "PreScumbleJuice" ) :),
    });
  data["BilletJuice"]["BlackheartDisagreeableJuice"] = item;
  if (!mappingp(data["BatGuano"])) data["BatGuano"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0.8, 1.2 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "GuanoSolution" ),
   $3->set_name( "guano_solution" ),
   $3->add_alias( "sludge" ),
   $3->set_short( "thick brown sludge" ),
   $3->add_adjective( ({ "thick", "brown" }) ),
   $3->set_long( "This is some thick brown sludge, streaked through with "
     "white.  The smell is... prominent.\n" )
:) });
  data["BatGuano"]["Water"] = item;
  if (!mappingp(data["GroundDeadlyNightshade"])) data["GroundDeadlyNightshade"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 1.0/600, 1.0/1000 });
  item->result = "/obj/reagents/transient_liquid.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("coffee") :),
        (: $3->set_short("coffee") :),
        (: $3->set_long("This is some freshly made coffee, $amount_size$.\n")
            :),
        (: $3->set_progress_msg( ({
            ({0, 0}),
            ({0, 0}),
            ({"The liquid in the @@short:#env#@@ darkens slightly.\n", ({
                "set_medium_alias:#obj#|TransientCoffee"})}),
            ({0, 0}),
            ({0, 0})
            }) ) :),
        (: $3->set_medium_alias("PreTransientCoffee") :),
        (: $3->add_eat_effect("/std/effects/ingested/poison.c", 10) :),
        (: $3->set_duration(30) :),
        (: $3->set_final("morph") :),
        (: $3->set_result("/obj/reagents/poison_coffee.ob") :),
        (: $3->set_result_amt(1.0) :),
        (: $3->set_result_alias("PoisonCoffee") :),
        (: $3->set_continuous() :),
        (: $3->set_liquid() :),
        (: $3->start_reaction() :)
    });
  data["GroundDeadlyNightshade"]["LiquidCoffee"] = item;
  if (!mappingp(data["TransientCoffee"])) data["TransientCoffee"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0, 2500 });
  item->result = "/obj/reagents/shimmer.ob";
  item->result_amt = 1.0;
  item->message = "Something begins to happen in the @@short:#env#@@...\n";
  item->func = ({
        (: $3->set_short("dimly glowing liquid") :),
        (: $3->set_duration(20) :),
        (: $3->set_final("morph") :),
        (: $3->set_result("/obj/reagents/panic.ob") :),
        (: $3->set_result_amt(1.0) :),
        (: $3->set_result_alias("PanicPotion") :),
        (: $3->start_reaction() :)
    });
  data["TransientCoffee"]["TransientPanic"] = item;
  if (!mappingp(data["TransientCoffee"])) data["TransientCoffee"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0, 2500 });
  item->result = "/obj/reagents/shimmer.ob";
  item->result_amt = 1.0;
  item->message = "Something begins to happen in the @@short:#env#@@...\n";
  item->func = ({
        (: $3->set_short("dimly glowing liquid") :),
        (: $3->set_duration(20) :),
        (: $3->set_final("morph") :),
        (: $3->set_result("/obj/reagents/perception.ob") :),
        (: $3->set_result_amt(1.0) :),
        (: $3->set_result_alias("PerceptionPotion") :),
        (: $3->start_reaction() :)
    });
  data["TransientCoffee"]["TransientPerception"] = item;
  if (!mappingp(data["GroundCoffee"])) data["GroundCoffee"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 1.0/60, 1.0/40 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("coffee") :),
        (: $3->set_short("coffee") :),
        (: $3->set_long("This is some freshly made coffee, $amount_size$.\n")
            :),
        (: $3->add_plural("coffee") :),
        (: $3->set_medium_alias("LiquidCoffee") :),
        (: tell_room($5, "The " + $2->short() + " in " + $4->the_short() +
            " turns brown.\n") :),
        (: $3->set_medium_alias("LiquidCoffee") :)
    });
  data["GroundCoffee"]["Water"] = item;
  if (!mappingp(data["GroundComfreyLeaf"])) data["GroundComfreyLeaf"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0/400;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("tea") :),
        (: $3->set_short("pale tea") :),
        (: $3->set_long("This is a pale coloured tea, $pile_size$.") :),
        (: $3->set_medium_alias("ComfreyTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/basic_healing",
                this_player()->query_skill_bonus(
                        "magic.methods.physical.brewing")/10)
        :)
    });
  data["GroundComfreyLeaf"]["Water"] = item;
  if (!mappingp(data["ComfreyTea"])) data["ComfreyTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 400.0, 2400.0 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("tea") :),
        (: $3->set_short("pale tea") :),
        (: $3->set_long("This is a pale coloured tea, $pile_size$.") :),
        (: $3->set_medium_alias("ComfreyYarrowTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/basic_healing",
                $1->query_eat_effects()["/std/effects/ingested/basic_healing"]
                  * 2 * $2->query_amount())
        :)
    });
  data["ComfreyTea"]["GroundYarrowLeaf"] = item;
  if (!mappingp(data["GroundGarlic"])) data["GroundGarlic"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 200/2800.0;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
     (: $3->set_name( "syrup" ) :),
     (: $3->set_short( "golden syrup" ) :),
     (: $3->set_long( "This is a sticky looking golden syrup.  "
                      "It smells strongly of garlic.\n") :),
     (: $3->set_medium_alias( "ColdCureSyrup" ) :),
     (: $3->add_eat_effect("/std/effects/ingested/cold_cure",
          ((this_player()->query_skill_bonus(
            "magic.methods.physical.healing")/5)+ 
           (this_player()->query_skill_bonus(
            "magic.methods.physical.brewing")/3))) :),
     (: $3->add_eat_effect("/std/effects/ingested/garlic_breath",
          this_player()->query_skill_bonus(
            "magic.methods.physical.healing")) :)
   });
  data["GroundGarlic"]["Honey"] = item;
  if (!mappingp(data["GroundCabbage"])) data["GroundCabbage"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1;
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "vegetable" ) :),
        (: $3->set_short( "shredded vegetables" ) :),
        (: $3->add_adjective(({"shredded"})) :),
        (: $3->add_alias("vegetables") :),
        (: $3->set_long("This is some shredded vegetables.  Needs something more...\n") :),
        (: $3->set_medium_alias("ShreddedVegetables") :),
    });
  data["GroundCabbage"]["GroundCarrot"] = item;
  if (!mappingp(data["RanchSaladDressing"])) data["RanchSaladDressing"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1,0.5});
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "coleslaw" ) :),
        (: $3->set_short( "coleslaw" ) :),
        (: $3->set_long("This is some delicious coleslaw.  Yum!!!\n") :),
        (: $3->set_medium_alias("Coleslaw") :),
    });
  data["RanchSaladDressing"]["ShreddedVegetables"] = item;
  if (!mappingp(data["GroundMolassesCookie"])) data["GroundMolassesCookie"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.7, 3.0});
  item->result = "/obj/reagents/generic_dough.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "dough" ) :),
        (: $3->set_short( "medicinal dough" ) :),
        (: $3->add_adjective(({"medicinal"})) :),
        (: $3->set_long("This is a medicinal dough.  It smells of molasses.\n") :),
        (: $3->set_medium_alias("MedicinalDough") :),
    });
  data["GroundMolassesCookie"]["LispMedicine"] = item;
  if (!mappingp(data["GroundRadish"])) data["GroundRadish"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.4,0.6});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "pale pink tea" ) :),
        (: $3->add_adjective(({"pale", "pink"})) :),
        (: $3->set_long("This is a pale pink tea.\n") :),
        (: $3->set_medium_alias("RadishTea") :),
    });
  data["GroundRadish"]["Water"] = item;
  if (!mappingp(data["GroundParsnip"])) data["GroundParsnip"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.4,0.6});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "milky white tea" ) :),
        (: $3->add_adjective(({"milky", "white"})) :),
        (: $3->set_long("This is a milky white tea.\n") :),
        (: $3->set_medium_alias("ParsnipTea") :),
    });
  data["GroundParsnip"]["Water"] = item;
  if (!mappingp(data["GroundRadish"])) data["GroundRadish"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.2,0.6});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "milky pink tea" ) :),
        (: $3->add_adjective(({"milky","pink"})) :),
        (: $3->set_long("This is a milky pink tea.\n") :),
        (: $3->set_medium_alias("ParsnipRadishTea") :),
    });
  data["GroundRadish"]["ParsnipTea"] = item;
  if (!mappingp(data["GroundParsnip"])) data["GroundParsnip"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.2,0.6});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "milky pink tea" ) :),
        (: $3->add_adjective(({"milky","pink"})) :),
        (: $3->set_long("This is a milky pink tea.\n") :),
        (: $3->set_medium_alias("ParsnipRadishTea") :),
    });
  data["GroundParsnip"]["RadishTea"] = item;
  if (!mappingp(data["ParsnipTea"])) data["ParsnipTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.8,1.2});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "milky pink tea" ) :),
        (: $3->add_adjective(({"milky","pink"})) :),
        (: $3->set_long("This is a milky pink tea.\n") :),
        (: $3->set_medium_alias("ParsnipRadishTea") :),
    });
  data["ParsnipTea"]["RadishTea"] = item;
  if (!mappingp(data["GroundOregano"])) data["GroundOregano"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1, 0.9});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "olive-green tea" ) :),
        (: $3->add_adjective(({"olive-green"})) :),
        (: $3->set_long("This is an olive-green tea.\n") :),
        (: $3->set_medium_alias("LispMedicine") :),
    });
  data["GroundOregano"]["ParsnipRadishTea"] = item;
  if (!mappingp(data["FungoidJuice"])) data["FungoidJuice"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 1.8/1, 2.2/1 });
  item->result = "/obj/reagents/generic_salve.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("paste") :),
        (: $3->set_short("sticky grey paste") :),
        (: $3->set_long("This is $pile_size$ of sticky grey paste, " +
                        "$amount_size$.\n") :),
        (: $3->set_medium_alias("PastyFungoidJuice") :),
        (: $3->add_adjective("sticky") :),
        (: $3->add_adjective("grey") :),
        (: $3->add_apply_effect("/std/effects/external/fungus_cure",
                this_player()->query_skill_bonus(
                        "magic.methods.physical.brewing")/10)
        :)
    });
  data["FungoidJuice"]["Water"] = item;
  if (!mappingp(data["GroundComfrey"])) data["GroundComfrey"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0/400;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("tea") :),
        (: $3->set_short("pale tea") :),
        (: $3->set_long("This is a pale coloured tea, $pile_size$.") :),
        (: $3->set_medium_alias("ComfreyTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/basic_healing",
                this_player()->query_skill_bonus(
                        "magic.methods.physical.brewing")/10)
        :)
    });
  data["GroundComfrey"]["Water"] = item;
  if (!mappingp(data["ComfreyTea"])) data["ComfreyTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 400.0, 2400.0 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("tea") :),
        (: $3->set_short("pale tea") :),
        (: $3->set_long("This is a pale coloured tea, $pile_size$.") :),
        (: $3->set_medium_alias("ComfreyYarrowTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/basic_healing",
                $1->query_eat_effects()["/std/effects/ingested/basic_healing"]
                  * this_player()->query_skill_bonus(
                        "magic.methods.physical.brewing")/10)
        :)
    });
  data["ComfreyTea"]["GroundYarrow"] = item;
  if (!mappingp(data["Kibrit"])) data["Kibrit"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1;
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "powder" ) :),
        (: $3->set_short( "light yellow powder" ) :),
        (: $3->add_adjective(({"light", "yellow"})) :),
        (: $3->set_long("This is some light yellow powder, $amount_size$.\n") :),
        (: $3->set_medium_alias("KibritTalcum") :),
    });
  data["Kibrit"]["TalcumPowder"] = item;
  if (!mappingp(data["AurumPotable"])) data["AurumPotable"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1;
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "solution" ) :),
        (: $3->set_short( "smelly milky-golden solution" ) :),
        (: $3->add_adjective(({"smelly", "milky-golden"})) :),
        (: $3->set_long("This is a smelly, milky-golden solution, "
             "$amount_size$.\n") :),
        (: $3->add_eat_effect("/std/effects/ingested/frog_repellent",
              100) :),
        (: $3->set_medium_alias("FrogRepellent") :),
    });
  data["AurumPotable"]["KibritTalcum"] = item;
  if (!mappingp(data["GroundVenom"])) data["GroundVenom"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0/400;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("poison") :),
        (: $3->set_short("deadly poison") :),
        (: $3->set_long("This is a pale coloured tea, $pile_size$.") :),
        (: $3->set_medium_alias("VenomPoison") :),
        (: $3->add_eat_effect("/std/effects/ingested/basic_healing",
                this_player()->query_skill_bonus(
                        "magic.methods.physical.brewing")/10)
        :)
    });
  data["GroundVenom"]["Water"] = item;
  if (!mappingp(data["VenomPoison"])) data["VenomPoison"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 400.0, 2400.0 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("poison") :),
        (: $3->set_short("deadly poison") :),
        (: $3->set_long("This is a pale coloured tea, $pile_size$.") :),
        (: $3->set_medium_alias("VenomCatalystPoison") :),
        (: $3->add_eat_effect("/std/effects/ingested/basic_healing",
                $1->query_eat_effects()["/std/effects/ingested/basic_healing"]
                  * this_player()->query_skill_bonus(
                        "magic.methods.physical.brewing")/10)
        :)
    });
  data["VenomPoison"]["GroundCatalyst"] = item;
  if (!mappingp(data["PoisonFang"])) data["PoisonFang"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0/400;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("poison") :),
        (: $3->set_short("deadly poison") :),
        (: $3->set_long("This is a pale coloured tea, $pile_size$.") :),
        (: $3->set_medium_alias("FangExtract") :),
        (: $3->add_eat_effect("/std/effects/ingested/basic_healing",
                this_player()->query_skill_bonus(
                        "magic.methods.physical.brewing")/10)
        :)
    });
  data["PoisonFang"]["Water"] = item;
  if (!mappingp(data["FangExtract"])) data["FangExtract"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 400.0, 2400.0 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("poison") :),
        (: $3->set_short("deadly poison") :),
        (: $3->set_long("This is a pale coloured tea, $pile_size$.") :),
        (: $3->set_medium_alias("FangLeafPoison") :),
        (: $3->add_eat_effect("/std/effects/poisons/spider_venom",
                $1->query_eat_effects()["/std/effects/poisons/spider_venom"]
                  * this_player()->query_skill_bonus(
                        "covert.items.poisons")/10)
        :)
    });
  data["FangExtract"]["PoisonLeaf"] = item;
  if (!mappingp(data["Coal"])) data["Coal"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 1, 3 });
  item->result = "/obj/mineral.c";
  item->result_amt = 0.33;
  item->func = ({ 
              (: $3->set_name("ore") :),
              (: $3->set_short("refined iron ore") :),
              (: $3->add_adjective(({"refined", "iron"})) :),
              (: $3->set_long("This iron ore has been roasted to "
                       "remove some impurities, $pile_size$.\n") :),
              (: $3->set_medium_alias("RefinedIronOre") :),
              (: $3->set_material("refined iron ore") :)
           });
  data["Coal"]["RawIronOre"] = item;
  if (!mappingp(data["GroundKlatchianFleabane"])) data["GroundKlatchianFleabane"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 1.0/50, 5.0/50 });
  item->result = "/obj/reagents/generic_salve.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("paste") :),
        (: $3->set_short("lavender paste") :),
        (: $3->set_long("This is $pile_size$ of lavender paste, " +
                        "$amount_size$.\n") :),
        (: $3->set_medium_alias("PastyKlatchianFleabane") :),
        (: $3->add_adjective("lavender") :)
    });
  data["GroundKlatchianFleabane"]["Water"] = item;
}

mixed data_return_1() {
  if (!mappingp(data["GroundStinkingMayweed"])) data["GroundStinkingMayweed"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 1.0/50, 5.0/50 });
  item->result = "/obj/reagents/flea_salve.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_medium_alias("FleaSalve") :),
        (: $3->add_apply_effect("/std/effects/external/flea_cure",
                this_player()->query_skill_bonus(
                        "magic.methods.physical.healing")/20)
        :)
    });
  data["GroundStinkingMayweed"]["PastyKlatchianFleabane"] = item;
  if (!mappingp(data["GroundParsley"])) data["GroundParsley"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1,0.2});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "dark green tea" ) :),
        (: $3->add_adjective(({"dark", "green"})) :),
        (: $3->set_long("This is a dark green, fresh-smelling tea.\n") :),
        (: $3->set_medium_alias("ParsleyTea") :),
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/breath_fresh") :),
    });
  data["GroundParsley"]["Water"] = item;
  if (!mappingp(data["GroundSage"])) data["GroundSage"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.4,0.6});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "grey-green tea" ) :),
        (: $3->add_adjective(({"grey-green"})) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_long("This is a grey-green tea.\n") :),
        (: $3->set_medium_alias("SageTea") :),
    });
  data["GroundSage"]["Water"] = item;
  if (!mappingp(data["FeatherStir"])) data["FeatherStir"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 0.25;
  item->result = LIQUID_OBJ;
  item->result_amt = 0.8;
  item->func = ({
        (: $3->set_name( "potion" ) :),
        (: $3->set_short( "teal green potion" ) :),
        (: $3->add_adjective(({"teal","green"})) :),
        (: $3->set_long("This is a teal green potion.\n") :),
        (: $3->set_medium_alias("SageIntPotion") :),
        (: $3->add_eat_effect("/std/effects/ingested/int_bonus",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/10) :),
    });
  data["FeatherStir"]["SageTea"] = item;
  if (!mappingp(data["GroundSpider"])) data["GroundSpider"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1,0.2});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "purple tea" ) :),
        (: $3->add_adjective(({"purple"})) :),
        (: $3->set_long("This is a purple tea.\n") :),
        (: $3->set_medium_alias("SpiderTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/cum_poison", 5) :),
    });
  data["GroundSpider"]["Water"] = item;
  if (!mappingp(data["GroundBasil"])) data["GroundBasil"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1,0.2});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "green-blue tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->add_adjective(({"green-blue"})) :),
        (: $3->set_long("This is a green-blue tea.\n") :),
        (: $3->set_medium_alias("BasilTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["GroundBasil"]["Water"] = item;
  if (!mappingp(data["GroundThyme"])) data["GroundThyme"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.3,0.6});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_short( "greenish tea" ) :),
        (: $3->add_adjective(({"greenish"})) :),
        (: $3->set_long("This is a greenish tea.\n") :),
        (: $3->set_medium_alias("ThymeTea") :),
    });
  data["GroundThyme"]["Water"] = item;
  if (!mappingp(data["BasilTea"])) data["BasilTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({5,10});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "brown tea" ) :),
        (: $3->add_adjective(({"brown"})) :),
        (: $3->set_long("This is a brown tea.\n") :),
        (: $3->set_medium_alias("BasilSpiderTea") :),
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/cum_poison", 5) :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["BasilTea"]["GroundSpider"] = item;
  if (!mappingp(data["FennelTea"])) data["FennelTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({5,10});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "muddy tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->add_adjective(({"muddy"})) :),
        (: $3->set_long("This is a muddy tea.\n") :),
        (: $3->set_medium_alias("FennelSpiderTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/cum_poison", 5) :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["FennelTea"]["GroundSpider"] = item;
  if (!mappingp(data["GroundFennel"])) data["GroundFennel"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1,0.2});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "muddy tea" ) :),
        (: $3->add_adjective(({"muddy"})) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_long("This is a muddy tea.\n") :),
        (: $3->set_medium_alias("FennelSpiderTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/cum_poison", 5) :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["GroundFennel"]["SpiderTea"] = item;
  if (!mappingp(data["BasilSpiderTea"])) data["BasilSpiderTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({6.67,20});
  item->result = "/obj/reagents/antidote_elixir";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/poison_antidote",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/2 +
    random(this_player()->
    query_skill_bonus("magic.methods.physical.brewing") ) ) :),
    });
  data["BasilSpiderTea"]["GroundFennel"] = item;
  if (!mappingp(data["BasilFennelTea"])) data["BasilFennelTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({6.67,20});
  item->result = "/obj/reagents/antidote_elixir";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/poison_antidote",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/2 +
    random(this_player()->
    query_skill_bonus("magic.methods.physical.brewing") ) )  :),
    });
  data["BasilFennelTea"]["GroundSpider"] = item;
  if (!mappingp(data["FennelSpiderTea"])) data["FennelSpiderTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({6.67,20});
  item->result = "/obj/reagents/antidote_elixir";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/poison_antidote",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/2 +
    random(this_player()->
    query_skill_bonus("magic.methods.physical.brewing") ) ) :),
    });
  data["FennelSpiderTea"]["GroundBasil"] = item;
  if (!mappingp(data["BasilSpiderTea"])) data["BasilSpiderTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({1.7,2.3});
  item->result = "/obj/reagents/antidote_elixir";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/poison_antidote",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/2 +
    random(this_player()->
    query_skill_bonus("magic.methods.physical.brewing") ) ) :),
    });
  data["BasilSpiderTea"]["FennelTea"] = item;
  if (!mappingp(data["BasilFennelTea"])) data["BasilFennelTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({1.7,2.3});
  item->result = "/obj/reagents/antidote_elixir";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/poison_antidote",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/2 +
    random(this_player()->
    query_skill_bonus("magic.methods.physical.brewing") ) ) :),
    });
  data["BasilFennelTea"]["SpiderTea"] = item;
  if (!mappingp(data["BasilTea"])) data["BasilTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({1.7,2.3});
  item->result = "/obj/reagents/antidote_elixir";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/poison_antidote",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/2 +
    random(this_player()->
    query_skill_bonus("magic.methods.physical.brewing") ) ) :),
    });
  data["BasilTea"]["FennelSpiderTea"] = item;
  if (!mappingp(data["GroundFennel"])) data["GroundFennel"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1,0.2});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "pale yellow tea" ) :),
        (: $3->add_adjective(({"pale yellow"})) :),
        (: $3->set_long("This is a pale yellow tea.\n") :),
        (: $3->set_medium_alias("FennelTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["GroundFennel"]["Water"] = item;
  if (!mappingp(data["BasilTea"])) data["BasilTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({5,10});
  item->result = LIQUID_OBJ;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "light green tea" ) :),
        (: $3->add_adjective(({"light","green"})) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_long("This is a light green tea.\n") :),
        (: $3->set_medium_alias("BasilFennelTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["BasilTea"]["GroundFennel"] = item;
  if (!mappingp(data["GroundBasil"])) data["GroundBasil"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1,0.2});
  item->result = LIQUID_OBJ;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "brown tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->add_adjective(({"brown"})) :),
        (: $3->set_long("This is a brown tea.\n") :),
        (: $3->set_medium_alias("BasilSpiderTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/cum_poison", 5) :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["GroundBasil"]["SpiderTea"] = item;
  if (!mappingp(data["FennelTea"])) data["FennelTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({5,10});
  item->result = LIQUID_OBJ;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "light green tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->add_adjective(({"light","green"})) :),
        (: $3->set_long("This is a light green tea.\n") :),
        (: $3->set_medium_alias("BasilFennelTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["FennelTea"]["GroundBasil"] = item;
  if (!mappingp(data["BasilTea"])) data["BasilTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "light green tea" ) :),
        (: $3->add_adjective(({"light","green"})) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_long("This is a light green tea.\n") :),
        (: $3->set_medium_alias("BasilFennelTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["BasilTea"]["FennelTea"] = item;
  if (!mappingp(data["BasilTea"])) data["BasilTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "brown tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->add_adjective(({"brown"})) :),
        (: $3->set_long("This is a brown tea.\n") :),
        (: $3->set_medium_alias("BasilSpiderTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/cum_poison", 5) :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["BasilTea"]["SpiderTea"] = item;
  if (!mappingp(data["FennelTea"])) data["FennelTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "muddy tea" ) :),
        (: $3->add_adjective(({"muddy"})) :),
        (: $3->set_long("This is a muddy tea.\n") :),
        (: $3->set_medium_alias("FennelSpiderTea") :),
        (: $3->add_property("potion",1) :),
        (: $3->add_eat_effect("/std/effects/ingested/cum_poison", 5) :),
        (: $3->add_eat_effect("/std/effects/ingested/weak_poison_cure") :),
    });
  data["FennelTea"]["SpiderTea"] = item;
  if (!mappingp(data["GroundEyebright"])) data["GroundEyebright"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.6,0.8});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "yellow tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->add_adjective(({"yellow"})) :),
        (: $3->set_long("This is a yellow tea.\n") :),
        (: $3->set_medium_alias("EyebrightTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/blind_protect"):),
    });
  data["GroundEyebright"]["Water"] = item;
  if (!mappingp(data["GroundCarrot"])) data["GroundCarrot"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.6,0.8});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "orange tea" ) :),
        (: $3->add_adjective(({"orange"})) :),
        (: $3->set_long("This is a orange tea.\n") :),
        (: $3->set_medium_alias("CarrotTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/blind_protect") :),
    });
  data["GroundCarrot"]["Water"] = item;
  if (!mappingp(data["CarrotTea"])) data["CarrotTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_short( "yellow-orange tea" ) :),
        (: $3->add_adjective(({"yellow-orange"})) :),
        (: $3->set_long("This is a yellow-orange tea.\n") :),
        (: $3->set_medium_alias("EyebrightCarrotTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/blind_protect"):),
    });
  data["CarrotTea"]["EyebrightTea"] = item;
  if (!mappingp(data["CarrotTea"])) data["CarrotTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({1.25,1.6667});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "yellow-orange tea" ) :),
        (: $3->add_adjective(({"yellow-orange"})) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_long("This is a yellow-orange tea.\n") :),
        (: $3->set_medium_alias("EyebrightCarrotTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/blind_protect") :),
    });
  data["CarrotTea"]["GroundEyebright"] = item;
  if (!mappingp(data["EyebrightTea"])) data["EyebrightTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({1.25,1.6667});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "yellow-orange tea" ) :),
        (: $3->add_adjective(({"yellow-orange"})) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_long("This is a yellow-orange tea.\n") :),
        (: $3->set_medium_alias("EyebrightCarrotTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/blind_protect") :),
    });
  data["EyebrightTea"]["GroundCarrot"] = item;
  if (!mappingp(data["EyebrightCarrotTea"])) data["EyebrightCarrotTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({3.0,4.0});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_short( "red-orange tea" ) :),
        (: $3->add_adjective(({"red-orange"})) :),
        (: $3->set_long("This is a red-orange tea.\n") :),
        (: $3->set_medium_alias("EyebrightCarrotBunnyEyeballTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/blind_protect",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/10) :),
    });
  data["EyebrightCarrotTea"]["GroundBunnyEyeball"] = item;
  if (!mappingp(data["BunnyEyeballTea"])) data["BunnyEyeballTea"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({1.5,2.0});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->set_short( "red-orange tea" ) :),
        (: $3->add_adjective(({"red-orange"})) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_long("This is a red-orange tea.\n") :),
        (: $3->set_medium_alias("EyebrightCarrotBunnyEyeballTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/blind_protect",
    this_player()->
    query_skill_bonus("magic.methods.physical.brewing")/10) :),
    });
  data["BunnyEyeballTea"]["EyebrightCarrotTea"] = item;
  if (!mappingp(data["GroundBunnyEyeball"])) data["GroundBunnyEyeball"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "tea" ) :),
        (: $3->add_property("potion",1) :),
        (: $3->set_short( "red tea" ) :),
        (: $3->add_adjective(({"red"})) :),
        (: $3->set_long("This is a red tea.\n") :),
        (: $3->set_medium_alias("BunnyEyeballTea") :),
        (: $3->add_eat_effect("/std/effects/ingested/blind_protect") :),
    });
  data["GroundBunnyEyeball"]["Water"] = item;
  if (!mappingp(data["DriedSlug"])) data["DriedSlug"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({0.1,0.2});
  item->result = "/d/sur/Scrogden/items/slugsoup";
  item->result_amt = 1.0;
  data["DriedSlug"]["Water"] = item;
  if (!mappingp(data["GumArabic"])) data["GumArabic"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0.8, 1.2 });
  item->result = LIQUID_OBJ;
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "WateredGumArabic" ),
   $3->set_name( "watered_gum_arabic" ),
   $3->add_alias( "syrup" ),
   $3->set_short( "runny syrup" ),
   $3->set_main_plural( "runny syrups" ),
   $3->add_adjective( "runny" ),
   $3->set_long( "This looks like some sort of gluey substance that's "
     "been thinned with water, $amount_size$. It's runny, but still "
     "fairly thick.\n" )
:) });
  data["GumArabic"]["Water"] = item;
  if (!mappingp(data["GumArabic"])) data["GumArabic"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 1.0/12, 1.0/4 });
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1;
  item->func = ({ (:
   $3->reset_continuous(),
   $3->set_amount_types( ([
     "tiny lump"  : ({ 20,   "tiny lumps" }),
     "small lump" : ({ 100,  "small lumps" }),
     "lump"       : ({ 400,  "smallish lumps" }),
     "large lump" : ({ 1000, "large lumps" }),
   ]) ),
   $3->set_decay_speed(0),
   $3->set_medium_alias( "TooStickySmokeCrystals" ),
   $3->set_name( "too_sticky_smoke_crystals" ),
   $3->add_alias( "lump" ),
   $3->set_short( "sticky grey lump" ),
   $3->set_main_plural( "sticky grey lumps" ),
   $3->add_adjective( ({ "sticky", "grey" }) ),
   $3->set_long( "This is a sticky grey lump of ground-up rock, bound "
     "together with some sort of thick syrup.\n" )
:) });
  data["GumArabic"]["SmokeCrystals"] = item;
  if (!mappingp(data["SmokeCrystals"])) data["SmokeCrystals"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0.2, 10.0 });
  item->result = "/obj/reagents/generic_salve.ob";
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "DissolvedSmokeCrystals" ),
   $3->set_name( "dissolved_smoke_crystals" ),
   $3->add_alias( "gloop" ),
   $3->set_short( "sticky grey gloop" ),
   $3->set_main_plural( "sticky grey gloops" ),
   $3->add_adjective( ({ "sticky", "grey" }) ),
   $3->set_long( "This is $pile_size$ of sticky grey gloop, $amount_size$."
     "  It looks like it might have once been solid mineral of some "
     "description; there is the ocassional crystal embedded in the "
     "mixture.\n" )
:) });
  data["SmokeCrystals"]["Water"] = item;
}

mixed data_return_2() {
  if (!mappingp(data["SmokeCrystals"])) data["SmokeCrystals"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 10.0;
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "StickySmokeCrystals" ),
   $3->set_name( "sticky_smoke_crystals" ),
   $3->add_alias( "crystals" ),
   $3->set_short( "sticky gray crystals" ),
   $3->add_adjective( ({ "sticky", "gray" }) ),
   $3->set_long( "This is $pile_size$ of sticky, dark grey crystals, about "
     "$amount_size$.  The crystals are quite sticky, but not so much so "
     "that they bind together.\n" )
:) });
  data["SmokeCrystals"]["WateredGumArabic"] = item;
  if (!mappingp(data["StickySmokeCrystals"])) data["StickySmokeCrystals"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0.2, 10.0 });
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "DissolvedSmokeCrystals" ),
   $3->set_name( "dissolved_smoke_crystals" ),
   $3->add_alias( "gloop" ),
   $3->set_short( "sticky grey gloop" ),
   $3->set_main_plural( "sticky grey gloops" ),
   $3->add_adjective( ({ "sticky", "grey" }) ),
   $3->set_long( "This is $pile_size$ of sticky grey gloop, $amount_size$."
     "  It looks like it might have once been solid mineral of some "
     "description; there is the ocassional crystal embedded in the "
     "mixture.\n" )
:) });
  data["StickySmokeCrystals"]["WateredGumArabic"] = item;
  if (!mappingp(data["PowderedCharcoal"])) data["PowderedCharcoal"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0/10;
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "DampInertSmokeCrystals" ),
   $3->set_name( "inert_smoke_crystals" ),
   $3->add_alias( "crystals" ),
   $3->set_short( "damp powdery black crystals" ),
   $3->add_adjective( ({ "damp", "powdery", "black" }) ),
   $3->set_long( "This is $pile_size$ of black crystals, about "
     "$amount_size$.  The crystals are covered in fine black powder, and "
     "they seem to still have a bit of moisture to them.\n" )
:) });
  data["PowderedCharcoal"]["StickySmokeCrystals"] = item;
  if (!mappingp(data["BlackGunPowder"])) data["BlackGunPowder"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0/10;
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "DampCoatedSmokeCrystals" ),
   $3->set_name( "damp_coated_smoke_crystals" ),
   $3->add_alias( "crystals" ),
   $3->set_short( "damp powdery black crystals" ),
   $3->add_adjective( ({ "damp", "powdery", "black" }) ),
   $3->set_long( "This is $pile_size$ of black crystals, about "
     "$amount_size$.  The crystals are covered in fine black powder, and "
     "they seem to still have a bit of moisture to them.\n" )
:) });
  data["BlackGunPowder"]["StickySmokeCrystals"] = item;
  if (!mappingp(data["CoatedSmokeCrystals"])) data["CoatedSmokeCrystals"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0.5, 1.5 });
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "SmokeBombFilling" ),
   $3->set_name( "smoke_bomb_filling" ),
   $3->add_alias( "powder" ),
   $3->set_short( "chunky black powder" ),
   $3->add_adjective( ({ "chunky", "black" }) ),
   $3->set_long( "This is $pile_size$ of black powder, with small crystals "
     "swimming in it. There's $amount_size$ here.\n" )
:) });
  data["CoatedSmokeCrystals"]["PowderedCharcoal"] = item;
  if (!mappingp(data["InertSmokeCrystals"])) data["InertSmokeCrystals"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 0.5, 1.5 });
  item->result = "/obj/reagents/generic_solid.ob";
  item->result_amt = 1;
  item->func = ({ (:
   $3->set_decay_speed(0),
   $3->set_medium_alias( "DudSmokeBombFilling" ),
   $3->set_name( "dud_smoke_bomb_filling" ),
   $3->add_alias( "powder" ),
   $3->set_short( "chunky black powder" ),
   $3->add_adjective( ({ "chunky", "black" }) ),
   $3->set_long( "This is $pile_size$ of black powder, with small crystals "
     "swimming in it. There's $amount_size$ here.\n" )
:) });
  data["InertSmokeCrystals"]["PowderedCharcoal"] = item;
  if (!mappingp(data["GroundFloppyMadman"])) data["GroundFloppyMadman"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0/400;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name( "water" ) :),
        (: $3->set_short( "pale brownish green water" ) :),
        (: $3->set_long("This is some pale green water, with "
                        "a brownish tint to it, about $pile_size$.\n") :),
        (: $3->set_medium_alias("SpellcheckPotion") :),
        (: $3->add_eat_effect( "/std/effects/ingested/potion_spellcheck",
            this_player()->query_skill_bonus(
               "magic.methods.physical.brewing" ) / 10 ) :)
    });
  data["GroundFloppyMadman"]["Water"] = item;
  if (!mappingp(data["SecondSightPotion"])) data["SecondSightPotion"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 1.0/2500;
  item->result = "/obj/reagents/ss_test.ob";
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_duration(600) :),
        (: $3->set_final("morph") :),
        (: $3->set_result("/obj/reagents/water.ob") :),
        (: $3->set_result_amt(1.0) :),
        (: $3->add_picture_command() :),
        (: $3->start_reaction() :)
    });
  data["SecondSightPotion"]["Water"] = item;
  if (!mappingp(data["RamtopsScumble"])) data["RamtopsScumble"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 2400/400.0;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("scumble") :),
        (: $3->set_short("sparkly scumble") :),
        (: $3->set_long("This is scumble with some sparkly "
               "sherbet traces in it, $amount_size$.\n") :),
        (: $3->add_eat_effect("/std/effects/ingested/drunk", 1500) :),
        (: $3->set_medium_alias("SherbetScumble") :),
    });
  data["RamtopsScumble"]["Sherbet"] = item;
  if (!mappingp(data["GroundThyme"])) data["GroundThyme"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = 200/2800.0;
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->func = ({
        (: $3->set_name("bomb") :),
        (: $3->add_adjective("thyme") :),
        (: $3->set_short("thyme bomb") :),
        (: $3->set_long("This is a thyme bomb, a drink that looks like "
                        "sparkly scumble, $pile_size$.") :),
        (: $3->add_eat_effect("/std/effects/ingested/drunk", 1500) :),
        (: $3->set_medium_alias("ThymeBomb") :),
        (: call_out( (: environment($1)->
           add_effect( "/w/dragonkin/effects/thyme_bomb", 
           ({ this_player()->
           query_skill_bonus("magic.methods.physical.brewing"), $1 }) ) :),
           1, $3 ) :),
        (: call_out( (: environment($1)->init() :), 2, $3 ) :)
    });
  data["GroundThyme"]["SherbetScumble"] = item;
  if (!mappingp(data["AncientWine"])) data["AncientWine"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({1.0, 300});
  item->result = LIQUID_OBJ;
  item->result_amt = 1.0;
  item->message = "There is a bubbling and hissing within the bottle as "
        "the mould and wine react...\n";
  item->func = ({
        (: $3->set_name( "vinegar" ) :),
        (: $3->set_short( "strong vinegar" ) :),
        (: $3->add_adjective("strong") :),
        (: $3->set_long("It's a clear liquid with an exceptionally acidic "
                "odour.\n") :),
        (: $3->set_medium_alias("Vinegar") :),
        (: $3->add_eat_effect( "/std/effects/ingested/poison", 20) :)
    });
  data["AncientWine"]["VinegarCulture"] = item;
  if (!mappingp(data["PlainFlour"])) data["PlainFlour"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 5, 960.0 });
  item->result = "/obj/reagents/generic_dough.ob";
  item->result_amt = 1;
  item->func = ({
        (: $3->set_name( "dough" ) :),
        (: $3->set_short( "plain dough" ) :),
        (: $3->add_adjective( ({ "plain" }) ) :),        
        (: $3->set_long( "This is $pile_size$ of plain dough, $amount_size$.\n" ) :),
        (: $3->set_medium_alias( "PlainDough" ) :),
    });
  data["PlainFlour"]["Water"] = item;
  if (!mappingp(data["PlainDough"])) data["PlainDough"] = ([]);
  item = new( class reaction
/* This reaction file is used to create apple juice. The point,
** naturally, is to make scumble, but if you get the wrong combination
** apple juices you will end up with plain apple juice. To get
** a juice which can be made into scumble you must mix Lancre 
** Blackhearts, Golden Disagreeables, and Green Billets.
**
** Author Wenda
** Created 23/01/00
** Edited 15/02/00: decided to go straight to juice and bypass grinding,
** with the use Taffyd's Handy Juicing Thing.
*/ );
  item->ratio = ({ 50, 150 });
  item->result = "/obj/reagents/generic_dough.ob";
  item->result_amt = 50;
  item->func = ({
        (: $3->set_name( "dough" ) :),
        (: $3->set_short( "sweet plain dough" ) :),
        (: $3->add_adjective( ({ "sweet", "plain" }) ) :),
        (: $3->set_long( "This is $pile_size$ of sweet dough, $amount_size$.\n" ) :),
        (: $3->set_medium_alias( "SweetPlainDough" ) :),
    });
  data["PlainDough"]["Sugar"] = item;
}

mixed data_return() {
  data_return_0();
  data_return_1();
  data_return_2();
  return data;
}
