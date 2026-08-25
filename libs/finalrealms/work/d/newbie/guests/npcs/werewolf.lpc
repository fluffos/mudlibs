inherit "/obj/monster";
object *it;
object med;
int x;
nosave int count = 1;
void setup() {
   add_alias("wolf");
   add_alias("wolfman");
   add_alias("werewolf");
   add_alias("man");
   set_name("standing wolf");
   set_short("Standing Wolf");
   set_long("He looks nothing like wolfman Jack.\n");
    set_main_plural("Wolfmen");
   set_gender(1);
   set_guild("fighter");
   set_random_stats(15, 18);
   adjust_con(1);
//set_kill_xp(3150);
   adjust_dex(4);
   set_level(28);
set_al(-100);

 
   load_chat(20, ({
         1, ":would be a great subject of a movie.",
         1, ":howls despairingly.",
      1, "'Ayyyyyooooooouuuuuu.",
         1, ":licks his pointed incisors.",
      1, ":rubs his shoulder against a nearby tree.",
      1, ":wonders if you have ever visited London.",
      1, "Standing Wolf's eyes glow as he senses your presence.",
      1, ":pricks his ears, waiting for your next move.",
      1, ":claws at the ground with his front paws.",
      1, ":groans and almost sounds human.",
      1, ":paces worriedly around you, his eyes never leaving yours."
   }));
   load_a_chat(30, ({
           1, ":is invigorated by the thrill of a fight.",
           1, ":licks his chops hungrily while gazing at your drumstick.."
               ".err...leg.",
           1, ":rises to his full height.",
           1, ":howls in delight at the sight of your blood!",
           1, ":dashes around you at lightening speed.",
           1, ":flares his nostrils.",
           1, ":jabs at you with a sharp claw."
   }));
} /* setup() */
 
 
void init()
  {
add_action("do_look","look");
  ::init();
}
/*init()*/
 
int do_look(string str)
{
int i;
   if (str == "wolf")
   {
    if (count==1)
   {
   count=2;
  write("Before you stands a creature cloaked in wolf skin.  "
  "Only your deepest gaze identifies that this is a human, half "
  "hidden by the coarse hair that covers his eyebrows and his "
  "cheekbones.  Hands clutching like claws hang down at his side, "
  "and the jagged fingernails seem to even snag the empty air.  It is "
  "his eyes that allow you to recognize him as a human, not a wolf; for "
  "they are too full of fear, terror and confusion to belong to a "
  "mere animal.  You shudder at this man's fate.\n");
return 1;
}
  if (count==2)
  {
     count=3;
  write("Balancing on his hind legs unsteadily, the wolf "
        "stares at you alertly.  Gray-brown fur hangs "
        "in tufts around his face but lies down more "
        "smoothly as it covers the muscles that ripple "
        "through the animal's body and its tail.   The wolf "
        "continues to gaze at you, and you uneasily recognize that "
        "there is something intelligent, something familiar.."
        "something human in those eyes.\n");
return 1;
  }
  if (count==3)
  {
       count=4;
       write("Balancing on his hind legs unsteadily, the wolf "
        "stares at you alertly.  Gray-brown fur hangs "
        "in tufts around his face but lies down more "
        "smoothly as it covers the muscles that ripple "
        "through the animal's body and its tail.   The wolf "
        "continues to gaze at you, and you uneasily recognize that "
        "there is something intelligent, something familiar.."
        "something human in those eyes.\n");
return 1;
  }
  if (count==4)
  {
        count=1;
write("Balancing on his hind legs unsteadily, the wolf "
        "stares at you alertly.  Gray-brown fur hangs "
        "in tufts around his face but lies down more "
        "smoothly as it covers the muscles that ripple "
        "through the animal's body and its tail.   The wolf "
        "continues to gaze at you, and you uneasily recognize that "
        "there is something intelligent, something familiar.."
        "something human in those eyes.\n");
  return 1;
}
}
}
 
#define AN attacker ->query_cap_name()
#define DN defender ->query_cap_name()
valid_attack() {
 
int two, three, four, five;
 
two = random(2);
three=random(3);
four=random(4);
five=random(5);
 
  return ([
"punch"   :({ AN+" "+({"scratches", "claws",})[two]+" "+DN+" on the "+({"thigh","cheek","back","knee",})[four]+".\n",
                 "You scratch "+DN+".\n",
AN+" "+({"scratches", "claws",})[two]+" you on the "+({"thigh","cheek","back","knee",})[four]+".\n"}),
 
"kick"    :({ AN+" "+({"scratches", "claws",})[two]+" "+DN+" on the "+({"arm","torso","leg","throat",})[four]+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"scratches", "claws",})[two]+" you on the "+({"arm","torso","leg","throat",})[four]+".\n"}),
 
"knee"    :({ AN+" "+({"bites", "mauls",})[two]+" "+DN+" on the "+({"thigh","cheek","back","knee",})[four]+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"bites", "mauls",})[two]+" you on the "+({"thigh","cheek","back","knee",})[four]+".\n"}),
 
"headbutt":({ AN+" "+({"bites", "mauls",})[two]+" on the "+({"arm","torso","leg","throat",})[four]+" of "+DN+".\n",
                 "You hit "+DN+".\n",
AN+" "+({"bites", "mauls",})[two]+" you on the "+({"arm","torso","leg","throat",})[four]+".\n"}),  ]);}

