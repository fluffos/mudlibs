//  峨眉派：emei.h
//  Amber reEdit on 1998 Apr ~ July.    Program for XO edition 1.0, 1.5
//  Amber@XO reEdit in 1999.1~2 for XO 1.5~2.0


//////////////////////////////////////////////////////////////////////
//  room define
#define EMEI_DIR                            "/d/menpai/emei/"
#define EMEI_HILL                           EMEI_DIR "std/hill"
#define EMEI_SROOM                          EMEI_DIR "std/small_room"
#define EMEI_BROOM                          EMEI_DIR "std/big_room"
#define EMEI_STREET                         EMEI_DIR "std/big_room"
#define EMEI_RESTROOM                       EMEI_DIR "std/restroom"
//////////////////////////////////////////////////////////////////////
//  directory define
#define EMEI_OBJ                            EMEI_DIR "obj/"
#define EMEI(x)                           ( EMEI_DIR "std/action/" + x )
//////////////////////////////////////////////////////////////////////
//  inherit define
#define EMEIDIZI                            EMEI_DIR "std/emeidizi"
// QUEST_NPC是具有特殊功能如解密，传功等的NPC
#define QUEST_NPC                           NPC
// COMM_NPC没有陪练、解密、传功等功能的一类很简单的NPC，尽量不附加过多的函数
#define COMM_NPC                            NPC
#define MONK                                EMEI_DIR "std/monk"
#define TAOIST                              EMEI_DIR "std/taoist"
// 标准乐器，以后应该挪到globals去
#define MUSIC                               ITEM
//////////////////////////////////////////////////////////////////////
// emei daemon
#define EMEI_D                              "/system/menpai/emeid"
//////////////////////////////////////////////////////////////////////
// emei feature
#define AUTO_NPC                            EMEI_DIR "std/autonpc"
//////////////////////////////////////////////////////////////////////
//  certain number
//  一天的秒数
#define DAY_PHASE                           720
//////////////////////////////////////////////////////////////////////

