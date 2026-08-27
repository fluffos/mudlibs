/*  For chaotic neutral we need a combination of light and darkness with winds,
    noise, voices, and other things that create an atmosphere of chaos.  I've
    decided to try to combine nature with darkness for a cross between good
    evil.  We'll see how it works...
 
    Guilo Forgebane             [The Bearded One]
*/
 
inherit "/std/sacroom";
 
void setup()  {
 
  set_light(50);
  add_property("no_clean_up",1);
 
  set_short("The Cathedral of Chaotic Neutral.");
 
  set_long("\nThe Cathedral of Chaotic Neutral:  Shrine of Confusion.\n\n"
           "   A huge waterfall cascades down a barren rock wall creating a "
           "dampness that permeates your clothing and a roaring that drills "
           "into your skull.  The overcast skies make it hard to see and the "
           "clouds constantly threaten rain.  A strong wind whips through "
           "the area with such force that you are constantly trying to keep "
           "your balance.  Life is abundant here but it has been changed "
           "somehow.  Insects buzz around you constantly and you find it "
           "difficult to concentrate.  A precariously balanced altar lies in "
           "the center of this area.\n"
           "\n");
 
  add_feel(({"dampness","damp"}),
           "   The mist from the waterfall flows through the area carried "
           "by the wind.  It soaks through your clothes in moments but it "
           "is not cold and uncomfortable.  The whole area is rather dreary "
           "but not unbearable.\n"
           "\n");
 
  add_feel(({"wind"}),
           "   You stagger against the blast of the wind.  It is not a cold "
           "or chilling wind, but rather warm and somehow comforting.  The "
           "force of it drives through you and makes it hard to think "
           "straight, however.  You slowly start to become disoriented.\n"
           "\n");
 
  add_sound(({"roaring","waterfall","wind","winds"}),
            "   Sound crashes from all around you.  The waterfall roars "
            "with a deafening force and combined with the howling wind you "
            "quickly lose your train of thought.  All you can think of is "
            "how you wish the world would just calm down and let you get "
            "your bearings again.\n"
            "\n");
 
  add_item(({"waterfall"}),
           "   As you approach the waterfall the spray from the cascading "
           "waters grows thicker.  The waterfall is so large it nearly "
           "covers the entire rock face.  The water is crystal clear and "
           "rather beautiful in a destructive way.\n"
           "\n");
 
  add_item(({"rock","wall","rock wall"}),
           "   The rock wall is large and grey.  You notice that the stone "
           "must be a form of slate, very hard but rather plain in color.  "
           "The only purpose for this wall seems to be the creation of the "
           "waterfall.\n"
           "\n");
 
  add_item(({"skies","clouds"}),
           "   You strain your neck to look into the skies and the heart "
           "of a thretening storm.  It hasn't struck yet but you can see "
           "the potential forces lying in wait just beyond this area.\n"
           "\n");
 
  add_item(({"wind"}),
           "   You stagger against the blast of the wind.  It is not a cold "
           "or chilling wind, but rather warm and somehow comforting.  The "
           "force of it drives through you and makes it hard to think "
           "straight, however.  You slowly start to become disoriented.\n"
           "\n");
 
  add_item(({"life"}),
           "   Life is abundant here but somehow it's been changed.  The "
           "plants are twisted and gnarled but healthy.  The animals are "
           "well fed but very timid and afraid.  You decide that life here "
           "must be a harsh mistress indeed.\n"
           "\n");
 
  add_item(({"insects"}),
           "   Insects buzz around you unceasingly.  They seem to be "
           "immune to the effects of the winds.  They seem to exist for the "
           "sole purpose of annoying you and any who enter here.\n"
           "\n");
 
  set_god_here("bivins");
  add_exit("river","/d/ss/ocheasuu/riveru3","path");
}  /* setup */
