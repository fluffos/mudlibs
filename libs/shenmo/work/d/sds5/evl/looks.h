void broadcast(string str)
{
string prefix = this_object()->query("short")+"\t";
string s1 = str, s2 = "";
while (strsrch(s1,"\n\n") != -1)
        s1 = replace_string(s1,"\n\n","\n");

if (s1[strlen(s1)-1]=='\n')
        {
        s1 = s1[0..strlen(s1)-2];
        s2 = "\n";
        }
if (strlen(s1) == 0)
        return;
s1 = replace_string(s1,"\n","\n"+prefix)+"";
reset_eval_cost();
tell_room( "/u/snowtu/workroom","\n"+prefix+s1+"\n" );
}


