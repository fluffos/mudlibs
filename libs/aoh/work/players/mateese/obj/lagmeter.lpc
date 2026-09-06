/* Foo
**
** A testobject.
**
**  [m] Mateese
*/

#include "/players/mateese/mydefs.h"
#include <properties.h>

#define LOGFILE MPL+"foo"
#define VERSION "920429"

inherit "/std/thing";

object report;

int timeh, time2, time5, time10, time20;
int deltah, delta2, delta5, delta10, delta20;

create () {
  thing::create();
  AddId ("lagmeter");
  SetShort ("a lagmeter");
  SetLong ("A lagmeter. You set 'report on' or 'off'.\n");
  SetValue (0);
  SetWeight (0);
  timeh=time2=time5=time10=time20=time();
  deltah=delta2=delta5=delta10=delta20=0;
  set_heart_beat(1);
  call_out("check_lag", 5, 5);
  call_out("check_lag", 10, 10);
  call_out("check_lag", 20, 20);
  call_out("check_lag", 2, 2);
}

init() {
  thing::init();
  add_action ("read", "inspect"); 
  add_action ("renew", "renew");
  add_action ("freport", "report");
}

renew(str) {
  string foo,bar;
  object ob;
  if (!str || !id(str)) return 0;
  write ("lagmeter destructed and updated.\n");
  if (sscanf(file_name(ME), "%s#%s",foo,bar) == 2)
    if (ob = find_object(foo)) destruct (ob);
  destruct(ME);
  return 1;
}

heart_beat() {
  int now;
  now=time();
  deltah=now-timeh-2;
  timeh=now;
}

void report () {
  if (report) tell_object (report, 
 "Lagmeter: Heart: "+deltah+" | 2: "+delta2+" | 5: "+delta5+" | 10: "+delta10
+" | 20: "+delta20+".\n"
                          );
}

void check_lag(int arg) {
  int now;
  now=time();
  call_out("check_lag", arg, arg);
  switch (arg) {
  case 2: delta2=now-time2-arg; time2=now; report(); break;
  case 5: delta5=now-time5-arg; time5=now; break;
  case 10: delta10=now-time10-arg; time10=now; break;
  case 20: delta20=now-time20-arg; time20=now; break;
  }
}

int freport (string str) {
  if (!PL) return 0;
  if (!str) {
    if (!report) write ("Not reporting.\n");
    else write ("Reporting to "+capitalize(geteuid(report))+"\n");
    return 1;
  }
  else if (str == "on") {
    report = PL;
    write ("Now reporting to "+capitalize(geteuid(report))+"\n");
    return 1;
  }
  else if (str == "off") {
    report = 0;
    write ("Reports stopped.\n");
    return 1;
  }
  return 0;
} 






