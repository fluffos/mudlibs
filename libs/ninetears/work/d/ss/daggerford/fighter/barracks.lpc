/* North and South exits made selective by Grimbrand on 26 January 1993 */
/* Tightened up by Fengarance sometime in June 1995  */
 
inherit "/std/guildroom";
#include "path.h"
 
object knight1, knight2, sign;
object CREATE();
 
void setup () 
   {set_short("Training Arena");
    set_long("This is the great training arena of the Fighters' Guild.  "+
             "Many warriors are here honing their fantastic ability to "+
             "crush and mangle.\n\nTo the south you can see the guild "+
             "hall, and to the west a large open faced building.  "+
             "There is a large sign attached to a post in the middle of "+
             "the ground.\n");
    add_item("guildhall", "The Guildhall of the Fighters is to the south, "+
             "this is where they meet to discuss ideas "+
             "(a noticeably unused building).\n");
    add_item("building", "A large open faced building to the north "+
            "where the guild members keep their weapons and armors.\n");
    sign = add_sign("A large sign attached to the wall off to the side.  "+
            "It has writting scrawled on it in some "+
            "red substance (You're sure its just paint).\n", 
            "            ________________________________________  \n"+
            "           |\\______________________________________/| \n"+
            "           ||                                      || \n"+
            "           ||        WELCOME TO THE ARENA          || \n"+
            "           ||                                      || \n"+
            "           ||   -- Type 'join' become a member of  || \n"+
            "           ||      fighter's guild.                || \n"+
            "           ||   -- For more information on the     || \n"+
            "           ||      Fighters' Guild type 'info'.    || \n"+
            "           ||   -- To advance your levels type     || \n"+
            "           ||      'advance <skill>'.              || \n"+
            "           ||   -- To see how much it will take    || \n"+
            "           ||      out of you to improve yourself  || \n"+
            "           ||      type 'cost <skill>'.            || \n"+
            "           ||                                      || \n"+
            "           ||______________________________________|| \n"+
            "           |/______________________________________\\| \n\n");
   
    set_light (60);
   
    add_exit ("west", DAGG +"drill1", "door");
    add_exit ("south", ROOM+"hall", "corridor");
    add_exit ("north", ROOM+"armory", "corridor");
    modify_exit("north", ({"function", "knight_test"}));
    modify_exit("south", ({"function", "knight_test"}));
    
    set_guild("warriors/fighter");
    add_specialization("fighter");
   }
 
void reset() 
   {int i;
    if(!knight1)
       {knight1 = CREATE();
        knight1->move(this_object());
       }
    if(!knight2)
       {knight2 = CREATE();
        knight2->move(this_object());
       }
   }
 
object CREATE()
   {object ob;
    ob = clone_object("/obj/monster");
    ob->set_name("knight");
    ob->set_short("knight");
    ob->set_main_plural("knights");
    ob->add_alias("fighter");
    ob->add_plural("fighters");
    ob->add_adjective( ({ "stern", "looking" }) );
    ob->set_long("A large stern looking fighter.  He looks "+
                 "sternly at you.\n");
    ob->set_race("human");
    ob->set_guild("fighter");
    ob->set_level(75 + random(5));
    ob->set_gender(1+random(2));
    ob->set_thac0(5);
    ob->set_str(25);
    ob->set_dex(18);
    ob->move(this_object());
     ob->set_max_hp(700);
     clone_object("/baseobs/weapons/long_sword")->move(ob);
    clone_object("/baseobs/weapons/long_sword")->move(ob);
    clone_object("/baseobs/armours/chainmail")->move(ob);
    ob->do_command("equip");
    return ob;   
   }
 
void dest_me ()
   {if(knight1)
        knight1->dest_me();
    if(knight2)
        knight2->dest_me();
    if(sign)
       sign->dest_me();
   }
 
int knight_test()
   {
     if((string)(this_player()->query_guild_ob()) !=
	"/std/guilds/warriors/fighter")
          {notify_fail("The Fighter God steps in front of you, denying "+
                "entry.\n\n");
           tell_room(environment(this_player()),
                this_player()->query_cap_name()+" is shoved back by one "+
                "of the fighter Gods after attempting to enter the guild.\n\n",
                ({this_player()}));
           return 0;
          }
    return 1;
   }
