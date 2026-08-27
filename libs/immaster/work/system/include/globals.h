//启动时自动加载

#ifndef GLOBALS_H
#define GLOBALS_H

//管理员账号
#define WIZARD "teamug"

// 外部底层核心
#define CORE_DIR "ext/mudcore/"

//系统底层
#define SYSTEM_DIR "system/core/"
#define SYSTEM_STD "system/std/"
#define SYSTEM_OBJ "system/obj/"
#define INHERIT_DIR "system/inherit/"

//功能模块
#include "inherit.h"
//守护进程
#include "daemons.h"
//标准继承对象
#include "stdob.h"

// 系统
#define MASTER_OB       SYSTEM_DIR "kernel/master"
#define SIMUL_EFUN_OB   SYSTEM_DIR "kernel/simul_efun"
#define LOGIN_OB        SYSTEM_DIR "object/login"
#define USER_OB         SYSTEM_DIR "object/user"
#define VOID_OB         SYSTEM_DIR "object/void"

//数据存储
#define LOG_DIR "log/"
#define DATA_DIR "data/"

// 其他
#define HTTP_PORT 8888
#define MOTD      SYSTEM_DIR "etc/motd"
#define PRELOAD   SYSTEM_DIR "kernel/master/preload"

// 指令路径
#define CMD_PATH_WIZ ({"system/cmds/wizard/", "ext/mudcore/cmds/wizard/"})
#define CMD_PATH_STD ({"system/cmds/player/", "ext/mudcore/cmds/player/"})

//游戏世界
#define WORLD_DIR  "game/world/"
#define START_ROOM  WORLD_DIR "tutorial/start_room"


// 核心框架头文件
#include <mudcore.h>

#endif