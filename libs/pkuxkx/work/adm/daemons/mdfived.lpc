//newmd5.c
#define hexcase 0  /* hex output format. 0 - lowercase; 1 - uppercase        */
#define chrsz 8  /* bits per input character. 8 - ASCII; 16 - Unicode      */
mapping CHR=([32:" ",33:"!",34:"\"",35:"#",
36:"$",37:"%",38:"&",39:"'",40:"(",
41:")",42:"*",43:"+",44:",",45:"-",
46:".",47:"/",48:"0",49:"1",50:"2",
51:"3",52:"4",53:"5",54:"6",55:"7",
56:"8",57:"9",58:":",59:";",60:"<",
61:"=",62:">",63:"?",64:"@",65:"A",
66:"B",67:"C",68:"D",69:"E",70:"F",
71:"G",72:"H",73:"I",74:"J",75:"K",
76:"L",77:"M",78:"N",79:"O",80:"P",
81:"Q",82:"R",83:"S",84:"T",85:"U",
86:"V",87:"W",88:"X",89:"Y",90:"Z",
91:"[",92:"\\",93:"]",94:"^",95:"_",
96:"`",97:"a",98:"b",99:"c",100:"d",
101:"e",102:"f",103:"g",104:"h",105:"i",
106:"j",107:"k",108:"l",109:"m",110:"n",
111:"o",112:"p",113:"q",114:"r",115:"s",
116:"t",117:"u",118:"v",119:"w",120:"x",
121:"y",122:"z",123:"{",124:"|",125:"}",
126:"~"]);
mapping ASC=([" ":32,"!":33,"\"":34,"#":35,
"$":36,"%":37,"&":38,"'":39,"(":40,
")":41,"*":42,"+":43,",":44,"-":45,
".":46,"/":47,"0":48,"1":49,"2":50,
"3":51,"4":52,"5":53,"6":54,"7":55,
"8":56,"9":57,":":58,";":59,"<":60,
"=":61,">":62,"?":63,"@":64,"A":65,
"B":66,"C":67,"D":68,"E":69,"F":70,
"G":71,"H":72,"I":73,"J":74,"K":75,
"L":76,"M":77,"N":78,"O":79,"P":80,
"Q":81,"R":82,"S":83,"T":84,"U":85,
"V":86,"W":87,"X":88,"Y":89,"Z":90,
"[":91,"\\":92,"]":93,"^":94,"_":95,
"`":96,"a":97,"b":98,"c":99,"d":100,
"e":101,"f":102,"g":103,"h":104,"i":105,
"j":106,"k":107,"l":108,"m":109,"n":110,
"o":111,"p":112,"q":113,"r":114,"s":115,
"t":116,"u":117,"v":118,"w":119,"x":120,
"y":121,"z":122,"{":123,"|":124,"}":125,
"~":126]);
int moveright(int num, int cnt)
{
	if (num>=0)
	{
		return (num>>cnt);
	}
	else
	{
		int x;
		x=num;
		x = (x & 0x7FFFFFFE) / pow(2,cnt);
		if (x& 0x80000000)
		{
                        x=(x|to_int((0x40000000 / pow(2,cnt-1))));
//                        x=(x|(0x40000000 div pow(2,cnt-1)));
		}
//		x=~x;
//		x=x^(0x00000080);
//		x=x>>cnt;
		return (x);
	}
}
/*
 * Calculate the HMAC-MD5, of a key and some data
 */
int safe_add(int x, int y)
{
	int lsw,msw;
	lsw = (x & 0xFFFF) + (y & 0xFFFF);
	msw = (x >> 16) + (y >> 16) + (lsw >> 16);
//	msw = moveright(x,16)+moveright(y,16)+moveright(lsw,16);
	return ((msw << 16) | (lsw & 0xFFFF));
}
/*
 * Bitwise rotate a 32-bit number to the left.
 */

int bit_rol(int num, int cnt)
{
//	printf("num=%dcnt=%dresult=%d\n",num,cnt,moveright(num,(32-cnt)));
  return (num << cnt) | (moveright(num,(32-cnt)));
}


/*
 * These functions implement the four basic operations the algorithm uses.
 */
int md5_cmn(int q, int a, int b, mixed x, int s, int t)
{
  return safe_add(bit_rol(safe_add(safe_add(a, q), safe_add(x, t)), s),b);
}
int md5_ff(int a, int b, int c, int d, mixed x, int s, int t)
{
  return md5_cmn((b & c) | ((~b) & d), a, b, x, s, t);
}
int md5_gg(int a, int b, int c, int d, mixed x, int s, int t)
{
  return md5_cmn((b & d) | (c & (~d)), a, b, x, s, t);
}
int md5_hh(int a, int b, int c, int d, mixed x, int s, int t)
{
  return md5_cmn(b ^ c ^ d, a, b, x, s, t);
}
int md5_ii(int a, int b, int c, int d, mixed x, int s, int t)
{
  return md5_cmn(c ^ (b | (~d)), a, b, x, s, t);
}



/*
 * Calculate the MD5 of an array of little-endian words, and a bit length
 */
mixed core_md5(mixed x, int len)
{
  /* append padding */
  int a,b,c,d,olda,oldb,oldc,oldd,i;
  mixed y=allocate(100);
  for (i=0;i<sizeof(x) ;i++ )
  {
	  y[i]=x[i];
  }
  y[len >> 5] |= 0x80 << ((len) % 32);
  y[(moveright((len + 64), 9) << 4) + 14] = len;
//  printf("%d\n%d\n",(((len + 64) >> 9) << 4) + 14,sizeof(x));
  
 a =  1732584193;
 b = -271733879;
 c = -1732584194;
 d =  271733878;

  for(i = 0; i < sizeof(x); i += 16)
  {
	olda = a;
	oldb = b;
	oldc = c;
	oldd = d;
// 	printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
    a = md5_ff(a, b, c, d, y[i+ 0], 7 , -680876936);
//	printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
    d = md5_ff(d, a, b, c, y[i+ 1], 12, -389564586);
    c = md5_ff(c, d, a, b, y[i+ 2], 17,  606105819);
    b = md5_ff(b, c, d, a, y[i+ 3], 22, -1044525330);
    a = md5_ff(a, b, c, d, y[i+ 4], 7 , -176418897);
    d = md5_ff(d, a, b, c, y[i+ 5], 12,  1200080426);
    c = md5_ff(c, d, a, b, y[i+ 6], 17, -1473231341);
    b = md5_ff(b, c, d, a, y[i+ 7], 22, -45705983);
    a = md5_ff(a, b, c, d, y[i+ 8], 7 ,  1770035416);
    d = md5_ff(d, a, b, c, y[i+ 9], 12, -1958414417);
    c = md5_ff(c, d, a, b, y[i+10], 17, -42063);
    b = md5_ff(b, c, d, a, y[i+11], 22, -1990404162);
    a = md5_ff(a, b, c, d, y[i+12], 7 ,  1804603682);
    d = md5_ff(d, a, b, c, y[i+13], 12, -40341101);
    c = md5_ff(c, d, a, b, y[i+14], 17, -1502002290);
    b = md5_ff(b, c, d, a, y[i+15], 22,  1236535329);
//	printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);

    a = md5_gg(a, b, c, d, y[i+ 1], 5 , -165796510);
    d = md5_gg(d, a, b, c, y[i+ 6], 9 , -1069501632);
    c = md5_gg(c, d, a, b, y[i+11], 14,  643717713);
    b = md5_gg(b, c, d, a, y[i+ 0], 20, -373897302);
    a = md5_gg(a, b, c, d, y[i+ 5], 5 , -701558691);
    d = md5_gg(d, a, b, c, y[i+10], 9 ,  38016083);
    c = md5_gg(c, d, a, b, y[i+15], 14, -660478335);
    b = md5_gg(b, c, d, a, y[i+ 4], 20, -405537848);
    a = md5_gg(a, b, c, d, y[i+ 9], 5 ,  568446438);
    d = md5_gg(d, a, b, c, y[i+14], 9 , -1019803690);
    c = md5_gg(c, d, a, b, y[i+ 3], 14, -187363961);
    b = md5_gg(b, c, d, a, y[i+ 8], 20,  1163531501);
    a = md5_gg(a, b, c, d, y[i+13], 5 , -1444681467);
    d = md5_gg(d, a, b, c, y[i+ 2], 9 , -51403784);
    c = md5_gg(c, d, a, b, y[i+ 7], 14,  1735328473);
    b = md5_gg(b, c, d, a, y[i+12], 20, -1926607734);
//	printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
    a = md5_hh(a, b, c, d, y[i+ 5], 4 , -378558);
    d = md5_hh(d, a, b, c, y[i+ 8], 11, -2022574463);
    c = md5_hh(c, d, a, b, y[i+11], 16,  1839030562);
    b = md5_hh(b, c, d, a, y[i+14], 23, -35309556);
    a = md5_hh(a, b, c, d, y[i+ 1], 4 , -1530992060);
    d = md5_hh(d, a, b, c, y[i+ 4], 11,  1272893353);
    c = md5_hh(c, d, a, b, y[i+ 7], 16, -155497632);
    b = md5_hh(b, c, d, a, y[i+10], 23, -1094730640);
    a = md5_hh(a, b, c, d, y[i+13], 4 ,  681279174);
    d = md5_hh(d, a, b, c, y[i+ 0], 11, -358537222);
    c = md5_hh(c, d, a, b, y[i+ 3], 16, -722521979);
    b = md5_hh(b, c, d, a, y[i+ 6], 23,  76029189);
    a = md5_hh(a, b, c, d, y[i+ 9], 4 , -640364487);
    d = md5_hh(d, a, b, c, y[i+12], 11, -421815835);
    c = md5_hh(c, d, a, b, y[i+15], 16,  530742520);
    b = md5_hh(b, c, d, a, y[i+ 2], 23, -995338651);
//	printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);

    a = md5_ii(a, b, c, d, y[i+ 0], 6 , -198630844);
    d = md5_ii(d, a, b, c, y[i+ 7], 10,  1126891415);
    c = md5_ii(c, d, a, b, y[i+14], 15, -1416354905);
    b = md5_ii(b, c, d, a, y[i+ 5], 21, -57434055);
    a = md5_ii(a, b, c, d, y[i+12], 6 ,  1700485571);
    d = md5_ii(d, a, b, c, y[i+ 3], 10, -1894986606);
    c = md5_ii(c, d, a, b, y[i+10], 15, -1051523);
    b = md5_ii(b, c, d, a, y[i+ 1], 21, -2054922799);
    a = md5_ii(a, b, c, d, y[i+ 8], 6 ,  1873313359);
    d = md5_ii(d, a, b, c, y[i+15], 10, -30611744);
    c = md5_ii(c, d, a, b, y[i+ 6], 15, -1560198380);
    b = md5_ii(b, c, d, a, y[i+13], 21,  1309151649);
    a = md5_ii(a, b, c, d, y[i+ 4], 6 , -145523070);
    d = md5_ii(d, a, b, c, y[i+11], 10, -1120210379);
    c = md5_ii(c, d, a, b, y[i+ 2], 15,  718787259);
    b = md5_ii(b, c, d, a, y[i+ 9], 21, -343485551);

    a = safe_add(a, olda);
    b = safe_add(b, oldb);
    c = safe_add(c, oldc);
    d = safe_add(d, oldd);
//	printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
  }
  return ({a, b, c, d});
  
}

/*
 * Convert a string to an array of little-endian words
 * If chrsz is ASCII, characters >255 have their hi-byte silently ignored.
 */
mixed str2binl(string str)
{
  int i;
  mixed bin = allocate(15);
  int mask = (1 << chrsz) - 1;
  for( i = 0; i < strwidth(str) * chrsz; i += chrsz)
    bin[i>>5] |= (ASC[str[(i / chrsz)..(i / chrsz)]] & mask) << (i%32);
  return bin;
}

/*
 * Convert an array of little-endian words to a hex string.
 */
string binl2hex(mixed binarray)
{
	string hex_tab,str;
//  var hex_tab = hexcase ? "0123456789ABCDEF" : "0123456789abcdef";
	hex_tab="0123456789abcdef";
	str="";
  for(int i = 0; i < sizeof(binarray) * 4; i++)
  {
    str += hex_tab[((binarray[i>>2] >> ((i%4)*8+4)) & 0xF)..((binarray[i>>2] >> ((i%4)*8+4)) & 0xF)] +
           hex_tab[((binarray[i>>2] >> ((i%4)*8  )) & 0xF)..((binarray[i>>2] >> ((i%4)*8  )) & 0xF)];
  }
  return str;
}

string hex_md5(string s)
{
	return binl2hex(core_md5(str2binl(s), strwidth(s) * chrsz));
}
