#include "/players/francesco/univ/ansi.h"
inherit "obj/monster";
int x, play;
   object gold;
reset(arg){
   ::reset(arg);
   set_name("narrator");
   set_race("human");
   set_alias("narrator");
      set_short("The Narrator");
     set_long("The Narrator is an old man, with glasses and a notebook on his\n"+
              "hand.  He looks very wise and you might 'ask' him his thoughts.\n"+
              "Once upon a time he also used to 'trade' any item.\n");
   set_level(10);
   set_hp(150);
   set_al(0);
   set_wc(14);
   set_ac(8);
}


init() {
   ::init();
   add_action("ask","ask");
}

ask(str) {
   if(play) { write("Shhhhhh, he is already narrating...\n"); return 1; }
   if(!str) {write("Ask whom?\n"); return 1;}
   if (str!="narrator") {write("Ask whom?\n"); return 1;}
   tell_room(environment(this_player()),HIR+"The narrator clears his throat."+NORM+"\n");
   play = 1; call_out("narrate",3);
   return 1; }

narrate(){
   narrate_it();
   x += 1;
   if(x<12) call_out("narrate",16);
   else { play = 0; x = 0; }
   return 1; }

narrate_it() {
   string lyric1,lyric2,lyric3,lyric4,lyric5;
   switch(x) {
      case 0: lyric1 = "\n   The remorseless drought had lasted now for ten million years,\n"+
                       "and would not end for another million. The reign of the terrible\n"+
                       "lizards had long since passed, but here on the continent which\n";
              lyric2 = "would one day  be known as Africa, the battle for survival had\n"+
                       "reached a new climax of ferocity, and the victory was not yet in\n"+
                       "sight.  In this dry and barren land, only the small or the swift\n";
              lyric3 = "or the fierce could flourish, or even hope to exist anymore.\n";
              lyric4 = "";
              lyric5 = "\n";break;
      case 1: lyric1 = "   The man-apes of the field had none of these attributes and they\n"+
                       "were on the long, pathetic road to racial extinction.  About twenty\n"+
                       "of them occupied a group of caves overlooking an arched valley\n";
              lyric2 = "divided by a sluggish, brown stream.  The tribe had always been\n"+
                       "hungry, and now it was starving.\n";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;
      case 2: lyric1 = "   As the first dim glow of dawn creeps into the cave, Moonwatcher\n"+
                       "discovered that his own father had died during the night.  He did\n"+
                       "not know the Old One was his father, for such a relationship was\n";
              lyric2 = "beyond his understanding.  But as he stood looking down at the \n"+
                       "emaciated body he felt something,  something akin to sadness. \n"+
                       "Then he carried his dead father out of the cave, and left him for\n";
              lyric3 = "the hyenas.\n";
              lyric4 = "";
              lyric5 = "\n";break;
      case 3: lyric1 = "   Dozing fitfully and weakened by his stuggle, Moonwatcher was\n"+
                       "startled by a sound. He sat up in the fetid darkness of the cave\n"+
                       "straining his senses out into the night, and fear creeps slowly\n";
              lyric2 = "into his soul.  Never in his life - already twice as long as most\n"+
                       "members of his species could expect - has he heard a sound like\n"+
                       "this.\n";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;
      case 4: lyric1 = "   The great cats approached in silence, and the only thing that \n"+
                       "betrayed them was a rare slide of earth, or the occasional cracking\n"+
                       "of a twig.  Yet this was a continuing crunching noise that grew\n";
              lyric2 = "steadily louder.  It seemed that some enormous beast was moving \n"+
                       "through the night, making no attempt at concealment, and ignoring \n"+
                       "all obstacles. And then there  came a sound which Moonwatcher could\n";
              lyric3 = "not possibly have identified, for it had never been heard before \n"+
                       "in the history of this planet.\n";
              lyric4 = "";
              lyric5 = "\n";break;
      case 5: lyric1 = "   Moonwatcher came face to face with the Monolith when he led the\n"+
                       "tribe down to the river in the first light of morning.  He had\n"+
                       "almost forgotten the terror of the night, because nothing had\n";
              lyric2 = "happened after that initial noise, so he did not even associate\n"+
                       "this strange thing with danger or with fear.  There was nothing\n"+
                       "in the least alarming about it.  \n";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;
      case 6: lyric1 = "   It was a cube about fifteen feet on a side, and it was made of \n"+
                       "some completely transparent material.  Indeed, it was not easy to \n"+
                       "see except when a power source of light glints on its edges.  There\n";
              lyric2 = "were no natural objects to which Moonwatcher could compare this \n"+
                       "apparition.\n";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;
      case 7: lyric1 = "   Though he was wisely cautious of most new things, he did not \n"+
                       "hesitate to walk up to it.  As nothing happened, he put out his\n"+
                       "hand, and felt a warm, hard surface.  After several minutes of\n";
              lyric2 = "intense thought, he arrived at a brilliant explanation:\n";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;
      case 8: lyric1 = "   'It is a rock, of course, and it must have grown during the\n"+
                       "night.  There are many plants that do this - white, pulpy things\n"+
                       "shaped like pebbles, that seem to shoot up in the hours of darkness.'\n";
              lyric2 = "";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;
      case 9: lyric1 = "   It was true that they were small and round, whereas this one was\n"+
                       "large and square, but greater and later philosophers than Moonwatcher\n"+
                       "would be prepared to overlook equally striking exceptions to their\n";
              lyric2 = "laws.\n";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;
      case 10: lyric1 = "   This really superb piece of abstract thinking lead Moonwatcher\n"+
                       "to a deduction which he immediately put to the test:\n"+
                       "'The white, round pebble-plants are very tasty (though there were\n";
              lyric2 = "a few that made one violently sick) perhaps this square one...?'\n"+
                       "A few licks and attempted nibbles quickly disillusioned him. \n"+
                       "There was no nourishment here.  So like a sensible hominid, he\n";
              lyric3 = "continued on his way to the river and forgot all about the Monolith.\n";
              lyric4 = "";
              lyric5 = "\n";break;
      case 11: lyric1 = HIR+"The Narrator closes his eyes and returns to his deep thoughts.\n";
              lyric2 = "";
              lyric3 = "";
              lyric4 = "";
              lyric5 = "\n";break;}

      tell_room(environment(this_player()),HIW+lyric1+NORM);
      tell_room(environment(this_player()),HIW+lyric2+NORM);
      tell_room(environment(this_player()),HIW+lyric3+NORM);
      tell_room(environment(this_player()),HIW+lyric4+NORM);
      tell_room(environment(this_player()),HIW+lyric5+NORM);
   return 1; }


