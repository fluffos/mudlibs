inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You let out a very loud grunt in satisfaction.$N$\n", "#MN# lets out a very loud grunt in satisfaction.$N$\n");
       target("You look at #TN# letting out a very loud grunt in satisfaction.$N$\n", "#MN# looks at #TN# letting out a very loud grunt in satisfaction.$N$\n", "#MN# looks at you letting out a very loud grunt in satisfaction.$N$\n");
       afar("<From Afar> You look at #TN# letting out a very loud grunt in satisfaction.$N$\n", "<From Afar> #MN# looks at you letting out a very loud grunt in satisfaction.$N$\n");
    }
}

int
cmd_grunt(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "wicket"; }
