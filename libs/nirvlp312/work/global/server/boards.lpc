#pragma strong_types  // Coogan, 24-Aug-01

#include <kernel.h>

#define SAVE_FILE "/save/boardserver"

inherit ACCESS;
inherit "basic/create";

private mapping boards;
private status prune_done;


int prune_board_list(string *boards);

private void save() {
  unguarded (1, #'save_object, SAVE_FILE);
}

void create() {
  set_privilege (1);
  unguarded (1, #'restore_object, SAVE_FILE);
  if (!boards) boards = m_allocate (40, 2);
  prune_done = 0;
}

// Fafnir 23-Jul-97: Do a board list cleanup at first reset(1)
// (not at create time)
void refresh() {
  if (!prune_done) {
    prune_done = 1;
    prune_board_list(0);
  }
}

void notify_change() {
  boards += 
    ([ previous_object ()->query_topic (): 
	  time (); 
	  load_name (environment (previous_object ()))
    ]);
  save ();
}

void notify_board() {
  boards +=
    ([previous_object ()->query_topic ():
	  previous_object ()->query_last_write ();
	  load_name (environment (previous_object ()))
    ]);
  save ();
}

void remove_board (string topic) {
  m_delete (boards, topic);
  save();
}

void remove_board_in(string room) {  // must be given as load_name
  mapping h;
  h = mkmapping(m_values(boards,1),m_indices(boards));
  m_delete(boards,h[room]);
  save();
}

string *query_boards() {
  m_delete (boards, 0);
  return m_indices (boards);
}

string query_environment(string board) {
  int change;
  string env;
  return boards && boards[board,1];
}

int query_last_write(string board) {
  int change;
  string env;
  return boards && boards[board];
}

// Fafnir 23-Jul-97: Board list scrubber
int prune_board_list(string *rem_boards) {
  int i;
  object res;
  string env;

  if (!rem_boards) {
    if (!boards)
      return 0;
    m_delete(boards,0);
    rem_boards = m_indices(boards);
  }
  i = 0;
  while (i<sizeof(rem_boards)) {
    if (get_eval_cost() < 300000) {
      call_out("prune_board_list",1,rem_boards[i..]);
      return -1;
    }
    env = boards[rem_boards[i],1];
    m_delete(boards,rem_boards[i]);
    if (!(catch(res = load_object(env)))) {
      if (res = present("bulletin board", res))
        boards += ([ res->query_topic() : res->query_last_write(); env ]);
    }
    i++;
  }
  save();
  return 1;
}

