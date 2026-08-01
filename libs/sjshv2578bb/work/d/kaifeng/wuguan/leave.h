int valid_leave(object who, string dir) {
  who = this_player();

  if (dir == "north") {
    return notify_fail("想踢馆嘛?\n");
  }
  if (dir == "hell") {
    return notify_fail("别乱跑。\n");
  }
  return 1;
}
