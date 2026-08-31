string hp_str(int hp,int max,int c) {
  string ret;
  switch(hp*100/max) {
    case 0..5:
      ret="at death's door";
      break;
    case 6..15:
      ret="barely alive";
      break;
    case 16..25:
      ret="terribly hurt";
      break;
    case 26..35:
      ret="in very bad shape";
      break;
    case 36..45:
      ret="in bad shape";
      break;
    case 46..55:
      ret="very hurt";
      break;
    case 56..65:
      ret="feeling rather hurt";
      break;
    case 66..75:
      ret="hurt";
      break;
    case 76..85:
      ret="somewhat hurt";
      break;
    case 86..95:
      ret="slightly hurt";
      break;
    case 96..100:
      ret="feeling very well";
      break;
    default:
      ret="in a very strange shape";
      break;
  }
  if(c) ret=capitalize(ret);
  return ret;
}

string sp_str(int sp,int max,int c) {
  string ret;
  switch(sp*100/max) {
    case 0..5:
      ret="exhausted";
      break;
    case 6..15:
      ret="worn down";
      break;
    case 16..25:
      ret="indisposed";
      break;
    case 26..35:
      ret="in very bad shape";
      break;
    case 36..45:
      ret="in bad shape";
      break;
    case 46..55:
      ret="very degraded";
      break;
    case 56..65:
      ret="rather degraded";
      break;
    case 66..75:
      ret="degraded";
      break;
    case 76..85:
      ret="somewhat degraded";
      break;
    case 86..95:
      ret="slightly degraded";
      break;
    case 96..100:
      ret="in full vigour";
      break;
    default:
      ret="in a very strange shape";
      break;
  }
  if(c) ret=capitalize(ret);
  return ret;
}

string fp_str(int fp,int max,int c) {
  string ret;
  switch(fp*100/max) {
    case 0..5:
      ret="exhausted";
      break;
    case 6..15:
      ret="worn down";
      break;
    case 16..25:
      ret="indisposed";
      break;
    case 26..35:
      ret="in very bad shape";
      break;
    case 36..45:
      ret="in bad shape";
      break;
    case 46..55:
      ret="very fatigued";
      break;
    case 56..65:
      ret="rather fatigued";
      break;
    case 66..75:
      ret="fatigued";
      break;
    case 76..85:
      ret="somewhat fatigued";
      break;
    case 86..95:
      ret="slightly fatigued";
      break;
    case 96..100:
      ret="in full vigour";
      break;
    default:
      ret="in a very strange shape";
      break;
  }
  if(c) ret=capitalize(ret);
  return ret;
}
