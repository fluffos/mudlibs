//	File	:  /include/ansi.h
//	Creator	:  Jjgod@VRHF
//	这是MUDLIB的标准颜色设置，由Jjgod汉化
 
#define ESC	""
#define CSI	ESC + "["
 
                /*  前景色  */
 
#define BLK ESC+"[30m"          /* 黑色    */
#define RED ESC+"[31m"          /* 红色      */
#define GRN ESC+"[32m"          /* 绿色    */
#define YEL ESC+"[33m"          /* 黄色   */
#define BLU ESC+"[34m"          /* 蓝色     */
#define MAG ESC+"[35m"          /* 紫色  */
#define CYN ESC+"[36m"          /* 青色     */
#define WHT ESC+"[37m"          /* 白色    */
 
                /*  加强前景色   */
 
#define HIR ESC+"[1;31m"        /* 亮红      */
#define HIG ESC+"[1;32m"        /* 亮绿    */
#define HIY ESC+"[1;33m"        /* 亮黄   */
#define HIB ESC+"[1;34m"        /* 亮蓝    */
#define HIM ESC+"[1;35m"        /* 亮紫  */
#define HIC ESC+"[1;36m"        /* 亮青     */
#define HIW ESC+"[1;37m"        /* 亮白    */

                /* 加强背景色  */

#define HBRED ESC+"[41;1m"       /* 亮红      */
#define HBGRN ESC+"[42;1m"       /* 亮绿    */
#define HBYEL ESC+"[43;1m"       /* 亮黄   */
#define HBBLU ESC+"[44;1m"       /* 亮蓝     */
#define HBMAG ESC+"[45;1m"       /* 亮紫  */
#define HBCYN ESC+"[46;1m"       /* 亮青    */
#define HBWHT ESC+"[47;1m"       /* 亮白    */
 
                /*  背景色  */
 
#define BBLK ESC+"[40m"          /*黑色    */
#define BRED ESC+"[41m"          /*红色      */
#define BGRN ESC+"[42m"          /*绿色    */
#define BYEL ESC+"[43m"          /*  黄色  */
#define BBLU ESC+"[44m"          /*蓝色    */
#define BMAG ESC+"[45m"          /*紫色 */
#define BCYN ESC+"[46m"          /*青色    */
// #define BWHT ESC+"[47m"          /* 白色    */

#define NOR ESC+"[2;37;0m"      /* 返回原色 */
 
/*  新增的Ansi颜色定义字符。由 Gothic  april 23,1993 */
/* 注意：这些操作符是为VT100终端设计的。 */
/*  在MUD中，它们可能不一定全部都能正常使用。   */
 
#define BOLD ESC+"[1m"          /* 打开粗体 */
#define CLR ESC+"[2J"           /* 清屏  */
#define HOME ESC+"[H"           /* 发送光标到原处 */
#define REF CLR+HOME            /* 清屏和清除光标 */
#define BIGTOP ESC+"#3"         /* Dbl height characters, top half */
#define BIGBOT ESC+"#4"         /* Dbl height characters, bottem half */
#define SAVEC ESC+"[s"           /* Save cursor position */
#define REST ESC+"[u"            /* Restore cursor to saved position */
//#define REVINDEX ESC+"M"        /* Scroll screen in opposite direction */
#define SINGW ESC+"#5"          /* Normal, single-width characters */
#define DBL ESC+"#6"            /* Creates double-width characters */
#define FRTOP ESC+"[2;25r"      /* 冻结首行 */
#define FRBOT ESC+"[1;24r"      /* 冻结底部一行 */
#define UNFR ESC+"[r"           /* 首行和底部一行解冻 */
#define BLINK ESC+"[5m"         /* 不断闪亮模式 */
#define U ESC+"[4m"             /* 下划线模式 */
#define REV ESC+"[7m"           /* 打开反白模式 */
#define HIREV ESC+"[1,7m"       /* 亮色彩反白显示  */
 
