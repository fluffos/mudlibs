// Ciaran Hargall, the City Elder from the information office

// created:       Auryn   [01-May-1999]

#include <npc.h>
#include <properties.h>


inherit "/std/npc";

void create()
{
  ::create();

  Set(P_NAME,"Ciaran Hargall");
  Set(P_RACE,"human");
  Set(P_LEVEL,10);
  Set(P_GENDER,1);


  Set(P_SHORT,"Ciaran Hargall, one of the City Elders");

  Set(P_LONG,
"You see an old man with short white hair and a neatly trimmed white beard. "
"His face is tanned and lined with deep wrinkles, telling of a long and not "
"always easy life. His eyes are the deep blue of a stormy sea and look at "
"you curiously. Ciaran might tell you a lot about the sights and the shops "
"of Silvere, if you ask him.\n");

  AddId( ({"elder","city elder","ciaran","hargall" }));


  AddQuestion( ({"ciaran","hargall"}),
	       "Ciaran says, "
	       "'Aye, friend, that's me name. And how can I help you?'\n");

  AddQuestion( "name",
	       "Ciaran says, "
	       "'Ciaran Hargall's me name, friend. I'm here to help you "
	       "find your way around Silvere.'\n" );

  AddQuestion( ({"city","silvere"}),
	       "Ciaran says, "
	       "'A beautiful city, don't you think? We have a lot of sights "
	       "to see... and of course there's the shops, too.'\n");

  AddQuestion( "help",
	       "Ciaran smiles and says, "
	       "'Just ask me about the things you'd like to know.'\n");

  AddQuestion( "sights",
	       "Ciaran says, "
	       "'Well, there's a lot of interesting places to visit around "
	       "the city... the palace, for example, the harbour, "
	       "the park...'\n");

  AddQuestion( "palace",
	       "Ciaran says, "
	       "'That's where our rulers live, the Lu'meyn and Lu'meyna. You "
	       "can find the palace if you follow Park Lane north until it "
	       "meets Westway, then follow Westway eastward.'\n");

  AddQuestion( ({"lu'meyn","lu'meyna","rulers"}),
	       "Ciaran says, "
	       "'The Lu'meyn and the Lu'meyna are our rulers, you would "
	       "probably call them our king and queen. Their title means "
	       "Guardian of Light.'\n");

  AddQuestion( ({"guardian","light"}),
	       "Ciaran says, "
	       "'Guardian of Light is the literal translation of the title "
	       "Lu'meyn or Lu'meyna. It is the title of our rulers.'\n");

  AddQuestion( ({"harbour"}),
	       "Ciaran says, "
	       "'Ah, the harbour, yes, quite a sight indeed... you'll find "
	       "it west of here. Just go north until you reach Westway, then "
	       "turn west. You'll also find the harbourmaster there, who "
	       "can tell you more about the harbour.'\n");

  AddQuestion( ({"harbourmaster","gregore","gregore d'angelina","d'angelina"}),
	       "Ciaran says, "
	       "'Yes, Gregore d'Angelina, very good man, that... anything "
	       "he doesn't know about the harbour isn't worth knowing.'\n");

  AddQuestion("westway",
	      "Ciaran says, "
	      "'Westway is the main road of the city. It leads from the "
	      "harbour to the palace. If you want to go shopping, look "
	      "around there.'\n");

  AddQuestion("park",
	      "Ciaran says, "
	      "'The park is south of here, just follow Park Lane and you'll "
	      "find it. Nice place to relax and have a picnic, if you're "
	      "in a mood for that.'\n");

  AddQuestion("shops",
	      "Ciaran says, "
	      "'Most of the shops are found along Westway. If you're looking "
	      "for fine goods, you should look around there.'\n");

SetShrugMsg(
"Ciaran looks up from his papers and smiles apologetically. He doesnt't "
"seem to know anything about this.\n");

}
