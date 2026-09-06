#define SK_DAEMON "/daemon/skill"
#include <magic.h>
#include <const.h>

string query_action_name() {
  return "Teach";
}

int main(string arg) {
  string lesson, name;
  object student;
  if (!stringp(arg) || sscanf(arg,"%s to %s",lesson,name) != 2) {
    msg("~CWRNSyntax:~CDEF teach ~[060skill~CDEF to ~[060student~CDEF.");
    return 1;
  }

  if( name == "me" || name == "myself" )
     name = this_player()->query_name();
  if (!find_living( name ) )
     return notify_fail( "Teach whom?\n" );

  if (this_player()->query_in_combat()) {
    msg("~CWRNYou are too busy fighting!~CDEF");
    return 1;
  }

  lesson = lower_case(lesson);
  student = present(name,environment(this_player()));

  if (!student)
     return notify_fail( "Teach whom?\n" );

  // convert abbreviated skill names and make sure the stupid ability actually
  // exists in the first place - yeesh, can't believe that test was never
  // added :P
  if( !SK_DAEMON->query_skill_exists(lesson) ) {
     lesson = SK_DAEMON->query_skill_name(lesson);
	 if( !lesson )
        return notify_fail( "There is no such skill.\n" );
	 else
        msg( "Teaching ~CCOM"+lesson+"~CDEF." );
  }

  set_actor(this_player());
  set_target(student);
  set_listener(this_player());

  if (student == this_player()) {
    if (this_player()->query_level() < ADMLEVEL) {
      msg("~CWRNYou cannot teach yourself.~CDEF");
      return 1;
    }
    this_player()->msg_local("~CACT~Name ~verbbegin to concentrate strongly.~CDEF");
    this_player()->push_action( ({ 1000,
                                   this_object(),
                                   student,
                                   ST_STANDING,
                                   lesson }) );
    return 1;
  }

  if (!student->query_is_player()) {
    msg("~CWRNYou may only teach other players!~CDEF");
    return 1;
  }
  if (student->query_in_combat()) {
    msg("~CWRN~Targ is too busy fighting to pay attention!~CDEF");
    return 1;
  }
  if (this_player()->query_stat("int") < 10) {
    msg("~CWRNYou are not intelligent enough to teach anything.~CDEF");
    return 1;
  }

  if (this_player()->query_skill(lesson) < 30 && this_player()->query_level() < WIZLEVEL) {
    msg("~CWRNYou don't know that skill well enough to teach it.~CDEF");
    return 1;
  }

  if (member(student->query_skills(), lesson)) {
    msg("~CWRN~Targ already ~vertknow that skill.~CDEF");
    return 1;
  }

  this_player()->msg_local("~CACT~Name ~verbbegin to teach ~targ a new skill~CDEF");
  this_player()->push_action( ({ 2000,
                                 this_object(),
                                 student,
                                 ST_STANDING,
                                 lesson }) );
  student->set_busy(1000);
  return 1;
}

void on_action(object student, mixed lesson) {
  string buf;
  int ok = 0;
  if (SK_DAEMON->query_skill_exists(lesson)) {
    // teaching a skill
    buf = "about ~[060"+SK_DAEMON->query_skill_description(lesson);
    if (student->stat_check("int",SK_DAEMON->query_skill_difficulty(lesson))) {
      ok = 1;
      student->set_skill(lesson,1);
      this_player()->practice_skill(lesson,3);
    }
  }

  set_actor(this_player());
  set_target(student);
  if (ok)
    buf = "~CACT~Name ~verbteach ~targ "+buf+"~CACT.~CDEF";
  else
    buf = "~CACT~Name ~verbtry to teach ~targ "+buf+"~CACT, but ~prot ~vertfail to grasp the concept.~CDEF";

  this_player()->msg_local(buf);
  this_player()->add_readiness(-1000);
  student->set_busy(0);
}
