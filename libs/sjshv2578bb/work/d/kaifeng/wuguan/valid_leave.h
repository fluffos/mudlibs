int valid_leave(object who, string dir) {
  object where = this_object();


  if (dir == where->query("can_leave"))
    return ::valid_leave(who, dir);

  //
  if (who->query("club") == where->query("clubb"))
    //
    return ::valid_leave(who, dir);


  //
  if (who->query_temp("tiguan") == where)
    return ::valid_leave(who, dir);
  return notify_fail("暂不待客。\n");

}
