inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You poke yourself in the eye with a stick, moron!$N$\n", "#MN# pokes themself in the eye with a stick.$N$\n");
       target("You poke #TN# with a stick.$N$\n", "#MN# pokes #TN# with a stick.$N$\n", "#MN# pokes you with a stick.$N$\n");
       afar("Somehow, from afar, you manage to poke #TN# with a stick.$N$\n", "Somehow, from afar, #MN# manages to poke you with a stick.$N$\n");
    }
}

int
cmd_pokest(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
