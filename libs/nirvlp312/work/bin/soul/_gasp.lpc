inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You gasp in astonishment!$N$\n", "#MN# gasps in astonishment!$N$\n");
       target("You gasp in astonishment at #TN#!$N$\n", "#MN# gasps in astonishment at #TN#!$N$\n", "#MN# gasps in astonishment at you!$N$\n");
       afar("You gasp in astonishment at #TN# from afar!$N$\n", "#MN# gasps in astonishment at you from afar!$N$\n");
    }
}

int
cmd_gasp(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
