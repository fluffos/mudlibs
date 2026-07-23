// createmote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping emote;
        string *creat;
        int i;

        if( !arg ) return notify_fail("这个命令生成所有Emote的搜索库到/u/look/emote.txt。\n");
        if( arg != "-creat" ) return notify_fail("这个命令生成所有Emote的搜索库到/u/look/emote.txt。\n");

        creat = sort_array(EMOTE_D->query_all_emote(), 1);
        if( arg == "-creat" ) {
                for(i=0; i<sizeof(creat); i++)
                {
                emote = EMOTE_D->query_emote(creat[i]);
                write_file("/u/look/emote.txt",sprintf("%s#%s%s#%s%s#%s%s#%s%s#%s%s#%s%s#%s",
                        creat[i], emote["myself"], creat[i], emote["others"],
                        creat[i], emote["myself_self"], creat[i], emote["others_self"],
                        creat[i], emote["myself_target"], creat[i], emote["target"],
                        creat[i], emote["others_target"] ));
                }
        }
        write("文件生成完毕。\n");
        return 1;
}

int help(object me)
{
write(@HELP
这个命令生成所有Emote的搜索库到/u/look/emote.txt。
HELP
    );
    return 1;
}
