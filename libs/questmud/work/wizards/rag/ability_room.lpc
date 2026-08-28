#define ABILITY_D "/daemons/ability_d"
inherit "room/room";

void init() {
  ::init();
  add_action("list","list");
  add_action("train","train");
  add_action("info","info");
}
  

void reset(int arg) {
  if(arg) return;
  add_exit("east","/world/city/gold7");
  
  short_desc = "Ability room";
  long_desc = "Here you can train several abilities which improve your character in\n"+
              "different ways. You can train abilities in 10% blocks. All abilities\n"+
              "must be trained to 100% to make them work. Some abilities give you\n"+
              "more info if you have them fully trained. You can do the following\n"+
              "things in this room:\n"+
              " list            - lists the abilities\n"+
              " train [ability] - starts training the [ability]\n"+
              " info [ability]  - shows info on the [ability]\n";
  
  /*property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";*/

  set_not_out(1);
  set_light(3);
}
  
int list() {
  ABILITY_D->list_abilities(this_player());
  return 1;
}

int train(string str) {
  ABILITY_D->train_ability(str, this_player());
  return 1;
}

int info(string str) {
  ABILITY_D->info(str, this_player());
  return 1;
}