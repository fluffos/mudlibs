inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: \"Heh\" in agreement.\n", "#MN# goes: \"Heh\" in agreement.\n");
       target("You go: \"Heh\" in agreement with #TN#.\n", "#MN# goes: \"Heh\" in agreement with #TN#.\n", "#MN# goes \"Heh\" in agreement with you.\n");
       afar("You go \"Heh\" in agreement with #TN# from afar.\n", "From afar, #MN# goes \"Heh\" in agreement with you.\n");
    }
}

int
cmd_hagree(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
