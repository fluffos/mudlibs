inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You pick your nose.$N$\n", "#MN# picks #MP# nose.$N$\n");
       target("You pick your nose with #TN#'s finger.$N$\n", "#MN# picks #MP# nose with #TN#'s finger.$N$\n", "#MN# picks #MP# nose with your finger.$N$\n");
       afar("Somehow you manage to pick your nose with #TN#'s finger from afar.$N$\n", "Somehow, #MN# manages to pick #MP# nose with your finger from afar!$N$\n");
    }
}

int
cmd_npick(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "earwax"; }
