
 /*********************

   Encrypt
     &      V 0.3
   Decrypt

  
   (C) Tron.
  
  *********************/   


/* Source characters */

#define CHARS "ABCDEFGHIJLKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"+\
              "0123456789-+<>*&/()?{[]}$.,:;'#@!` ~%" 

#define DEFSEED "Crypt V 0.3 --(C) Tron--"


private string chars;
private string defseed;

private int *defkey;  // Default crypt seed key.
private int *codekey; // User defined crypt seed key.
private int len;      // Length of source characters.

int *compute_codekey(string str);

void
reset(status arg) {

  if(arg) return;

  chars = CHARS;
  len = sizeof(chars);
  defkey = compute_codekey(DEFSEED);
  codekey = ({});

}

/********************

 Find displacement of 
 character in CHARS 
 string.

 ********************/

private int
displacement(string str) {

string start, end;

   if(!str) return 0;

   if(sscanf(chars,"%s"+str+"%s",start,end)==2) return sizeof(start)+1;
   if(sscanf(chars,str+"%s",end)) return 1;
   if(sscanf(chars,"%s"+str,start)) return sizeof(chars);

   return 0;
}

/*******************************

 Form a Key-array for
 encrypt & decrypt.
 Array consists of displacements
 for each char in crypt seed.

 *******************************/
   
private int *
compute_codekey(string str) {
    
int *tmp;
int i;

    if(!str) return defkey;

    tmp = ({});
    for(i=0; i<sizeof(str); i++)
       tmp += ({displacement(str[i..i])});

 return tmp;
}
 
/***********************

 Return character from
 source characters by 
 giving displacement as
 argument.

 ***********************/

private string
compute_new_value(int val) {

    if (val > len) val = val - len;
    else if (val < 1) val = len + val;

    val--;

  return chars[val..val];
}    

/**************************************

 Open encrypted code.
 
 - str      string to encrypt/decrypt.
 - seed     encrypt/decrypt with seed.
 - new      start using a new seed.
 - encrypt  encrypt mode (1)

***************************************/

varargs string
decrypt(string str, string seed, status new, status encrypt) {
int i, j, tmp, siz;
string st;

    if(!str) return 0;

    if(new || !codekey) 
       codekey = compute_codekey(seed);

    st = "";
    siz = sizeof(codekey);

    for(i=j=0; i < sizeof(str); i++, j++) {

         if(!(j%siz)) j=0;

           tmp = displacement(str[i..i]);
           if(tmp && encrypt)
             st += compute_new_value(tmp + codekey[j]);
           else if(tmp)
             st += compute_new_value(tmp - codekey[j]);
           else st += str[i..i];
      }

return st;
}

/******************************

 Use decrypt with encrypt flag.

*******************************/

varargs string
encrypt(string str, string seed, status new) {
  
  return decrypt(str, seed, new, 1);
}
 
           
