int rm(string file) {
  if(ACCESS_H -> has_guarded_access("file", file, PERM_DELETE))
    return efun::rm(file);
  return 0;
}

int rmdir(string dir) {
  if(ACCESS_H -> has_guarded_access("file", dir, PERM_DELETE))
    return efun::rmdir(dir);
  return 0;
}

int mkdir(string dir) {
  if(ACCESS_H -> has_guarded_access("file", dir, PERM_WRITE))
    return efun::mkdir(dir);
  return 0;
}

int rename(string src, string dest) {
  if(ACCESS_H -> has_guarded_access("file", src, PERM_DELETE | PERM_READ)
  && ACCESS_H -> has_guarded_access("file", dest, PERM_WRITE))
    return efun::rename(src, dest);
  return 0;
}

int cp(string src, string dest) {
  if(!ACCESS_H -> has_guarded_access("file", src, PERM_READ))
    return -1;
  if(!ACCESS_H -> has_guarded_access("file", dest, PERM_WRITE))
    return -2;

  return efun::cp(src, dest);
}

