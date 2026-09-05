#include "living.h"

reset(arg) {
    if (arg) 
        return;
    set_heart_beat(1);
    name = "thief";
    cap_name = "thief";
    msgin = "enters";
    msgout = "leaves";
    max_hp = 100;
    hit_point = 100;
    level = 5;
    tough = 4;
    musc = 3;
    willp = 45;
    cool = 56;
    dex = 90;
    spd = 67;
    brain = 24;
    fellow = 26;
    experience = 3383;
    weapon_class = 10;
    armor_class = 5;
    alignment = 60;
    is_npc = 1;
    enable_commands();
}

short() { return "The thief"; }

long() {
    write("A little thief.\nYou better check your things.\n"+
         "Maby they're not all there !!\n");
}

id(str) {
    return str == name;
}

random_move() {
  int n;
  n = random(6);
  if (n == 0)
    command("west");
  if (n == 1)
    command("east");
  if (n == 2)
    command("north");
  if (n == 3)
    command("south");
  if (n == 4)
    command("up");
  if (n == 5)
    command("down");
}

heart_beat()
{
    age += 1;
    attack();
    steal();
    if (random(5) == 0) random_move();
    if (attacker_ob && hit_point < (max_hp - 10))
       random_move();
}

steal()
{
    object ob, who;
    int weight;

    who = this_player();
    while(who) {
        if (who != this_object() && living(who) && random(2) == 0) {
            if (call_other(this_player(),"query_dex") < random (100))
                return;
            ob = first_inventory(who);
            if (ob == 0)
                return;
            transfer(ob, this_object());
            return;
        }
        who = next_inventory(who);
    }
}
