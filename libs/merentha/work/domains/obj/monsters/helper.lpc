// Petrarch
// Jan 19, 2002
// Helper Monster

#include <std.h>
inherit MONSTER;

void create() {
::create();
  set_name("Helper");
  set_short("a welcome helper");
  set_long("This creature is here to help you in some ways.  He will speak
to you and answer some questions, though not very well.  He also surves
the purpose of being a monster example.");
  set_id(({"helper", "welcome helper"}));
  set_level(5);
  set_race("elf");
  set_gender("male");
  set_money("gold", 10);
  new(WEA "sword")->move(this_object());
  command("wield sword");
  new(ARM "cloak")->move(this_object());
  command("wear cloak");
}

void catch_tell(string str) {
  if(!str) return;
  if(this_object()==this_player()) return;
  says("I saw: "+str);
}

