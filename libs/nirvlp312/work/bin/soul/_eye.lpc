inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look around the room eyeing everyone you see.$N$\n", "#MN# looks around the room eyeing everyone #MS# sees.$N$\n");
       target("You eye #TN# suspiciously.$N$\n", "#MN# eyes #TN# suspiciously.$N$\n", "#MN# eyes you suspiciously.$N$\n");
       afar("You eye #TN# suspiciously from afar.$N$\n", "#MN# eyes you suspiciously from afar.$N$\n");
    }
}

int
cmd_eye(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "wocket"; }
