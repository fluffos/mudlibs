#include <std.h>
#include <aciri.h>
inherit GUARD;

int oi=0;

void create() {
 ::create();
   set_name("risa");
   set_short("Risa, the joker");
   set_long("Long ago, Risa wandererd into this tower. After a long "
     "time, she eventually lost her mind. Now Risa stumbles around "
     "the tower, mumbling to herself and laughing at nothing. Risa "
     "will not let you pass her, for she fears you may attack her from "
     "behind.");
   set_gender("female");
   set_heart_beat(1);
   make(ARM"jcap");
   make(OBJ"jacks");
}

int is_invincible() {
   this_object()->force_me("throw jacks at "+this_player()->query_name());
   return 0;
}

void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wear cap"); oi = 1; }
}
