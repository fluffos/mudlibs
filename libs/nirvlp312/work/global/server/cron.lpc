#pragma strong_types

#include <kernel.h>
#include <time_units.h>
#include <timezone.h>
#include <server.h>

inherit "basic/create";

private mixed *jobs;
private int clockhand = -1;

int query_clockhand() {  // Carador, 13-Dec-98
  return clockhand;
}

status prevent_move() {
  return 1; // don't move the blueprint anywhere
}

private void set_clockhand() {
  if (jobs[0] && clockhand < 0) {
    clockhand = insert_alist(SE_TIME->query_day_time(),jobs[0][0]);
    if (clockhand >= sizeof(jobs[0][0]))
      clockhand = 0;
  }
}

// moved from the cron() function into an own lfun, Coogan, 25-Aug-2005
private varargs void do_cron_jobs(status forced) {
  mixed h;
  int i;
  mixed *calls;

    m_delete(jobs[0][1][clockhand],0);
    calls = fold_left(#'+,m_values(jobs[0][1][clockhand]),({}));
    for (i = sizeof(calls); i; i--) {
      // following line temporarily added by Carador, 13-Dec-98
      log_file("CRON",
               ctime() + ": localdaytime: " + SE_TIME->query_day_time() +
               (forced ? " (forced)" : "") + " \n" +
               implode(explode(sprintf("%O", calls[<i]), "\n"), " ")+"\n");
      if (h=catch(apply(#'efun::call_other,calls[<i])))  // error occurs?
        NOTIFY_ERROR(sprintf("Error in cron job: %O"
                             "%O\n",h,calls[<i]));
    }
    if (++clockhand >= sizeof(jobs[0][0])) // wrap around
      clockhand = 0;
  return;
}

void cron() {
  mixed h;
  int now, i;
  mixed *calls;

  if (!jobs[0]) 
    return;
  now = SE_TIME->query_day_time();
  set_clockhand();

  if (now >= jobs[0][0][clockhand] - (30 << TZ_SHIFT) && 
      now <= jobs[0][0][clockhand] + (30 << TZ_SHIFT)) {// plus/minus 30 seconds
    do_cron_jobs();
  }
  else {
    // added logging of out-of-hand crons, Coogan, 16-Aug-2004
    if (now >= jobs[0][0][clockhand] - (600 << TZ_SHIFT) &&  // plus/minux
        now <= jobs[0][0][clockhand] + (600 << TZ_SHIFT)) {  // 600 seconds
      log_file("CRON", ctime() + ": cron out of hand? : localdaytime: " + now +
                       " at next job " + jobs[0][0][clockhand] + "\n");
    }
    if (now >= jobs[0][0][clockhand] - ( 30 << TZ_SHIFT) && // minus 30 secs up
        now <= jobs[0][0][clockhand] + (600 << TZ_SHIFT)) { // to plus 600 secs
    // cronjobs are out of hand because of the garbage collection:
    // perform the missed crons now (which is better than to drop them).
    // TODO: It would be better if there's a flag set after the end of the GC
    //       indicating the real end of the GC, so that no time limit like the
    //       above 600 secs has to be assumed.
    // Coogan, 25-Aug-2005
      do_cron_jobs(1);  // do the cronjobs, but log with status 'forced'
      call_out("cron", 1);  // 0->1, Coogan, 03-Nov-2009
      return;
    }
  }

  if (!clockhand) // next day
    call_out("cron",(jobs[0][0][clockhand] + ONE_DAY - now) >> TZ_SHIFT);
  else
    call_out("cron",(jobs[0][0][clockhand] - now) >> TZ_SHIFT);
}

void crontab_add(int when, string obj, string fun, mixed arg) {
  int i;
  check_arguments(({ when,  obj,      fun }),
                  ({ #'intp,#'stringp,#'stringp }),"crontab_add");
  if (!jobs[0]) {
    jobs[0] = ({ ({ }), ({ }) });
    call_out("cron",0);
  }
  if ((i = assoc(when,jobs[0][0])) < 0)
    jobs[0] = insert_alist(when,([ previous_object():
                                     ({ ({ obj,fun,arg }) }) ]),
                           jobs[0]);
  else if (!member(jobs[0][1][i],previous_object()))
    jobs[0][1][i][previous_object()] = ({ ({ obj,fun,arg }) });
  else
    jobs[0][1][i][previous_object()] += ({ ({ obj,fun,arg }) });
  clockhand = -1;
  if (find_call_out("cron") > 2) {
    remove_call_out("cron");
    call_out("cron",0);
  }
}

int crontab_remove(int when, string obj, string fun) {
  int i, ret, num;
  mixed *calls;

  set_clockhand();
  if (!(jobs[0] && (num=assoc(when,jobs[0][0])) >= 0 && 
        (member(jobs[0][1][num],previous_object()))))
    return 0;
  if (!obj && !fun) // remove all
    m_delete(jobs[0][1][num],previous_object());
  else {
    calls = jobs[0][1][num][previous_object()];
    for (i = sizeof(calls); i--; )
      if ((!obj || calls[i][0] == obj) &&
          (!fun || calls[i][1] == fun)) {
        calls[i..i] = ({});
        ret++;
      }
    if (!sizeof(calls))
      m_delete(jobs[0][1][num],previous_object());
    else
      jobs[0][1][num] = calls;
  }
  m_delete(jobs[0][1][num],0);
  if (!sizeof(jobs[0][1][num])) {
    jobs[0][0][num..num] = ({});
    jobs[0][1][num..num] = ({});
    jobs[0] = order_alist(jobs[0]);
  }
  if (!sizeof(jobs[0][0]))
    jobs[0] = 0;
  clockhand = -1;  // Coogan, 04-Dec-2003
  if (find_call_out("cron") > 2) {
    remove_call_out("cron");
    call_out("cron",0);
  }
  return ret;
}

private void print_jobs(object whose, mixed *job,mixed *time_who_num) {
  int i;
  if (time_who_num[1] && creator_file(object_name(whose)) != time_who_num[1])
    return;
  for (i = sizeof(job); i; i--)
    this_player()->tell_more(sprintf("job %3d at %.2d:%.2d:%.2d %s::%s\n",
                                     time_who_num[2],
                                     time_who_num[0]/ONE_HOUR,
                                     (time_who_num[0] /
                                      (ONE_HOUR / ONE_MINUTE) % ONE_MINUTE),
                                     time_who_num[0] % ONE_MINUTE,
                                     job[<i][0],
                                     job[<i][1]));
}

void crontab_list(string who, int num) {
  int i, start;

  set_clockhand();
  if (jobs[0]) {
    if (num)
      start = clockhand;
    if (!num || (num += clockhand) > sizeof(jobs[0][0]))
      num = sizeof(jobs[0][0]);
    this_player()->tell_more("clockhand=" + clockhand + "\n");
    for (i = start; i < num; i++)
      walk_mapping(jobs[0][1][i],#'print_jobs,({ jobs[0][0][i],who,i }));
    this_player()->tell_more("next job in " + find_call_out ("cron") +
                             " seconds\n");
  }
}

void create() {
  if (clonep())
    destruct(this_object());
  jobs = allocate_shared_mem("cron::jobs",({ 0 }));
  cron();
}

void set_jobs(mixed *j) {
  if (!check_privilege(1))
    return;
  jobs[0] = j;
}
