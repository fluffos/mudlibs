// /include/sgarmy.h
// data type for the unit of sg army, a army for each city
// by xiaobai, August 2001

class SGarmy
{
    int m_nTaskId;  // task id in which this army is
    
	int m_nArmyId;  // 方面军 id
	string m_strArmyName;  // 方面军名字

	string m_strNationId;  // 所属国家代号
	string m_strCityId;  // 所属城市代号

	string m_strLeaderId;  // 主帅

	string m_strSide;  // a 为进攻方，d 为防守方

	string m_strColor;  // 显示的颜色

	int m_nFood;  // 粮草
	int m_nGold;  // 金
	string m_strCaptive  // 俘虏名单 

	int m_nCntTroop;  // troop 数目的计数器
	
	mapping m_mTrpIds;  // array of the troop id
}
