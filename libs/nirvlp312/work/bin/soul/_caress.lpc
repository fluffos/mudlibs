inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You caress yourself lovingly.$N$\n", "#MN# caresses #MO#self lovingly.$N$\n");
       target("You caress #TN# lovingly.$N$\n", "#MN# caresses #TN# lovingly.$N$\n", "#MN# caresses you lovingly.$N$\n");
       afar("You caress #TN# lovingly from afar.$N$\n", "#MN# caresses you lovingly from afar.$N$\n");
    }
}

int
cmd_caress(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
