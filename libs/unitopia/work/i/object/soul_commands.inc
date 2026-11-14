// -*-C++-*--------------------------------------------------------- This
// file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /i/object/soul_commands.inc
// Description: Alle Emotions, die man mit der Seele ausdruecken kann
//              Aus der Seele zur Verkleinerung ausgelagert.
// Created by : Parsec
//
//
// Neue Seele-Befehle bitte in
//     /p/Doc/Lehre/Demo/room/soul-test-room.c
// testen.
//
//
// Modified by: Sissi  12.12.98: das total verkorxte Knuddeln
//                               wieder repariert.
//              Parsec 21.04.99: deute mit Richtungen
//              Parsec 24.09.99: Kommunikationskram nach voice verlegt
//              Parsec  7.07.00: Bugfix stupse
//              Sissi   7.07.00: Gruppenumarmung (ja, das ist Schwachsinn,
//                               aber genau das macht doch UNItopia so
//                               liebenswert)
// $Log: soul_commands.inc,v $
// Revision 1.56  2012-11-24 15:55:46  sorcerer
// Schoenheitskorrekturen nach Sins Vorschlag eingebaut
//
// Revision 1.55  2012-11-11 21:46:54  sorcerer
// Typo
//
// Revision 1.54  2009-04-15 13:38:10  gnomi
// Typo.
//
// Revision 1.53  2008-04-26 18:18:22  gnomi
// /p/parsec-Ueberbleibsel entfernt.
//
// Revision 1.52  2007/02/14 17:32:48  gnomi
// Einen Befehl vergessen gehabt.
//
// Revision 1.51  2007/02/14 17:26:21  gnomi
// Diverse Befehle auch fuer Dinge erlauben.
//
// Revision 1.50  2006/05/01 00:41:23  gnomi
// wuschle -> wuschel (einheitliches Verb fuer die Controller)
//
// Revision 1.49  2005/02/20 22:25:30  sissi
// Fehler bei gu_bekannt behoben: Initiator bekam auch Meldung, falls
// er sie initiiert hat, ohne jemals teilgenommen zu haben.
//
// Revision 1.48  2005/02/19 23:28:21  sissi
// Fehler beim Schnurren behoben.
//
// Revision 1.47  2005/01/23 12:52:21  sissi
// Beim Verwuscheln von Lebewesen wird nun die Rasse beruecksichtigt,
// sodass dann Federn, Blaetter, Fuehler oder Schuppen verwuschelt werden.
//
// Revision 1.46  2004/05/13 21:42:47  gnomi
// Gruppenumarmung: msg_write statt msg_notify fuer Erfolgsmeldungen nutzen.
// MA_EMOTE statt MA_LOOK nehmen.
//
// Revision 1.45  2004/02/26 20:48:24  gnomi
// Pflanzen kann man nicht ans Bein pinkeln...
//
// Revision 1.44  2003/12/05 22:55:52  sissi
// Stupse-Meldung etwas umgestupst.
//
// Revision 1.43  2003/10/30 07:59:30  sissi
// Man schmollt nur noch in Innenraeumen in der Ecke, sonst in der
// Gegend herum.
//
// Revision 1.42  2003/05/28 01:04:57  gnomi
// notify_move statt Follower nutzen.
//
// Revision 1.41  2003/03/02 21:41:12  sissi
// Deuten auf Pflanzen geaendert.
//
// Revision 1.40  2003/02/18 01:21:37  gnomi
// Die meisten Seelebefehle des Kuschelis eingebaut.
// Dank an Caradhras und Mammi.
//
// Revision 1.39  2003/02/02 03:20:37  gnomi
// Typo.
//
// Revision 1.38  2003/02/01 02:44:26  gnomi
// kitzle: Darauf achten, dass keine Kuerzel bei der Reaktion genutzt werden.
//
// Revision 1.37  2002/11/25 22:58:13  sissi
// Man kann Pflanzen nicht wuscheln, aber dafuer Stupsen, aber nicht auf
// die Nase sondern auf ne Bluete (die gesucht wird) oder Blaetter (die
// gesucht werden).
//
// Revision 1.36  2002/11/20 04:10:13  gnomi
// deute-Fehlermeldung korrigiert.
//
// Revision 1.35  2002/09/26 20:49:27  gnomi
// DInge bekommen keine Gaensehaut.
//
// Revision 1.34  2002/09/11 22:42:33  gnomi
// Orks werden nicht mehr aufgefordert Orks platt zu machen.
//
// Revision 1.33  2002/06/17 00:29:57  gnomi
// Bei einigen Befehlen testen, ob man im flachen Wasser steht.
//
// Revision 1.32  2002/06/15 15:36:58  gnomi
// Typo (Du patschst)
//
// Revision 1.31  2002/02/23 05:19:57  gnomi
// PO/PL -> SOUL_PO/PL
//
// Revision 1.30  2001/10/10 23:56:42  sissi
// beim Wuscheln: statt diesesistdir leider im Weg jetzt dieses ist dir leider
// im Weg.
//
// Revision 1.29  2001/10/09 02:49:00  gnomi
// An diversen stellen "ist" durch ist() ersetzt.
//
// Revision 1.28  2001/09/29 23:26:22  sissi
// Mudlibkonformere Formatierung
// Knuddle nur noch mit Lebewesen
// Man jammert jetzt ueber die Goetter / die Spieler und die Welt
//
// Revision 1.27  2001/09/20 21:48:39  sissi
// Hinweis, dass man Gruppenumarmung mit gu abkuerzen kann.
//
// Revision 1.26  2001/04/19 12:56:55  freaky
// Typo gefixed.
//
// Revision 1.25  2001/03/23 01:20:02  gnomi
// Schauen, ob man die Umgebung als Partner nehmen kann.
//
// Revision 1.24  2001/03/22 01:40:41  gnomi
// Stolper hat PSEUDO_MOVE als Flag.
//
// Revision 1.23  2001/03/04 22:55:26  gnomi
// An einer Stelle zu viel ersetzt.
//
// Revision 1.22  2001/03/04 22:52:00  gnomi
// Anstatt living livingp nutzen. (Letzteres akzeptiert auch lebende V-Items.)
//
// Revision 1.21  2001/02/21 00:01:35  sissi
// Pfeife, Reibe ueberarbeitet.
//
// Revision 1.20  2001/02/12 00:13:31  gnomi
// level.h includen.
//
// Revision 1.19  2001/02/04 22:23:42  freaky
// weine: korrekter soul-aufruf eingebaut.
//
// Revision 1.18  2001/01/30 22:17:37  sissi
// stupse mich, wie es per Goetterabstimmung recht deutlich beschlossen wurde,
// CVS Log eingebaut.
//
//


#include <room.h>
#include <message.h>
#include <level.h>
#include <landschaft.h>

int gruppenumarmung_bekannt;

#define IM_WASSER_SCHWIMMEND	(query_im_wasser(ENV(owner)) && !(ENV(owner)->query_type(LANDSCHAFT)&L_FLACH))


/*
----------------------------------------------------------------------------
Jetzt alle Emotions, die man mit der Seele ausdruecken kann, in
alphabetischer Reihenfolge
----------------------------------------------------------------------------
*/


int achsel(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "zuck",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                          "mit den Schultern");
}


int aechze(string str)
{
    //    NO_GHOST;
    return soul_plus_adv(str, "aechz",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          "vor Anstrengung");
}


int anschmiege(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, PARTNER, "an"), "schmieg", NETT, 0,
        MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
        ({"dich an","sich an"}), "an", FALL_AKK,
        "Schmiege dich an wen oder was <wie> an?");
}


int applaudiere(string str)
{
    NO_GHOST;

    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "applaudier", 0, NETT, 0,
            "Du applaudierst von ganzem Herzen.",
            Wer(owner, ART_AAA)+" gibt eine Runde Applaus.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;
        feel(owner);
        return 1;
    }
    else
        return
            soul_adv_part(
                soul_parser(str, IGNORE_FAR),
                "applaudier", NETT, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
                0, 0, FALL_DAT);
}

int argl(string str)
{
    return soul_plus_adv(str, "argl",
	NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
	"herum");
}

int baggere(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "bagger", 0, MIES, 0,
            "Du baggerst ein bisschen herum.",
            Wer(owner, ART_AAA)+" baggert bloede rum.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
        feel(owner);
        return 1;
    }
    else
        return soul_adv_part(
            soul_parser(str, LIVING),
            "bagger", MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
            0, "an", FALL_AKK);
}


int bedauere(string str)
{
    NO_GHOST;
    return
        soul_adv_part(
            soul_parser(str, PARTNER | IGNORE_FAR),
            "bedauer", NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
            0, 0, FALL_AKK,
            "Bedauere wen oder was <wie>?");
}


int begruesse(string str)
{
    mixed *res;

    res = soul_parser(str, PARTNER);

    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Begruesse wen <wie>?");
        return 1;
    }
    if(res[0]==owner)
    {
        msg_notify("Du bist dir selbst wohl noch nicht vorgestellt worden?");
        return 1;
    }
    if (res[1]=="")
        res[1]=" stuermisch";

    if(livingp(res[0]))
    {
	if (forbidden_msg_soul_action_partner_notify(
    	res[0], "begruess", res[1], NETT, 0,
        "Vor lauter Freude, "+xdeinen(res[0])+" zu sehen, faellst du "
          +ihm(res[0])+res[1]+" um "
          +seinen((["name":"hals","gender":"maennlich"]),0,res[0])+".",
        "Vor lauter Freude, "+xdich(res[0])+" zu sehen, faellt "+
          xdir(res[0])+" "+wer(owner, ART_AAA)+res[1]+" um deinen Hals.",
        "Vor lauter Freude, "+xseinen(res[0])+" zu sehen, faellt "+wer(owner, ART_AAA)
          +" "+ihm(res[0])+res[1]+" um "
          +seinen((["name":"hals","gender":"maennlich"]), 0,res[0])+".",
        MA_EMOTE, MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK | MT_NOISE))
    	    return 1 ;
    }
    else
    {
	if (forbidden_msg_soul_action_partner_notify(
    	res[0], "begruess", res[1], NETT, 0,
        "Vor lauter Freude, "+xdeinen(res[0])+" wiederzusehen, umarmst du "
          +ihn(res[0])+res[1]+".",
        "Vor lauter Freude, "+xdich(res[0])+" widerzusehen, umarmt "
	  +wer(owner, ART_AAA)+" "+xdich(res[0])+res[1]+".",
        "Vor lauter Freude, "+xseinen(res[0])+" wiederzusehen, umarmt "
	  +wer(owner, ART_AAA)+" "+ihn(res[0])+res[1]+".",
        MA_EMOTE, MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK | MT_NOISE))
    	    return 1 ;
    }
    
    feel(owner);
    return 1;
}


int bewundere(string str)
{
//    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, PARTNER | IGNORE_FAR),
        "bewunder", NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
        0, 0, FALL_AKK,
        "Bewundere wen oder was <wie>?");
}


int blinzle(string str)
{
    NO_GHOST;

    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "blinzel", 0, NEUTRAL, 0,
            "Du blinzelst. Hast du vielleicht Sand in den Augen?",
            Wer(owner, ART_AAA)+" blinzelt. Hat "+er(owner)+" vielleicht "
            "Sand in den Augen?",
            MA_EMOTE, MT_LOOK))
            return 1 ;
        feel(owner);
        return 1;
    }
    else
        return soul_adv_part(
            soul_parser(str, IGNORE_FAR),
            "blinzel", NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
            0, "zu", FALL_DAT);
}


int boxe(string str)
{
    mixed res;

    NO_GHOST;

    res = soul_parser(str);
    if (!sizeof(res))
        return 1;

    if (livingp(res[0]))
        return soul_adv_part(res, "box",
                              MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                              0, "in die Rippen", FALL_DAT);
    else
        return soul_adv_part(res, "box",
                              MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                              0, 0, FALL_AKK);
}


int brumme(string str)
{
    NO_GHOST;
    return soul_adv_part(soul_parser(str, IGNORE_FAR), "brumm",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
                          "", "an", FALL_AKK);
}


int daeumle(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "dreh",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                          "Daeumchen");
}


int danke(string str)
{
//    NO_GHOST;
    return soul_adv_part(soul_parser(str, PARTNER), "dank",
                          NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                          0, 0, FALL_DAT,
                          "Danke wem oder was <wie>?");
}


int deute(string str)
{
    mixed  *parsed, wer;
    int    flag;
    string tmp, tmp2 ;

    NO_GHOST;

    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "deut", 0, NEUTRAL, 0,
            "Du deutest wild in der Gegend herum.",
            Wer(owner, ART_AAA)+" deutet wild und ziellos in der Gegend herum.",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }

    str = space(str) ;
    parsed = parse_com((strlen(str)>4 &&
                         lower_case(str[0..3])=="auf ") ?
                        str[4..<1] : str);

    if (parsed[PARSE_RET_CODE] != PARSE_OK)
    {
        str = regreplace(str, "nach ", "", 1) ;
        tmp = ([
            "rauf"       : "rauf",
            "oben"       : "nach oben",
            "unten"      : "nach unten",
            "h"          : "hoch",
            "hoch"       : "hoch",
            "r"          : "runter",
            "runter"     : "runter",
            "n"          : "nach Norden",
            "norden"     : "nach Norden",
            "s"          : "nach Sueden",
            "sueden"     : "nach Sueden",
            "w"          : "nach Westen",
            "westen"     : "nach Westen",
            "o"          : "nach Osten",
            "osten"      : "nach Osten",
            "nw"         : "nach Nordwesten",
            "nordwesten" : "nach Nordwesten",
            "so"         : "nach Suedosten",
            "suedosten"  : "nach Suedosten",
            "no"         : "nach Nordosten",
            "nordosten"  : "nach Nordosten",
            "sw"         : "nach Suedwesten",
            "suedwesten" : "nach Suedwesten",
            ])[str] ;

        if (tmp)
        {
            // In die Standardrichtungen kann man immer deuten
            if (forbidden_msg_soul_action_notify(
                "deut", tmp, NEUTRAL, 0,
                "Du deutest "+tmp+".",
                Wer(owner, ART_AAA)+" deutet "+tmp+".",
                MA_EMOTE, MT_LOOK))
                return 1 ;
            return 1 ;
        }
        else if (environment(owner)->query_one_exit(str))
        {
            tmp = "in Richtung "+CAP(str) ;
            if (environment(owner)->query_exit_flag(
                str, EXIT_ATOM_NOT|EXIT_ATOM_HIDDEN|EXIT_ATOM_LOCKED))
                // sichtbare oder nolist-Ausgaenge, keine Hidden oder locked
                tmp2 = tmp ;
            else
                tmp2 = "in die Gegend" ;

            if (forbidden_msg_soul_action_notify(
                "deut", tmp, NEUTRAL, 0,
                "Du deutest "+tmp+".",
                Wer(owner, ART_AAA)+" deutet "+tmp2+".",
                MA_EMOTE, MT_LOOK))
                return 1 ;
            return 1 ;
        }
    }

    if(parse_com_error(parsed, "Deute worauf?\n",
        "Auf mehrere Dinge gleichzeitig kannst du nicht deuten.\n"))
            return 0;

    wer = parsed[PARSE_OBS][0] ;

    if (wer == owner)
    {
        if (forbidden_msg_soul_action_partner_notify(
            wer, "deut", 0, NEUTRAL, 0,
            "Du deutest auf dich.",
            0,
            Wer(owner, ART_AAA)+" deutet auf sich.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }
    else
    {
        flag = livingp(wer);

        if (forbidden_msg_soul_action_partner_notify(
            wer, "deut", 0, NEUTRAL, 0,
            "Du deutest auf "+xdeinen(wer)+"."+
              (flag ? " Mit nackten Fingern deutet man doch nicht einfach auf "
               + (pflanzlichp(wer)?"Pflanzen!":"Lebewesen!")
               :""),
            Wer(owner, ART_AAA)+" deutet auf "+xdich(wer)+".",
            Wer(owner, ART_AAA)+" deutet auf "+xseinen(wer)+".",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }

    feel(owner);
    return 1;
}


int drohe(string str)
{
    mixed res;
    // object *who;

    NO_GHOST;
    res = soul_parser(str, IGNORE_FAR);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Drohe wem oder was?");
        return 1;
    }

    // who = objectp(res[0])?({res[0],owner}):({owner});


    if (forbidden_msg_soul_action_partner_notify(
        res[0], "droh", 0, NEUTRAL, 0,
        "Du hebst drohend den Zeigefinger, siehst fest "+
          xdeinen(res[0])+" an, wedelst den Zeigefinger leicht hin und her und "
          "sagst dazu: Du, Du, Du!",
         Wer(owner, ART_AAA)+" hebt drohend den Zeigefinger, "
           "sieht "+xdich(res[0])+
           " fest an, wedelt den Zeigefinger leicht hin und her "
           "und sagt dazu: Du, Du, Du!",
        Wer(owner, ART_AAA)+" hebt drohend den Zeigefinger, sieht "+xseinen(res[0])+
          " fest an, wedelt den Zeigefinger leicht hin und her und "
          "sagt dazu: Du, Du, Du!",
        MA_EMOTE, MT_LOOK | MT_NOISE))
        return 1 ;

    feel(owner) ;
    return 1;
}


int druecke(string str)
{
    NO_GHOST;

    if (zustand != SEELE && me(str))
    {
        if (forbidden_msg_soul_action_partner_notify(
            TO, "drueck", 0, NETT, 0,
            "Du drueckst "+xdeinen()+" liebevoll an dich. "+
              Er()+" ist weich und flauschig, und du wuenschst dir, "
              "Du koenntest "+ihn()+" fuer immer so im Arm halten. "
              "Nur sehr widerwillig laesst du "+ihn()+
              " schliesslich wieder los.",
            Wer(owner, ART_AAA)+" drueckt sich ganz fest an dich ran.",
            Wer(owner, ART_AAA)+" drueckt "+xseinen()+
              " ganz lieb zu sich hin. "+
              Er(owner)+" scheint "+ihn()+" gar nicht mehr loslassen "
              "zu wollen.",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
        return 1 ;
    }

    return soul_adv_part(
        soul_parser(str,PARTNER),
        "drueck", NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
        0, 0, FALL_AKK,
        "Druecke wen oder was <wie>?");
}


int entmanne(string str)
{
    mixed   res;

    NO_GHOST;
    res = soul_parser(str,SOUL_PL | SOUL_PO | NOT_TO_ENV);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Entmanne wen <wie>?");
        return 1;
    }
    if(res[0] == owner)
    {
        msg_notify("Bist du eine Gummipuppe, oder wie willst du das machen?");
        return 1;
    }
    if (in_mir(res[0]))
    {
        msg_notify(
            "Bist du eine Gummipuppe, oder wie willst du das machen, "
            "solange du "+den(res[0])+" bei dir traegst?");
        return 1;
    }

    if (res[1]=="") res[1] = " ploetzlich";

    if (res[0]->query_gender() == "maennlich")
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "entmann", res[1], MIES, 0,
            "Du triffst "+xdeinen(res[0])+res[1]+" mit deinem Knie.",
            Wer(owner, ART_AAA)+" tritt "+xdir(res[0])+""+res[1]+" mit "+
              seinem((["gender":"saechlich","name":"knie"]),0,owner)+
              " in deine Weichteile! "+xDir(res[0])+
              " bleibt die Luft weg, "+xdu(res[0])+" "+
              ((query_im_wasser(ENV(owner))) ?
               "sackst in "+xdich(res[0])+" zusammen" : "faellst zu Boden")+
              " und kruemmst "+xdich(res[0])+" vor "
              "unsagbaren Schmerzen, wie wenn "+xdu(res[0])+" gleich alles "
              "auskotzen muesstest!",
            Wer(owner, ART_AAA)+" hebt"+res[1]+" "+
              seinen((["gender":"saechlich","name":"knie"]),0,owner)+
              " und schickt "+den(res[0]) +
              " sich vor Schmerz kruemmend auf den Boden!",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
    }
    else {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "entmann", res[1], MIES, 0,
            "Du versuchst einen Knieschlag bei "+xdeinem(res[0])+
              ". Nicht sehr erfolgreich, wie auch!",
            Wer(owner, ART_AAA)+" hebt"+res[1]+" "+
              seinen((["gender":"saechlich","name":"knie"]),0,owner)+
              ", ohne viel Erfolg.",
            Wer(owner, ART_AAA)+" versucht "+xseinen(res[0])+res[1]+
              " mit dem Knie zu treffen, ohne viel Erfolg.",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
    }

    feel(owner);
    return 1;
}



int entschuldige(string str)
{
    mixed   res;
    string  wie;


//    NO_GHOST;

    if (str)
    {
        if (str[0..4] == "mich ") str = str[5..];
        else if (str[0..4] == "dich ") str = str[5..];
        if (str[0..4] == "beim ") str = str[5..];
        else if (str[0..3] == "bei ") str = str[4..];
    }
    else
    {
        msg_notify("Entschuldige dich bei <wem> <wie>?");
        return 1;
    }
    res = soul_parser(str, PARTNER);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Entschuldige mich bei <wem> <wie>?");
        return 1;
    }
    if(res[0] == owner)
    {
       msg_notify(
           "Oh, das waere sinnlos, da du dir ja eh nie verzeihen wuerdest. "
           "Oder?");
       return 1;
    }

    if (res[1]=="") res[1] = " zaehneknirschend";

    if (query_im_wasser(ENV(owner)) || res[0]==ENV(owner))
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "entschuldige", res[1], NETT, 0,
            "Du flehst "+xdeinen(res[0])+res[1]+" um Verzeihung an.",
            Wer(owner, ART_AAA)+" fleht "+
              xdich(res[0])+""+res[1]+" um Verzeihung an.",
            Wer(owner, ART_AAA)+" fleht "+
              xseinen(res[0])+res[1]+" um Verzeihung an.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;
    }
    else
    {
        if (in_mir(res[0]))
        {
            if (forbidden_msg_soul_action_partner_notify(
                res[0], "entschuldige", res[1], NETT, 0,
                "Du faellst auf die Knie und flehst "+xdeinen(res[0])+res[1]+
                  " um Verzeihung an.",
                Wer(owner, ART_AAA)+" wirft sich auf die Knie "
                  "und fleht "+xdich(res[0])+""+res[1]+" um Verzeihung an.",
                Wer(owner, ART_AAA)+" wirft sich auf die Knie und fleht "+
                  xseinen(res[0])+res[1]+" um Verzeihung an.",
                MA_EMOTE, MT_LOOK | MT_NOISE))
                return 1 ;
        }
        else
        {
            if (forbidden_msg_soul_action_partner_notify(
                res[0], "entschuldige", res[1], NETT, 0,
                "Du faellst vor "+xdeinem(res[0])+" auf die Knie und flehst"+
                  res[1]+" um Verzeihung.",
                Wer(owner, ART_AAA)+" wirft sich vor "+xdir(res[0])+" auf die Knie "
                  "und fleht"+res[1]+" um Verzeihung.",
                Wer(owner, ART_AAA)+" wirft sich vor "+xseinem(res[0])+" auf die Knie "
                  "und fleht"+res[1]+" um Verzeihung.",
                MA_EMOTE, MT_LOOK | MT_NOISE))
                return 1 ;
        }
    }

    feel(owner);
    return 1;
}


int erbleiche(string str)
{
    NO_GHOST;

    str = (!str || str=="") ? "" : " "+str;

    if (forbidden_msg_soul_action_notify(
        "erbleich", str, NEUTRAL, 0,
        "Alle Farbe weicht aus deinem Gesicht. Du erbleichst"+str+".",
        "Alle Farbe weicht aus "+
          ihrem((["name":"gesicht","gender":"saechlich"]),0,owner)+". "+
          Wer(owner, ART_AAA)+" erbleicht"+str+".",
        MA_EMOTE, MT_LOOK))
        return 1 ;

    feel(owner);
    return 1;
}


int erroete(string str)
{
    NO_GHOST;
    if (str)
        return soul_plus_adv(str, "erroete",
                              NEUTRAL, 0, MA_EMOTE, MT_FEEL, MT_LOOK);

    if (forbidden_msg_soul_action_notify(
        "erroet", str, NEUTRAL, 0,
        "Deine Wangen gluehen.",
        Wer(owner, ART_AAA)+" erroetet.",
        MA_EMOTE, MT_FEEL, MT_LOOK))
        return 1 ;

    feel(owner);
    return 1;
}


#ifdef dasistnochnichtfertig
int erschrecke (string str)
{
    mixed *res;

    // kein Konflikt mit dem Erschrecken der Vampyre:
    if (this_player()->query_gilde()=="Vampyrgilde") return 0;
    if (!str)
    {
        if (this_player()->query_ghost()
        {
            if (!forbidden_msg_soul_action_notify(
                "erschrick", 0, NEUTRAL, 0,
                "Du heulst ganz schrecklich, klapperst fuerchterlich mit "
                "deinen Zaehnen und rasselst schauderlich mit deiner "
                "rostigen Rasselkette.",
                Der(owner)+" heult ganz schrecklich, klappert fuerchterlich "
                "mit den Zaehnen und rasselt schauderlich mit der rostigen "
                "Rasselkette. Wie gruselig!",
                MA_EMOTE, MT_NOISE | MT_LOOK))
                feel (owner);
        }
        else if (!forbidden_msg_soul_action_notify(
                "erschrick", 0, NEUTRAL, 0,
                "Du fuchtelst aufgeregt in der Gegend herum, "
                "springst nervoes auf und ab, verdrehst die Augen und "
                "wackelst hektisch mit dem Kopf. Das ist bestimmt sehr "
                "erschreckend.",
                Der(owner)+" fuchtelt aufgeregt in der Gegend herum, "
                "springt nervoes auf und ab, verdreht die Augen und "
                "wackelt hektisch mit dem Kopf. Das ist alles ziemlich "
                "erschreckend.",
                MA_EMOTE, MT_NOISE | MT_LOOK))
                feel (owner);
        return 1;
    }

    res = soul_parser(str,SOUL_PL|NOT_TO_ENV);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        if (forbidden_msg_soul_action_notify(
            "erschrick", str, NEUTRAL, 0,
            "Du erschrickst Dich"+res[1]+".",
            Wer(owner, ART_AAA)+" erschrickt sich"+res[1]+".",
            MA_EMOTE, MT_LOOK))
    }
    else
    {
        if (this_player()->query_ghost()
        {
            if (!forbidden_msg_soul_action_partner_notify(
                res[0], "erschrick", 0, NEUTRAL, 0,
                "Du trittst "+xdeinem(res[0])+" kraeftig auf die Fuesse, "
                  "dann drueckst du "+ihm(res[0])+" leidenschaftlich "
                  "die Nase zu, als "+er(res[0])+" daraufhin den Mund "
                  "aufsperrt ziehst du "+seinen((["name":"zunge",
                  "gender":"weiblich"]),0,res[0])+" ganz lang und "
                  "ziehst zum Abschluss ganz fest an "
                  +seinem((["name":"ohren","gender":"saechlich",
                           "plural":1]),"beid",res[0])+".",
                Wer(owner, ART_AAA)+" tritt "+xdir(res[0])+" kraeftig auf deine Fuesse, "
              "dann drueckt "+er(owner)+" "+xdir(res[0])+" leidenschaftlich "
              "die Nase zu, als "+xdu(res[0])+" daraufhin den Mund "
              "aufsperrst zieht "+der(owner)+" deine Zunge "
              "ganz lang und "
              "zieht zum Abschluss ganz fest an "
              "deinen beiden Ohren. Au, ist das gemein.",
                Wer(owner, ART_AAA)+" tritt "+xseinem(res[0])+" kraeftig auf die Fuesse, "
              "dann drueckt "+er(owner)+" "+ihm(res[0])+" leidenschaftlich "
              "die Nase zu, als "+er(res[0])+" daraufhin den Mund "
              "aufsperrt zieht "+der(owner)+" die Zunge von "
              +dem(res[0])+" ganz lang und "
              "zieht zum Abschluss ganz fest an "
              +seinem((["name":"ohren","gender":"saechlich",
                        "plural":1]),"beid",res[0])+".",
                MA_EMOTE,
                MT_LOOK | MT_FEEL, MT_LOOK | MT_FEEL | MT_TASTE, MT_LOOK))
                feel (owner);
        }
        else
    }
    return 1;

}
#endif

int huch(string str)
{
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "erschrick", 0, NEUTRAL, 0,
            "Du erschrickst!",
            Der(owner)+" erschrickt!",
            MA_EMOTE, MT_NOISE | MT_LOOK))
            return 1;
    }
    else
    {
        if (forbidden_msg_soul_action_notify(
            "erschrick", str, NEUTRAL, 0,
            "Du erschickst "+str+"!",
            Der(owner)+" erschrickt "+str+"!",
            MA_EMOTE, MT_NOISE | MT_LOOK))
            return 1;
    }
    feel(owner);
    return 1;
}

int feixe(string str)
{
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR), "feix",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
        0, "an", FALL_AKK);
}


int flippe(string str)
{
    return soul_plus_adv(str, "flipp",
                          NEUTRAL, 0, MA_EMOTE,
                          MT_LOOK | MT_NOISE | MT_FEEL, MT_LOOK | MT_NOISE,
                          "aus", 0, "total");
}


int fluche(string str)
{
    if (!str)
    {
        //    NO_GHOST;

        if (forbidden_msg_soul_action_notify(
            "fluch", 0, MIES, 0,
            "Du laesst einen ueblen Fluch ab.",
             Wer(owner, ART_AAA)+" flucht wie ein Rohrspatz.",
             MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "fluch",
                          MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE);
}


int freue(string str)
{
    if(IS_GHOST)
        return soul_plus_adv(str, "freu",
                              NETT, 0, MA_EMOTE, MT_LOOK, 0,
                              0, 0, "wie ein kleines Gespenst", 1);
    return soul_plus_adv(str, "freu",
                          NETT, 0, MA_EMOTE, MT_LOOK, 0,
                          0, 0, "wie ein kleines Kind", 1);
}


int friere(string str)
{
    string fill;
    fill = (ENV(owner)->query_type("temperatur")>25) ?
        " Bei dieser Hitze?" : "";
    NO_GHOST;
    str = (!str || str=="") ? " einfach jaemmerlich" : " "+str;

    if (forbidden_msg_soul_action_notify(
        "frier", str, NEUTRAL, 0,
        "Du schlaegst deine Haende um deinen Koerper und stampfst mit "
          "den Fuessen auf. Du frierst"+str+"."+fill,
        Wer(owner, ART_AAA)+" schlaegt "+
          seinen((["name":"haende","gender":"weiblich","plural":1]),
                 0, owner)+ " um "+
          seinen((["name":"koerper","gender":"maennlich"]), 0, owner)+
          " und stampft mit den Fuessen auf. "+Er(owner)+" friert"+str+
          "."+fill,
        MA_EMOTE, MT_LOOK))
        return 1 ;

    feel(owner);
    return 1;
}


int fuchtle(string str)
{
    NO_GHOST;
    return soul_plus_adv(
        str, "fuchtel",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
        "rum",0, "wie ein"+(["maennlich":" Bloeder","weiblich":"e Bloede",
                            "saechlich":" Bloedes"])[owner->query_gender()]+
        " in der Gegend");
}


int furze(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "furz", 0, MIES, 0,
            "FARRRRRRRRRRRRRRRRZ! Wie unanstaendig!",
            Wer(owner, ART_AAA)+" laesst einen fahren.",
            MA_EMOTE, MT_NOISE | MT_SMELL))
            return 1;

        feel(owner);
        return 1;
    }

    return soul_plus_adv(str, "furz",
                          MIES, 0, MA_EMOTE, MT_NOISE);
}


int gackere(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "gacker", 0, NEUTRAL, 0,
            "Du gackerst stolz.",
            Wer(owner, ART_AAA)+" wirft "+
            seinen((["gender":"maennlich","name":"kopf"]),0,owner)+
            " zurueck und gackert stolz!",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "gacker",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE) ;
}


int gaehne(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR), "gaehn",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "an", FALL_AKK);
}


int gluckse(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "glucks",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE);
}


int gratuliere(string str)
{
    mixed *res;
    string wer;

    res = soul_parser(str);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        if (forbidden_msg_soul_action_notify(
            "gratulier", str, NETT, 0,
            "Du sagst: Herzlichen Glueckwunsch!",
            Wer(owner, ART_AAA)+" sagt: Herzlichen Glueckwunsch!",
            MA_COMM, MT_NOISE))
            return 1 ;

        return 1;
    }
    if (res[0]==owner)
    {
        msg_notify("Das ist ja wohl nicht dein Ernst! Eigenlob stinkt!");
        return 1;
    }

    wer = (["weiblich":"Frauen", "maennlich":"Maenner",
        "saechlich":"Kreaturen"])[owner->query_gender()];
    if (!livingp(res[0]))
    {
	return soul_adv_part(res, "gratulier",
    	    NETT, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
    	    0, 0, FALL_DAT);
    }
    else if (query_innenraum(ENV(owner)))
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "gratulier", 0, NETT, 0,
            "Du holst hinter "+
              ihrem((["name":"ohr","gender":"saechlich"]), 0, res[0],
                     0, 0, ART_DEIN)+
              // dem Ohr "+deines(res[0])+
              // dem Ohr "+get_genitiv (res[0]->query_cap_name())+
              " eine bunte Luftschlange hervor und wirfst "
              "sie "+ihm(res[0])+" lieb gratulierend ueber den Kopf.",
            Wer(owner, ART_AAA)+" holt hinter deinem Ohr "
              "eine bunte Luftschlange hervor und wirft sie "+xdir(res[0])+
              " lieb gratulierend ueber deinen Kopf. "
              "So albern koennen auch nur "+wer+" sein.",
            Wer(owner, ART_AAA)+" holt hinter "+
              ihrem((["name":"ohr","gender":"saechlich"]), 0, res[0],
                     0, 0, ART_SEIN)+
              // dem Ohr "+seines(res[0])+
              // dem Ohr "+get_genitiv (res[0]->query_cap_name())+
              " eine bunte Luftschlange hervor und wirft sie "+ihm(res[0])+
              " lieb gratulierend ueber den Kopf. "
              "So albern koennen auch nur "+wer+" sein.",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
    }
    else
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "gratulier", 0, NETT, 0,
            "Du pflueckst spontan einige Blumen und wirfst sie "
               +xdeinem(res[0])+" herzlich gratulierend ueber den Kopf.",
             Wer(owner, ART_AAA)+" pflueckt spontan "
               "einige Blumen und wirft sie "+xdir(res[0])+
              " herzlich gratulierend "
               "ueber deinen Kopf. So albern koennen auch nur "+wer+" sein.",
             Wer(owner, ART_AAA)+" pflueckt spontan einige Blumen und wirft sie "
               +xseinem(res[0])+" herzlich gratulierend ueber den Kopf. "
               "So albern koennen auch nur "+wer+" sein.",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
    }

    feel(owner);
    return 1;
}


int grinse(string str)
{
    if(IS_GHOST)
        return soul_adv_part(
            soul_parser(str, IGNORE_FAR),
            "grins", NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
            0, "an", FALL_AKK, 0, "gespenstisch");
    else
        return soul_adv_part(
            soul_parser(str, IGNORE_FAR),
            "grins", NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
            0, "an", FALL_AKK);
}


int grueble(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "gruebl", 0, NEUTRAL, 0,
            "Du gruebelst herum, bis dir blauer Qualm aus den Ohren quillt.",
            Wer(owner, ART_AAA)+" gruebelt herum. Nach kurzer Zeit quillt "+
              ihm(owner)+" blauer Qualm aus "+
              seinem((["name":"ohren","plural":1,"gender":"saechlich"]),
                     0,owner)+".",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "gruebel",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK);
}


int grummle(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "grummel", 0, NEUTRAL, 0,
            "Du grummelst rum.",
            Wer(owner, ART_AAA)+" grummelt vor sich hin.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR), "grummel",
        MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "an", FALL_AKK);
}

int grumpfgrummle(string str)
{
    return soul_plus_adv(str, "grumpfgrummel",
	NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
	"herum");
}

int grunze(string str)
{
    string how;

    NO_GHOST;

    if (!str)
    {
        how = (["maennlich":"ein Wildeber","weiblich":"eine Wildsau",
               "saechlich":"ein Wildschweinliches"])[owner->query_gender()];

        if (forbidden_msg_soul_action_notify(
            "grunz", 0, NEUTRAL, 0,
            "Du grunzt wie "+how+".",
            Wer(owner, ART_AAA)+" grunzt wie "+how+".",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "grunz",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          "herum");
}

// Gruppenumarmung

int query_gruppenumarmung_teilnahme ()
{
    return find_call_out ("gruppenumarmung_co") + 1;
}

int gruppenumarmung_teilnahme_test (object wer)
{
    object seele;
    return (seele = present ("seele", wer)) ? seele->query_gruppenumarmung_teilnahme() : 0;
}

int gruppenumarmung_bekannt_test (object wer)
{
    object seele;
    return (seele = present ("seele", wer)) ? seele->query_gruppenumarmung_bekannt() : 0;
}

void gruppenumarmung_ueberstanden ()
{
    while (remove_call_out ("gruppenumarmung_co") != -1);
    owner->delete_controller("notify_move",#'gruppenumarmung_ueberstanden);
}

int gruppenumarmung ()
{
    object *mitspieler, *teilnehmer, *unwissende, seele;
    if (query_gruppenumarmung_teilnahme()) {
        notify_fail ("Du nimmst doch bereits an einer Gruppenumarmung teil.\n");
        return 0;
    }
    mitspieler = filter (all_inventory (environment (this_player())), #'living)
        - ({this_player()});
    if (!sizeof (mitspieler)) {
        notify_fail ("Es ist niemand da, der bei der Gruppenumarmung mitmachen koennte.\n");
        return 0;
    }
    teilnehmer = filter (mitspieler, #'gruppenumarmung_teilnahme_test);
    if (sizeof (teilnehmer)) {
        // an Gruppenumarmung teilnehmen
        owner->do_command ("sage Au ja, Gruppenumarmung!");
        call_out ("gruppenumarmung_co",gruppenumarmung_teilnahme_test(teilnehmer[0])+1);
        msg_say (MT_LOOK, MA_EMOTE, Der(owner)+" breitet beide Arme weit aus, bereit, an der Gruppenumarmung teilzunehmen.");
    } else {
        // Gruppenumarmung initiieren
        owner->do_command ("sage Gruppenumarmung!");
        call_out ("gruppenumarmung_co",14);
        msg_say (MT_LOOK, MA_EMOTE, Der(owner)+" breitet beide Arme weit aus, bereit, an der Gruppenumarmung teilzunehmen.");
        map_objects (mitspieler,"notify","seele",owner,0,
            "gruppenumarmung_start",0,0,0,MT_LOOK,MT_LOOK,MT_LOOK);
        map_objects (mitspieler,"notify_soul",owner,"gruppenumarmung_start",0);
    }
    gruppenumarmung_bekannt = 1;
    owner->add_controller("notify_move",#'gruppenumarmung_ueberstanden);
    msg_write (MT_LOOK, MA_EMOTE, "Du breitest Deine Arme weit aus, bereit zur Gruppenumarmung.");
    // unwissende ueber Gruppenumarmung informieren
    unwissende = mitspieler - filter (mitspieler, #'gruppenumarmung_bekannt_test);
    for (int i = sizeof (unwissende); i--;) {
        msg_to (unwissende[i], MT_NOTIFY, MA_UNKNOWN,
            "Um an der Gruppenumarmung teilzunehmen gib einfach \"gruppenumarmung\" "
            "oder abgekuerzt \"gu\" ein.");
        if (seele=present ("seele",unwissende[i]))
            seele->set_gruppenumarmung_bekannt (1);
    }
    return 1;
}

void gruppenumarmung_co ()
{
    object *mitspieler, *teilnehmer, *zuschauer, seele;
    string msg;
    mitspieler = filter (all_inventory (environment (this_player())), #'living);
    teilnehmer = ({owner}) + filter (mitspieler, #'gruppenumarmung_teilnahme_test);
    if (sizeof (teilnehmer)<2) {
        msg_to (owner, MT_NOTIFY, MA_FEEL,
            "Es macht leider niemand bei der Gruppenumarmung mit. "
            "Frustriert laesst Du Deine Arme sinken.");
        msg_say (MT_LOOK, MA_FEEL, Der(owner)+" laesst die Arme, die zur "
            "Gruppenumarmung erhoben waren, wieder sinken, da ausser "+
            ihm(owner)+" niemand bei der Gruppenumarmung mitmachen wollte.");
        return;
    }
    for (int i = sizeof (teilnehmer); i--;) {
        msg_to (teilnehmer[i], MT_FEEL, MA_FEEL,
            "Du umarmst "+liste(map (arr_delete(teilnehmer,i),#'den))
           +" gleichzeitig gegenseitig durcheinander miteinander in "
            "einem wirren Knoten aus Armen. Nach einiger Zeit gelingt es "
            "Euch, Euch wieder zu entknoten.");
        if (seele=present("seele",teilnehmer[i]))
            seele->gruppenumarmung_ueberstanden ();
    }
    msg_say (MT_LOOK, MA_FEEL,
        capitalize (liste (map (teilnehmer, #'der)))+
        " umarmen sich gleichzeitig durcheinander gegenseitig miteinander "
        "in einem wirren Knoten aus Armen. Nach einiger Zeit gelingt "
        "es ihnen wieder, sich zu entknoten.",
        teilnehmer);
}

int query_gruppenumarmung_bekannt ()
{
    return gruppenumarmung_bekannt;
}

void set_gruppenumarmung_bekannt (int x)
{
    gruppenumarmung_bekannt = x;
}

void notify_follow ()
{
    gruppenumarmung_ueberstanden ();
}


int haetschle(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, PARTNER),
        "haetschel", NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
        0, 0, FALL_AKK);
}


int haue(string str)
{
    mixed res;
    
    NO_GHOST;
    return soul_adv_part(
        res = soul_parser(str, PARTNER),
        "hau", MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
        0, 0, FALL_AKK, 0,
	sizeof(res) && livingp(res[0]) && "gruen und blau");
}


int hechle(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR),
        "hechel", NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "nach", FALL_DAT, 0, "mit heraushaengender Zunge");
}


int heule(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "heul",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          0, 0, "zum Steine erweichen");
}


int hickse(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "stoess", 0, NEUTRAL, 0,
            "Hick",
            Wer(owner, ART_AAA)+" hat einen Schluckauf.",
            MA_EMOTE, MT_LOOK | MT_NOISE | MT_FEEL, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "stoess",
                          NEUTRAL, 0, MA_EMOTE,
                          MT_LOOK | MT_NOISE | MT_FEEL, MT_LOOK | MT_NOISE,
                          "auf");
}


int huepfe(string str)
{
    mixed   *res;
    string  wer, tmp;

    NO_GHOST;

    res = soul_parser(str, NOT_TO_ENV, "um");

    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        if (IM_WASSER_SCHWIMMEND)
            return soul_plus_adv(str, "huepf",
                                  NEUTRAL, PSEUDO_MOVE, MA_EMOTE, MT_LOOK, 0,
                                  "wie ein Korken im Wasser auf und ab");
        else
            return soul_plus_adv(str, "huepf",
                                  NEUTRAL, PSEUDO_MOVE, MA_EMOTE, MT_LOOK, 0,
                                  "herum");
    }

    if (res[0] == owner)
    {
        msg_notify("Um dich selbst herum? Aeh... Wie soll denn das gehen?");
        return 1;
    }
    if (in_mir(res[0]))
    {
        msg_notify("Um "+xdeinen(res[0])+" herumhuepfen solange du "+
                    ihn(res[0])+" bei dir traegst? "
                    "Aeh... Wie soll denn das gehen?");
        return 1;
    }

    if (IM_WASSER_SCHWIMMEND)
        tmp = " wie ein Korken im Wasser" ;
    else
        tmp = "" ;

    if (forbidden_msg_soul_action_partner_notify(
        res[0], "huepf", res[1], NEUTRAL, PSEUDO_MOVE,
        "Du huepfst"+tmp+res[1]+" um "+xdeinen(res[0])+" herum.",
        Wer(owner, ART_AAA)+" huepft"+tmp+res[1]+" um "+xdich(res[0])+" herum.",
        Wer(owner, ART_AAA)+" huepft"+tmp+res[1]+" um "+xseinen(res[0])+" herum.",
        MA_EMOTE, MT_LOOK))
        return 1 ;

    return 1;
}


int huestle (string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "huestel",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          0,0,"dezent");
}


int huste(string str)
{
    mixed res;

    NO_GHOST;

    res = soul_parser(str);
    if (!sizeof(res))
        return 1;

    if (livingp(res[0]))
        return soul_adv_part(
            res, "huste",
            MIES, 0, MA_EMOTE,
            MT_LOOK | MT_NOISE,
            MT_LOOK | MT_NOISE | MT_FEEL | MT_SMELL,
            MT_LOOK | MT_NOISE,
            0, "ins Gesicht", FALL_DAT);
    else
        return soul_adv_part(
            res, "huste",
            NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
            0, "an", FALL_AKK);
}

int ieks(string str)
{
    return soul_plus_adv(str, "iek",
	NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
	"herum");
}


int ja()
{
    if(IS_GHOST)
    {
        if (forbidden_msg_soul_action_notify(
            "ja", 0, NEUTRAL, 0,
            "Du waberst bestaetigend auf und ab.",
            Wer(owner, ART_AAA)+" wabert bestaetigend auf und ab.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }
    else
    {
        if (forbidden_msg_soul_action_notify(
            "ja", 0, NEUTRAL, 0,
            "Du nickst zustimmend.",
            Wer(owner, ART_AAA)+" nickt zustimmend.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }
    return 1;
}


int jammer(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "jammer", str, NEUTRAL, 0,
            "Du jammerst der Welt dein Leid vor.",
            Wer(owner, ART_AAA)+" jammert ueber die "
                +(wizp(this_player())?"Spieler":"Goetter")+
                " und die Welt.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(soul_parser(str, IGNORE_FAR),
                          "jammer", NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
                          0, "was vor", FALL_DAT);
}


int japse(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "japs",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          0, 0, "nach Luft");
}


int jubiliere (string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "jubilier",
                          NETT, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          0,0,"ausgelassen");
}


int juble(string str)
{
    NO_GHOST;

    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "jubel", 0, NETT, 0,
            "Du reisst in unbeschreiblichem Jubel beide Arme hoch "
              "und gehst freudestrahlend in die Knie.",
            Wer(owner, ART_AAA)+" reisst in unbeschreiblichem Jubel beide Arme "
              "hoch und geht freudestrahlend in die Knie.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "jubel",
                          NETT, 0, MA_EMOTE, MT_LOOK | MT_NOISE);
}


int jaule(string str)
{
    NO_GHOST;
    if(!str)
    {
        if (forbidden_msg_soul_action_notify(
            "jaul", 0, NEUTRAL, 0,
            "Du jaulst herum. AUUHUHUUUUHUHU!",
            Wer(owner, ART_AAA)+" jault herum wie ein Strassenkoeter.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "jaul",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          "herum");
}


int keife(string str)
{
    NO_GHOST;

    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "keif", 0, MIES, 0,
            "Du keifst wie ein altes Waschweib.",
            Wer(owner, ART_AAA)+" keift wie ein altes Waschweib.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR),
        "keif", MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "an", FALL_AKK);
}


int keuche(string str)
{
    NO_GHOST;

    return soul_plus_adv(str, "keuch",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE);
}


int kichere(string str)
{
    mixed *res;
    
    res = soul_parser(str, IGNORE_FAR);
    if(!sizeof(res) || !res[0])
       return soul_plus_adv(str, "kicher",
                             NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
			     0, 0,
			     ((IS_GHOST) ? "gespenstisch" : "albern")) ;
    else
       return  soul_adv_part(res, "kicher", NEUTRAL, 0, MA_EMOTE,
                              MT_LOOK | MT_NOISE, 0, 0,
                              0, "an", FALL_AKK, 0,
                              ((IS_GHOST)?"gespenstisch":0));
}


void wurde_gekitzelt(object opfer)
{
    string cmd;
    if (!opfer || opfer->id("statue"))
        return;
    cmd = ({"kicher","kicher lustig","lache laut","lache spontan",
	    "lache lauthals","schreie vor Lachen","zucke","","",
	    "lache"})[random(10)];
    if(!strlen(cmd))
	return;
    if(playerp(opfer))
	cmd = "\\"+cmd; // Damit keine Kuerzel ausgefuehrt werden.
    opfer->do_command(cmd);
}


int kitzeln(string str)
{
    mixed  *res;

    NO_GHOST;

    res=soul_parser(str, PARTNER);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Kitzle wen <wie>?");
        return 1;
    }
    if(res[0]==owner)
    {
        msg_notify("Kitzle dich selbst?");
        return 1;
    }

    if (forbidden_msg_soul_action_partner_notify(
        res[0], "kitzel", res[1], NEUTRAL, 0,
        "Du kitzelst "+xdeinen(res[0])+res[1]+".",
        Wer(owner, ART_AAA)+" kitzelt "+xdich(res[0])+""+res[1]+".",
        Wer(owner, ART_AAA)+" kitzelt "+xseinen(res[0])+res[1]+".",
        MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
        return 1 ;

    if(objectp(res[0]) && livingp(res[0]) && !res[0]->id("statue"))
        call_out("wurde_gekitzelt", 2, res[0]);

    feel(owner);

    return 1 ;
}


int klatsche(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR),
        "klatsch", NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "zu", FALL_DAT);
}


int knabbere(string str)
{
    mixed res;
    NO_GHOST;
    if (!str)
        msg_notify("Knabber an wem <wie>?");
    else
    {
        res = soul_parser(str, PARTNER, "an");

        if(!sizeof(res))
            return 1;
        if(res[0])
        {
            if(res[0] == owner)
            {
                msg_notify("An deinem eigenen Ohr rumknabbern?");
                return 1;
            }

            if(livingp(res[0]))
            {
                if (forbidden_msg_soul_action_partner_notify(
                    res[0], "knabber", res[1], NEUTRAL, 0,
                    "Du knabberst"+res[1]+" "+
                      regreplace("an "+ihrem(
                          (["name":"ohr","gender":"saechlich"]), 0, res[0],
                          0, 0, ART_DEIN), "^an dem", "am", 0)+
                      // "am Ohr "+deines(res[0])+
                      ".",
                    Wer(owner, ART_AAA)+" knabbert"+res[1]+" an deinem Ohr.",
                    Wer(owner, ART_AAA)+" knabbert"+res[1]+" "+
                      regreplace("an "+ihrem(
                          (["name":"ohr","gender":"saechlich"]), 0, res[0],
                          0, 0, ART_SEIN), "^an dem", "am", 0)+
                      // "am Ohr "+seines(res[0])+
                      ".",
                    MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
                    return 1 ;
            }
            else if (objectp(res[0]) && res[0]->query_nahrung())
            {
                if (environment(res[0]) != owner)
                {
                    msg_notify("Dazu solltest du "+den(res[0])+
                                " erst einmal nehmen.");
                    return 1;
                }

                if (forbidden_msg_soul_action_partner_notify(
                    res[0], "knabber", res[1], NEUTRAL, 0,
                    "Du knabberst ein wenig an "+xdeinem(res[0])+
                      " herum.",
                    Wer(owner, ART_AAA)+" knabbert ein wenig an "+xdir(res[0])+
                      " herum.",
                    Wer(owner, ART_AAA)+" knabbert ein wenig an "+xseinem(res[0])+
                      " herum.",
                    MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
                    return 1 ;
            }
            else
            {
                if (forbidden_msg_soul_action_partner_notify(
                    res[0], "knabber", res[1], NEUTRAL, 0,
                    "Du beisst dir an "+xdeinem(res[0])+" fast die Zaehne aus.",
                    Wer(owner, ART_AAA)+" beisst sich an "+xdir(res[0])+
                      " fast die Zaehne aus.",
                    Wer(owner, ART_AAA)+" beisst sich an "+xseinem(res[0])+
                      " fast die Zaehne aus.",
                    MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
                    return 1 ;
            }
        }
        else
            return soul_plus_adv(res[1], "knabber",
                                  NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                                  "herum");
    }

    feel(owner) ;
    return 1;
}


int kneife(string str)
{
    mixed res;
    NO_GHOST;

    return soul_adv_part(res = soul_parser(str, PARTNER), "kneif",
                          MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK, 0,
                          sizeof(res) && livingp(res[0]) && "in den Hintern",
			  FALL_AKK);
}


int knickse(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "knicks", 0, NETT, 0,
            "Du machst einen anmutigen Knicks.",
            Wer(owner, ART_AAA)+" macht einen anmutigen Knicks.",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(soul_parser(str, IGNORE_FAR, "vor"), "knicks",
                          NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
                          "vor", 0, FALL_DAT);
}


int knirsche(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "knirsch",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          "mit den Zaehnen");
}


int knuddle(string str)
{
    mixed *res;

    if (zustand != SEELE && me(str))
    {
        if (forbidden_msg_soul_action_partner_notify(
            TO, "knuddel", 0, NETT, 0,
            "Du knuddelst "+xdeinen()+" ganz lieb. "
              "Ach wie suess "+er()+" doch ist.",
            Wer(owner, ART_AAA)+" knuddelt dich ganz fest.",
            Wer(owner, ART_AAA)+" knuddelt "+xseinen()+" ganz lieb. "+
              Er(owner)+" muss "+ihn()+" wohl sehr lieb haben.",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
        return 1 ;
    }

    res = soul_parser(str, PARTNER);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Knuddle wen <wie>?");
        return 1;
    }
    if (res[0] == owner)
    {
        msg_notify("Du willst dich wohl vor den anderen zum Kasper machen?");
        return 1;
    }
    if(IS_GHOST)
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "knuddel", res[1], NETT, 0,
            "Du gleitest beim Versuch, "+xdeinen(res[0])+" zu knuddeln, "
              "durch "+ihn(res[0])+" hindurch."+
	      (livingp(res[0])?(" "+Der(res[0])+" bekommt dabei eine "
	        "Gaensehaut."):""),
            Wer(owner, ART_AAA)+" gleitet beim Versuch, "+xdich(res[0])+" zu "
              "knuddeln, durch "+xdich(res[0])+" hindurch. "+xDu(res[0])+
              " bekommst dabei eine Gaensehaut.",
            Wer(owner, ART_AAA)+" gleitet bei beim Versuch, "+xseinen(res[0])+
              " zu knuddeln, durch "+ihn(res[0])+" hindurch."+
	      (livingp(res[0])?(" "+Der(res[0])+" bekommt dabei eine "
	        "Gaensehaut."):""),
             MA_EMOTE, MT_LOOK))
            return 1;
    }
    else
    {
        if (res[1]=="")
            res[1]=" ganz fest";

        if (forbidden_msg_soul_action_partner_notify(
                res[0], "knuddel", res[1], NETT, 0,
                 "Du knuddelst "+xdeinen(res[0])+res[1]+".",
                Wer(owner, ART_AAA)+" knuddelt "+xdich(res[0])+res[1]+". "+
                  Er(owner)+" muss "+xdich(res[0])+" wohl sehr lieb haben.",
                Wer(owner, ART_AAA)+" knuddelt "+xseinen(res[0])+res[1]+"."+
		(livingp(res[0])?" Ist das ein schoenes Paar.":""),
                MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
                return 1 ;
    }

    feel(owner);
    return 1;
}


int knurre(string str)
{
    if(IS_GHOST)
        return soul_adv_part(
            soul_parser(str, IGNORE_FAR), "knurr",
            NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
            0, "an", FALL_AKK, 0, "grauenhaft wild");
    else
        return soul_adv_part(
            soul_parser(str, IGNORE_FAR), "knurr",
            NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
            0, "an", FALL_AKK);
}


int knutsche(string str)
{
    mixed *res;

    NO_GHOST;
    res = soul_parser(str, PARTNER);
    if (!sizeof(res))
         return 1;
    if (!res[0])
    {
        msg_notify("Knutsche wen?");
        return 1;
    }
    if (res[0] == owner)
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "knutsch", 0, NEUTRAL, 0,
            "Du ziehst eine fuerchterliche Schnute beim Versuch, dich "
              "selbst abzuknutschen.",
            0,
            Wer(owner, ART_AAA)+" verrenkt "+seinen((["name":"gesicht",
                                            "gender":"saechlich"]),0,owner)+
              ", beim Versuch, sich selbst zu "
              "knutschen. Lustig. Auf welche Ideen manche Leute kommen!",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        return 1;
    }

    if (livingp(res[0]))
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "knutsch", res[1], NETT, 0,
            "Du gibst "+xdeinem(res[0])+
              " einen RICHTIGEN Kuss... Das dauert eine Weile...",
            Wer(owner, ART_AAA)+" gibt "+xdir(res[0])+
              " einen tiefen und hingebungsvollen Kuss...\n"
              "Er scheint ewig zu dauern...",
            Wer(owner, ART_AAA)+" gibt "+xseinem(res[0])+
              " einen tiefen und hingebungsvollen Kuss...\n"
              "Er scheint ewig zu dauern...",
            MA_EMOTE, MT_LOOK | MT_FEEL | MT_TASTE, 0, MT_LOOK))
            return 1 ;
    }
    else
    {
        if (res[1]=="")
            res[1]=" etwas lustlos";

        if (forbidden_msg_soul_action_partner_notify(
            res[0], "knutsch", res[1], NETT, 0,
            "Du knutschst"+res[1]+" an "+xdeinem(res[0])+" rum.",
            Wer(owner, ART_AAA)+" knutscht"+res[1]+" an "+xdir(res[0])+" rum.",
            Wer(owner, ART_AAA)+" knutscht"+res[1]+" an "+xseinem(res[0])+" rum.",
            MA_EMOTE, MT_LOOK | MT_FEEL | MT_TASTE, 0, MT_LOOK))
            return 1 ;
    }

    feel(owner);
    return 1;
}


int kotze(string str)
{
    NO_GHOST;
    if(owner->query_fp()<1 && owner->query_wp()<1)
    {
        if (forbidden_msg_soul_action_notify(
            "kotz", str, MIES, 0,
            "Du versuchst zu kotzen, hast aber nichts im Magen.\n"
              "Darum wuergst du halt ein bisschen rum.",
            Wer(owner, ART_AAA)+" versucht mit leerem Magen zu kotzen. "
              "Das geht natuerlich schief!",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    if(!str)
    {
        if (forbidden_msg_soul_action_notify(
            "kotz", 0, MIES, 0,
            "Du kotzt ueber deine Fuesse.",
            Wer(owner, ART_AAA)+" verdreht die Augen und kotzt.",
            MA_EMOTE,
            MT_LOOK | MT_NOISE | MT_TASTE | MT_SMELL,
            MT_LOOK | MT_NOISE | MT_SMELL))
            return 1 ;

        feel(owner);
        return 1;
    }
    else
        return soul_adv_part(
            soul_parser(str, 0, "ueber"), "kotz",
            MIES, 0, MA_EMOTE,
            MT_LOOK | MT_NOISE | MT_TASTE | MT_SMELL,
            MT_LOOK | MT_NOISE | MT_FEEL | MT_SMELL,
            MT_LOOK | MT_NOISE | MT_SMELL,
            "ueber", 0, FALL_AKK);
}


int kratze(string str)
{
    mixed *res;

    NO_GHOST;
    if(!str)
    {
        if (forbidden_msg_soul_action_notify(
            "kratz", 0, NEUTRAL, 0,
            "Haehhhhhh? Du kratzt dich etwas ratlos an deinem Kopf.",
            Wer(owner, ART_AAA)+" kratzt sich reichlich ratlos an "+
              seinem((["name":"kopf","gender":"maennlich"]),0,owner)+".",
            MA_EMOTE, MT_LOOK | MT_FEEL, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1 ;
    }
    else
    {
        res = soul_parser(str);
        if (!sizeof(res))
            return 1;
        if (!res[0] || res[0]==owner)
            return soul_plus_adv(
                res[1], "kratz",
                NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, MT_LOOK,
                ({"an deinem Kopf","an "+
                      seinem((["name":"kopf","gender":"maennlich"]),0,owner)}),
                0, 0, FALL_NOM);
        else
            return soul_adv_part(
                res, "kratz",
                NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, 0, FALL_AKK);
    }
}

int kraule(string str)
{
    mixed res;

    NO_GHOST;

    if (!sizeof(res = soul_parser(str,PARTNER)))
        return 1;

    if (!res[0])
        return notify_fail("Wen willst Du kraulen?\n");

    if (res[0] == owner)
        return notify_fail("Dich selbst kannst Du nicht kraulen.\n");

    if (forbidden_msg_soul_action_partner_notify(
        res[0], "kraul", res[1], NETT, 0,
        "Du kraulst "+xdeinen(res[0])+res[1]+".",
        Der(owner)+" krault "+xdich(res[0])+res[1]+".",
        Ihr(res[0])+" "+plural("wird","werden",res[0])+" von "+dem(owner)
       +res[1]+" gekrault.",
        MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
        return 1;

    feel(owner);
    return 1;
}

int krieche(string str)
{
    mixed *res;

    NO_GHOST;
    res = soul_parser(str, SOUL_PO | NOT_TO_ENV, "vor");
    if (!sizeof(res))
        return 1;

    if (query_im_wasser(ENV(owner)))
    {
        msg_notify("Im Wasser Kriechen. Wie soll das gehen?") ;
        return 1;
    }

    if (!res[0])
        return soul_plus_adv(res[1], "kriech",
                              NEUTRAL, PSEUDO_MOVE, MA_EMOTE, MT_LOOK, 0,
                              "auf dem Boden herum");
    return soul_adv_part(
        res, "kriech", NEUTRAL, PSEUDO_MOVE, MA_EMOTE, MT_LOOK, 0, 0,
        "vor", "im Staub", FALL_DAT);
}


int kringle(string str)
{
    NO_GHOST;

    if (IM_WASSER_SCHWIMMEND)
    {
        if (forbidden_msg_soul_action_notify(
            "kringel", str, NETT, PSEUDO_MOVE,
            "Du kringelst dich vor Lachen im Wasser hin und her.\n"
              "Ups, jetzt hast du dich aber ordentlich verschluckt.",
            Wer(owner, ART_AAA)+" kringelt sich vor Lachen im Wasser hin und her. "
              "Ungluecklicherweise verschluckt "+er(owner)+
              " dabei eine Menge Wasser.\n"
              "Angewidert verzieht "+er(owner)+" "+
              seinen((["name":"gesicht","gender":"saechlich"]), 0, owner)+".",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1;
    }
    else
    {
        if (forbidden_msg_soul_action_notify(
            "kringel", str, NETT, PSEUDO_MOVE,
            "Du kringelst dich vor Lachen auf dem Boden.",
            Wer(owner, ART_AAA)+" kringelt sich vor Lachen auf dem Boden.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1;
    }

    feel(owner);
    return 1;
}


int kuesse(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str,PARTNER),
        "kuess", NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_FEEL,
        0, 0, FALL_AKK, "Kuesse wen oder was <wie>?");
}


int kuschle(string str)
{
    mixed   *res;
    string  tmp ;

    NO_GHOST;

    tmp = lower_case(space(str || "")) ;
    if (strlen(tmp)<3)
    {
        msg_notify("Kuschle dich an wen?");
        return 1;
    }
    if (tmp[0..2]=="an ")
        str = tmp[3..<1];

    if (zustand != SEELE && me(str))
    {
        if (forbidden_msg_soul_action_partner_notify(
            TO, "kuschel", 0, NETT, 0,
            "Du kuschelst dich ganz lieb mit "+xdeinem()+" zusammen. "
              "Um nichts in Magyra moechtest du "+ihn()+" missen.",
            Wer(owner, ART_AAA)+" kuschelt sich ganz fest an ich ran.",
            Wer(owner, ART_AAA)+" kuschelt sich liebevoll mit "+xseinem()+
              " zusammen. Danach waere dir jetzt auch zumute.",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
        return 1 ;
    }

    res = soul_parser(str,PARTNER);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Kuschle dich an wen?");
        return 1;
    }
    if (res[0]==owner)
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "kuschel", 0, NETT, 0,
            "Du schlingst deine Arme um dich und kuschelst, was das Zeug "
              "haelt. Das muss vielleicht aussehen... Egal, du magst eben doch "
              "niemanden so sehr wie dich selbst.",
            0,
            Wer(owner, ART_AAA)+" schlingt "+seinen((["name":"arme","gender":"maennlich",
                                            "plural":1]),0,owner)+
              " um den Koerper und kuschelt so mit sich "
              "selbt. Man ist sich doch eben selbst am naechsten!",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1;
        return 1;
    }

    if (livingp(res[0]))
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "kuschel", res[1], NETT, 0,
            "Du kuschelst dich an "+xdeinen(res[0])+" hin und spuerst, wie "+
              der(res[0])+" unter deinen Umarmungen und Liebkosungen ruhiger, "+
              "zufriedener und gluecklicher wird.",
            Wer(owner, ART_AAA)+" kuschelt sich an "+xdich(res[0])+" ran, und "+
              xdu(res[0])+" "+
              "fuehlst "+xdich(res[0])+
              " umarmt und liebkost von "+ihm(owner)+". Dies "
              "loest sehr schoene Gefuehle in "+xdir(res[0])+
              " aus, und "+xdu(res[0])+" fuehlst "+xdich(res[0])+" "
              "ruhig, zufrieden und gluecklich.",
            Wer(owner, ART_AAA)+" kuschelt sich an "+xseinen(res[0])+" an.",
            MA_EMOTE, MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK))
            return 1 ;
    }
    else
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "kuschel", res[1], NETT, 0,
             "Du kuschelst dich"+res[1]+" an "+xdeinen(res[0])+" ran.",
            Wer(owner, ART_AAA)+" kuschelt sich"+res[1]+
              " an "+xdich(res[0])+" ran.",
            Wer(owner, ART_AAA)+" kuschelt sich"+res[1]+
              " an "+xseinen(res[0])+" ran.",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
     }

    feel(owner);
    return 1;
}


int lache(string str)
{
    if (!str)
    {
        if(IS_GHOST)
        {
            if (IM_WASSER_SCHWIMMEND)
            {
                if (forbidden_msg_soul_action_notify(
                    "lach", str, NETT, 0,
                    "Du waberst durchs Wasser vor Lachen.",
                    Wer(owner, ART_AAA)+" wabert durchs Wasser vor Lachen.",
                    MA_EMOTE, MT_LOOK | MT_NOISE))
                    return 1;
            }
            else
            {
                if (forbidden_msg_soul_action_notify(
                    "lach", str, NETT, 0,
                    "Du waberst am Boden vor Lachen.",
                    Wer(owner, ART_AAA)+" wabert am Boden vor Lachen.",
                    MA_EMOTE, MT_LOOK | MT_NOISE))
                    return 1;
            }
        }
        else
        {
            if (forbidden_msg_soul_action_notify(
                "lach", str, NETT, 0,
                "Du kippst um vor Lachen.",
                Wer(owner, ART_AAA)+" kippt um vor Lachen.",
                MA_EMOTE, MT_LOOK | MT_NOISE))
                return 1;
        }

        feel(owner);
        return 1;
    }

    return soul_adv_part(soul_parser(str, IGNORE_FAR),
                          "lach", NETT, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
                          0, "zu", FALL_DAT);
}


int laechle(string str)
{
    if(IS_GHOST)
    {
        if(!str)
        {
            msg_notify("Du laechelst innerlich.");
            return 1;
        }
        else
            return soul_adv_part(
                soul_parser(str, IGNORE_FAR),
                "laechel", NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
                0, "an", FALL_AKK, 0, "geisterhaft");
    }
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR),
        "laechel", NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
        0, "an", FALL_AKK);
}



int lecke(string str)
{
    mixed *res;

    NO_GHOST;

    res = soul_parser(str);
    if (!sizeof(res))
        return 1;

    if (res[0])
        return soul_adv_part(
            soul_parser(str,PARTNER),
            "leck", NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
            0, "ab", FALL_AKK);
    return soul_plus_adv(res[1], "leck",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                          "die Lippen", 0, "lasziv", 2);
}


int liebe(string str)
{
    mixed *res;
    NO_GHOST;

    res = soul_parser(str, PARTNER);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Unterbreite wem eine Liebeserklaerung?");
        return 1;
    }
    if (res[0]==owner)
    {
        msg_notify("Auch Narzissmus kennt gewisse Grenzen...");
        return 1;
    }

    if (forbidden_msg_soul_action_partner_notify(
    	res[0], "lieb", 0, NETT, 0,
        "Du erzaehlst "+xdeinem(res[0])+" deine aufrichtigen Gefuehle.",
        Wer(owner, ART_AAA)+" fluestert "+xdir(res[0])+" was von Liebe ins Ohr.",
        Wer(owner, ART_AAA)+" fluestert sanft zu "+xseinem(res[0])+".",
        MA_EMOTE, MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK))
    	    return 1 ;

    feel(owner);
    return 1;
}


int maule(string str)
{
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR),
        "maul", MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "an", FALL_AKK);
}


int moshe(string str)
{
    NO_GHOST;

    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "mosh", str, NEUTRAL, 0,
            "Du pumpst deinen Kopf auf und ab wie den Kolben einer "
              "Dampfmaschine, waehrend deine Beine gleichzeitig die "
              "irrsinnigsten Verrenkungen machen.\n"
              "MOOOOOOOOOOOOOOOOOOSH!",
             Wer(owner, ART_AAA)+" pumpt "+
               seinen((["name":"kopf", "gender":"maennlich"]),0,owner)+
               " auf und ab wie den Kolben "
               "einer ausser Kontrolle geratenen Dampfmaschine. "
               "Gleichzeitig vollfuehren "+
               sein((["name":"beine","gender":"saechlich","plural":1]),0,owner)+
               " erstaunliche, rhythmische Verrenkungen. "
               "Ein Wunder, dass "+er(owner)+" sich dabei nichts bricht.\n"
               "MOOOOOOOOOOOOOOOOOOSH!",
             MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "mosh",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                          "in der Gegend rum");
}


int nerve(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, PARTNER),
        "nerv", MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
        0, 0, FALL_AKK, 0, "unertraeglich");
}


int nicke(string str)
{
    if(IS_GHOST)
    {
        if (forbidden_msg_soul_action_notify(
            "nick", str, NEUTRAL, 0,
            "Du waberst auf und ab.",
            Wer(owner, ART_AAA)+" wabert auf und ab.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
        return 1;
    }

    NO_GHOST;

    return soul_adv_part(
        soul_parser(str, IGNORE_FAR),
        "nick", NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
        0, "zu", FALL_DAT);
}


int niese(string str)
{
    mixed res;

    NO_GHOST;

    if(!str)
    {
        if (forbidden_msg_soul_action_notify(
            "nies", 0, NEUTRAL, 0,
            "Du musst heftig niesen.\n"
              "Gesundheit!",
             Wer(owner, ART_AAA)+" niest.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    res = soul_parser(str);
    if (!sizeof(res))
        return 1;

    if (livingp(res[0]))
        return soul_adv_part(
            res, "nies",
            MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE | MT_FEEL, 0,
            MT_LOOK | MT_NOISE,
            0, "voll ins Gesicht", FALL_DAT);
    else
        return soul_adv_part(
            res, "nies",
            NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
            0, "an", FALL_AKK);
}


int noergle(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str),
        "noergel", MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "von schraeg hinten an", FALL_AKK,
        0, "wie ein altes Waschweib");
}


int ohrfeige(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, SOUL_PL), "gib",
        MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK | MT_NOISE,
        0, "eine Ohrfeige", FALL_DAT,
        "Gib wem <wie> eine Ohrfeige?");
}

int patsch(string str)
{
    mixed *res;

    res = soul_parser(str, PARTNER);

    if (!sizeof (res))
    {
        msg_notify("patsche wen <wie>?");
        return 1;
    }
    if (!sizeof(res) || !res[0] || (res[0]==owner))
    {
        if (forbidden_msg_soul_action_notify(
            "patsch", 0, NEUTRAL, 0,
            ("Du patschst Dir")+(sizeof(res)?res[1]:" ")+" an Deine Stirn.",
            (Wer(owner, ART_AAA)+" patscht sich")
                +(sizeof(res)?res[1]:" ")+" an die Stirn.",
            MA_EMOTE, MT_LOOK))
            return 1;
        feel(owner);
        return 1;
    }

    if (livingp(res[0]))
    {
	if (forbidden_msg_soul_action_partner_notify(
        res[0], "patsch", res[1], NEUTRAL, 0,
        "Du patschst "+dem(res[0])+res[1]+" an die Stirn.",
        Wer(owner, ART_AAA)+" patscht Dir"+res[1]+" an Deine Stirn.",
        Wer(owner, ART_AAA)+" patscht "+dem(res[0])+res[1]+" an die Stirn.",
        MA_EMOTE, MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK | MT_NOISE))
    	    return 1 ;
    }
    else
    {
	return soul_adv_part(
    	    res, "patsch", 
	    NEUTRAL, 0, MA_EMOTE,
	    MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK | MT_NOISE,
	    "auf", 0, FALL_AKK);
    }
    feel(owner);
    return 1;
}

int pfeife(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR), "pfeif",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "nach", FALL_DAT, 0, "unschuldig");
}


int piepse(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "pieps",
                          NEUTRAL, 0, MA_EMOTE, MT_NOISE, 0,
                          "herum", 0, "wie ein kleines Voegelchen");
}


int pinkle(string str)
{
    mixed   res;
    object  *inv ;
    int     i;

    NO_GHOST;

    if (IM_WASSER_SCHWIMMEND)
    {
        res = soul_parser(str) ;
        if (!sizeof(res))
            return 1;

        if (str && res[0])
        {
            if (forbidden_msg_soul_action_notify(
                "pinkel", str, NEUTRAL, 0,
                "Du versuchst "+xdeinen(res[0])+" anzupinkeln. "
                  "Ups, das ging wohl in die ohnehin schon nasse Hose.",
                "Das Wasser um "+den(owner)+" faerbt sich ploetzlich "
                  "leicht gelblich.",
                MA_EMOTE, MT_LOOK))
                return 1 ;
        }
        else
        {
            if (forbidden_msg_soul_action_notify(
                "pinkel", str, NEUTRAL, 0,
                "Du pinkelst unauffaellig. "
                  "Ups, das ging wohl in die ohnehin schon nasse Hose.",
                "Das Wasser um "+den(owner)+" faerbt sich ploetzlich "
                  "leicht gelblich.",
                MA_EMOTE, MT_LOOK))
                return 1 ;
        }
        this_player()->set_handeln();
    }
    else
    {
        inv = all_inventory(owner);
        for (i = sizeof(inv)-1; i >= 0 ; i--)
            if (inv[i]->query_typ() == "hose" && inv[i]->query_worn())
            {
                if (forbidden_msg_soul_action_notify(
                    "pinkel", str, NEUTRAL, 0,
                    Dein(inv[i])+" wird langsam warm und waermer.",
                    Ihr(inv[i])+" beginnt zu tropfen. "
                      "Um "+ihn(owner)+" bildet sich eine kleine "
                      "Pfuetze am Boden.",
                    MA_EMOTE, MT_LOOK | MT_SMELL))
                    return 1 ;

                feel(owner);
                return 1;
            }

        if (!str)
        {
            if (forbidden_msg_soul_action_notify(
                "pinkel", str, NEUTRAL, 0,
                "Du pinkelst unauffaellig.",
                Wer(owner, ART_AAA)+" pinkelt unauffaellig in einem vermeintlich "
                 "unbeobachteten Augenblick.",
                MA_EMOTE, MT_LOOK | MT_SMELL))
                return 1 ;
        }
        else
        {
            res = soul_parser(str);
            if (!sizeof(res))
                return 1;

            if (livingp(res[0]) && !pflanzlichp(res[0]) && res[0]!=ENV(owner))
                return soul_adv_part(
                    res, "pinkel",
                    MIES, 0, MA_EMOTE,
                    MT_LOOK, MT_LOOK | MT_FEEL | MT_SMELL, MT_LOOK,
                    0, "ans Bein", FALL_DAT);
            else
                return soul_adv_part(
                    res, "pinkel",
                    MIES, 0, MA_EMOTE,
                    MT_LOOK, MT_LOOK | MT_FEEL | MT_SMELL, MT_LOOK,
                    0, "an", FALL_AKK, 0, "in hohem Bogen");
        }
    }

    feel(owner);
    return 1;
}


int pople(string str)
{
    mixed  *res;
    NO_GHOST;
    if(!str)
    {
        if (forbidden_msg_soul_action_notify(
            "popel", str, NEUTRAL, 0,
            "Du popelst hingebungsvoll in deiner Nase. Vielleicht findest "
              "du ja Oel!",
            Wer(owner, ART_AAA)+" popelt hingebungsvoll in "+
              seinem((["name":"nase","gender":"weiblich"]),0,owner)+". "
              "Offensichtlich"+ist(owner,3)+er(owner)+
	      " auf der Suche nach Oel oder aehnlichem.",
            MA_EMOTE, MT_LOOK | MT_FEEL, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }

    res = soul_parser(str, 0, "an");
    if (!sizeof(res))
        return 1;
    if (!res[0])
        return soul_plus_adv(res[1], "popel",
                              NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, MT_LOOK,
                              ({ "in deiner Nase",
                                 "in "+
                                 seinem((["name":"nase","gender":"weiblich"]),
                                        0,owner)}));
    else
        return soul_adv_part(res, "popel",
                              NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                              "an", "herum", FALL_DAT);
}


int pruste(string str)
{
    mixed  res;

    NO_GHOST;

    res = soul_parser(str, NOT_TO_ENV);
    if (!res || (!sizeof (res)))
    {
        if (forbidden_msg_soul_action_notify(
            "pruste", str, NEUTRAL, 0,
            "Du prustest lauthals vor Lachen.",
            Wer(owner, ART_AAA)+" prustet lauthals vor Lachen.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;
    }
    else
    {
        if (res[0])
            return soul_adv_part(res, "pruste",
                                  NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
                                  0, "vor Lachen um", FALL_AKK);
        else
        {
            if (res[1] == "")
                res[1] == " lauthals";
            if (forbidden_msg_soul_action_notify(
                "pruste", str, NEUTRAL, 0,
                "Du prustest"+res[1]+" vor Lachen.",
                Wer(owner, ART_AAA)+" prustet"+res[1]+" vor Lachen.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;
        }
    }

    feel(owner) ;
    return 1;
}


int quaele(string str)
{
    mixed *res;

    NO_GHOST;

    res = soul_parser(str,SOUL_PL|NOT_TO_ENV);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        if (forbidden_msg_soul_action_notify(
            "quael", str, NEUTRAL, 0,
            "Du quaelst dich"+res[1]+".",
            Wer(owner, ART_AAA)+" quaelt sich"+res[1]+".",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }
    else
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "quael", 0, MIES, 0,
            "Du trittst "+xdeinem(res[0])+" kraeftig auf die Fuesse, "
              "dann drueckst du "+ihm(res[0])+" leidenschaftlich "
              "die Nase zu, als "+er(res[0])+" daraufhin den Mund "
              "aufsperrt ziehst du "+seinen((["name":"zunge",
              "gender":"weiblich"]),0,res[0])+" ganz lang und "
              "ziehst zum Abschluss ganz fest an "
              +seinem((["name":"ohren","gender":"saechlich",
                       "plural":1]),"beid",res[0])+".",
            Wer(owner, ART_AAA)+" tritt "+xdir(res[0])+" kraeftig auf deine Fuesse, "
              "dann drueckt "+er(owner)+" "+xdir(res[0])+" leidenschaftlich "
              "die Nase zu, als "+xdu(res[0])+" daraufhin den Mund "
              "aufsperrst zieht "+der(owner)+" deine Zunge "
              "ganz lang und "
              "zieht zum Abschluss ganz fest an "
              "deinen beiden Ohren. Au, ist das gemein.",
            Wer(owner, ART_AAA)+" tritt "+xseinem(res[0])+" kraeftig auf die Fuesse, "
              "dann drueckt "+er(owner)+" "+ihm(res[0])+" leidenschaftlich "
              "die Nase zu, als "+er(res[0])+" daraufhin den Mund "
              "aufsperrt zieht "+der(owner)+" die Zunge von "
              +dem(res[0])+" ganz lang und "
              "zieht zum Abschluss ganz fest an "
              +seinem((["name":"ohren","gender":"saechlich",
                        "plural":1]),"beid",res[0])+".",
            MA_EMOTE,
            MT_LOOK | MT_FEEL, MT_LOOK | MT_FEEL | MT_TASTE, MT_LOOK))
            return 1 ;
    }

    feel(owner) ;
    return 1;
}


int quengle(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, 0, "an"), "quengel",
        MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        "an", "herum", FALL_DAT);
}


int raeuspere(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "raeusper",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          0, 0, "unauffaellig", 1);
}


int reibe(string str)
{
    mixed *res;
    string wie;

    NO_GHOST;

    res = soul_parser(str,PARTNER);
    if (!sizeof(res))
        return 1;
    if (!res[0]) {
        if (res[1] != "")
            return soul_plus_adv(
                res[1], "reib",
                NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                0, 0, 0, 2);
        else
            return soul_plus_adv(
                "", "reib",
                NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                ({ "deine Haende",
               seinen((["name":"haende","gender":"maennlich","plural":1]),
                   0, owner)}),
                0, 0, 2);
    }
    if (res[1] == "")
        wie = (livingp(res[0]) ? " verschmust" : "") +" wie eine Katze";
    else {
        wie = res[1];
        res[1] = "";
    }
    return soul_adv_part(res, "reib",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
        ({"dich"+wie+" an","sich"+wie+" an"}), 0, FALL_DAT);
}


int roechle(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "roechel",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          0, 0, "mitleiderregend");
}


int ruelpse(string str)
{
    mixed res;

    NO_GHOST;

    res = soul_parser(str);
    if (!sizeof(res))
        return 1;

    if (livingp(res[0]))
        return soul_adv_part(
            res, "ruelps", MIES, 0, MA_EMOTE,
            MT_LOOK | MT_NOISE,
            MT_LOOK | MT_NOISE | MT_SMELL, MT_LOOK | MT_NOISE,
            0, "direkt ins Gesicht", FALL_DAT, 0, "unanstaendig");
    else
        return soul_adv_part(
            res, "ruelps", MIES, 0, MA_EMOTE,
            MT_LOOK | MT_NOISE,
            MT_LOOK | MT_NOISE | MT_SMELL, MT_LOOK | MT_NOISE,
            0, "an", FALL_AKK);
}


int ruempfe(string str)
{
    NO_GHOST;
    return soul_plus_adv(
        str, "ruempf",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
        ({"deine Nase",seinen((["name":"nase",
                               "gender":"weiblich"]), 0, owner)}),
        0, "angewidert");
}


int runzle(string str)
{
    NO_GHOST;
    return soul_plus_adv(
        str, "runzel",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
        ({"deine Stirn",seinen((["name":"stirn",
                                "gender":"weiblich"]), 0, owner)}));
}


int sabbere(string str)
{
    mixed   res;

    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "sabber", str, NEUTRAL, 0,
            "Ihgitt! Du sabberst ja!",
            "Speichelfaeden triefen "+dem(owner)+" aus dem Mund. Es ist "
              "geradezu widerlich, wie "+er(owner)+" sabbert!",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }

    res = soul_parser(str);
    if (!sizeof(res))
        return 1;

    if (IM_WASSER_SCHWIMMEND || !livingp(res[0]))
        return soul_adv_part(
            res, "sabber",
            MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
            0, 0, FALL_AKK, 0, "an");
    else
        return soul_adv_part(
            res, "sabber",
            MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
            0, "auf die Fuesse", FALL_DAT);
}


int schaeme(string str)
{
    NO_GHOST;
    return soul_plus_adv(
        str, "schaem",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
        "in Grund und Boden", 0, 0, 1);
}


int schimpfe(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "schimpf", str, NEUTRAL, 0,
            "Du schimpfst laut und wuetend herum.",
            Wer(owner, ART_AAA)+" schimpft laut und wuetend herum.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(
        soul_parser(str), "schimpf",
        MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "aus", FALL_AKK, 0, "fuerchterlich");
}


int schluchze(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "schluchz",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE);
}


int schlucke(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "schluck", 0, NEUTRAL, 0,
            "*schluck* ---- GULP!",
            Wer(owner, ART_AAA)+" schluckt trocken.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str, "schluck",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE);
}

int schmatze(string str)
{
    return soul_plus_adv(str, "schmatz",
	NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
	0, 0, "laut");
}

int schmolle(string str)
{
    mixed res;

    NO_GHOST;

    res = soul_parser(str, IGNORE_FAR);
    if (!sizeof(res))
        return 1;

    if (res[0])
        return soul_adv_part(
            res, "schmoll",
            NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
            0, "an", FALL_AKK);
    else
        if (query_innenraum(ENV(owner)))
            return soul_plus_adv(str, "schmoll",
                              NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                              "in der Ecke");
        else
            return soul_plus_adv(str, "schmoll",
                              NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                              "in der Gegend herum");
}


int schmunzle(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR), "schmunzel",
        NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
        0, "an", FALL_AKK);
}


int schmuse(string str)
{
    NO_GHOST;

    if (zustand != SEELE && me(str))
    {
        if (forbidden_msg_soul_action_partner_notify(
            TO, "schmus", 0, NETT, 0,
            "Du schmust "+xdeinen()+" ganz sanft zu dir her. "
              "Oh, wie schoen, dass du "+ihn()+" bei dir hast.",
            Wer(owner, ART_AAA)+" schmust mit dir.",
            Wer(owner, ART_AAA)+" schmust gluecklich mit "+xseinem()+". "+
              "Ach, wenn du das jetzt doch auch haben koenntest...",
             MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
        return 1 ;
    }

    if (str && (str[0..3]=="mit ")) str = str[4..];

    return soul_adv_part(soul_parser(str, PARTNER, "mit"), "schmus",
                          NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                          "mit", 0,  FALL_DAT, "Schmuse mit <wem> <wie>?");
}


int schnarche(string str)
{
    NO_GHOST;

    if (forbidden_msg_soul_action_notify(
        "schnarch", 0, NEUTRAL, 0,
        "Zzzzzzzzzz...",
        Wer(owner, ART_AAA)+" schnarcht laut.",
        MA_EMOTE, MT_LOOK | MT_NOISE))
        return 1 ;

    feel(owner);
    return 1;
}


int schnaube(string str)
{
    return soul_adv_part(
        soul_parser(str), "schnaub",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "an", FALL_AKK, 0, "veraechtlich");
}


int schnaufe(string str)
{
    mixed res;

    NO_GHOST;

    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "schnauf", 0, NEUTRAL, 0,
            "Du schnaufst wie ein Walross.",
            Wer(owner, ART_AAA)+" schnauft wie ein Walross.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    if(sizeof(res = soul_parser(str, PARTNER)) && livingp(res[0]))
        return soul_adv_part(
            res, "schnauf",
            NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
            0, "ins Ohr", FALL_DAT);
    else
        return soul_adv_part(
            res, "schnauf",
            NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
            0, "an", FALL_AKK);
}


int schneuze(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "schneuz",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          "in ein Taschentuch", 0, "ausgiebig", 1);
}


int schniefe(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str), "schnief",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "an", FALL_AKK);
}


int schnippe(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "schnipp",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          "mit den Fingern");
}

int schnuckel(string str)
{
    mixed *res;

    NO_GHOST;

    res = soul_parser(str, PARTNER, "mit");
    
    if (!sizeof(res))
	return 1;
    if (!res[0])
        return notify_fail("Mit wem willst Du schnuckeln?\n");

    if (res[0] == owner)
        return notify_fail("Mit Dir selbst schnuckeln kannst Du nicht.\n");

    if (forbidden_msg_soul_action_partner_notify(
        res[0],"schnuckel",res[1],NETT,0,
        "Du schnuckelst Dich an "+xdeinen(res[0])+res[1]+" ran und spuerst "
       +(livingp(res[0])
         ? "die Waerme "
          +des((["name":"koerper","gender":"maennlich",
	         "plural":QUERY("plural", res[0]), "adjektiv":({"ander"})]))
          +" an Deinem Koerper."
         : ihn(res[0])+" an Deinem Koerper."),
        Der(owner)+" schnuckelt sich an "+xdich(res[0])+res[1]+" ran und Du fuehlst "
       +"Dich erwaermt.",
        Der(owner)+" schnuckelt sich an "+xseinen(res[0])+res[1]+" ran.",
        MA_EMOTE,  MT_LOOK))
        return 1;

    feel(owner);
    return 1;
}

int schnurre(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "schnurr", 0, NEUTRAL, 0,
            "SSSCCCHHHNNNUUUUUUUUUUURRRRRRRRRRRR!\nDu schnurrst zufrieden.",
            Wer(owner, ART_AAA)+" schnurrt zufrieden.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(
        soul_parser(str), "schnurr",
        NETT, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
        0, "an", FALL_AKK);
}


int schreie(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "schrei", 0, NEUTRAL, 0,
            "AUUUAAAHHHHHH!!!!",
            Wer(owner, ART_AAA)+" schreit laut!",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1;

        feel(owner);
        return 1;
    }
    return soul_adv_part(soul_parser(str), "schrei",
                          MIES, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
                          0, "an", FALL_AKK, 0, 0, "!");
}


int schwitze(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "schwitz",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_SMELL, 0,
                          0, 0, "heftig");
}


int schuettle(string str)
{
    mixed *res;
    int pos;
    string st, wie;

    NO_GHOST;
    if (!str || (str == ""))
{
        msg_notify(
            "Schuettle mich <wie> | kopf <wie> | wen <wie> | was <wie> | "
            "wessen Hand / Haende <wie> | wem die Hand / Haende <wie>?");
        return 1;
    }
    st = space (lower_case (str));
    if (strstr(st+" ", "mich ") == 0)
    {
        if (strlen (str) > 5)
        {
            wie = str [5..strlen(str)-1];
            if (forbidden_msg_soul_action_notify(
                "schuettel", wie, NEUTRAL, 0,
                "Du schuettelst dich "+wie+".",
                Wer(owner, ART_AAA)+" schuettelt sich "+wie+".",
                MA_EMOTE, MT_LOOK))
                return 1 ;
        }
        else
        {
            if (forbidden_msg_soul_action_notify(
                "schuettel", 0, NEUTRAL, 0,
                "Du schuettelst dich.",
                Wer(owner, ART_AAA)+" schuettelt sich.",
                MA_EMOTE, MT_LOOK))
                return 1 ;
        }
    }
    else if ((strstr (st+" ","meinen kopf ") == 0) || 
             (strstr (st+" ","kopf ") == 0))
    {
        if (st[0] == 'm') str = str[7..]; // ggf. "meinen" abschneiden
        if (strlen (str) > 5)
        {
            wie = str [5..strlen(str)-1];
            if (forbidden_msg_soul_action_notify(
                "schuettel", wie, NEUTRAL, 0,
                "Du schuettelst deinen Kopf "+wie+".",
                Wer(owner, ART_AAA)+" schuettelt "
                  +seinen((["name":"kopf","gender":"maennlich"]),0,owner)
                  +" "+wie+".",
                MA_EMOTE, MT_LOOK))
                return 1 ;
        }
        else
        {
            if (forbidden_msg_soul_action_notify(
                "schuettel", 0, NEUTRAL, 0,
                "Du schuettelst deinen Kopf.",
                Wer(owner, ART_AAA)+" schuettelt "
                  +seinen((["name":"kopf","gender":"maennlich"]),0,owner)+".",
                MA_EMOTE, MT_LOOK))
                return 1;
        }
    }
    else if ((strstr (str+" ","haende ") != -1) || 
             (strstr (str+" ","hand ") != -1))
    {
        if (((pos = strstr (str,"s haende")) != -1)
            || ((pos = strstr (str,"' haende")) != -1))
            return soul_adv_part(
                soul_parser(str[0..pos-1]+str[pos+8..], SOUL_PL),
                "schuettel", NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, "die Haende", FALL_DAT,
                "Schuettle wessen Haende wie?");
        if (((pos = strstr (str,"s hand")) != -1)
            || ((pos = strstr (str,"' hand")) != -1))
            return soul_adv_part(
                soul_parser(str[0..pos-1]+str[pos+6..],SOUL_PL),
                "schuettel", NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, "die Hand", FALL_DAT,
                "Schuettle wessen Hand wie?");
        if ((pos = strstr (str," die haende")) != -1)
            return soul_adv_part(
                soul_parser(str[0..pos-1]+str[pos+11..],SOUL_PL),
                "schuettel", NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, "die Haende", FALL_DAT,
                "Schuettle wessen Haende wie?");
        if ((pos = strstr (str," haende")) != -1)
            return soul_adv_part(
                soul_parser(str[0..pos-1]+str[pos+7..],SOUL_PL),
                "schuettel", NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, "die Haende", FALL_DAT,
                "Schuettle wessen Haende wie?");
        if ((pos = strstr (str," die hand")) != -1)
            return soul_adv_part(
                soul_parser(str[0..pos-1]+str[pos+9..],SOUL_PL),
                "schuettel", NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, "die Hand", FALL_DAT,
                "Schuettle wessen Hand wie?");
        if ((pos = strstr (str," hand")) != -1)
            return soul_adv_part(
                soul_parser(str[0..pos-1]+str[pos+5..],SOUL_PL),
                "schuettel", NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, "die Hand", FALL_DAT,
                "Schuettle wessen Hand wie?");
        msg_notify("Schuettle wessen Hand / Haende <wie>?");
        return 1;
    }
    else
    {
        res = soul_parser(str);
        if (!sizeof(res))
            return 1;
        if (!res[0]) // Wenn das passiert, ist da ein Bug
            return soul_plus_adv(res[1], "schuettel",
                                  NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                                  0, 0, "albern", 1);
        if (livingp(res[0]))
            return soul_adv_part(
                res, "schuettel",
                NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, 0, FALL_AKK);
        else
            return soul_adv_part(
                res, "schuettel",
                NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, 0, FALL_AKK, 0, "wie bloede");
    }

    feel(owner) ;
    return 1;
}


int seufze(string str)
{
    mixed *res;
    
    res = soul_parser(str, IGNORE_FAR);
    
    if(!sizeof(res) || !res[0])
       return soul_plus_adv(str,"seufz",
                             NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
			     0, 0, (IS_GHOST)?"gespenstisch tief":"tief");
    else
       return  soul_adv_part(res, "seufz", NEUTRAL, 0, MA_EMOTE,
                             MT_LOOK | MT_NOISE, 0, 0,
                             0, "an", FALL_AKK, 0,
                             (IS_GHOST)?"gespenstisch tief":0);

}



int spucke(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "spuck", 0, MIES, 0,
            "Du spuckst.",
            Wer(owner, ART_AAA)+" spuckt auf den Boden.",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(
        soul_parser(str, PARTNER), "spuck",
        MIES, 0, MA_EMOTE, MT_LOOK, MT_LOOK | MT_FEEL, MT_LOOK,
        0, "an", FALL_AKK);
}


int starre(string str)
{
    mixed res;
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "starr", 0, NEUTRAL, 0,
            "Du starrst ins Leere.",
            Wer(owner, ART_AAA)+" starrt ins Leere.",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    if(!sizeof(res = soul_parser(str, PARTNER | IGNORE_FAR)))
        return 1 ;

    if (livingp(res[0]))
        return soul_adv_part(res, "starr",
                              NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
                              0, "tief in die Augen", FALL_DAT);
    else
        return soul_adv_part(res, "starr",
                              NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
                              0, "an", FALL_AKK);
}


int staune(string str)
{
    NO_GHOST;
    return soul_adv_part(soul_parser(str, IGNORE_FAR), "staun",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
                          0, "an", FALL_AKK, 0, "ueberrascht");
}


int stiere(string str)
{
    return soul_adv_part(soul_parser(str,PARTNER | IGNORE_FAR), "stier",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
                          0,"an",FALL_AKK, "Stiere wen oder was <wie> an?");
}


int stoehne(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "stoehn",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0,
                          0, 0, "laut");
}


int stolpere(string str)
{
    mixed *res;

    NO_GHOST;

    res = soul_parser(str, NOT_TO_ENV, "gegen");
    if (!sizeof(res))
        return 1;

    if (res[0])
        return soul_adv_part(res, "stolper",
                              NEUTRAL, PSEUDO_MOVE, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                              "gegen", 0, FALL_AKK, 0, "ungeschickt");
    return soul_plus_adv(res[1], "stolper",
                          NEUTRAL, PSEUDO_MOVE, MA_EMOTE, MT_LOOK, 0,
                          "herum");
}


int stolziere(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "stolzier",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                          "daher");
}


int stosse(string str)
{
    mixed res;
    NO_GHOST;
    if (!str)
    {
        msg_notify("Stosse wem <wie> in die Rippen?");
        return 1;
    }
    if (!sizeof(res = soul_parser(str,PARTNER)))
        return 1 ;

    if(livingp(res[0]))
        return soul_adv_part(res, "stoess",
                              MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                              0, "in die Rippen", FALL_DAT);
    else
        return soul_adv_part(res, "stoess",
                              MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                              0, 0, FALL_AKK);
    return 1;
}


int strahle(string str)
{
    NO_GHOST;
    return soul_adv_part(soul_parser(str, IGNORE_FAR), "strahl",
                          NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
                          0, "an", FALL_AKK,
                          "Strahle wen <wie> (an)?", "gluecklich");
}


int streichle(string str)
{
    NO_GHOST;
    return soul_adv_part(soul_parser(str,PARTNER), "streichel",
                          NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                          0, 0, FALL_AKK,
                          "Streichle wen <wie>?");
}


int stupse(string str)
{
    mixed *res;
    string str_owner, str_partner, str_others, str_gibt;
    mapping moepding;

    NO_GHOST;

    res = soul_parser(str, PARTNER);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Stupse wen?");
        return 1;
    }

     if (res[0] == owner)
     {
        msg_notify("Lass den Bloedsinn! "+
            (!wizp(owner) ?
                ("Mach lieber ein paar "+
		 ((owner->query_gilde()=="Orkgilde")?"Menschen":"Orks")+
		 " platt!") :
                "Programmier lieber was Lustiges!")+"");
        return 1;
    }


    if (!livingp(res[0]))
    {
        if(zustand == SEELE)
	{
	    return soul_adv_part(res, "stups",
		NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                0, "an", FALL_AKK);
	}
	else
	{
	    if (forbidden_msg_soul_action_partner_notify(
    		res[0], "stups", 0, NETT, 0,
		xDein()+" stupst "+xdeinen(res[0])+res[1]+" an.",
		Ihr()+" lehnt sich zu "+xdir(res[0])+" "+
        	    "rueber und stupst "+xdich(res[0])+
        	    " mit seiner weichen Pfote "+res[1]+" an.",
		Ihr()+" lehnt sich zu "+dem(res[0])+" rueber und stupst "+
		ihn(res[0])+res[1]+" an.",
    		MA_EMOTE, MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK | MT_NOISE))
    		    return 1 ;

	    feel(owner);
	    return 1;
	}
    }
    
    moepding = (["name":"nase","gender":"weiblich"]);
    str_gibt = "gibt";

    // fuer Pflanzen nach nem besseren Moepding suchen als Nase
    if (objectp(res[0]) && res[0]->material("pflanzlich")) {
        if (!res[0]->here("bluete",0,&moepding)
            && !res[0]->here("blatt",0,&moepding))
        moepding = (["name":"blatt","gender":"saechlich"]);
        if (moepding["plural"]) str_gibt = "geben";
    }

    if (objectp(res[0]) && ENV(res[0]) == owner)
        str_others = Der(moepding)+" "+str_gibt+" ein "
            "deutlich hoerbares MOEP von sich." ;
    else
        str_others = Ihr(moepding,0,res[0])+" "+str_gibt+
            " ein "+"deutlich hoerbares MOEP von sich.";

    if(zustand == SEELE)
    {
        str_owner = "Du stupst "+xdeinen(res[0])+" auf "+den(moepding)+"." ;
        str_partner = Wer(owner, ART_AAA)+" moept "+xdich(res[0])+
            ". Auf "+den(moepding)+"!";
    }
    else
    {
        str_owner = xDein()+" stupst "+xdeinen(res[0])+" auf "+den(moepding)+".";
        str_partner = Ihr()+" lehnt sich zu "+xdir(res[0])+" "+
            "rueber und stupst "+xdich(res[0])+
            " mit seiner weichen Pfote auf "+den(moepding)+".";
    }

    if (forbidden_msg_soul_action_partner_notify(
        res[0], "stups", 0, NETT, 0,
        str_owner, str_partner, str_others,
        MA_EMOTE, MT_LOOK | MT_FEEL | MT_NOISE, 0, MT_LOOK | MT_NOISE))
        return 1 ;

    feel(owner);
    return 1;
}




int taenzle(string str)
{
    NO_GHOST;
    return soul_adv_part(soul_parser(str, 0, "um"), "taenzel",
                          NETT, PSEUDO_MOVE, MA_EMOTE, MT_LOOK, 0, 0,
                          "um", "herum", FALL_AKK, 0, "wie ein Boxtroll");
}


int taetschel(string str)
{
    mixed *res;
    NO_GHOST;
    
    return soul_adv_part(res=soul_parser(str, PARTNER), "taetschel",
                          NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK, 0,
                          sizeof(res) && livingp(res[0]) && "den Kopf",
			  (sizeof(res) && livingp(res[0]))?FALL_DAT:FALL_AKK,
			  "Taetschle wem den Kopf?", "liebevoll");
}


int tanze(string str)
{
    mixed res;

    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "tanz", 0, NETT, PSEUDO_MOVE,
            "Kommst du dir nicht irgendwie bloed vor?",
             Wer(owner, ART_AAA)+" tanzt den Ententanz.",
             MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
    }
    else
    {
        if (strstr (str,"mit ") == 0)
            str = str[4..];
        if(!sizeof(res = soul_parser(str, NOT_TO_ENV, "mit")))
            return 1 ;

        if (objectp(res[0]))
        {
            if (living(res[0]))
                return soul_adv_part(
                    res, "schweb",
                    NETT, PSEUDO_MOVE, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                    "mit", "ueber den Tanzboden", FALL_DAT);
            else
                soul_adv_part(
                    res, "versuch",
                    NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                    "mit", "zu tanzen", FALL_DAT);
        }
        else
        {
            msg_notify("Tanze mit <wem oder was> <wie>?");
            return 1;
        }
    }
    return 1;
}


int taumle(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "taumel",
                          NEUTRAL, PSEUDO_MOVE, MA_EMOTE, MT_LOOK, 0,
                          "herum", 0, "scheinbar trunken");
}


int tobe(string str)
{
    string  tmp, tmp2 ;
    object  raum ;

    NO_GHOST;

    if (query_im_wasser(raum = ENV(owner)))
    {
        tmp  = "spritzt laut fluchend mit Wasser um dich" ;
        tmp2 = "spritzt laut fluchend mit Wasser um sich" ;
    }
    else if (query_innenraum(raum))
    {
        tmp = "springst laut schreiend durch den Raum" ;
        tmp2 = "springt laut schreiend durch den Raum" ;
    }
    else
    {
        tmp = "springst laut schreiend in der Gegend herum" ;
        tmp2 = "springt laut schreiend in der Gegend herum" ;
    }

    if (forbidden_msg_soul_action_notify(
        "tob", 0, NEUTRAL, PSEUDO_MOVE,
        "Du laeufst vor Wut rot an, ballst die Faeuste und "+tmp+".",
        Wer(owner, ART_AAA)+" laeuft vor Wut rot an, ballt die Faeuste und "+tmp2+". "
          "Was fuer ein wahnsinniger Tobsuchtsanfall!",
        MA_EMOTE, MT_LOOK | MT_NOISE))
        return 1 ;

    feel(owner);
    return 1;
}

int torkel(string str)
{
    NO_GHOST;

    if ((str = strip(str)) != "")
        str = " "+str;

    if (forbidden_msg_soul_action_notify(
        "torkel", str, NEUTRAL, 0,
        "Du kannst Dich vor lauter Alkohol nicht richtig halten und schwankst"
       +str+" herum. *lall*",
        Der(owner)+" kann sich vor lauter Alkohol nicht richtig halten und "
       +"schwankt"+str+" herum. *lall*",
        MA_EMOTE, MT_LOOK | MT_NOISE))
        return 1 ;

    feel(owner);
    return 1;
}

int traeume(string str)
{
    return soul_plus_adv(str, "traeum",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                          ({"vor dich hin","vor sich hin"}));
}


int trete(string str)
{
    mixed *res;

    NO_GHOST;

    res = soul_parser(str, PARTNER | NOT_TO_ENV, "gegen");
    if (!sizeof(res))
        return 1;

    // kryptisch,kryptisch...
    return soul_adv_part(
        res, "tritt",
        MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
        0,
        ((sizeof(res) && livingp(res[0])) ?
         "ans Knie" : 0),
        ((sizeof(res) && livingp(res[0])) ?
         FALL_DAT : FALL_AKK),
        "Trete wem oder was <wie> ans Knie?");
}


int troeste(string str)
{
    NO_GHOST;
    return soul_adv_part(soul_parser(str, PARTNER), "troeste",
                          NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                          0, 0, FALL_AKK, "Troeste wen <wie>?");
}


int umarme(string str)
{
    NO_GHOST;

    if (zustand != SEELE && me(str))
    {
        if (forbidden_msg_soul_action_partner_notify(
            TO, "umarm", 0, NETT, 0,
            "Du legst deine Arme um "+xdeinen()+" und haeltst "+
              ihn()+" ganz fest.",
            Wer(owner, ART_AAA)+" umarmt dich.",
            Wer(owner, ART_AAA)+" umarmt "+xseinen()+".",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;
        return 1 ;
    }

    return soul_adv_part(soul_parser(str, PARTNER), "umarm",
                          NETT, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                          0, 0, FALL_AKK, "Umarme wen <wie>?");
}


int verabschiede(string str)
{
    NO_GHOST;
    return soul_adv_part(soul_parser(str, PARTNER, "von"), "verabschiede",
                          NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
                          ({"dich von","sich von"}), 0, FALL_DAT,
                          "Verabschiede dich von wem <wie>?");
}


int verbeuge(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "verbeug", 0, NETT, 0,
            "Du verbeugst dich ehrfuerchtig.",
            Wer(owner, ART_AAA)+" verbeugt sich ehrfuerchtig.",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(soul_parser(str, IGNORE_FAR, "vor"), "verbeug",
                          NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
                          ({"dich vor","sich vor"}), 0, FALL_DAT);
}


int verneige(string str)
{
    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "verneig", 0, NETT, 0,
            "Du verneigst dich vor den Anwesenden.",
            Wer(owner, ART_AAA)+" verneigt sich anmutig.",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_adv_part(soul_parser(str, IGNORE_FAR, "vor"), "verneig",
                          NETT, 0, MA_EMOTE, MT_LOOK, 0, 0,
                          ({"dich vor","sich vor"}), 0, FALL_DAT);
}


int verneine(string str)
{
    if(IS_GHOST)
    {
        if (forbidden_msg_soul_action_notify(
            "vernein", 0, NEUTRAL, 0,
            "Du waberst verneinend hin und her.",
            Wer(owner, ART_AAA)+" wabert verneinend hin und her.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }
    else
    {
        if (forbidden_msg_soul_action_notify(
            "vernein", 0, NEUTRAL, 0,
            "Du schuettelst verneinend deinen Kopf.",
            Wer(owner, ART_AAA)+" schuettelt verneinend "+
              seinen((["gender":"maennlich","name":"kopf"]),0,owner)+".",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }

    feel(owner);
    return 1;
}

int verzweifel(string str)
{
    if (str)
    {
        if (forbidden_msg_soul_action_notify(
            "verzweifel", str, NEUTRAL, 0,
            "Du verzweifelst "+str+".",
            Der(owner)+" verzweifelt "+str+".",
            MA_EMOTE, MT_NOISE | MT_LOOK))
            return 1;
    }
    else if (forbidden_msg_soul_action_notify(
    	"verzweifel", 0, NEUTRAL, 0,
        "Du reisst Dir aus lauter Verzweifelung ein paar Haare aus.",
        Der(owner)+" reisst sich aus lauter Verzweiflung ein paar Haare aus.",
        MA_EMOTE, MT_LOOK | MT_NOISE))
        return 1 ;

    feel(owner);
    return 1;
}


int vogel(string str)
{
    mixed *res;

    res = soul_parser(str, IGNORE_FAR);
    if (!sizeof(res))
        return 1;

    if (!res[0] || res[0] == owner)
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "vogel", 0, NEUTRAL, 0,
            "Du klopfst ein paar mal ausdrucksstark mit dem Finger "
              "an deine Stirn und ueberpruefst dabei, ob du noch alle Tassen "
              "im Schrank hast.",
            0,
            Wer(owner, ART_AAA)+" tippt sich mit "+
              seinem((["name":"finger","gender":"maennlich"]), 0, owner)+
              " an die Stirn. Ob "+er(owner)+
              " sich wohl ein Voegelchen gefangen hat?",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    else
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "vogel", res[1], MIES, 0,
            "Du zeigst "+xdeinem(res[0])+" einen Vogel.",
            Wer(owner, ART_AAA)+" tippt mit "+
              seinem((["name":"finger","gender":"maennlich"]), 0, owner)+
              " an die Stirn und fragt sich, ob "+xdu(res[0])+" "+
              ((mappingp(res[0])) ? "sich" : "dir")+
              " da wohl ein Voegelchen gefangen hast?",
            Wer(owner, ART_AAA)+" zeigt "+xseinem(res[0])+" einen Vogel.",
            MA_EMOTE, MT_LOOK | MT_FEEL, MT_LOOK))
            return 1 ;
    }

    feel(owner) ;
    return 1 ;
}


int wackle(string str)
{
    NO_GHOST;
    return soul_plus_adv(str, "wackel",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0,
                          "mit dem Hintern");
}


int waelze(string str)
{
    if(IS_GHOST)
    {
        if (IM_WASSER_SCHWIMMEND)
        {
            if (forbidden_msg_soul_action_notify(
                "waelz", str, NETT, PSEUDO_MOVE,
                "Du waberst im Wasser hin und her vor Lachen.",
                Wer(owner, ART_AAA)+" wabert im Wasser hin und her vor Lachen.",
                MA_EMOTE, MT_LOOK | MT_NOISE))
                return 1;
        }
        else
        {
            if (forbidden_msg_soul_action_notify(
                    "waelz", str, NETT, PSEUDO_MOVE,
                    "Du waberst am Boden vor Lachen.",
                    Wer(owner, ART_AAA)+" wabert am Boden vor Lachen.",
                    MA_EMOTE, MT_LOOK | MT_NOISE))
                return 1;
        }
    }
    else
    {
        if (IM_WASSER_SCHWIMMEND)
        {
            if (forbidden_msg_soul_action_notify(
                "waelz", str, NETT, PSEUDO_MOVE,
                "Du waelzt dich vor Lachen im Wasser hin und her. "
                  "Vorsicht, sonst schluckst du zu viel Wasser dabei!",
                Wer(owner, ART_AAA)+" waelzt sich vor Lachen im Wasser hin und her und "
                  "schluckt dabei ordentlich.\n"
                  "Laut hustend und lachend prustet "+er(owner)+
                  " das Wasser wieder aus.",
                MA_EMOTE, MT_LOOK | MT_NOISE))
                return 1;
        }
        else
        {
            if (forbidden_msg_soul_action_notify(
                "waelz", str, NETT, PSEUDO_MOVE,
                "Du waelzt dich vor Lachen auf dem Boden.",
                Wer(owner, ART_AAA)+" waelzt sich vor Lachen auf dem Boden.",
                MA_EMOTE, MT_LOOK | MT_NOISE))
                return 1;
        }
    }

    feel(owner);
    return 1;
}


int weine(string str)
{
    mixed  *res;
    string tmp;

    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "wein", 0, NEUTRAL, 0,
            "Waaaaah!",
            Wer(owner, ART_AAA)+" bricht in Traenen aus.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    res = soul_parser(str);
    if (!sizeof(res))
        return 1;
    if (!res[0])
	return soul_plus_adv(str,"wein",NEUTRAL,0,MA_EMOTE,MT_LOOK | MT_NOISE);
    if (res[0]==owner)
    {
        msg_notify("Bei dir selbst? Aeh... Wie soll denn das gehen?");
        return 1;
    }

    if (livingp(res[0]))
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "wein", res[1], NEUTRAL, 0,
            "Du weinst dich an "+
              ihr((["name":"schulter","gender":"maennlich"]), 0, res[0],
                   0, 0, ART_DEIN)+
              // "der Schulter "+deines(res[0])+
              res[1]+" aus.",
            Wer(owner, ART_AAA)+" weint sich"+res[1]+" an deiner Schulter aus.",
            Wer(owner, ART_AAA)+" weint sich an "+
              ihr((["name":"schulter","gender":"maennlich"]), 0, res[0],
                   0, 0, ART_SEIN)+
              // der Schulter "+seines(res[0])+
              res[1]+" aus.",
            MA_EMOTE, MT_LOOK | MT_NOISE, MT_LOOK | MT_NOISE | MT_FEEL,
            MT_LOOK | MT_NOISE))
            return 1 ;
    }
    else
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "wein", res[1], NEUTRAL, 0,
            "Du weinst dich an "+xdeinem(res[0])+res[1]+" aus.",
            Wer(owner, ART_AAA)+" weint sich"+res[1]+" bei "+xdir(res[0])+" aus.",
            Wer(owner, ART_AAA)+" weint sich an "+xseinem(res[0])+res[1]+" aus.",
            MA_EMOTE, MT_LOOK | MT_NOISE, MT_LOOK | MT_NOISE | MT_FEEL,
            MT_LOOK | MT_NOISE))
            return 1 ;
    }

    feel(owner) ;
    return 1;
}


int wiehere(string str)
{
//    NO_GHOST;
    return soul_plus_adv(str, "wieher",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE);
}


int winke(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR), "wink",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
        0, "zu", FALL_DAT);
}


int wonke(string str)
{
    NO_GHOST;
    return soul_adv_part(
        soul_parser(str, IGNORE_FAR), "wonk",
        NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
        0, "zu", FALL_DAT);
}


int winsle(string str)
{
//    NO_GHOST;
    return soul_adv_part(soul_parser(str, IGNORE_FAR), "winsel",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_NOISE, 0, 0,
                          0, "an", FALL_AKK);
}


int wuerge(string str)
{
    mixed *res;

    NO_GHOST;
    if (!str)
    {
        if (forbidden_msg_soul_action_notify(
            "wuerg", 0, NEUTRAL, 0,
            "Argl... W U E R G! Wkrstfg...",
            Wer(owner, ART_AAA)+" wuergt vernehmlich.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;

        feel(owner);
        return 1;
    }
    res = soul_parser(str,SOUL_PL);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify("Wuerge wen?");
        return 1;
    }
    if (res[0] == owner)
    {
        if (forbidden_msg_soul_action_partner_notify(
            res[0], "wuerg", res[1], NEUTRAL, 0,
            "Du greifst an deinen Hals und wuergst dich"+res[1]+".",
            0,
            Wer(owner, ART_AAA)+" greift an "+
              seinen((["name":"hals","gender":"maennlich"]),0,owner)+
              " und wuergt sich"+res[1]+".",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }

    if (forbidden_msg_soul_action_partner_notify(
        res[0], "wuerg", res[1], MIES, 0,
        "Du wuergst "+xdeinen(res[0])+". Das erleichtert...",
        Wer(owner, ART_AAA)+" ergreift mit beiden Haenden deinen "
          "Hals und wuergt "+xdich(res[0])+
          " vehement. Dir bleibt die Luft weg bei so viel Frechheit...",
        Wer(owner, ART_AAA)+" faehrt "+xseinem(res[0])+" an die Gurgel und wuergt "+
          ihn(res[0])+".",
        MA_EMOTE, MT_LOOK | MT_FEEL))
        return 1 ;

    feel(owner);
    return 1;
}


int wuete(string str)
{
    string  what, wie;
    object  raum ;

    NO_GHOST;
    switch (owner->query_gender())
    {
        case "maennlich" : what="ein Irrer"; break;
        case "weiblich"  : what="eine Irre"; break;
        default          : what="ein Irres";
    }
    wie =
        "Du wuetest wie "+what+"! "
        "AAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHRRRRRRRRRRRRRRRGGGGGGGG"
        "GGGHHHHHHHH!!!!!" ;

    if (query_im_wasser(raum = ENV(owner)))
    {
        if (forbidden_msg_soul_action_notify(
            "wuet", wie, NEUTRAL, PSEUDO_MOVE,
            "Du patschst zornig mit den Haenden ins Wasser und "
              "spritzt anschliessend wild um dich fluchend herum! "+wie,
            Wer(owner, ART_AAA)+" patscht zornig mit den Haenden ins Wasser und "
              "spritzt anschliessend wild um sich fluchend herum. "+
              Er(owner)+" fuehrt sich auf wie Rumpelstielzchen.",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;
    }
    else if (query_innenraum(raum))
    {
        if (forbidden_msg_soul_action_notify(
            "wuet", wie, NEUTRAL, PSEUDO_MOVE,
            "Du stampfst zornig mit dem Fuss auf und rennst anschliessend "
              "die glatten Waende hinauf! "+wie,
            Wer(owner, ART_AAA)+" stampft zornig mit dem Fuss auf und rennt "
              "anschliessend die glatten Waende hinauf! "+
              Er(owner)+" wuetet wie "+what+".",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;
    }
    else
    {
        if (forbidden_msg_soul_action_notify(
            "wuet", wie, NEUTRAL, PSEUDO_MOVE,
            "Du stampfst zornig mit dem Fuss auf und tobst "
              "anschliessend wild um dich fluchend in der Gegend herum! "+wie,
            Wer(owner, ART_AAA)+" stampft zornig mit dem Fuss auf und tobt "
              "anschliessend wie Rumpelstielzchen in der Gegend herum. "+
              Er(owner)+" wuetet wie "+what+".",
            MA_EMOTE, MT_LOOK | MT_NOISE))
            return 1 ;
    }

    feel(owner);
    return 1;
}


int wundere(string str)
{
    if(IS_GHOST)
    {
        if (forbidden_msg_soul_action_notify(
            "wunder", 0, NEUTRAL, 0,
            "Du wunderst dich sehr.\nBahnhof? Aeguebdn?",
            Wer(owner, ART_AAA)+" muss sich schon sehr wundern.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }
    else
    {
        if (forbidden_msg_soul_action_notify(
            "wunder", 0, NEUTRAL, 0,
            "Du wunderst dich sehr.\nBahnhof? Aeguebdn?",
            Wer(owner, ART_AAA)+" muss sich schon sehr wundern. "
              "Verwirrt kratzt "+er(owner)+" sich am Kopf.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }

    feel(owner);
    return 1;
}


int wuschle(string str)
{
    mixed *res;
    object kopfbedeckung, *inv;
    mapping haare;
    int i;

    NO_GHOST;
    res = soul_parser(str,SOUL_PL);
    if (!sizeof(res))
        return 1;
    if (!res[0])
    {
        msg_notify(CAP(query_verb())+" wen?");
        return 1;
    }
    if (res[0] == owner)
    {
        inv = all_inventory (res[0]);
        for (i=sizeof(inv)-1; i>=0; i--)
            if (inv[i]->query_typ()=="muetze" && inv[i]->query_worn())
            {
                if (forbidden_msg_soul_action_notify(
                    "wuschel", res[1], NETT, 0,
                    "Du hast "+query_deklin(inv[i],ART_EIN,FALL_AKK,-2)+
                      " auf dem Kopf, "+ // dieser
                      wer(inv[i],ART_DIESER|ART_NO_NOMEN|ART_NO_ADJEKTIV)+
                      ist(inv[i],3)+"Dir leider im Weg.",
                    Wer(owner, ART_AAA)+" hebt kurz "+
                      seinen((["name":"haende","plural":1,
                               "gender":"weiblich"]), 0, owner)+
                      " zum Kopf, zieht sie aber sofort wieder zurueck.",
                    MA_EMOTE, MT_LOOK))
                    return 1 ;

                return 1;
            }

        if (forbidden_msg_soul_action_partner_notify(
            res[0], "wuschel", res[1], NETT, 0,
            "Du bringst deine Haare selber mit beiden Haenden "
              "in eine fuerchterliche Unordnung, deine Haarpracht "
              "ist jetzt ganz wirr und total zerzaust.",
            0,
            Wer(owner, ART_AAA)+" faehrt sich wie irre mit den Haenden "
              "in den Haaren herum, bis diese gaenzlich wirr und "
              "total zerzaust sind.",
            MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
            return 1 ;

        feel(owner) ;
        return 1;
    }
    if (objectp(res[0]) && living(res[0]))
    {
        inv = all_inventory (res[0]);
        for (i=sizeof(inv)-1; i>=0; i--)
            if (inv[i]->query_typ()=="muetze" && inv[i]->query_worn())
            {
                if (forbidden_msg_soul_action_partner_notify(
                    res[0], "wuschel", res[1], NETT, 0,
                    Der(res[0])+" hat "+
                      query_deklin(inv[i],ART_EIN,FALL_AKK,-2)+
                      " auf dem Kopf, "+ // dieser
                      wer(inv[i],ART_DIESER|ART_NO_NOMEN|ART_NO_ADJEKTIV)+
                      " "+ist(inv[i])+" dir leider im Weg.",
                    Wer(owner, ART_AAA)+" greift kurz nach deinem Kopf, zieht "+
                      seinen((["name":"haende","plural":1,
                               "gender":"weiblich"]), 0, owner)+
                      " aber sofort wieder zurueck.",
                     Wer(owner, ART_AAA)+" greift kurz nach "+
                       ihrem((["name":"kopf","gender":"maennlich"]),0,res[0])+
                       ", zieht "+
                       seinen((["name":"haende","plural":1,
                                "gender":"weiblich"]), 0, owner)+
                    " aber sofort wieder zurueck.",
                    MA_EMOTE, MT_LOOK))
                    return 1 ;
                return 1 ;
            }
    }

    haare = (["name":"haare","plural":1,"gender":"saechlich"]);

    if (objectp(res[0]) && res[0]->material("pflanzlich"))
        haare = (["name":"blaetter","plural":1,"gender":"saechlich"]);

    if (objectp(res[0]) && res[0]->query_race()=="vogel")
        haare = (["name":"federn","plural":1,"gender":"weiblich"]);

    if (objectp(res[0]) && 
        (res[0]->query_race()=="schlange" || res[0]->query_race()=="fisch"))
        haare = (["name":"schuppen","plural":1,"gender":"weiblich"]);

    if (objectp(res[0]) && res[0]->query_race()=="insekt")
        haare = (["name":"fuehler","plural":1,"gender":"maennlich"]);

    if (forbidden_msg_soul_action_partner_notify(
        res[0], "wuschel", res[1], NETT, 0,
        "Du verwuschelst mit einem froehlichen Laecheln im Gesicht "
          "ganz lieb "+den(haare)+" von "+xdeinem(res[0])+", bis sie herrlich "
          "durcheinander sind. "
          +Der(res[0])+" scheint das gerne zu haben.",
        Wer(owner, ART_AAA)+" verwuschelt "+xdir(res[0])+" mit "
          "einem froehlichen Laecheln im Gesicht ganz lieb "
          +deinen(haare)+", sie sind jetzt herrlich durcheinander. "
          "Ahhh, tut das gut... "+xDu(res[0])+" hast das gerne...",
        Wer(owner, ART_AAA)+" verwuschelt mit einem froehlichen Laecheln im Gesicht "
          +den(haare)+" von "+xseinem(res[0])+", bis sie herrlich "
          "durcheinander sind. "
          +Der(res[0])+" scheint das gerne zu haben.",
        MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK))
        return 1 ;

    feel(owner);
    return 1;
}


int zittere(string str)
{
    NO_GHOST;
    if(!str)
    {
        if (forbidden_msg_soul_action_notify(
            "zitter", 0, NEUTRAL, 0,
            "Du zitterst wie Espenlaub.",
            Wer(owner, ART_AAA)+" zittert wie Espenlaub.",
            MA_EMOTE, MT_LOOK))
            return 1 ;

        feel(owner);
        return 1;
    }
    return soul_plus_adv(str,"zitter",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK);
}


int zunge(string str)
{
    mixed *res;

    res = soul_parser(str, IGNORE_FAR);
    if (!sizeof(res))
        return 1;

    if (res && res[0])
    {
        if (res[0] == owner)
        {
            msg_notify("Wie soll das denn gehen? "
                        "Willst du deine Zunge verknoten?");
            return 1 ;
        }
        else
            return soul_adv_part(
                res, "streck",
                NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
                0,
                ({ "deine Zunge raus",
                   seinen((["name":"zunge","gender":"weiblich"]),
                           0, owner)+" raus" }), FALL_DAT);
    }
    else
    {
        if (res[1] == "")
            res[1] = " weit" ;

        if (forbidden_msg_soul_action_notify(
            "streck", str, NEUTRAL, 0,
            "Du streckst deine Zunge"+res[1]+" raus.",
            Wer(owner, ART_AAA)+" streckt "+
              seinen((["name":"zunge","gender":"weiblich"]), 0, owner)+
              res[1]+" raus.",
            MA_EMOTE, MT_LOOK))
            return 1 ;
    }

    feel(owner) ;

    return 1 ;
}


int zwicke(string str)
{
    mixed *res;
    NO_GHOST;
    
    return soul_adv_part(res = soul_parser(str, PARTNER), "zwick",
                          MIES, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK, 0,
                          sizeof(res) && livingp(res[0]) && "in die Nase",
			  FALL_AKK, "Zwicke wen <wie>?");
}


int zupfe(string str)
{
    mixed *res;
    NO_GHOST;
    
    res = soul_parser(str, PARTNER, "an");
    if(sizeof(res) && livingp(res[0]))
    {
	return soul_adv_part(res, "zupf",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                          0, "am Aermel", FALL_AKK, "Zupfe wen <wie>?");
    }
    else
    {
	return soul_adv_part(res, "zupf",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK | MT_FEEL, 0, MT_LOOK,
                          "an", 0, FALL_DAT, "Zupfe wen <wie>?");
    }
}


int zwinkere(string str)
{
    NO_GHOST;

    return soul_adv_part(soul_parser(str, IGNORE_FAR), "zwinker",
                          NEUTRAL, 0, MA_EMOTE, MT_LOOK, 0, 0,
                          0, "zu", FALL_DAT, 0, "vielsagend");
}
