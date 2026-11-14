// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	 /secure/master/alc.inc
// Description:  Verwaltung der ACLs
// Author:	 Sissi (1998)
// Modified by:  Sissi (04.01.1999):  Auch andere ACLs als SAVE / RESTORE
//                                    duerfen an Dateien vergeben werden.
//               Sissi (07.02.1999):  Umbenennen von Gruppen
//                                    query_debugger_acl
//               Sissi (22.10.1999):  .o und .c - Problematik bearbeitet
//               Sissi (18.05.2000):  eben jene hoffentlich abgehakt
//
//
// $Log: acl.inc,v $
// Revision 1.32  2016/03/21 12:40:27  gnomi
// strlen -> sizeof
//
// Revision 1.31  2013/07/06 04:10:23  myonara
// delete_acl_entry fuer ohne TI angepasst (goetter_register)
//
// Revision 1.30  2012-12-01 22:57:00  sorcerer
// indexing past string end behoben
//
// Revision 1.29  2010-07-04 09:41:50  sorcerer
// indexing past string end
//
// Revision 1.28  2009-06-17 07:59:01  gnomi
// Goetterregister darf auch ACLs abfragen und loeschen.
//
// Revision 1.27  2009-04-15 13:42:04  gnomi
// Fuers Goetterregister eine Abfragemoeglichkeit auf leere Gruppen eingebaut.
//
// Revision 1.26  2005/05/26 01:05:22  gnomi
// Goetter auf Urlaub beachten.
//
// Revision 1.25  2004/09/22 22:22:39  gnomi
// Konsistenzcheckausgabe sortieren.
// Bei Konsistenzcheck auf ueberfluessige Dateiendung bei Objekten pruefen.
//
// Revision 1.24  2003/05/28 01:09:07  gnomi
// ACLs koennen mit einem externen Define NO_ACLS deaktiviert werden.
//
// Revision 1.23  2003/05/09 01:46:16  gnomi
// Konsistenzcheck um Dateiendungscheck erweitert.
//
// Revision 1.22  2003/05/06 02:41:42  gnomi
// Bessere Meldungen bei Konsistenzcheck.
//
// Revision 1.21  2003/04/30 01:23:39  gnomi
// Konsistenzcheck eingebaut.
//
// Revision 1.20  2002/11/09 02:49:31  gnomi
// Auch fuer die WizShell zulassen.
//
// Revision 1.19  2002/08/07 23:31:17  gnomi
// Weitere Funktion, um nach ACLs fuer eine bestimmte Gruppe zu suchen.
//
// Revision 1.18  2002/01/20 19:58:36  gnomi
// add_acl_entry: Falls Datei nicht existiert, wird nur eine Warnung statt
// einer Fehlermeldung ausgegeben.
//
// Revision 1.17  2001/08/28 21:11:39  sissi
// query_acl_entry um den Parameter aclmask erweitert und die Funktion
// entsprechend abgeaendert, siehe Doku.
// Doku zu query_access verstaendlicher gemacht.
//
// Revision 1.16  2001/05/27 22:41:04  gnomi
// datei[strlen(datei)-1] -> datei[<1]
// (Kommt dann auch mit leeren Strings klar.)
//
// Revision 1.15  2001/05/19 20:40:01  gnomi
// Es werden auch Dateien akzeptiert, die kein ".c" am Ende haben.
//
// Revision 1.14  2001/05/01 00:07:41  sissi
// Keine Rechte mehr fuer nicht existierende Dateien vergebbar.
//
// Revision 1.13  2001/04/18 16:28:34  freaky
// keine simul-efuns im Master verwenden!
//
// Revision 1.12  2001/04/17 20:13:30  gnomi
// delete_acl_dir um ein ganzes Verzeichnis zu entfernen.
//
// Revision 1.11  2001/03/24 00:19:37  gnomi
// dump_acls: Verzeichnisse alphabetisch sortieren.
//
// Revision 1.10  2001/02/24 16:04:40  freaky
// member_array nach member umgebaut.
//
// Revision 1.9  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

// In der Hoffnung, dass es damit etwas leichter lesbar wird, einige Defines:

#define ACL_ROOT 0
#define ACL_PATH 0
#define ACL_RIGHTS_LIST 1
#define ACL_NODE 2
#define ACL_RIGHTS_WHO 0
#define ACL_RIGHTS_WHICH 1
#define ACL_ERROR -1
#define ACL_SUCCESS 0

#define SAVE_ACLS save_master()

mapping ACL = ([0:({})]);

// Ich hasse dieses Secure - Zeugs...
// Es frisst evals fuer das truegerische Gefuehl der Sicherheit,
// die nicht vorhanden ist.

#define ACL_SECURE(fehler) \
    if ((  (!this_interactive()) \
         || (this_interactive()!=this_player()) \
	 || (!previous_object()) \
         || (geteuid(previous_object())!=({string})this_interactive()->query_real_name()) \
	 || (object_name(previous_object())[0..15]!="/obj/zauberstab#"\
	     && strstr(object_name(previous_object()),"/obj/wizard_shell#")) \
	 || (query_verb()!="zacl")) \
	&& (object_name(previous_object()) != GOETTER_REGISTER)) \
	return fehler

#define ACL_DCHECK(datei,fehler) \
    if (!datei || (datei[0] != '/') || (strstr(datei,"//") >= 0) \
        || (strstr(datei,"/./") >= 0) || (strstr(datei,"/..") >= 0)) \
        return fehler

int query_acl_mapping_size ()
{
    return sizeof (ACL);
}


private int get_free_ACL_index()
{
    int i;
    for (i = 1; i > 0; i++)
        if (!member (ACL,i)) return i;
    // oh je, Katastrophe, das Mapping ist total voll!
    raise_error ("Das ACL - Mapping ist total voll!");
}

/*
FUNKTION: add_acl_entry
DEKLARATION: string add_acl_entry(string datei, string grouporwiz, int aclmask)
BESCHREIBUNG:
Fuegt fuer die Datei / das Verzeichnis pfad und die Gruppe oder den Wizard
grouporwiz den ACL - Eintrag hinzu, welcher durch die aclmask festgelegt ist.
Gibt einen String mit einer Fehlermeldung zurueck, falls es nicht geklappt
hat, oder 0, falls es geklappt hat.
VERWEISE: delete_acl_entry, query_acl_entry, query_access
GRUPPEN: master, acl
*/

string add_acl_entry (string datei, string grouporwizorfile, int aclmask)
{

    mixed entry;
    string *pfad, tempfad, ti_real_name;
    int i, j, aclindex, pfadpos, temp, darfdas;

    ACL_SECURE("So geht das aber nicht");
    ACL_DCHECK(datei,"Ungueltiger Pfad.");

    ti_real_name = ({string})this_interactive()->query_real_name();
    // die Ueberpruefung, dass this interactive existiert,
    // ein Spieler ist usw. machte bereits ACL_SECURE.

    // ACL_RESTORE und ACL_SAVE - Rechte koennen nur an Dateien vergeben
    // werden, ACL_DEBUG und ACL_ADMIN nur an Goetter / Gruppen.

    if (GOETTER_REGISTER->is_wiz(grouporwizorfile))
    {
        if ((aclmask & ACL_RESTORE) || (aclmask & ACL_SAVE))
            return "Goettern koennen weder Save- noch "
                   "Restore-Objekt-Rechte gegeben werden.\n";
        grouporwizorfile = lower_case(grouporwizorfile);
    }
    else if (GROUP_MASTER->group_exists(grouporwizorfile))
    {
        if ((aclmask & ACL_RESTORE) || (aclmask & ACL_SAVE))
            return "Gruppen koennen weder Save- noch "
                   "Restore-Objekt-Rechte gegeben werden.\n";
    }
    else // es ist entweder eine Datei oder gar nichts
    {
        if (grouporwizorfile[<2..] != ".c")
            grouporwizorfile += ".c";
        if (file_size (grouporwizorfile) < 0)
            return grouporwizorfile[0..<3]+" ist weder Gott noch "
                   "Gruppe noch Datei.\n";
        if (aclmask & ACL_DEBUG)
            return "Dateien kann kein Debug - Recht gegeben werden.\n";
        if (aclmask & ACL_ADMIN)
            return "Dateien kann kein Admin - Recht gegeben werden.\n";
        grouporwizorfile = grouporwizorfile[0..<3];
    }

    // ein .o am Ende abschneiden, das ist dann einheitlicher:
    if ((aclmask & ACL_SAVE) || (aclmask & ACL_RESTORE)) {
        if (datei[<2..] == ".o")
            datei = datei[0..<3];
    }

    // ein / am Ende abschneiden:
    while (datei[<1] == '/')
        datei = datei[0..<2];

    pfad = explode (datei[1..],"/");

    // bei .o - Dateien muss die Datei nicht existieren.
    if ((aclmask & ACL_SAVE) || (aclmask & ACL_RESTORE)) {
        if (file_size (tempfad=implode(pfad[0..<2],"/")) != FSIZE_DIR)
            return "Es gibt kein Verzeichnis /"+tempfad+".";
        if (file_size (datei) != FSIZE_DIR)
            datei += ".o"; 
    } else { 
        // bei normalen Dateien / Verzeichnissen muss sie jedoch existieren
	if (file_size (datei) != FSIZE_NOFILE) {}
	else if (file_size (datei+".c") != FSIZE_NOFILE) {
	    datei += ".c";
	    pfad [<1] += ".c";
        }
	else if(file_size(tempfad=implode(pfad[0..<2],"/")) != FSIZE_DIR)
		return "Es gibt kein Verzeichnis /"+tempfad+".";
	else
	    tell_object(this_player(),
		sprintf("Warnung: %-=68s\n","Es gibt weder eine Datei noch ein Verzeichnis "+datei+"!"));
    }

    // Wir starten im Acl - Root
    aclindex = ACL_ROOT;
    // Wir gehen pfad von links nach rechts durch
    pfadpos = 0;
    darfdas = adminp (this_interactive());
    do {
        // Erstmal den Knoten, der zu pfad[pfadpos] gehoert, suchen
	for (i = sizeof (ACL[aclindex])-1;
            (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]);
            i--);
        if (i < 0) {
            if (!darfdas)
                return "Du bist nicht als ACL - Admin hierfuer eingetragen.";
            // Knoten nicht gefunden, wir basteln einen neuen
            ACL[aclindex] += ({({pfad[pfadpos],0})});
            i = sizeof (ACL[aclindex]) - 1;
        }
        
        if (!darfdas && pointerp(ACL[aclindex][i][ACL_RIGHTS_LIST])) {
            // nachschauen, ob der Gott als ACL-Admin eingetragen ist.
            // natuerlich nur nachschauen, solange !darfdas.
            entry = ACL[aclindex][i][ACL_RIGHTS_LIST];
            for (j = 0;
                 (!darfdas) && (j < sizeof (entry));
                 j++)
                if (entry[j][ACL_RIGHTS_WHICH] & ACL_ADMIN)
                    if ((entry[j][ACL_RIGHTS_WHO] == ti_real_name)
                      || GROUP_MASTER->is_group_member(
                             ti_real_name,
                             entry[j][ACL_RIGHTS_WHO]))
                        darfdas = 1;
        }
        if (pfadpos < sizeof(pfad)-1) {
            // wir sind noch nicht am Pfadende angelangt, wechseln in das
            // Unterverzeichnis.
            // Erstmal schauen, ob das Unterverzeichnis bereits einen eigenen
            // Knoten besitzt (muss es nicht):
            if (sizeof(ACL[aclindex][i]) < 3) {
                // Das Verzeichnis besitzt noch keinen eigenen Knoten.
                // Wenn "darfdas" noch nicht erfuellt ist, kann es
                // das jetzt auch nicht mehr werden.
                if (!darfdas)
                    return "Du bist nicht als ACL-Admin hierfuer eingetragen.";
                // Andernfalls: wir basteln einen Knoten:
                temp=get_free_ACL_index();
                ACL[aclindex][i] += ({temp});
                aclindex = temp;
                ACL[aclindex] = ({});
            }
            else aclindex = ACL[aclindex][i][ACL_NODE];
        }
        pfadpos++;
    } while (pfadpos < sizeof (pfad));
    if (!darfdas)
        return "Du bist nicht als ACL-Admin hierfuer eingetragen.";
    // Der Knoten, in welchem wir die ACLs setzen muessen, ist
    // jetzt gefunden, es ist ACL [aclindex][i][ACL_RIGHTS_LIST].
    // Moeglicherweise ist dieser Knoten noch ganz leer, erstmal gucken:
    if (!pointerp(entry = ACL[aclindex][i][ACL_RIGHTS_LIST])) {
        ACL[aclindex][i][ACL_RIGHTS_LIST] = ({({grouporwizorfile,aclmask})});
        SAVE_ACLS;
        return ACL_SUCCESS;
    }
    for (j = 0; j < sizeof (entry); j ++)
        if (entry[j][ACL_RIGHTS_WHO] == grouporwizorfile) {
            entry[j][ACL_RIGHTS_WHICH] |= aclmask;
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
    // Kein Eintrag da, neuen machen.
    ACL[aclindex][i][ACL_RIGHTS_LIST] += ({({grouporwizorfile,aclmask})});
    SAVE_ACLS;
    return ACL_SUCCESS;
}

/*
FUNKTION: delete_acl_entry
DEKLARATION: string delete_acl_entry(string datei, string grouporwiz, int aclmask)
BESCHREIBUNG:
Entfernt fuer die Datei / das Verzeichnis pfad und die Gruppe oder den Wizard
grouporwiz den ACL - Eintrag, welcher durch die aclmask festgelegt ist.
Gibt eine Fehlermeldung zurueck, wenns nicht geklappt hat, sonst 0.
VERWEISE: add_acl_entry, query_acl_entry, query_access
GRUPPEN: master, acl
*/

string delete_acl_entry (string datei, string grouporwizorfile, int aclmask)
{
    mixed entry;
    string *pfad, ti_real_name;
    mixed long_way_to_the_ACL;
    int i, j, aclindex, pfadpos, temp, darfdas;

    ACL_SECURE("So geht das aber nicht.");
    ACL_DCHECK(datei,"Ungueltiger Pfad");

    if (objectp(this_interactive()))
        ti_real_name = ({string})this_interactive()->query_real_name();
    else
        ti_real_name = object_name(previous_object());
    // die Ueberpruefung, dass this interactive existiert,
    // ein Spieler ist usw. machte bereits ACL_SECURE.

    // Einen Test, ob grouporwizorfile eine Gruppe, ein Gott oder
    // eine Datei (save/restore-Object) ist, benoetigen wir nicht.
    // Wenn grouporwizorfile keine Gruppe, Gott oder Datei ist, so
    // existiert der ACL-Eintrag auch nicht oder aber, die Gruppe,
    // der Gott oder die Datei existieren nicht mehr, und in diesem
    // Fall ist es sehr gut, den ACL - Eintrag zu loeschen.
    // Das braucht man, um Eintraege nicht mehr existierender Gruppen
    // oder Goetter entfernen zu koennen.
    long_way_to_the_ACL = ({});

    if (grouporwizorfile[<2..] == ".c")
        grouporwizorfile = grouporwizorfile[0..<3];

    // ein .o am Ende abschneiden:
    if ((aclmask & ACL_SAVE) || (aclmask & ACL_RESTORE))
        if (datei[<2..] == ".o")
            datei = datei[0..<3];

    // ein / am Ende abschneiden:
    while (datei[<1] == '/')
        datei = datei[0..<2];

    pfad = explode (datei[1..],"/");
    // Wir starten im Acl - Root
    aclindex = ACL_ROOT;
    // Wir gehen pfad von links nach rechts durch
    pfadpos = 0;
    darfdas = adminp (this_interactive()) || geteuid(previous_object())==ROOT_UID;
    do {
        // Erstmal den Knoten, der zu pfad[pfadpos] gehoert, suchen
	for (i = sizeof (ACL[aclindex])-1;
            (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]);
            i--);
	if ((i < 0) && (pfadpos == sizeof (pfad)-1)) {
	    if ((aclmask & ACL_SAVE) || (aclmask & ACL_RESTORE))
		for (i = sizeof (ACL[aclindex])-1;
		    (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]+".o");
		    i--);
	    else 
		for (i = sizeof (ACL[aclindex])-1;
		    (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]+".c");
		    i--);
	}

        if (i < 0)
            // Knoten nicht gefunden
            return "Es existiert kein ACL Eintrag fuer "+datei+".";
        if (!darfdas && pointerp(ACL[aclindex][i][ACL_RIGHTS_LIST])) {
            // nachschauen, ob der Gott als ACL-Admin eingetragen ist.
            // natuerlich nur nachschauen, solange !darfdas.
            entry = ACL[aclindex][i][ACL_RIGHTS_LIST];
            for (j = 0;
                 j < sizeof (entry);
                 j++)
                if (entry[j][ACL_RIGHTS_WHICH] & ACL_ADMIN)
                    if ((entry[j][ACL_RIGHTS_WHO] == ti_real_name)
                     || GROUP_MASTER->is_group_member(
                        ti_real_name,
                        entry[j][ACL_RIGHTS_WHO]))
                        darfdas = 1;
        }
        if (pfadpos < sizeof(pfad)-1) {
            // wir sind noch nicht am Pfadende angelangt, wechseln in das
            // Unterverzeichnis.
            // Erstmal schauen, ob das Unterverzeichnis ueberhaupt einen eigenen
            // Knoten besitzt (muss es nicht):
            if (sizeof(ACL[aclindex][i]) < 3)
                // Das Verzeichnis besitzt keinen eigenen Knoten.
                return "Es existiert kein ACL Eintrag fuer "+datei+".";
            long_way_to_the_ACL += ({aclindex,i});
            aclindex = ACL[aclindex][i][ACL_NODE];
        }
        pfadpos++;
    } while (pfadpos < sizeof (pfad));
    if (!darfdas) return "Du bist nicht als ACL Admin hierfuer eingetragen.";
    // Der Knoten, in welchem wir die ACLs loeschen muessen, ist
    // jetzt gefunden, es ist ACL [aclindex][i][ACL_RIGHTS_LIST].
    // Moeglicherweise ist dieser Knoten noch ganz leer, erstmal gucken:
    if (!pointerp(entry = ACL[aclindex][i][ACL_RIGHTS_LIST]))
        return "Es existiert kein ACL Eintrag fuer "+datei+".";
    for (j = 0;
        (j < sizeof (entry))
         && (entry[j][ACL_RIGHTS_WHO] != grouporwizorfile); 
         j++) ;
    if (j == sizeof(entry))
        // Kein Eintrag da.
        return "Es existiert kein ACL Eintrag fuer "+datei+".";
    entry[j][ACL_RIGHTS_WHICH] = (entry[j][ACL_RIGHTS_WHICH] |= aclmask)
                                 - aclmask;
    // so, jetzt wirds anstrengend, jetzt besteht naemlich eventuell
    // die Chance, den ACL - Baum zu verkleinern
    if (ACL[aclindex][i][ACL_RIGHTS_LIST][j][ACL_RIGHTS_WHICH] != 0) {
       SAVE_ACLS;
       return ACL_SUCCESS;
    }
    // in der Tat, wir koennen einen Eintrag rauswerfen.
    ACL[aclindex][i][ACL_RIGHTS_LIST] =
        ACL[aclindex][i][ACL_RIGHTS_LIST][0..j-1] +
        ACL[aclindex][i][ACL_RIGHTS_LIST][j+1..];
    // So, das folgende machen wir jetzt solange in Richtung Wurzel des Baumes,
    // bis es nicht mehr geht...
    do {
        // Ist vielleicht der ganze Knoten schon leer?
        if (pointerp(ACL[aclindex][i][ACL_RIGHTS_LIST]) &&
            sizeof(ACL[aclindex][i][ACL_RIGHTS_LIST])) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        // Weg mit dem Knoten...
	ACL[aclindex][i][ACL_RIGHTS_LIST] = 0;
        // Wenn wir an dem Knoten ein Blatt haengen haben, kann er nicht weg,
        // obwohl die ACL_RIGHTS_LISTE leer ist
        if ((sizeof(ACL[aclindex][i]) == 3) && (ACL[aclindex][i][ACL_NODE] != 0)) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        // ganze Knoten ist leer, wegwerfen...
        ACL[aclindex] = ACL[aclindex][0..i-1] + ACL[aclindex][i+1..];
        // Mal gucken, vielleicht koennen wir ja sogar das ganze Blatt wegwerfen?
        // Aber nur, wenns nicht der erste ist.
        if (aclindex == ACL_ROOT) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        if (sizeof(ACL[aclindex]) != 0) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        // Wahnsinn, das ganze Blatt kann weg...
        m_delete (ACL,aclindex);
        // Jetzt muss natuerlich der Verweis auf dieses Blatt auch noch weg.
        if (sizeof (long_way_to_the_ACL) == 0) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        aclindex = long_way_to_the_ACL[<2];
        i = long_way_to_the_ACL[<1];
        long_way_to_the_ACL = long_way_to_the_ACL[0..<3];
        // den Knoten (ACL_NODE) "hinten" abschnippeln
        ACL[aclindex][i] = ACL[aclindex][i][ACL_PATH..ACL_RIGHTS_LIST];
        // Nachdem der Verweis auf das Blatt draussen ist, bleibt nur noch die
        // ACL_RIGHTS_LISTE uebrig. Wenn die auch leer, weg damit...
        //
        // Und genau an dieser Stelle waren wir zu Beginn der Schleife bereits,
        // nur "damals" ein Blatt hoeher... daher: schleifen...
    } while (1);
    // die Schleife wird irgendwann innen drin durch return ACL_SUCCESS verlassen.
}

/*
FUNKTION: delete_acl_dir
DEKLARATION: string delete_acl_dir(string datei)
BESCHREIBUNG:
Entfernt alle ACLs in diesem Verzeichnis und seinen Unterverzeichnissen
Gibt eine Fehlermeldung zurueck, wenns nicht geklappt hat, sonst 0.
VERWEISE: delete_acl_entry, add_acl_entry, query_acl_entry, query_access
GRUPPEN: master, acl
*/

string delete_acl_dir(string datei)
{
    mixed entry;
    string *pfad, ti_real_name;
    mixed long_way_to_the_ACL, stack;
    int i, j, aclindex, pfadpos, temp, darfdas;

    ACL_SECURE("So geht das aber nicht.");
    ACL_DCHECK(datei,"Ungueltiger Pfad");

    ti_real_name = ({string})this_interactive()->query_real_name();
    // die Ueberpruefung, dass this interactive existiert,
    // ein Spieler ist usw. machte bereits ACL_SECURE.

    long_way_to_the_ACL = ({});

    // ein / am Ende abschneiden:
    while (datei[<1] == '/')
        datei = datei[0..<2];

    pfad = explode (datei[1..],"/");
    // Wir starten im Acl - Root
    aclindex = ACL_ROOT;
    // Wir gehen pfad von links nach rechts durch
    pfadpos = 0;
    darfdas = adminp (this_interactive());
    do {
        // Erstmal den Knoten, der zu pfad[pfadpos] gehoert, suchen
	for (i = sizeof (ACL[aclindex])-1;
            (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]);
            i--);
        if (i < 0)
            // Knoten nicht gefunden
            return "Es existiert kein ACL Eintrag fuer "+datei+".";
        if (!darfdas && pointerp(ACL[aclindex][i][ACL_RIGHTS_LIST])) {
            // nachschauen, ob der Gott als ACL-Admin eingetragen ist.
            // natuerlich nur nachschauen, solange !darfdas.
            entry = ACL[aclindex][i][ACL_RIGHTS_LIST];
            for (j = 0;
                 j < sizeof (entry);
                 j++)
                if (entry[j][ACL_RIGHTS_WHICH] & ACL_ADMIN)
                    if ((entry[j][ACL_RIGHTS_WHO] == ti_real_name)
                     || GROUP_MASTER->is_group_member(
                        ti_real_name,
                        entry[j][ACL_RIGHTS_WHO]))
                        darfdas = 1;
        }
        if (pfadpos < sizeof(pfad)-1) {
            // wir sind noch nicht am Pfadende angelangt, wechseln in das
            // Unterverzeichnis.
            // Erstmal schauen, ob das Unterverzeichnis ueberhaupt einen eigenen
            // Knoten besitzt (muss es nicht):
            if (sizeof(ACL[aclindex][i]) < 3)
                // Das Verzeichnis besitzt keinen eigenen Knoten.
                return "Es existiert kein ACL Eintrag fuer "+datei+".";
            long_way_to_the_ACL += ({aclindex,i});
            aclindex = ACL[aclindex][i][ACL_NODE];
        }
        pfadpos++;
    } while (pfadpos < sizeof (pfad));
    if (!darfdas) return "Du bist nicht als ACL Admin hierfuer eingetragen.";
    // Der Knoten, in welchem wir die ACLs loeschen muessen, ist
    // jetzt gefunden, es ist ACL [aclindex][i][ACL_RIGHTS_LIST].

    // So nun den Eintrag rauswerfen.
    ACL[aclindex][i][ACL_RIGHTS_LIST] = 0;
    //Rekursiv alle Eintraege loeschen.
    if(sizeof(ACL[aclindex][i])>=3)
    {
        stack = ({ACL[aclindex][i][ACL_NODE]});
        while(sizeof(stack))
        {
            temp = stack[0];
            for(j=sizeof(ACL[temp])-1;j>=0;j--)
                if(sizeof(ACL[temp][j])>=3)
                    stack += ({ACL[temp][j][ACL_NODE]});
            m_delete (ACL, temp);
	    // erstes Element loeschen.
	    stack[0..0] = ({});
        }
        ACL[aclindex][i]=ACL[aclindex][i][0..ACL_NODE-1];
    }
    // So, das folgende machen wir jetzt solange in Richtung Wurzel des Baumes,
    // bis es nicht mehr geht...
    do {
        // Ist vielleicht der ganze Knoten schon leer?
        if (pointerp(ACL[aclindex][i][ACL_RIGHTS_LIST]) &&
            sizeof(ACL[aclindex][i][ACL_RIGHTS_LIST])) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        // Weg mit dem Knoten...
	ACL[aclindex][i][ACL_RIGHTS_LIST] = 0;
        // Wenn wir an dem Knoten ein Blatt haengen haben, kann er nicht weg,
        // obwohl die ACL_RIGHTS_LISTE leer ist
        if ((sizeof(ACL[aclindex][i]) == 3) && (ACL[aclindex][i][ACL_NODE] != 0)) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        // ganze Knoten ist leer, wegwerfen...
        ACL[aclindex] = ACL[aclindex][0..i-1] + ACL[aclindex][i+1..];
        // Mal gucken, vielleicht koennen wir ja sogar das ganze Blatt wegwerfen?
        // Aber nur, wenns nicht der erste ist.
        if (aclindex == ACL_ROOT) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        if (sizeof(ACL[aclindex]) != 0) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        // Wahnsinn, das ganze Blatt kann weg...
        m_delete (ACL,aclindex);
        // Jetzt muss natuerlich der Verweis auf dieses Blatt auch noch weg.
        if (sizeof (long_way_to_the_ACL) == 0) {
            SAVE_ACLS;
            return ACL_SUCCESS;
        }
        aclindex = long_way_to_the_ACL[<2];
        i = long_way_to_the_ACL[<1];
        long_way_to_the_ACL = long_way_to_the_ACL[0..<3];
        // den Knoten (ACL_NODE) "hinten" abschnippeln
        ACL[aclindex][i] = ACL[aclindex][i][ACL_PATH..ACL_RIGHTS_LIST];
        // Nachdem der Verweis auf das Blatt draussen ist, bleibt nur noch die
        // ACL_RIGHTS_LISTE uebrig. Wenn die auch leer, weg damit...
        //
        // Und genau an dieser Stelle waren wir zu Beginn der Schleife bereits,
        // nur "damals" ein Blatt hoeher... daher: schleifen...
    } while (1);
    // die Schleife wird irgendwann innen drin durch return ACL_SUCCESS verlassen.
}


/*
FUNKTION: dump_acl_entries
DEKLARATION: string dump_acl_entries(string datei, int mode)
BESCHREIBUNG:
Liefert fuer die Datei / das Verzeichnis die ACL - Eintraege
in Form eines Strings.
Ist mode = 1, so werden auch die Unterverzeichnisse mit
aufgelistet, fuer die ACL Eintraege existieren. Ist mode = 2, so
werden alle Eintraege auf dem Weg zu dieser Datei / diesem Verzeichnis
aufgelistet.
VERWEISE: add_acl_entry, delete_acl_entry, query_access
GRUPPEN: master, acl
*/

private string my_wrap_say(string str1, string str2)
// der Master darf auf keine simul efuns zugreifen, da er auch ohne diese
// ladbar sein muss.
// Das wrap_say ist aber so einfach, dass es sich nicht lohnt, sich zu
// verrenken, um doch einen simul efun Aufruf hinzubekommen.
{
    return sprintf("%s%=-*s\n", str1[0..7], 67, str1[8..]+" "+str2);
}


string ACLmask2str (int mask)
{
    string ergebnis;
    ergebnis = "";
    if (mask & ACL_WRITE) ergebnis += "write ";
    if (mask & ACL_REMOVE) ergebnis += "remove ";
    if (mask & ACL_CREATE) ergebnis += "create ";
    if (mask & ACL_MKDIR) ergebnis += "mkdir ";
    if (mask & ACL_RMDIR) ergebnis += "rmdir ";
    if (mask & ACL_SAVE) ergebnis += "save ";
    if (mask & ACL_RESTORE) ergebnis += "restore ";
    if (mask & ACL_READ) ergebnis += "read ";
    if (mask & ACL_ADMIN) ergebnis += "admin ";
    if (mask & ACL_DEBUG) ergebnis += "debug ";
    return ergebnis;
}

string ACLmask2cmd (int mask)
{
    string ergebnis;
    ergebnis = "";
    if (mask & ACL_CREATE) ergebnis += "+c";
    if (mask & ACL_WRITE) ergebnis += "+w";
    if (mask & ACL_REMOVE) ergebnis += "+d";
    if (mask & ACL_MKDIR) ergebnis += "+C";
    if (mask & ACL_RMDIR) ergebnis += "+D";
    if (mask & ACL_SAVE) ergebnis += "+s";
    if (mask & ACL_RESTORE) ergebnis += "+r";
    if (mask & ACL_ADMIN) ergebnis += "+a";
    if (mask & ACL_DEBUG) ergebnis += "+b";
    return ergebnis;
}

private string dump_acl_node(string datei, int node)
{
    string ergebnis;
    mixed *entry;
    int j;
    ergebnis = "";
    foreach(mixed dir:sort_array(ACL[node],(:$1[ACL_PATH]>$2[ACL_PATH]:))) {
        entry = dir[ACL_RIGHTS_LIST];
        if (pointerp(entry)) {
            // Falls entry kein Array ist, so bedeutet dies, dass
            // keine direkten Eintraege vorhanden sind, sondern nur
            // fuer die Unterverzeichnisse dieses Knotens,
            // die bearbeiten wir dann im naechsten Schritt.
            ergebnis += "\nACLs fuer: "+datei+"/"+dir[ACL_PATH]+"\n";
            for (j = 0; j < sizeof (entry); j ++)
                ergebnis += my_wrap_say (entry [j] [ACL_RIGHTS_WHO]+":",
                            ACLmask2str(entry [j] [ACL_RIGHTS_WHICH]));
            }
        if (sizeof (dir)>2)
            ergebnis += dump_acl_node (datei+"/"+dir[ACL_PATH],
                dir[ACL_NODE]);
    }
    return ergebnis;
}


string dump_acl_entries(string datei, int mode)
{
    mixed entry;
    string *pfad, ergebnis;
    int i, j, aclindex, pfadpos;

    ACL_SECURE("So geht das aber nicht.");
    ACL_DCHECK(datei,"Das is keine existierende Datei.\n");

    // ein / am Ende abschneiden:
    while (datei[<1] == '/')
        datei = datei[0..<2];

    pfad = explode (datei[1..], "/");
    // Wir starten im Acl - Root
    aclindex = ACL_ROOT;
    // Wir gehen pfad von links nach rechts durch
    pfadpos = 0;
    ergebnis = "";
    do {
        // Erstmal den Knoten, der zu pfad[pfadpos] gehoert, suchen
	for (i = sizeof (ACL[aclindex])-1;
            (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]);
            i--);
        if (i < 0)
            // Knoten nicht gefunden
            return (ergebnis=="")?"Keine ACL - Eintraege.":ergebnis[0..<2];
        if (pfadpos < sizeof(pfad)-1) {
	    if (mode == 2) // Alle Rechte auf dem Weg anzeigen
	    {
	        entry = ACL[aclindex][i][ACL_RIGHTS_LIST];
		if (pointerp(entry))
		{
		    for (j = 0, ergebnis += "ACLs fuer: /" +
		        implode(pfad[0..pfadpos],"/")+"\n";
		    j < sizeof (entry);
		    j ++)
		        ergebnis += my_wrap_say (entry[j][ACL_RIGHTS_WHO]+":",
                                    ACLmask2str(entry[j][ACL_RIGHTS_WHICH]));
		    ergebnis += "\n";
		}
	    }
            // wir sind noch nicht am Pfadende angelangt, wechseln in das
            // Unterverzeichnis.
            // Erstmal schauen, ob das Unterverzeichnis ueberhaupt einen eigenen
            // Knoten besitzt (muss es nicht):
            if (sizeof(ACL[aclindex][i]) < 3)
                // Das Verzeichnis besitzt keinen eigenen Knoten.
                return (ergebnis=="")?"Keine ACL - Eintraege vorhanden."
		                     :ergebnis;
            aclindex = ACL[aclindex][i][ACL_NODE];
        }
        pfadpos++;
    } while (pfadpos < sizeof (pfad));
    // Der Knoten, in welchem wir die ACLs suchen, ist
    // jetzt gefunden, es ist ACL [aclindex][i][ACL_RIGHTS_LIST].
    // Moeglicherweise ist dieser Knoten noch ganz leer, erstmal gucken:
    entry = ACL[aclindex][i][ACL_RIGHTS_LIST];
    if (!pointerp(entry))
        ergebnis = (ergebnis=="")?"Keine ACL - Eintraege fuer "+datei+".\n"
	                         :ergebnis;
    else for (j = 0, ergebnis += "ACLs fuer: "+datei+"\n";
         j < sizeof (entry);
         j ++)
        ergebnis += my_wrap_say (entry [j] [ACL_RIGHTS_WHO]+":",
                    ACLmask2str(entry [j] [ACL_RIGHTS_WHICH]));
    if (mode == 1 && (sizeof (ACL[aclindex][i]) > 2))
        ergebnis += dump_acl_node (datei,ACL[aclindex][i][ACL_NODE]);
    return ergebnis;
}

private mixed* query_node_for_a_group(string datei, string gruppe, int node)
{
    mixed *ergebnis;
    mixed *entry;
    int j;

    ergebnis = ({});

    foreach(mixed dir:sort_array(ACL[node],(:$1[ACL_PATH]>$2[ACL_PATH]:)))
    {
        entry = dir[ACL_RIGHTS_LIST];
        if (pointerp(entry)) {
            // Falls entry kein Array ist, so bedeutet dies, dass
            // keine direkten Eintraege vorhanden sind, sondern nur
            // fuer die Unterverzeichnisse dieses Knotens,
            // die bearbeiten wir dann im naechsten Schritt.
	    
            for (j = 0; j < sizeof (entry); j ++)
		if (entry[j][ACL_RIGHTS_WHO] == gruppe)
		    ergebnis += ({ ({datei+"/"+dir[ACL_PATH], entry[j][ACL_RIGHTS_WHICH] }) });
    	}
        if (sizeof (dir)>2)
            ergebnis += query_node_for_a_group (datei+"/"+dir[ACL_PATH],
		gruppe, dir[ACL_NODE]);
    }
    return ergebnis;
}

mixed *query_entries_for_a_group(string datei, string gruppe)
{
    string *pfad;
    int i, j, aclindex, pfadpos;

    ACL_SECURE(0);
    ACL_DCHECK(datei,0);

    // ein / am Ende abschneiden:
    while (sizeof(datei) && datei[<1] == '/')
        datei = datei[0..<2];

    pfad = (sizeof(datei)>1)?explode (datei[1..], "/"):({});
    // Wir starten im Acl - Root
    aclindex = ACL_ROOT;
    // Wir gehen pfad von links nach rechts durch
    pfadpos = 0;
    while (pfadpos < sizeof (pfad)) {
        // Erstmal den Knoten, der zu pfad[pfadpos] gehoert, suchen
	for (i = sizeof (ACL[aclindex])-1;
            (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]);
            i--);
        if (i < 0)
            // Knoten nicht gefunden
            return ({});
        if (pfadpos < sizeof(pfad)-1) {
            // wir sind noch nicht am Pfadende angelangt, wechseln in das
            // Unterverzeichnis.
            // Erstmal schauen, ob das Unterverzeichnis ueberhaupt einen eigenen
            // Knoten besitzt (muss es nicht):
            if (sizeof(ACL[aclindex][i]) < 3)
                // Das Verzeichnis besitzt keinen eigenen Knoten.
                return ({});
            aclindex = ACL[aclindex][i][ACL_NODE];
        }
        pfadpos++;
    } 
    // Der Knoten, in welchem wir die ACLs suchen, ist
    // jetzt gefunden, es ist ACL [aclindex][i][ACL_RIGHTS_LIST].
    // Moeglicherweise ist dieser Knoten noch ganz leer, erstmal gucken:
    return query_node_for_a_group(datei, gruppe, aclindex);
}

mixed dump_entries_for_a_group(string datei, string gruppe)
{
    string *pfad;
    mixed *nodes;
    int i, j, aclindex, pfadpos;
    string ret;

    ACL_SECURE("So geht das aber nicht.");
    ACL_DCHECK(datei,"Das is keine existierende Datei.\n");

    // ein / am Ende abschneiden:
    while (sizeof(datei) && datei[<1] == '/')
        datei = datei[0..<2];

    pfad = (sizeof(datei)>1)?explode (datei[1..], "/"):({});
    // Wir starten im Acl - Root
    aclindex = ACL_ROOT;
    // Wir gehen pfad von links nach rechts durch
    pfadpos = 0;
    while (pfadpos < sizeof (pfad)) {
        // Erstmal den Knoten, der zu pfad[pfadpos] gehoert, suchen
	for (i = sizeof (ACL[aclindex])-1;
            (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]);
            i--);
        if (i < 0)
            // Knoten nicht gefunden
            return "Keine ACL - Eintraege.";
        if (pfadpos < sizeof(pfad)-1) {
            // wir sind noch nicht am Pfadende angelangt, wechseln in das
            // Unterverzeichnis.
            // Erstmal schauen, ob das Unterverzeichnis ueberhaupt einen eigenen
            // Knoten besitzt (muss es nicht):
            if (sizeof(ACL[aclindex][i]) < 3)
                // Das Verzeichnis besitzt keinen eigenen Knoten.
                return "Keine ACL - Eintraege vorhanden.";
            aclindex = ACL[aclindex][i][ACL_NODE];
        }
        pfadpos++;
    } 
    // Der Knoten, in welchem wir die ACLs suchen, ist
    // jetzt gefunden, es ist ACL [aclindex][i][ACL_RIGHTS_LIST].
    // Moeglicherweise ist dieser Knoten noch ganz leer, erstmal gucken:
    nodes = query_node_for_a_group(datei, gruppe, aclindex);
    if(nodes)
    {
	ret = "";
	foreach(mixed node: nodes)
	    ret += my_wrap_say(node[0], ACLmask2str(node[1]));
    }
    
    if(!sizeof(ret))
	return "Keine ACL - Eintraege fuer die Gruppe '"+gruppe+"' vorhanden.";
    return ret;
}


int group_has_entries(string gruppe)
{
    return sizeof(query_node_for_a_group("", gruppe, 0))>0;
}

/*
FUNKTION: query_access
DEKLARATION: int query_access(string *pfad, string wizorfile, int aclmask)
BESCHREIBUNG:
Liefert 1, falls der Wizzard bzw die Datei fuer die Datei bzw das Verzeichnis
pfad die durch die aclmask spezifizierten Rechte besitzt. Diese ergeben sich
aus den vollstaendigen Rechten des Wizzards bzw. der Datei entlang des Pfades.
Sind die gewuenschten Rechte nicht komplett vorhanden, so wird 0
zurueckgeliefert, andernfalls 1.
VERWEISE: add_acl_entry, delete_acl_entry, query_acl_entry
GRUPPEN: master, acl
*/

int query_access(string *pfad, string wizorfile, int aclmask)
{
#ifdef NO_ACLS
    return 1;
#else
    mixed entry;
    int i, j, aclindex, pfadpos, temp;

    if (!pfad || !sizeof(pfad) || !wizorfile || !aclmask) return 0;
    // Wir starten im Acl - Root
    aclindex = ACL_ROOT;
    // Wir gehen pfad von links nach rechts durch
    pfadpos = 0;
    do {
        // Uns langsam dem Pfad entlang zu dem Knoten vorkaempfen,
        // der zu pfad[pfadpos] gehoert, und entlang des Weges suchen.
	for (i = sizeof (ACL[aclindex])-1;
            (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]);
            i--)
            ;
        if (i < 0)
            // Knoten nicht gefunden
            return 0;
        if (pointerp(entry = ACL[aclindex][i][ACL_RIGHTS_LIST])) {
            for (j = 0;
                 j < sizeof (entry);
                 j ++)
                if ((entry[j][ACL_RIGHTS_WHO] == wizorfile)
                   || GROUP_MASTER->is_group_member(wizorfile,
                      entry[j][ACL_RIGHTS_WHO])) {
                   temp=entry[j][ACL_RIGHTS_WHICH];
                   aclmask = (aclmask | temp) - temp;
                   if (!aclmask) return 1;
                }
        }

        if (pfadpos < sizeof(pfad)-1) {
            // wir sind noch nicht am Pfadende angelangt, wechseln in das
            // Unterverzeichnis.
            // Erstmal schauen, ob das Unterverzeichnis ueberhaupt einen eigenen
            // Knoten besitzt (muss es nicht):
            if (sizeof(ACL[aclindex][i]) < 3)
                // Das Verzeichnis besitzt keinen eigenen Knoten.
                return 0;
            aclindex = ACL[aclindex][i][ACL_NODE];
        }
        pfadpos++;
    } while (pfadpos < sizeof (pfad));
    return 0;
#endif
}


/*
FUNKTION: query_acl_entry
DEKLARATION: int query_acl_entry(string pfad, string groupwizfile, int aclmask)
BESCHREIBUNG:
Testet fuer die Datei / das Verzeichnis pfad und die Gruppe oder den
Wizard oder die Datei groupwizfile, ob die in der aclmask uebergebenen Rechte
vorhanden sind. Wenn ja, liefert diese Funktion eine 1, wenn nein, eine 0.
Die Flags, aus denen die aclmask per Veroderung entsteht, sind in
/sys/acl.h definiert.
VERWEISE: add_acl_entry, delete_acl_entry, query_access
GRUPPEN: master, acl
*/

// HINWEIS: Die folgende Funktion wird vom Master selbst nicht verwendet,
// sie existiert nur als "Feature nach aussen hin".

int query_acl_entry(string datei, string grouporwizorfile, int aclmask)
{
    string *pfad;

    ACL_DCHECK(datei,ACL_ERROR);

    // ein / am Ende abschneiden:
    while (datei[<1] == '/')
        datei = datei[0..<2];

    pfad = explode (datei[1..],"/");

    // den Rest der Arbeit erledigt query_access:
    return query_access (pfad, grouporwizorfile, aclmask);
}

/*
FUNKTION: query_debugger_acl
DEKLARATION: string *query_debugger_acl (string *pfad)
BESCHREIBUNG:
Liefert alle Goetter und Gruppen, die fuer eine bestimmte Datei
Debugger sind. Das sind all die, die entlang des Dateipfades irgendwo
entweder ACL_WRITE oder ACL_DEBUG besitzen.
Es werden dabei nur existierende Gruppen und Goetter geliefert.
VERWEISE: add_acl_entry, delete_acl_entry, query_acl_entry
GRUPPEN: master, acl
*/

string *query_debugger_acl(string *pfad)
{
    mixed entry;
    string *erg, who;
    int i, j, aclindex, pfadpos, temp, aclmask;

    aclmask = ACL_DEBUG | ACL_WRITE;
    erg = ({});
    // Wir starten im Acl - Root
    aclindex = ACL_ROOT;
    // Wir gehen pfad von links nach rechts durch
    pfadpos = 0;
    do {
        // Uns langsam dem Pfad entlang zu dem Knoten vorkaempfen,
        // der zu pfad[pfadpos] gehoert, und entlang des Weges suchen.
	for (i = sizeof (ACL[aclindex])-1;
            (i >= 0) && (ACL[aclindex][i][ACL_PATH] != pfad[pfadpos]);
            i--)
            ;
        if ((i < 0) && (pfadpos == sizeof(pfad)-1)) {
            string temp2 = pfad[pfadpos]+".c";
	    for (i = sizeof (ACL[aclindex])-1;
                (i >= 0) && (ACL[aclindex][i][ACL_PATH] != temp2);
                i--)
                ;
        }
        if (i < 0)
            // Knoten nicht gefunden
            return erg;
        if (pointerp(entry = ACL[aclindex][i][ACL_RIGHTS_LIST])) {
            for (j = sizeof (entry); j --; )
                if (entry[j][ACL_RIGHTS_WHICH] & aclmask) {
                    who = entry[j][ACL_RIGHTS_WHO];

                    if ((member(erg,who)==-1) &&
                        (GOETTER_REGISTER->is_wiz(who) ||
                         GROUP_MASTER->group_exists(who)))
                        erg += ({who});
                }
        }

        if (pfadpos < sizeof(pfad)-1) {
            // wir sind noch nicht am Pfadende angelangt, wechseln in das
            // Unterverzeichnis.
            // Erstmal schauen, ob das Unterverzeichnis ueberhaupt einen eigenen
            // Knoten besitzt (muss es nicht):
            if (sizeof(ACL[aclindex][i]) < 3)
                // Das Verzeichnis besitzt keinen eigenen Knoten.
                return erg;
            aclindex = ACL[aclindex][i][ACL_NODE];
        }
        pfadpos++;
    } while (pfadpos < sizeof (pfad));
    return erg;
}

/*
mixed query_acl_tt(int nr)
{
    if (this_interactive() == this_player() && adminp(this_player()) &&
	    geteuid(previous_object()) == geteuid(this_player()))
	return ACL[nr];
}
*/

string query_acl_dump()
{
    return funcall(symbol_function("mixed2str"),ACL);
}

void rename_groups_in_entry (int key, mixed entry, mixed old, mixed new)
{
    int i,j;
    for (i=sizeof (entry); i--; )
        for (j=sizeof (entry[i][ACL_RIGHTS_LIST]); j--; )
            if (entry[i][ACL_RIGHTS_LIST][j][ACL_RIGHTS_WHO][0..sizeof(old)-1] == old)
                entry[i][ACL_RIGHTS_LIST][j][ACL_RIGHTS_WHO] = new +
                    entry[i][ACL_RIGHTS_LIST][j][ACL_RIGHTS_WHO][sizeof(old)..];
}

void rename_group (string old, string new)
{
    if (object_name(previous_object()) != "/apps/groups")
        return;
    walk_mapping (ACL,#'rename_groups_in_entry, old, new);
    SAVE_ACLS;
}

// (ACL_ADMIN|ACL_WRITE|ACL_CREATE|ACL_REMOVE|ACL_MKDIR|ACL_RMDIR|ACL_SAVE|ACL_RESTORE|ACL_DEBUG)
#define ACL_MASK 0x1ff
#define ACL_LPC_FILES (ACL_WRITE|ACL_CREATE|ACL_REMOVE)
#define ACL_SAVE_FILES (ACL_SAVE|ACL_RESTORE)

private void check_acl(mixed *stack, string *ret, mapping groupnames)
{
    if(!this_player())
	return;
    while(sizeof(stack) && get_eval_cost()>50000)
    {
	mixed acl = stack[0][1];
	string name = stack[0][0];
	string prefix;

	stack = stack[1..<1];
	if(sizeof(acl)<1 || !stringp(acl[ACL_PATH]))
	{
	    ret += ({"Unterverzeichniseintrag in '"+name+"' hat keinen Namen."});
	    name +="<Unbekannt>";
        }
	else
	    name += acl[ACL_PATH];
	
	prefix = "'"+name+"': ";
	
        if(sizeof(acl)<2)
	{
	    ret += ({prefix+"Eintrag ist zu klein."});
	    continue;
	}
	else if(sizeof(acl)>3)
	    ret += ({prefix+"Eintrag hat zuviele Arrayelemente."});
    
	if(acl[ACL_RIGHTS_LIST])
        {
	    if(!pointerp(acl[ACL_RIGHTS_LIST]))
		ret += ({prefix+"Rechteliste ist kein Array."});
	    else
		foreach(mixed right: acl[ACL_RIGHTS_LIST])
		{
		    string holder = right[ACL_RIGHTS_WHO];
		    int rights;
		    
		    if(!stringp(holder))
			ret += ({prefix+"Ungueltiger Rechteeintrag."});
		    else if(member(holder,'/')>=0)
		    {
			if(!funcall(symbol_function("valid_file_name"), holder))
			    ret += ({prefix+"Dateiname '"+holder+"' ist ungueltig."});
			else if(holder[<2..<1]==".c")
			    ret += ({prefix+"Objektname '"+holder+"' enthaelt Dateiendung."});
		    }
		    else if(lower_case(holder)==holder)
		    {
			if(!GOETTER_REGISTER->is_wiz(holder) &&
			    !GOETTER_REGISTER->is_wiz_on_vacation(holder))
			    ret += ({prefix+"Rechteinhaber '"+capitalize(holder)+"' ist kein Gott."});
		    }
		    else if(!member(groupnames, holder))
			ret += ({prefix+"Rechteinhaber '"+holder+"' ist keine Gruppe."});

		    rights = right[ACL_RIGHTS_WHICH];
		    if(!intp(rights))
			ret += ({prefix+"Rechteflag ist keine Zahl."});
		    else
		    {
			if(rights & ~ACL_MASK)
			    ret += ({prefix+"Unbekannte Rechte vergeben."});
		        if((rights & ACL_LPC_FILES) && file_size(name)==FSIZE_NOFILE && file_size(name+".c")>0)
			    ret += ({prefix+"ACLs ohne .c-Endung vergeben."});
			if((rights & ACL_SAVE_FILES) && name[<2..<1]==".o")
			    ret += ({prefix+"ACLs mit .o-Endung vergeben."});
		    }
		}
	}
    
	if(sizeof(acl)>ACL_NODE)
	{
	    if(file_size(name)!=FSIZE_DIR)
		ret += ({"'"+name+"' ist kein Verzeichnis."});

	    if(!member(ACL, acl[ACL_NODE]))
		ret += ({prefix+"ACL-Node existiert nicht."});
	    else if(!sizeof(ACL[acl[ACL_NODE]]))
		ret += ({prefix+"Leerer Eintrag."});
	    else
	    {
		name += "/";
		stack = map(ACL[acl[ACL_NODE]], (: ({$2, $1}) :), name) + stack;
	    }
	}
	else if(!sizeof(acl[ACL_RIGHTS_LIST]))
	    ret += ({prefix+"ACL-Eintrag ist unnoetig."});
    }
    if(sizeof(stack))
	call_out(#'check_acl, 2, stack, ret, groupnames);
    else
    {
	string *str = ({});
	if(!sizeof(ret))
	    efun::write("Alles okay.\n");
	foreach(string err: sort_array(ret,#'>))
	    str += explode(sprintf("%s%-=70s\n",err[0..7],err[8..<1]),"\n")[0..<2];
	this_player()->more(str);
    }
}

void acl_consistency_check()
{
    mapping groupnames = ({mapping})GROUP_MASTER->get_group_list();
    check_acl(map(ACL[ACL_ROOT],(:({"/", $1 }):)), ({}), groupnames);
}
