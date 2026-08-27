inherit "/obj/monster";
#define PET "attack dog"
object owner;
string oname;
int stay;
void setup()
{
  owner = 0;
set_level(50);
  set_living_name("dog");
  set_name("dog");
  add_alias("saint bernard");
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
  set_short("Saint Bernard");
  set_long("\nYou see before you a large Saint Bernard, which you estimate "+
           "is approximately 7 feet tall.  It is very playful.\n");
  set_heart_beat(1);
  reset_get();
  set_gender(1);
  reset_drop();
  set_race(PET);
  add_attack("bite",0,100,100,0,0,"sharp");
  add_attack("pounce",0,60,125,0,0,"blunt");
  add_attack("paws",0,60,125,0,0,"blunt");
   load_chat(30,({
                    1,"The saint bernard leaps on top of you and you fall "+
                      "flat on your back.\n",
                    1,"The saint bernard licks your face in an affectionate "+
                      "way.\n",
                    1,"EEEEWW!  You have got dog hairs all over your "+
                      "clothes now!\n",
                    1,"The saint bernard wants you to take him for a walk!\n",
                    1,"Woooof! Woooof!.\n",
                    1,"The saint bernard looks sheepishly at you "+
                      "You begin to wonder what kind of trouble he is getting "+
                      "in to.\n",
                    1,"The saint bernard holds his paw up for a handshake.\n",
                    1,"The saint bernard pounces on you playfully.\n",
                    1,"The saint bernard playfully bites you.\n"}));

}
int write_message(int dam, object him, object me, string type, string attack)
{
switch(attack)
{
  case "bite" :
    say("The Saint Bernard bites "+him->query_cap_name()+" really hard!\n");
    tell_object(him,me->query_cap_name()+" bit you!\n");
  break;

  case "pounce" :
    say("The Saint Bernard pounces on "+him->query_cap_name()+" and is crushed"+        " by his weight.\n");
    tell_object(him,me->query_cap_name()+" pounced on you!\n");
  break;

  case "paws" :
   say("The Saint Bernard paws "+him->query_cap_name()+" with brute force!\n");
    tell_object(him,me->query_cap_name()+" slaps you with it's paw!\n");
  break;

}
}
void init()
{
  ::init();
  add_action("come", "come");
  add_action("stay", "stay");
  add_action("join", "join");
  add_action("snake_attack", "attack");
  add_action("calm", "calm");
}
come()
{
  if(owner==this_player())
  {
    stay=0;
    tell_room(environment(this_object()), oname+ " orders the dog to come, "+
              "and the dog runs on over licking "+oname+" on the face.\n");
    write("\n");
    return 1;
  }
  notify_fail("You are not quite sure, but it looked like the dog shook his "+
              "head.  \n");
  return 0;
}
stay()
{
  if(owner != this_player())
  {
    tell_room(environment(this_object()), this_player()->query_cap_name()+
              " orders the dog to stay, but is ignored.\n", this_player());
    write("The dog growls menacingly at you.\n");
    return 1;
  }
  stay=1;
  tell_room(environment(this_object()), this_player()->query_cap_name()+
            " orders the dog to stay.\nThe dog lays down like a good "+
            "dog.\n", owner);
  write("The dog whimpers and goes to the corner and lies down.\n");
  return 1;
}
join(string who)
{
  if(!who)
  {
    notify_fail("The syntax is: 'join me'.\n");
    return 0;
  }
  if(!owner && who == "me")
  {
    owner = this_player();
    oname = (string)owner->query_name();
    stay = 0;
    write("The dog is now your loyal Saint Bernard.\n");
    do_command(" whisper "+oname+""+
    " You can command me to:\n - 'attack <target>'\n"+
    " - 'calm <target>' to have me stop killing a target\n"+
    " - 'stay' to stay put\n"+
    " - 'come' to make me follow you again.\n");
    return 1;
  }
  notify_fail("The dog growls at you.  "+capitalize(oname)+
              " is already its master.\n");
  return 0;
}
snake_attack(string str)
{
  object target;
  if(this_player() != owner)
  return 0;
  if(!str)
  {
    notify_fail("The syntax is: 'attack <target>'.\n");
    return 0;
  }
  tell_room(environment(this_object()), capitalize(oname)+" orders "+
            "the dog to attack "+str+".\n");
  if(str == oname || str == "me")
  {
    notify_fail("The dog likes you too much.\n");
    return 0;
  }
  target = present(str, environment(this_object()));
  if(!target)
  {
    tell_room(environment(this_object()), "The dog tries to find a "+str+
              " to attack, but searches in vain.\n");
    return 1;
  }
  attack_ob(target);
  tell_room(environment(this_object()), "The dog follows the orders of "+
            capitalize(oname)+" and attacks "+str+" who is promptly "+
            "bit!\n");
  return 1;
}
calm(string str)
{
  if(!str)
  {
    notify_fail("The syntax is: 'calm <target>'.\n");
    return 0;
  }
  if(this_player() == owner)
  {
    stop_fight(find_living(str));
    return 1;
  }
}
void heart_beat()
{
  ::heart_beat();
  if(!owner || stay)
    return;
  if(environment(this_object()) == environment(owner))
    return;
  this_object()->move(environment(owner));
  tell_object(owner,"You drag the dog in by the leash.\n");
}

