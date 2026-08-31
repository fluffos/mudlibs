
#include <std.h>

inherit MONSTER;

varargs void say_this(string str, object whom);

int is_zor_mon() { return 1; }
init() {
}
create() {
  ::create();
    set_name("helena");
    set_id( ({ "helena", "hag", "old hag" }) );
    set_level(20);
    set_short("The Old Hag, Helena");
    set_long(@LONG
This woman (?) appears to be a billion years old and is wearing
what would best be described as tattered and filthy rags for
clothing.  She seems to be very interested in a large clay pot
that is suspended over a hole in the floor.
LONG
);
  set("race", "high-man");
  set_gender("female");
  set_body_type("human");
  set_wimpy(0);
  set_alignment(500);
  set_languages( ({ "common", "undead-tongue", "devilish" }) );
  set_lang_prof("common",10);
  set_lang_prof("undead-tongue",10);
  set_lang_prof("devilish",10);
  set_chats(5, ({
    "Helena mumbles quietly.",
    "The old hag cackles softly as she pokes a stick in the pot and moans seem to come from its contents.",
    "Helena ignores you as she grabs what appears to be body parts and places them in the pot.",
    "The old hag turns her back to you as she goes over to a corpse and hacks on it with a butcher knife.",
    "Helena doesn't seem to notice you as she chants and sprinkles some red powder in the pot.",
    "The old hag peers at you as she scoops some black powder from the pot.",
    "Helena looks up at you and then rubs some black powder on a small gemstone.",
    "The old hags looks up at you and then returns to her work.",
    }) );
	set_class("fighter");
  set_casting_chance(35);
	set_combat_chance(80);
  set_skill("prayer",100);
  set_skill("illusionism",100);
  set_skill("body alteration", 100);
  add_spell("divine transformation","$(ME)");
  set_spell_level("divine transformation",6);
  add_spell("mirror image","$(ME)");
  set_spell_level("mirror image",1);
  add_spell("harm", "$A");
  set_spell_level("harm", 6);
  set("aggressive", 0 );
}
void catch_tell(string str) {
  string a, b, lang;
  object tp, ob;

  if(sscanf(str, "%*s says something in %s.", lang) == 2) {
    say_this("I don't understand "+lang+".  Please speak in common.");
    return;
  }
  if(sscanf(str, "%s gives you %s", a, b) == 2) {
    a = lower_case(a);
    tp = present(a, environment(this_object()));
    if(!tp) return;
    ob = present("soul_gem", this_object());
    if(!ob) {
      write(@WRONG
What do I want with this?

Need not do I have of such...
WRONG
);
      force_me("drop all");
      printf("Do you have a soul gem (y/n)?");
      input_to("soul_gem_question");
      return;
      ob->remove();
    }
   else {
     if((string)ob->query_property("soul gem") == "Itrius") {
       force_me("shout Soul Gem of Itrius have I...given me...Feel me fury!");
       return;
     }
     else {
       force_me("cackle");
       return;
     }
   }
  }
}

void soul_gem_question(string str) {
    int x;
    str = lower_case(str);
    switch(str) {
        case "y" :
        case "yes" :
           force_me("say To me give and dust it will I...");
           return;
        default:
           x=random(10);
           switch(x) {
            case 0 :
              force_me("say Bathe you should, in the pool of the devil spawn...");
              break;
            case 1 :
              force_me("say Poison you will the wound do, but perservere and it shall not.");
              break;
            case 2 :
              force_me("say The festering sore will endear you to the Mathins.");
              break;
            case 3 :
              force_me("say Shadow of life is death...purity is revealed in the cruicible.");
              break;
            default :
              force_me("Bring me the Gem of Itrius...and come true shall your dreams.");
              break;
           }
    }
}

void directed_message(object whom, string cmd) {
  string who, what, p1, p2;

  who  = (string)whom->query_cap_name();
  if((sscanf(cmd, "%suest%s", p1, p2) == 2) ||
    (sscanf(cmd, "%smystery%s",p1, p2) == 2)){
     write(@TEXT
Helena chuckles, "Yoos be wanting to know about this canyon?"

After a long pause she stops what she is doing and turns to face
you.  "Much goings and much comings...Muerta surrounds us, yet
live on we do.  Fury is riding high on a mare of the night..."

Helena wispers, "A portal be...A portal be..."

She then turns back to the pot adding a couple more body parts.
TEXT
);
     say("Helena mumbles something to "+who);
    return;
  }
  if((sscanf(cmd, "%soul gem%s", p1, p2) == 2)){
     write(@TEXT
Helena cackles, "A jar for brain honey..."

The old hag holds up a small stone.  It is dark and covered with
a sooty film.  "...A mind is a terrible thing...to waste...if the
Fury come for you where will you hide?  Oft, it is said that sex
with a devil will clarify the spirit, where then shall such desert
best be tasted?  I smell you don't understand...tis no bother for
without your toes you cannot walk and bereft a tongue no lies will
you babble.  To me shall be brought Itrius' refuge."  
TEXT
);
     say("Helena babbles something to "+who);
    return;
  }
  if((sscanf(cmd, "%spool%s", p1, p2) == 2) ||
    (sscanf(cmd, "%sspawn%s",p1, p2) == 2) ||
    (sscanf(cmd, "%smathin%s",p1, p2) == 2) ||
    (sscanf(cmd, "%swound%s",p1, p2) == 2) ){
     write(@TEXT
The old hag giggles, "Cleanliness is next to ugliness...and you
stiches in time will gather no moss.  Hell has stabbed its phalic
sword into the womb of the earth...infernal procreation spills forth
juices of damnation...wash well in the spirit of taint...I taste your
thoughts and know your desires...Others too, the Mathins, can taste
your presence and feel your will...You must scrub away your doubt,
lest ye be felled like a mighty oak to a knife of butter.  Bed down
with the mightiest of foes and your offspring will be theirs."
TEXT
);
     say("Helena giggles and says something to "+who);
    return;
  }
  if((sscanf(cmd, "%help%s", p1, p2) == 2)){
     write(@TEXT
Helena lets out a gastly wail and shrieks, "Help from me wish you?
I'll help you see the inside of your death shroud only to be carved
for ashen soup stock.  Lest you know that which you seek, bother me
not with your childish interuptions."
TEXT
);
     say("Helena shrieks at "+who);
    return;
  }
}
varargs void say_this(string str, object whom) {
  string your_lang;

  if(objectp(whom))
    your_lang = (string)whom->query_primary_lang();
  if(your_lang && stringp(your_lang) &&
    (int)this_object()->query_lang_prof(your_lang)
     >= 8) force_me("speak "+your_lang);
  else force_me("speak common");
  force_me("say "+str);
  return;
}
