/**
 * @brief 武圣真意系统配置常量
 * @author LPC开发者
 * @date 2024
 * @details 集中定义所有配置常量，消除魔法数字
 */

#ifndef __ZHENYI_CONSTANTS_H__
#define __ZHENYI_CONSTANTS_H__

// ==================== 背包相关常量 ====================
#define ZHENYI_BAG_MAX_CAPACITY       1000      // 背包最大容量
#define ZHENYI_BAG_DEFAULT_CAPACITY   1000      // 背包默认容量

// ==================== 合成系统常量 ====================
#define ZHENYI_SYNTHESIS_MIN_LEVEL    100       // 合成所需最低等级
#define ZHENYI_SYNTHESIS_COUNT        3         // 合成所需真意数量
#define ZHENYI_SYNTHESIS_MAX_HISTORY  100       // 最大历史记录数量
#define ZHENYI_LEVEL_RANGE_STEP       100       // 等级分组步长

// ==================== 分解系统常量 ====================
#define ZHENYI_DECOMPOSE_MAX_HISTORY  50        // 分解最大历史记录数量

// ==================== 方案管理常量 ====================
#define ZHENYI_SCHEME_NAME_MAX_LENGTH 12        // 方案名称最大长度
#define ZHENYI_SCHEME_NAME_MIN_LENGTH 1         // 方案名称最小长度
#define ZHENYI_SCHEME_MAX_COUNT       10        // 最大方案数量

// ==================== 品质等级常量 ====================
#define ZHENYI_QUALITY_FANGCHEN       1         // 凡尘真意品质等级
#define ZHENYI_QUALITY_TONGMING       2         // 通明真意品质等级
#define ZHENYI_QUALITY_LINGXI         3         // 灵犀真意品质等级
#define ZHENYI_QUALITY_XUANAO         4         // 玄奥真意品质等级
#define ZHENYI_QUALITY_WUWO           5         // 无我真意品质等级
#define ZHENYI_QUALITY_ZHENWU         6         // 真武真意品质等级

#define ZHENYI_MIN_SYNTHESIS_QUALITY  3         // 最低可合成品质等级（蓝色）

// ==================== 武蕴点数常量 ====================
#define WUYUN_VALUE_FANGCHEN          1         // 凡尘真意武蕴值
#define WUYUN_VALUE_TONGMING          2         // 通明真意武蕴值
#define WUYUN_VALUE_LINGXI            5         // 灵犀真意武蕴值
#define WUYUN_VALUE_XUANAO            10        // 玄奥真意武蕴值
#define WUYUN_VALUE_WUWO              15        // 无我真意武蕴值
#define WUYUN_VALUE_ZHENWU            20        // 真武真意武蕴值

// ==================== 等级倍率常量 ====================
#define ZHENYI_BASE_LEVEL             100       // 基准等级
#define ZHENYI_LEVEL_MULTIPLIER_STEP  1.5       // 每100级的倍率增长系数

// ==================== 日志相关常量 ====================
#define ZHENYI_LOG_TYPE_INFO          "info"
#define ZHENYI_LOG_TYPE_ERROR         "error"
#define ZHENYI_LOG_TYPE_WARNING       "warning"
#define ZHENYI_LOG_TYPE_SUCCESS       "success"
#define ZHENYI_LOG_TYPE_CRITICAL      "critical"

#endif /* __ZHENYI_CONSTANTS_H__ */
