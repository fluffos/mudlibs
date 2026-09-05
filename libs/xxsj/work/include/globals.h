// globals.h - 全局头文件
// 自动包含在所有 LPC 文件中

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

// 常用目录定义
#define COMMAND_DIR     "/command/"
#define CLONE_DIR       "/clone/"
#define ROOM_DIR        "/room/"
#define SINGLE_DIR      "/single/"

// 核心对象
#define MASTER_OB       "/single/master"
#define SIMUL_EFUN_OB   "/single/simul_efun"
#define USER_OB         "/clone/xiuxian_user"
#define VOID_OB         "/room/xiuxian/square"

// ANSI 颜色代码 - 已禁用，使用纯文本
#define RESET       ""
#define BOLD        ""
#define BLACK       ""
#define RED         ""
#define GREEN       ""
#define YELLOW      ""
#define BLUE        ""
#define MAGENTA     ""
#define CYAN        ""
#define WHITE       ""

// 高亮颜色 - 已禁用，使用纯文本
#define HIR         ""  // 高亮红色
#define HIG         ""  // 高亮绿色
#define HIY         ""  // 高亮黄色
#define HIB         ""  // 高亮蓝色
#define HIM         ""  // 高亮品红
#define HIC         ""  // 高亮青色
#define HIW         ""  // 高亮白色

// 常用宏
#define ME          this_player()
#define ENV(x)      environment(x)
#define HERE        environment(this_player())

#endif // __GLOBALS_H__
