#include <saveload.h>
#include <object.h>

int on_get() {
   return MOVE_OK_FLAG;
}

string query_name() {
   return "Skill_practice";
}

object id( string s ) {
   return s == query_name()?this_object():0;
}

string skill;
int off_time;

string query_skill() {
   return skill;
}

void set_skill( string x ) {
   skill = x;
}

void on_suspend() {
   off_time = time();
}

void on_restore() {
   int time_elapsed;

   time_elapsed = time() - off_time;

   environment()->practice_skill( skill, time_elapsed / 30 );

   destruct( this_object() );
}
