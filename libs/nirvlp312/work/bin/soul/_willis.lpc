inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ask, \"Whatchoo talkin' 'bout, Willis?\"\n", "#MN# asks, \"Whatchoo talkin' 'bout, Willis?\"\n");
       target("You ask #TN#, \"Whatchoo talkin' 'bout, Willis?\"\n", "#MN# asks #TN#, \"Whatchoo talkin' 'bout, Willis?\"\n", "#MN# asks you, \"Whatchoo talkin' 'bout, Willis?\"\n");
       afar("From afar, you ask #TN#, \"Whatchoo talkin' 'bout, Willis?\"\n", "From afar, #MN# asks you, \"Whatchoo talkin' 'bout, Willis?\"\n");
    }
}

int
cmd_willis(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
