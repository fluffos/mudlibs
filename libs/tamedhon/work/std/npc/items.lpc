// Tamedhon MUDLIB
//
// std/npc/items.c -- AddItem() fuer NPCs
//
// $Date: 2006/06/01 12:30:00 $
/* $Revision: 1.3 $
 * $Log: items.c,v $
 * Revision 2006/06/01 12:30:00  Serii
 * random bei AddUniqueItem()
 *
 * Revision 1.2  2004/03/12 14:00:00  Serii
 * AddUniqueItem() eingebaut
 *
 * Revision 1.1  2000/06/04 18:59:08  Samtpfote
 * Initial revision
 *
 */

#pragma strong_types

#include <moving.h>
#include <npc/items.h>

#define ADB(x)		if(find_player("debugger")) \
			    tell_object(find_player("debugger"), \
			    sprintf("[npc/items.c] %O\n",x));


void AddItem(mixed what, int clone_method)
{
    object	ob;
	string	file;
	
//UI
        if(objectp(what))
	{
	  ob=what;
	}
//IU
	else if(stringp(what)) 
	{
	  file=what;
	}
	else if(pointerp(what))		/* array? */
	{
	  file=what[random(sizeof(what))];
	}
	
    //ADB(file);	
    if(!ob)catch(ob=clone_object(file));
    if(!ob)
    {
	raise_error(sprintf("%O: could not access file %s for cloning!\n",
			this_object(), file));
	return;			
    }
    
    switch(clone_method)
    {
	case CLONE_WIELD:
	    ob->move(this_object(), M_GET|M_SILENT);
	    ob->wield_me(1);
	    break;
	    
	case CLONE_WEAR:
	    ob->move(this_object(), M_GET|M_SILENT);
	    ob->DoWear(1);
	    break;
    
	case CLONE_MOVE:
	default:
	    ob->move(this_object(), M_GET|M_SILENT);
	    break;
    }
}

varargs void AddUniqueItem(string *filenames, int clone_method, int bp, int rand)
{
  if(!filenames || !clone_method)
  {
    raise_error("Wrong arguments to AddUniqueItem()\n");
    return;
  }
  if(sizeof(filenames)!=2)
  {
    raise_error("Wrong number of filenames in AddUniqueItem()\n");
    return;
  }
  if(!rand||rand<2)AddItem(call_other("/p/daemon/UIMaster","UI_clone_object",filenames[0],filenames[1],bp),clone_method);
  else if(!random(rand))AddItem(call_other("/p/daemon/UIMaster","UI_clone_object",filenames[0],filenames[1],bp),clone_method);
  else AddItem(filenames[1],clone_method);
}
