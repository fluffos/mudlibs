
 /* -------------------------------------------------------------------------
  * G-LIB v0.0-alpha0                        GENERIC OBJECT LIBRARY FOR LPMUD
  * (see /doc/license before altering the code)
  * -------------------------------------------------------------------------
  * file name   : include/ansi.h
  * description : definations for all ansi codes
  * coder(s)    : namhas
  * -------------------------------------------------------------------------
  */

#define ESC     ""            /* esc-code     */
#define CSI     ESC + "["      /* csi-code     */

#define C_NRM   CSI + "0m"     /* normal       */
#define C_BLD   CSI + "1m"     /* bold         */
#define C_ITA   CSI + "3m"     /* italics      */
#define C_UND   CSI + "4m"     /* underline    */
#define C_FLA   CSI + "5m"     /* flash        */
#define C_IN1   CSI + "7m"     /* inverse      */
#define C_IN2   CSI + "8m"     /* invisible    */

#define C_BLA   CSI + "30m"    /* black        */
#define C_RED   CSI + "31m"    /* red          */
#define C_GRE   CSI + "32m"    /* green        */
#define C_YEL   CSI + "33m"    /* yellow       */
#define C_BLU   CSI + "34m"    /* blue         */
#define C_PUR   CSI + "35m"    /* purple       */
#define C_CYA   CSI + "36m"    /* cyan         */
#define C_WHI   CSI + "37m"    /* white        */

#define C_BBLA  CSI + "1;30m"  /* bold black   */
#define C_BRED  CSI + "1;31m"  /* bold red     */
#define C_BGRE  CSI + "1;32m"  /* bold green   */
#define C_BYEL  CSI + "1;33m"  /* bold yellow  */
#define C_BBLU  CSI + "1;34m"  /* bold blue    */
#define C_BPUR  CSI + "1;35m"  /* bold purple  */
#define C_BCYA  CSI + "1;36m"  /* bold cyan    */
#define C_BWHI  CSI + "1;37m"  /* bold white   */

#define C_CLR   CSI + "1;1H" + CSI + "2J"     /* screen clear */
#define C_HOM   CSI + "[H"     /* home cursor  */
#define C_REF   C_CLR + C_HOM  /* both         */

