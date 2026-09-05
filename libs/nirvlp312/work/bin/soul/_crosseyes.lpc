inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cross your eyes and look very stupid.$N$\n", "$MN$ crosses $MP$ eyes and looks very stupid.$N$\n");
       target("You look at $TN$ and cross your eyes.$N$\n", "$MN$ crosses $MP$ eyes and looks at $TN$.$N$\n", "$MN$ crosses $MP$ eyes and looks at you.$RET$You can almost feel yourself getting dumber.$N$\n");
       afar("From afar, you look at $TN$ and cross your eyes.$N$\n", "From afar, $MN$ crosses $MP$ eyes and looks at you.$RET$You can almost feel yourself getting dumber.$N$\n");
    }
}

int
cmd_crosseyes(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
