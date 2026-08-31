/* Glowing orb cloned by the conjuring light spell.
   See /bin/user/_light.c for more info.
   By Valodin, Jan 15, 1993
*/
 
inherit "/std/object";

void set_creator(object ob);
void light(int level, int time);
int bury();
int extinguish(string str);
void dim();
int move(mixed dest);
int remove();
int darken();
 
int light_level, light_time;
object creator;
 
void create()
{
  set_id( ({ "orb", "glowing orb", "magical orb" }) );
  set_name("orb");
  set_short("A glowing orb");
  set_weight(0);
  set_value(0);
  light_level = 0;
  light_time = 0;
}
 
void init()
{
  add_action("extinguish", "extinguish");
  add_action("darken", "darken");
}
 
void set_creator(object ob)
{
  creator = ob;
}
 
void light(int level, int time)
{
  light_level = level;
  light_time = time;
  if (environment())
    environment()->set_property("light", level);
  call_out("dim", time);
}
 
int bury() { 
  write("The orb eludes your grasp!");
  return 1;
}
 
int extinguish(string str)
{
  if (!str) return 0;
  if(present(str, this_player()) != this_object())
    return 0;
  write("You extinguish your orb, leaving nothing.\n");
  say(this_player()->query_cap_name()+" extinguishes " +
      this_player()->query_possessive()  + " orb.\n",
      this_player());
  if (environment())
    environment()->set_property("light", -light_level);
  remove_call_out("dim");
  light_level = 0;
  remove();
  return 1;
}
 
void dim()
{
  object env=environment();
  if (!env) {
    remove();
    return;
  }
  light_level = light_level - 1;
  env->set_property("light", -1);
  if(light_level == 0)
  {
    if(!living(env))
      /* must be a room or bag */
      tell_object(env,
                  "The orb winks out of existence.\n");
    else
      /*  in a person */
    {
      tell_room(environment(env), "The orb that " +
                capitalize((string)env->query_name()) +
                " is carrying winks out of existence.\n",
                env);
      tell_object(env,
                  "The orb that you are carrying winks out of existence.\n");
    }
    remove();
  }
  else
  {
    if(!living(env))
      /* must be a room or bag */
      tell_object(env,
                  "The glow of the orb weakens slightly.\n");
    else
      /*  in a person */
    {
      tell_room(environment(env),
                "The glow of the orb that " +
                capitalize((string)env->query_name()) +
                " is carrying weakens slightly.\n",
                env);
      tell_object(env,
                  "The glow of the orb that you are carrying weakens" +
                  " slightly.\n");
    }
    call_out("dim", light_time);
  }
}
 
int move(mixed dest)
{
    int x;
    object env=environment();
 
    if(env)
      env->set_property("light", -light_level);
    x = ::move(dest);
    env = environment();
    if(env)
      env->set_property("light", light_level);
    return x;
}
 
int remove() {
    object env=environment();
    if(light_level && env) 
      env->set_property("light", -light_level);
    return ::remove();
}
 
int darken(string str){
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   if(this_player() != creator)
     return notify_fail("Only the creator of an orb can attenuate its brilliance.\n");
   
   remove_call_out("dim");
   dim(); 
   return 1;
}

