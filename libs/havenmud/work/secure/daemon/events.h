#ifndef __EVENTS_H__
#define __EVENTS_H__

nosave void create();
varargs nosave int eventSave(int ung);
varargs void eventReboot(int x, int skip_backup);
nosave void eventAnnounceReboot(int x, int skip_backup);
void eventShutdown(int skip_backup);
nosave void Shutdown(int skip_backup);
nosave void eventPollEvents();

int SetRebootInterval(int x);
int GetRebootInterval();
void AddEvent(string c, string s, string f, mixed a, int w, int r);
mapping GetEvents();

#endif /* __EVENTS_H__ */
