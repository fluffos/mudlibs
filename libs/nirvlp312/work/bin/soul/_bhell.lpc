inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look toward the sky and mutter, \"Bloody Hell.\"\n", "#CMN# looks towards the sky and mutters, \"Bloody Hell.\"\n");
       target("You look toward #CTN# and mutter, \"Bloody Hell.\"\n", "#CMN# looks towards #CTN# and mutters, \"Bloody Hell.\"\n", "#CMN# looks towards you and mutters, \"Bloody Hell.\"\n");
       afar("You look toward #CTN# and mutter, \"Bloody Hell.\"\n", "#CMN# looks towards you and mutters, \"Bloody Hell.\"\n");
    }
}

int
cmd_bhell(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
