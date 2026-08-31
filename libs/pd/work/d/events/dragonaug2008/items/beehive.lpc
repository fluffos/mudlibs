#include <std.h>
#include <dragonevent.h>

inherit OBJECT;

int count;
int backlog;

void create() {
  set_name("beehive");
  set_short("a beehive");
  set_long("A beehive that vibrates intensely. It appears to be brimming with activity.");
  set_id( ({ "hive", "beehive" }) );
  set_mass(11);
  set_heart_beat(1);
  count = 0;
  backlog = 0;
}

void heart_beat() {
  int i = random(3)+2;
  string message;
  object env = environment(this_object());

  count++;
  if(count <= random(4)+3) return;
  count = 0;

  if(!env) return;

  //find the room this item is in
  for(int count=10; !env->is_room(); count--) {
    //if this is in the dog, do specific things
    if(file_name(env)[0..sizeof(DRAG_MOBS"beedog")-1] == DRAG_MOBS"beedog") {
      message = "%^RED%^The hound %^BOLD%^barks%^RESET%^%^RED%^, and "+cardinal(i)+" bees shoot forth from its mouth!";
      if(present("bone", env)) {
        backlog += i;
        message("info", "%^YELLOW%^The hound chokes and coughs as he chews on his bone!", environment(env));
        env->add_hp(-(backlog * (5000+random(400))));
        if(env->query_hp() > 1)
          return;
        else {
          env->die();
          env = this_object();
          message = "%^RED%^A flood of %^YELLOW%^bees%^RESET%^%^RED%^ are released from the dead hound's mouth!";
        }
      }
    }
    if(env) env = environment(env);
    if(!env) return;
  }

  if(backlog) {
    i += backlog;
    backlog = 0;
    if(!message)
      message("info", "%^RED%^A flood of bees are released from the beehive!", env);
    if(i > 45) i = 45;
  }

  if(!message) message = "%^YELLOW%^"+capitalize(cardinal(i))+" %^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^e%^YELLOW%^s fly out of the beehive!";
  message("info", message, env);
  for(;i > 0; i--)
    new(DRAG_MOBS"bee")->move(env);
}
