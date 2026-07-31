一套完整的重起系统
安装说明：
    只需按目录树将各个文件覆盖原有目录下的文件。
文件说明：
1、/adm/daemons/autobootd.c
    自动重起主程序，定时在每天7:30自动重起。重起10分钟前开始倒计时。
如果取消#define REBOOT_TIME 7.5这一行，则系统每24小时重起一次。
2、/adm/etc/preload
    只是增加/adm/daemons/autoboot一行，以便在MUD启动时自动加载autobootd进程。
3、/include/globals.h
    只是增加#define AUTOBOOT_D	"/adm/daemons/autobootd"一行，
  以便MUD里所有程序都可以访问自动重起进程。
4、/cmds/arch/reboot.c
    大巫师以上权限可以重新制定多少分钟后重起。
5、/cmds/usr/uptime.c
    如果MUD将在30分钟后重新启动，则用户登录MUD时会有所提示。
  另外，用户在MUD中也可以通过uptime命令重起时间。