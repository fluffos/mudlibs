inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You poke yourself in the ribs.$N$\n", "#MN# pokes #MO#self in the ribs.$N$\n");
       target("You poke #TN# in the ribs.$N$\n", "#MN# pokes #TN# in the ribs.$N$\n", "#MN# pokes you in the ribs.$N$\n");
       afar("You poke #TN# in the ribs from afar.$N$\n", "#MN# pokes you in the ribs from afar.$N$\n");
    }
}

int
cmd_poke(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
