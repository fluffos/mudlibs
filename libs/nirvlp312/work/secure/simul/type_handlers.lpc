int member_array(mixed item, mixed arr) {
  return efun::member(arr, item);
}

mapping m_delete(mapping m, mixed key) {
  return efun::m_delete(copy(m), key);
}

int file_time(string path) {
  mixed *v;

  if (sizeof(v=get_dir(path,4)))
    return v[0];
}

