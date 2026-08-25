//  Character created by Mist ---  Fall 1994


inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
// Descriptions...
   set_name("gorbag");
   set_short("Gorbag");
   set_long("   This Gorbag, the bartender here.  He is a mean and "
            "quite nasty looking Orc who growls at you when he "
            "notices that you are looking at him.  He looks ready "
            "to take your order or kill you, whichever you choose.  "
            "\n\n");
   set_gender(1);
   set_race("orc");
   set_guild("fighter");
   set_random_stats(1, 6);
   adjust_dex(9);
   adjust_int(4);
   adjust_wis(4);
   adjust_str(16);
   adjust_cha(9);
   set_level(12);
   set_al(random(10));
   set_wimpy(0);
   set_aggressive(0);
 
   load_chat(50, ({
        1, ":cleans off the counter with a towel.",
		1,  ":asks you: 'What will it be?'"
   }));
   load_a_chat(100, ({
        1,":growls at you.",
        1,":glares at you."
   }));
 
   adjust_money(random(5), "silver");
 
   add_move_zone("orc_newbie");
   set_move_after(20, 40);
 
} /* void setup() */
 

