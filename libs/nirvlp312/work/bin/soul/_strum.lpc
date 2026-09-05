inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You strum your guitar adeptly.\n", "#MN# strums #MP# guitar adeptly.\n");
       target("You strum your guitar adeptly for #TN#.\n", "#MN# strums #MP# guitar adeptly for #TN#.\n", "#MN# strums #MP# guitar adeptly for you.\n");
       afar("You strum your guitar adeptly for #TN# from afar.\n", "#MN# strums #MP# guitar adeptly for you from afar.\n");
    }
}

int
cmd_strum(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
