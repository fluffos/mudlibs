#ifndef __VRM__
#define __VRM__

// 迷宫名称列表
nosave mapping vrm_name_list = ([
#if VRM_0001_SUPPORT
    "VRM_0001":    "埋骨之地",    // 基础副本 
#endif
#if VRM_0002_SUPPORT
    "VRM_0002":    "天外天",    // 1转副本
#endif
#if VRM_0003_SUPPORT
    "VRM_0003":    "镇魔塔林",    // 2转副本，解谜tianmo用
#endif
#if VRM_0004_SUPPORT
    "VRM_0004":    "冥河",    // 3转副本
#endif
#if VRM_0005_SUPPORT
    "VRM_0005":    "上古洪荒",    // 4转副本
#endif
#if VRM_0011_SUPPORT
    "VRM_0011":    "归墟",    // 5转副本
#endif
#if VRM_0502_SUPPORT
    "VRM_0502":    "试炼之地",    // 解谜副本
#endif
#if VRM_0501_SUPPORT
    "VRM_0501":    "蛇洞",    // 低级副本
#endif
]);

// 迷宫存在时间列表，时间最好在15到120分钟之间
nosave mapping vrm_exist_time_list = ([
#if VRM_0001_SUPPORT
    "VRM_0001":    3600,        // 埋骨之地    // 1小时
#endif
#if VRM_0002_SUPPORT
    "VRM_0002":    3600,        // 天外天    // 1小时
#endif
#if VRM_0003_SUPPORT
    "VRM_0003":    3600,        // 镇魔塔林    // 1小时
#endif
#if VRM_0004_SUPPORT
    "VRM_0004":    3600,        // 冥河    // 1小时
#endif
#if VRM_0005_SUPPORT
    "VRM_0005":    3600,        // 上古洪荒    // 1小时
#endif
#if VRM_0011_SUPPORT
    "VRM_0011":    3600,        // 归墟    // 1小时
#endif
#if VRM_0502_SUPPORT
    "VRM_0502":    1800,        // 试炼之地    // 半小时
#endif
#if VRM_0501_SUPPORT
    "VRM_0501":    1800,        // 蛇洞    // 半小时
#endif
]);

#if RDM_VRM_SUPPORT

#define RDM_VRM_REFRESH_TIME    1800    // 随机迷宫刷新时间，半小时
#define RDM_VRM_CLOSE_TIME    900    // 随机迷宫门口关闭时间，30分钟
int refresh_rdm_vrm_time;        // 保存刷新随机迷宫的时间

int close_rdm_vrm_time;            // 保存关闭随机迷宫入口的时间
object close_rdm_vrm_room;        // 保存关闭随机迷宫入口的房间

nosave string *rdm_vrm_list = ({  // 随机刷新迷宫表

});
nosave string *rdm_vrm_entry_list = ({    // 随机刷新迷宫的随机入口地点
"/d/moon/yunu5",
"/d/qujing/jindou/shanshi2",
"/d/qujing/jilei/jilei2",
});

#endif


// 迷宫更新时间列表，时间最好在120到360分钟之间
nosave mapping vrm_reset_time_list = ([
#if VRM_0001_SUPPORT
    "VRM_0001":    7200,        // 埋骨之地    // 2小时
#endif
#if VRM_0002_SUPPORT
    "VRM_0002":    7200,        // 天外天    // 2小时
#endif
#if VRM_0003_SUPPORT
    "VRM_0003":    7200,        // 镇魔塔林    // 2小时
#endif
#if VRM_0004_SUPPORT
    "VRM_0004":    7200,        // 冥河    // 2小时
#endif
#if VRM_0005_SUPPORT
    "VRM_0005":    7200,        // 上古洪荒    // 2小时
#endif
#if VRM_0011_SUPPORT
    "VRM_0011":    7200,        // 归墟    // 2小时
#endif
#if VRM_0501_SUPPORT
    "VRM_0501":    3600,        // 蛇洞    // 1小时
#endif
#if VRM_0502_SUPPORT
    "VRM_0502":    3600,        // 试炼之地    // 半小时
#endif
]);


#endif
