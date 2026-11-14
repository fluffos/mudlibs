/* Aleena - Chosen Prophet of the All-God
 * Angel, November 1993
 */
inherit "inherit/monster";
object symb;


reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("aleena");
  set_gender(2);
  set_magic_resist(75);
  set_wc(30);
  set_level(30);
  set_ac(30);
  set_short("Prophet Aleena, Priestess of the All-God");
  set_long(
     "With green eyes and a young delicate face, there is an eternal   \n"+
     "peace within this young woman. Even though only in her youth     \n"+
     "she is the most powerful cleric, one chosen by the most powerful \n"+
     "of all gods - the Creator.\n");

  load_spells(30, ({ "fs", "csw", "hwd", "bls", "crs" }));

  load_chat(8, ({ "Aleena says: Welcome child.\n",
     "Aleena prays before the altar.\n",
     "Aleena prays earnestly.\n",
     "Aleena says: have you come to pray, my child?\n",
     "Aleena smiles happily.\n",
     "Aleena says: Worship with me, my child.\n"
  }));

  load_a_chat(8, ({ "Aleena says: My Lord will protect me.\n",
     "Aleena exclaims: Oh Lord, protect me.\n",
     "Aleena says: The All-God will strike you down.\n",
     "Aleena asks: Why do you attack me?\n"
  }));
  
  move_object(clone_object("room/city/monst/armour"),this_object());
   move_object(clone_object("room/city/monst/mace"),this_object());
  init_command("wield mace");
  init_command("wear armour");
/*

  symb = clone_object("inherit/armour");
  symb -> set_type("amulet");
  symb -> set_name("symbol");
  symb -> set_ac(1);
  symb -> set_weight(1);
  symb -> set_value(300);
  symb -> set_short("A holy symbol");  
  symb -> set_alias("holy symbol");
  symb -> set_long(
     "This is a platinum holysymbol to the All-God. It gives off a \n"+
     "soft light and is perhaps magical in nature.\n");
  move_object(symb, this_object());
  init_command("wear symbol");
*/

}
init() {
  ::init();
  call_out("welcome", 1, this_player());
  add_action("pray", "pray");
}

hit_player() {
  object obj;
  obj = this_player();
  if(obj -> query_level() < 15) {
    this_object() -> stop_all_fight();
    this_player() -> stop_all_fight();
    say("Aleena says: I wouldn't do that if I were you "+ 
        obj->query_name() +"\n");
    return 0;
  }
}

welcome(object obj) {
    if(this_player()->query_ghost()) {
      write("Aleena exclaims: I shall pray to the All-God to raise you!\n");
      obj->toggle_ghost();
      return 1;
    }
    say("Aleena says: Welcome, "+ this_player()->query_name() +". "+
        "Please worship with me.\n");
}

pray() {
  if(!this_player()->query_ghost()) {
    write("Aleena says: I can offer you the following services.\n\n"+
          "Cure Light Wounds......100 coins \n"+
          "Cure Disease...........200 coins \n"+
          "Dispel Magic...........500 coins \n"+
          "Aleena says: Tell me which service you wish, "+
           this_player()->query_name() +"?\n");
    return 1;
  }
  this_player()->toggle_ghost();
  return 1;
}


catch_tell(str) {
  call_out("delay_catch",1,str);
}

delay_catch(string str) {
  string tmp1, tmp2;
  
  if(this_object()->query_attack()) return;
  if(environment(this_player()) != environment()) {
    if(sscanf(str, "%stell%s", tmp1, tmp2)) {
      write("Aleena says: I hear you. But my powers can only be given "+
            "in my presence.\n");
    }
    return;
  }
  if(sscanf(str, "%scure light wounds%s", tmp1, tmp2)) {
    cure_wounds();
  }
  else if(sscanf(str, "%scure disease%s", tmp1, tmp2)) {
    cure_disease();
  }
  else if(sscanf(str, "%sdispel magic%s", tmp1, tmp2)) {
    dispel_magic();
  }
  else if(sscanf(str, "%shullo%s", tmp1, tmp2)) {
    say("Aleena says: Hullo, my child.\n");
  }
}

cure_wounds() {
  if(this_player()->query_money() < 100) {
    write("Aleena says: But you don't have enough money for the donation.\n");
    return 1;
  }
  say("Aleena begins a silent prayer.\n");
  say("Aleena touches the wounds of "+ this_player()->query_name() +"\n"+
  this_player()->query_possessive() +" wounds are healed.\n", this_player());

  tell_object(this_player(), "Aleena touches your wounds.\n"+
                             "You are healed.\n");
  this_player()->add_money(-100);
  this_player()->adj_hp(2 * (random(4) + 1));
  return 1;
}

cure_disease() {
  object disease;
  if(this_player()->query_money() < 200) {
    say("Aleena says: But you don't have enough money for the donation.\n");
    return 1;
  }
  if(present("Disease", this_player()));
    disease = present("Disease", this_player());
  if(!disease) {
    say("Aleena says: But you have no diseases, "
        + this_player()->query_name() +"\n");
    return 1;
  }
  say("Aleena begins a silent prayer.\n");
  say("Aleena lays her hands upon "+ this_player()->query_name()
     +" and\nheals "+ this_player()->query_possessive()
     +" diseases.\n", this_player());

  tell_object(this_player(), "Aleena lays her hands on you and "+
    "cures your diseases.\n");
  this_player()->add_money(-200);
  destruct(disease);
  return 1;
}

dispel_magic() {
  int i, j;
  object obj;

  obj = all_inventory(this_player());

  if(this_player()->query_money() < 500) {
    say("Aleena says: But you don't have enough money for the donation.\n");
    return 1;
  }
  say("Aleena begins a silent prayer.\n");
  for(i=0; i<sizeof(obj); i++) {
    if(obj[i] -> dispel_magic()) {
      if(obj[i] -> short())
        say(obj[i] -> short() +" is dispelled.\n");
      else
        say("Something is dispelled.\n");
      j++;
    }
  }
  if(!j) {
    say("Nothing happens.\n");
  }
  this_player()->add_money(-500);
  return 1;
}
