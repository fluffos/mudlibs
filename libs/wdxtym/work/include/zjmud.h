//ÖÕ¼«µØÓü×ªÒåÐ­Òé

#define ZJKEY           "123456789abcd" 
#define ZJPAYPORT		3001
#define ZJUDPPORT		3004

#define ESA		"" 
#define ZJSEP		"$zj#"
#define ZJSP2		"$z2#"
#define ZJBR		"$br#"
#define ZJURL(w)	ESA + "[u:" + w + "]"
#define ZJSIZE(n)	ESA + "[s:" + n + "]"

#define SYSY		ESA + "000"
#define INPUTTXT(a,b)	ESA + "001" + a + ZJSEP + b
#define ZJTITLE		ESA + "002"
#define ZJEXIT		ESA + "003"
#define ZJEXITRM	ESA + "903"
#define ZJEXITCL	ESA + "913"
#define ZJLONG		ESA + "004"
#define ZJOBIN		ESA + "005"
#define ZJOBOUT		ESA + "905"
#define ZJBTSET		ESA + "006"
#define ZJOBLONG	ESA + "007"
#define ZJOBACTS	ESA + "008"
#define ZJOBACTS2	ESA + "009"
#define ZJYESNO		ESA + "010"
#define ZJMAPTXT	ESA + "011"
#define ZJHPTXT		ESA + "012"
#define ZJMORETXT	ESA + "013"
#define ZJFORCECMD(c)	ESA + "014" + c + "\n"
#define ZJTMPSAY	ESA + "015"
#define ZJFMSG		ESA + "016"
#define ZJFNOMSG	ESA + "017"

#define ZJPOPMENU	ESA + "020"
#define ZJMENUF(r,w,h,s)	"$"+r+","+w+","+h+","+s+"#"
#define ZJTTMENU	ESA + "021"
#define ZJCHARHP	ESA + "022"
#define ZJLONGXX	ESA + "023"

#define ZJCHANNEL	ESA + "100"
#define SYSEXIT		ESA + "999"

