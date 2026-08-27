/* Meditation Object, by Greymist 1995 */
#define TRANCE_HB 15
#define TRANCE_HP 0
#define TRANCE_GP 3

inherit "/std/object";

object ME;
int my_count;

object query_medi_me() { return ME; }
int query_medi_count() { return my_count; }

int query_auto_load(){return 1;}
void destruct_trance()
{
   if ( ME )  ME->remove_extra_look(TO);
  destruct(TO);
}

void set_trance(object ob)
{
  ME = ob;
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

  if(!ME || (int)ME->query_dead() || !(ME->query_trance()))
  {
	destruct_trance();
   return;
  }

  currhp = (int)ME->query_hp();
  maxhp = (int)ME->query_max_hp();
  currgp=(int)ME->query_gp();
  maxgp=(int)ME->query_max_gp();

 if(my_count++>TRANCE_HB)
   {
   if(currhp<maxhp)
      {
       ME->adjust_hp(TRANCE_HP);
      }
   if(currgp<maxgp)
      {
      ME->adjust_gp(TRANCE_GP);
      }
    my_count = 0;
  }
  set_heart_beat(1);
}

string extra_look()
{
  return "Is deep in a meditative trance.\n";
}
