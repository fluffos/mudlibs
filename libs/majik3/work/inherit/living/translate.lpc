/*
 * /inherit/living/translate.c 					^l parsing for languages
 * 
 * coded by dazzt
 * */


string translate(string str)
{
	string *lans = ({ "alande", "kvanya", "uruzden", "draz", "ohrim", "sartog",
		    "grahnik", "hgrzag", "palen", "choui", "yavahe", "ugal", "tzhimsal",
		    "yiunda", "0" });

	int i, sl;
	string lang, msg, *l, s;
	
	s = "";
	l = explode(str, "^l");
	for (i = 0, sl = sizeof(l); i < sl; i++)
	{
		if (sscanf(l[i], "%s %s", lang, msg) == 2)
		{
			if (member_array(lang, lans) != -1)
			{
				if ((i || str[0..1] == "^l"))
                    s += (lang == "0" ? msg : "/daemon/language"->scramble(lang, THOB->query_skill_chance(lang), msg));
				else
					s += lang + " " + msg;
				continue;
			}
			else
			{
				s += ((i || str[0..1] == "^l") ? "^l" : "") + lang + " " + msg;
				continue;
			}
			s += lang + " " + msg;
			continue;
		}
		s += l[i];
	}
	return s;
}

	
