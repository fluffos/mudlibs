inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You declare it to be a jacktacular day.$N$\n", "#MN# declares it to be one jacktacular day.$N$\n");
       target("You declare #TN# to be jacktacular.$N$\n", "#MN# declares #TN# to be jacktacular.$N$\n", "#MN# declares you to be jacktacular.$N$\n");
       afar("You declare #TN# to be jacktacular from afar.$N$\n", "#MN# declares you to be jacktacular from afar.$N$\n");
    }
}

int
cmd_jacktacular(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
