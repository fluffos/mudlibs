/*
 * (c) Vertebraker @ some point.
 */
object
loadObject(mixed a)
{
    if(objectp(a)) return a;

    else if(stringp(a))
    {
      object obj;

      if((obj = find_object(a)) && objectp(obj))
        return obj;
      else if(catch((mixed)a->load_me()))
        return 0;
      else
        return find_object(a);
    }

    else
      return 0;
}
