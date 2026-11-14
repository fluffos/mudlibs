// privs need to be better than just adminp()
object query_snoop(object ob) {
  // this is where we can disallow non-admin from seeing admin snooping...
  object sob;
  if(!ACCESS_H -> has_guarded_access("efun", "query_snoop", PERM_EXECUTE))
    return 0;

  sob = efun::query_snoop(ob);

  if(adminp(sob) && !sizeof(filter(previous_object(-1), (: adminp($1) :))))
      return 0;

  return sob;
}

object query_snooping(object ob) {
  if(!ACCESS_H -> has_guarded_access("efun", "query_snooping", PERM_EXECUTE))
    return 0;

  if(adminp(ob) && !sizeof(filter(previous_object(-1), (: adminp($1) :))))
    return 0;

  return efun::query_snooping(ob);
}

varargs object snoop(object snooper, object snoopee) {
  if(!ACCESS_H -> has_guarded_access("efun", "snoop", PERM_EXECUTE))
    return 0;

  if(!objectp(snoopee))
    return efun::snoop(snooper);
  else
    return efun::snoop(snooper, snoopee);
}
