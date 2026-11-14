#pragma strict_types
#pragma save_types
status id(string str){return str=="lib";}

	 /* DOCUMENTATION in ~ergberg/libdocs/get_opt */

string spaces;

void create(){

  spaces="                                                                                                                                                               ";
}


void perror(string str){

  write(query_verb()+": "+str);
}


/*****************************************************/
mixed get_opt2(mixed line, mixed *arr, string errfunc){
/*****************************************************/

  int    stringarg,anza,anzl,anzp,i,j,k,extra;
  mixed  *p;
  string arg1,minus;

  /* checks: */
  arg1=line;
  if (!line      ||
	  line==""   ||
	  line==({}) ||
	  !sizeof(arr)
	  ) return line;
  if (!arr || !(anza=sizeof(arr)) || anza&3) return 0;
  
  stringarg=1;
  if (stringp(line))
	line=explode(line," ");
  else
	if (pointerp(line))
	  stringarg=0;
	else
	  return line;
  if (!(anzl=sizeof(line))) return arg1;

  for (i=0; i<anzl;i++){
	if (line[i]=="")
	  line[i]=0;
	if (line[i]=="--"){
	  line[i]=0;
	  break;
	}
	for (j=0; line[i]&&j<anza; j+=4){
/*	  write(arr[j]+":"+arr[j+1]+"\n"); */
	  if(arr[j]==extract(line[i],0,strlen(arr[j])-1)){
		p=({0,0,0,0,0,0,0,0,0,0,0,0});
		extra=0;
		anzp=arr[j+1];
		if (anzp<0){
		  anzp=-1-anzp;
		  p[0]=arr[j];
		  extra=1;
		}
		if (anzp>12) return 0;
		minus=line[0]=='-'?"-":"";
		line[i]=extract(line[i],strlen(arr[j]));
		if (line[i]!=""){
		  if (!anzp)
			line[i]=minus+line[i];
		  i--;
		}
		else line[i]=0;
		for(k=0; k<anzp && i+k+1<anzl; i++){
		  if (line[i+k+1]=="") {line[i+k+1]=0; continue;}
		  p[k+extra]=line[i+k+1];
		  k++;
		  line[i+k]=0;
		}
		if (k<anzp && !call_other(previous_object(),errfunc,"?"))
		  if (anzp==1)
			perror("option requires an argument -- "+arr[j]+"\n");
		  else
			perror("option requires "+anzp+" arguments -- "+arr[j]+"\n");
		if (arr[j+2])
		  call_other(arr[j+2],arr[j+3],p[0],p[1],p[2],p[3],p[4],
					 p[5],p[6],p[7],p[8],p[9],p[10],p[11]);
		break;
	  }
	}
	if (j==anza&&line[i][0]=='-'&&!call_other(previous_object(),errfunc,"?")){
	  perror("illegal option -- "+line[i]+"\n");
	  line[i]=0;
	}
  }
  line=filter(line,"clear_unused",this_object());
  if (stringarg)
	line=implode(line," ");
  if (!line)
	line="";
  return line;
}
  
status clear_unused(mixed x){ return x!=0;}

/**************************************************/
mixed get_opt(mixed line, string opts, string func){
/**************************************************/
  
  int    i,len,optc;
  mixed  *arr;
  
  len=strlen(opts);
  for(optc=i=0; i<len; i++)
	if (opts[i]!=':') optc++;
  arr=allocate(optc<<2);
  while(opts[0]==':') opts=extract(opts,1);
  for(optc=i=0; i<len; i++)
	if (opts[i]==':') arr[optc-3]-=1;
	else{
	  arr[optc++]="-"+extract(opts,i,i);
	  arr[optc++]=-1;
	  arr[optc++]=previous_object();
	  arr[optc++]=func;
	}
  return get_opt2(line,arr,func);
}




#define RESET_FORMAT             \
if (newline)                     \
  out+="\n";                     \
if (offset)                      \
  out+=extract(spaces,-offset);  \
if (!newline){                   \
  offset+=margin;                \
  iwidth-=margin;                \
}                                \
out+=tmp;                        \
newline=1;                       \
tmp="";                          \
this_out=space=0


string finish(string tmp, string justify, int miss, status done){

  string out;
  int    off,k,j;
  string *arr;
  
/*  write("finish: '"+tmp+"'["+miss+"|"+done+"]\n"); */
  if (miss)
	switch(justify){
	case "right":
	  tmp=extract(spaces,-miss)+tmp;
	  break;
	case "center":
	  if (done)
		tmp+=extract(spaces,-(miss-(miss>>1)));
	  tmp=extract(spaces,-(miss>>1))+tmp;
	  break;
	case "both":
	  arr=explode(tmp," ");
	  if (sizeof(arr)>1 && !done){
		off=miss/(sizeof(arr)-1);
		miss-=off*(sizeof(arr)-1);
		k=sizeof(arr)>>1;
		for (j=0; j<sizeof(arr)-1; j++){
		  if (off)
			arr[j]+=extract(spaces,-off);
		  if ((k+=miss)>sizeof(arr)-1){
			arr[j]+=" ";
			k-=sizeof(arr)-1;
		  }
		}
		tmp=implode(arr," ");
		break;
	  }
	  tmp=implode(arr," ");
	  /*fall through*/
	default:
	  if (done)
		tmp=tmp+extract(spaces,-miss);
	  break;
	}
  return tmp;
}

/***************************************************************************/
string format(string str, int width, string justify, int offset, int margin){
/***************************************************************************/

  string *arr, out, tmp, a, help;
  int    i, off, iwidth, space, this_out, anz, len;
  status newline, lastisnl;
  
  if (!width) width=78;
  if (offset >= width) offset = width - 1;
  if (margin + offset >= width)	margin = width - offset - 1;
  if (!str || str == "") return extract(spaces,-width);
  if (!justify)	justify = "left";
  lastisnl = extract(str,-1) == "\n";
  arr = explode(str," ");
  if (!arr) arr = ({});
  anz = sizeof(arr);
  out = "";
  tmp = "";
  this_out = 0;
  newline = space = 0;
  
  iwidth = width;
  
  for(i = 0; i < anz; i++) {
    help = 0;
    if (!arr[i])  arr[i] = "";
    if (sscanf(arr[i], "%s\n%s", a, help))  arr[i] = a;
    len = strlen(arr[i]);
    if (len + this_out + space <= iwidth) {
      this_out += space + len;
      if (space) tmp += " ";
      space = 1;
      tmp += arr[i];
    }
    else {
    if (tmp == "") {
      switch (justify) {
      case "right":
        tmp = extract (arr[i], -iwidth);
        break;
      case "both":
      case "center":
        off=(strlen(arr[i])-iwidth)>>1;
        tmp=extract(arr[i],off,off+iwidth-1);
        break;
      default:
        tmp=extract(arr[i],0,iwidth-1);
      }
    }
    else i--;
    if (!help) {
      tmp = finish (tmp, justify, iwidth-strlen(tmp), i == anz-1 && newline);
      RESET_FORMAT;
     }
   }
   if (help) {
     tmp=finish (tmp, justify, iwidth-strlen(tmp)
                , 1 /* i == anz-1 && help == "" && newline*/
                );
     RESET_FORMAT;
     arr[i]=help;
     i--;
   }
 }
 if (tmp != "") {
   tmp = finish (tmp, justify, iwidth-strlen(tmp), newline);
   RESET_FORMAT;
 }
 if (lastisnl) out+="\n";
 return out;
}


status query_prevent_shadow(){return 1;}

