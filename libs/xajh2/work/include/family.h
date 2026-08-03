// family.h
// Qyz

#ifndef __FAMILY__
#define __FAMILY__

#define EAST        "无量剑派东宗"
#define WEST        "无量剑派西宗"
#define KONGDONG    "崆峒派"
#define PENGLAI     "蓬莱派"
#define DUANSHI     "镇南王府"
#define FUNIU       "伏牛派"
#define SHAOLIN     "少林派"
#define KUNLUN      "昆仑派"
#define XINGXIU     "星宿派"
#define MURONG      "姑苏慕容"
#define GAIBANG     "丐帮"
#define TIANSHAN    "天山派"

#define ALL_FAMILYS ({ EAST, WEST, KONGDONG, PENGLAI, DUANSHI, \
                       FUNIU, SHAOLIN, KUNLUN, XINGXIU, MURONG, \
                       GAIBANG, TIANSHAN})
                

#define FAMILY_ENEMY    2
#define FAMILY_FRIEND   1

#define MURONG_ENEMY    ({ XINGXIU, FUNIU, DUANSHI, SHAOLIN, })
#define XINGXIU_ENEMY   ({ MURONG, SHAOLIN, EAST, WEST, DUANSHI, KONGDONG })
#endif
