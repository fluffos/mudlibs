int valid_bind(object binder, object old_owner, object new_owner) {
  if(binder == find_object(SEFUN_OBJ))
    return 1;

  if(check_permission("file", base_name(old_owner), PERM_BIND) &&
     check_permission("file", base_name(new_owner), PERM_BIND) )
     return 1;

  return old_owner == binder;
}
