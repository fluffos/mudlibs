string base_name(mixed ob) {
  string name, t;

  if(stringp(ob))
    name = ob;
  else if(objectp(ob))
    name = file_name(ob);
  else
    return 0;

  if(sscanf(name, "%s#%s", name, t) == 2)
    return name;

  return name;
}
