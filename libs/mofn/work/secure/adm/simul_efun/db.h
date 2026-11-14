int db_close(int handle) {
  if(base_name(PO) == DB_H ||
     ACCESS_H -> has_guarded_access("efun", "db_close", PERM_EXECUTE))
    return efun::db_close(handle);
  return 0;
}

int db_commit(int handle) {
  if(base_name(PO) == DB_H ||
     ACCESS_H -> has_guarded_access("efun", "db_commit", PERM_EXECUTE))
    return efun::db_commit(handle);
  return 0;
}

varargs int db_connect(string host, string database, string name, string password) {
  if(base_name(PO) == DB_H ||
     ACCESS_H -> has_guarded_access("efun", "db_connect", PERM_EXECUTE))
    if(stringp(password))
      return efun::db_connect(host, database, name, password);
    else if(stringp(name))
      return efun::db_connect(host, database, name);
    else
      return efun::db_connect(host, database);

  return 0;
}

mixed db_exec(int handle, string sql) {
  if(base_name(PO) == DB_H ||
     ACCESS_H -> has_guarded_access("efun", "db_exec", PERM_EXECUTE))
    return efun::db_exec(handle, sql);
  return "Invalid access.\n";
}

mixed db_fetch(int handle, int row) {
  if(base_name(PO) == DB_H ||
     ACCESS_H -> has_guarded_access("efun", "db_fetch", PERM_EXECUTE))
    return efun::db_fetch(handle, row);
  return ({ });
}

int db_rollback(int handle) {
  if(base_name(PO) == DB_H ||
     ACCESS_H -> has_guarded_access("efun", "db_rollback", PERM_EXECUTE))
    return efun::db_rollback(handle);
  return 0;
}
