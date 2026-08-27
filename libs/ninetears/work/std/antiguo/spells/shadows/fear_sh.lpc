#include <spells.h>

object myplayer;

void dispell_me()
{
  if (myplayer)
  {
    tell_object(myplayer,"El aura de miedo que te rodeaba desaparece.\n");
    tell_room(environment(myplayer),"El aura de miedo que rodeaba a "+myplayer->query_cap_name()+
              " desaparece.\n",myplayer);
    
    myplayer->set_wimpy(0);
  }
  call_out("dest_me",0);
}

int query_wimpy()
{
  return 100;
}

int set_wimpy(int wimpy)
{
  myplayer->set_wimpy(100);
  return 100;
}

void setup_shadow(object victim)
{
 int i;

  if (victim)
  {
    shadow(victim,1);
    myplayer=victim;
    myplayer->set_wimpy(100);
    myplayer->run_away();
    i=33-myplayer->query_level();
    if(i>15)
       i=15;
    else
      if(i<3)
        i=3; 
    set_reset(TO,i);
  }
  else call_out("dest_me", 0);

}
void adjust_hp(int i)
{
  if(!environment(TO)->query_timed_property("fear"))
      TO->dispell_me();

} 
void dest_me()
{
  destruct(TO);
}

void reset()
{
  TO->dispell_me();
}
