#ifndef __REPORTER_H__
#define __REPORTER_H__

varargs mixed start_report(object tp, string subject);
public nomask void finish_report(string text, object user);
public nomask void finish_github(mapping response, object user);
public nomask void get_subject(string subject, object user);

#endif // __REPORTER_H__
