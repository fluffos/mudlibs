// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /i/zauberstab/zacl.inc
// Description: Gruppen- und ACL-Handling des Zauberstabs
// Author:      Sissi (12.98)
// Modified:    Horni (16.05.2000) Bugfix fuer zacl /
//
//
// $Log: zacl.inc,v $
// Revision 1.12  2007/08/30 20:30:20  gnomi
// Typo.
//
// Revision 1.11  2003/08/16 22:07:19  gnomi
// static add_actions entfernt.
//
// Revision 1.10  2002/08/07 23:31:44  gnomi
// zacl ? <GruppenOderGottName> sucht nach ACls fuer eine bestimmte Gruppe
// odert Gott.
//
// Revision 1.9  2001/04/17 20:12:35  gnomi
// add_path wird verwendet, wenn einem Objekt Rechte gegeben werden.
// zacl <wo> -* <wer>
// zacl <verz> remove
//
// Revision 1.8  2001/03/24 23:15:02  gnomi
// Hilfetexte ueber HELP_NO_STR ausgeben.
//
// Revision 1.7  2001/03/24 03:27:26  gnomi
// zacl: Fehler ausgeben, wenn keine Rechteaenderungen stattfinden.
//
// Revision 1.6  2001/03/24 00:40:05  gnomi
// zacl: Zusaetzliche Leerzeichen nicht beachten.
//
// Revision 1.5  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strong_types

int z_gruppe(string str)
{
    string *wunsch;
    SECURE;
    HELP_NO_STR("zgruppe");
    wunsch = explode (str," ");
    if (sizeof (wunsch) == 1)
        if (str == "!")
            W(GROUP_MASTER->query_maingroup_info());
        else
            W(GROUP_MASTER->query_group_info(wunsch[0]));
    else if (sizeof (wunsch) == 2) {
        if (wunsch[1] == "?")
            W(GROUP_MASTER->query_group_info(wunsch[0]));
	else if (wunsch[1] == "??")
            W(GROUP_MASTER->query_full_group_info(wunsch[0]));
        else if (wunsch[0] == "?") {
            if (GOETTER_REGISTER->is_wiz(wunsch[1]))
                W (GROUP_MASTER->query_immediate_memberships_info_of(
                    lower_case(wunsch[1])));
            else // ist wohl eine Gruppe
                W (GROUP_MASTER->query_immediate_memberships_info_of(wunsch[1]));
        }
        else if (wunsch[0] == "??") {
//            WLN ("Funktion momentan deaktiviert, Gruss, Sissi.");
            if (GOETTER_REGISTER->is_wiz(wunsch[1]))
                wunsch[1] = lower_case(wunsch[1]);
            W (GROUP_MASTER->query_wiz_infos (wunsch[1]));
        }
        else if (wunsch[1] == "+")
            WLN(GROUP_MASTER->add_group(wunsch[0]));
        else if (wunsch[1] == "-")
            WLN(GROUP_MASTER->delete_group(wunsch[0]));
        else WLN("Unbekannter Wunsch: "+wunsch[1]);
    }
    else if (sizeof (wunsch) == 3) {
        if (wunsch[1] == "+")
            WLN(GROUP_MASTER->add_group_member(wunsch[2],wunsch[0]));
        else if (wunsch[1] == "-")
            WLN(GROUP_MASTER->delete_group_member(wunsch[2],wunsch[0]));
        else if (wunsch[1] == "+A")
            WLN(GROUP_MASTER->add_group_admin(wunsch[2],wunsch[0]));
        else if (wunsch[1] == "-A")
            WLN(GROUP_MASTER->delete_group_admin(wunsch[2],wunsch[0]));
        else if (wunsch[1] == "R")
            WLN(GROUP_MASTER->rename_group (wunsch[0],wunsch[2]));
        else WLN("Unbekannter Wunsch: "+wunsch[1]);
    }
    else WLN ("Zu viele Parameter.");
    PRINT;
    return 1;
}

int z_acl(string str)
{
    string *wunsch, ergebnis;
    int aclmaskminus, aclmaskplus, i;
    object ob;
    SECURE;
    HELP_NO_STR("zacl");
    wunsch = explode (str," ")-({""});
    if ((sizeof (wunsch) == 1) ||
            ((sizeof (wunsch) == 2) && member((["?","??"]),wunsch[1]))) {
        if(wunsch[0]=="/")
          FAIL("Fuer das Stammverzeichnis gibt es keine ACLs\n");
        ergebnis=OWN->add_path(wunsch[0]);
	if(sizeof(wunsch)==2 && wunsch[1]=="?")
	{
	    ob=search_object(wunsch[0]);
	    if(ob)
	        ergebnis=object_name(ob)+".c";
	}
        WLN(MASTER_OB->dump_acl_entries (ergebnis,
	    (sizeof(wunsch)==1)?0:3-strlen(wunsch[1])));
	PRINT;
    }
    else if(sizeof(wunsch)==2 && wunsch[0]=="?") {
        ergebnis = MASTER_OB->dump_entries_for_a_group("/",wunsch[1]);
	if(ergebnis[<1]=='\n')
	{
	    W(sprintf("ACLs fuer '%s'\n", wunsch[1]));
	    W(ergebnis);
	}
	else
	{
	    WLN(ergebnis);
	    if(wunsch[1][0]!='/' && !GROUP_MASTER->group_exists(wunsch[1]) &&
		!GOETTER_REGISTER->is_wiz(wunsch[1]))
		    W(sprintf("('%s' ist weder Gott noch Gruppe.)\n",wunsch[1]));
	}
	PRINT;
    }
    else if(sizeof(wunsch)==2 && lower_case(wunsch[1])=="remove") {
        ergebnis = MASTER_OB->delete_acl_dir (OWN->add_path(wunsch[0]));
        if (!ergebnis)
            WLN ("ACLs aendern hat geklappt.");
        else
            WLN (ergebnis);
        PRINT;
    }
    else {
	wunsch[1..<2]=({implode(wunsch[1..<2],"")});
        aclmaskplus = 0; aclmaskminus = 0;
        for (i=0; i < strlen (wunsch[1])-1; i+=2) {
                 if (wunsch[1][i..i+1] == "+c") aclmaskplus |= ACL_CREATE;
            else if (wunsch[1][i..i+1] == "-c") aclmaskminus |= ACL_CREATE;
            else if (wunsch[1][i..i+1] == "+w") aclmaskplus |= ACL_WRITE;
            else if (wunsch[1][i..i+1] == "-w") aclmaskminus |= ACL_WRITE;
            else if (wunsch[1][i..i+1] == "+d") aclmaskplus |= ACL_REMOVE;
            else if (wunsch[1][i..i+1] == "-d") aclmaskminus |= ACL_REMOVE;
            else if (wunsch[1][i..i+1] == "+C") aclmaskplus |= ACL_MKDIR;
            else if (wunsch[1][i..i+1] == "-C") aclmaskminus |= ACL_MKDIR;
            else if (wunsch[1][i..i+1] == "+D") aclmaskplus |= ACL_RMDIR;
            else if (wunsch[1][i..i+1] == "-D") aclmaskminus |= ACL_RMDIR;
            else if (wunsch[1][i..i+1] == "+s") aclmaskplus |= ACL_SAVE;
            else if (wunsch[1][i..i+1] == "-s") aclmaskminus |= ACL_SAVE;
            else if (wunsch[1][i..i+1] == "+r") aclmaskplus |= ACL_RESTORE;
            else if (wunsch[1][i..i+1] == "-r") aclmaskminus |= ACL_RESTORE;
//          else if (wunsch[1][i..i+1] == "+R") aclmaskplus |= ACL_READ;
//          else if (wunsch[1][i..i+1] == "-R") aclmaskminus |= ACL_READ;
            else if (wunsch[1][i..i+1] == "+a") aclmaskplus |= ACL_ADMIN;
            else if (wunsch[1][i..i+1] == "-a") aclmaskminus |= ACL_ADMIN;
            else if (wunsch[1][i..i+1] == "+b") aclmaskplus |= ACL_DEBUG;
            else if (wunsch[1][i..i+1] == "-b") aclmaskminus |= ACL_DEBUG;
            else if (wunsch[1][i..i+1] == "+*")
                aclmaskplus |= ACL_CREATE | ACL_WRITE | ACL_REMOVE | ACL_MKDIR
                            | ACL_RMDIR | ACL_SAVE | ACL_RESTORE | ACL_ADMIN
                            | ACL_DEBUG;
            else if (wunsch[1][i..i+1] == "-*")
                aclmaskminus |= ACL_CREATE | ACL_WRITE | ACL_REMOVE | ACL_MKDIR
                             | ACL_RMDIR | ACL_SAVE | ACL_RESTORE | ACL_ADMIN
                             | ACL_DEBUG;
            else FAIL ("Oh, leider weiss ich nicht, was ich mit '"
                +wunsch[1][i..]+"' anfangen soll.\n");
        }
        if (!(aclmaskplus|aclmaskminus))
            FAIL ("Ohje, Dein Zauberstab versteht nicht, was Du meinst.\n"
                  "Hilfe zum zacl - Befehl gibts mit \"zacl ?\".\n");
        if (aclmaskplus & aclmaskminus)
            FAIL ("Du musst Dich schon entscheiden, ob Du ein Recht\n"
                  "wegnehmen oder gewaehren willst.\n");
        if(member(wunsch[2],'/')>=0)
            wunsch[2]=OWN->add_path(wunsch[2]);
        if (aclmaskplus)
            ergebnis = MASTER_OB->add_acl_entry (OWN->add_path(wunsch[0]),wunsch[2],
                aclmaskplus);
        if (!ergebnis && aclmaskminus)
            ergebnis = MASTER_OB->delete_acl_entry (OWN->add_path(wunsch[0]),wunsch[2],
                aclmaskminus);
        if (!ergebnis)
            WLN ("ACLs aendern hat geklappt.");
        else
            WLN (ergebnis);
        PRINT;
    }
    return 1;
}
