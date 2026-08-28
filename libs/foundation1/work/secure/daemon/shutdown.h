#ifndef __SHUTDOWN_H
#define __SHUTDOWN_H

void create();
void reboot_mud(int x);
nosave void countdown(int x);
nosave void final_warning();
nosave void reboot();
nosave private void notify_listeners(int x);
void notify_armageddon(object ob);

#endif /* __SHUTDOWN_H */
