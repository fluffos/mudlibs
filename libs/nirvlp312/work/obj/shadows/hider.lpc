/* shadow for 'hid in shadows' skills of thief */

inherit "obj/shadows/shadow";

object who;
int stealth;

void shadow_short(string alt_type) {
  if (this_player()->query_hide_in_shadows_object()) {
    destruct(this_object());
    return;
  }
  who = this_player();
  if (!alt_type) alt_type = "stealth";
  stealth = (int)call_other(this_player(), "query_" + alt_type) + 1;
  shadow_object(who);
}

status move_player(string dest_dir, mixed option_dest, status domain_safe) {
  status flag;

  tell_object(who, "You stop hiding and move out of the shadows...\n");
  flag = (status)who->move_player(dest_dir, option_dest, domain_safe);
  destruct(this_object());
  return flag;
}

string short(status wiz) {
  if (environment(this_player()) == environment(who)) {
    if (random(stealth) >=
        random((int)this_player()->query_intelligence() + 1)) {
      return (wiz) ? "@" + (string)who->short(wiz) : 0;
    }
  }
  if (wiz)
    return "@" + (string)who->short(wiz);
  else
    return (string)who->short(wiz);
}

object query_hide_in_shadows_object() { return this_object(); }

int query_hide_in_shadows() { return stealth; }

