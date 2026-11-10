/* This function comes from the Nightmare master object. */
//object unguarded_ob;

varargs mixed apply_unguarded(function f, int local) {
  object previous_unguarded; 
  string err;
  mixed val;

  if (base_name(previous_object()) != SEFUN_OBJ) {
    error("Illegal unguarded apply.");  
    return 0;
  }
  previous_unguarded = unguarded_ob;
  if (local)
    unguarded_ob = master();
  else
    unguarded_ob = previous_object(1);
  err = catch(val = (mixed)(*f)());
  unguarded_ob = previous_unguarded;
  if (stringp(err)) {
    error(err);
  }
  return val;
}

int check_permission(string type, string path, int perm) {
  if(objectp(unguarded_ob))
    return ACCESS_H -> has_permission(unguarded_ob, type, path, perm);
  else
    return ACCESS_H -> has_guarded_access(type, path, perm);
}
