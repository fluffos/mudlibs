/* Edmund, a nice chap.
 * Will attack all newbiekillers.. 
 * not many will be able to kill this guy..
 * Baldrick, feb '95
 */

inherit "/obj/monster";

void setup() {    
   add_property("NO_BUDGE",1);
      set_name("edmund");
      set_short("Edmund");
      set_race("human");
      set_gender(1);
      set_class("fighter");
      add_move_zone("city");
      set_str(28);
      set_dex(18);
      set_con(18);
      set_int(7);
      set_wis(7);
      set_cha(5);
      set_level(60);
      set_thac0(0);
      set_long(
        "Edmund is an old and ugly looking chap, he seems to study " +
        "everyone closely.\n");
      adjust_money(random(20),"copper");
      load_chat(10, ({
        1, "'I don't like bad people.",
        1, "'I will kill all evil.",
        1, ":looks closely at you.",
      }));
      load_a_chat(60, ({
        1, "'I'll kill you.",
      }));
      new("/baseobs/weapons/bastard_sword")->move(this_object());
      new("/baseobs/armours/chainmail")->move(this_object());
      new("/baseobs/armours/large_shield")->move(this_object());
      this_object()->init_equip();
} /* setup */

void event_fight_in_progress(object ob1, object ob2) 
  {
  int ob1_lvl, ob2_lvl;

  //if (!ob1->query_interactive() && !ob2->query_interactive())
  //  return;

  ob1_lvl = ob1->query_level();
  ob2_lvl = ob2->query_level();

  if (ob1_lvl < 5 && ob2_lvl > 5 && interactive(ob1))
    {
    tell_room("I don't like this!\n");
    attack_ob(ob2);    
    }

  /* The other way round: */
  if (ob2_lvl < 5 && ob1_lvl > 5 && interactive(ob2))
    {
    tell_room("I don't like this!\n");
    attack_ob(ob1);
    }

} /* fight in progress */

