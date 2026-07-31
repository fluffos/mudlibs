// SN:a6`B[X@i[ecZC[i@
void log_current_attribut(object me)
{
                me->set("current_attribut/str", me->query_str());
                me->set("current_attribut/int", me->query_int());
                me->set("current_attribut/con", me->query_con());
                me->set("current_attribut/dex", me->query_dex());
}
