#include <rooms.h>
#include <stdrooms.h>
#include <properties.h>
#include <moving.h>

inherit "/std/room";

void died(object pl);
int dead();
void back();

int i;
object who,roo;

varargs void create(int arg) {
 ::create(arg);
 SetIntShort("In a gloomy cave");
 SetIntLong(
 "This is a gloomy cave, where the cave-sprite lives.\n");
 SetIndoors(1);
 SetIntLight(0);
}

void init() {
  ::init();
  call_out("dead",5);
}

int dead() {
  int died;
  write(
"You are in the gloomy cave of the cave-sprite. The cave-sprite stares at U.\n");
  died = ({int})this_player()->QueryAttribute("died");
  switch (died) {
     case 0: write(
"The cave-sprite says: 'Oh dear, you seem to have gotten yourself killed. "
"I might be able to help you out, but I've never really done this before. "
"Do you want to try to reincarnate you? All right! But don't blame me if "
"something goes wr...'\n"
"  --- poof!! ---\n"
"You are engulfed in a cloud of orange smoke. Coughing and gasping, you "
"emerge from the smoke and find ...\n"); break;
     case 1: write(
"The cave-sprite says: 'Tsk,tsk - you did it agian! Remember - you're only "+
({string})this_player()->QueryRace()+" and you don't have as many lives as a cat (at least, I don't "
"think so ...)! That's twice you've ended up dead - want to try for three? "
"As you whish! Hang on for just a second while I fire up my thurible..."
" --- foof! ---\n"
"An immense cloud of orange smoke fills the air. As it clears, you find that "
"once again you ...\n"); break;
     case 2: write(
"The cave-sprite says: 'You clumsy oaf, you've done it again! I don't know "
"how long I can keep this up. Do you want me to try reincarnating you again? "
"Okay, where did I put my orange smoke? ...\n"
"  > poof! < \n"
"Everything disappears in a dense cloud of orange smoke ...\n"); break;
    default: write(
"The cave-sprite says: 'Now you've rally done it! I'm out of orange smoke! "
"You don't expect me to do a decent reincarnation without any orange smoke, "
"do you? Yes ... well, that's the kind of blinkered, Philistine pig-ignorance "
"that I've come to expect from you mortals. You sit there on your loathsome, "
"spotty behind, squeezing blackheads and not careing a thinker's damn about "
"the struugling cave-sprite, you simpering, whining, moudly-faced heap of "
"parrot droppings! If you're so smart, then you can reincarnate yourself, "
"because quite frankly I'm as mad as hell and I'm not going to take this "
"anymore - I'm leaving!!!!'\n"
"The enraged cave-sprite drops a thurible and disappears. For a moment you "
"don't know what to do. Then you take the thurible and fire it by yourself. "
"There is no >poof!< or >foof!< and no cloud of orange smoke, as you appear "
"at a place that seems familiar to you ...\n");
   }
   this_player()->SetAttribute("died", died+1);
   this_player()->Set(P_HP,5);
   call_out("back",5);
   return 1;
}

void back() {
  who->move(objectp(roo)?roo:STARTROOM, M_GO);
}

void died(object pl) {
  tell_object(pl,"You die!\n");
  roo=environment(pl);
  who=pl;
  pl->reduce_hit_point(200,0);
  pl->move(this_object(), M_TELEPORT);
}
