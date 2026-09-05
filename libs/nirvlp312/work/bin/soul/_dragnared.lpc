inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ask a question and before anyone can answer, you go idle! Just like Dragnar!$N$\n", "#MN# asks a question and before anyone can answer, #MS# goes idle! Just like Dragnar!$N$\n");
       target("You ask #TN# a question and before #TS# can answer, you go idle! Just like Dragnar!$N$\n", "#MN# asks #TN# a question and before anyone can answer, #TS# goes idle! Just like Dragnar!$N$\n", "#MN# asks you a question and before you can answer, #MS# goes idle! Just like Dragnar!$N$\n");
       afar("From afar, you ask #TN# a question and before #TS# can answer, you go idle! Just like Dragnar!$N$\n", "From afar, #MN# asks you a question and before you can answer, #MS# goes idle! Just like Dragnar!$N$\n");
    }
}

int
cmd_dragnared(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "shinshi"; }
