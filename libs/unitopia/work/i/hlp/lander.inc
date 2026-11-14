// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /i/hlp/lander.inc
// Description: 
//
// $Log: lander.inc,v $
// Revision 1.6  2002/12/17 03:56:53  gnomi
// Arbeitet jetzt ueber Controller statt moved_in-Ueberlagerung.
//
// Revision 1.5  2002/10/19 00:41:02  gnomi
// moved_in/out hat kein VARARGS mehr.
//
// Revision 1.4  2001/01/30 23:59:00  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma save_types
#pragma strong_types

#include <config.h>
#include <level.h>

private string map2domain_expansion(string name)
{
    int x, y;

    if(sscanf(name,"/map/m%d_%d",x,y) == 2 &&
       stringp(name = MAP_OB->query_map_file_name(x,y)) &&
        name[<2..] == ".c")
       name = name[0..<3];
    return name;
}

private void hlp_moved_in(string notify_moved_in, object who, object woher, string dir, int way)
{
   object kugel;
   string ort;

   if(who &&
      (hlpp(who) || wizp(who)) &&
      (kugel = present("hlp#tool", who)) &&
      kugel->gabe("pf") &&
      !(kugel->query_ort(ort = map2domain_expansion(object_name()))))
      kugel->add_ort(ort);
}

private int __lander_inc_init__ = this_object()->add_controller(
    "notify_moved_in", #'hlp_moved_in);
