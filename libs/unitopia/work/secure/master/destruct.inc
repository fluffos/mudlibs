// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/destruct.inc
// Description: prepare_destruct wird vor einem destruct() aufgerufen
// Author:	Freaky
// Modified by:	Freaky (07.05.96) do_log_error und remove_shadow eingebaut
// 		Freaky (01.03.2000) an das neue add_encumbrance() angepasst
//
// $Log: destruct.inc,v $
// Revision 1.25  2016/03/21 12:41:08  gnomi
// Typo zum vorherigen Patch.
//
// Revision 1.24  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.23  2010/09/05 10:50:59  sorcerer
// Meldung mit wrap umgebrochen
//
// Revision 1.22  2007/12/29 16:33:30  gnomi
// Kleinere Catch-Reserve.
//
// Revision 1.21  2007/06/25 22:20:33  gnomi
// Spieler via force_move ins Nirwana bewegen.
//
// Revision 1.20  2006/10/02 20:17:55  gnomi
// Das Zerstoeren des Inventars gegen die Zerstoerung des Objektes an sich
// absichern.
//
// Revision 1.19  2006/01/22 01:09:23  gnomi
// Flags bei debug_message angeben.
//
// Revision 1.18  2004/11/16 23:01:03  gnomi
// Destruct-Fehler im debug.log ausgeben.
//
// Revision 1.17  2004/10/06 22:12:08  gnomi
// CATCH-Makro: Eval-Toleranz erhoeht.
//
// Revision 1.16  2004/09/22 22:23:01  gnomi
// Erst alle Objekte aus dem Gegenstand rausbewegen, dann den Rest zerstoeren.
//
// Revision 1.15  2004/01/28 23:23:16  gnomi
// catch() nur dann ausfuehren, falls die __CATCH_EVAL_COST__ zur Verfuegung
// stehen, ansonsten dies als Fehler behandeln.
//
// Revision 1.14  2003/08/07 13:27:23  menaures
// Fehlerausgabe im prepare_destruct weniger technisch fuer Spieler
//
// Revision 1.13  2002/10/28 03:03:27  gnomi
// STATIC_LIGHT-Code ausgebaut.
//
// Revision 1.12  2002/07/02 22:31:27  menaures
// Lichtsystem in die Mudlib integriert.
//
// Revision 1.11  2002/01/12 21:23:46  gnomi
// Benachrichtung des QUEUED entfernt.
//
// Revision 1.10  2001/03/21 11:02:07  freaky
// do-log-error: weiteren Parameter eingefuerhrt, mit dem keine Meldung
// an Spieler erzeugt wird.
//
// Revision 1.9  2001/03/13 22:53:22  freaky
// einige Funktionen protected machen.
//
// Revision 1.8  2000/12/31 00:37:58  freaky
// destruct_error robuster gemacht.
//
// Revision 1.7  2000/12/26 13:09:00  freaky
// destruct_error() eingefuehrt.
// catch um das notify("remove") gemacht.
//

#pragma strict_types

#if __VERSION__ > "3.3.559"
#define CATCH(cmd) catch(cmd; reserve 5000)
#else
#define CATCH(cmd) ((get_eval_cost()>__CATCH_EVAL_COST__+7)?catch(cmd):"*Not enough eval time left for catch()\n")
#endif

private void destruct_error(object ob, object sh, varargs mixed *args)
{
    string msg;

    args[<1] = args[<1][1..];
    CATCH(msg = apply(#'sprintf,args));
    if (!msg)
	msg = implode(args," ");
    CATCH(do_log_error("FATAL: prepare_destruct(): " + msg,
		__FILE__,object_name(ob),
		0,explode(getuid(sh),":") + ({ getuid(sh) }),0));

    if(wizp(this_player()))
        write("FATAL: prepare_destruct(): " + msg +
	        "\nDieser Fehler MUSS sofort behoben werden!!!\n");
    else
    {
        write("Vor dir tut sich ein ganzer Riss im Raum-Zeit-Gefuege auf.\n"
              "Dieser Fehler MUSS sofort behoben werden!!!\n");
	debug_message("FATAL: prepare_destruct(): " + msg + "\n", DMSG_STDOUT | DMSG_LOGFILE | DMSG_STAMP);
#if __EFUN_DEFINED__(driver_info)
	debug_message(efun::driver_info(DI_TRACE_CURRENT_AS_STRING), DMSG_STDOUT | DMSG_LOGFILE | DMSG_STAMP);
#else
	debug_message(efun::debug_info(DINFO_TRACE,DIT_STR_CURRENT), DMSG_STDOUT | DMSG_LOGFILE | DMSG_STAMP);
#endif
    }
}

protected mixed prepare_destruct(object ob)
{
    object super, inv, sh, next;
    string tmp;

    // Wenn es kein Shadow ist, alle Shadows des Objektes unshadowen und
    // zerstoeren.
#if __EFUN_DEFINED__(query_shadowing)
    if (!query_shadowing(ob))
#else
    if (!efun::object_info(ob, OI_SHADOW_PREV))
#endif
    {
        if (tmp = CATCH(ob->notify("remove")))
	{
	    destruct_error(ob,ob,
		    "Fehler beim notify_remove() von:%O Fehler:%s",ob,tmp);
	}
	if (environment(ob) && tmp = CATCH(environment(ob)->notify("remove_inventory", ob)))
	{
	    destruct_error(ob,ob,
		    "Fehler beim notify_remove_inventory() von:%O Fehler:%s",ob,tmp);
	}
#if __EFUN_DEFINED__(query_shadowing)
	for (sh = shadow(ob, 0); sh; sh = next)
	{
	    next = shadow(sh, 0);
#else
	for (sh = efun::object_info(ob, OI_SHADOW_NEXT); sh; sh = next)
	{
	    next = efun::object_info(sh, OI_SHADOW_NEXT);
#endif
	    if (tmp = CATCH(sh->remove_shadow(sh)))
	    {
		destruct_error(sh,sh,
			"Fehler beim remove_shadow von:%O auf:%O Fehler:%s",
			sh,ob,tmp);
	    }
	    if (sh)
	    {
		funcall(bind_lambda(#'unshadow, sh)); // avoid deep recursion
		destruct(sh);
	    }
	}
    }
 
    super = environment(ob);
    if (!super)
    {
	if (object_name(ob) == "/room/void")
	    tmp = "/room/hell";
	else
	    tmp = "/room/void";
	while (ob && (inv = first_inventory(ob)))
#if __EFUN_DEFINED__(query_once_interactive)
	    if (query_once_interactive(inv))
#else
	    if (efun::object_info(inv, OI_ONCE_INTERACTIVE))
#endif
	    {
		tell_object(inv,
			    "Alles in deiner Umgebung loest sich auf....\n");
		tell_room(tmp, funcall(symbol_function("wrap"),
                    funcall(symbol_function("Der"), inv) + " stolpert mit "
                    "einem ueberraschten Gesichtsausdruck heran."));
		    
		inv->force_move(tmp,MOVE_MAGIC);
	    }
	    else
	    {
		inv->remove();
		if (inv)
		    destruct(inv);
	    }
    }
    else
    {
	// Erst alles rausbewegen und dann den Rest zerstoeren.
	// (Hilft bei Objekten, die anderen Objekten folgen.)
	foreach(inv: all_inventory(ob))
	    if(inv && environment(inv)==ob &&
		tmp = CATCH(inv->move(super)))
	    {
		destruct_error(inv,sh,
			"Fehler beim MOVE von:%O nach:%O Fehler:%s",
			inv,super,tmp);
		if (inv)
		    destruct(inv);
	    }
	    
	while (ob && (inv = first_inventory(ob)))
	{
	    inv->remove();
	    if (inv)
	        destruct(inv);
	}

	if (tmp = CATCH(super->add_encumbrance(ob,ENC_REMOVE,0)))
	{
	    destruct_error(ob,sh,
		    "Fehler bei add_encumbrance von:%O in:%O Fehler:%s",
		    ob,super,tmp);
	}
    }

    return 0; /* 0 for sucess */
}
