inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go \"Heh\" in a negative fashion.$N$\n", "#MN# goes: \"Heh\" in a negative fashion.$N$\n");
       target("You go: \"Heh\" in a negative fashion at #TN#.$N$\n", "#MN# goes: \"Heh\" in a negative fashion at #TN#.$N$\n", "#MN# goes: \"Heh\" in a negative fashion at you.$N$\n");
       afar("You go: \"Heh\" in a negative fashion at #TN# from afar.$N$\n", "#MN# goes: \"Heh\" in a negative fashion at you from afar.$N$\n");
    }
}

int
cmd_hehno(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
