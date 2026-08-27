/* Meditation Object, by Greymist 1995 */
#define TRANCE_HB 15
#define TRANCE_HP 0
#define TRANCE_GP 3

inherit "/std/object";

object me;
int my_count;

object query_medi_me() { return me; }
int query_medi_count() { return my_count; }

int query_auto_load(){return 1;}

void destruct_trance()
{
  if ( me )  
    me->remove_extra_look(this_object());
  destruct(this_object());
}

void set_trance(object ob)
{
  me = ob;
  my_count = 0;
  set_heart_beat(1);
}

void setup()
{
  set_weight(0);
  set_name("");
}

void heart_beat()
{
  int currhp, maxhp, ratio;
  int currgp, maxgp;

  if(!me || (int)me->query_dead() || !(me->query_trance()))
  {
    destruct_trance();
    return;
  }

  currhp = (int)me->query_hp();
  maxhp = (int)me->query_max_hp();
  currgp=(int)me->query_gp();
  maxgp=(int)me->query_max_gp();

  if(my_count++>TRANCE_HB)
  {
    if(currhp<maxhp)
      me->adjust_hp(TRANCE_HP);
    if(currgp<maxgp)
      me->adjust_gp(TRANCE_GP);
     my_count = 0;
  }
  set_heart_beat(1);
}

