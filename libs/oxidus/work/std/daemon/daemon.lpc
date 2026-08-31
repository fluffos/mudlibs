// /std/daemon/daemon.c
// Base daemon inheritible
//
// Created:     2022/08/23: Gesslar
// Last Change: 2022/08/23: Gesslar
//
// 2022/08/23: Gesslar - Created

inherit STD_OBJECT;
inherit EXT_PERSIST_DATA;

void create(mixed _args...) {
  setup_chain();
}

void heart_beat() {
  evaluate_heart_beat();
}

int is_daemon() {
  return 1;
}
