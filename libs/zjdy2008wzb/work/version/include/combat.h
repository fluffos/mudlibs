// SN:fRiBESW9=\<am=TI
// combat.h

#ifndef __COMBAT__
#define __COMBAT__

// 攻击类型

// 常规
#define TYPE_REGULAR            0
// 反击
#define TYPE_RIPOSTE            1
// 突击
#define TYPE_QUICK              2

#define RESULT_DODGE            -1
#define RESULT_PARRY            -2

// 用于在 COMBAT_D 的 skill_power() 中指出技能的
// 用途，以区别计算其威力。
#define SKILL_USAGE_ATTACK      1
#define SKILL_USAGE_DEFENSE     2

// 攻击模式
#define UNARMED_ATTACK          0
#define WEAPON_ATTACK           1

// 远程攻击和穿透性攻击忽略所有的防御功能。
#define REMOTE_ATTACK           2
#define PENETRATE_ATTACK        3

// 默认穿透几率
#define DEFAULT_PENETRATE_RATE  25

// 默认武器自动攻击机率
#define DEFAULT_WEAPON_PERFORM_RATE  10

// action 选项

// 如何启用 / 禁用 / 检查这些选项？
// 在 query_action() 的返回值中，给那个 mapping
// 添加一个叫做 "option" 的键，它的值便是所有需
// 要打开的选项。每个选项用 | 连接。COMBAT_D 检
// 查时会看看  action["option"] 是否 & 了某个选
// 项，例如若 action["option"] & ENABLE_SORT 不
// 为 0 的话，就表示 ENABLE_SORT 这个选项是启用
// 的。

// 如果你想打开大部分的选项，单单禁用掉某一项的
// 话，可以设定为 ENABLE_ALL | ~ENABLE_SORT，这
// 就表示打开其他选项的同时禁用 ENABLE_SORT。

// 范例：
// ([ "action" : "......", 
//    "......" : "......",
//    "option" : ENABLE_SORT | IGNORE_DEFENSE,
//  ]);

// 对于一个防御性的技能，无法返回 action， 它将
// 如何体现它的特性？ 可以采用一个通用的方式(上
// 述的方式是针对单独的一招)：skill_option()，
// 这个函数返回的格式同上述 "option" 的格式一致。
// 例如：
// int query_option() { return IGNORE_FACTOR; }

// 注意：query_option()的参数的第一个永远是指自
// 己，即拥有这个技能的人。第二个是指对方，无论
// 对方是攻击者也好，防御者也好。

// 选项的定义比如按照每个是上一项的 2 倍进行，
// 如 1, 2, 4, 8, 16, 32...即第 n 项是 2 的 n-1
// 次方。

// 输出的信息将被进行排版，按规定字数断行后再行
// 输出。
#define ENABLE_SORT             1

// 忽略防御效果
#define IGNORE_PARRY            2       // 招架技能
#define IGNORE_DODGE            4       // 轻功技能
#define IGNORE_FORCE            8       // 内功技能
#define IGNORE_ARMOR            16      // 衣服护甲

// 忽略掉 parry、dodge、force  技能的特殊防御效
// 果，以及衣服、盔甲的特殊防护功能。
#define IGNORE_DEFENSE          IGNORE_PARRY | IGNORE_DODGE |\
                                IGNORE_FORCE | IGNORE_ARMOR
                                
// 作为防御技能时对与敌方伤害的忽略
#define IGNORE_FORCE_FACTOR     32      // 忽略 jiali
#define IGNORE_CRAZE_FACTOR     64      // 忽略 jianu

// 忽略所有附加点数
#define IGNORE_FACTOR           IGNORE_FORCE_FACTOR |\
                                IGNORE_CRAZE_FACTOR

// 忽略反震
#define IGNORE_RESHOCK          128

// 打开所有的选项
#define ENABLE_ALL              ENABLE_SORT | IGNORE_DEFENSE |\
                                IGNORE_FACTOR | IGNORE_RESHOCK

#endif
