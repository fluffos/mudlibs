inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look around looking to give someone a sift kick to the pills.$N$\n", "#MN# glances around looking to give someone a sift kick to the pills.$N$\n");
       target("You yell: THINK FAST...#RET#You run up and give #TN# a swift kick to the pills...#RET##TN# hits the ground in pain curling up in a fetal position....#RET#You point at #TN# and go: \"Ha-ha\"!$N$\n", "#MN# yells: THINK FAST...#RET##MN# runs up and gives #TN# a swift kick to the pills...#RET##TN# hit the ground in pain curling up in a fetal position....#RET##MN# points at #TN# and goes: \"Ha-ha\"!$N$\n", "#MN# yells: THINK FAST...#RET##MN# runs up and gives You a swift kick to the pills...#RET#You hit the ground in pain curling up in a fetal position....#RET##MN# points at You and goes: \"Ha-ha\"!$N$\n");
       afar("You yell: THINK FAST...#RET#You run up and give #TN# a swift kick to the pills...#RET##TN# hits the ground in pain curling up in a fetal position....#RET#You point at #TN# and go: \"Ha-ha\"!$N$\n", "#MN# yells: THINK FAST...#RET##MN# runs up and gives You a a swift kick to the pills...#RET#You hit the ground in pain and curl up in a fetal position...#RET##MN# points at You and goes: \"Ha-ha\"!$N$\n");
    }
}

int
cmd_kball(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "wicket"; }
