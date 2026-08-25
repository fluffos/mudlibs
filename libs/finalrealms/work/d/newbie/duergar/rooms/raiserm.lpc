/*  Room by Grimbrand 2-3-96  */

inherit "/std/raiseroom";
#include "path.h";

object helper;

void setup() {

   add_property("no_undead",1); set_light(10);
   
   set_short("Realm of the Duergar:  The Cathedral of Lawful Evil");

   set_long("\n   Realm of the Duergar:  The Cathedral of Lawful Evil."+
            "\n\n"+
            "     Your first view of this area is darkness, pure and "+
            "evil.  The darkness seems to have a life of its own, a "+
            "will-power unseen but felt.  Cold stone, black as pitch, "+
            "passes beneath your feet as you walk into the area.  "+
            "Columns decorated with symbols and creatures are spaced "+
            "throughout the hall.  The shadows seem to move with a "+
            "savage and maleficent grace, fear chills you to the bone "+
            "as you sense malevolent intelligence tempered with honor "+
            "and fanatical loyalty.  Indeed, these very traits are "+
            "depicted in the carvings and mosaics etched into the living "+
            "stone of this Cathedral.  A massive altar, set into the "+
            "stone heart of the hall, draws your attention subtly yet "+
            "commandingly.\n"
            "\n");

   add_smell(({"hall", "area", "evil", "darkness"}),
             "   The hall smells musty and old, accentuated with the "+
             "sharper scent of spices and the sweet metallic scent of "+
             "freshly spilt blood.\n"+
             "\n");

   add_feel(({"stone"}),
            "   The stone of the hall is cold to the touch.  You can "+
            "actually -feel- hatred, revenge, and malevolent intent "+
            "vibrating in the stone.  The raw power of this area feels "+
            "like an oppresive weight crushing you to the floor.\n"+
            "\n");

   add_feel(({"hatred", "revenge", "malevolent intent"}),
            "   Overpowering emotion eminates from the very rock of "+
            "the Cathedral.  Hatred, revenge, war, destruction, and "+
            "shockingly intelligent evil overwhelm you with a unique "+
            "sense of dread.  You sense additionally a great sense of "+
            "honor and fanatical loyalty underlying the entire "+
            "sensation.\n"+
            "\n");

   add_item(({"darkness", "shadow", "shadows"}),
            "   The darkness appears very much alive and moves with "+
            "a savage and malefic grace.  It seems very threatening "+
            "yet inviting enough to draw you in not unlike the "+
            "hypnotic effect of something so horrifically terrible "+
            "that you are unable to glance away.  Moving and swaying, "+
            "the darkness seems to be engaged in some sort of arcane "+
            "dance of worship to the God of Darkness and Evil, "+
            "Grimbrand.\n"+
            "\n");

   add_item(({"stone"}),
            "   The stone of the hall has been constructed of "+
            "obsidian and is as black as pitch.  It seems to absorb "+
            "all light with a voracious appetite creating an illusion "+
            "of endlessness.  It feels bitterly cold and extremely "+
            "hard.\n"+
            "\n");

   add_item(({"columns"}),
            "   The columns are evenly spaced forming an oval around "+
            "the altar.  Each column depicts different creatures "+
            "chosen by Grimbrand himself as the patron idols of "+
            "each of the seperate classes housed within the evil "+
            "dominion.  One displays the image of the Jackel, another "+
            "that of the King Cobra, and a third has a Fer-de-Lance "+
            "Viper, each has been inlaid into the obsidian with the "+
            "rare metal known as Electrum.\n"+
            "\n");

   add_item(({"symbol", "symbols", "creature", "creatures"}),
            "   The inlaid electrum in the columns seem to eminate "+
            "a soft glow of even darker darkness as if radiated by "+
            "pure evil.  You can see a Jackel, a King Cobra, and a "+
            "Fer-de-Lance Viper, each are depicted as foreground "+
            "characters who are shadowed from behind by an incredibly "+
            "powerful looking Siberian Tiger.  Each of the three "+
            "foreground animals are in various acts of wanton "+
            "destruction and slaying.\n"+
            "\n");

   add_item(({"altar", "Altar"}),
            "   This massive sacrifical altar is approximately waist "+
            "high for a Duergar.  It is made of what appears to be a "+
            "solid block of pewter and has electrum designs inlaid "+
            "on each side.  The altar is fashioned in the same form "+
            "as what you might expect a vivisectionist to require on "+
            "his operating table.  The edges of the altar are "+
            "recessed in such a manner to allow the blood from the "+
            "sacrifice to drain away down into the central depths of "+
            "this altar.  The altar itself seems to emit a low "+
            "humming sound, and when you touch it, the humming stops.\n"+
            "\n");

add_sign("__________________________________________\n"
         "|                                        |\n"
         "|       Dendall Academy Raiseroom        |\n"
         "|                                        |\n"
         "|  Type raise <ghost> to raise someone.  |\n"
         "|________________________________________|\n\n");

add_exit("north",NEWBIE+"main03","door");
}

void reset() {

   if(!helper) 
     {
      helper = clone_object("/baseobs/monsters/healer");
      helper->move(this_object());
     }

   helper->set_name("Duergar Priest");
   helper->set_short("Priest");
   helper->add_alias("priest");
   helper->set_guild("fighter");
   helper->set_race("duergar");
   helper->set_level(55 + random(10));
   helper->set_thac0(-4);
   helper->set_max_hp(1500);
   helper->set_max_gp(1000);
   helper->set_gender(1);
   helper->set_kill_xp(5);
   helper->set_long("\n   The duergar standing before you is a Priest "
                    "of the God of the Duergar, Grimbrand:  God of "
                    "Darkness and Evil.  This priest renders help to "
                    "all Duergar seeking aid, even those who are "
                    "beyond the need of simple patches and potions.\n"
                    "\n");
}

void dest_me() {
if (helper) helper->dest_me();
::dest_me();
}
