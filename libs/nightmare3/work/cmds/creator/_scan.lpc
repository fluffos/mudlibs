/* A wizardly extension, by Waldo and Godefroy.
   This one has extenstions by Angus, too.
   Originally built on Floyd Mud (1.4), upgraded for HERO Mud (2.4.5) and
   then unleashed upon the world (3.0).
   Please retain this comment in any distributions you make. Thanks. */
 
// The copy included with the MudOS/TMI mudlibs has been maintained
// (but not extended in functionality) by Buddha.
// The scroll subsequently passed into the care of Huma, who tightened up
// the code considerably, and may have added some new functions. His
// version became the standard version on 10-31-92.
 
// _scan.c is code jerked out of the scroll wiztool by Hanse@Nightmare 2/12/93
 
#include <std.h>

inherit DAEMON;
 
int tab, *place;
string ret;
 
void printaallin(object ob, int num);
void printascan(object ob, int num);
void printa(object ob);
void prints(object ob);
object find_obj(string str);
object location(object ob);
 
int cmd_scan(string str) {
    object obj;
    string dummy;
    int atflag;
    atflag = 0;
    if (!str || str == "") obj = location(this_player());
    else {
        if (sscanf(str, "@%s", dummy) == 1) { atflag = 1; str = dummy; }
        obj = find_obj(str);
        if (!obj) { notify_fail("Failed to find object.\n"); return 0; }
    }
    if (atflag) obj = location(obj);
    ret = "Scanning:\n";
    printa(obj);
#ifdef HAS_SHADOWS
    prints(obj);
#endif
    place = allocate(20);
    printaallin(obj, 0);
    write(ret);
    return 1;
}
 
void printaallin(object ob, int num) {
    int i;
    mixed *inv;
    tab += 2;
    inv = all_inventory(ob);
    place[num] = 0;
    for(i=0;i<sizeof(inv);i++) {
        printascan(inv[i], num);
#ifdef HAS_SHADOWS
        prints(inv[i]);
#endif
        printaallin(inv[i], num + 1);
    }
    tab -= 2;
}
 
void printascan(object ob, int num) {
    int cnt;
    string st;
    place[num] += 1;
    while (cnt < tab) { ret += " "; cnt += 1; }
    if (!ob) { ret += "No object.\n"; return; }
    ret += place[num];
    if(place[num] < 10) ret += ":  ";
    else ret += ": ";
    st = (string)ob->query_name();
    if (st) st = capitalize(st);
    if (st) ret += st +" [";
    else {
        st = (string)ob->query_short();
        if (st) ret += capitalize(st) + " [";
        else ret += "(no name) [";
    }
    ret += file_name(ob) + "]\n";
}
 
void printa(object ob) {
    int cnt;
    string st;
    while (cnt < tab) { ret += " "; cnt += 1; }
    if (!ob) { ret += "No object.\n"; return; }
    st =(string)ob->query_cap_name();
    if (st && st != "" && st != "Someone" && st != "A shadow") ret += st + " [";
    else {
        st = (string)ob->query_name();
	if (!st) st = (string)ob->query_short();
        if(st && st != "") ret += st + " [";
        else ret += "(no name) [";
    }
    /*
     * if(cloned(ob1)) write("*"); if(approved(ob1)) write("#");
     */
   ret += file_name(ob) + "]\n";
}
 
// shadows disabled in the driver. no need for this
#if HAS_SHADOWS
void prints(object ob) {
    int cnt;
    object obj;
    if (!ob) return;
    obj = shadow(ob, 0);
    if (!obj) return;
    while (cnt < tab) { ret += " "; cnt += 1; }
    ret += "[S] [OBJ(" + file_name(obj) + ")] [uid:";
    if(getuid(ob)) ret += capitalize(getuid(ob)) + "] [euid:";
    else ret += "none] [euid:";
    if(geteuid(ob)) ret += capitalize(geteuid(ob)) + "]\n";
    else ret += "none]\n";
    prints(obj);
}
#endif
 
object find_obj(string str) {
    int i;
    string name;
    object ob, *user;
    if (sscanf(str, "@%s", name))
        if (ob = find_obj(name))
            if(ob = environment(ob)) return ob;
    ob = find_player(str);
    if (!ob) ob = find_living(str);
    if (!ob) ob = present(str, this_player());
    if (!ob) ob = present(str, environment(this_player()));
    if (!ob) ob = find_object(str);
    if (!ob) catch(call_other(this_player()->query("cwd") + "/" + str, "?"));
    if (!ob) catch(call_other(user_path((string)this_player()->query_name()) +
                              str, "?"));
    if (!ob) ob = find_object(this_player()->query("cwd") + "/" + str);
    if (!ob) ob = find_object(user_path((string)this_player()->query_name()) +
                              str);
    if (!ob && str == "me") ob = this_player();
    if (!ob && str == "here") ob = environment(this_player());
    if (!ob) {
        for(user=users(); i<sizeof(user); i++)
            if ((string)user[i]->query_name() == str) return user[i];
    }
    if(ob && ob->query_invis() && creatorp(ob)) ob=0;
    return ob;
}
 
object location(object ob) {
    if (!environment(ob)) return ob;
    ob = environment(ob);
    return location(ob);
}
 
void help() {
    write("Syntax: scan <object>:\n"+
          "This command scans an object and returns info about it.\n"+
          "scan me      - scans yourself\n"+
          "scan here    - scans your environment\n"+
          "scan @object - scans the environment of an object\n"+
          "See also: I, sc, ss\n"+
          "");
}
