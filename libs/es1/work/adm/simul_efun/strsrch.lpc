/* strsrch
//  This will be replaced by an efun in 0.9.17.13 so I haven't gone
//    to extremes of efficency or documentation
// args:
//   1) search space - the string being searched
//   2) search pattern - the string or char being searched for
//   3) reverse flag - whether to start at the beggining or end
// return value:
//   -1) failure
//     offset
*/
varargs int strsrch(string spc, mixed pat, int rev)
{
    int i,j,k;

    if(nullp(spc) || nullp(pat))
	return -1;
    
    if(intp(pat)) {
	j=strlen(spc);
	if(rev) {
	    while(j--)
		if(spc[j]==pat)
		    break;
	    return j;
	} else {
	    for(i=0;i<j;i++)
		if(spc[i]==pat)
		    break;
	    return (i==j) ? -1 : i;
	}
    } else if(stringp(pat)) {
	k=strlen(pat) - 1;
        j=strlen(spc) - k;
	if(rev) {
	    while(j--)
		if(spc[j..j+k]==pat)
		    break;
	    return j;
	} else {
	    j--;
	    for(i=0;i<j;i++)
		if(spc[i..i+k]==pat)
		    break;
	    return (i==j) ? -1 : i;
	}
    } else
	return -1;
}
