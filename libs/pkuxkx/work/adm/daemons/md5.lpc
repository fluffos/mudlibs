#include <md5.h>
/*unsigned int LShift(unsigned int lValue,unsigned int iShiftBits)
{
	if (!iShiftBits)
	{
		return lValue;
	}
	else if (iShiftBits==31)
	{
		if (lValue & 1)
			return 0x80000000;
		else
			return 0;
	}
	if (lValue & m_l2Power[31 - iShiftBits])
		return ((lValue & m_lOnBits[31 - (iShiftBits + 1)]) * m_l2Power[iShiftBits]) | 0x80000000;
	else
		return ((lValue & m_lOnBits(31 - iShiftBits)) * m_l2Power(iShiftBits));
}

unsigned int RShift(unsigned int lValue,unsigned int iShiftBits)
*/
int RotateLeft(int lValue, int iShiftBits)
{
	return ((lValue << iShiftBits) | (lValue >> (32 - iShiftBits)));
}


int AddUnsigned(int lX,int lY)
{
	int lX4,lY4,lX8,lY8,lResult;

    lX8 = lX & 0x80000000;
    lY8 = lY & 0x80000000;
    lX4 = lX & 0x40000000;
    lY4 = lY & 0x40000000;
 
    lResult = (lX & 0x3FFFFFFF) + (lY & 0x3FFFFFFF);
 
    if (lX4 & lY4)
		lResult = lResult^0x80000000^lX8^lY8;
    else if (lX4 | lY4)
	{
        if (lResult & 0x40000000)
            lResult = lResult^0xC0000000^lX8^lY8;
        else
            lResult = lResult^0x40000000^lX8^lY8;
    }
    else
        lResult = lResult^lX8^lY8;
    return lResult;
}

#define md5_F(X, Y, Z)      (((X)&(Y))|((~(X))&(Z)))
#define md5_G(X, Y, Z)      (((X)&(Z))|((~(Z))&(Y)))
#define md5_H(X, Y, Z)      ((X)^(Y)^(Z))
#define md5_I(X, Y, Z)      ((Y)^((X)|(~(Z))))

#define Tr(a, b, c, d, x, s, ac, f)   (a)=AddUnsigned((a),AddUnsigned(AddUnsigned(f(b,c,d),(x)),(ac));(a)=RotateLeft((a), (s));(a) = AddUnsigned((a), (b));

#define MODULUS_BITS 512
#define CONGRUENT_BITS 448

mixed ConvertToWordArray(string str)
{
int lMessageLength;
int lNumberOfWords;
mixed lWordArray=allocate(33);
int lBytePosition;
int lByteCount;
int lWordCount;

	lMessageLength = strwidth(str);
    
    lNumberOfWords = (((lMessageLength + ((MODULUS_BITS - CONGRUENT_BITS) \ BITS_TO_A_BYTE)) \ (MODULUS_BITS / BITS_TO_A_BYTE)) + 1) * (MODULUS_BITS / BITS_TO_A_WORD);

	return ({1,2});

/*  mixed bin = allocate(9);
  int i;
  int mask = (1 << BITS_TO_A_BYTE) - 1;
  for( i = 0; i < strwidth(str) * BITS_TO_A_BYTE; i += BITS_TO_A_BYTE)
    bin[i>>5] |= ((i / BITS_TO_A_BYTE) & mask) << (i%32);
  return bin;
 */
}


string md5(string pass)
{
//	mixed mBits=*allocate(31);
	mixed mBits = ({1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823, 2147483647});
	mixed s1 = ({7,12,17,22});
	mixed s2 = ({5,9,14,20});
	mixed s3 = ({4,11,16,23});
	mixed s4 = ({6,10,15,21});
	mixed x = allocate(9);
	
	x=ConvertToWordArray("text");
	for (int i=0;i<sizeof(x) ;i++ )
	{
		printf("%d\n",x[i]);
	}
}
