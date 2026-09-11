// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Belboz

#include <daemons.h>
#include <mudlib.h>

inherit CMD;

private void main()
{
    int         pts,total;
    string      rank;

    if( wizardp(this_user()) )
    {
        out("你是一位编程人员。\n");
    }

    pts = this_body()->query_score();
    total = QUEST_D->total_points();
    if(total)
      switch( (100*pts)/total )
        {
        case 0:  rank = "完全新手";break;
        case 1..5: rank = "业余爱好者";break;
        case 6..10: rank = "初级选手";break;
        case 11..20: rank = "入门选手";break;
        case 21..30: rank = "初级探险家";break;
        case 31..40: rank = "中级探险家";break;
        case 41..50: rank = "高级探险家";break;
        case 51..60: rank = "冒险家";break;
        case 61..70: rank = "专业冒险家";break;
        case 71..80: rank = "熟练的玩家";break;
        case 81..90: rank = "完全的玩家";break;
        case 91..99: rank = "老练的玩家";break;
        default:
          if(pts < 0 ) rank = "犯错的小丑";
          else rank = "帮派大佬";
    }
    if(total)
      outf("在%s中，你从 %d 分中拿到了 %d 分，级别是：%s。\n", 
           mud_name(), total, pts, rank );
    else
      outf("在%s中根本没有分数，所以我想你还干得不错。\n", mud_name());
}
