// Last edited by deforce on 12-10-2007
// Generic reporting facility (for bugs, ideas, typos, etc.).
// Created by Deathblade on 09-04-1994 - Lifted from Rust's "bug" command.

#include <config.h>
#include <mudlib.h>
#include <edit.h>
#include <log.h>

#define DIVIDER "\
\n***********************************************************************\n"

inherit M_ACCESS;

// For security reasons (since we write these using unguarded()), the
// file names should be "constants" rather than passed into us.  Same
// thing goes for posting to newsgroups.
// This does imply that the Reporter is limited by virtue of need to
// change this file, but that is a necessity if this will be writing
// to restricted directories.
private nosave mapping log_files = ([
   "bug" : LOG_BUG,
//   "feedback" : LOG_FEEDBACK,
//   "idea" : LOG_IDEA,
//   "praise" : LOG_PRAISE,
//   "question" : LOG_QUESTION,
   "typo" : LOG_TYPO,
]);
private nosave mapping news_groups = ([
   "bug" : LOG_BUG,
   "feedback" : LOG_FEEDBACK,
   "idea" : LOG_IDEA,
   "praise" : LOG_PRAISE,
   "question" : LOG_QUESTION,
   "typo" : LOG_TYPO,
]);
int busy = 0;

void create()
{
   set_privilege(1);
}

private nomask void issue_report(string type, string subject, string text)
{
   string where_am_i;
   object env;

   env = environment(this_body());
   where_am_i = (env ? file_name(env) : "unknown");
   type = lower_case(type);

   if (subject && news_groups[lower_case(type)])
   {
      text = sprintf("%s\n", text + "\n" + where_am_i);

      unguarded(1, (: NEWS_D->system_post($(news_groups[type]), $(subject), $(text)) :));
   }

   if (log_files[lower_case(type)])
   {
      text = sprintf("%s: %s reports from %s on %s--\n\n%s" DIVIDER, type,
         this_body()->query_name(), where_am_i, ctime(time()), text);

      LOG_D->log(log_files[lower_case(type)], text);
   }

   write("Thanks for the report!\n");
}

// Handle the completion of the report
private nomask void done_ed(string type, string subject, string *lines)
{
   type = lower_case(type);
   busy--;

   if (!lines)
   {
      printf("%s entry aborted.\n", type);
      return;
   }

   issue_report(type, subject, implode(lines, "\n") + "\n");
}

// begin_report()
// Entry point for a full text-entry bug report.  When the user completes
// their entry of the report, it will be handled appropriately.
varargs void begin_report(string type, string subject)
{
   type = lower_case(type);

   if (!log_files[type] && !news_groups[type])
   {
      error("Illegal report type.\n");
   }

   printf("** %s report **\n", type);
   busy++;
   new(EDIT_OB, EDIT_TEXT, 0, (: done_ed, type, subject :));
}

// short_report()
// The text has already been entered/derived/whatever.  This will just
// go straight ahead and issue the appropriate report.
varargs void short_report(string type, string subject, string text)
{
   type = lower_case(type);

   if (!log_files[type] && !news_groups[type])
   {
      error("Illegal report type.\n");
   }

   issue_report(type, subject, text + "\n");
}

// report_something()
// Do the right thing based on the report type, the input, and the config settings.
void report_something(string type, string input)
{
   object env = environment(this_body());
   string this_place = (env ? env->short() : "unknown");
   type = lower_case(type);

#ifdef LOG_DONT_POST
   if (!input || input == "")
   {
      begin_report(type);
   }
   else
   {
      short_report(type, 0, input);
   }
#else
   if (!input || input == "")
   {
      begin_report(type, this_place);
   }
   else
   {
      short_report(type, this_place, input);
   }
#endif
}

void clean_up()
{
   if (!busy) { destruct(this_object()); }
}