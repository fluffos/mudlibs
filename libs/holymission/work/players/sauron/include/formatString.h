#ifndef __FORMATSTRING_H__

#define __FORMATSTRING_H__

#define leftAlign(sStr,iLen)	sprintf("%*-s",iLen,sStr[0..iLen-1])
#define rightAlign(sStr,iLen)	sprintf("%*s",iLen,sStr[0..iLen-1])
#define centreAlign(sStr,iLen)	sprintf("%*|s",iLen,sStr[0..iLen-1])

#define IsSpace(x)		(x==' ' || x=='\t' || x=='\n')
#define IsUpper(x)		(x>='A' && x<='Z')
#define Islower(x)		(x>='a' && x<='z')

#endif // __FORMATSTRING_H__
