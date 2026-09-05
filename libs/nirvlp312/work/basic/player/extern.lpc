/*
 * extern.c
 * lfuns for using extern_data in the player object
 * Documentation in /doc/class/basic/extern_data
 *
 * Rumplemintz
 */

private mapping extern_data;

void set_extern_data(mixed owner, string name, mixed data);
void change_extern_data(mixed owner, string name, closure changes, mixed args);
void remove_extern_data(mixed owner, string name);
mixed query_extern_data(mixed owner, string name);

void set_extern_data(mixed owner, string name, mixed data) {
  if (!intp(owner) && !stringp(owner)) return;
  if (!intp(owner) && !stringp(name)) return;
  if (objectp(data)) return;
  if (!data) return remove_extern_data(owner, name);
  if (mappingp(data))
    data = copy(data);
  else if (pointerp(data))
    data = data[0..];
  if (!extern_data)
    extern_data = ([owner: ([name: data])]);
  else if (!extern_data[owner])
    extern_data += ([owner: ([name: data])]);
  else
    extern_data[owner][name] = data;
}

varargs void change_extern_data(mixed owner, string name, closure changes,
                                mixed args) {
  if (!intp(owner) && !stringp(owner)) return;
  if (!intp(owner) && !stringp(name)) return;
  if (!closurep(changes)) return;
  if (mappingp(args))
    args = copy(args);
  else if (pointerp(args))
    args = args[0..];
  if (!extern_data)
    extern_data = ([owner: ([name: 0])]);
  else if (!extern_data[owner])
    extern_data += ([owner: ([name: 0])]);
  extern_data[owner][name] = apply(changes, extern_data[owner][name], args);
}

void remove_extern_data(mixed owner, string name) {
  if (!extern_data || !extern_data[owner]) return;
  m_delete(extern_data[owner], name);
  if (!sizeof(m_indices(extern_data[owner])))
    m_delete(extern_data, owner);
  if (!sizeof(m_indices(extern_data)))
    extern_data = 0;
}

mixed query_extern_data(mixed owner, string name) {
  mixed data;

  data = extern_data && extern_data[owner] && extern_data[owner][name];
  if (!data)
    return 0;
  else if (mappingp(data))
    return copy(data);
  else if (pointerp(data))
    return data[0..];
  else return data;
}
