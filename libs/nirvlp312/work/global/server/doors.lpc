#pragma strong_types
#pragma no_shadow

#define DEFAULT_TYPE   "door"

inherit "basic/create";

private mapping doors;  

/*
  This mapping will look as follows: 

  ([ door_room_file_name : 
      ([ door_object : destination_function_or_string; type,
         ...
      ]),
     ...
  ])
*/

void create() {
  if (clonep(this_object())) 
    return destruct(this_object());
  if (!(doors = "/etc/shared"->query_global("doors"))) {
    doors = m_allocate(10,1);
    "/etc/shared"->set_global("doors",doors);
  }
}

status prevent_move() { return 1; }

#define DEBUG
#ifdef DEBUG
mapping query_doors () { return doors; }
#endif

private string normal_file_name(string name) {
  // handling of path abbreviations added, Coogan, 18-Jun-01
  name = load_name(name);  // get rid of leading '/'
  if (name[0..1]=="./")
    name=implode(explode(object_name(previous_object()),"/")[0..<2],"/") +
                                                                name[1..];
  else if (name[0..2]=="../")
    name=implode(explode(object_name(previous_object()),"/")[0..<3],"/") +
                                                                name[2..];
  return name;
}

varargs void add_door(object door, mixed to, string type) {
  mixed from, ob;
  if (!door || !(from=environment(door)) || !to) 
    return;
  from = object_name(from);

  // handle path abbreviations, Coogan, 18-Jun-01
  if (stringp(to) && to[0]=='.') {
    if (to[0..1] == "./")
      to=implode(explode(from,"/")[0..<2],"/") + to[1..];
    else if (to[0..2] == "../")
      to=implode(explode(from,"/")[0..<3],"/") + to[2..];
  }

  // normalise the 'to' argument
  if (objectp(to)) {
    to = object_name(to);
  }
  else if (stringp(to)) {
    to = normal_file_name(to);
  }
  else if (closurep(to)) {
    ;  // do nothing here
  }
  else {
    raise_error("Illegal value of argument 2 for add_door()\n");
  }

  // the type argument
  type = type || DEFAULT_TYPE;

  if (!member(doors, from))
    m_add(doors, from, ([:2]));

  m_add(doors[from], door, to, type);

  "/etc/shared"->set_global("doors", doors);
}

// added argument type to have the possibility for a window and
// a door between two rooms, Coogan, 25-Feb-2006
varargs object get_door(mixed from, mixed to, string type) {
  mixed tmp, dest;
  int i;
  
  if (!from || !to) 
    return 0;

  // from
  if (objectp(from)) 
    from = object_name(from);
  else if (stringp(from)) 
    from = normal_file_name(from);
  else
    raise_error("Illegal type of argument 1 in get_door()\n");

  // to
  if (objectp(to)) 
    to = object_name(to);
  else if (stringp(to))
    to = normal_file_name(to);
  else
    raise_error("Illegal type of argument 2 in get_door()\n");

  // type
  type = type || DEFAULT_TYPE;

  if (!member(doors, from))
    return 0;

  for (i = sizeof(tmp = m_indices(doors[from])); i--; ) {
    dest = funcall(doors[from][tmp[i]]);
    if (dest && stringp(dest))
      catch((dest = load_object(dest)));
    if (!dest || !objectp(dest))
      continue;
    if (object_name(dest) == to &&
        doors[from][tmp[i],1] == type)
      return tmp[i];
  }
  return 0;  // Coogan, 24-Mar-2011
}

object get_other_door(object door) {
  mixed to, from;

  if (!door || !(from = environment(door))) 
    return 0;

  from = object_name(from);

  if (!member(doors, from))
    return 0;

  if (stringp(to = funcall(doors[from][door])) && to) {
    to = load_object(to);
  }

  if (to = (to && object_name(to)))
    return get_door(to, from, doors[from][door,1]);
}

void remove_door(object door) {
  mixed from, to;
  int i;

  if (!door || !(from = environment(door))) 
    return;

  from = object_name(from);

  if (!member(doors, from))
    return;

  m_delete(doors[from], door);
  "/etc/shared"->set_global("doors", doors);
}

object get_destination(object door) {
  mixed from, to;

  if (!door || !(from = environment(door))) 
    return 0;

  from = object_name(from);

  if (!member(doors, from))
    return 0;

  to = funcall(doors[from][door]);
  if (to && stringp(to))
    to = load_object(to);
  return to;
}

private void collect_doors(string room, mapping ignore, 
                           mapping destinations, mapping collect) {
  collect += mkmapping(m_indices(destinations));
}

object * get_all_doors() {
  mixed h;
  walk_mapping(doors, #'collect_doors, h = ([]));
  return h;
}

