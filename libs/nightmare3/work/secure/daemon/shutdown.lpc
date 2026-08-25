/*    /secure/daemon/shutdown.c
 *    from Nightmare 3.3
 *    the daemon which handles all shutdown nonsense
 *    created by Descartes of Borg 940924
 */

#include <std.h>
#include <rooms.h>
#include <commands.h>
#include <objects.h>
#include "shutdown.h"

inherit DAEMON;

nosave private object *__Notify;

void create() {
    daemon::create();
    __Notify = ({});
}

void reboot_mud(int x) {
    if(x < 2) return;
    if(!((int)master()->valid_apply(({}))) && file_name(previous_object(0)) !=
      CMD_END) return;
    catch(new(OB_SHUT)->move(ROOM_START));
    call_out("countdown", 60, x-1);
    message("broadcast", "Armageddon shouts: I am annoyed! "
      "Reboot in "+x+" minutes!", users());
}

protected void countdown(int x) {
    if(x == 1) call_out("final_warning", 50);
    else call_out("countdown", 60, x-1);
    message("broadcast", "Armageddon shouts: Reboot in "+
      consolidate(x, "a minute")+"!", users());
    if(x == 3)
      message("broadcast", "Tell me if you need a trip to the shop!",
        this_player());
    notify_listeners(x);
}

protected void final_warning() {
    call_out("reboot", 10);
    message("broadcast", "Armageddon shouts: Final warning!  Reboot "
      "in 10 seconds!", users());
    notify_listeners(0);
}

protected void reboot() {
    catch(users()->force_me("quit"));
    shutdown();
}

 private void notify_listeners(int x) {
    catch(__Notify->call_end(x*60));
}

void notify_armageddon(object ob) {
    __Notify = distinct_array(({ ob }) + __Notify) - ({ 0 });
}

