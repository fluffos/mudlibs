/*    /std/user/autosave.c
 *    from Nightmare IV
 *    object to save a player to file
 *    created by Descartes of Borg 940216
 */

#include <config.h>
#include <dirs.h>
#include <privs.h>
#include <security.h>
#include "autosave.h"

private mixed *__AutoLoad;
private int __ItemsValue;
nosave private int __LastSave;

void convert_auto();

void create() {
    __AutoLoad = ({});
    __ItemsValue = 0;
    __LastSave = time();
}

void setup() {
    object ob;
    int i;

    master()->create_save();
    call_out("save_player", 2, query_name());
    convert_auto();
    if(!(i = sizeof(__AutoLoad))) return;
    while(i--) {
        if(sizeof(__AutoLoad[i]) != 2) continue;
        if(!stringp(__AutoLoad[i][0]) || !pointerp(__AutoLoad[i][1])) continue;
        catch(ob = new(__AutoLoad[i][0]));
        if(!ob) continue;
        ob->move(this_object());
        catch(ob->init_arg(__AutoLoad[i][1]));
    }
}

void heart_beat() {
    int x;

    if((x=time()) - __LastSave < AUTOSAVE_TIME) return;
    __LastSave = x;
    save_player(query_name());
    if(!creatorp(this_object())) message("system", "Autosave.", this_object());
}

nomask void save_player(string nom) {
    string file, dir;

    if(!nom || nom != query_name()) return;
    pre_save();
    file = sprintf("%s/%s/%s", DIR_USERS, nom[0..0], nom+__SAVE_EXTENSION__);
    //debug_message("file: "+file);
    if(file_size(dir = sprintf("%s/%s", DIR_USERS, nom[0..0])) != -2){
    //debug_message("directory "+dir+"  does not exist.");
    }
    unguarded((: save_object, file, 1 :));
}

void pre_save() {
    object *inv;
    mixed *tmp;
    int i;

    i = sizeof(inv = all_inventory(this_object()));
    __ItemsValue = 0;
    __AutoLoad = ({});
    while(i--) {
        if(pointerp(tmp = (mixed *)inv[i]->query_auto_load())) {
            if(sizeof(tmp) == 2 && pointerp(tmp[1]))
              __AutoLoad += ({ tmp });
        }
        else __ItemsValue += (int)inv[i]->query_value();
    }
}

nomask int restore_player(string nom) {
    string file;

    if(previous_object(0) != master()) return 0;
    file = sprintf("%s/%s/%s", DIR_USERS, nom[0..0], nom+__SAVE_EXTENSION__);
    //debug_message("autosave: file is "+file);
    //debug_message("autosave: I am "+identify(this_object()));
    return unguarded((: restore_object, file :));
}

int remove() {
    object *inv;
    int i;

    i = sizeof(inv = all_inventory(this_object()));
    while(i--) if((mixed *)inv[i]->query_auto_load()) inv[i]->remove();
}

string query_name() { return 0; }

private mixed *auto_load;
protected void convert_auto() {
    if(!auto_load) return;
    __AutoLoad = copy(auto_load);
    auto_load = 0;
}
