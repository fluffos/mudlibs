// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/clone_object.inc
// Description:	Patch fuer UDL
// Author:	Jesaia (12.06.2000)
// Modified by:	
// $Log: clone_object.inc,v $
// Revision 1.17  2015/08/26 21:40:30  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.16  2007/08/19 15:29:58  menaures
// Zerstoerte Objekte koennen doch als 0 im Mapping auftauchen
//
// Revision 1.15  2007/04/02 18:32:22  gnomi
// Schonzeit auf 120 Sekunden wegen Verkaeufer erhoeht.
//
// Revision 1.14  2006/12/30 01:01:07  menaures
// Nicht referenzierte Objekte zeitnah entfernen
//
// Revision 1.13  2003/05/30 12:22:46  freaky
// Hilfs-Funktionen eingefuehrt fuer das set_this_ob Problem
//
// Revision 1.12  2002/02/23 05:17:26  gnomi
// Korrektur zum letzten Patch.
//
// Revision 1.11  2002/02/22 03:09:32  gnomi
// clone_object: Simul-Efun search_object statt Funktion des Masters nutzen.
//
// Revision 1.10  2002/02/21 20:03:05  freaky
// Pulami: Erweiterung um lokale Pfade und '%' eingebaut.
//
// Revision 1.9  2000/12/07 20:53:26  gnomi
// Vor dem raise_error ein set_this_object(previous_object()); damit die
// Fehlermeldung dem richtigen Objekt zugeordnet wird.
//
// Revision 1.8  2000/07/16 22:25:24  freaky
// Nicht nur im Testmud einen Fehler erzeugen.
//
// Revision 1.7  2000/06/24 20:13:56  freaky
// sys_log bei Filenamen ohne leading slash eingebaut.
//
// Revision 1.6  2000/06/19 16:44:48  freaky
// set_this_object() wieder rueckgaengig machen, fuer den Fall, dass diese
// Funktionen von der simul-efun selbst benutzt werden.
//
// Revision 1.5  2000/06/19 13:58:47  freaky
// Aenderungen am UDL-Handling
//
// Revision 1.4  2000/06/18 23:38:41  freaky
// kleinere Tweaks
//
// Revision 1.3  2000/06/18 23:00:53  freaky
// Variable ob war unnoetig
//
// Revision 1.2  2000/06/18 23:00:06  freaky
// Angepasst an die neue UDL-Struktur
//

/* --- Globale Variablen: --- */
mapping clones;

/* --- Initialisierung: --- */
protected void clone_object_create()
{
    clones = global_info["clones"] ||= ([:3]);
}

protected void clone_object_reset()
{
    /* Nicht referenzierte Objekte killen: */
    mixed type;
    mapping c = clones;

    clones = global_info["clones"] = ([:3]);

    foreach(object ob, string creator, int line, string trace : c)
    {
        // Ausnahmefall/Driverbug:
        if(!ob) continue;

        if(environment(ob) || query_shadowing(ob) || interactive(ob) ||
           !clonep(ob) || player_present(ob))
        {
            // OK.
            continue;
        }

        type = 1;
        catch(type = ({mixed})(ob->query_type("nocleanup") ||
                     ob->query_type("repraesentant") ||
                     ob->query_type("umgebung")); publish);

        if(type)
        {
            // Entweder OK oder Fehler.
            // Bleibt manueller Ueberpruefung ueberlassen.
            continue;
        }

        if(time() - object_time(ob) < 120)
        {
            // Schonzeit 120 Sekunden (Verkaeufer):
            clones[ob,0] = c[ob,0];
            clones[ob,1] = c[ob,1];
            clones[ob,2] = c[ob,2];
            continue;
        }

        // Wir haben ein nicht referenziertes Objekt.
        do_warning2(sprintf("Clone hatte keine Umgebung und wurde daher "
                            "zerstoert.\nTrace:\n%s", trace),
                    creator, object_name(ob), line);
        catch(ob->remove(); publish);
        catch(destruct(ob); publish);
    }
}

/* --- Simul-Efun: --- */

// Damit das set_this_object wieder vorbei ist nach dem clone_object
private object clone_object_set_this_object(mixed ob, object po)
{
    set_this_object(po);
    return efun::clone_object(ob);
}


object clone_object(mixed toclone)
{
    string udlname;
    object ret, to, clone;

    if (objectp(toclone))
    {
	udlname = ({string})toclone->query_udl_file();
    }
    else
    {
	string tmp;
	
	if(toclone[0]=='%')
	{
	    tmp = search_file(toclone, 0, "obj", ".c");
	    udlname = search_file(toclone, 0, "obj", ".udl");
	    if(tmp && strlen(udlname)<strlen(tmp)+3)
	    {
		tmp = tmp[..<3];
		udlname = 0;
	    }
	    else if(udlname)
	    {
		tmp = udlname[0..<5];
		udlname = 0;
	    }
	}
	else
	    tmp = abs_path(toclone);

	if(!tmp)
	{
	    set_this_object(previous_object());  
	    raise_error("Invalid filename for clone_object(): '" +
		toclone + "'\n");
	}

	toclone = tmp;

	// TODO: sollte man evtl. master::compile_object() nehmen, da
	// das ja ein File cloned
	if (file_size(toclone + ".c") < 0 && file_size(toclone + ".udl") > 0)
	    udlname = toclone;
    }

    if (udlname)
	clone = ({object})MASTER_OB->build_udl_object(udlname);
    else
        clone = funcall(#'clone_object_set_this_object,toclone,previous_object());

    if(clone)
    {
        clones[clone,0] = efun::load_name(previous_object());
#if __EFUN_DEFINED__(driver_info)
        clones[clone,1] = efun::driver_info(DI_TRACE_CURRENT)[<2][TRACE_LOC];
        clones[clone,2] = efun::driver_info(DI_TRACE_CURRENT_AS_STRING);
#else
        clones[clone,1] = efun::debug_info(DINFO_TRACE, DIT_CURRENT)[<2][TRACE_LOC];
        clones[clone,2] = efun::debug_info(DINFO_TRACE, DIT_STR_CURRENT);
#endif
    }

    return clone;
}
