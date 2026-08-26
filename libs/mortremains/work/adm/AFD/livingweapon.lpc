
// Lexander's Living Weapon Code
// Designed to 'overlay' the weapon code transparently.

#include <move.h>
#include <mudlib.h>

inherit WEAPON ;

string str;

void unwield(int silent);
int power_test(string ownertest,string itemtest);

int power_test(string ownertest,string itemtest) {

    object owner,thisweapon;
    
    thisweapon = this_object();
    if (!thisweapon->query("alive"))    { return 1; }
    owner = environment(thisweapon);
    if (!owner)                         { return 1; }
    if (!living(owner))                 { return 1; }
    if (owner->query(ownertest) < thisweapon->query(itemtest)) 
        return 0;
    else
        return 1;
}

int move(mixed dest) {

    object owner,thisweapon;
    int retvalue;    
    
    thisweapon = this_object();
    if (thisweapon->query("resist_move")) {   
          owner = environment(thisweapon);
          if (!thisweapon->power_test("stat/intellect","living_power")) {
             str = thisweapon->query("move_fail_func");   
             if (str) { call_other(thisweapon, str); }
             else {
                tell_object(owner, 
"Try as you might, " + thisweapon->query("short") + " refuses to budge.\n");
             }
             return MOVE_NOT_ALLOWED;
          }
    }
    
    retvalue = ::move(dest);
    if (!retvalue) {
        if (str = thisweapon->query("move_func")) { 
call_other(thisweapon,str); }
    } 
    return retvalue;
}

int wield(int silent, int weaponnum) {
    
    object owner,thisweapon;

    thisweapon = this_object();
    if (thisweapon->query("resist_wield")) {
        owner = environment(thisweapon);
        if (!thisweapon->power_test("stat/intellect","living_power")) {
             str = thisweapon->query("wield_fail_func");
             if (str) { call_other(thisweapon, str); }
             else {
                tell_object( owner,
                "The weapon will not allow you to wield it.\n");
                }
             return 0;
        }
    }
    return 1;   // cludgeroo
/*  This doesn't work.
    return ::wield(silent, weaponnum) ;
*/
}

int unwield(int silent) {

    object owner,thisweapon;

    thisweapon = this_object();
    if (thisweapon->query("resist_unwield")) {
        owner = environment(thisweapon);
        if (!thisweapon->power_test("stat/intellect","living_power")) {
             str = thisweapon->query("unwield_fail_func");
             if (str) { call_other(thisweapon,str); }
             else {
                tell_object(owner,
                "The weapon refuses to let you unwield it.\n");
             }
             return 0;
        }
    }
    return ::unwield(silent); 
}

int set_alive() {
        
        set_heart_beat((int)this_object()->query("living_action_rate")*10);
        set("alive",1);
}

int alive() {
        
        object owner,thisweapon;

        thisweapon = this_object();
        if (thisweapon->query("alive")) { return 0; }
        thisweapon->set("alive",1);
        if (thisweapon->query("resist_alive")) {
           owner = environment(thisweapon);
           if (!thisweapon->power_test("stat/intellect","living_power")) {
                thisweapon->set("alive",0);
                if (str = query("alive_fail_func"))
                        { call_other(thisweapon,str); }
                return 0;
           }
        }
       set_heart_beat((int)thisweapon->query("living_action_rate")*10);
        if (str = query("alive_func")) { call_other(thisweapon,str); }
        return 1;
}

int unalive() {

        object owner,thisweapon;

        thisweapon = this_object();
        if (!thisweapon->query("alive")) { return 0; }
        if (thisweapon->query("resist_unalive")) {
            owner = environment(thisweapon);
            if (!thisweapon->power_test("stat/intellect","living_power")) {
                return 0;
            }
            if (str = query("unalive_fail_func")) 
                { call_other(thisweapon,str); }
        }
        thisweapon->set("alive",0);
        if (str = query("unalive_func")) { call_other(thisweapon,str); }
        set_heart_beat(0);
        return 1;
}

void heart_beat() {

        mapping funclist;
        int ctr,value,listsize;
        mixed *keylist;
        string str;

        funclist = this_object()->query("living_func");

        if (!funclist) { return; }
        listsize = sizeof(funclist);
        if (!listsize) { return; }
        keylist = keys(funclist);       

        for(ctr = 0;ctr < listsize;ctr++) {             
                if (!stringp(keylist[ctr])) { continue; }
                str = keylist[ctr];
                if (!intp(funclist[str])) { continue; }
                value = random(100) + 1;
                if (value < funclist[str])
                        {
                        call_other(this_object(),str);
                        }
        }
}
