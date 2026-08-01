// nongtian-lu.h
// by augx@sj  9/10/2001
// powerd by augx@sj  10/12/2001

#define ANSI_LEFT	"[D"
#define ANSI_RIGHT	"[C"
#define ANSI_UP		"[A"
#define ANSI_DOWN	"[B"

#define ANSI_LEFT_LINE		"[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D"
nosave string ANSI_RIGHT_LINE = "[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C";
nosave string SPACE_LINE = "     ";

void init() {
  add_action("do_look", "look");
  this_player()->delete_temp("look_sign");
}

void write_line(string v) {
  int x = random(20);
  write(ANSI_RIGHT_LINE[0..(x * 3 - 1)]);
  write(v[x..<1]);
  write(ANSI_LEFT_LINE);
  write(v[0..(x - 1)]);
  write(ANSI_RIGHT_LINE[x * 3..59]);
}

void remove_busy(object me) {
  if (me) me->delete_temp("sign_busy");
}

int do_look(string arg) {
  object me = this_player();
  string *v0, *v1, *v2, *v3;
  string s;
  int *arrows = ({ 0, 1, 2, 3 });
  int *arrows2 = ({ 0, 1, 2, 3 });
  int *lines = ({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
  int i, j, k, a, b, y, y2;

  if (arg != "sign") return 0;
  if (me->query_temp("sign_busy")) {
    tell_object(me, "你刚才难道没有看清楚吗？\n");
    return 1;
  }

  arrows[0] = arrows2[random(4)]; arrows2 -= ({ arrows[0] });
  arrows[1] = arrows2[random(3)]; arrows2 -= ({ arrows[1] });
  arrows[2] = arrows2[random(2)]; arrows2 -= ({ arrows[2] });
  arrows[3] = arrows2[0];

  j = (int)me->query_temp("nongtian1");
  if (j < 0) j = 0;
  else if (j > 3) j = 3;
  if (j == arrows[0]) j = 0;
  else if (j == arrows[1]) j = 1;
  else if (j == arrows[2]) j = 2;
  else j = 3;

  i = random((int)query("signs"));
  s = read_file(sprintf(__DIR__ "signs/sign%d-%d.txt", arrows[0], i));
  if (!stringp(s)) { tell_object(me, "系统过忙，请稍后再试！\n"); return 1; }
  v0 = explode(s, "\n");

  i = random((int)query("signs"));
  s = read_file(sprintf(__DIR__ "signs/sign%d-%d.txt", arrows[1], i));
  if (!stringp(s)) { tell_object(me, "系统过忙，请稍后再试！\n"); return 1; }
  v1 = explode(s, "\n");

  i = random((int)query("signs"));
  s = read_file(sprintf(__DIR__ "signs/sign%d-%d.txt", arrows[2], i));
  if (!stringp(s)) { tell_object(me, "系统过忙，请稍后再试！\n"); return 1; }
  v2 = explode(s, "\n");

  i = random((int)query("signs"));
  s = read_file(sprintf(__DIR__ "signs/sign%d-%d.txt", arrows[3], i));
  if (!stringp(s)) { tell_object(me, "系统过忙，请稍后再试！\n"); return 1; }
  v3 = explode(s, "\n");

  if (sizeof(v0) < 10 || sizeof(v1) < 10 || sizeof(v2) < 10 || sizeof(v3) < 10) {
    tell_object(me, "系统过忙，请稍后再试！\n");
    return 1;
  }

  arrows[0] = random(3);
  arrows[1] = random(2);
  arrows[2] = random(3);
  arrows[3] = random(2);

  y = 0;
  k = j;
  a = random(100); b = 50;
  if (a < b)
    tell_object(me, "请注意第" + CHINESE_D->chinese_number(j + 1) + "个箭头：\n");
  else
    tell_object(me, "请注意下列箭头：\n");
  for (i = 0; i < 10; i++) {
    y2 = lines[random(10 - i)];
    lines -= ({ y2 });
    if (y2 < y)
      for (j = 0; j < (y - y2); j++) write(ANSI_UP);
    else
      for (j = 0; j < (y2 - y); j++) write("\n");
    y = y2;

    write(" ");
    if (a < 50) {
      write(SPACE_LINE[0..arrows[0]]);
      write_line(v0[y]);
      write(SPACE_LINE[0..arrows[1]]);
      write_line(v1[y]);
      write(SPACE_LINE[0..arrows[2]]);
      write_line(v2[y]);
      write(SPACE_LINE[0..arrows[3]]);
      write_line(v3[y]);
    } else {
      switch (k) {
        case 0: write_line(v0[y]); break;
        case 1: write_line(v1[y]); break;
        case 2: write_line(v2[y]); break;
        case 3: write_line(v3[y]); break;
      }
    }

    y++;
    write("\n");
  }
  for (j = 0; j < (10 - y); j++) write("\n");

  me->set_temp("look_sign", 1);
  if (!wizardp(me))
    me->set_temp("sign_busy", 1);
  call_out("remove_busy", 2, me);
  return 1;
}

int go_die(object me) {
  object room;
  message_vision("\n$N越走越累，最终竟然发作自己又走回到入口......\n\n", me);
  room = find_object(__DIR__ "nongtian0");
  if (room) me->move(room);

  if (random(9) == 3) {
    message_vision(RED "\n$N体力不支，倒在地上，再也起不来了！\n" NOR, me);
    me->set_temp("last_damage_from", "在农田中迷路脱力");
    me->die();
  } else {
    message_vision(HIR "\n$N走的晕头转向，最后竟然晕了过去！\n" NOR, me);
    me->unconcious();
  }

  return 0;
}

int valid_leave(object me, string dir) {
  int i;
  if (userp(me) && (dir == "east" || dir == "south" || dir == "west" || dir == "north")) {
    if (!me->query_temp("look_sign")) return notify_fail("你走了半天，发现自己又回到了原处。\n");
    i = (int)me->query_temp("nongtian1");
    if (i < 0) i = 0;
    else if (i > 3) i = 3;
    switch (i) {
      case 0: if (dir != "east") return go_die(me); break;
      case 1: if (dir != "south") return go_die(me); break;
      case 2: if (dir != "west") return go_die(me); break;
      case 3: if (dir != "north") return go_die(me); break;
    }
  }
  return ::valid_leave(me, dir);
}
