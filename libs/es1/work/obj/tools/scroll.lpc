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

#include <mudlib.h>

inherit OBJECT ;

/* Variables */
nosave int tab, *place, shortflag, xref;
nosave object my_owner, ref_ob;
nosave string ret, ref_file;

/* Pre-Defined Functions */
void printaallin(object ob, int num);
void printascan(object ob, int num);
void printa(object ob);
void prints(object ob);
object find_obj(string str);
object location(object ob);
mixed resolv_str(string str);
object find_ref(object ref_where);
int xfinish(mixed *xresult);
mixed xparse(mixed *str);

/* Functions */
string query_auto_load() {
   return "obj/tools/scroll:";
}
int get() { return 0; }
int drop() { return 1; }
void create() {
   seteuid(getuid());
   set("id", ({ "scroll" }));
   set("short", "@@query_short");
   set("long", "A magical scroll.\n" +
	     "With it you can:\n" +
	     "\tsc [obj] - scan object (your env. if not supplied)\n" +
	     "\tss [obj] - shortscan object (your env. if not supplied)\n" +
	     "\tref <n> - ref object <n> in your env.\n" +
	     "\tref i<n> - ref object <n> in your inv.\n" +
	     "\tref r<n> - ref object <n> in ref's inv.\n" +
	     "\tref re - ref env. of ref'd object\n" +
	     "\tref e - ref your env.\n" +
	     "\tcref - clone ref'd object\n" +
	     "\tdref - dest ref'd object\n" +
	     "\ttref <str> - tell_object(ref,str)\n" +
	     "\tgref - move ref'd object to you\n" +
	     "\tiref - show id's of ref'd object\n" +
	     "\tmove <obj1> to <obj2> - move object <x> to object <y>\n" +
	     "\tcall <obj>;<fun>;[arg1];[arg2] - call function <fun> in object <obj>\n\t\twith [arg1] and [arg2], both of which are optional.\n" +
	     "OBJECTS can be: \"ref\" (ref'd object), any player, any living object,\n" +
    "\tanything in your inv., anything in your env., the file-name of a\n" +
	     "\tplace, \"me\" (you), \"here\" (your env.)\n");
}
string query_short() {
   if (ref_ob && this_player() == my_owner)
      return "a scroll [OBJ("+file_name(ref_ob)+")]";
   else
      return "a scroll";
}
void init() {
   if (my_owner && environment() != my_owner) return;
   if (!my_owner && !wizardp(this_player())) destruct(this_object());
   else my_owner = this_player();
   add_action("cmd_call", "call");
   add_action("cmd_sc", "sc");
   add_action("cmd_ss", "ss");
   add_action("cmd_move", "move");
   add_action("cmd_ref", "ref");
   add_action("cmd_tref", "tref");
   add_action("cmd_dref", "dref");
   add_action("cmd_gref", "gref");
   add_action("cmd_iref", "iref");
   add_action("cmd_cref", "cref");
}
object query_ref() { return ref_ob; }
int cmd_sc(string str) {
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
    prints(obj);
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
        prints(inv[i]);
	if (!shortflag) printaallin(inv[i], num + 1);
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
    st = (string)ob->query("cap_name");
    if (st) ret += st +" [";
    else {
        st = (string)ob->query_short();
	if (st) ret += capitalize(st) + " [";
	else ret += "(no name) [";
    }
    ret += "OBJ(" + file_name(ob) + ")] [UID:";
    if(getuid(ob)) ret += capitalize(getuid(ob)) + "] [EUID:";
    else ret += "NULL] [EUID:";
    if(geteuid(ob)) ret += capitalize(geteuid(ob)) + "]\n";
    else ret += "NULL]\n";
}
void printa(object ob) {
    int cnt;
    string st;
    while (cnt < tab) { ret += " "; cnt += 1; }
    if (!ob) { ret += "No object.\n"; return; }
    st = (string)ob->query("cap_name");
    if (st && st != "" && st != "Someone") ret += st + " [";
    else {
	st = (string)ob->query_real_name();
        if(st && st != "") ret += capitalize(st) + " (invis) [";
	else ret += "(no name) [";
    }
        /*
     * if(cloned(ob1)) write("*"); if(approved(ob1)) write("#");
     */
    ret += "OBJ(" + file_name(ob) + ")] [UID:";
    if(getuid(ob)) ret += capitalize(getuid(ob))+"] [EUID:";
    else ret += "NULL] [EUID:";
    if(geteuid(ob)) ret += capitalize(geteuid(ob))+"]\n";
    else ret += "NULL]\n";
}
void prints(object ob) {
    int cnt;
    object obj;
    if (!ob) return;
    obj = shadow(ob, 0);
    if (!obj) return;
    while (cnt < tab) { ret += " "; cnt += 1; }
    ret += "[S] [OBJ(" + file_name(obj) + ")] [UID:";
    if(getuid(ob)) ret += capitalize(getuid(ob)) + "] [EUID:";
    else ret += "NONE] [EUID:";
    if(geteuid(ob)) ret += capitalize(geteuid(ob)) + "]\n";
    else ret += "NONE]\n";
    prints(obj);
}
object find_obj(string str) {
    int i;
    string name;
    object ob, *user;
    if (sscanf(str, "@%s", name))
        if (ob = find_obj(name))
            if(ob = environment(ob)) return ob;
    if (str == "ref") return ref_ob;
    ob = find_player(str);
    if (!ob) ob = find_living(str);
    if (!ob) ob = present(str, this_player());
    if (!ob) ob = present(str, environment(this_player()));
    if (!ob) ob = find_object(str);
    if (!ob) catch(call_other(this_player()->query("cwd") + "/" + str, "?"));
    if (!ob) catch(call_other(user_path((string)this_player()->query("name")) +
                              str, "?"));
    if (!ob) ob = find_object(this_player()->query("cwd") + "/" + str);
    if (!ob) ob = find_object(user_path((string)this_player()->query("name")) +
                              str);
    if (!ob && str == "me") ob = this_player();
    if (!ob && str == "here") ob = environment(this_player());
    if (!ob) {
        for(user=users(); i<sizeof(user); i++)
            if ((string)user[i]->query_real_name() == str) return user[i];
    }
    return ob;
}
object location(object ob) {
    if (!environment(ob)) return ob;
    ob = environment(ob);
    return location(ob);
}
int cmd_move(string str) {
    string a1, a2, c1, c2;
    int at1, at2;
    object b1, b2;
    if (!str || str == "") {
        notify_fail("Syntax: move <obj1> to <obj2>\n");
        return 0;
    }
    if (sscanf(str, "%s to %s", a1, a2) != 2) return 0;
    if (sscanf(a1, "@%s", c1)) { at1 = 1; a1 = c1; }
    if (sscanf(a2, "@%s", c2)) { at2 = 1; a2 = c2; }
    b1 = find_obj(a1);
    if (!b1) { notify_fail(a1 + " not found.\n"); return 0; }
    if (at1) {
	b1 = environment(b1);
	if (!b1) { notify_fail("No object for @" + a1 + "\n"); return 0; }
    }
    b2 = find_obj(a2);
    if (!b2) { notify_fail(a2 + " not found.\n"); return 0; }
    if (at2) {
	b2 = environment(b2);
	if (!b2) { notify_fail("No object for @" + a2 + "\n"); return 0; }
    }
    if (b1 == b2) {
        notify_fail("Can't move an object to itself.\n");
        return 0;
    }
    if(!(c1 = (string)b1->query_name())) c1 = (string)b1->query_short();
    if(!(c2 = (string)b2->query_name())) c2 = (string)b2->query_short();
    write(c1 + " moved to " + c2 + ".\n");
    b1->move(b2);
    return 1;
}
int cmd_ref(string str) {
   object xxy;
   if (!str) {
      tab = 1;
      ret = "Ref_ob =";
      printa(ref_ob);
      write(ret);
   }
   else if (sscanf(str, "p%d", xref) == 1) {
      xref--;
      if (xref < 0 || xref >= sizeof(users())) {
         notify_fail("Number exceeds available players. Ref_ob not changed.\n");
         return 0;
      }
      ref_ob = users()[xref];
      ret = "Ref_ob set to:";
      tab = 1;
      printa(ref_ob);
      write(ret);
   }
   else if (sscanf(str, "i%d", xref) == 1) {
      xref--;
      if(xref < 0 || xref >= sizeof(all_inventory(this_player()))) {
         notify_fail("Number exceeds number of objects in inventory.\n");
         return 0;
      }
      ref_ob = find_ref(this_player());
   }
   else if (sscanf(str, "%d", xref) == 1) {
      xref--;
      if (xref < 0 ||
         xref >= sizeof(all_inventory(environment(this_player())))) {
         notify_fail("Number exceeds number of objects in environment.\n");
         return 0;
      }
      ref_ob = find_ref(environment(this_player()));
   }
  else if (sscanf(str, "r%d", xref) == 1) {
      xref--;
      if (!ref_ob) {
         notify_fail("Ref_ob = No object.\n");
         return 0;
      }
      if (xref < 0 || xref >= sizeof(all_inventory(ref_ob))) {
         notify_fail("Number exceeds number of objects in ref_ob.\n");
         return 0;
      }
      ref_ob = find_ref(ref_ob);
   }
   else if (str == "e") {
      ref_ob = environment(this_player());
      ret = "Ref_ob set to:";
      tab = 1;
      printa(ref_ob);
      write(ret);
   }
   else {
      xxy = find_obj(str);
      if (xxy) {
         ref_ob = xxy;
         ret = "Ref_ob set to:";
         tab = 1;
         printa(ref_ob);
         write(ret);
      } else {
         notify_fail("Invalid reference specification.\n");
         return 0;
      }
   }
   return 1;
}
object find_ref(object ref_where) {
   object *ob;
   ob = all_inventory(ref_where);
   ret = "Ref_ob set to:";
   tab = 1;
   printa(ob[xref]);
   write(ret);
   return ob[xref];
}
int cmd_tref(string str) {
    if (!ref_ob) { notify_fail("No object to tell.\n"); return 0; }
    tell_object(ref_ob, (string)this_player()->query("cap_name") +
      " tells you: " + str + "\n");
    write("You tell " + (string)ref_ob->query("cap_name") + ": " + str + ".\n");
    return 1;
}
int cmd_gref() {
   if (!ref_ob) {
      notify_fail("No object to get.\n");
      return 0;
   }
   ref_ob->move(this_player());
   if (environment(ref_ob) == this_player())
      write((string)ref_ob->query("short") + " moved into you.\n");
   else {
      ref_ob->move(environment(this_player()));
      if (environment(ref_ob) == environment(this_player()))
         write((string)ref_ob->query("short") + " moved to environment.\n");
      else
         write("Failed to move " + (string)ref_ob->short("short") + ".\n");
   }
   return 1;
}
int cmd_iref() {
    int i;
    string *id_array;
    if (!ref_ob) { notify_fail("No object to id.\n"); return 1; }
    id_array = (string*)ref_ob->query("id") ;
    ret = "id's: ";
    if (!id_array || !sizeof(id_array)) {
        ret = " [none!]\n";
        write(ret);
        return 1;
    }
    for (i=0; i<sizeof(id_array); i++) ret += " '" + id_array[i] + "'";
    write(ret + "\n");
    return 1;
}
varargs int cmd_dref(int arg) {
   string ref_name;
   if (!ref_ob) {
      notify_fail("No object to destruct.\n");
      return 0;
   }
   ref_name = "[OBJ(" + file_name(ref_ob) + ")]";
   if (!arg) {
      ref_ob->remove();
      if (!ref_ob) {
         write("REMOVE: " + ref_name + "\n");
         return 1;
      }
   }
   destruct(ref_ob);
   write("DESTRUCT: " + ref_name + "\n");
   return 1;
}
int cmd_cref() {
   object ob;
   string file, mess;
   int num;
   if (!ref_ob) {
      notify_fail("No object to clone.\n");
      return 0;
   }
   file = file_name(ref_ob);
   sscanf(file, "%s#%d", file, num);
   mess = catch(ob = clone_object(file));
   if(mess) {
      write(mess+"\n");
      return 1;
   }
   ob->move(this_player());
   write("CLONED: " + file + "->" + file_name(ob) + ".\n");
   return 1;
}
int cmd_call(string str) {
   int i;
   mixed *xs;
   object xob;
   string t1,t2;
   xs = ({ });
   while (str && sscanf(str, "%s;\"%s\"%s", t1, t2, str)) {
      if (t1 != "" && explode(t1, ";"))
         xs += explode(t1, ";");
      if (t2)
         xs += ({ t2 });
      else if (str) {
         xs += ({ str });
         str = 0;
      }
   }
   if (str && str != "" && explode(str, ";"))
      xs += explode(str, ";");
   if (sizeof(xs) < 2 || xs[0] == "" || xs[1] == "") {
      write("Syntax: call <ob>;<func>;<arg1>;<arg2>\n");
      return 1;
   }
   xob = find_obj(xs[0]);
   if (!xob) {
      write("Object not found.\n");
      return 1;
   }
   if (!function_exists(xs[1], xob)) {
      object sob;
      for(sob = shadow(xob, 0);sob;sob = shadow(sob, 0)) {
         if (function_exists(xs[1], sob)) {
            sob = xob;
            break;
         }
      }
      if (xob != sob) {
         write("No such function in that object.\n");
         return 1;
      }
   }
   for(i=2; i<sizeof(xs); i++)
      xs[i] = resolv_str(xs[i]);
   switch(sizeof(xs)) {
      case 2: return xfinish((mixed)call_other(xob,xs[1]));
      case 3: return xfinish((mixed)call_other(xob,xs[1],xs[2]));
      case 4: return xfinish((mixed)call_other(xob,xs[1],xs[2],xs[3]));
      case 5: return xfinish((mixed)call_other(xob,xs[1],xs[2],xs[3],xs[4]));
      default: return xfinish((mixed)call_other(xob,xs));
   }
}
mixed resolv_str(string str) {
   int i, reti;
   string rets, m1, m2;
   mixed *reta;
   mapping retm;
   if (str == "" || str == " ") return "";
   if (!str) return;
   if (sscanf(str, "%d", reti)) return reti;
   if (sscanf(str, "({%s})", rets)) {
      reta = explode(rets, ",");
      for(i=0; i<sizeof(reta); i++)
         reta[i] = resolv_str(reta[i]);
      return reta;
   }
   if (sscanf(str, "([%s])", rets)) {
      retm = ([ ]);
      reta = explode(rets, ",");
      for(i=0; i<sizeof(reta); i++) {
         sscanf(reta[i], "%s:%s", m1, m2);
         m1 = resolv_str(m1);
         m2 = resolv_str(m2);
         retm += ([ m1 : m2 ]);
      }
      return retm;
   }
   if (sscanf(str, "%s\"%s\"%s", m1, rets, m2)) {
      m1 = resolv_str(m1);
      m2 = resolv_str(m2);
      if ((!m1 || m1 == "") && (!m2 || m2 == ""))
         return rets;
   }
   reta = explode(str, " ");
   if (reta)
      str = implode(reta, "");
   else
      str = "";
   return str;
}
int xfinish(mixed xresult) {
write("Returned:\n");
write(dump_variable(xresult));
write("\n");
return 1;
   if (undefinedp(xresult))
      write("Result = -0-\n");
   // else if (nullp(xresult))
      // write("Result = Nullp\n");
   else
      write("Result = " + xparse(xresult) + "\n");
   return 1;
}
object convert_object(mixed str) { return str; }
mapping convert_mapping(mixed str) { return str; }
mixed xparse(mixed *str) {
   int i;
   object ob;
   mapping map;
   mixed nresult;
   if(pointerp(str)) {
      nresult = "({ ";
      for(i=0;i<sizeof(str);i++) {
         if(i) nresult += ", ";
         nresult += xparse(str[i]);
      }
      nresult += " })";
   }
   else if (mapp(str)) {
      nresult = "([ ";
      map = convert_mapping(str);
      str = keys(map);
      for(i=0; i<sizeof(str); i++) {
         if (i) nresult += ", ";
         nresult += xparse(str[i]) + " : " + xparse(map[str[i]]);
      }
      nresult += " ])";
   }
   else if(stringp(str))
      nresult = "\"" + str + "\"";
   else if(objectp(str)) {
      ob = convert_object(str);
      nresult = "OBJ(" + file_name(ob) + ")";
   }
   else
      nresult = str;
   return nresult;
}

int cmd_ss(string str) {
    shortflag = 1;
    cmd_sc(str);
    shortflag = 0;
    return 1;
}
save() {
   save_object("/u/h/huma/scroll");
}
int move(object dest) {
   if (my_owner) return 1;
   return ::move(dest);
}

/* EOF */
