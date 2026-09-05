inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You slap yourself like a $R$red$N$headed stepchild.$N$\n", "#CMN# slaps #MO#self like a $R$red$N$headed stepchild.$N$\n");
       target("You slap #CTN# like a $R$red$N$headed stepchild!$N$\n", "#CMN# slaps #CTN# like a $R$red$N$headed stepchild!$N$\n", "#CMN# slaps you like a $R$red$N$headed stepchild!$N$\n");
       afar("You slap #CTN# like a $R$red$N$headed stepchild, from afar! (Wanker!)$N$\n", "#CMN# slaps you like a $R$red$N$headed stepchild, from afar! (What a fool!)$N$\n");
    }
}

int
cmd_rslap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
