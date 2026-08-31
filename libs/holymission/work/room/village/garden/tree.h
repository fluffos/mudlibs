#include <room_defs.h>
#include <damage.h>

// PROTOTYPES
string apple_look();
int _jump(string str);
int _pick(string str);
private nosave mixed *random_insect();
private nosave mixed *random_bird();

nosave int apple_count;

string apple_look() {
  if(apple_count <= 0)
    return "There are no apples here. ";
  return "There are a few apples here you could reach. ";
}

int _jump(string str) {
  string nothing, filename, msg, location;
  int    dam;

  dam = 0;
  switch(str) {
    case "off" :
    case "off tree" :
    case "off branch" :
    case "off the branch" :
    case "off the tree" :
    case "to ground" :
    case "down" :
    case "to the ground" :
      if(sscanf(file_name(TO), "%s/tree%s", nothing, filename) != 2)
        return 0;
      dam = 5;
      switch(filename) {
        case "05" :
        case "20" :
        case "30" :
        case "35" :
          writelw("You cannot jump at the trunk of the tree. You must "+
                  "be on a branch.\n");
          return 1;
        case "23" :
          location = VILLAGE_GARDEN + "tree04";
        case "25" :
          dam += 5;
          if(!random(5)) {
            msg = "You jump from the branch and head toward the ground "+
                  "but land on the branch below you! OUCH, that hurt.\n";
            dam -= 5;
            if(!location)
              location = VILLAGE_GARDEN + "tree04";
            break;
          }
        case "06" :
        case "07" :
        case "10" :
          msg = "You jump from the branch and you notice you may hit the "+
                "town wall below. ";
          if(!random(3)) {
            msg += "Unfortunately, your luck has run out and you hit the "+
                   "wall! OUCH, that hurt!\n";
            dam += 5;
          }
          else
            msg += "Thankfully, the fates are with you today as you miss it "+
                   "and head for the garden ground.\n";
          location = VILLAGE_GARDEN + "garden3";
          break;
        case "22" :
          dam += 5;
          if(!random(5)) {
            msg = "You jump from the branch and head toward the ground "+
                  "but land on the branch below you! OUCH, that hurt.\n";
            dam -= 5;
            location = VILLAGE_GARDEN + "tree04";
            break;
          }
        case "04" :
          msg = "You jump from the branch and head straight for the "+
                "ground.\n";
          location = VILLAGE_GARDEN + "garden3";
          break;
        case "24" :
          dam += 5;
          if(!random(5)) {
            msg = "You jump from the branch and head toward the ground "+
                  "but land on the branch below you! OUCH, that hurt.\n";
            dam -= 5;
            location = VILLAGE_GARDEN + "tree09";
            break;
          }
        case "09" :
          msg = "You jump from the branch over the town wall and head "+
                "straight into the fields outside of the town!\n";
          location = FIELDS + "crops";
          break;
        case "26" :
          dam += 5;
          msg = "You jump from the branch past the town wall and into "+
                "a forest.\n";
          location = "";
          break;
        case "08" :
          msg = "You jump from the branch past the town wall and into "+
                "the fields outside of town.\n";
          location = FIELDS + "crops";
          break;
        case "03" :
          msg = "You jump from the branch and head toward the town wall. ";
          if(!random(3)) {
            msg += "Unfortunately, your luck has run out and you hit the "+
                   "wall! OUCH, that hurt!\n";
            dam += 5;
          }
          else
            msg += "Thankfully, the fates are with you today as you miss it "+
                   "and head for the garden ground.\n";
          location = VILLAGE_GARDEN + "garden6";
          break;
        case "01" :
          msg = "You jump from the branch and head toward the town wall. ";
          if(!random(3)) {
            msg += "Unfortunately, your luck has run out and you hit the "+
                   "wall! OUCH, that hurt!\n";
            dam += 5;
          }
          else
            msg += "Thankfully, the fates are with you today as you miss it "+
                   "and head for the garden ground.\n";
        location = VILLAGE_GARDEN + "garden5";
          break;
        case "02" :
          msg = "You jump from the branch and head toward the town wall. ";
          if(!random(3)) {
            msg += "Unfortunately, your luck has run out and you hit the "+
                   "wall! OUCH, that hurt!\n";
            dam += 5;
          }
          else
            msg += "Thankfully, the fates are with you today as you miss it "+
                   "and head for the garden ground.\n";
          location = VILLAGE_GARDEN + "garden6";
          break;
        case "11" :
          msg = "You jump from the branch and head toward the town wall. ";
          if(!random(3)) {
            msg += "Unfortunately, your luck has run out and you hit the "+
                   "wall! OUCH, that hurt!\n";
            dam += 5;
          }
          else
            msg += "Thankfully, the fates are with you today as you miss it "+
                   "and head for the garden ground.\n";
          location = VILLAGE_GARDEN + "garden2";
          break;
        case "12" :
          msg = "You jump from the branch and head toward the ground.\n";
          location = VILLAGE_GARDEN + "garden2";
          break;
        case "13" :
          msg = "You jump from the branch past the town wall and into "+
                "a forest.\n";
          location = "";
          break;
        default :
          msg = "You jump and land on the ground.\n";
          location = VILLAGE_GARDEN + "garden3";
          break;
      }
      break;
    default :
      notify_fail("Jump where?\n");
      return 0;
  }
  say(TP->NAME + " jumps off the branch.\n");
  writelw(msg);
  TP->MOVEP("to the ground#" + location);
#if 1
  TP->hit_player(dam);
#else
  TP->hit_by_physical(dam, ({ PHYSICAL }), ({ 0 }));
#endif
  return 1;
}

int _pick(string str) {
  object ob;

  switch(str) {
    case "apple" :
    case "apples" :
    case "an apple" :
    case "a apple" :
    case "the apple" :
      if(apple_count <= 0) {
        write("There are no apples left to pick!\n");
        return 1;
      }
      apple_count--;
      write("You pick a delicious red apple!\n");
      ob=clone_object("/obj/food");
      ob->set_name("apple");
      ob->set_alias_list(({ "fruit", "red apple" }));
      ob->set_short("A bright red apple");
      ob->set_long("A delicious-looking apple. It is probably sweet and "+
                   "juicy.\n");
      ob->set_heal_amount(2+random(8));
      ob->set_value(20);
      ob->set_weight(1);
      if(transfer(ob, TP))
        MOVE(ob, ENV(TP));
      return 1;
    default :
      notify_fail("Pick what?\n");
      return 0;
  }
}

private nosave mixed *random_insect() {
  mixed *tmp;

  tmp = allocate(2);
  switch(random(10)) {
    case 0..1 :
      tmp[0] = 3 + random(3);
      tmp[1] = ({
        "set_name", "termite",
        "set_level", 1,
        "set_race", "insect",
        "set_short", "A small termite",
        "set_long", "A small termite eating some wood.\n",
        "set_gender", 0,
        "set_size", 1,
      });
      break;
    case 2..3 :
      tmp[0] = 2 + random(3);
      tmp[1] = ({
        "set_name", "mosquito",
        "set_level", 1,
        "set_race", "insect",
        "set_short", "A small mosquito",
        "set_long", "A small mosquito looking for his next meal.\n",
        "set_gender", 0,
        "set_size", 1,
      });
      break;
    case 4..5 :
      tmp[0] = 2 + random(3);
      tmp[1] = ({
        "set_name","caterpillar",
        "set_level", 1,
        "set_race", "insect",
        "set_short","A small caterpillar",
        "set_long","A small caterpillar crawling along.\n",
        "set_gender", 0,
        "set_size", 1,
      });
      break;
    case 6..7 :
      tmp[0] = 5 + random(2);
      tmp[1] = ({
        "set_name", "gnat",
        "set_level", 1,
        "set_race", "insect",
        "set_short", "A small gnat",
        "set_long", "A tiny gnat flying around your head bothering you.\n",
        "set_gender", 0,
        "set_size", 1,
      });
      break;
    default :
      tmp[0] = 4 + random(5);
      tmp[1] = ({
        "set_name", "ant",
        "set_level", 1,
        "set_race", "insect",
        "set_short", "A small ant",
        "set_long", "A tiny ant following an unseen trail.\n",
        "set_gender", 0,
        "set_size", 1,
      });
      break;
  }
  return tmp;
}

private nosave mixed *random_bird() {
  mixed *tmp;

  tmp = allocate(2);
  switch(random(10)) {
    case 0..1 :
      tmp[0] = 1 + random(2);
      tmp[1] = ({
        "set_name", "sparrow",
        "set_level", 2,
        "set_race", "bird",
        "set_short", "A sparrow",
        "set_long", "A sparrow enjoying its rest.\n",
        "set_gender", 1 + random(2),
        "set_size", 1,
      });
      break;
    case 2..3 :
      tmp[0] = 1 + random(2);
      tmp[1] = ({
        "set_name", "robin",
        "set_level", 2,
        "set_race", "bird",
        "set_short", "A robin",
        "set_long", "A robin, munching on a worm.\n",
        "set_gender", 1 + random(2),
        "set_size", 1,
      });
      break;
    case 4..5 :
      tmp[0] = 1 + random(2);
      tmp[1] = ({
        "set_name", "raven",
        "set_level", 3,
        "set_race", "bird",
        "set_short", "A raven",
        "set_long", "A raven watching you eerily.\n",
        "set_gender", 1 + random(2),
        "set_size", 1,
      });
      break;
    case 7..8 :
      tmp[0] = 1 + random(2);
      tmp[1] = ({
        "set_name", "woodpecker",
        "set_level", 3,
        "set_race", "bird",
        "set_short", "A woodpecker",
        "set_long", "A woodpecker eating its dinner in the tree.\n",
        "set_gender", 1 + random(2),
        "set_size", 1,
      });
      break;
    default  :
      tmp[0] = 1 + random(2);
      tmp[1] = ({
        "set_name", "quail",
        "set_level", 2,
        "set_race", "bird",
        "set_short", "A quail",
        "set_long", "A quail wanted a bush, but has settled for the tree.\n",
        "set_gender", 1 + random(2),
        "set_size", 1,
      });
      break;
  }
}

