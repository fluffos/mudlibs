inherit "/bin/std";

string *pinky;

void ChangeComment() {
  string comment;
  comment = pinky[random(sizeof(pinky))];
  nontarget("You think hard, and say, \""+comment+"\"$N$\n", "After a great deal of thought, #MN# says, \""+comment+"\"  Odd.$N$\n");
  target("You think hard, and then tell #TN#, \""+comment+"\"$N$\n", "After a great deal of thought, #MN# says to #TN#, \""+comment+"\"  #CMS# better be careful, or #TN# will have to hurt #MO#.$N$\n", "After a great deal of thought, #MN# tells you, \""+comment+"\"  It's clear that you shall have to hurt #MO#.$N$\n");
  afar("From afar, you tell #TN#, \""+comment+"\"$N$\n", "From afar, #MN# tells you, \""+comment+"\"$N$\n");
}

void
reset(int x)
{
    if(!x) {
      ::reset();
       restore_object("players/illarion/obj/pinky");
       ChangeComment();
    }
}

int
cmd_pinky2(string arg)
{
    ChangeComment();
    return do_cmd(arg);
}

int guildcast(string channel, string who) {
  ChangeComment();
  return ::guildcast(channel, who);
}

int broadcast(string channel, string who) {
  ChangeComment();
  return ::broadcast(channel, who);
}



query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
