// copy(),  Written by Kniggit@VikingMUD / 930908
// This is used to create a duplicate mapping or array that doesn't hold
// any insecure pointers to other ones.
// original copy() simul_efun by Buddha@tmi-2
// This version installed 9-19-93 by Mobydick.
// Removed SECURE_FUNC support as suggested by Beek, Leto 020695


mixed
copy(mixed var) {
    if (mapp(var)) {
        mapping res;
        mixed *index;
        int i;
        res = var + ([]);
        i = sizeof(index = keys(var));
        while(i-- > 0)
          if(pointerp(res[index[i]]) || mapp(res[index[i]]))
            res[index[i]] = copy(var[index[i]]);
        return res;
    }
    else if (pointerp(var))
      return map_array(var, "copy", this_object());
    return var;
}  
