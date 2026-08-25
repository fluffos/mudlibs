/* Hamlet threw me together. */
/* then Hamlet made me better */
/* Some more stuff added by Timion May 97 */
inherit "/obj/monster";

/* DOCUMENTATION:

   inherit this instead of /obj/monster.
   You must do set_moves(({"east","east"...}));  in setup().  Yes, the
     directions you want him to go must be typed out.
     
   OPTIONS:
   *  set_walk_delay() sets how long between steps.  It's in heartbeats.
   *  set_cycle(1)  will tell him to turn around and go back the way he
      came when he finishes his path.  The directions he went must be the
      standard ones for this to work.  If you have odd ones, see below.
      Also, if you go south and the new room you're in doesn't have a north,
      obviously he's gonna fail.
   *  add_opposites(({"barf","puke"}))  will add  barf and puke into the
      array of opposite directions.
   *  Instead of having him turn around and go back, you can decide to instead
      define a full circuit with set_moves().  The obvious thing then would
      be to have him start over when he gets to the end of the moves.
      Use set_begin_anew(1)  to have him do that.
*/  
   
   
string *opposites = ({ "north", "south", "east", "west", "northwest", 
                       "southeast", "northeast", "southwest", "up", "down",
                       "in", "out" });

int loc = 0;
int ascending = 1;
int cycle = 0;
int begin_anew = 0;
string *direcs = ({ });
int WALKDELAY = 5;
int awake = -1;
int WALKING = 1;

/* You must at least do set_moves() in your monster's setup() */

void set_walk_delay(int delay) {  WALKDELAY = delay;  }
void set_moves(string *moves) {  direcs = moves;  }
void set_cycle(int val) {  cycle = val;  }
void set_begin_anew(int val) {  begin_anew = val;  }

string *add_opposites(string *opp) {
  opposites = opp + opposites;
  return opposites;
}

int mycounter = 0;
int opp_pos;

void heart_beat() {
  ::heart_beat();

  if(!WALKING)
    return;
    
  awake++;
  if(awake < 15)
    set_heart_beat(1);
  else 
    awake = -1;

  mycounter++;

  if(loc == sizeof(direcs)) {
    if(cycle) {
      ascending = 0;
      loc--;
    }
    if(begin_anew)
      loc = 0;
      
    return;
  }

  if(loc == -1) {
    if(cycle) {
      ascending = 1;
      loc++;
    }
    return;
  }

  if(mycounter == WALKDELAY) {
    if(ascending)
      environment(this_object())->do_exit_command("blah",direcs[loc],
                  this_object(),0);
    else {
      opp_pos = member_array(direcs[loc],opposites);
      if(opp_pos == -1) {
        WALKING = 0;
        return;
      }
      else if( (opp_pos % 2) == 0 )
        environment(this_object())->do_exit_command("blah",
                    opposites[opp_pos + 1], this_object(),0);
      else
        environment(this_object())->do_exit_command("blah",
                    opposites[opp_pos - 1], this_object(),0);
    }

    if(ascending)
      loc++;
    else
      loc--;

    mycounter = 0;
  }
}
