//---------------------------------------------------------------------------
// std/room.c
//
// The standard room in One Step Beyond.
//---------------------------------------------------------------------------

#include <classes.h>
#include <properties.h>

inherit "/std/room/restrictions";  // also has an create()
inherit "/std/room/description";
inherit "/std/room/exits";         // init() is here
inherit "/std/room/vwindows";      // has init() and reset()
inherit "/std/room/details";       // id() is here, vitem
inherit "/std/room/items";         // reset() is here
inherit "/std/skills";             // init() und create() and skill actions
inherit "/std/room/secrets";      // init() und create() and secrets
inherit "/std/room/cleaning";     // clean_up() and remove()
inherit "/std/thing/description";  // For the extra descriptions
inherit "/std/base";
  /* The clean_up() and remove() of /std/base are replaced by
     those in /std/room/cleaning. The dispatching function
     are below.
   */
// new commands to enable drink/food support and getting of vitems
// Magictcs - 21 apr 98
inherit "/std/room/vget";         // get support
inherit "/std/room/vdrink";       // drink support
inherit "/std/room/vfood";        // food support

/* -------------------------------------------------------------------------
 * Region handling
 * -------------------------------------------------------------------------
 */
mixed pRegion;

int QueryRegion() {
  if (intp(pRegion)) return pRegion;
  if (closurep(pRegion)) return funcall(pRegion);
  return -1;
}

int SetRegion(mixed r) {
  if (!r) return -1;                      // bad argument
  if (intp(r)) return pRegion=r;
  if (closurep(r)) { pRegion=r; return QueryRegion(); }
  write("Wrong argument for SetRegion.\n"
    "Use: SetRegion( region1 )\n"
    "     SetRegion( region1 | region2 | region3 | .... );\n");
  return -1;
}

/* some little hacks for the use at beyond. The implementation
 * is not very good, especially the QueryIntMap(), but at the
 * moment it works.
 * Feel free to 'fix' the routines to make them better.
 * Sonic
 */

int * pCoordinates;

int * InitCoordinates(int x, int y, int z, int *offset)
{
   /* is offset available? if not, make it available */
   if(!offset) offset=({ 0,0,0 });
   /* and is it of right size (3 entries)? If not, zero it */
   if(sizeof(offset)!=3)  offset=({ 0,0,0 });
   x+=offset[0];  /* set the x-value of the room */
   y+=offset[1];  /* set the y-value of the room */
   z+=offset[2];  /* set the height of the room */
   return pCoordinates=({ x,y,z });  /* save the values */
}

int * QueryCoordinates()
{
   return pCoordinates;
}

int SetCoordinates(mixed args)
{
   int x,y,z;
   mixed rels;

   if(!args)
   {
      write("SetCoordinates(): no coordinates are given.\n");
      return -1;
   }

   /* if the array is filled with one or two coordinate sets,
    * go to the function, that sets the coordinates
    */
   rels=({0,0,0});
   switch(sizeof(args))
   {
      case 1:
      {
         if(sizeof(args[0])==3)
         {
            x=args[0][0];
            y=args[0][1];
            z=args[0][2];
            break;
         }
         else
         {
            write("*** SetCoordinates(): Wrong size of coordinate set.\n");
            return -1;
            break;
         }
      }
      case 2:
      {
         if(sizeof(args[0])==3)
         {
            x=args[0][0];
            y=args[0][1];
            z=args[0][2];
         }
         else
         {
            write("SetCoordinates(): wrong size of first coordinate set.\n");
            return -1;
            break;
         }
         if(sizeof(args[1])==3) rels=args[1];
         else
         {
            write("SetCoordinates(): wrong size of second coordinate set.\n");
            return -1;
            break;
         }
         break;
      }
      case 3:
      {
         x=args[0];
         y=args[1];
         z=args[2];
         break;
      }
      default:
      {
         write(
            "wrong sets of coordinates was given.\n"
            "Syntax: SetCoordinates( ({ x,y,z }) );\n"
            "        SetCoordinates( ({ ({ x,y,z }) }) );\n"
            "        SetCoordinates( ({ ({ x,y,z }),({ x,y,z }) );\n");
         return -1;
         break;
      }
   }
   InitCoordinates(x,y,z,rels);
   return 1;
}

string pIntMap;

public string QueryIntMap() { return pIntMap; }
public string SetIntMap(string mapfile)
{
   if(mapfile)
   {
      string dir_id, dir_name;

      if(sscanf(object_name(this_object()), "/%s/%s/",
                dir_id, dir_name)==2)
      {
         switch(dir_id)
         {
            case "d":     pIntMap="/d/"+dir_name+"/doc/maps/"+mapfile+".map";
                          break;
            case "players": pIntMap="/players/"+dir_name+"/doc/maps/"+mapfile+".map";
                            break;
            default:  pIntMap="./"+mapfile+".map";
                      break;
         }
      }
   }
   return pIntMap;
}

public varargs void create(int noreplace) {
  if (!noreplace &&
      object_name()[0..8] != "/std/room" && object_name()[0..8] != "/obj/room")
    base::replace_pgm();
  base::create();
  restrictions::create();
  details::create(); /* for details */
  AddClassId(C_ROOM);
  skills::create();  // must be AFTER AddClassId
  seteuid(getuid());
  Set(P_HELP_MSG, "There is nothing special about this room.\n");
   pIntMap="/d/silvere/doc/maps/harbour.map";
  // support for new commands: - Magictcs - 21 apr 98
  AddRoomCmd("get",  "cmd_get_vitem");
  AddRoomCmd("take", "cmd_get_vitem");
  AddRoomCmd("drink","cmd_drink_vitem");
  AddRoomCmd("eat",  "cmd_eat_vitem");
}

public int id (string try_id) {
  return (norm_id(try_id) == C_ROOM) || details::id(try_id);
}

public int class_id (string try_id) {
  return norm_id(try_id) == C_ROOM;
}

public varargs int remove (int arg) { return cleaning::remove(arg); }

public int clean_up (int ref) { return cleaning::clean_up(ref); }

public mixed SetHelpMsg(mixed s) {
  return "/std/thing/description"::SetHelpMsg(s);
}

public mixed QueryHelpMsg() {
  return "/std/thing/description"::QueryHelpMsg();
}

public varargs string Long(string what)  {
  mixed rc;

  rc = what && details::GetDetail(what);
  return (pointerp(rc) ? rc[0] : rc) || "";
}

public varargs string ExaLong(string what)  {
  mixed rc;

  rc = what && details::GetDetail(what);
  return pointerp(rc) ? rc[1] : "You see nothing special.\n"+rc;
}

public varargs string Noise(string what) {
  return what && details::GetNoise(what) || "";
}

public varargs string Smell(string what) {
  return what && details::GetSmell(what) || "";
}

public varargs string Read(string what) {
  return what && details::GetReadMsg(what) || "";
}

public void init() {
  exits::init();
  skills::init();
  vwindows::init();
}

public void reset() {
  items::reset();
  vwindows::reset();
  // we need a special reset for our vitem commands - Magictcs - 21 apr 98
  vget::reset();
  vdrink::reset();
  vfood::reset();

}
