#include <magic.h>
#include <battle.h>

string query_name();
int query_must_hold_target();
int query_level();
int query_cost();
string query_type();
int query_readiness_requirement();
int query_num_steps();
string query_step_skill(mixed param);
string query_step_msg(mapping param);
string query_fail_msg(mapping param);
int valid_target(mapping param);
string validate_params(mapping param);
varargs int on_cast(mapping param);
