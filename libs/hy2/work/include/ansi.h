/*  ansi.h
*/

#ifndef	ANSI_ESCAPE_H
#define ANSI_ESCAPE_H
 
#define ESC	"\x1B"
 
#define NOR ESC "[0;2m"		/* Normal white forground */
 
/* Foreground colors */
 
#define BLK	ESC "[30m"	/* Black    */
#define RED	ESC "[31m"	/* Red      */
#define GRN	ESC "[32m"	/* Green    */
#define YEL	ESC "[33m"	/* Yellow   */
#define BLU	ESC "[34m"	/* Blue     */
#define MAG	ESC "[35m"	/* Magenta  */
#define CYN	ESC "[36m"	/* Cyan     */
#define WHT	ESC "[37m"	/* White    */
 
/* Background colors */
 
#define BBLK	ESC "[40m"	/* Black    */
#define BRED	ESC "[41m"	/* Red      */
#define BGRN	ESC "[42m"	/* Green    */
#define BYEL	ESC "[43m"	/* Yellow   */
#define BBLU	ESC "[44m"	/* Blue     */
#define BMAG	ESC "[45m"	/* Magenta  */
#define BCYN	ESC "[46m"	/* Cyan     */
#define BWHT	ESC "[47m"	/* White    */

/* Bold foreground colors */

#define HIK	ESC "[1;30m"	/* Black    */
#define HIR	ESC "[1;31m"	/* Red      */
#define HIG	ESC "[1;32m"	/* Green    */
#define HIY	ESC "[1;33m"	/* Yellow   */
#define HIB	ESC "[1;34m"	/* Blue     */
#define HIM	ESC "[1;35m"	/* Magenta  */
#define HIC	ESC "[1;36m"	/* Cyan     */
#define HIW	ESC "[1;37m"	/* White    */

#define BOLD		ESC "[1m"			// Bold mode
#define LINE		ESC+"[4m"			// 底线
#define BLINK		ESC+"[5m"			// 闪烁
#define REV			ESC+"[7m"			// 反白
#define CLR			ESC+"[2J"			// 清除画面

#define HOME		ESC+"[H"			// 将游标移到左上
#define REF			CLR+HOME			// 清除画面并将游标移到左上

#define SAVEC		ESC+"[s"			// 保存目前游标位置
#define RESTC		ESC+"[u"			// 反回游标保存位置
#define SAVECA		ESC "7"				// Save cursor & attribute
#define RESTCA		ESC "8"				// Restore cursor & attribute

#define MV(x,y)     ESC "["+x+";"+y+"H"
#define UP(n)		ESC "["+n+"A"		// 游标上移 n 列(line),<已至萤幕顶端则无效>
#define DOWN(n)		ESC "["+n+"B"		// 游标下移 n 列(line),<已至萤幕底端则无效>
#define RIGHT(n)	ESC "["+n+"C"		// 游标向右移 n 列(line),<已至萤幕最右则无效>
#define LEFT(n)		ESC "["+n+"D"		// 游标向左移 n 列(line),<已至萤幕最左则无效>

#define R(t,b)		ESC "["+t+";"+b+"r" // 设置萤幕大小
#define UNFR		ESC+"[r"            // Unfreeze top and bottom lines
 
#endif	/* ANSI_ESCAPE_H */
