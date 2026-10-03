#ifndef __SHUTDOWN_H
#define __SHUTDOWN_H

void create();
void reboot_mud(int x);
protected void countdown(int x);
protected void final_warning();
protected void reboot();
private void notify_listeners(int x);
void notify_armageddon(object ob);

#endif /* __SHUTDOWN_H */
