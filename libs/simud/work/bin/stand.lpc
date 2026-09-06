#include <battle.h>

string query_action_name() {
  return "Stand";
}

int main(string str) {
  if (this_player()->query_stance() == ST_STANDING)
    msg("You are already standing.");
  else
    this_player()->push_action(({1000,this_object(),this_player(),ST_ALL,0}));
  return 1;
}

void on_action(object victim, mixed param) {
  if (this_player()->query_endurance() < 1) {
    msg("You are too tired to stand back up!");
    return;
  } else if (this_player()->query_stance() == ST_STANDING) {
    msg("You are already standing.");
    return;
  }
  this_player()->change_stance(ST_STANDING);
}
