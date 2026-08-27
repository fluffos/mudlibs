inherit "/obj/monster";
 
#define ARMOUR "/baseobs/armours/"
#define WEAPON "/baseobs/weapons/"
 
void setup()
  {set_name("watchman");
   add_property("NO_BUDGE",1);
   add_alias("gate watchman");
   add_alias("guard");
   set_main_plural("watchmen");
   add_plural("guards");
   set_short("Gate Watchman");
   set_long("These guards were recently recruited from an elite mercenary "+
            "company to replace the previously inept garrison.  In silence, "+
            "he scans the faces of those who pass . . .\n");
   set_race("human");
   set_guild("fighter");
   set_level(22+random(5));
   set_gender(1);
   set_heart_beat(1);
   set_wimpy(0);
   set_al(-60);
   set_ac(6);
   set_random_stats(18, 18);
   set_str(18+random(10));
   set_dex(15+random(5));
   set_con(15+random(5));
   set_max_hp(310);
   load_chat(10, ({
        1, ":flinches.",
        1, ":sneers at you from beneath his visor.",
        1, "'Beat it, Punk!"
        }));
   clone_object(WEAPON + "bastard_sword")->move(this_object());
   clone_object(ARMOUR + "helmet")->move(this_object());
   clone_object(ARMOUR + "chainmail")->move(this_object());
   clone_object(ARMOUR + "large_shield")->move(this_object());
   do_command("equip");
  }
 
int heart_beat()
   {object *atts, target;
    int chance, x, dam;
    atts=query_attacker_list();
    if(sizeof(atts))
       {chance=random(10);
        if(chance == 5)   
          {x=random(sizeof(atts));
           target=atts[x];
           if(environment(target) == environment(this_object()))
           tell_object(target, "The watchman steps back from you, allowing "+
             "the archers on the nearby walls to take a clear shot at you.  "+
             "Several strike your body, causing tremendous pain!\n\n");
           tell_room(environment(target), "The watchman feints and tempo"+
             "rarily disengages in combat with "+target->query_cap_name()+
             ".  Suddenly, from above a salvo of arrows rains down from the "+
             "outer walls, striking his opponent!\n\n", ({target}));
           dam=25+random(50);
           tell_object(target, "You take "+dam+" points of damage from "+
             "the missiles.\n\n");
           target->adjust_hp(-(dam));
          }
       }
    ::heart_beat();
   }
 
