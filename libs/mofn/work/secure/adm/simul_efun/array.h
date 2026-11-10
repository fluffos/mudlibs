mixed delete(mixed arr, int start, int len) {
  return arr[0..start-1] + arr[start+len..];
}
