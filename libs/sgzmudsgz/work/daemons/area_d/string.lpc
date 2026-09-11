// string.c by fire on Dec. 20 1998
string get_area_importancestr(string p_id)
{
   int i=AREA_D->get_area(p_id,"importance");
   switch(i)
   {
    case AI_INDUSTRY:
       return "工业";
    case AI_AGRICULTURE:
       return "农业";
    case AI_BUSINESS:
       return "商业";
    case AI_SAFE:
       return "安定";
    case AI_MILITARY:
       return "军事";
    default:
       return "均衡";
   }
}
string get_area_statusstr(string p_id)
{
        int p_st;
        p_st=AREA_D->get_area(p_id,"status");
        switch(p_st)
        {
        case ST_NOOFFICER:
                return "空白";
        case ST_NORMAL:
                return "正常";
        case ST_WAR:
                return "战争";
        case ST_MEETING:
                return "会议";
       case ST_TRAIN:
              return "练兵";
        }
        return "未知";
}
