//     /bin/user/_fly.c
//     A dragon ability
//     Needed to get to their hall
//     Nightshade
//     demon and angel added 3/27/2002
//     New system added 10-26-02
 
#include <std.h> 
#include <daemons.h>
#include <locations.h>

#define DRAGON_HALL "/d/nopk/tirun/dragon_hall"

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <fly>\n\n"
    "Some races are able to fly to different places with use of their wings.",
    this_player() );
}

int abil() {
  object tp=this_player();
  string race = tp->query_race();
  string *check;

  switch (race) {
    case "imp": case "faerie":
      return 0;
    case "vampire":
      if (tp->query_level() >= 9) return 1;
  }

  if (tp->is_monster()) {
    if (function_exists("query_flying_mob", tp) && !tp->query_flying_mob())
      return 0;
    check = tp->query_limbs();
  }
  else if (tp->is_player()) check = RACE_D->query_limbs(race);
  else return 0;

  if (sizeof(regexp(check, "wing")) >= 2)
    return 1;
  return 0;
}

string type() { return "other"; }

int align_ok(object tp) {
  switch (tp->query_race()) {
    case "archangel":
      if (tp->query_alignment() < -500) return 0;
    break;
    case "demon":
      if (tp->query_alignment() > 500) return 0;
    break;
    default:
  }
  return 1;
}

int cmd_fly(string str) {
    object tp = this_player();
    object env = environment(tp);
    string base = base_name(env);
    object room;
    string *severed;
    string area, *dirs;
    string o;
    int skill;

    if (!abil())
       return 0;

    if (env->query_property("sky")) return 0;

    skill = tp->query_skill("flying");


    if (tp->query_current_attacker())
       return notify_fail("You try to fly away, but battle prevents you.\n");

    if (tp->query_arena())
       return notify_fail("You wouldn't dare try to fly out of the arena!\n");
       
    if (tp->query_busy())
       return notify_fail("You are off balance.\n");
       
    if (env->query_property("indoors"))
       return notify_fail("You cannot do that indoors.\n");

    if (env->query_property("no fly"))
       return notify_fail("The winds are too fierce.\n");
    
    if (tp->query_sp() < 10)
       return notify_fail("You are too tired.\n");
       
    if (tp->query_rest_type())
       return notify_fail("You are too comfortable to start flying.\n");

    if (tp->query_riding())
      return notify_fail("You must dismount before you can fly!");
    
    severed = regexp(tp->query_severed_limbs(), "wing");
    if (sizeof(severed))
      return notify_fail("Your "+severed[0]+" is missing!\n");
    
    if (!align_ok(tp)) {
      notify_fail("As you spread your wings, an immense, unearthly pain "
                  "surges through your body!\n");
      tp->add_hp(-(10+random(25)));
      if (tp->query_hp() < 1) tp->set_hp(1);
      return 0;
    }
    
    if (tp->query_riding())
      tp->force_me("dismount");
    

    if (tp->query_race() == "dragon" && str == "hall")
      room = load_object(DRAGON_HALL);
    else if (base == "/std/room/sky_room")
      return notify_fail("You are already flying.\n");

    else if (env->query_property("coords"))
      room = SKY_D->get_room(env->query_property("coords"));

    else {
      
      dirs=explode(base_name(env), "/");
      area=dirs[1];
      if(area == "nopk" || area == "freepk") area=dirs[2];
    
      if(!strsrch(base, "/d/nopk/standard/rain_forest/corinthor/"))
        o="O"; 
      else if(!strsrch(base, "/wizards/powerman/room/"))
        o="T"; 
      else if(!strsrch(base, "/wizards/detach/forbiden/rooms/"))
        o="J"; 
      else if (!strsrch(base, "/d/events/dragonaug2008/"))
        o="V";
      
      else {
        switch(area) {
          case "aekari": o="A"; break;
          case "forest": o="B"; break;
          case "tirunmts": o="C"; break;
          case "citrin": o="D"; break;
          case "distopia": o="E"; break;
          case "durst": o="F"; break; // Desert
          case "merkkerri": o="G"; break;
          case "purgatory": o="H"; break;
          case "rhondale": o="I"; break;
          case "helgrath": o="J"; break;
          case "lodos": o="L"; break;
          case "lodos_path": o="L"; break;
          case "metaisland": o="M"; break;
          case "arlon": o="N"; break;
          case "elven_path": o="O"; break;
          case "standard": o="S"; break; // Corinthor
          case "roston": o="Q"; break;
          case "shadow": o="R"; break;
          case "tirun": o="S"; break;
          case "inferi_island": o="U"; break;
          case "saahr": o="W"; break;
          default:
            o="S";
        }
      }
    }

    if (o)
      room = SKY_D->get_room(SKY_D->query_coord_from_letter(o));

    //if (wizardp(tp)) printf("%s\n%O\n%O", area, room, dirs);

    if (!room)
      write("A gust of wind prevents you from flying here!");
    else {
      if (base_name(room) == DRAGON_HALL) {
        if (tp->query_mounted())
          tp->force_me("buck "+tp->query_mounted()->query_name());
        write("You fly to your hall in the sky.");
      }
      else
        write("You leap into the sky.");
      say(tp->query_cap_name()+" leaps into the air!");
      tp->move_player(room, "into the sky");
    }

    return 1;
}

