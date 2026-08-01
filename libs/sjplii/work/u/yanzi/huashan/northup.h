int valid_leave(object me, string dir)

{

  int sk;

  sk = (int)me->query_skill("move", 1);

  if (dir == "northup") {

    if ((int)me->query("gin") < 20 || (int)me->query("sen") < 20)

      return notify_fail("你已经太累了，休息休息再爬山吧。\n");

    if (sk < 60) {

      me->receive_damage("gin", 20);

      me->receive_damage("sen", 20);

      me->improve_skill("move", random((int)me->query("int")));

      return 1;

    }

  }

  return ::valid_leave(me, dir);

}
