// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/skill_handling.inc
// Description: valid-skill-checking
// Author:	Francis
// Modified by: Freaky, Garthan (16.10.96) optimierung der spiele- und quest-
//		  Skillbeschreibungen.
//              Parsec  24.03.99  Variable Maximalskills eingefuehrt
//
//
// $Log: skill_handling.inc,v $
// Revision 1.5  2001/02/03 13:43:08  sissi
// Stock - Skill hinzugefuegt.
//
// Revision 1.4  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

/*
 * Nur Skill-Pfade, die hier eingetragen sind duerfen auch gesetzt werden.
 */
static mixed *skills;
static mapping skill_strings;

private void get_skills() {
 skill_strings=([]);

 skills = ({ ({ "skill",
 ({ ({ "offensiv", ({ ({ "scharf", ({ ({ "schwert", ({
                                            ({ "kurzschwert", 0, MAX_SKILL }),
					    ({ "langschwert", 0, MAX_SKILL })
						    })
				      }),
				      ({ "messer",     0, MAX_SKILL }),
				      ({ "saebel",     0, MAX_SKILL }),
				      ({ "degen",      0, MAX_SKILL }),
				      ({ "axt",        0, MAX_SKILL }),
				      ({ "speer",      0, MAX_SKILL }),
				      ({ "wurfmesser", 0, MAX_SKILL }),
				      ({ "bogen",      0, MAX_SKILL }),
				      ({ "blasrohr",   0, MAX_SKILL })
				   })
		      }),
		      ({ "stumpf", ({ ({ "schleuder", 0, MAX_SKILL }),
				      ({ "keule",     0, MAX_SKILL }),
				      ({ "peitsche",  0, MAX_SKILL }),
                                      ({ "stock",     0, MAX_SKILL })
				   })
		      }),
		      ({ "haende", 0, MAX_SKILL })
		   })
    }),
    ({ "defensiv", ({ ({ "schild", ({ ({ "klein", 0, MAX_SKILL }),
				      ({ "gross", 0, MAX_SKILL })
				   })
		      })
		   })
    }),
    ({ "zauber", ({ ({ "licht",     0, MAX_SKILL }),
		    ({ "abwehr",    0, MAX_SKILL }),
		    ({ "sicht",     0, MAX_SKILL }),
		    // ({ "nehmen", 0, MAX_SKILL }),
		    // ({ "tarnen", 0, MAX_SKILL }),
                    // ({ "suche",  0, MAX_SKILL }),
		    ({ "bewerte",   0, MAX_SKILL })
		 })
    }),
    /*
    ({ "magie", ({ ({ "offensiv",      0, MAX_SKILL }),
		    ({ "defensiv",     0, MAX_SKILL }),
		    ({ "information",  0, MAX_SKILL }),
		    ({ "manipulation", 0, MAX_SKILL }),
		    ({ "illusion",     0, MAX_SKILL })
		 })
    }),
    */
    ({ "getoetet", ({ ({ "grosswild",   0, MAX_SKILL }),
		      ({ "kleingetier", 0, MAX_SKILL })
		   })
    }),
    ({ "wissen", ({ ({ "navigation", 0, MAX_SKILL }),
		    ({ "erforscht",  0, MAX_SKILL * 2 }),
		    ({ "reise",      0, MAX_SKILL / 2 }),
		    ({ "gesehen",    0, MAX_SKILL }),
		    ({ "handeln",    0, MAX_SKILL * 2 })
		 })
    }),
    /*
    ({ "handwerk", ({ ({ "stehlen", 0, MAX_SKILL })
		   })
    })
    */

}) }) });

}

int valid_skill(string *path) {
	int a, b, found;
	mixed *sub;
	object ob;

    if (!sizeof(path))
	return 0;
#if 0
    if (find_player("freaky"))
	for (a=0; a<caller_stack_depth(); a++)
	     tell_object(find_player("freaky"),sprintf("%d:%O:\n",a,previous_object(a)));
#endif

    if ((ob = previous_object(2)) &&
	object_name(ob) == QUEST_ROOM
	   ||
        this_interactive() &&
	(
	  adminp(this_interactive())
	    ||
          sizeof(path) >= 3 && path[0] == "skill" &&
	    ( path[1] == "spiel" &&
	      member((string*)FILED->query_auth("spiele"),
	         this_interactive()->query_real_name()) >= 0
		 ||
	      path[1] == "raetsel" &&
	      member((string*)FILED->query_auth("raetsel"),
		 this_interactive()->query_real_name()) >= 0
	    )
	)
        )
        return 1;

    sub = skills;
    for (a=0; a<sizeof(path); a++) {
        if (!sub)
            return 0;
        if (sizeof(sub) <= 0)
            return 1;
        found = 0;
        for (b=0; b<sizeof(sub); b++)
            if (sub[b][0] == path[a]) {
                sub = sub[b][1];
                found = 1;
                break;
                }
        if (!found)
            return 0;
        }
    if (!sub)
        return 1;
    return 0;
}


int query_max_skill( string *path)
{
    int     a, b, found, max;
    mixed   *sub;
    object  ob;

    if ( !sizeof(path) )
	return 0;

    if ( sizeof( path) >= 3 && path[0] == "skill" )
    {
        if ( path[1] == "spiel" )
            return (int) GAME_ROOM->query_game_points( path[2]) ;
        if ( path[1] == "raetsel" )
            return (int) QUEST_ROOM->query_quest_points( path[2]) ;
    }

    sub = skills;
    for ( a = 0 ; a < sizeof( path) ; a++ )
    {
	max = 0 ;

	if (!sub)
	    return 0;
	if ( sizeof( sub) <= 0)
	    return 0;

	found = 0;
	for ( b = 0 ; b < sizeof( sub) ; b++ )
	    if (sub[b][0] == path[a])
            {
                if ( sizeof( sub[b]) == 3 &&
                     sub[b][1] == 0       &&
                     intp( sub[b][2]) )
                    max = sub[b][2] ;

		sub = sub[b][1];
		found = 1;
		break;
            }

	if (!found)
	    return 0;
    }

    return max ;
}


private string *read_skill_strings(string unique) {
    string content, *strings;

    if (!unique || !(content = read_file(unique)) || content == "")
	return 0;
    strings = explode(content,"\n")-({""});
    if (sizeof(strings)) {
	skill_strings[unique]=strings;
	return strings;
	}
}

string *search_skill_strings(string unique) {
    string *strings;

    if (!unique)
	return 0;
    strings=skill_strings[unique];
    if (!strings)
	return read_skill_strings(unique);
    return strings;
}

string get_quest_string(string *path, int amount, string gender)
{
   int selection, i, a, num;
   mixed *skill_info;
   mixed skill_text;
   object qg_obj;

   if(!(qg_obj = ({object})QUEST_ROOM->query_quest_object(path[2])))
      return 0;
   if(!(skill_info = ({mixed *})qg_obj->query_skill_msgs()))
      return 0;
   if(!pointerp(skill_info[0]))
      return 0;
   if(!pointerp(skill_info[1]))
   {
      num = sizeof(skill_info[0]);
      // selection = amount*(num-1)/({int})QUEST_ROOM->query_quest_points(path[2],0);
      selection = amount*(num-1)/({int})qg_obj->query_points(0);
      skill_text = skill_info[0][selection >= num ? num-1 : selection];
      if(pointerp(skill_text))
         return skill_text[member(({"maennlich","weiblich"}),gender)+1];
      else
         return skill_text;
   }
   else
      for(i = 0, a = sizeof(skill_info[0]); i < a; i++)
         if(amount >= skill_info[1][i] && (i==a-1||amount<skill_info[1][i+1]))
	    if(pointerp(skill_text = skill_info[0][i]))
	       return skill_text[member(({"maennlich","weiblich"}),gender)+1];
	    else
	       return skill_text;
}

string get_game_string(string *path, int amount, string gender)
{
   int selection, i, a, num;
   mixed *skill_info;
   mixed skill_text;
   object qg_obj;

   if(!(qg_obj = ({object})GAME_ROOM->query_game_object(path[2])))
      return 0;
   if(!(skill_info = ({mixed *})qg_obj->query_skill_msgs()))
      return 0;
   if(!pointerp(skill_info[0]))
      return 0;
   if(!pointerp(skill_info[1]))
   {
      num = sizeof(skill_info[0]);
      /*
      selection = amount*(num-1)/({int})GAME_ROOM->query_game_points(path[2],0);
      */
      selection = amount*(num-1)/({int})qg_obj->query_points(0);
      skill_text = skill_info[0][selection >= num ? num-1 : selection];
      if(pointerp(skill_text))
         return skill_text[member(({"maennlich","weiblich"}),gender)+1];
      else
         return skill_text;
   }
   else
      for(i = 0, a = sizeof(skill_info[0]); i < a; i++)
         if(amount >= skill_info[1][i] && (i==a-1||amount<skill_info[1][i+1]))
	    if(pointerp(skill_text = skill_info[0][i]))
	       return skill_text[member(({"maennlich","weiblich"}),gender)+1];
	    else
	       return skill_text;
}

string get_skill_string(string *path, int amount, string gender) {
    string unique, *strings, suffix;
    int num, max;

    if(!sizeof(path))
	return 0;

    if(sizeof(path) == 3)
       switch(path[1])
       {
	  case "spiel"   :
	     return get_game_string(path, amount, gender);
	  case "raetsel" :
	     return get_quest_string(path, amount, gender);
       }

    unique = implode(path,"/");
    if (gender == "weiblich")
	suffix = ".w";
    else if (gender == "maennlich")
	suffix = ".m";
    else
	suffix = ".s";
    strings = search_skill_strings(SKILL_PATH_STRINGS+"/"+unique+suffix);
    if (!strings)
	strings = search_skill_strings(SKILL_PATH_STRINGS+"/"+unique);
    if (!(num = sizeof(strings)))
	return 0;

#if 0
    // Alte Obergrenzenberechnung. Wert 4000 = 8/9 * MAX_SKILL
    max=AVERAGE_EXPERIENCE+(((MAX_SKILL-AVERAGE_EXPERIENCE)*2)/3);
#else
    // Angebpasst auf variable Max-Skills, AVERAGE_EXPERIENCE eleminiert
    max = (query_max_skill( path) * 8 / 9) ;
#endif
    if (amount >= max)
	return strings[<1];
    return strings[(num-1)*amount/max];
}
