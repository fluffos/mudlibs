inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You threaten the room with the Wrath of Chett[tm].$N$\n", "#MN# threatens the room with the Wrath of Chett[tm].$N$\n");
       target("You threaten #TN# with the Wrath of Chett[tm].$N$\n", "#MN# threatens #TN# with the Wrath of Chett[tm].$N$\n", "#MN# threatens you with the Wrath of Chett[tm].$N$\n");
       afar("You threaten #TN# with the Wrath of Chett[tm] from afar.$N$\n", "#MN# threatens you with the Wrath of Chett[tm] from afar.$N$\n");
    }
}

int
cmd_threaten(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
