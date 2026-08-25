// 24 Sept 1993 Chrisy -
//    Changed all vairables "function" to funct". MAkes MudOS hiccup :)
/* And now I'm messing with this..
 * how stupid can I be? I will add a thingie that only let immortals enter
 * the last three slots.
 * Baldrick, jan '95
 */

inherit "std/object";

#include "login_handler.h"

#define SAVE_NAME "/save/login_handler"
/* 4 days.  I hope... */
#define TIME_OUT (60*60*24*4)

string *names;
mixed *functions;
mixed *objects;
nosave string *players_on;
nosave int number_players;


void create() {
  names = ({ });
  functions = ({ });
  seteuid("Room");
  objects = ({ });
  restore_object(SAVE_NAME,1);
  players_on = ({ });
  number_players = 0;
} /* create() */

int add_login_call(string player, mixed funct, mixed obj) {
  int pos;

  if((pos = member_array(player, names)) != -1) {
    if(pointerp(funct) && pointerp(obj)) {
      if(sizeof(funct) != sizeof(obj))
        return 0;
      functions[pos] += funct;
      objects[pos] += obj;
    }
    else {
      if(pointerp(funct) || pointerp(obj))
        return 0;
      if(!functions) {
        functions = ({ });
        objects = ({ });
      }
      functions[pos] += ({ funct });
      objects[pos] += ({ obj });
    }
  }
  else {
    if(pointerp(funct) && pointerp(objects)) {
      if(sizeof(funct) != sizeof(obj))
        return 0;
      if(!functions) {
        functions += ({ });
        objects += ({ });
      }
      names += ({ player });
      functions += ({ funct });
      objects += ({ obj });
    }
    else {
      if(pointerp(funct) || pointerp(obj))
        return 0;
      names += ({ player });
      functions += ({ ({ funct }) });
      objects += ({ ({ obj }) });
    }
  }
  catch(save_object(SAVE_NAME,1));
  return 1;
} /* add_login_call() */

int remove_login_call(string player, mixed funct, mixed obj) {
  int pos, loop;

  if((pos = member_array(player, names)) == -1)
    return 0;
  if(stringp(funct) || stringp(obj)) {
    funct = ({ funct });
    obj = ({ obj });
  }
  if(stringp(funct) || stringp(obj))
    return 0;
  if(sizeof(funct) != sizeof(obj))
    return 0;
  printf("%d,  %O\n", pos, functions[pos]);
  for(loop = 0; loop < sizeof(functions[pos]); loop++) {
    int where;

    if((where = member_array(funct[pos], functions[pos])) ==
                member_array(obj[pos], objects[pos])) {
      functions[pos] = delete(functions[pos], where, 1);
      objects[pos] = delete(objects[pos], where, 1);
      loop--;
    }
  }
  if(!sizeof(functions[pos])) {
    names = delete(names, pos, 1);
    functions = delete(functions, pos, 1);
    objects = delete(objects, pos, 1);
  }
  catch(save_object(SAVE_NAME,1));
  return 1;
} /* remove_login_call() */

string *query_names() { return names; }
mixed *query_functions() { return functions; }
mixed *query_objects() { return objects; }

int player_logon(string player) {
  int pos, loop;

  if(lower_case(player) != (string)previous_object()->query_name())
    return 0;
  if((pos = member_array(player, players_on)) != -1)
    log_file("LOGIN", player+" logged in but was already on.\n");
   else
    players_on += ({ player });

  if((pos = member_array(player, names)) != -1) 
    {
    for(loop = 0; loop < sizeof(functions[pos]); loop++)
      call_out("do_call", 0, ({ functions[pos][loop], objects[pos][loop],
               player, LOGIN }) );
    }
  if((pos = member_array("all", names)) != -1) 
    {
    for(loop = 0; loop < sizeof(functions[pos]); loop++)
      call_out("do_call", 0, ({ functions[pos][loop], objects[pos][loop],
               player, LOGIN }) );
    }
} /* player_login() */

void do_call(mixed data) {
  call_other(data[1], data[0], data[2], data[3]);
} /* do_call() */

int player_logout(string player) {
  int pos;

  if((pos = member_array(player, players_on)) == -1)
    return 0;
  players_on = delete(players_on, pos, 1);
  if((pos = member_array(player, players_on)) != -1) {
    int loop;
 
    for(loop = 0; loop < sizeof(functions[pos]); loop++)
      call_out("do_call", 0, ({ functions[pos][loop], objects[pos][loop],
               player, LOGOUT }));
  }
  return 1;
} /* player_logout() */

string *query_players_on() { return players_on; }


