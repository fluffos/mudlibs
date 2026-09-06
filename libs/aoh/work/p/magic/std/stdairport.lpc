// Carpet airport (c) Softbyte 31mar97
//
//
// This file can be inherited as a second inherit file to give any room
// all possibilites of a carpet airport
//
//
//
// Use: 1. In create you can add different carpets via
//         AddCarpet(type|file);            // use this form preferably
//         AddCarpet(type|file,refreshmode); 
//       
//         e.g. AddCarpet(NETWORK_LLP);
//              AddCarpet("/d/woodland/common/obj/turbocarpet");
//
//      2. If you want a new carpet when a player enters the room and
//         there is no carpet present call in your init() function
//         RefreshAirport();
//
//
//      3. type can be a filename string or following defines (see magic.h)
//         NETWORK_LLP       : standard carpet
//         NETWORK_HLP       : hlp carpet
//         NETWORK_WOODLAND  : woodland fast service


#include <rooms.h>
#include <moving.h>
#include <magic.h>

mapping carpets;
mapping QueryCarpets() {return carpets;}

// Works like add item and adds a carpet of a certain network (type)
// type can be either an filename of an carpet or a predefined network
// (see above or magic.h, i.e. NETWORK_LLP,...)
// to the room. refr is the optional refresh argument (default:REFRESH_REMOVE)
public varargs void AddCarpet(mixed type,int refr)
{
string filename;

  if (!carpets) carpets=([]);

  if (!refr) refr=REFRESH_REMOVE;
  if (!type) type=NETWORK_LLP;
  if (!intp(type))   
  {
    filename=type;
    type=filename->QueryNetwork();
  }
  else
  {
    switch(type)
    {
      case NETWORK_LLP: filename="/p/magic/obj/carpet";
      break;
      case NETWORK_HLP: filename="/p/magic/obj/carpet_hlp";
      break;
      case NETWORK_WOODLAND: filename="/p/magic/obj/carpet_woodland";
      break;
      default: filename="/p/magic/obj/carpet"; 
    }
  }
  if (!carpets[type]) carpets+=([type:filename]);
  this_object()->AddItem(filename,refr);
}

private void clone_carpet(string filename,int type)
{
string myid;
object carp;
  myid="_carpet"+to_string(type);  // "_carpet0"
  if (carpets[type] && !present(myid,this_object()))
  {
     carp=clone_object(filename);
     carp->move(this_object(),M_SILENT);
     tell_room(this_object(),
       capitalize(carp->QueryShort())+" lands swiftly from the sky.\n");
  }
}

// Refreshes the carpet in init
public void RefreshAirport()
{
int *idx;
int i;

   if (!carpets) carpets=([]);
   idx=m_indices(carpets);
   for (i=0;i<sizeof(idx);i++)
   {
     clone_carpet(carpets[idx[i]],idx[i]);
   }
}
 
