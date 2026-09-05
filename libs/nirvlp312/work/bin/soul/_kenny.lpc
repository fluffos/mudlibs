inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You exclaim \"Oh my god, they killed Kenny! THEY'RE $HR$BASTARDS$N$!!\"\n", "#MN# exclaims \"Oh my god, they killed Kenny! THEY'RE $HR$BASTARDS$N$!!\"\n");
       target("You point at #TN# and exclaim \"Oh my god, you killed Kenny! YOU $HR$BASTARD$N$!!\"\n", "#MN# points at #TN# and exclaims \"Oh my god, you killed Kenny!  YOU $HR$BASTARD$N$!!\"$N\n", "#MN# points at you and exclaims \"Oh my god, you killed Kenny! You $HR$BASTARD$N$!!\"\n");
       afar("You point at #TN# and exclaim \"Oh my god, you killed Kenny! YOU $HR$BASTARD$N$!!\" $HK$[$HW$Afar$HK$]$N$\n", "#MN# points at you and exclaims \"Oh my god, you killed Kenny! YOU $HR$BASTARD$N$!!\" $HK$[$HW$Afar$HK$]$N$\n");
    }
}

int
cmd_kenny(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
