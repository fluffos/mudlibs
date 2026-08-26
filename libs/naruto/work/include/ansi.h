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
#define LINE		ESC+"[4m"			// 底線
#define BLINK		ESC+"[5m"			// 閃爍
#define REV			ESC+"[7m"			// 反白
#define CLR			ESC+"[2J"			// 清除畫面

#define HOME		ESC+"[H"			// 將游標移到左上
#define REF			CLR+HOME			// 清除畫面並將游標移到左上

#define SAVEC		ESC+"[s"			// 保存目前游標位置
#define RESTC		ESC+"[u"			// 反回游標保存位置
#define SAVECA		ESC "7"				// Save cursor & attribute
#define RESTCA		ESC "8"				// Restore cursor & attribute

#define MV(x,y)     ESC "["+x+";"+y+"H"
#define UP(n)		ESC "["+n+"A"		// 游標上移 n 列(line),<已至螢幕頂端則無效>
#define DOWN(n)		ESC "["+n+"B"		// 游標下移 n 列(line),<已至螢幕底端則無效>
#define RIGHT(n)	ESC "["+n+"C"		// 游標向右移 n 列(line),<已至螢幕最右則無效>
#define LEFT(n)		ESC "["+n+"D"		// 游標向左移 n 列(line),<已至螢幕最左則無效>

#define R(t,b)		ESC "["+t+";"+b+"r" // 設置螢幕大小
#define UNFR		ESC+"[r"            // Unfreeze top and bottom lines
 
#endif	/* ANSI_ESCAPE_H */
