//  Call_other define to retain compat.
//  Will load object if not found.

varargs mixed call_other(mixed ob, string fun, mixed arg1, mixed arg2, mixed arg3, mixed arg4, mixed arg5, mixed arg6) {
  string err;
  
  if(!ob) {
    error("* Error in call_other, 0 passed as first arg.");
    return 0;
  }
  if(stringp(ob)) {
    if(!find_object(ob))
      ob = load_object(ob);
  }
  else if(pointerp(ob))
    ob = map_array(ob, (: ((stringp($1))?(load_object($1)):($1)) :));
  if(arg6)
    return efun::call_other(ob, fun, arg1, arg2, arg3, arg4, arg5, arg6);
  if(arg5)
    return efun::call_other(ob, fun, arg1, arg2, arg3, arg4, arg5);
  if(arg4)
    return efun::call_other(ob, fun, arg1, arg2, arg3, arg4);
  if(arg3)
    return efun::call_other(ob, fun, arg1, arg2, arg3);
  if(arg2)
    return efun::call_other(ob, fun, arg1, arg2);
  if(arg1)
    return efun::call_other(ob, fun, arg1);
  return efun::call_other(ob, fun);
}
