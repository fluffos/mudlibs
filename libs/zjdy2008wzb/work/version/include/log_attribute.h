// SN:_YSF3Xh?oGS<SOYM
void log_current_attribute(object me)
{
        me->set("current_str", me->query_str());
        me->set("current_int", me->query_int());
        me->set("current_con", me->query_con());
        me->set("current_dex", me->query_dex());
}
