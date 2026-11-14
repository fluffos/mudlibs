// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/get_wiz_name.inc
// Description: Ermittelt den Programmierer eines Files
// Modified:    Freaky (20.05.94) Fixed Bug mit Map-Raeumen
// Modified:	Freaky (08.02.95) Fuer Verzeichnisse in einer Domain,
//				  fuer die es keinen Gott gibt, returne DL
//
// $Log: get_wiz_name.inc,v $
// Revision 1.3  2001/03/13 22:52:25  freaky
// Funktion faktisch disablen, da es nicht wirklich Sinn macht.
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types
/*
 * Get the owner of a file. 
 * driver:     wird fuer die driver wiz_list benoetigt.
 *
 * Wird nur fuer get_error_file() verwendet. Damit wird bestimmt, fuer
 * welchen Wiz der Fehler im Driver gespeichert werden soll.
 */
string get_wiz_name(string file)
{
    return 0;
}
#if 0
string get_wiz_name(string file)
{
    string *path, name;
    int size, x, y;

    if (!file)
	return 0;
    /* leading slash dran */
    if (file[0] != '/')
	file = "/" + file;
    if (sscanf(file, "/map/m%d_%d",x,y) == 2)
	file = ({string})MAP_OB->query_map_file_name(x,y);
    path = explode(file,"/");
    size = sizeof(path);
    switch(path[1])
    {
      case "d":
	if (size > 4)
	{
	    name = path[3];
	    if (!GOETTER_REGISTER->is_wiz(name))
		name = query_domain_lord(path[2]);
	}
	else if (size == 4)
	    name = query_domain_lord(path[2]);
	break;
      case "w":
      case "p":
	if (size > 3)
	    name = path[2];
	break;
      default:
	return 0;
    }
    return GOETTER_REGISTER->is_wiz(name) && name;
}
#endif
