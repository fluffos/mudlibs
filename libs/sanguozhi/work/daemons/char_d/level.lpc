// level.c by fire on Dec 1998
int get_char_nation_level(string p_id)
{
    return OFFICER_D->query_level
       (CHAR_D->get_char(p_id,"ranknation"));
}
int get_char_local_level(string p_id)
{
    return OFFICER_D->query_level
       (CHAR_D->get_char(p_id,"ranklocal"));
}
int get_char_level(string p_id)
{
    int ln,ll;
    ln=get_char_nation_level(p_id);
    ll=get_char_local_level(p_id);
    return bmax(ln,ll);
}
