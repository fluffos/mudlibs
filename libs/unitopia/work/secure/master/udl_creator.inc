// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/udl_creator.c
// Description:	Files mit der Endung .udl werde hier verarbeitet.
// Author:	Jesaia (11.06.2000)
// Modified by:	Freaky (18.06.2000) Sicherheisabfragen eingebaut,
// 			Handler korrigiert.
// $Log: udl_creator.inc,v $
// Revision 1.11  2004/10/10 22:26:39  gnomi
// Typo.
//
// Revision 1.10  2003/04/01 00:08:03  freaky
// set_this_object: an neuen Driver angepasst.
//
// Revision 1.9  2000/06/19 16:44:03  freaky
// wieder public gemacht, damit es von simul_efun::clone_object() aufgerufen
// werden kann.
//
// Revision 1.8  2000/06/18 22:59:21  freaky
// set_original_udl_file() eingebaut
//
// Revision 1.7  2000/06/18 16:20:42  freaky
// UDL repariert: set_this_object() wurde nicht rueckgaengig gemacht
//


#pragma strict_types

private object clone_object_set_this_object(mixed ob, object po)
{
    set_this_object(po);
    return clone_object(ob);
}

// Files mit der Endung .udl werde hier verarbeitet, und das fertige
// Objekt wird an compile_object geliefert.
object build_udl_object(string f_name)
{
    int StartPoint, EndPoint;
    string udl_description, udl_type, udl_description2;
    object ob, po;

#if 1
    object debugger;
    if (debugger = find_player("freaky"))
	tell_object(debugger,sprintf("UDL: %O TO:%O PO:%O\n",
		    f_name,this_object(),previous_object()));
#endif
    udl_description = read_file(f_name + ".udl");

    // Freaky: evtl sollte man eher \n durch ein Space ersetzen
    udl_description2 = udl_description - "\n";
    StartPoint = strstr(udl_description2,"<#UDLBASIC_TYPE#>",1) + 18;
    EndPoint = strstr(udl_description2,"<#/UDLBASIC_TYPE#>",1) - 1;
    udl_type = trim(udl_description2[StartPoint..EndPoint]);

    if (debugger)
	tell_object(debugger,sprintf("UDL: %O udl-type:%O\n",
		    f_name,udl_type));

    //to = this_object();
    // Freaky: Da das ganze ja auch von touch in der simul-efun aufgerufen
    // wird, muss man evtl previous_object(1) nehmen:
    if (previous_object() == find_object(SIMUL_EFUN) ||
	    previous_object() == find_object(SPARE_SIMUL_EFUN))
	po = previous_object(1);
    else
	po = previous_object();

    // Freaky: TODO: Hier sollte man pruefen, ob udl_type ueberhaupt ein
    // sinnvoller Wert ist. Wenn nicht, sollte man eine Fehlermeldung erzeugen.
    // Weiterhin sollte man evtl. eine Pfaderweiterung wie in
    // master::inherit_file() machen, damit man keine globalen Pfade angeben
    // muss.
    ob = funcall(#'clone_object_set_this_object,udl_type,po);
    /*
    set_this_object(po);
    ob = clone_object(udl_type);
    set_this_object(to);
    */

    if (!ob)
	return 0;

    ob->set_udl_file(f_name);
    ob->process_udl(udl_description);

    if (debugger)
	tell_object(debugger,sprintf("UDL: %O ob:%O\n",
		    f_name,ob));

    return ob;
}
