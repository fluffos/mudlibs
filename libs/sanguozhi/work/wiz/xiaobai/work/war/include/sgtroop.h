// /include/sgtroop.h
// data type for the unit of sg troop
// by xiaobai, August 2001

///////// status of the troops //////////////

#define SGTRP_QIBING        "qibing"
#define SGTRP_MAIFU         "maifu"
#define SGTRP_APPEAR        "appear"
#define SGTRP_COMMANDO      "commando"



class SGtroop
{
	int m_nArmyId;  // 所属方面军
	int m_nTrpId;  // 本队编号

	string m_strLeaders;  // 本队主将

// 本队位置
    string m_strLanding;
    string m_strRoom;
	int m_nPosX;
	int m_nPosY;
	string m_strTerrain;  // 地形

// 状态
	string m_strWarOrder;

	int m_nSoldierNum;
	int m_nTrain;
	int m_nMorale;
	int m_nEnergy;
	
	string m_strStatus;

// 装备
	string m_strRighthandItem;  // 双手武器算右手，
	string m_strLefthandItem;
	string m_strArmor;
	string m_strHorse;
	string m_strCraft;
}
