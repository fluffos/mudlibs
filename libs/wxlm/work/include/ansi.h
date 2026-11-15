 
//	文件	:  /include/ansi.h
 
#define ESC	"" // 定义转义字符
#define CSI	ESC + "[" // 定义控制序列引导符
#define BEL	ESC + "[s" // 定义响铃字符

		/*  前景色  */

#define BLK ESC+"[30m"	  /* 黑色    */
#define RED ESC+"[31m"	  /* 红色      */
#define GRN ESC+"[32m"	  /* 绿色    */
#define YEL ESC+"[33m"	  /* 黄色   */
#define BLU ESC+"[34m"	  /* 蓝色     */
#define MAG ESC+"[35m"	  /* 品红  */
#define CYN ESC+"[36m"	  /* 青色     */
#define WHT ESC+"[37m"	  /* 白色    */
 
		/*  高亮前景色   */
 
#define HIR ESC+"[1;31m"	/* 红色      */
#define HIG ESC+"[1;32m"	/* 绿色    */
#define HIY ESC+"[1;33m"	/* 黄色   */
#define HIB ESC+"[1;34m"	/* 蓝色     */
#define HIM ESC+"[1;35m"	/* 品红  */
#define HIC ESC+"[1;36m"	/* 青色     */
#define HIW ESC+"[1;37m"	/* 白色    */

		/* 高亮背景色  */

#define HBRED ESC+"[41;1m"       /* 红色      */
#define HBGRN ESC+"[42;1m"       /* 绿色    */
#define HBYEL ESC+"[43;1m"       /* 黄色   */
#define HBBLU ESC+"[44;1m"       /* 蓝色     */
#define HBMAG ESC+"[45;1m"       /* 品红  */
#define HBCYN ESC+"[46;1m"       /* 青色     */
#define HBWHT ESC+"[47;1m"       /* 白色    */
 
		/*  背景色  */
 
#define BBLK ESC+"[40m"	  /* 黑色    */
#define BRED ESC+"[41m"	  /* 红色      */
#define BGRN ESC+"[42m"	  /* 绿色    */
#define BYEL ESC+"[43m"	  /* 黄色   */
#define BBLU ESC+"[44m"	  /* 蓝色     */
#define BMAG ESC+"[45m"	  /* 品红  */
#define BCYN ESC+"[46m"	  /* 青色     */

#define NOR ESC+"[2;37;0m"      /* 恢复默认颜色 */
 
/*  由 Gothic 于 1993 年 4 月 23 日添加到 ansi.h 的其他 ansi Esc 代码 */
/* 注意，这些是 VT100 终端和模拟器的 Esc 代码 */
/*       它们可能并非全部在 mud 中工作	       */
 
#define BOLD ESC+"[1m"	  /* 粗体 */
#define CLR ESC+"[2J"	   /* 清屏  */
#define HOME ESC+"[H"	   /* 光标回到初始位置 */
#define REF CLR+HOME	    /* 清屏并将光标回到初始位置 */
#define BIGTOP ESC+"#3"	 /* 双倍高度字符，上半部分 */
#define BIGBOT ESC+"#4"	 /* 双倍高度字符，下半部分 */
#define SAVEC ESC+"[s"	  /* 保存光标位置 */
#define REST ESC+"[u"	   /* 恢复光标到保存的位置 */
//#define REVINDEX ESC+"M       /* 反方向滚动屏幕 */
#define SINGW ESC+"#5"	  /* 正常，单宽度字符 */
#define DBL ESC+"#6"	    /* 创建双宽度字符 */
#define FRTOP ESC+"[2;25r"      /* 冻结顶行 */
#define FRBOT ESC+"[1;24r"      /* 冻结底行 */
#define UNFR ESC+"[r"	   /* 解冻顶行和底行 */
#define BLINK ESC+"[5m"	 /* 闪烁 */
#define U ESC+"[4m"	     /* 下划线 */
#define REV ESC+"[7m"	   /* 反显 */
#define HIREV ESC+"[1,7m"       /* 高亮反显  */
 

