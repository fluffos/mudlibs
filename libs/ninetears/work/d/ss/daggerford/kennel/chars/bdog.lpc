inherit "/obj/monster";
object owner;
string oname;
int stay;
void setup()
{
  owner = 0;
  set_level(random(5));
  set_living_name("black dog");
  set_name("dog");
 /* set_adjective("black");*/
  add_alias("attack dog");
  set_aggressive(0);
  set_follow_speed(200);
  reset_all();
  set_str(25);
  set_con(25);
  set_int(14);
  set_dex(25);
  set_wis(14);
  set_max_hp(4500);
  set_al(0);
  set_short("black attack dog");
  set_long("\nYou see before you a large black mean attack dog. You can see "+
           "that he is trained for dogfighting.\n");
  set_heart_beat(1);
  reset_get();
  set_gender(1);
  reset_drop();
  /* set_race(); */
  add_attack("bite",0,30,100,0,0,"sharp");
  add_attack("pounce",0,40,125,0,0,"blunt");
  add_attack("paws",0,30,125,0,0,"blunt");
} /* void setup */

int write_message(int dam, object him, object me, string type, string attack)
{
switch(attack)
{
  case "bite" :
    say("The black attack dog bites "+him->query_cap_name()+" really hard!\n");
  break;

  case "pounce" :
    say("The black attack dog pounces on "+him->query_cap_name()+" and is "+
        "crushed by his weight.\n");
  break;

  case "paws" :
   say("The black attack dog paws "+him->query_cap_name()+
       " with brute force!\n");
  break;

} /* switch attack */
} /* int write message */

void init()
{
  ::init();
} /* void init */

void heart_beat()
{
  ::heart_beat();
}

