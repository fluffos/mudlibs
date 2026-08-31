/* declares makros for doors 
   
####################################################################################
*/
  
#define _BEGIN\
  (str) {\
    string d, k;\
    int p;\
    object key;\
    if (!str) return 0;\
    if ((p = sscanf(str,"%s with %s",d,k))==0){\
      d = str; k = 0;\
    }

#define _WHICH\
  if (str=="door") {\
    write ("which door ?\n");\
    return 1;\
  }

#define _END\
    p = sscanf(str,"%sdoor",d);\
    if (p==1) {\
      write ("There is no "+d+" door in this room.\n");\
      return 1;\
    }\
    return 0;\
  }

/* ############################################################################### */

#define _MOVE_BEGIN \
  move (dir) { if (!dir) dir=query_verb();

#define _MOVE(_dir,_name,_query)\
    if ((dir == _dir)&&(_query())) {\
      write("You crashed against the "+_name+"!\n"); return 1; }

#define _MOVE_END return ::move(dir); }

/* ############################################################################### */

#define _OPEN(_id,_name,_query,_set,_room)\
  if (_id) {\
    switch (_query()) {\
      case 0 : write("The "+_name+" is already open.\n"); break;\
      case 1 : write("The "+_name+" opens.\n");\
        say(capitalize(this_player()->query_name()) + " opens the "+_name+".\n");\
        tell_room(_room,capitalize(this_player()->query_name()) \
                + " opens the "+_name+".\n");\
        _set(0); break;\
      case 2 : write("The "+_name+" is locked.\n"); break;\
      default: write("Door in unknown status."+query()+"\n");\
    } return 1; }

/* ############################################################################### */

#define _CLOSE(_id,_name,_query,_set,_room)\
 if (_id) {\
   if (_query()) write("The "+_name+" is already closed.\n");\
    else { write("The "+_name+" closes.\n");\
      say(capitalize(this_player()->query_name()) + " closes the "+_name+".\n");\
      tell_room(_room,capitalize(this_player()->query_name()) \
              + " closes the "+_name+".\n");\
      _set(1);\
    }  return 1; }

#define _UNLOCK(_id,_name,_type,_code,_query,_set,_room)\
  if (_id) {\
    if (!k) write ("What will you use to unlock the door?\n");\
    else if (k=="key") write ("Which key will you use to unlock the "+_name+"?\n");\
    else if (k== _type+" key") {\
      if ((key = present(_type+" key",this_player())) && (key->query_code() == _code)) {\
        switch (_query()) {\
          case 0 : write("The "+_name+" is already open.\n"); break;\
          case 1 : write("The "+_name+" is already unlocked.\n"); break;\
          case 2 : write("You unlock the "+_name+".\n");\
            say(capitalize(this_player()->query_name()) \
                + " unlocks the "+_name+" with a "+_type+" key.\n");\
            tell_room(_room,capitalize(this_player()->query_name()) \
                + " unlocks the "+_name+" with a "+_type+" key.\n");\
            _set(1); break; } \
        } else write("You have not the "+_type+" key!\n");\
    } else write ("The key doesn't fit into the lock\n");\
  return 1;\
  }
  
#define _LOCK(_id,_name,_type,_code,_query,_set,_room)\
  if (_id) {\
    if (!k) write ("What will you use to lock the door?\n");\
    else if (k=="key") write ("Which key will you use to lock the "+_name+"?\n");\
    else if (k== _type +" key") {\
      if ((key = present(_type +" key",this_player())) && (key->query_code() == _code)) {\
        if (_query()==2)  write("The "+_name+" is already locked.\n");\
        else { write("You lock the "+_name+".\n");\
          say(capitalize(this_player()->query_name()) \
              + " locks the "+_name+" with a "+_type+" key.\n");\
          tell_room(_room,capitalize(this_player()->query_name()) \
                + " locks the "+_name+" with a "+_type+" key.\n");\
          _set(2); }\
      } else write("You have not the "+_type+" key!\n");\
    } else write ("The key doesn't fit into the lock\n");\
    return 1;\
  }

#define _NO_LOCK(_id,_name)\
  if (_id) { write ("This "+_name+" door has no lock.\n"); return 1; }
