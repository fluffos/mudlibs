// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/format.inc
// Description:	Hilfsdatei zu /secure/event.c
// Author:	Garthan
//
// $Log: format.inc,v $
// Revision 1.15  2016/01/22 17:20:53  myonara
// ev_hilferuf ergaenzt.
//
// Revision 1.14  2013-03-16 15:54:08  gnomi
// ev_ueberfall() eingebaut.
//
// Revision 1.13  2009-03-20 08:14:46  gnomi
// Typo.
//
// Revision 1.12  2005/07/05 21:33:50  gnomi
// Typo.
//
// Revision 1.11  2004/07/04 00:19:02  gnomi
// Login/Logout-Meldung etwas verbessert...
//
// Revision 1.10  2003/11/06 04:03:36  gnomi
// Typo beim Notruf.
//
// Revision 1.9  2003/11/05 01:49:49  gnomi
// OOC: Bessere Formatierung.
// Notruf: Formatierungen fuer die Antwort an den Spieler.
//
// Revision 1.8  2003/11/04 03:25:09  gnomi
// Formatierung fuer den OOC- und Notruf-kanal.
//
// Revision 1.7  2003/07/31 00:48:05  menaures
// Levelaenderungkanal nun mit Levelnamen statt Nummern
//
// Revision 1.6  2003/05/10 17:36:59  menaures
// Bugfix zum vorhergehenden Patch
//
// Revision 1.5  2003/05/06 02:42:55  gnomi
// Kirchenabhaengige Todesmeldung eingebaut.
//
// Revision 1.4  2001/01/28 23:10:23  gnomi
// Beim real_namen nicht den Umweg ueber Der() gehen.
//
// Revision 1.3  2001/01/28 19:00:12  gnomi
// Bei Goetterkanaelen wird der real_name genutzt.
//

string real_Der(object who)
{
   if(!playerp(who)) return Der(who);
   return who->query_real_cap_name()||capitalize(who->query_real_name());
}

mixed real_Who(object who)
{
   if(!playerp(who)) return who;
   return ([
    "name": 	who->query_real_name(),
    "cap_name":	who->query_real_cap_name(),
    "gender":	who->query_real_gender(),
   ]);
}

string ev_login(object who, string mess, mixed param)
{
   return INFO+real_Der(who)+" betritt "+(IS_INVIS(who)?"unsichtbar ":"")+MUD_NAME+".\n";
}

string ev_logout(object who, string mess, mixed param)
{
   return INFO+real_Der(who)+" hat "+MUD_NAME+(param?" fuer immer":IS_INVIS(who)?" unsichtbar":"")+
	  " verlassen.\n";
}

string ev_netztod(object who, string mess, mixed mode)
{
   if(mode)
      return INFO+real_Der(who)+(random(15000)?" bricht aus ":" erbricht aus ")+
	 seinem((["gender":"weiblich","name":"statue"]),0,real_Who(who))+".\n";
   else
      return INFO+real_Der(who)+" erstarrt zu einer Statue.\n";
}

string ev_tod(object who, string mess, mixed param)
{
    string church = who->query_kirche();
    if(church)
    {
	church = church->get_death_message(who);
	if(church)
	    return church;
    }
   return 
   "Die Totenglocke 'Verdombde' traegt eine traurige Botschaft uebers Land:\n"+
   Der(who,"")+" ist tot!\n";
}

string ev_raetsel(object who, string mess, mixed param)
{
   if(mess)
      return wrap(mess);
   return INFO+Der(who)+" hat das Raetsel '"+param+"' geloest.\n";
}

string ev_spiele(object who, string mess, mixed param)
{
   if(mess)
      return wrap(mess);
   return INFO+Der(who)+" hat erfolgreich '"+param+"' gespielt.\n";
}

string ev_gott(object who, string mess, mixed param)
{
   if(param)
      return Der(who)+" gehoert nun der Engelsschar an.\n";
   return Der(who)+" wurde in den Kreis der Goetter aufgenommen.\n";
}

string ev_gilden(object who, string gilde, mixed mode)
{
   string gender, name;
   gender = GILDEN_OB->query_one_gilden_info(gilde,GILDEN_GESCHLECHT)
      || "weiblich";
   name = GILDEN_OB->query_one_gilden_info(gilde,GILDEN_NAME) || gilde;
   if(mode)
      return INFO+real_Der(who)+" ist "+dem((["name":name,"gender":gender]))+" beigetreten.\n";
   else
      return INFO+real_Der(who)+" ist aus "+dem((["name":name,"gender":gender]))+" ausgetreten.\n";
}

private string level_str(mixed level)
{
    switch(level)
    {
        case 0: return "Monster";
        case LVL_PLAYER: return "Spieler";
        case LVL_HLP: return "Engel";
        case LVL_LEARNER: return "Lehrling";
        case LVL_GESELLE: return "Geselle";
        case LVL_VOGT: return "Vogt";
        default: return to_string(level);
    }
}

string ev_level(object who, string mess, mixed param)
{
   string name;
   if(!(name = who->query_real_name()) && !(name = der(who)))
      return 0;
   return INFO+capitalize(name)+
	  " Levelaenderung: "+level_str(param[0])+" -> "+level_str(param[1])+".\n";
}

mixed ev_feedback(object who, string mess, mixed param)
{
   return stringp(param)?({mess,param}):mess;
}

string ev_ooc(object who, string mess, mixed param)
{
    return wrap_say("[OOC] "+real_Der(who)+":", mess);
}

string ev_notruf(object who, string mess, mixed param)
{
    if(!wizp(who))
	return wrap_say(real_Der(who)+" ruft das Pantheon um Hilfe:", mess);
    if(stringp(param) && strlen(param))
	return wrap_say(real_Der(who)+" antwortet zu "+param+":", mess);
    return wrap_say(real_Der(who)+" sagt zum Pantheon:", mess);
}

string ev_hilferuf(object who, string mess, mixed param)
{
    if (param)
        return wrap_say(real_Der(who)+" antwortet:", mess);
    return wrap_say(real_Der(who)+" ruft um Hilfe:", mess);
}

string ev_ueberfall(object taeter, string mess, object opfer)
{
    if(!playerp(taeter) || !playerp(opfer))
        return 0;
    return wrap_say("Ueberfall:", real_Der(taeter)+" greift "+real_Der(opfer)+" an.");
}
