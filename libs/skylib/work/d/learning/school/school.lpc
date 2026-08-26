// May - 2000
// Modified for Riftwar - 7-02-01 - Shaydz
#include "defs.h";
inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("Wizard's School Room");
    set_long("This is an abnormally large propylaeum to the Wizards "
      "School here on " +MUD_NAME+ ".\n" +"   A large gate towers so "
      "high here that one has to crack their neck to see the top of it. "
      "On the left and right side of the gate are two massive Gamorrean "
      "guards, who grunt and snort while waiting for their next "
      "trespasser to prey upon. On the other side of the gate is a "
      "long stoa lined with tomes that contain sacred knowledge of the "
      "ancients only those who have become masters or gained tutelage under "
      "them can comprehend these texts. Impressive as this vantage point may be, "
      "there are many things to learn.\n");

    add_item("gate","The gate is approximately 30 to 40 feet high. It is made of Laboi "
      "Crystals. The form work of the gate is beyond measure. To begin to describe "
      "it would fail to do it justice. Instead it can only be passionately "
      "explored to its indescrible detail. One aspect really "
      "paradoxically shines is a titanium doorbutton, which blips "
      "and flickers.");

    add_item("crystals", "These are the crystals of Laboi. They are highly "
      "sought through out the universe for its rarity and beauty. However, "
      "Laboi crystals can only be cultivated by a gentle mammalian race that "
      "live on Laboi II. The Laboi are a nomadic tribe who search for the "
      "dangerous yans. One important aspect of developing these crystals "
      "is they need telekinesis to affect how they grow and shape. "
      "Ponder the one who was powerful enough to form these crystals into a "
      "monolithic gate.");

    add_item("doorbutton","The titatium door button has different hues of "
      "blue and silver. It blips and bloops to a presence that approaches it. "
      "The lights glow into red and white making most familar sounds. Aside the "
      "light is a port. Its complex circuitry requires some knowledge.");

    add_item("port","The port is circular with varying lenths of radial angles. "
      "Interlocking plates whir momentarily and make fasciating geometric "
      "combinations. The answer to this intresting port lies only in the memory "
      "of the past. Also in the port is a hollowed out core.");

    add_item("light","Yep its a light, nothing fascinating about the light. "
      "Except, maybe the fact it changes colors from white to blue and red most "
      "fluidly.  Apparently the light is filled with a vitreous fluid is remarkably "
      "cool to the touch. It is probably made of a crystalline type of fluid.");

    add_item("guard","Which guard? There are two guards. left or right?");

    add_item("left guard","The short Gamorrean guard looks like a joke. However, "
      "it would not be wise to under estimate him. For he is not just short "
      "but very stout and heavy boned. He wields a 40 centimenter vibro blade. "
      "He is adorned with bare essentials and reeks of the most foul odors. "
      "His cousin guards the right side some thing is particular about the "
      "right guard.");

    add_item("right guard","This is an abnormally large guard, especially, "
      "for a Gamorrean guard. He stands 2.5 meters tall. Yet, in addition "
      "to to being tall he is massively built. One would estimate he is "
      "about 500 kilograms. Certainly such a rarity in Gamorrean guard "
      "must come high priced. This leads to some assumptions about the size "
      "of the left guard.");

    add_item("stoa","Alas, my friend, you can see good but you don't have "
      "x-ray vision through the gate. Also, its telekinetic nature hinders "
      "force-vision as well.");

    add_item("tomes","Alas, my friend, you can see good but you don't have "
      "x-ray vision through the gate. Also, its telekinetic nature hinders "
      "force-vision as well.");

    add_exit("common","/w/common","path");
    add_exit("general", GENSCHOOL "start","path");
    add_exit("room school",ROOMSCH+"start","path");
    add_exit("getting started",GETSTART+"start","path");
    add_exit("npc school",NPCSCHOOL+"start","path");
    add_exit("item school",ITEMSC+"start","path");
    add_exit("add command",ADD_SC+"start","path");

}
