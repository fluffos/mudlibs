inherit F_CLEAN_UP;

int main(object me)
{
        string *e;
        string str="";
        int i;

        e = EMOTE_D->query_all_emote();

        for(i=sizeof(e)-1; i>=0; i--)
                str+=sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");

        me->start_more(str);
        write("\n");
        return 1;
}
