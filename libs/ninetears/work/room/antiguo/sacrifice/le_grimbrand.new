#include "money.h"
inherit "/std/raiseroom";
inherit "/std/sacroom";

void setup() {

   set_light(30);

   set_short("The Cathedral of Lawful Evil");

   set_long("\nThe Cathedral of Lawful Evil:  Chantry of Darkness and "
            "Malevolence.\n\n"
            "     Your first view of this area is darkness, pure and "
            "evil.  The darkness seems to have a life of its own, a "
            "will-power unseen but felt.  Cold stone, black as pitch, "
            "passes beneath your feet as you walk into the area.  "
            "Columns decorated with symbols and creatures are spaced "
            "throughout the hall.  The shadows seem to move with a "
            "savage and maleficent grace, fear chills you to the bone "
            "as you sense malevolent intelligence tempered with honor "
            "and fanatical loyalty.  Indeed, these very traits are "
            "depicted in the carvings and mosaics etched into the very "
            "stone of this Cathedral.  A massive altar, set into the "
            "stone heart of the hall, draws your attention subtly yet "
            "commandingly.  From here you can see three exits leading "
            "into other chambers beyond this hall of worship.\n"
            "\n");

   add_smell(({"hall", "area", "evil", "darkness"}),
             "   The hall smells musty and old, accentuated with the "
             "sharper scent of spices and the sweet metallic scent of "
             "freshly spilt blood.\n"
             "\n");

   add_feel(({"stone"}),
            "   The stone of the hall is cold to the touch.  You can "
            "actually -feel- hatred, revenge, and malevolent intent "
            "vibrating in the stone.  The raw power of this area feels "
            "like an oppresive weight crushing you to the floor.\n"
            "\n");

   add_feel(({"hatred", "revenge", "malevolent intent"}),
            "   Overpowering emotion eminates from the very rock of "
            "the Cathedral.  Hatred, revenge, war, destruction, and "
            "shockingly intelligent evil overwhelm you with a unique "
            "sense of dread.  You sense additionally a great sense of "
            "honor and fanatical loyalty underlying the entire "
            "sensation.\n"
            "\n");

   add_item(({"darkness", "shadow", "shadows"}),
            "   The darkness appears very much alive and moves with "
            "a savage and malefic grace.  It seems very threatening "
            "yet inviting enough to draw you in not unlike the "
            "hypnotic effect of something so horrifically terrible "
            "that you are unable to glance away.  Moving and swaying, "
            "the darkness seems to be engaged in some sort of arcane "
            "dance of worship to the God of Darkness and Evil, "
            "Grimbrand.\n"
            "\n");

   add_item(({"stone"}),
            "   The stone of the hall has been constructed of "
            "obsidian and is as black as pitch.  It seems to absorb "
            "all light with a voracious appetite creating an illusion "
            "of endlessness.  It feels bitterly cold and extremely "
            "hard.\n"
            "\n");

   add_item(({"columns"}),
            "   The columns are evenly spaced forming an oval around "
            "the altar.  Each column depicts different creatures "
            "chosen by Grimbrand himself as the patron idols of "
            "each of the seperate classes housed within the evil "
            "dominion.  One displays the image of the Jackel, another "
            "that of the King Cobra, and a third has a Fer-de-Lance "
            "Viper, each has been inlaid into the obsidian with the "
            "rare metal known as Electrum.\n"
            "\n");

   add_item(({"symbol", "symbols", "creature", "creatures"}),
            "   The inlaid electrum in the columns seem to eminate "
            "a soft glow of even darker darkness as if radiated by "
            "pure evil.  You can see a Jackel, a King Cobra, and a "
            "Fer-de-Lance Viper, each are depicted as foreground "
            "characters who are shadowed from behind by an incredibly "
            "powerful looking Siberian Tiger.  Each of the three "
            "foreground animals are in various acts of wanton "
            "destruction and slaying.\n"
            "\n");

   add_item(({"altar", "Altar"}),
            "   This massive sacrifical altar is approximately waist "
            "high for a Duergar.  It is made of what appears to be a "
            "solid block of pewter and has an Electrum Plaque inlaid "
            "on each side.  The altar is fashioned in the same form "
            "as what you might expect a vivisectionist to require on "
            "his operating table.  The edges of the altar are "
            "recessed in such a manner to allow the blood from the "
            "sacrifice to drain away down into the central depths of "
            "this altar.  The altar itself seems to emit a low "
            "humming sound and when you touch it the humming stops.\n"
            "\n");

   add_item(({"plaque", "Plaque", "electrum plaque", "Electrum Plaque"}),
            "   As you look at the plaque you hear a very deep voice "
            "echo within your head, saying:\n\n"
            "     The raising service here requires the following:\n\n"
            "     You must _open_ an account.\n"
            "     You must _deposit_ money, of which a 10% tithing\n"
            "       will be extracted.\n"
            "     You may check the amount in your account by typing\n"
            "       _balance_.\n"
            "     To raise yourself type _raise me_.\n"
            "     To raise a friend type _raise <ghost>_.\n\n"
            "   The service charge for a Raising is 1 Platinum Coin "
            "for each experience level of the Mortal being raised.\n"
            "\n");

   add_exit("up", "/d/bf/banefall/dendall/guilds/cguild.c", "corridor");
}

void init() {
   ::init();
   add_action("do_heal", "heal");
}

int do_heal() {
   int Dark = (int)this_player()->query_value();

   switch((int)this_player()->query_level())
   {

   case 0..5:
    if(Dark >= 1000)
      {
       this_player()->pay_money((int)MONEY_HAND->create_money_array(1000));
       this_player()->adjust_hp(20);
       write_file("/w/grimbrand/mythos/HEAL",
                  this_player()->query_short()+
                  " paid for healing on "+
                  ctime(time())+" in the Cathedral.\n");
       write("\n   Darkness enters your body and you feel your "
             "wounds closing.\n\n");
       say("\n   A tendril of darkness from the room touches "+
           this_player()->query_cap_name()+"'s wounds and "+
           this_player()->query_pronoun()+" begins to heal!\n"
          "\n", ({ this_player() }));
       return (1);
       break;
      }
     else
      {
       write("\n   You are too destitue to pay for healing.\n\n");
       return (1);
     }

   case 6..10:
    if(Dark >= 2000)
      {
       this_player()->pay_money((int)MONEY_HAND->create_money_array(2000));
       this_player()->adjust_hp(20);
       write_file("/w/grimbrand/mythos/HEAL",
                  this_player()->query_short()+
                  " paid for healing on "+
                  ctime(time())+" in the Cathedral.\n");
       write("\n   Darkness enters your body and you feel your "
             "wounds closing.\n\n");
       say("\n   A tendril of darkness from the room touches "+
           this_player()->query_cap_name()+"'s wounds and "+
           this_player()->query_pronoun()+" begins to heal!\n"
           "\n", ({ this_player() }));
       return (1);
       break;
      }

   case 11..1000:
   if(Dark >= 4000)
     {
      this_player()->pay_money((int)MONEY_HAND->create_money_array(4000));
      this_player()->adjust_hp(20);
      write_file("/w/grimbrand/mythos/HEAL",
                 this_player()->query_short()+
                 " paid for healing on "+
                 ctime(time())+" in the Cathedral."
                 "\n");
      write("\n   Darkness enters your body and you feel your wounds "
            "closing.\n\n");
      say("\n   A tendril of darkness from the room touches "+
          this_player()->query_cap_name()+"'s wounds and "+
          this_player()->query_pronoun()+" begins to heal!\n"
          "\n", ({ this_player() }));
      return (1);
     }
   else
     {
      write("\n   You are too destitute to pay for healing.\n\n");
      return (1);
      break;
     }
   }
}
