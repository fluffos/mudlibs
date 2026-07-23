//  emeid.h in /d/menpai/emei/std
//  Amber Edit on 1997-12-22
//  Amber@XO reEdit in 1999.1~2 for XO 1.5~2.0

// defines
// EMEI_D调用自己的循环间隔（60秒，相当于一个时辰）
#define HEART_BEAT_TICK                                             30
#include <pair.h>
//自动调用的计数器
private nosave int nHeartBeatNumber = 0;
///////////////////////////////////////////////////////////////////////
// 用来记录发生过的事情：更简单的调用方法还可以是set和query
mapping m_ActionData;//格式为： 「物件」/「事件」:「状态」
// 需要进行移动的NPC
/*private nosave class Pair * t_NpcList = ({
    {   Key = EMEI_DIR "npc/yunyou_daoshi1";
        Value = 5;
    },//  云游道士2种10个
    {   Key = EMEI_DIR "npc/yunyou_daoshi2";
        Value = 5;
    },
    {   Key = EMEI_DIR "npc/youfang_seng1";
        Value = 3;
    },//  游方僧5种15个
    {   Key = EMEI_DIR "npc/youfang_seng2";
        Value = 3;
    },
    {   Key = EMEI_DIR "npc/youfang_seng3";
        Value = 3;
    },
    {   Key = EMEI_DIR "npc/youfang_seng4";
        Value = 3;
    },
    {   Key = EMEI_DIR "npc/youfang_seng5";
        Value = 3;
    },
});
*/
///////////////////////////////////////////////////////////////////////
// 针对daemon负责存储的区域内事件的发生状态进行存取。
mixed GetActionRecord( string ObName, string EventID );
void SetActionRecord( string ObName, string EventID, mixed status );
///////////////////////////////////////////////////////////////////////
// 找到所有峨眉派的NPC/玩家（在线）
object * FindMembers( int IsUser );
// 找出某人最高修为项
class Pair GetBestXiuweiType( object who );
// 返回一天的时间段： 「早上」「下午」「晚上」，用来打招呼
string GetDayPhase();
//////////////////////////////////////////////////////////////////////
int IsTongmenOf( object who )// 是否是峨眉派弟子
{
    return ( who->query("family/family_name") == "峨嵋派" );
}
