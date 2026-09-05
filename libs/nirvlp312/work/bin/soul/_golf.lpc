inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say: \"Golf?\" \"Oh yeah, love to golf....big into golf#RET#Takes me 14,000 strokes on each hole#RET#I look like a friggin' propeller out there#RET#I peel up so much sod they call me the Farmer!\"\n", "#MN# says: \"Golf?\" \"Oh yeah, love to golf....big into golf#RET#Takes me 14,000 strokes on each hole#RET#I look like a friggin' propeller out there#RET#I peel up so much sod they call me the Farmer!\"\n");
       target("You say to #TN#: \"Golf?\" \"Oh yeah, love to golf....big into golf#RET#Takes me 14,000 strokes on each hole#RET#I look like a friggin' propeller out there#RET#I peel up so much sod they call me the Farmer!\"\n", "#MN# says to #TN#: \"Golf?\" \"Oh yeah, love to golf....big into golf#RET#Takes me 14,000 strokes on each hole#RET#I look like a friggin' propeller out there#RET#I peel up so much sod they call me the Farmer!\"\n", "#MN# says to you: \"Golf?\" \"Oh yeah, love to golf....big into golf#RET#Takes me 14,000 strokes on each hole#RET#I look like a friggin' propeller out there#RET#I peel up so much sod they call me the Farmer!\"\n");
       afar("$HY$[afar]$N$ You say to #TN#: \"Golf?\" \"Oh yeah, love to golf....big into golf#RET#$HY$[afar]$N$ Takes me 14,000 strokes each hole#RET#$HY$[afar]$N$ I look like a friggin' propeller out there#RET#$HY$[afar]$N$ I peel up so much sod they call me the Farmer!\"\n", "$HY$[afar]$N$ #MN# says to you: \"Golf?\" \"Oh yeah, love to golf....big into golf#RET#$HY$[afar]$N$ Takes me 14,000 strokes on each hole#RET#$HY$[afar]$N$ I look like a friggin' propeller out there#RET#$HY$[afar]$N$ I peel up so much sod they call me the Farmer!\"\n");
    }
}

int
cmd_golf(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
