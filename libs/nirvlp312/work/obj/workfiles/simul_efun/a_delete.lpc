mixed * a_delete(int i, mixed *strs) {
  mixed *ab;
  int s;
  s = sizeof(strs);
  if(i > 0) {
    ab = strs[0..i-1];
    if(i + 1 < s) {
      ab += strs[i+1..s-1];
    }
  }
  else {
    if(s > 1) {
      ab = strs[1..s-1];
    }
    else {
      ab = ({ });
    }
  }
  return ab;
}

