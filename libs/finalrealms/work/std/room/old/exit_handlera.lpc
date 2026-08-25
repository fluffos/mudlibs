//External exit_handler for room.c...  should make it less "fat"
//      room.c references these functions below [Piper 12/24/95]

#define ROOM_HAND "/obj/handlers/room_handler"
#define LOCK_HAND "/obj/handlers/lock_handler"

#include "door.h"
#include "room.h"


string expand_alias(mixed *aliases,string str)
{
  int i;
 
  if (!aliases)
    return str;
 
  if ((i=member_array(str,aliases))==-1)
    return str;
 
  if (i%2)
    return aliases[i-1];
  return str;
} /* expand_alias() */

string expand_direc(string str)
{
  string s1,s2;
  
  if(sscanf(str,"%s %s",s1,s2) == 2)  return s1;
  return str;
}  /* expand_direc() */

varargs mixed* add_exit(mapping door_control, mapping exit_map,
                       mixed *dest_other, string *dest_direc,
                       object *hidden_objects,string direc,
                       mixed dest, string type, string material)
{
  mixed *stuff;
  int i;
  string exit_string, 
       short_exit_string;

  if(!material) {
   switch(type) {
    case "gate" :
      material = "metal";
      break;
    case "door" :
      material = "wood";
      break;
    default :
      material = "unknown";
      break; 
   }
  }

  if(!exit_map) 
    exit_map = ([ ]);
  
  exit_map[direc] = ({ dest, type, material, direc });
  
  if(member_array(direc,dest_other) != -1)
      return ({ });

  stuff = ({dest}) +ROOM_HAND->query_exit_type(type,direc);


  dest_other += ({ direc,stuff });
  dest_direc += ({ expand_direc(direc) });
  exit_string = 0;
  short_exit_string = 0;
  if((stuff = (mixed)ROOM_HAND->query_door_type(type,direc,dest)))
  {
//  door_control[direc] = ({ clone_object(DOOR_OBJECT) });
//  door_control[direc][0]->setup_door(direc,this_object(),dest,stuff);
//  hidden_objects += ({ door_control[direc][0] });
    door_control[dest] = direc;
  }

  return ({ door_control,exit_map,dest_other,dest_direc,hidden_objects });
}

mixed* modify_exit(mapping door_control, mapping doors_in,
                mixed *dest_other, mixed *hidden_objects,
                string direc, mixed *data)
{
  int i, j;
  if ((i=member_array(direc, dest_other)) == -1)
          return 0;
 
  for (j=0;j<sizeof(data);j+=2)
    switch (lower_case(data[j])) {
      case "message" :
        dest_other[i+1][ROOM_MESS] = data[j+1];
        break;
      case "obvious" :
        dest_other[i+1][ROOM_OBV] = data[j+1];
        break;
      case "function" :
        dest_other[i+1][ROOM_FUNC] = data[j+1];
        break;
      case "size" :
        dest_other[i+1][ROOM_SIZE] = data[j+1];
        break;
      case "enter" :
        dest_other[i+1][ROOM_ENTER] = data[j+1];
        break;
      case "dest" :
        dest_other[i+1][ROOM_DEST] = data[j+1];
        break;
//    case "open" :
//      if (door_control[direc])
//        door_control[direc][0]->set_open(data[j+1]);
//      break;
//    case "key" :
//      if (door_control[direc])
//        door_control[direc][0]->set_key_prop(data[j+1]);
//      break;
//    case "other" :
//      if (door_control[direc])
//        door_control[direc][0]->set_other_id(data[j+1]);
//      break;
//    case "open desc" :
//      if (door_control[direc])
//        door_control[direc][0]->set_open_desc(data[j+1]);
//      break;
//    case "close desc" :
//      if (door_control[direc])
//        door_control[direc][0]->set_close_desc(data[j+1]);
//      break;
//    case "undoor" :
//      if (door_control[direc]) {
//        door_control[direc][0]->go_away();
//        hidden_objects = hidden_objects - ({ door_control[direc][0] });
//      }
//      door_control = m_delete(door_control, direc);
//      break;
    }
 
  return ({ door_control,doors_in,dest_other,hidden_objects });
} /* modify_exit() */

// remove_exit (check "undoor" above.. this is easier... go figure) [Piper]

mixed* remove_exit(mapping door_control,mapping doors_in,
       mapping exit_map,mixed *dest_other, mixed *dest_direc,
       mixed *hidden_objects,string direc)
{
  int i;
  string exit_string,
       short_exit_string;
  if (!dest_other)
    dest_other = ({ });
  if ((i=member_array(direc, dest_other)) == -1)
    return 0;
  dest_other = delete(dest_other, i, 2);
  dest_direc = delete(dest_direc, i/2, 1);
  if (door_control[direc]) {
    door_control[direc][0]->go_away();
    hidden_objects = hidden_objects - ({ door_control[direc][0] });
  }
  door_control = m_delete(door_control, direc);
  exit_map = m_delete(exit_map, direc);
  short_exit_string = 0;
  exit_string = 0;

  return ({ door_control,doors_in,exit_map,dest_other,
            dest_direc,hidden_objects });
} /* remove_exit() */

mixed *query_size(mixed *dest_other, string direc, object room_ob)
{
   int i;
 
  if ((i=member_array(direc, dest_other))==-1)
    return 0;
  if (stringp(dest_other[i+1][ROOM_SIZE]))
  {   
    i=call_other(room_ob, dest_other[i+1][ROOM_SIZE]); 
         return 0;
  }
 if (pointerp(dest_other[i+1][ROOM_SIZE]))
   {
   i = call_other(dest_other[i+1][ROOM_SIZE][0],
                      dest_other[i+1][ROOM_SIZE][1]);
       return 0;
  }
  return dest_other[i+1][ROOM_SIZE];
} /* query_size() */

int do_exit_command(mapping door_control,mapping door_locks,
                    mapping exit_map,mixed *dest_direc,
                    mixed *dest_other, mixed *aliases,
                    string str, mixed verb, object ob,
                    object foll, object room_ob)
{
  string special_mess, closed;
   int i,lk;
  mixed zip;
   int old_call_out;
 
  if (!verb)
    verb = query_verb();
  else {
    if (pointerp(verb)) {
      special_mess = verb[1];
      verb = verb[0];
    }
    if (!sscanf(verb, "%s %s", verb, str) !=2)
      str = "";
  }
  if (!ob)
    ob = this_player();
  if ((i=member_array(verb,dest_direc))==-1)
    if ((i=member_array(verb, aliases)) == -1)
      return 0;
    else
      if ((i=member_array(aliases[i-1], dest_direc)) == -1)
        return 0;
 
/* ok must be two command exit */
  if (dest_direc[i] != dest_other[i*2]) {
    string s1,s2;
    int j;
 
    sscanf(dest_other[i*2],"%s %s",s1,s2);
    str = expand_alias(aliases,str);
    if (s2 != str) {
      zip = dest_direc[i+1..sizeof(dest_direc)];
      while (1)
        if ((j = member_array(verb, zip)) != -1) {
          i += j+1;
          sscanf(dest_other[i*2],"%s %s", s1, s2);
          if (str == s2)
            break;
          zip = zip[j+1..sizeof(zip)];
        } else
          return 0;
    }
  }
//  Adding my lock checking method here  [Piper 12/24/95]
 
if((LOCK_HAND->query_lock_index(door_locks,dest_direc[i]) == 1)&&
   (LOCK_HAND->query_lock_str(door_locks,dest_direc[i]) != 0))
{
  LOCK_HAND->lock_messages(exit_map,dest_direc[i]);
  return(1);
}
 
/* First check for lockedness of doors etc */
  if (zip = door_control[dest_other[i*2]]) {
    if (zip[0]->query_locked()) /* Locked...  We auto-unlock, if they have the k
ey */
      if (!zip[0]->moveing_unlock(ob))
        return 0;
    if (!zip[0]->query_open()) { /* Closed open it and close it after us. */
      if (!zip[0]->moveing_open(ob))
        return 0;
      closed = zip[0];
    }
  }
  if (dest_other[i*2+1][ROOM_FUNC])
    if (stringp(dest_other[i*2+1][ROOM_FUNC])) {
     if (!call_other(room_ob, dest_other[i*2+1][ROOM_FUNC],
          str, ob, special_mess))
        return 0;
    } else {
      if (pointerp(dest_other[i*2+1][ROOM_FUNC]))
        if (!call_other(dest_other[i*2+1][ROOM_FUNC][0],
                        dest_other[i*2+1][ROOM_FUNC][1], ob, special_mess))
          return 0;
    }
 
  if (!special_mess)
/*
 {
          special_mess = room_exits[exit_index + ROOM_MESS];
 
         if (!special_mess)
          {
              special_mess = ROOM_HAND->exit_message(full_exit_name);
          }
      }
*/
  catch( zip = (int)ob->move_player(dest_other[i*2], dest_other[i*2+1][ROOM_DEST],
                                   dest_other[i*2+1][ROOM_MESS], foll,
                                   dest_other[i*2+1][ROOM_ENTER]));
  else
    catch( zip = (int)ob->move_player(dest_other[i*2], dest_other[i*2+1][ROOM_DEST],
                                   special_mess, foll,
                                   dest_other[i*2+1][ROOM_ENTER]));
  if (closed)
    closed->moveing_close(ob);
 
  return zip;
} /* do_exit_command() */

//  Those "Obvious exits:" messages [Piper 1/5/96]

/*
 * Yes folks. This creates that really stupid obvious exits message you keep
 * getting. Hope you really hate it.
 * specialy changed to handle stupid things. If you can figure it out I
 * will shake your hand. Look for docs coming soon to a universe near you.
 */
string query_dirs_string(mixed *dest_direc, mixed *dest_other,
                         object room_ob, string exit_color)
{
  string ret, *dirs;
  string exit_string;
  int no, i, nostore, size;
 
 if (!dest_direc || sizeof(dest_direc)==0)
    dest_direc = ({ });
  dirs = ({ });
  size = sizeof(dest_other);
  for (i=0; i < size; i+=2)
    if (dest_other[i+1][ROOM_OBV]) {
      no++;
      dirs += ({ dest_other[i] });
    } else if (stringp(dest_other[i+1][ROOM_OBV])) {
      nostore = 1;
       if (call_other(room_ob,dest_other[i+1][ROOM_OBV]))
        dirs += ({ dest_other[i] });
    } else if (pointerp(dest_other[i+1][ROOM_OBV])) {
      nostore = 1;
      if (call_other(dest_other[i+1][ROOM_OBV][0],dest_other[i+1][ROOM_OBV][1]))
 
        dirs += ({ dest_other[i] });
    }
  if (sizeof(dirs)==0) {
    if (nostore)
      return exit_color+"There are no obvious exits.%^RESET%^";
    exit_string = exit_color+"There are no obvious exits.%^RESET%^";
    return exit_string;
  }
  if (sizeof(dirs)==1) {
    if (nostore)
      return exit_color+"There is one obvious exit: "+dirs[0]+".%^RESET%^";
    exit_string = exit_color+"There is one obvious exit: "+dirs[0]+".%^RESET%^";
 
    return exit_string;
  }
  ret = " and "+dirs[sizeof(dirs)-1]+".";
  dirs = delete(dirs,sizeof(dirs)-1, 1);
  if (nostore)
    return exit_color+"There are "+query_num(sizeof(dirs)+1, 0)+
           " obvious exits : "+implode(dirs,", ")+ret+"%^RESET%^";
  exit_string = exit_color+"There are "+query_num(sizeof(dirs)+1, 0)+
                " obvious exits : "+implode(dirs,", ")+ret+"%^RESET%^";
  return exit_string;
} /* query_dirs_string() */

