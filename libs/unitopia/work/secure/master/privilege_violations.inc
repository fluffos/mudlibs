// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /secure/master/privilege_violations.inc
// Description: Entscheidungen ueber sicherheitskritische Funktionen
// Author:      Gnomi
//
// $Log: privilege_violations.inc,v $
// Revision 1.43  2016/03/21 12:41:39  gnomi
// strlen -> sizeof
//
// Revision 1.42  2016/03/10 20:32:21  gnomi
// receive_message-Shadow duerfen auch vertraute Objekte.
//
// Revision 1.41  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.40  2015/01/23 17:50:46  myonara
// Bugfix zu player_con (z_erneuere)
//
// Revision 1.39  2014/12/19 18:20:38  myonara
// neu offline_set_rang. und Bigfix zu player_con
//
// Revision 1.38  2014/10/14 17:34:09  myonara
// Neues Element player_con: zern erlauben.
//
// Revision 1.37  2014/01/05 12:45:15  myonara
// ah_dont_die ueberarbeitet
// ah_dont_die und ah_no_guardian_angel mit Warnungen versehen
//
// Revision 1.36  2013/12/08 16:58:10  myonara
// /apps/room_autoload in move zugelassen.
//
// Revision 1.35  2013/06/15 20:49:22  sorcerer
// Neu: query_no_idle_logout
//
// Revision 1.34  2013-05-09 11:09:08  myonara
// RTE's fuer manche violations einefuehrt, Leerzeichen statt Tabs.
//
// Revision 1.33  2007/10/24 21:57:58  gnomi
// Man sich nicht in einen Shadow bewegen bzw. ein Objekt mit Inhalt darf nicht
// Shadow werden.
//
// Revision 1.32  2007/07/27 15:09:37  gnomi
// offline_add_konto eingefuehrt.
//
// Revision 1.31  2007/06/25 22:20:46  gnomi
// prepare_destruct darf force_move einsetzen.
//
// Revision 1.30  2007/05/26 23:05:47  gnomi
// Bei "move" melden, wohin bewegt werden sollte.
//
// Revision 1.29  2005/08/28 00:20:52  gnomi
// Neues Count-Ob-Handling.
//
// Revision 1.28  2005/06/03 20:17:45  gnomi
// Admins koennen Spielerbeschreibungen (per zc) veraendern-
//
// Revision 1.27  2005/05/06 23:00:00  gnomi
// Ueberfluessige #ifdefs entfernt.
//
// Revision 1.26  2005/03/27 20:34:49  menaures
// Neue Mudlib-Priv "set_one_description_source"
//
// Revision 1.25  2005/02/02 22:32:26  gnomi
// ah_dont_die eingefuehrt.
//
// Revision 1.24  2004/11/27 21:36:01  gnomi
// add_hp-Aenderung: Neue ah_no_guardian_angel-Parameter dokumentiert.
//
// Revision 1.23  2004/11/16 23:00:34  gnomi
// Dem SR-Raum ein force_move erlauben.
//
// Revision 1.22  2004/09/17 08:39:28  gnomi
// ah_no_guardian_angel eingefuehrt.
//
// Revision 1.21  2004/05/12 21:00:41  gnomi
// Unerlaubte Moves jetzt wirtklich verbieten, statt nur Warnungen ausgeben.
//
// Revision 1.20  2003/12/14 15:41:21  menaures
// /apps/spielerrat_kandidatenliste darf gemoved werden.
//
// Revision 1.19  2003/09/24 01:14:55  gnomi
// SR-Buecher duerfen force_move nutzen.
//
// Revision 1.18  2003/07/31 00:50:26  menaures
// Move von /apps/second erlauben
//
// Revision 1.17  2003/07/27 21:06:30  menaures
// Path-Restriction no-move ueber mudlib_privilege "move" realisieren
//
// Revision 1.16  2003/07/16 00:57:33  gnomi
// "query_ip": Aequivalent zu den nomask simul_efun query_ip_name-Privis.
//
// Revision 1.15  2003/01/26 04:05:47  gnomi
// Leichen duerfen ihre Skelette per force_move bewegen.
//
// Revision 1.14  2003/01/24 01:29:32  gnomi
// guardian_angel und magic_disguise hinzugefuegt.
//
// Revision 1.13  2003/01/17 01:48:56  gnomi
// Mudlib-Privilegien aus /static/adm/MUDLIB_PRIVILEGES einlesen.
//
// Revision 1.12  2002/11/22 00:25:20  gnomi
// Move der Goetter beim Ausloggen in den Workroom per force_move erlauben.
//
// Revision 1.11  2002/10/21 01:01:09  gnomi
// force_move fuer ein technisches Ob aus dem Lab.
//
// Revision 1.10  2002/10/16 01:03:19  gnomi
// reg_actions duerfen zur einfacheren Verarbeitung von countobs force_move
// nutzen. (Das ist erstmal ein Test, vielleicht kann dies spaeter mal direkt
// ins countob wandern.)
//
// Revision 1.9  2002/09/18 23:46:23  gnomi
// force_move mti Mailreader: Falsches Objekt abgetestet.
//
// Revision 1.8  2002/09/11 22:43:11  gnomi
// Postaemter duerfen force_move fuer die Briefmappen einsetzen.
//
// Revision 1.7  2002/03/16 12:11:49  gnomi
// Sicherheitsloch gestopft.
//
// Revision 1.6  2001/11/18 02:02:01  gnomi
// /obj/brett wurde nach /i/object/brett verschoben.
//
// Revision 1.5  2001/11/10 08:36:49  gnomi
// Newsbretter duerfen Newsreader auch an geschlossene Spieler (Geister)
// verteilen.
//
// Revision 1.4  2001/10/27 07:06:48  gnomi
// Gnomi: die() in /i/living/die wird es erlaubt, Leichen in die Umgebung
// per force_move zu bewegen.
//
// Revision 1.3  2001/08/31 03:29:48  gnomi
// Altes move_force rausgenommen.
// Bewegung zum Tod und zu Lyrion sind nun per force_move erlaubt.
//
// Revision 1.2  2001/07/22 23:36:35  gnomi
// Anstatt move_force gibt es ein force_move, welches strenger sein kann.
//
// Revision 1.1  2001/07/22 01:38:33  gnomi
// Funktion fuer Mudlib-Privis.
//

#define PRIVI_FILE "/static/adm/MUDLIB_PRIVILEGES"

static mapping granted;

private void get_privis()
{
    string file = read_file(PRIVI_FILE);
    string section;
    int singles;

    if(!file)
        return;
    granted = ([]);
    foreach(string line:explode(file,"\n"))
    {
        line = trim(line);
        if(!sizeof(line) || line[0]=='#')
            continue;
        if(line[0]=='[' && line[<1]==']')
        {
            section = line[1..<2];
            granted[section] = ([:0]);
        }
        else if(!section)
            write("Master: Fehler beim Lesen von "PRIVI_FILE"!\n");
        else
        {
            int i = strstr(line,":");
            if(i<0)
                m_add(granted[section],line);
            else
            {
                if(!widthof(granted[section]))
                    granted[section] = m_reallocate(granted[section], 1);
                granted[section][line[0..i-1]] = map(explode(line[i+1..<1],","),#'trim);
            }
        }
    }
}


/*
 * Liefert das Programm und Include zurueck.
 * n=0: Programm, welches die Funktion aufgerufen hat, welche previous_program
 *      abfragt.
 * trace: debug_info(DINFO_TRACE); (Damit es nicht doppelt abgefragt werden
 *        muss)
 */
private string* previous_program(int n, mixed trace)
{
    string prog, incl, incl2;

    if(sizeof(trace)<=1 || sizeof(trace)<=n+2) return 0;

    // <1 ist der Aufrufer von previous_program
    // Und n=0 soll den Aufrufer des Aufrufers von previous_program bringen
    sscanf(trace[<(n+2)][TRACE_PROGRAM],"%s (%s)",prog,incl);
    
    if(!prog)
        prog = trace[<(n+2)][TRACE_PROGRAM];
    prog = add_slash(prog);
    if(incl && incl[0]!='/')
        incl = implode(explode(prog,"/")[0..<2]+({incl}),"/");

    return ({ prog, incl });
}

/*
 * Wenn die in what angegebene Funktion erlaubt ist, liefert diese Funktion
 * 1 zurueck, ansonsten 0. who ist das offensichtlich verantwortliche
 * Objekt.
 */
int mudlib_privilege_violation(string what, object who, varargs mixed *args)
{
    string tolog="";
    mixed trace,onet;
    string ob, ob2;
    string *pp;
    int i;
    
    switch(what)
    {
        case "move":
        // who: Aufrufer von Move
        // args: ({destination, way})
            string tmp;
            object dest;

            ob = object_name(previous_object());

            // Ausnahmeregelungen (einzelne Files):
            if(member( ({"/apps/second","/apps/room_autoload",
                         "/apps/spielerrat_kandidatenliste"}), ob ) != -1)
            {
                return 1;
            }

            // Ausnahmeregelungen (absolute Verzeichnisse, laengste zuerst):
            foreach(tmp : ({"/room/"}))
            {
                if(strstr(ob, tmp) == 0)
                {
                    ob2 = ob[sizeof(tmp)..];
                    break;
                }
            }

            ob2 ||= ob;

            // Restrictions (Teilverzeichnisse):
            foreach(tmp : ({"/room/", "/apps/", "/i/"}))
            {
                if(strstr(ob2, tmp) != -1)
                {
                    do_log_error(sprintf("Bitte Objekte aus %s nicht bewegen!\n", tmp),
                        (who ? object_name(who) : ob), ob, 0, 0, 1);
                    return 0; 
                }
            }

            if(sscanf(ob2, "%~s#%~d") < 2 && strstr(ob2, "/obj/") >= 0)
            {
                do_log_error("Bitte das Original-Objekt nicht bewegen, "
                        "nur Clones davon!\n",
                             (who ? object_name(who) : ob), ob, 0, 0, 1);
                return 0;
            }

            if(stringp(args[0])?(args[0]=="/obj/room"):
                objectp(args[0])?(object_name(args[0])=="/obj/room"):0)
            {
                tolog = sprintf(" nach %O (wie: %O)", args[0], args[1]);
                break;
            }
        
            if(stringp(args[0]))
                dest = find_object(args[0]);
            else if(objectp(args[0]))
                dest = args[0];
    
#if __EFUN_DEFINED__(driver_info)
            if(dest && efun::object_info(dest, OI_SHADOW_PREV))
#else
            if(dest && query_shadowing(dest))
#endif
            {
                do_log_error("Bitte nicht in Shadows hineinbewegen!\n",
                        (who ? object_name(who) : ob), ob, 0, 0, 1);
                return 0;
            }

            return 1;

        case "force_move":
            // who: Wer rufte force_move auf.
            // args: ({destination, way})
        
            // Poststellen duerfen die Briefmappe verteilen.
            if(load_name(previous_object())=="/obj/mailreader" && playerp(args[0]))
                return 1;
        
            // Genauerer Test notwendig, da z_call im selben Objekt und Include
            // wie z_erneuere ist.
            
#if __EFUN_DEFINED__(driver_info)
            trace = efun::driver_info(DI_TRACE_CURRENT);
#else
            trace = efun::debug_info(DINFO_TRACE, DIT_CURRENT);
#endif

            // trace[<1]: mudlib_privilege_violation
            // trace[<2]: force_move
            // trace[<3]: Aufrufende Funktion
            if(sizeof(trace)<4)
                break;
            
            ob = add_slash(trace[<3][TRACE_OBJECT]);

#ifdef AUTO_COUNTOB
            // Countobs nutzen es zum Teilen
            if (add_slash(trace[<3][TRACE_PROGRAM]) == "/i/object/countob.c" &&
                trace[<3][TRACE_TYPE] == TRACE_TYPE_LFUN &&
                trace[<3][TRACE_NAME] == "split_object")
                return 1;
#endif /* AUTO_COUNTOB */

            // Die Funktion anschauen. (zcall duerfen nur Admins)
            if (ob[0..15]=="/obj/zauberstab#" &&
                    ( ( trace[<3][TRACE_TYPE] == TRACE_TYPE_LFUN &&
                        trace[<3][TRACE_NAME] == "z_erneuere") ||
                      ( trace[<3][TRACE_TYPE] == TRACE_TYPE_EFUN &&
                        trace[<3][TRACE_NAME] == "call_resolved" &&
                        adminp(this_interactive()) &&
                    geteuid(this_interactive())==geteuid(find_object(ob)) &&
                    this_interactive()==this_player()) ) )
                return 1;
    
            // Der Master darf das beim Zerstoeren
            if (add_slash(trace[<3][TRACE_PROGRAM]) == 
                    "/secure/master.c (/secure/master/destruct.inc)" &&
                trace[<3][TRACE_TYPE] == TRACE_TYPE_LFUN &&
                trace[<3][TRACE_NAME] == "prepare_destruct")
                return 1;
    
            // Goetter kommen beim Ausloggen in ihren Workroom.
            if (add_slash(trace[<3][TRACE_PROGRAM]) == "/i/player/player.c" &&
                trace[<3][TRACE_TYPE] == TRACE_TYPE_LFUN &&
                trace[<3][TRACE_NAME] == "quit")
                return 1;

        // Leichen kommen so in die Umgebung
            if (add_slash(trace[<3][TRACE_PROGRAM]) == "/i/living/die.c" &&
                trace[<3][TRACE_TYPE] == TRACE_TYPE_LFUN &&
                trace[<3][TRACE_NAME] == "die")
                return 1;
            // ... Skelette in die Umgebung der Leiche
            if (add_slash(trace[<3][TRACE_PROGRAM]) == "/i/object/leiche.c" &&
                trace[<3][TRACE_TYPE] == TRACE_TYPE_LFUN &&
                trace[<3][TRACE_NAME] == "skelettiere")
                return 1;

            // Player duerfen zum Tod oder Lyrion
            if (member(query_valid_shells(),explode(ob,"#")[0])>=0 &&
                trace[<3][TRACE_TYPE] == TRACE_TYPE_LFUN &&
                    ( trace[<3][TRACE_NAME] == "move_to_death" ||
                    trace[<3][TRACE_NAME] == "add_hp") )
                return 1;
        
            // Bretter duerfen Newsreader verteilen.
            if (load_name(previous_object()) == "/obj/newsreader" &&
                (add_slash(trace[<3][TRACE_PROGRAM]) == "/obj/brett.c" ||
                add_slash(trace[<3][TRACE_PROGRAM]) == "/i/object/brett.c") &&
                trace[<3][TRACE_TYPE] == TRACE_TYPE_LFUN && 
                trace[<3][TRACE_NAME] == "query_read")
                return 1;
    
            // reg_action darf das fuer eine Spezialbehandlung von countobs.
            if(add_slash(trace[<3][TRACE_PROGRAM]) == "/p/Misc/i/reg_action.c")
                return 1;

            // Spielerratsraeume duerfen das fuer einen Rauswurf
            if(ob[0..28] == "/room/rathaus/spielerrat/raum" &&
               add_slash(trace[<3][TRACE_PROGRAM]) == 
                   "/room/rathaus/spielerrat/i/rauswurf.c")
                return 1;
        
        // Geister duerfen diese Buecher nehmen...
            if(ob[0..32] == "/room/rathaus/spielerrat/obj/buch")
                return 1;

            ob2 = funcall(symbol_function("map2domain"),ob);
            if(ob2)
                ob2 = ob2[0..<3]; // Keine Endung
            else
                ob2 = ob;

            if(granted && granted["force_move"] &&
                member(granted["force_move"][load_name(previous_object())]
                        ||({}), ob2)>=0)
                return 1;

            tolog = sprintf(" nach %O (wie: %O), obj: %O (%O) in %O",
                args[0], args[1], trace[<3][TRACE_OBJECT],
                trace[<3][TRACE_PROGRAM], trace[<3][TRACE_NAME]);

            break;

        case "receive_message":
        // who: Der Shadow
        // args: ({})
    
            if(load_name(who)=="/obj/editor_shadow")
                return 1;

            if(granted && granted["receive_message"] &&
                member(granted["receive_message"], load_name(who)))
                return 1;

            // Goetter duerfen sich oder ihren Testies ihre eigenen Shadows
            // natuerlich ueberwerfen, wenn sie Spass daran haben...
            if(((wizp(previous_object()) && (ob=({string})previous_object()->query_real_name())) ||
                (ob=({string})testplayerp(previous_object()))) &&
                (!strstr(load_name(who),"/w/"+ob+"/") || geteuid(who) == ob))
                return 1;
        
            tolog = sprintf(", TP: %O, PO(3): %O", this_player(), 
                    previous_object(3));
            do_log_error(sprintf("Shadow %O darf %s nicht ueberlagern!\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;
    
        case "guardian_angel":
        // who: Der Aufrufer von set_probability_for_guardian_angel
        // args: ({sterblich, unsterblich})
    
            if(granted && granted["guardian_angel"] &&
                member(granted["guardian_angel"], load_name(who)))
                return 1;
        
            tolog = sprintf(", sterblich: %O, unsterblich: %O", args[0], 
                        args[1]);
            
            do_log_error(sprintf(
                    "Objekt %O darf set_probability_for_%s nicht aufrufen!\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;

        case "ah_dont_die":        
        // who: Der Aufrufer von add_hp mit AH_DONT_DIE
        // args: ({ hps, attacker_ob, flag, erf_tod_msg }) (altes add_hp)
        // args: ({ hps, infos }) (neues add_hp)

            tolog = sprintf(", hps: %O, infos: %O", args[0], args[1]);

            if(!granted || !granted["ah_dont_die"])
            {
                do_log_error(sprintf(
                    "Objekt %O darf %s nicht verwenden.\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
                break;
            }
            if (member(granted["ah_dont_die"], load_name(who)))
            {
                return 1;
            }
        
            // Wir ignorieren who und schauen alle Shadows durch.
            foreach(object po: caller_stack()[1..])
                if(member(granted["ah_dont_die"], load_name(po)))
                    return 1;
            do_log_error(sprintf(
                    "Objekt %O und seine Shadows darf %s nicht verwenden.\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;
            
        case "ah_no_guardian_angel":
        // who: Der Aufrufer von add_hp mit AH_NO_GUARDIAN_ANGEL
        // args: ({ hps, attacker_ob, flag, erf_tod_msg }) (altes add_hp)
        // args: ({ hps, infos }) (neues add_hp)
            if(granted && granted["ah_no_guardian_angel"] &&
                member(granted["ah_no_guardian_angel"], load_name(who)))
                return 1;
            
            tolog = sprintf(", hps: %O, infos: %O", args[0], args[1]);
            do_log_error(sprintf(
                    "Objekt %O darf %s nicht verwenden.\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;
    
        case "magic_disguise":
        case "hp_sp_view_shadow":
        // who: Der Shadow
        // args: ({})

            if(granted && granted[what] &&
                member(granted[what], load_name(who)))
                return 1;
            do_log_error(sprintf("Shadow %O darf %s nicht ueberlagern!\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;

        case "query_ip":
        // who: Der Aufrufer
    
#if __EFUN_DEFINED__(driver_info)
            trace = efun::driver_info(DI_TRACE_CURRENT);
#else
            trace = efun::debug_info(DINFO_TRACE, DIT_CURRENT);
#endif
            pp = previous_program(1,trace);
        
            if( pp[0]=="/apps/town.c" ||
                (pp[0]=="/i/zauberstab/zauberstab.c" &&
                (pp[1]=="/i/zauberstab/zvolk.inc" ||
                pp[1]=="/i/zauberstab/zinfos.inc")))
                return 1;

            tolog = pp[1]?sprintf(", program: %s (%s)",pp[0],pp[1])
                    :sprintf(", program: %s",pp[0]);

            break;

        case "set_one_description_source":
        // who: Der Aufrufer
        // args: ({merkmalnummer, wert})

            if(object_name(who) == "/apps/description")
                return 1;
        
            if(adminp(this_player()) && this_player()==this_interactive() &&
                getuid(who)==getuid(this_player()))
                return 1;

            if(granted && granted[what] &&
               member(granted[what], load_name(who)))
                return 1;
            do_log_error(sprintf("Objekt %O darf %s nicht aufrufen!\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;

        case "offline_add_konto":
        // who: Der Aufrufer
        // args: ({ spieler, wert })
            if(granted && granted[what] &&
                member(granted[what], load_name(who)))
                return 1;
            do_log_error(sprintf("Objekt %O darf %s nicht aufrufen!\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;
        case "offline_set_rang":
        // who: Der Aufrufer
        // args: ({ spieler, wert })
            if(granted && granted[what] &&
                member(granted[what], load_name(who)))
                return 1;
            do_log_error(sprintf("Objekt %O darf %s nicht aufrufen!\n",
                        who,what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;
        case "query_no_idle_logout":
        // who: Das Environment, das ein Idle-Logout verhindern will
        // args: ({ spieler })
            if(granted && granted[what] &&
                member(granted[what], load_name(who)))
                return 1;
            do_log_error(sprintf("Raum %O darf %s nicht verwenden!\n",
                        who, what),
                        object_name(who), object_name(who), 0, 0, 1);
            break;

        case "player_con":
        // who: das Objekt, das in den Player_container will
        // args: 0
#if __EFUN_DEFINED__(driver_info)
            trace = efun::driver_info(DI_TRACE_CURRENT);
#else
            trace = efun::debug_info(DINFO_TRACE, DIT_CURRENT);
#endif

            // trace[<1]: mudlib_privilege_violation
            // trace[<2]: let_not_in (in /obj/player_con.c)
            // trace[<3]: move
            // trace[<n]: Aufrufende Funktion z_erneuere.
            foreach (onet : trace)
            {
                if (!pointerp(onet)) continue;
                ob = add_slash(onet[TRACE_OBJECT]);
                if (ob[0..15]=="/obj/zauberstab#" &&
                    ( ( onet[TRACE_TYPE] == TRACE_TYPE_LFUN &&
                        onet[TRACE_NAME] == "z_erneuere") ) )
                    return 1;
            }
            
            break;
    }
    write_file("/log/sys/MUDLIB_PRIVI", sprintf("[%s] %O: who: %O in %O%s\n",
        ctime(time()), what, who, previous_object(), tolog));
}
