// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /secure/master/auto_include.inc
// Description: Funktion fuer den Driver-Hook H_AUTO_INCLUDE
// Author:      Freaky (18.11.2001)
//
// $Log: auto_include.inc,v $
// Revision 1.45  2015/05/08 14:11:03  sorcerer
// RTTC jetzt fuer ganz UNI
//
// Revision 1.44  2014/03/13 08:58:32  sorcerer
// Aktuelle Pragma-Unterstuetzungen
//
// Revision 1.43  2013/06/21 21:01:36  sorcerer
// Viele Raetsel scharfgeschaltet fuer RTTC
//
// Revision 1.42  2013/06/19 18:19:36  myonara
// weitere 8 Raetsel RTTC aktiv geschaltet
//
// Revision 1.41  2013/06/03 19:44:08  sorcerer
// Schiffe jetzt auch mit RTTC
//
// Revision 1.40  2013/05/31 18:56:28  sorcerer
// ganze viele Raetsel jetzt mit RTTC
//
// Revision 1.39  2013-05-27 20:03:12  sorcerer
// Raetsel einzeln gelistet fuer nicht-RTTC
//
// Revision 1.38  2012-10-17 16:20:27  sorcerer
// strong_types, pedantic und priv. vars fuer alle, 
// RTTC fuer alle Gilden, if-Abfragen fuer Driverversion < 3.3 raus
//
// Revision 1.37  2012-10-15 14:05:48  sorcerer
// Metas und Ebenen auch mit RTTC
//
// Revision 1.36  2012-09-11 09:23:45  sorcerer
// strengere Richtlinien fuer diverse Bereiche
//
// Revision 1.35  2012-08-19 18:38:13  sorcerer
// Metamorpher nutzen alles ausser RTTC
//
// Revision 1.34  2012-01-07 17:21:45  sorcerer
// alle Codekontrollen fuer Doerrland aktiv
//
// Revision 1.33  2012-01-04 14:35:39  sorcerer
// RTTC fuer Doerrland
//
// Revision 1.32  2011-11-25 22:24:30  sorcerer
// RTTC fuer Bardengilde
//
// Revision 1.31  2011-01-09 21:32:13  sorcerer
// rttc fuer Spiele
//
// Revision 1.30  2010-11-13 21:04:25  sorcerer
// Campus und Midgard mit strengen Codestandards
//
// Revision 1.29  2010-10-30 14:24:00  sorcerer
// Diverse striktere Richtlinien
//
// Revision 1.28  2010-05-05 20:36:08  sorcerer
// RTTC fuer Kokos und OdF
//
// Revision 1.27  2010-04-04 17:50:41  sorcerer
// Kompatibilitaet fuer prae-3.3-efuns raus
//
// Revision 1.26  2010-03-15 10:46:43  sorcerer
// RTTC fuer Arktis
//
// Revision 1.25  2009-11-21 22:30:45  sorcerer
// komplett umstrukturiert und erweitert (RTTC)
//
// Revision 1.24  2009-11-19 12:18:45  sorcerer
// REGEXP_A und _B zusammengefuehrt (/w jetzt pedantic)
//
// Revision 1.23  2009-09-07 21:58:32  gnomi
// Mehr Bereiche mit schaerferen Bedingungen.
//
// Revision 1.22  2009-07-30 17:00:31  gnomi
// VARARGS raus.
//
// Revision 1.21  2009-06-17 07:59:53  gnomi
// VARARGS beim naechsten Neustart deaktivieren.
// Gallien und P haben schaerfere Bedingungen.
//
// Revision 1.20  2009-01-15 09:18:23  gnomi
// Schaerfere Regeln fuer die Druidengilde.
//
// Revision 1.19  2008/01/21 14:29:21  gnomi
// Statt "" 0 zurueckliefern (weniger Aufwand fuer den Driver).
//
// Revision 1.18  2005/02/13 14:38:29  menaures
// Strengere Regeln fuer Kokosinsel
//
// Revision 1.17  2005/02/02 22:32:50  gnomi
// Strengere Regeln auch fuer /z/Raetsel.
//
// Revision 1.16  2004/07/19 21:32:03  gnomi
// Pragma no_warn_missing_return (fuer den 3.3er) hinzugefuegt.
//
// Revision 1.15  2004/07/12 18:54:51  menaures
// Bugfix zum vorhergehenden Patch.
// Funktion neu gestaltet, es ist jetzt hoffentlich leserlicher.
//
// Revision 1.14  2004/07/12 12:14:59  gnomi
// Fuer Includes nichts mehr hinzufuegen, da Pragmas ja neuerdings auch ueber
// Include-Grenzen hinweg gelten.
//
// Revision 1.13  2004/05/12 20:55:48  gnomi
// Haertere Bedingungen auch fuers Hexenvolk.
//
// Revision 1.12  2003/05/07 04:42:32  gnomi
// Fuer Kokosinseln und /w kein pedantic.
//
// Revision 1.11  2003/05/06 02:41:20  gnomi
// Im /w gelten schaerfere Bedingung.
// verbose_errors fuer alle.
// Kokosinseln und Finsterlinge haben ebenfalls schaerfere Bedingungen.
//
// Revision 1.10  2003/01/25 19:12:10  gnomi
// Abfrage (welche testweise eingefuehrt wurde) wieder rausgenommen.
//
// Revision 1.9  2003/01/25 17:16:49  sissi
// *** empty log message ***
//
// Revision 1.7  2002/12/12 00:33:14  gnomi
// pragma verbose_errors fuers /w.
//
// Revision 1.6  2002/12/10 01:28:03  gnomi
// Bardengilde hat haertere Bedingungen.
//
// Revision 1.5  2002/10/17 13:47:07  freaky
// Versionsabhaengigkeit entfernt
//
// Revision 1.4  2002/03/16 12:11:34  gnomi
// Gallien hat keine haerteren Bedingungen mehr.
//
// Revision 1.3  2002/03/02 12:02:25  gnomi
// Ebenen haben nun auch die haerteren Bedingungen.
//
// Revision 1.2  2002/02/02 23:00:48  gnomi
// Einige Domains erhalten nun Pragmas zum genaueren Typcheck.
//
// Revision 1.1  2001/11/19 19:19:50  freaky
// fuer ldmud-3.2.9dev363 eingefuehrt.
//

string auto_include(string base_file, string current_file, int sys_include)
{
    string ret;

    if (sys_include || current_file)
    {
        // Kein Auto-Include String fuer Include-Dateien.
        // Es gelten die Einstellungen der Datei, die den #include ausfuehrt.
        return 0;
    }

    // Fehlenden / hinzufuegen
    base_file = "/"+base_file;


/*
   Einstellungen fuer alle
*/
    ret = "#pragma combine_strings, verbose_errors, warn_deprecated, "
                  "strong_types, save_types, pedantic, "
                  "no_warn_missing_return\n"
          "default private variables;\n";

#if __VERSION__ >= "3.5.0-2790"
    ret += "#pragma rtt_checks\n";
#endif // __VERSION__ >= "3.5.0-2790"
   

/*
   Einstellungen fuer TestMUD (Orbit), nicht UNItopia
*/
#ifdef TestMUD

#endif // TestMUD


/*
   besondere Einstellungen fuer Teile UNItopias, nicht TestMUD (Orbit)
     TODO: zu allgemeinen Einstellungen machen bzw. loswerden!
     ACHTUNG: /map/m enthaelt Files aller Domains!
*/
#if defined(UNItopia) && !defined(TestMUD)

/*
// das hier wieder aktivieren, falls kurzfrisitig doch ein Raetsel 
// die RTTCs wieder ausschalten muss
#define BAD_CODESTYLE "^/(z/Raetsel/(<DIR1>|<DIR2>)" \
                           "Admin|apps|i|obj|room|sys)" \
                        "|map/m)"

    if (!sizeof(regexp(({base_file}), BAD_CODESTYLE)))
    {
        ret += "#pragma rtt_checks\n";
    }
*/

#endif // defined(UNItopia) && !defined(TestMUD)


    return ret;
}
