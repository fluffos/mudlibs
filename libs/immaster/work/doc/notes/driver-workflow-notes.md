- driver 首先根据 config 进行配置，然后分别载入 simul_efun 和 master，最后载入 preload。加载完毕游戏启动，等待玩家连线。
- 当玩家连线时，driver 调用 master_ob -> connect()，返回一个新建的 login_ob，并自动调用 login_ob -> logon()。
- logon()调用守护进程 LOGIN_D -> login()，这里进行账号验证、新账号创建，切换到 user_ob 并进入游戏世界。
- 进入游戏世界之后，driver 通过玩家的行为（指令）及其触发的 apply，以及 heart_beat()、call_out()等对游戏世界进行管理，从游戏世界的角度来看，没有通常意义上程序的起点和终点，而是事件驱动模式。
- driver 的工作模式为一轮一轮的循环，直到 shutdown()或者发生错误崩溃。
- driver 首先将上一个循环内用户输入的指令建立一个列表，然后将上一个循环内计划发送给玩家的 message 全部发送出去，这时 driver 依照指令列表一一执行指令，再逐一执行每一个 heart_beat()，最后执行所有等待的 call_out()，至此一个循环结束，并开启下一轮循环。

* 总结：一个游戏启动、玩家登录并进入游戏世界所需最基本的文件（除 driver 外）：
  - config // 配置文件
  - globals.h // 全局变量头文件
  - simul_efun.c // 模拟 efun
  - master.c // 主控对象
  * preload // 预处理
  - login.c // 登录对象
  - login_d.c // 登录守护进程
  - user.c // 玩家对象
  - void.c // 进入世界的第一个房间
