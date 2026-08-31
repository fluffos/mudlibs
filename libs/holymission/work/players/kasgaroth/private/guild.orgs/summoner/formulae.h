#define MAXBP        (30 + (10 * TP->LEVEL) + (8 * TP->STR) + (5 * TP->INT))
#define MAXCREATURES 3
#define SUCCESS      (25 + TP->CHA + TP->WIS - TO->LEVEL)
#define DEF_CHANCE   ((20 + TO->AC) + (TP->LEVEL / 3) + (TP->DEX / 5))
#define RET_CHANCE   ((100 - DEF_CHANCE) / 2)
#define GOLEM_DES_SP 25
#define MAXINTOX     5

#define BOLT_DAM     (50 + TP->STR + TP->DEX)
#define MAGMA_DAM    (50 + (TP->STR / 2) + (TP->DEX / 2))
#define BLAZE_DAM    (20 + (TP->STR / 2) + (TP->DEX / 2))
#define CYCLONE_DAM  (20 + (TP->STR / 2) + (TP->DEX / 2))
#define ICE_DAM      (10 + (TP->STR / 2) + (TP->DEX / 2))
#define SMOKE_AC     (2 + (TP->DEX / 10))
#define SMOKE_TIME   (5 + (TP->DEX / 3))
#define MUD_TIME     (2 + (TP->STR / 5))

#define ROC_SUM_SP   25

#define RAVEN_SUM_SP 10
#define RAVEN_BAN_SP 10
#define RT_SP        2

#define WISP_DAM     50
#define WISP_BAN_SP  10
#define WISP_LS      (1 + TP->LEVEL / 6)

#define BEAST_DAM    100
#define BEAST_TAK_SP 5
#define BEAST_GIV_SP 5
#define BEAST_DRP_SP 5
#define BEAST_BAN_SP 10
#define BEAST_CAP    (TP->STR + 10)

#define SEEK_DAM     100
#define SEEK_BAN_SP  10
#define SEEK_GO_SP   10
#define SEEK_ENT_SP  10
#define SEEK_L_SP    5
#define SEEK_LA_SP   5
#define SEEK_LINK_SP 20
#define SEEK_RET_SP  15
#define SEEK_NAME_SP 5
#define SEEK_SAY_SP  5
#define SEEK_EMOT_SP 5
#define SEEK_FOL_SP 20

#define ATT_ATK_SP   10
#define ATT_STOP_SP  20
#define ATT_TER_SP   50

#define TENT_CHN     5
#define TENT_DAM     30

#define FIRE_CHN     5
#define FIRE_DAM     50

