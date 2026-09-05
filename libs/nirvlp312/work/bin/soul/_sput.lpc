inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sput mightily.$N$\n", "#MN# sputs mightily.$N$\n");
       target("You sput at #TN#.$N$\n", "#MN# sputs at #TN#.$N$\n", "#MN# sputs at you.$N$\n");
       afar("[afar]You sput at #TN#.$N$\n", "[afar]#MN# sputs at you.$N$\n");
    }
}

int
cmd_sput(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
