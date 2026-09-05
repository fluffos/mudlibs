inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You waggle your eyebrows.$N$\n", "$MN$ waggles $MP$ eyebrows.$N$\n");
       target("You waggle your eyebrows at $TN$.$N$\n", "$MN$ waggles $MP$ eyebrows at $TN$.$N$\n", "$MN$ waggles $MP$ eyebrows at you.$N$\n");
       afar("From afar, you waggle your eyebrows at $TN$.$N$\n", "From afar, $MN$ waggles $MP$ eyebrows at you.$N$\n");
    }
}

int
cmd_waggle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
