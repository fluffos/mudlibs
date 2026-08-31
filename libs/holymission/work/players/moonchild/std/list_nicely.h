string list_nicely(string *list) {
  int j,i;
  string output;
  j=sizeof(list)-1;
  switch(j) {
    case 0:
      return list[0] + ".\n";
      break;
    case 1:
      return list[0] + " and " + list[1] + ".\n";
      break;
    default:
      output="";
      j--;
      for(i=0;i<j;i++)
	output+=list[i]+", ";
      output+=list[j] + " and " + list[j+1] + ".\n";
      return output;
      break;
  }
}
